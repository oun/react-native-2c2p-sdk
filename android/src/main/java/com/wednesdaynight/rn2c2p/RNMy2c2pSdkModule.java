
package com.wednesdaynight.rn2c2p;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.ccpp.my2c2psdk.cores.My2c2pResponse;
import com.facebook.react.bridge.ActivityEventListener;
import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.BaseActivityEventListener;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.ccpp.my2c2psdk.cores.My2c2pSDK;
import com.ccpp.my2c2psdk.cores.My3DSActivity;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableMap;

import android.util.Log;

public class RNMy2c2pSdkModule extends ReactContextBaseJavaModule {

  private static final String TAG = "RNMy2c2pSdkModule";
  private static final int REQUEST_SDK = 1;
  private static final String ACTIVITY_DOES_NOT_EXIST = "ACTIVITY_DOES_NOT_EXIST";
  private static final String START_ACTIVITY_ERROR = "START_ACTIVITY_ERROR";
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
            WritableMap result = Arguments.createMap();
            result.putString("version", response.getVersion());
            result.putString("timeStamp", response.getTimeStamp());
            result.putString("merchantID", response.getMerchantID());
            result.putString("respCode", response.getRespCode());
            result.putString("pan", response.getPan());
            result.putString("amount", response.getAmount());
            result.putString("uniqueTransactionCode", response.getUniqueTransactionCode());
            result.putString("tranRef", response.getTranRef());
            result.putString("approvalCode", response.getApprovalCode());
            result.putString("refNumber", response.getRefNumber());
            result.putString("dateTime", response.getDateTime());
            result.putString("eci", response.getEci());
            result.putString("status", response.getStatus());
            result.putString("failReason", response.getFailReason());
            result.putString("userDefined1", response.getUserDefined1());
            result.putString("userDefined2", response.getUserDefined2());
            result.putString("userDefined3", response.getUserDefined3());
            result.putString("userDefined4", response.getUserDefined4());
            result.putString("userDefined5", response.getUserDefined5());
            result.putString("storeCardUniqueID", response.getStoreCardUniqueID());
            result.putString("recurringUniqueID", response.getRecurringUniqueID());
            result.putString("hashValue", response.getHashValue());
            result.putString("ippPeriod", response.getIppPeriod());
            result.putString("ippInterestType", response.getIppInterestType());
            result.putString("ippInterestRate", response.getIppInterestRate());
            result.putString("ippMerchantAbsorbRate", response.getIppMerchantAbsorbRate());
            result.putString("paidChannel", response.getPaidChannel());
            result.putString("paidAgent", response.getPaidAgent());
            result.putString("paymentChannel", response.getPaymentChannel());
            result.putString("backendInvoice", response.getBackendInvoice());
            result.putString("issuerCountry", response.getIssuerCountry());
            result.putString("bankName", response.getBankName());
            result.putString("raw", response.getRaw());
            promise.resolve(result);
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
    this.reactContext.addActivityEventListener(activityEventListener);
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

    try {
      // execute the library using intent
      Activity currentActivity = getCurrentActivity();
      if (currentActivity == null) {
        promise.reject(ACTIVITY_DOES_NOT_EXIST, "Activity doesn't exist");
        return;
      }
      Intent intent = new Intent(currentActivity, My3DSActivity.class);
      intent.putExtra(My2c2pSDK.PARAMS, my2c2pSDK);
      currentActivity.startActivityForResult(intent, REQUEST_SDK);
    } catch (Exception e) {
      Log.e(TAG, "Error starting activity", e);
      promise.reject(START_ACTIVITY_ERROR, e);
    }
  }
}