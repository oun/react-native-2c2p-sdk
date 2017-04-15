/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from 'react';
import {
  AppRegistry,
  StyleSheet,
  Text,
  View
} from 'react-native';
import NonUIPaymentScene from './NonUIPaymentScene';

export default class ReactNative2c2pExample extends Component {
  render() {
    return (
      <View>
      </View>
    );
  }
}

const styles = StyleSheet.create({
});

AppRegistry.registerComponent('ReactNative2c2pExample', () => NonUIPaymentScene);
