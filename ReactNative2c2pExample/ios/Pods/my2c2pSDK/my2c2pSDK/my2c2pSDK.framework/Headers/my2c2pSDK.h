//
//  my2c2pSDK.h
//  my2c2pSDK
//
//  Version : 3.0.0
//  Update At 31/03/2015
//  Created by 2c2p on 23/1/13.
//  Copyright (c) 2013 2c2p. All rights reserved.


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "my2c2pHeader.h"
#import "my2c2pPaymentFormViewController.h"
#import "paymentFormViewController.h"
#import <PassKit/PassKit.h>

#define iOS2c2pLogNoti @"iOS2c2pLogNotification"


@class PKPaymentRequest;

typedef void (^APIResponse)(NSDictionary* response);
typedef void (^APIViewControllerAppear)(UINavigationController* otpVC);
typedef void (^APIResponseError)(NSError* error);

@protocol my2c2pSDKDelegate <NSObject>

@optional
- (void)my2c2pSDKWillOpenWebView;
- (void)my2c2pSDKDidOpenWebView;
- (void)my2c2pSDKWillCloseWebViewWithCancel:(BOOL)cancel;
- (void)my2c2pSDKDidCloseWebViewWithCancel:(BOOL)cancel;

- (void)my2c2pSDKWillOpenOTPPage DEPRECATED_MSG_ATTRIBUTE("Please use my2c2pSDKWillOpenWebView");
- (void)my2c2pSDKDidOpenOTPPage DEPRECATED_MSG_ATTRIBUTE("Please use my2c2pSDKDidOpenWebView");
- (void)my2c2pSDKWillCloseOTPPageWithCancel:(BOOL)cancel DEPRECATED_MSG_ATTRIBUTE("Please use my2c2pSDKWillCloseWebViewWithCancel:");
- (void)my2c2pSDKDidCloseOTPPageWithCancel:(BOOL)cancel DEPRECATED_MSG_ATTRIBUTE("Please use my2c2pSDKDidCloseWebViewWithCancel:");

//Apple Pay
- (void)my2c2pSDKApplePayWillOpen;
- (void)my2c2pSDKApplePayWillClose;
- (void)my2c2pSDKApplePayDidClosed;

@end
@interface my2c2pSDK : NSObject <NSURLConnectionDataDelegate,NSURLConnectionDelegate,UITextFieldDelegate>

@property (nonatomic,assign) id<my2c2pSDKDelegate> delegate;
@property (nonatomic,strong) NSString* merchantID;
@property (nonatomic,strong) NSString* uniqueTransactionCode;
@property (nonatomic,strong) NSString* desc;
@property (nonatomic,assign) double amt DEPRECATED_MSG_ATTRIBUTE("Please use amount");
@property (nonatomic,assign) double amount;
@property (nonatomic,strong) NSString* currencyCode;

@property (nonatomic,strong) NSString* payCategoryID;
@property (nonatomic,strong) NSString* userDefined1;
@property (nonatomic,strong) NSString* userDefined2;
@property (nonatomic,strong) NSString* userDefined3;
@property (nonatomic,strong) NSString* userDefined4;
@property (nonatomic,strong) NSString* userDefined5;
@property (nonatomic,assign) BOOL enableStoreCard;

@property (nonatomic,strong) NSString* cardholderName DEPRECATED_MSG_ATTRIBUTE("Please use cardHolderName");
@property (nonatomic,strong) NSString* cardHolderName;

@property (nonatomic,strong) NSString* cardholderEmail  DEPRECATED_MSG_ATTRIBUTE("Please use cardHolderEmail");
@property (nonatomic,strong) NSString* cardHolderEmail;

@property (nonatomic,strong) NSString* storeCardUniqueID;

//for 3ds
@property (nonatomic,strong) NSString *request3DS;

//For non payment UI
@property (nonatomic,strong) NSString* pan;
@property (nonatomic) int cardExpireMonth;
@property (nonatomic) int cardExpireYear;
@property (nonatomic) NSString* securityCode;
@property (nonatomic,strong) NSString* panCountry;
@property (nonatomic,strong) NSString* panBank;
///////////////
@property (nonatomic) BOOL productionMode;
//for v8
@property (nonatomic) BOOL displayPaymentPage DEPRECATED_MSG_ATTRIBUTE("Please use paymentUI");
@property (nonatomic) BOOL paymentUI;

//for v8
@property (nonatomic, assign) double apiVersion DEPRECATED_MSG_ATTRIBUTE("Please use version");
@property (nonatomic, assign) double version;
@property (nonatomic, assign) BOOL ippTransaction;
@property (nonatomic, assign) int installmentPeriod;
@property (nonatomic, strong) NSString *interestType;
@property (nonatomic, assign) BOOL recurring;
@property (nonatomic, assign) BOOL storeCard;
@property (nonatomic, strong) NSString *invoicePrefix;
@property (nonatomic, assign) double recurringAmount;
@property (nonatomic, assign) BOOL allowAccumulate;
@property (nonatomic, assign) double maxAccumulateAmt;
@property (nonatomic, assign) int recurringInterval;
@property (nonatomic, assign) int recurringCount;
@property (nonatomic, strong) NSString *chargeNextDate;
@property (nonatomic, strong) NSString *promotion;
@property (nonatomic, strong) NSString *secretKey;
@property (nonatomic, strong) NSString *paymentOption;
@property (nonatomic, strong) NSString *hashKey;

//123
@property (nonatomic, strong) NSString *agentCode;
@property (nonatomic, strong) NSString *channelCode;
@property (nonatomic, strong) NSString *paymentExpiry;
@property (nonatomic, strong) NSString *mobileNo;

@property (nonatomic, strong) NSString* statementDescriptor;

//for API 9.0
@property (nonatomic,assign) My2c2pPaymentChannel paymentChannel;

///////////////

- (id) initWithPrivateKey:(NSString*)privateKey;

- (void) requestWithTarget:(id)targetViewController onResponse:(APIResponse)completion onFail:(APIResponseError)error;

- (void) requestWithTarget:(id)targetViewController AndPaymentForm:(my2c2pPaymentFormViewController *)paymentForm onResponse:(APIResponse)completion onFail:(APIResponseError)error;

// Apple Pay
- (void)requestWithTarget:(id)targetViewController PaymentRequest:(PKPaymentRequest *)pkrequest onResponse:(APIResponse)completion onFail:(APIResponseError)error;
- (BOOL)isSupportApplePay:(PKPaymentRequest *)pkrequest;

+ (BOOL)handleOpenURL:(NSURL *)url;

@end
