//
//  PQCheck Client Library
//
//  Copyright © 2017 Post-Quantum. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PQCheckIdentity.h"
#import "PQCheckCheck.h"

@interface PQCheckClientLib : NSObject


/*!
 * @discussion Creates a 'check' using a recorded video of the user reading text aloud.
 * @param identity If nil an identity will be created and the recording becomes the reference for later checks. If non-nil the recording is checked against the original video used to create the identity and the degree of confidence for the comparison is in PQCheckCheck.faceConsistency and PQCheckCheck.voiceConsistency.
 * @param spokenText The text read out by the user in the video.
 * @param deadline The time beyond which the server should reject video uploads for this check. If nil defaults to 5 minutes after now.
 * @param videoUrl URL for the video recording (typically a local file)
 * @param mimeType The video's MIME type
 * @param completionBlock Block that receives the result on the main thread.
 * @return A cancelable NSOperation
 */
+ (nonnull NSOperation*)identity:(nullable PQCheckIdentity*)identity
       createCheckWithSpokenText:(nonnull NSString*)spokenText
                        deadline:(nullable NSDate*)deadline
                        videoUrl:(nonnull NSURL*)videoUrl
                        mimeType:(nonnull NSString*)mimeType
                     httpHeaders:(nullable NSDictionary<NSString *, NSString *>*)httpHeaders
                 completionBlock:(nonnull void (^)(PQCheckIdentity* __nullable identity, PQCheckCheck* __nullable check, NSError* __nullable error))completionBlock;

/*!
 * @discussion Updates a given PQCheckIdentity with the latest server data.
 * @param identity The identity to be updated.
 */
+ (nonnull NSOperation*)identity:(nonnull PQCheckIdentity*)identity
       updateWithCompletionBlock:(nonnull void (^)(PQCheckIdentity* __nullable identity, NSError* __nullable error))completionBlock;

+ (nonnull NSOperation*)postCheckSample:(nonnull NSURL*)sampleUrl
               videoUrl:(nonnull NSURL*)videoUrl
               mimeType:(nonnull NSString*)mimeType
            httpHeaders:(nullable NSDictionary<NSString *, NSString *>*)httpHeaders
        completionBlock:(void (^__nullable)(PQCheckCheck* __nullable check, NSError* __nullable error))completionBlock;

@end
