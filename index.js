var RNMy2c2pSdk = require('react-native').NativeModules.RNMy2c2pSdk;

module.exports = {
  init: function(privateKey, production) {
    RNMy2c2pSdk.setup(privateKey, production);
  },

  requestPayment: function(params) {
    var payment = Object.assign({}, defaultPaymentRequest, params);
    return RNMy2c2pSdk.requestPayment(payment);
  },

  requestRecurringPayment: function(params) {
    var payment = Object.assign({}, defaultPaymentRequest, params);
    return RNMy2c2pSdk.requestRecurringPayment(payment);
  },

  requestInstallmentPayment: function(params) {
    var payment = Object.assign({}, defaultPaymentRequest, params);
    return RNMy2c2pSdk.requestInstallmentPayment(payment);
  },

  requestAlternativePayment: function(params) {
    var payment = Object.assign({}, defaultPaymentRequest, params);
    return RNMy2c2pSdk.requestAlternativePayment(payment);
  },

  requestPaymentChannel: function(params) {
    var payment = Object.assign({}, defaultPaymentRequest, params);
    return RNMy2c2pSdk.requestPaymentChannel(payment);
  }
};

const defaultPaymentRequest = {
  request3DS: 'Y',
  paymentUI: false,
  storeCard: false,
  payCategoryID: '',
  userDefined1: '',
  userDefined2: '',
  userDefined3: '',
  userDefined4: '',
  userDefined5: ''
};
