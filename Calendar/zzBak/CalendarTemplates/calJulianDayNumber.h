#ifndef _CALJULIANDAYNUMBER_
#define _CALJULIANDAYNUMBER_

/**
  *File: calJulianDayNumber.h

  *Description:

   this file declares class calJulianDayNumber

  *Version: 1.2 "@(#) calJulianDayNumber. header. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <iostream>

// standard template
#include "calBase.h"

// local includes
// const declarations
// function prototypes
// forward declarations
template <typename T>
class tCalRataDie;

// begin class declaration
template <typename T>
class tCalJulianDayNumber : public tCalBase<T>
{
   friend inline std::ostream& operator<<(std::ostream& os, const tCalJulianDayNumber& jd);

   public:
   // constructors
      tCalJulianDayNumber(); // default
      tCalJulianDayNumber(long int integerPart, double fractionalPart = 0.0);
      tCalJulianDayNumber(long double jdn);
      tCalJulianDayNumber(const tCalJulianDayNumber& jdn);

   // assignment operator
      tCalJulianDayNumber& operator=(const tCalJulianDayNumber& jdn);

   // destructor
      ~tCalJulianDayNumber();

   // accessors
      long int IntegerPart()    const { return static_cast<long int>(pv_value); }
      double   FractionalPart() const { return pv_value - static_cast<long int>(pv_value); }

      static long double Epoch() { return pv_epoch; }

//      static long int EpochIntegerPart() { return pv_epoch_integerPart; }

   // other functionality

//      tCalRataDie Fixed() const;

   protected:

   private:
      void _ComputeFixed();

   private:
      long double pv_value;

      static const long double pv_epoch;
};

// include any inline code here
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const tCalJulianDayNumber<T>& jd)
{
   os << "(" << jd.IntegerPart() << ", " << jd.FractionalPart() << ") "; return os;
}

#include "calJulianDayNumber.cpp"
/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
//typedef tCalJulianDayNumber calJD;
//typedef tCalJulianDayNumber calJDN;
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALJULIANDAYNUMBER_
