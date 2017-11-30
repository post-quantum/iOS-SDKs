//
//  PQCheck Client Library
//
//  Copyright © 2017 Post-Quantum. All rights reserved.
//

#import  <Foundation/Foundation.h>

@interface PQCheckAssertion : NSObject

@property (nonatomic, copy, nonnull) NSString* uuid;
@property (nonatomic, copy, nonnull) NSString* measure;
@property (nonatomic, copy, nonnull) NSString* of;
@property (nonatomic, nullable) NSNumber *accuracy;

- (nonnull id)initWithJSONDictionary:(nonnull NSDictionary*)json;
- (nonnull NSDictionary*)toJson;

+ (nonnull instancetype)assertionWithSpokenText:(nonnull NSString*)spokenText;

@end
