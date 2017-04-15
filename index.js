var RNMy2c2pSdk = require('react-native').NativeModules.RNMy2c2pSdk;

module.exports = {
  init: function(privateKey) {
    RNMy2c2pSdk.setup(privateKey);
  },

  requestPayment: function(paymentDetails) {
    return RNMy2c2pSdk.requestPayment(paymentDetails);
  }
};
