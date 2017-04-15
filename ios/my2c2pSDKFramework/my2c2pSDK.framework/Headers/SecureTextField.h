//
//  SecureTextField.h
//  SecureTextField
//
//  Created by 2c2p on 18/1/16.
//  Copyright © 2016 2c2p. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface SecureTextField : UITextField

@property (nonatomic,assign) BOOL productionMode;

- (NSString *)getErrorMessageFromValidateCVV;
- (NSString *)getErrorMessageFromValidateDate;
- (NSString *)getErrorMessageFromValidateCard;
- (NSArray *)textMY;
- (BOOL)shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string AndMaxLength:(int)length;
- (BOOL)shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string AllowOnlyNumber:(BOOL)allowOnlyNumber AndMaxLength:(int)length;

- (BOOL)isSupportCardFromArray:(NSArray *)availableCards;
@end
