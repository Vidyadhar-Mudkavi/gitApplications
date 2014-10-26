#ifndef _CALRATADIE_
#define _CALRATADIE_
/**
  *File: calRataDie.h

  *Description:

   this file declares class calRataDie

  *Version: 1.1 "@(#) calRataDie. header. ver. 1.1. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <iostream>

// standard template
#include <string>
#include <vector>

// local includes
#include "calFn.h"

#if 0
// const declarations
namespace cal
{
   static char* weekDay[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", 
                               "Thursday", "Friday", "Saturday"
                             };
}
#endif

// function prototypes
// forward declarations
class calGregorian;
class calJulianDayNumber;
class calJulian;
class calIso;

// begin class declaration
class calRataDie
{
   friend class calFn;
   friend class calGregorian;
   friend inline std::ostream& operator<<(std::ostream& os, const calRataDie& rd);
   public:
   // constructors
      calRataDie(); // default
      calRataDie(long int date);
      calRataDie(const calRataDie& rata_die);

   // assignment operator
      calRataDie& operator=(const calRataDie& rata_die);
      inline calRataDie& operator=(long int fixed_date);

   // destructor
      ~calRataDie();

   // other functionality
      calGregorian Gregorian() const;
      calJulian    Julian() const;
      calIso       Iso() const;

      long int     GregorianYear() const;
      inline std::string  DayOfWeek() const;

      calJulianDayNumber JulianDayNumber() const;

      inline calRataDie operator-(long int decrement) const;

   protected:
      long int operator()() const { return pv_date; }
   private:
      long int pv_date;
      //long int pv_iso_date;

      static char* pv_weekDay[7];
};

// include any inline code here

inline std::string calRataDie::DayOfWeek() const
{
   long int lindex = calFn::Mod(pv_date, 7);
   int index = static_cast<int>( calFn::Mod(pv_date, 7) );
   return pv_weekDay[ index ];
}

inline calRataDie& calRataDie::operator=(long int fixed_date)
{
   pv_date = fixed_date; return *this;
}


inline calRataDie calRataDie::operator-(long int decrement) const
{
   return calRataDie(pv_date-decrement);
}

inline std::ostream& operator<<(std::ostream& os, const calRataDie& rd)
{
   os << rd.pv_date; return os;
}



/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
// here are the alternate names
typedef calRataDie calFixed;
typedef calRataDie calRD;
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALRATADIE_
