import React from 'react';
import { StackNavigator } from 'react-navigation';
import HomeScreen from './HomeScreen';
import NonUIPaymentScreen from './NonUIPaymentScreen';
import UIPaymentScreen from './UIPaymentScreen';
import PaymentResultScreen from './PaymentResultScreen';

export default StackNavigator({
  Home: { screen: HomeScreen },
  NonUIPayment: { screen: NonUIPaymentScreen },
  UIPayment: { screen: UIPaymentScreen },
  PaymentResult: { screen: PaymentResultScreen }
});