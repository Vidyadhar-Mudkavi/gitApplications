/**
  *File: epochs.cpp

  *Description:

   this file is a collection of epochs for various calendar
   (epochs are with respect to the Fixed or the RataDie calendar)

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
// standard templates
// local includes
#include "epochs.h"
#include "calJulianDayNumber.h"
#include "calGregorian.h"
#include "calJulian.h"

// const declarations
const char* epochs_id = 
   "@(#) epochs. implementation. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";


epochs::epochs()
{
// empty
}

// static data initialization

const long double calJulianDayNumber::pv_epoch = -1721424.5;
const long int    calJulian::pv_epoch          = -1;

const long int calGregorian::pv_epoch = 1;
