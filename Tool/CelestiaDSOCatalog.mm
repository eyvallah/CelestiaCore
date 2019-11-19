//
//  CelestiaDSOCatalog.m
//  CelestiaCore
//
//  Created by 李林峰 on 2019/8/10.
//  Copyright © 2019 李林峰. All rights reserved.
//

#import "CelestiaDSOCatalog+Private.h"
#import "CelestiaDSO+Private.h"

#define BROWSER_MAX_DSO_COUNT   300

@interface CelestiaDSOCatalog () {
    DSODatabase *d;
}

@end

@implementation CelestiaDSOCatalog (Private)

- (instancetype)initWithDatabase:(DSODatabase *)database {
    self = [super init];
    if (self) {
        d = database;
    }
    return self;
}

- (DSODatabase *)database {
    return d;
}

@end

@implementation CelestiaDSOCatalog

- (NSInteger)count {
    return d->size();
}

- (CelestiaDSO *)objectAtIndex:(NSInteger)index {
    return [[CelestiaDSO alloc] initWithDSO:d->getDSO((uint32_t)index)];
}

- (NSString *)dsoName:(CelestiaDSO *)dso {
    return [NSString stringWithUTF8String:d->getDSOName([dso DSO]).c_str()];
}

- (NSArray<NSString *> *)completionForName:(NSString *)name {
    std::vector<std::string> names = d->getCompletion([name UTF8String]);
    NSMutableArray *array = [NSMutableArray arrayWithCapacity:names.size()];
    for (int i = 0; i < names.size(); i++) {
        [array addObject:[NSString stringWithUTF8String:names[i].c_str()]];
    }
    return array;
}

@end
