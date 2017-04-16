var RNMy2c2pSdk = require('react-native').NativeModules.RNMy2c2pSdk;

module.exports = {
  init: function(privateKey, production = false) {
    RNMy2c2pSdk.setup(privateKey, production);
  },

  requestPaymentUI: function(params) {
    var payment = Object.assign({}, params, { paymentUI: true });
    return RNMy2c2pSdk.requestPayment(payment);
  },

  requestPayment: function(params) {
    var payment = Object.assign({}, params, { paymentUI: false });
    return RNMy2c2pSdk.requestPayment(payment);
  }
};
