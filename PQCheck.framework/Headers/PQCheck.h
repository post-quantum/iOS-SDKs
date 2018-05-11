//
//  Copyright © 2017 Post-Quantum. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PQCheckType) {
    PQCheckTypeFaceOnly,
    PQCheckTypeFaceOnlyFast,
    PQCheckTypeSpokenPhrase,
    PQCheckTypeSpokenNumber,
    PQCheckTypeSpokenNumberSequence
};

typedef NS_ENUM(NSInteger, PQSpeechAwareness) {
    PQSpeechAwarenessNone,
    PQSpeechAwarenessVAD,
    PQSpeechAwarenessSTT
};

typedef NS_ENUM(NSInteger, PQDemoMode) {
    PQDemoModeOff,
    PQDemoModeCheckPassed,
    PQDemoModeCheckFailed,
    PQDemoModeError
};

typedef NS_ENUM(NSInteger, PQCheckResult) {
    PQCheckResultNotRun,    // sample not uploaded or error during upload
    PQCheckResultCompleted,  // sample has been uploaded but the result is not yet known
    PQCheckResultMatchGood, // sample has been uploaded and processed and the result is GOOD
    PQCheckResultMatchBad   // sample has been uploaded and processed and the result is BAD
};


typedef void (^PQCheckResultBlock)(NSError* error, PQCheckResult result, NSString* httpResponseBody);

@interface PQCheck : NSObject

// General properties
@property (nonatomic, readonly) NSURL* sampleUrl;
@property (nonatomic) PQCheckType checkType;
@property (nonatomic) PQSpeechAwareness speechAwareness;
@property (nonatomic) NSString* spoken;
@property (nonatomic) PQDemoMode demoMode;
@property (nonatomic) bool isForRegistration;


// Voice Activity Detection (VAD) parameters
@property (nonatomic) float vadMinimumVolumeDB;      // -45
@property (nonatomic) int vadSpeechVolumeDeltaMin;   // 7     (dB gain for non-speech to speech, range 1 to 20)
@property (nonatomic) int vadPhraseStrictness;       // 0
@property (nonatomic) int vadPhraseSamplePeriodMs;   // 400
@property (nonatomic) int vadPhraseOnThreshold;      // 8
@property (nonatomic) int vadPhraseOffThreshold;     // -20
@property (nonatomic) int vadSequenceStrictness;     // 0
@property (nonatomic) int vadSequenceSamplePeriodMs; // 200
@property (nonatomic) int vadSequenceOnThreshold;    // 5
@property (nonatomic) int vadSequenceOffThreshold;   // -5


// Min & max recording durations
@property (nonatomic) float minRecordDuration; // defaults to 2 seconds
@property (nonatomic) float maxRecordDuration; // defaults to 10 seconds

// Callbacks
@property (nonatomic, copy) PQCheckResultBlock gotResultBlock;
@property (nonatomic, copy) PQCheckResultBlock completeBlock;

// Theme
@property (nonatomic) NSString* fontBold;
@property (nonatomic) NSString* fontSemibold;
@property (nonatomic) NSString* fontRegular;
@property (nonatomic) NSString* fontLight;
@property (nonatomic) UIColor* colorBackground;
@property (nonatomic) UIColor* colorToolbarBackground;
@property (nonatomic) UIColor* colorToolbarForeground;
@property (nonatomic) UIColor* colorCameraOverlayBackground;
@property (nonatomic) UIColor* colorGaugeLabels;
@property (nonatomic) UIColor* colorGaugeValues;
@property (nonatomic) UIColor* colorFilledOval;
@property (nonatomic) UIColor* colorAccent;
@property (nonatomic) UIColor* colorConditionGood;
@property (nonatomic) UIColor* colorConditionBad;
@property (nonatomic) UIColor* colorTextNormal;
@property (nonatomic) UIColor* colorTextRecognized;
@property (nonatomic) UIColor* colorTextDone;
@property (nonatomic) UIColor* colorNumberSequenceCompleted;
@property (nonatomic) UIImage* imageVoiceRecording;
@property (nonatomic) bool colouredPreview; // defaults to false
@property (nonatomic) NSString* successMessage;
@property (nonatomic) NSString* customDoneTitlePrefix;
@property (nonatomic) bool verboseLogging;
@property (nonatomic) bool skipResultScreen;


// API
@property (nonatomic) NSDictionary<NSString *, NSString *>* httpHeaders;

+ (instancetype)createCheckForSampleUrl:(NSURL*)sampleUrl;

- (void)startFromViewController:(UIViewController*)viewController;

+ (void)startVadTuner;

@end
