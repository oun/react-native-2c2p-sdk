import React from 'react';
import { StackNavigator } from 'react-navigation';
import HomeScreen from './HomeScreen';
import NonUIPaymentScreen from './NonUIPaymentScreen';
import UIPaymentScreen from './UIPaymentScreen';
import PaymentResultScreen from './PaymentResultScreen';
import RecurringPaymentScreen from './RecurringPaymentScreen';
import InstallmentPaymentScreen from './InstallmentPaymentScreen';
import AlternativePaymentScreen from './AlternativePaymentScreen';

export default StackNavigator({
  Home: { screen: HomeScreen },
  NonUIPayment: { screen: NonUIPaymentScreen },
  UIPayment: { screen: UIPaymentScreen },
  InstallmentPayment: { screen: InstallmentPaymentScreen },
  RecurringPayment: { screen: RecurringPaymentScreen },
  AlternativePayment: { screen: AlternativePaymentScreen },
  PaymentResult: { screen: PaymentResultScreen }
});