#ifndef _CALJULIANDAYNUMBER_
#define _CALJULIANDAYNUMBER_
/**
  *File: calJulianDayNumber.h

  *Description:

   this file declares class calJulianDayNumber

  *Version: 1.0 "@(#) calJulianDayNumber. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <iostream>

// standard template
// local includes
// const declarations
// function prototypes
// forward declarations
class calRataDie;

// begin class declaration
class calJulianDayNumber
{
   friend inline std::ostream& operator<<(std::ostream& os, const calJulianDayNumber& jd);
   public:
   // constructors
      calJulianDayNumber(); // default
      calJulianDayNumber(long int integerPart, double fractionalPart = 0.0);
      calJulianDayNumber(long double jdn);
      calJulianDayNumber(const calJulianDayNumber& jdn);

   // assignment operator
      calJulianDayNumber& operator=(const calJulianDayNumber& jdn);

   // destructor
      ~calJulianDayNumber();

   // accessors
      long int IntegerPart()    const { return static_cast<long int>(pv_value); }
      double   FractionalPart() const { return pv_value - static_cast<long int>(pv_value); }

      static long double Epoch() { return pv_epoch; }

//      static long int EpochIntegerPart() { return pv_epoch_integerPart; }

   // other functionality
      calRataDie Fixed() const;

   protected:
   private:
      long double pv_value;

      static const long double pv_epoch;
};

// include any inline code here
inline std::ostream& operator<<(std::ostream& os, const calJulianDayNumber& jd)
{
   os << "(" << jd.IntegerPart() << ", " << jd.FractionalPart() << ") "; return os;
}

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
typedef calJulianDayNumber calJD;
typedef calJulianDayNumber calJDN;
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALJULIANDAYNUMBER_
