//
//  PQCheck Client Library
//
//  Copyright © 2017 Post-Quantum. All rights reserved.
//

#import  <Foundation/Foundation.h>

@interface PQCheckIdentity : NSObject <NSCoding>

@property (nonatomic, copy, nonnull) NSString* uuid;
@property (nonatomic, nullable) NSArray* checks;
@property (nonatomic, nullable) NSString* ownerToken;

- (nullable id)initWithJSONDictionary:(nullable NSDictionary *)jsonDictionary;

@end
