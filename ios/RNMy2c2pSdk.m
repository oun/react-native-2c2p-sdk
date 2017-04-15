
#import <React/RCTLog.h>
#import "RNMy2c2pSdk.h"

@implementation RNMy2c2pSdk

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}
RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(setup: (NSString *)privateKey) {
    _my2c2pSDK = [[my2c2pSDK alloc] initWithPrivateKey:privateKey];
    _my2c2pSDK.version = 9.0;
}

RCT_EXPORT_METHOD(requestPayment: (NSDictionary *)details resolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject)
{
    RCTLogInfo(@"Request payment: %@", details);

    _my2c2pSDK.merchantID = details[@"merchantID"];
    _my2c2pSDK.uniqueTransactionCode = details[@"uniqueTransactionCode"];
    _my2c2pSDK.desc = details[@"desc"];
    _my2c2pSDK.amount = [details[@"amount"] doubleValue];
    _my2c2pSDK.currencyCode = details[@"currencyCode"];
    _my2c2pSDK.cardHolderName = details[@"cardHolderName"];
    _my2c2pSDK.cardHolderEmail = details[@"cardHolderEmail"];
    //  _my2c2pSDK.storeCardUniqueID = self.storecarduniqueID.text;
    _my2c2pSDK.pan = details[@"pan"];
    _my2c2pSDK.cardExpireMonth = [details[@"cardExpireMonth"] integerValue];
    _my2c2pSDK.cardExpireYear = [details[@"cardExpireYear"] integerValue];
    _my2c2pSDK.securityCode = details[@"securityCode"];
    _my2c2pSDK.panCountry = details[@"panCountry"];
    //  _my2c2pSDK.panBank = @"";
    //  _my2c2pSDK.request3DS = self.request3DS.text;
    //  _my2c2pSDK.hashKey = self.hashKey.text;
    //  _my2c2pSDK.paymentChannel = (My2c2pPaymentChannel)self.paymentChannel.selectedSegmentIndex;
    //  _my2c2pSDK.paymentOption = _paymentOptions[self.paymentOption.selectedSegmentIndex];
    //  _my2c2pSDK.statementDescriptor = self.statementDescriptor.text;
    //  _my2c2pSDK.promotion = self.binPromotionTextField.text;

    //  _my2c2pSDK.agentCode = self.agentCodeTextField.text;
    //  _my2c2pSDK.channelCode = self.channelCodeTextField.text;
    //  _my2c2pSDK.paymentExpiry = self.paymentExpiryTextField.text;
    //  _my2c2pSDK.mobileNo = self.mobileNoTextField.text;

    _my2c2pSDK.payCategoryID = details[@"payCategoryID"];
    _my2c2pSDK.userDefined1 = details[@"userDefined1"];
    _my2c2pSDK.userDefined2 = details[@"userDefined2"];
    _my2c2pSDK.userDefined3 = details[@"userDefined3"];
    _my2c2pSDK.userDefined4 = details[@"userDefined4"];
    _my2c2pSDK.userDefined5 = details[@"userDefined5"];

    _my2c2pSDK.enableStoreCard = NO;

    _my2c2pSDK.productionMode = NO;

    //For Allow Payment and non Payment
    _my2c2pSDK.secretKey = @"u6Y6kxBM7ai2";
    _my2c2pSDK.storeCard = NO;
    //  _my2c2pSDK.recurring = self.recurringPayment.on;
    //  _my2c2pSDK.recurringAmount = [self.recurringAmount.text doubleValue];
    //  _my2c2pSDK.recurringCount = [self.recurringCount.text intValue];
    //  _my2c2pSDK.recurringInterval = [self.recurringInterval.text intValue];
    //  _my2c2pSDK.invoicePrefix = self.invoicePrefix.text;


    _my2c2pSDK.ippTransaction = NO;
    //  _my2c2pSDK.installmentPeriod = [self.installmentperiod.text intValue];
    //  _my2c2pSDK.interestType = self.interesttype.text;


    _my2c2pSDK.paymentUI = NO;

    AppDelegate *delegate = (AppDelegate *)[[UIApplication sharedApplication] delegate];

    // Determine what controller is in the front based on if the app has a navigation controller or a tab bar controller
    UIViewController* showingController;
    if([delegate.window.rootViewController isKindOfClass:[UINavigationController class]]){

        showingController = ((UINavigationController*)delegate.window.rootViewController).visibleViewController;
    } else if ([delegate.window.rootViewController isKindOfClass:[UITabBarController class]]) {

        showingController = ((UITabBarController*)delegate.window.rootViewController).selectedViewController;
    } else {

        showingController = (UIViewController*)delegate.window.rootViewController;
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

@end
  
