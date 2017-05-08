
# react-native-my2c2p-sdk

A minimal react-native bridge to 2c2p sdk.

## Installation

`$ npm install react-native-my2c2p-sdk --save`

or

`$ yarn add react-native-my2c2p-sdk`

### Automatic Linking

`$ react-native link react-native-my2c2p-sdk`

### Manual Linking

#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-my2c2p-sdk` and add `RNMy2c2pSdk.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNMy2c2pSdk.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.wednesdaynight.rn2c2p.RNMy2c2pSdkPackage;` to the imports at the top of the file
  - Add `new RNMy2c2pSdkPackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-my2c2p-sdk'
  	project(':react-native-my2c2p-sdk').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-my2c2p-sdk/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
    compile project(':react-native-my2c2p-sdk')
  	```

### Setup My2c2pSDK

Follow instruction on 2c2p ([android](https://s.2c2p.com/manuals/android/setupsdk.html), [iOS](https://s.2c2p.com/manuals/ios/setupsdk.html)) to generate private keys. 

#### iOS

Install via cocoa pods:
Add `pod 'my2c2pSDK'` to the ios/Podfile and run `pod install`.

#### Android

1. Download My2c2pSDK library from <https://s.2c2p.com/manuals/android/download/my2c2psdk.html>.
   Convert library to gradle module (See [example](https://github.com/oun/react-native-2c2p-example/tree/master/android/app/my2c2psdk)) 
   and put into directory: `your-react-native-project/android/app/my2c2psdk`.
2. Append the following lines to `android/settings.gradle`:
    ```
    include ':my2c2psdk'
    project(':my2c2psdk').projectDir = new File(rootProject.projectDir, './app/my2c2psdk')
    ```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
    compile project(':my2c2psdk')
  	```
4. Add activity to app AndroidManifest.xml
    ```
    <activity android:name="com.ccpp.my2c2psdk.cores.My3DSActivity"
            android:theme="@style/My2c2pSDK.Theme"
            android:screenOrientation="portrait">
        <intent-filter>
            <action android:name="android.intent.action.VIEW" />
    
            <category android:name="android.intent.category.DEFAULT" />
            <category android:name="android.intent.category.BROWSABLE" />
            <!-- For 123 payment : eNETS (Direct Debit/Web Payment) Only -->
            <!-- For demo server -->
            <data
                android:scheme="my2c2pjt"
                android:host="123" />
            <!-- For demo server -->
            <data
                android:scheme="my2c2pjt01"
                android:host="123" />
            <!-- For prod server -->
            <data
                android:scheme="my2c2p1001"
                android:host="123" />
            <!-- End -->
        </intent-filter>
    </activity>
    <activity android:name="com.ccpp.my2c2psdk.cores.OTPActivity"
        android:screenOrientation="portrait"
        android:theme="@android:style/Theme.NoTitleBar"/>
    ```

## Usage
```javascript
import React, { Component } from 'react';
import My2c2pSDK from 'react-native-my2c2p-sdk';
import { ScrollView, TouchableHighlight, Text, StyleSheet } from 'react-native';
...

const privateKey = 'YOUR PRIVATE KEY';
const merchantID = 'YOUR MERCHANT ID';
const secretKey = 'YOUR SECRET KEY';
const productionMode = false;

export default class PaymentScreen extends Component {
  componentDidMount() {
    My2c2pSDK.init(privateKey, productionMode);
  }

  handlePayment = async () => {
    try {
      const response = await My2c2pSDK.requestPayment({
        paymentUI: false,
        merchantID: merchantID,
        uniqueTransactionCode: '123456789',
        desc: 'Transaction description',
        amount: 19.0,
        currencyCode: '702',
        cardHolderName: 'John Doe',
        cardHolderEmail: 'john@doe.com',
        pan: '4111111111111111',
        cardExpireMonth: 2,
        cardExpireYear: 2019,
        securityCode: '123',
        panCountry: 'SG',
        secretKey: secretKey
      });
      console.log(response);
    } catch(error) {
      if (error.code === 'TRANSACTION_CANCELED') {
        // transaction is canceled from OTP
      }
      console.log(error);
    }
  }

  render() {
    return (
      <ScrollView>
        // Form ...
        <TouchableHighlight onPress={this.handlePayment}>
          <Text>Submit</Text>
        </TouchableHighlight>
      </ScrollView>
    );
  }
  
  ...
}

```

### Credit card payment (Non-UI)
```javascript
My2c2pSDK.requestPayment({
  paymentUI: false,
  merchantID: merchantID,
  uniqueTransactionCode: '123456789',
  desc: 'Transaction description',
  amount: 19.0,
  currencyCode: '702',
  cardHolderName: 'John Doe',
  cardHolderEmail: 'john@doe.com',
  pan: '4111111111111111',
  cardExpireMonth: 2,
  cardExpireYear: 2019,
  securityCode: '123',
  panCountry: 'SG',
  secretKey: secretKey
});
```

### Credit card payment (UI)
```javascript
My2c2pSDK.requestPayment({
  paymentUI: true,
  merchantID: merchantID,
  uniqueTransactionCode: '123456789',
  desc: 'Transaction description',
  amount: 19.0,
  currencyCode: '702',
  secretKey: secretKey
});
```

Check the full document for [payment request](https://s.2c2p.com/manuals/android/reference/nonuirequest.html#payment-request)
and [response](https://s.2c2p.com/manuals/android/reference/my2c2presponse.html)

## Example app:

https://github.com/oun/react-native-2c2p-example
