/**
  *File: calEpochs.cpp

  *Description:

   this file is a collection of epochs for various calendar
   (epochs are with respect to the Fixed or the RataDie calendar)

  *Version: 1.2

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
// standard templates

// local includes
#include "calEpochs.h"
#include "calGregorian.h"
#include "calJulianDayNumber.h"

#if 0
#include "calJulian.h"
#include "calOldHinduSolar.h"
#endif

// const declarations
const char* calEpochs_id = 
   "@(#) calEpochs. implementation. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";


calEpochs::calEpochs()
{
// empty
}

// static data initialization

#if 0
template <typename T>
const long int    calGregorian<T>::pv_epoch        =  1;
#endif
const long int    calGregorian<int>::pv_epoch        =  1;
const long double calJulianDayNumber<int>::pv_epoch  = -1721424.5;  // (-4713-11-24, Noon, Gregorian)

#if 0
const long double calJulianDayNumber::pv_epoch  = -1721424.5;  // (-4713-11-24, Noon, Gregorian)
const long int    calJulian::pv_epoch           = -1;
const long int    calOldHinduSolar::pv_epoch    = -1132959;    // (-3101-01-23 Gregorian)
#endif


