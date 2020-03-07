//
//  CelestiaGalaxy.h
//  celestia
//
//  Created by Bob Ippolito on Sat Jun 08 2002.
//  Copyright (c) 2002 Chris Laurel. All rights reserved.
//

#import <CelestiaCore/CelestiaAstroObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface CelestiaGalaxy : CelestiaAstroObject

@property (readonly) NSString *type;

@property float radius;
@property float detail;

@end

NS_ASSUME_NONNULL_END
