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
#include "calJulianDayNumber.h"
#include "calGregorian.h"
#include "calJulian.h"
#include "calOldHinduSolar.h"

// const declarations
const char* calEpochs_id = 
   "@(#) calEpochs. implementation. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";


calEpochs::calEpochs()
{
// empty
}

// static data initialization

template <typename T>
const long double tCalJulianDayNumber<T>::pv_epoch  = -1721424.5;  // (-4713-11-24, Noon, Gregorian)

template <typename T>
const long int    tCalJulian<T>::pv_epoch           = -1;

template <typename T>
const long int    tCalGregorian<T>::pv_epoch        =  1;

template <typename T>
const long int    tCalOldHinduSolar<T>::pv_epoch    = -1132959;    // (-3101-01-23 Gregorian)



