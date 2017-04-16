import React from 'react';
import { ScrollView, Text } from 'react-native';

export default function PaymentResultScreen(props) {
  const { params } = props.navigation.state;
  return (
    <ScrollView>
      <Text>{JSON.stringify(params.result, null, 2)}</Text>
    </ScrollView>
  );
}
