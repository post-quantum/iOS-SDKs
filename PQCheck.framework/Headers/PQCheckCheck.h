//
//  PQCheck Client Library
//
//  Copyright © 2017 Post-Quantum. All rights reserved.
//

#import  <Foundation/Foundation.h>
#import "PQCheckSample.h"
#import "PQCheckAssertion.h"

@interface PQCheckCheck : NSObject

@property (nullable, nonatomic) NSString* uuid;
@property (nullable, nonatomic) NSDate* dateCreated;
@property (nonnull, nonatomic) NSDate* dateDeadline;
@property (nullable, nonatomic) PQCheckSample* sample;
@property (nullable, nonatomic) NSDictionary* attestations;
@property (nonnull, nonatomic) NSArray<PQCheckAssertion*>* assertions;
@property (nullable, nonatomic) NSString* hrefSelf;
@property (nullable, nonatomic) NSString* hrefParent;
@property (nullable, nonatomic) NSString* hrefSample;
@property (nullable, nonatomic) NSNumber* faceConsistency;
@property (nullable, nonatomic) NSNumber* voiceConsistency;


- (nullable id)initWithJSONDictionary:(nullable NSDictionary *)jsonDictionary;
- (nullable id)initWithSpokenText:(nonnull NSString*)spokenText;
- (nonnull NSDictionary*)toJson;
- (BOOL)isFaceConsistent;
- (BOOL)isVoiceConsistent;
- (BOOL)hasAssertions;

@end
