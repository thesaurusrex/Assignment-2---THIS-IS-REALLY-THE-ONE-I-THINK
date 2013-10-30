//
//  MathUtils.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-01-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <algorithm>

#if WIN32
#define MAX_VALUE(a,b) max(a,b)
#define MIN_VALUE(a,b) min(a,b)
#endif

#ifdef __APPLE__
#define MAX_VALUE(a,b) std::max(a,b)
#define MIN_VALUE(a,b) std::min(a,b)
#endif


class MathUtils
{
public:
  //Returns the next power of 2 for the value
  static unsigned int nextPowerOf2(unsigned int value);
  
  //Conveniance methods to convert between degrees and radians
  static float radiansToDegrees(float radians);
  static float degressToRadians(float degrees);
  
  //Determines wether value A and B are within a certain range
  static bool withinRange(float valueA, float valueB, float range);
};

#endif
