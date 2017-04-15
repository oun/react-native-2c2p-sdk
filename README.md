
# react-native-my2c2p-sdk

## Getting started

`$ npm install react-native-my2c2p-sdk --save`

### Mostly automatic installation

`$ react-native link react-native-my2c2p-sdk`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-my2c2p-sdk` and add `RNMy2c2pSdk.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNMy2c2pSdk.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.wednesdaynight.rn2c2p.RNMy2c2pSdkPackage;` to the imports at the top of the file
  - Add `new RNMy2c2pSdkPackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-my2c2p-sdk'
  	project(':react-native-my2c2p-sdk').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-my2c2p-sdk/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-my2c2p-sdk')
  	```


## Usage
```javascript
import RNMy2c2pSdk from 'react-native-my2c2p-sdk';

// TODO: What to do with the module?
RNMy2c2pSdk;
```
  