typedef enum {
    NONE = 0,
    MPU = 1,
    UPOP ,
    ALIPAY,
    ONE_TWO_THREE,
    MASTER_PASS,
    APPLE_PAY,
    QWIK,
    LINE_PAY
} My2c2pPaymentChannel;

//Constants
#define CONSTANT_DEVICE_TYPE @"A"
#define CONSTANT_API_VERSION @"1.0"
#define CONSTANT_SDK_VERSION @"3.0.4"

//Bundle
#define BUNDLE_KEY_PAYMENT_CHANNEL @"PaymentChannel"

// Payment Options
#define PAYMENT_OPTION_ALL @"A"
#define PAYMENT_OPTION_FULL @"F"
#define PAYMENT_OPTION_INSTALLMENT @"I"
#define PAYMENT_OPTION_CREDIT_CARD @"C"
#define PAYMENT_OPTION_CREDIT_CARD_INSTALLMENT @"B"
#define PAYMENT_OPTION_ONE_TWO_THREE @"1"
#define PAYMENT_OPTION_MPU @"M"
#define PAYMENT_OPTION_UPOP @"U"
#define PAYMENT_OPTION_ALIPAY @"L"

//API
#define API_VERSION @"version"
#define API_TIMESTAMP @"timestamp"
#define API_MERCHANT_ID @"id"
#define API_AMOUNT @"amount"
#define API_UNIQUE_TRANSACTION_CODE @"uniqueTransactionCode"
#define API_CURRENCY_CODE @"currencyCode"
#define API_INTEREST_TYPE @"interestType"
#define API_PAYMENT_OPTION @"paymentOption"
#define API_REQUEST_3DS @"request3DS"
#define API_STORED_CARD_UNIQUE_ID @"storedCardUniqueID"
#define API_RECURRING @"recurring"
#define API_INVOICE_PREFIX @"invoicePrefix"
#define API_PROMOTION @"promotion"
#define API_RES_CODE @"resCode"
#define API_RES_DESC @"resDesc"
#define API_RES_FORMAT @"api_format"
#define API_FORMAT_TYPE_XML @"xml"
#define API_FORMAT_TYPE_JSON @"json"
#define API_RESPONSE_CODE_SUCCESS @"1000"
#define API_RESPONSE_CODE_MERCHANT_SUCCESS @"000"
#define API_RESPONSE_CODE_APPROVED @"00"
#define API_RESPONSE_CODE_SUCCESS_123_ENET @"1001"
#define API_RESPONSE_CODE_APPROVED_123 @"000"
#define API_RESPONSE_CODE_PENDING_123 @"001"
#define API_RESPONSE_CODE_CANCEL_123 @"003"

//Error Code
#define  API_ERROR_CODE_SDK_GENERAL @"501"
#define  API_ERROR_CODE_CONNECTION @"500"
#define  API_ERROR_CODE_SDK @"201"
#define  API_ERROR_CODE_EMPTY_MID @"03"
#define  API_ERROR_CODE_EMPTY_DESC @"303"
#define  API_ERROR_CODE_EMPTY_UNIQUE_TRANSACTION_CODE @"412"
#define  API_ERROR_CODE_EMPTY_UNIQUE_CURRENCY_CODE @"406"
#define  API_ERROR_CODE_INVALID_AMOUNT @"13"
#define  API_ERROR_CODE_EMPTY_PAN @"03"
#define  API_ERROR_CODE_EMPTY_SECRET_KEY @"99"
#define  API_ERROR_CODE_VALIDATE_FAIL @"99"

//Error Message
#define API_ERROR_MESSAGE_INVALID_JSON @"Invalid json"
#define API_ERROR_MESSAGE_INVALID_SECURE_PAY_JSON @"Invalid securePay json"
#define API_ERROR_MESSAGE_CONNECTION_TIMEOUT @"Connection Timeout"
#define API_ERROR_MESSAGE_NO_CONNECTION @"Unable to connect to server. Please check your internet connection"
#define API_ERROR_MESSAGE_2C2P_INVALID_KEY @"Invalid My2c2pKey"
#define API_ERROR_MESSAGE_2C2P_PARAM_NOT_SET @"My2c2pSDK param is not set"
#define API_ERROR_MESSAGE_JSON_MECHANT_DETAILS_NULL @"Merchent details is null"
#define API_ERROR_MESSAGE_JSON_MECHANT_DETAILS_NOT_FOUND @"Merchent details not found"
#define API_ERROR_MESSAGE_UNABLE_CONNECT_SERVER @"Couldn't connect to server, Please try again."
#define API_ERROR_MESSAGE_PARSE_JSON @"parsing error"
#define API_ERROR_MESSAGE_MECHANT_INFO_NULL @"MerchantInfo is empty"
#define API_ERROR_MESSAGE_FONT_RAW_MISSING @"raw fonts file missing! font_myanmar_thai_samsung & font_myanmar_thai_smartzg."
#define API_ERROR_MESSAGE_INVALID_OPEN_URL @"Open Url not found"
#define API_ERROR_MESSAGE_WEB_BROWSER_NOT_FOUND @"Web browser app not found"

//My2c2pResponse
#define API_RESPONSE_STATUS_CANCEL @"C"
#define API_RESPONSE_STATUS_FAIL @"F"
#define API_RESPONSE_STATUS_CODE @"301"
#define API_RESPONSE_REASON_CANCEL @"The transaction is canceled"
#define API_RESPONSE_REASON_CANCEL_123 @"The transaction is canceled"
#define API_RESPONSE_REASON_PENDING_123 @"success (pending)"

//123
#define API_123_CHANNEL_CODE_WEB_PAY @"WEBPAY"
#define API_123_PAYMENT_CHANNEL_CODE_CASH_PAYMENT @"002"
#define API_123_PAYMENT_CHANNEL_CODE_DIRECT_DEBIT @"003"
