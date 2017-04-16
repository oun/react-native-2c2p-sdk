import React from 'react';
import { View, Text, StyleSheet, TouchableHighlight } from 'react-native';

export default function HomeScreen(props) {
  const menuItems = [
    {
      title: 'Non UI Payment',
      route: 'NonUIPayment'
    },
    {
      title: 'Payment With UI',
      route: 'UIPayment'
    }
  ];
  const { navigate } = props.navigation;
  return (
    <View>
      {
        menuItems.map((item, index) => (
          <TouchableHighlight key={index} onPress={() => navigate(item.route)}>
            <View style={styles.menuItem}>
              <Text>{item.title}</Text>
            </View>
          </TouchableHighlight>
        ))
      }
    </View>
  );
}

HomeScreen.navigationOptions = {
  title: 'Home'
};

const styles = StyleSheet.create({
  menuItem: {
    backgroundColor: 'white',
    padding: 14,
    borderBottomWidth: 1,
    borderBottomColor: '#eeeeee'
  }
});
