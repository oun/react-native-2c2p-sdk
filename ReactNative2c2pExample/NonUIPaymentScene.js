import React, { Component } from 'react';
import { View, TouchableOpacity, Text, StyleSheet } from 'react-native';
import My2c2pSDK from 'react-native-my2c2p-sdk';
import config from './config.json';

export default class NonUIPaymentScene extends Component {
  componentDidMount() {
    My2c2pSDK.init(config.privateKey);
  }

  handlePayment = async () => {
    const details = {
      merchantID: '614',
      uniqueTransactionCode: '123456706',
      desc: 'test product 1',
      amount: 1299.0,
      currencyCode: '702',
      cardHolderName: 'Mr. John',
      cardHolderEmail: 'john@example.com',
      pan: '4111111111111111',
      cardExpireMonth: 2,
      cardExpireYear: 2019,
      securityCode: '012',
      panCountry: 'SG'
    };

    try {
      const response = await My2c2pSDK.requestPayment(details);
      console.log(response);
    } catch(error) {
      console.log(error);
    }
  }

  render() {
    return (
      <View style={styles.container}>
        <TouchableOpacity onPress={this.handlePayment}>
          <Text>Begin Payment</Text>
        </TouchableOpacity>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  }
});