//
//  PKCS12Helper.h
//  AWCMWrapper
//
// Copyright © 2016 VMware, Inc. All rights reserved.
// This product is protected by copyright and intellectual property laws in the United States and other countries as well as by international treaties.
// AirWatch products may be covered by one or more patents listed at http://www.vmware.com/go/patents.
//

#import <Foundation/Foundation.h>
#import <AWCMWrapper/AWCMWrapperModule.h>
/*!
 @class AWPKCS12Helper

 @brief PKCS12 Helper to extract information from p12 data.

 @discussion This class helps you extract Certificate, password information from 
 p12 file.
 */

@interface AWPKCS12Helper : AWCMWrapperModuleAPIObject

/*!
 @brief Validates if the given p12 data is valid or not.

 @discussion This method will try to validate the signature in p12 file and 
 see if it can decrypt the content.

 To use it, simply call [AWPKCS12Helper validatePKCS12Data:data password:@"sample password"];

 @param  p12Data PKCS12 Data to verify
 
 @param  password Password used to encrypt PKCS12 data.

 @return BOOL if the data is verifies with the given password
 */
+ (BOOL) validatePKCS12Data:(NSData* _Nullable)p12Data
                   password:(NSString* _Nullable)password;

/*!
 @brief Extracts certificate data from PKCS12 data.

 @discussion This method will try to validate the PKCS12 structure and returns certificate Data

 To use it, [AWPKCS12Helper certificateDataFromPKCS12Data password:@"sample password"];

 @param  p12Data PKCS12 Data to verify

 @param  password Password used to encrypt PKCS12 data.

 @return NSData NSData representation of Certificate. nil if can not be parsed or verified.
 */
+ (NSData* _Nullable) certificateDataFromPKCS12Data:(NSData* _Nullable)p12Data
                                           password:(NSString* _Nullable)password;

/*!
 @brief Extracts private key data from PKCS12 data.

 @discussion This method will try to validate the PKCS12 structure and returns private key Data

 To use it, [AWPKCS12Helper privateKeyDataFromPKCS12Data password:@"sample password"];

 @param  p12Data PKCS12 Data to verify

 @param  password Password used to encrypt PKCS12 data.

 @return NSData NSData representation of Private Key. nil if can not be parsed or verified.
 */
+ (NSData* _Nullable) privateKeyDataFromPKCS12Data:(NSData* _Nullable)p12Data
                                          password:(NSString* _Nullable)password;

/*!
 @brief Convert and export PKCS12 data to FIPS compliant PKCS12 data.

 @discussion This method will try to convert PKCS12 data to FIPS compliant PKCS12 data.

 To use it, [AWPKCS12Helper exportToFIPSFromPKCS12Data:p12Data password:@"sample password"];

 @param  p12Data PKCS12 Data to convert

 @param  password Password used to encrypt PKCS12 data.

 @return NSData NSData representation of FIPS compliant PKCS12 data. nil if the operation
         can't be completed.
 */
+ (NSData* _Nullable) exportToFIPSFromPKCS12Data:(NSData* _Nullable)p12Data
                                        password:(NSString* _Nullable)password;

/*!
 @brief Create PKCS12 data using der formatted certificate data, private key data, and password.
 
 @discussion This method will try to create PKCS12 data using der formatted certificate data, private key data, and a given password string.
 
 To use it, [AWPKCS12Helper createPKCS12DataFromDer:certificateData privateKey:privateKeyData password:@"sample password"];
 
 @param  certDerData Der formatted certificate Data
 
 @param  pKeyPemData Pem formatted privatekey data corresponding to the provided certificate data.
 
 @param  password Password used to encrypt PKCS12 data.
 
 @return NSData NSData representation of PKCS12 data. nil if the operation
 can't be completed.
 */
+ (NSData* _Nullable) createPKCS12DataFromDer:(NSData* _Nullable)certDerData privateKeyPEM:(NSData* _Nullable)pKeyPemData password:(NSString* _Nullable)password;


/*!
@brief Updated PKCS12 data to use new password and returns PKCS12 data

@discussion This method will try to update PKCS12 data to use new password, if old password is incorrect fails to update the data and returns nil

To use it, [AWPKCS12Helper updatePKCS12Password: p12Data oldPassword:@"oldPassword" newPassword:@"newPassword"];

@param  p12Data PKCS12 Data to update

@param  oldPassword current Password used to encrypt PKCS12 data.

@param  newPassword new password to encrypt PKCS12 data.

@return NSData NSData representation of PKCS12 data. nil if the operation can't be completed.
*/
+ (NSData* _Nullable)updatePKCS12Password:(NSData* _Nullable)p12Data oldPassword:(NSString* _Nullable)oldPassword newPassword:(NSString* _Nullable)newPassword;
@end
