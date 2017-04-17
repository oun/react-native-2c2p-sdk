
package com.wednesdaynight.rn2c2p;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.ccpp.my2c2psdk.cores.My2c2pResponse;
import com.facebook.react.bridge.ActivityEventListener;
import com.facebook.react.bridge.BaseActivityEventListener;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.ccpp.my2c2psdk.cores.My2c2pSDK;
import com.ccpp.my2c2psdk.cores.My3DSActivity;
import com.facebook.react.bridge.ReadableMap;
import android.util.Log;

public class RNMy2c2pSdkModule extends ReactContextBaseJavaModule {

  private static final String TAG = "RNMy2c2pSdkModule";
  private static final int REQUEST_SDK = 1;
  private static final String E_ACTIVITY_DOES_NOT_EXIST = "E_ACTIVITY_DOES_NOT_EXIST";
  private static final String NO_RESPONSE = "NO_RESPONSE";

  private final ReactApplicationContext reactContext;
  private My2c2pSDK my2c2pSDK;
  private Promise promise;

  private final ActivityEventListener activityEventListener = new BaseActivityEventListener() {
    @Override
    public void onActivityResult(Activity activity, int requestCode, int resultCode, Intent data) {
      if (requestCode == REQUEST_SDK) {
        if (data != null) {
          Log.d(TAG, "result code: " + resultCode);

          My2c2pResponse response = data.getExtras().getParcelable(My2c2pResponse.RESPONSE);
          if (response != null) {
            if (response.getRespCode().equals("301")) {
              Log.d(TAG, "transaction canceled" + resultCode);
            }
            Log.d(TAG, "response" + response.toString());
            promise.resolve(response);
          } else {
            promise.reject(NO_RESPONSE, "No response data");
          }
        }
      }
    }
  };

  public RNMy2c2pSdkModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.reactContext = reactContext;
    reactContext.addActivityEventListener(activityEventListener);
  }

  @Override
  public String getName() {
    return "RNMy2c2pSdk";
  }

  @ReactMethod
  public void setup(String privateKey, Boolean productionMode) {
    my2c2pSDK = new My2c2pSDK(privateKey);
    my2c2pSDK.productionMode = productionMode;
  }

  @ReactMethod
  public void requestPayment(ReadableMap paymentDetails, Promise promise) {
    this.promise = promise;

    //set mandatory fields
    my2c2pSDK.version = "9.1";
    my2c2pSDK.merchantID = paymentDetails.getString("merchantID");
    my2c2pSDK.uniqueTransactionCode = paymentDetails.getString("uniqueTransactionCode");
    my2c2pSDK.desc = paymentDetails.getString("desc");
    my2c2pSDK.amount = paymentDetails.getDouble("amount");
    my2c2pSDK.currencyCode = paymentDetails.getString("currencyCode");
    my2c2pSDK.pan = paymentDetails.getString("pan");
    my2c2pSDK.cardExpireMonth = Integer.toString(paymentDetails.getInt("cardExpireMonth"));
    my2c2pSDK.cardExpireYear = Integer.toString(paymentDetails.getInt("cardExpireYear"));
    my2c2pSDK.cardHolderName = paymentDetails.getString("cardHolderName");
    my2c2pSDK.panCountry = paymentDetails.getString("panCountry");
    my2c2pSDK.secretKey = paymentDetails.getString("secretKey");
    my2c2pSDK.paymentUI = paymentDetails.getBoolean("paymentUI");

    //set optional fields
    my2c2pSDK.securityCode = paymentDetails.getString("securityCode");

    // execute the library using intent
    Activity currentActivity = getCurrentActivity();
    if (currentActivity == null) {
      promise.reject(E_ACTIVITY_DOES_NOT_EXIST, "Activity doesn't exist");
      return;
    }
    Intent intent = new Intent(currentActivity, My3DSActivity.class);
    intent.putExtra(My2c2pSDK.PARAMS, my2c2pSDK);
    currentActivity.startActivityForResult(intent, REQUEST_SDK);
  }
}