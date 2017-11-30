//
//  PQCheck Client Library
//
//  Copyright © 2017 Post-Quantum. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PQCheckSample : NSObject

@property (nonatomic, nonnull) NSString* uuid;
@property (nonatomic, nonnull) NSString* sha256;
@property (nonatomic, nonnull) NSDate *created;
@property (nonatomic, nonnull) NSString *contentType;
@property (nonatomic)   NSUInteger numberOfBytes;

- (nullable id)initWithJSONDictionary:(nullable NSDictionary*)json;

@end
