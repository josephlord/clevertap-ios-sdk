
#import "CTMessageMO.h"

@class CTUserMO;

NS_ASSUME_NONNULL_BEGIN

@interface CTMessageMO (CoreDataProperties)
- (instancetype)initWithJSON:(NSDictionary *)json forContext:(NSManagedObjectContext *)context;
- (NSDictionary *)toJSON;
- (instancetype)updateWithJson:(NSDictionary *)json forMessage:(CTMessageMO*)msg;

@property (nullable, nonatomic, copy) NSDate *date;
@property (nullable, nonatomic, copy) NSDate *expires;
@property (nullable, nonatomic, copy) NSString *id;
@property (nullable, nonatomic, retain) CTUserMO *user;
@property (nullable, nonatomic, copy) id json;
@property (nonatomic, assign) BOOL isRead;

@end

NS_ASSUME_NONNULL_END
