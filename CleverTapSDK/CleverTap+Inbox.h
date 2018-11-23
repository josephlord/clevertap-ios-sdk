@import Foundation;
#import "CleverTap.h"

@interface CleverTapInboxMessage : NSObject

@property (nullable, nonatomic, copy, readonly) NSString *title;
@property (nullable, nonatomic, copy, readonly) NSString *body;
@property (nullable, nonatomic, copy, readonly) NSString *imageUrl;
@property (nullable, nonatomic, copy, readonly) NSString *actionUrl;
@property (nullable, nonatomic, copy, readonly) NSDate *date;
@property (nullable, nonatomic, copy, readonly) NSDate *expires;
@property (nullable, nonatomic, copy, readonly) NSString *messageId;
@property (nullable, nonatomic, copy, readonly) NSString *type;
@property (nullable, nonatomic, copy, readonly) NSDictionary *media;
@property (nullable, nonatomic, copy, readonly) NSDictionary *json;
@property (nullable, nonatomic, copy, readonly) NSDictionary *customData;
@property (nonatomic, assign, readonly) BOOL isRead;

@end

@protocol CleverTapInboxViewControllerDelegate <NSObject>
- (void)messageDidSelect:(CleverTapInboxMessage *)message;
@end

@interface CleverTapInboxStyleConfig : NSObject

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *cellBackgroundColor;
@property (nonatomic, strong) UIColor *contentBackgroundColor;
@property (nonatomic, strong) UIColor *cellBorderColor;
@property (nonatomic, strong) UIColor *contentBorderColor;
@property (nonatomic, strong) UIColor *messageTitleColor;
@property (nonatomic, strong) UIColor *messageBodyColor;

@end

@interface CleverTapInboxViewController : UITableViewController

@end

typedef void (^CleverTapInboxSuccessBlock)(BOOL success);
typedef void (^CleverTapInboxUpdatedBlock)(void);

@interface CleverTap (Inbox)

- (void)initializeInboxWithCallback:(CleverTapInboxSuccessBlock _Nonnull)callback;

- (NSUInteger)getInboxMessageCount;

- (NSUInteger)getInboxMessageUnreadCount;

- (NSArray<CleverTapInboxMessage *> * _Nonnull )getAllInboxMessages;

- (NSArray<CleverTapInboxMessage *> * _Nonnull )getUnreadInboxMessages;

- (CleverTapInboxMessage * _Nullable )getInboxMessageForId:(NSString *)messageId;

- (void)deleteInboxMessage:(CleverTapInboxMessage * _Nonnull )message;

- (void)markReadInboxMessage:(CleverTapInboxMessage * _Nonnull) message;

- (void)registerInboxUpdatedBlock:(CleverTapInboxUpdatedBlock _Nonnull)block;

- (CleverTapInboxViewController * _Nullable)newInboxViewControllerWithConfig:(CleverTapInboxStyleConfig * _Nullable )config andDelegate:(id<CleverTapInboxViewControllerDelegate> _Nullable )delegate;


@end
