import React, { Component } from 'react';
import { ScrollView, View, Text, TouchableHighlight, StyleSheet } from 'react-native';
import My2c2pSDK from 'react-native-my2c2p-sdk';
import t, { form } from 'tcomb-form-native';
import config from './config.json';

export default class UIPaymentScreen extends Component {
  componentDidMount() {
    My2c2pSDK.init(config.privateKey);
  }

  initialFormValues() {
    return {
      merchantID: '614',
      uniqueTransactionCode: '123456706',
      desc: 'test product 1',
      amount: 1299.0,
      currencyCode: '702',
      secretKey: 'u6Y6kxBM7ai2'
    };
  }

  handleSubmit = async () => {
    const { navigate } = this.props.navigation;
    try {
      const response = await My2c2pSDK.requestPaymentUI(this.form.getValue());
      navigate('PaymentResult', { result: response });
    } catch(error) {
      console.log(error);
      navigate('PaymentResult', { result: error });
    }
  }

  render() {
    return (
      <ScrollView contentContainerStyle={styles.container}>
        <form.Form
          ref={form => (this.form = form)}
          type={payment}
          value={this.initialFormValues()}
        />
        <TouchableHighlight onPress={this.handleSubmit}>
          <View style={styles.submitButton}>
            <Text style={styles.submitButtonText}>Submit</Text>
          </View>
        </TouchableHighlight>
      </ScrollView>
    );
  }
}

const payment = t.struct({
  merchantID: t.String,
  secretKey: t.String,
  uniqueTransactionCode: t.String,
  desc: t.String,
  amount: t.Number,
  currencyCode: t.String
});

const styles = StyleSheet.create({
  container: {
    paddingHorizontal: 10,
    paddingVertical: 10,
    backgroundColor: 'white',
  },
  submitButton: {
    paddingVertical: 14,
    alignItems: 'center',
    backgroundColor: '#1e88e5'
  },
  submitButtonText: {
    color: 'white',
    fontSize: 18
  }
});