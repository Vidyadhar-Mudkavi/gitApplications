/**
  *File: calEpochs.cpp

  *Description:

   this file is a collection of epochs for various calendar
   (epochs are with respect to the Fixed or the RataDie calendar)

  *Version: 1.1

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

// const declarations
const char* calEpochs_id = 
   "@(#) calEpochs. implementation. ver. 1.1. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";


calEpochs::calEpochs()
{
// empty
}

// static data initialization

const long double calJulianDayNumber::pv_epoch  = -1721424.5;
const long int    calJulian::pv_epoch           = -1;

const long int    calGregorian::pv_epoch        = 1;
