
#import <React/RCTLog.h>
#import "RNMy2c2pSdk.h"

@implementation RNMy2c2pSdk

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}
RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(setup: (NSString *)privateKey production: (BOOL)productionMode) {
    RCTLogInfo(@"Initialize with params: production=%@", productionMode);
    _my2c2pSDK = [[my2c2pSDK alloc] initWithPrivateKey:privateKey];
    _my2c2pSDK.version = 9.0;
    _my2c2pSDK.productionMode = productionMode;
}

RCT_EXPORT_METHOD(requestPayment: (NSDictionary *)details resolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject)
{
    RCTLogInfo(@"Request payment: %@", details);

    _my2c2pSDK.merchantID = details[@"merchantID"];
    _my2c2pSDK.secretKey = details[@"secretKey"];
    _my2c2pSDK.uniqueTransactionCode = details[@"uniqueTransactionCode"];
    _my2c2pSDK.desc = details[@"desc"];
    _my2c2pSDK.amount = [details[@"amount"] doubleValue];
    _my2c2pSDK.currencyCode = details[@"currencyCode"];
    _my2c2pSDK.cardHolderName = details[@"cardHolderName"];
    _my2c2pSDK.cardHolderEmail = details[@"cardHolderEmail"];
    _my2c2pSDK.storeCardUniqueID = details[@"storeCardUniqueID"];
    _my2c2pSDK.pan = details[@"pan"];
    _my2c2pSDK.cardExpireMonth = [details[@"cardExpireMonth"] integerValue];
    _my2c2pSDK.cardExpireYear = [details[@"cardExpireYear"] integerValue];
    _my2c2pSDK.securityCode = details[@"securityCode"];
    _my2c2pSDK.panCountry = details[@"panCountry"];
    _my2c2pSDK.panBank = details[@"panBank"];
    _my2c2pSDK.request3DS = details[@"request3DS"];
    //  _my2c2pSDK.hashKey = self.hashKey.text;
    _my2c2pSDK.paymentChannel = details[@"paymentChannel"];
    //  _my2c2pSDK.paymentOption = _paymentOptions[self.paymentOption.selectedSegmentIndex];
    _my2c2pSDK.statementDescriptor = details[@"statementDescriptor"];
    [self nilSafeSetPropertyValue: details[@"promotion"] forKey: @"promotion"];

    // 123
    _my2c2pSDK.agentCode = details[@"agentCode"];
    _my2c2pSDK.channelCode = details[@"channelCode"];
    _my2c2pSDK.paymentExpiry = details[@"paymentExpiry"];
    _my2c2pSDK.mobileNo = details[@"mobileNo"];

    _my2c2pSDK.payCategoryID = details[@"payCategoryID"];
    _my2c2pSDK.userDefined1 = details[@"userDefined1"];
    _my2c2pSDK.userDefined2 = details[@"userDefined2"];
    _my2c2pSDK.userDefined3 = details[@"userDefined3"];
    _my2c2pSDK.userDefined4 = details[@"userDefined4"];
    _my2c2pSDK.userDefined5 = details[@"userDefined5"];

    [self nilSafeSetBoolPropertyValue: details[@"enableStoreCard"] forKey: @"enableStoreCard"];

    //For Allow Payment and non Payment
    [self nilSafeSetBoolPropertyValue: details[@"storeCard"] forKey: @"storeCard"];
    //  _my2c2pSDK.recurring = self.recurringPayment.on;
    //  _my2c2pSDK.recurringAmount = [self.recurringAmount.text doubleValue];
    //  _my2c2pSDK.recurringCount = [self.recurringCount.text intValue];
    //  _my2c2pSDK.recurringInterval = [self.recurringInterval.text intValue];
    //  _my2c2pSDK.invoicePrefix = self.invoicePrefix.text;


    _my2c2pSDK.ippTransaction = NO;
    //  _my2c2pSDK.installmentPeriod = [self.installmentperiod.text intValue];
    //  _my2c2pSDK.interestType = self.interesttype.text;

    [self nilSafeSetBoolPropertyValue: details[@"paymentUI"] forKey: @"paymentUI"];

    UIWindow *window = [[[UIApplication sharedApplication] delegate] window];

    // Determine what controller is in the front based on if the app has a navigation controller or a tab bar controller
    UIViewController* showingController;
    if([window.rootViewController isKindOfClass:[UINavigationController class]]){

        showingController = ((UINavigationController*)window.rootViewController).visibleViewController;
    } else if ([window.rootViewController isKindOfClass:[UITabBarController class]]) {

        showingController = ((UITabBarController*)window.rootViewController).selectedViewController;
    } else {

        showingController = (UIViewController*)window.rootViewController;
    }
    _my2c2pSDK.delegate = showingController;

    dispatch_async(dispatch_get_main_queue(), ^{
        [_my2c2pSDK requestWithTarget: showingController onResponse:^(NSDictionary *response)
         {
             RCTLogInfo(@"%@",response);
             resolve(response);

         } onFail:^(NSError *error) {

             RCTLogInfo(@"%@",error);
             reject(@"payment failed", @"The request payment failed", error);
         }];
    });
}

- (void)nilSafeSetPropertyValue: (NSObject *)value forKey: (NSString *)key
{
    if (value) {
        [_my2c2pSDK setValue: value forKey:key];
    }
}

- (void)nilSafeSetBoolPropertyValue: (NSObject *)value forKey: (NSString *)key
{
    if (value) {
        [_my2c2pSDK setValue: (NSNumber *)value forKey:key];
    }
}

@end
  
