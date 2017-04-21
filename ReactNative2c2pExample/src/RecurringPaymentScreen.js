import React, { Component } from 'react';
import { ScrollView, View, Text, TouchableHighlight, StyleSheet } from 'react-native';
import My2c2pSDK from 'react-native-my2c2p-sdk';
import t, { form } from 'tcomb-form-native';
import faker from 'faker';
import config from './config.json';

export default class RecurringPaymentScreen extends Component {
  static navigationOptions = {
    title: 'Recurring Payment'
  };

  componentDidMount() {
    My2c2pSDK.init(config.privateKey, false);
  }

  initialFormValues() {
    return {
      merchantID: config.merchantID,
      uniqueTransactionCode: faker.random.number({ min: 100000000, max: 999999999 }).toString(),
      desc: faker.commerce.productName(),
      amount: 30.0,
      currencyCode: '702',
      cardHolderName: faker.name.findName(),
      cardHolderEmail: faker.internet.email(),
      pan: '4111111111111111',
      cardExpireMonth: 2,
      cardExpireYear: 2019,
      securityCode: '012',
      panCountry: 'SG',
      invoicePrefix: 'INV',
      recurringInterval: 7,
      recurringCount: 3,
      recurringAmount: 10,
      allowAccumulate: true,
      maxAccumulateAmt: 100.0,
      secretKey: config.secretKey
    };
  }

  handleSubmit = async () => {
    const { navigate } = this.props.navigation;
    try {
      const params = { ...this.form.getValue(), paymentUI: false };
      const response = await My2c2pSDK.requestRecurringPayment(params);
      navigate('PaymentResult', { result: response });
    } catch(error) {
      console.log(error);
      navigate('PaymentResult', { result: error.message });
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
  currencyCode: t.String,
  cardHolderName: t.String,
  cardHolderEmail: t.String,
  pan: t.String,
  cardExpireMonth: t.Number,
  cardExpireYear: t.Number,
  securityCode: t.String,
  panCountry: t.String,
  invoicePrefix: t.String,
  recurringInterval: t.Number,
  recurringCount: t.Number,
  recurringAmount: t.Number,
  allowAccumulate: t.Boolean,
  maxAccumulateAmt: t.Number,
  payCategoryID: t.maybe(t.String),
  userDefined1: t.maybe(t.String),
  userDefined2: t.maybe(t.String),
  userDefined3: t.maybe(t.String),
  userDefined4: t.maybe(t.String),
  userDefined5: t.maybe(t.String)
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