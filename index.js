var sdk = require('react-native').NativeModules.RNMy2c2pSdk;

function ReactNative2c2pSDK(privateKey) {
  this.privateKey = privateKey;
}

ReactNative2c2pSDK.prototype.requestPayment = function(paymentDetails) {
  sdk.requestPayment(paymentDetails, this.privateKey);
};

module.exports = ReactNative2c2pSDK;
