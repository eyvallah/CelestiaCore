//
// CelestiaUtil.h
//
// Copyright © 2020 Celestia Development Team. All rights reserved.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//

#import <Foundation/Foundation.h>

@class CelestiaVector;

NS_ASSUME_NONNULL_BEGIN

@interface CelestiaDMS : NSObject

@property NSInteger hours;
@property NSInteger degrees;
@property NSInteger minutes;
@property double seconds;

@property (readonly) double decimal;

- (instancetype)initWithDecimal:(double)decimal;
- (instancetype)initWithDegrees:(NSInteger)degrees minutes:(NSInteger)minutes seconds:(double)seconds;

@end

@interface NSDate (Astro)

@property (readonly) double julianDay;

+ (instancetype)dateWithJulian:(double)jd;

@end

@interface CelestiaAstroUtils : NSObject

+ (nullable NSString *)stringWithCoordinateSystem:(int)n;
+ (int)coordinateSystem:(NSString *)coord;
+ (double)speedOfLight;
+ (double)J2000;
+ (double)G;
+ (double)solarMass;
+ (double)earthMass;
+ (float)lumToAbsMag:(float)lum;
+ (float)lumToAppMag:(float)lum lightYears:(float)lyrs;
+ (float)absMagToLum:(float)mag;
+ (float)absToAppMag:(float)mag lightYears:(float)lyrs;
+ (float)appToAbsMag:(float)mag lightYears:(float)lyrs;
+ (float)lightYearsToParsecs:(float)ly;
+ (float)parsecsToLightYears:(float)pc;
+ (double)lightYearsToKilometers:(double)ly;
+ (double)kilometersToLightYears:(double)km;
+ (double)lightYearsToAU:(double)ly;
+ (double)AUtoLightYears:(double)au;
+ (double)kilometersToAU:(double)km;
+ (double)AUtoKilometers:(double)au;
+ (double)microLightYearsToKilometers:(double)mly;
+ (double)kilometersToMicroLightYears:(double)km;
+ (double)microLightYearsToAU:(double)mly;
+ (double)AUtoMicroLightYears:(double)au;
+ (double)secondsToJulianDate:(double)sec;
+ (double)julianDateToSeconds:(double)jd;
+ (NSArray<NSNumber *> *)anomaly:(double)meanAnamaly eccentricity:(double)eccentricity;
+ (double)meanEclipticObliquity:(double)jd;
+ (CelestiaVector *)celToJ2000Ecliptic:(CelestiaVector *)cel;
+ (CelestiaVector *)eclipticToEquatorial:(CelestiaVector *)ecliptic;
+ (CelestiaVector *)equatorialToGalactic:(CelestiaVector *)equatorial;
+ (CelestiaVector *)rectToSpherical:(CelestiaVector *)rect;

@end

NS_ASSUME_NONNULL_END
