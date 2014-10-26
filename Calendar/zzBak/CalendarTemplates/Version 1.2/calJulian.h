#ifndef _CALJULIAN_
#define _CALJULIAN_
/**
  *File: calJulian.h

  *Description:

   this file declares class calJulian

  *Version: 1.2 "@(#) calJulian. header. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <iostream>

// standard template
// local includes
#include "calDate.h"
#include "calBase.h"

#include "calFn.h"

// const declarations
// function prototypes
// forward declarations
class calRataDie;

// begin class declaration
class calJulian : public calBase
{
   friend class calRataDie;
   inline friend std::ostream& operator<<(std::ostream& os, const calJulian& j_date);
   public:
   // constructors
      calJulian(); // default
      calJulian(const calDate& date);
      calJulian(const calJulian& julian);

   // assignment operator
      inline calJulian& operator=(const calJulian& julian);
      inline calJulian& operator=(const calDate& date);

   // destructor
      ~calJulian();

   // accessors
      long int Year() const { return pv_year; }

   // other functionality
      inline bool isLeapYear() const;

      static inline long int Epoch() { return pv_epoch; }

   protected:
      calJulian(long int year, int month, int day);

   private:
      void     _ComputeFixed();

   private:
      long int pv_year;
      int      pv_day;
      int      pv_month;

      static const long int pv_epoch;

};

// include any inline code here
inline calJulian& calJulian::operator=(const calJulian& julian)
{
// invoke the base class assignment as well
   (*static_cast<calBase*>(this)) = julian;
   pv_year  = julian.pv_year;
   pv_month = julian.pv_month;
   pv_day   = julian.pv_day;

   return *this;
}

inline calJulian& calJulian::operator=(const calDate& date)
{
   pv_year  = date.Year();
   pv_month = date.Month();
   pv_day   = date.Day();

   _ComputeFixed();

   return *this;
}

/**
  *Purpose: asserts if the year is a leap year.
  
  * Note: in lisp implementation, it does not matter if x is negative in
          x mod y so long as y is positive. in c++, we must take care of
          this.
  */
inline bool calJulian::isLeapYear() const
{
   if (pv_year > 0)
   {
      return (calFn::Mod(pv_year, 4) ==0);
   }
   else
   {
      return (calFn::Mod(pv_year, 4) == 3);
   }
}

inline std::ostream& operator<<(std::ostream& os, const calJulian& j_date)
{
   if ( j_date.pv_year >= 0 )
   {
      os << j_date.pv_year << "-" << j_date.pv_month << "-" << j_date.pv_day << " C. E. "; return os;
   }
   else
   {
      os << -j_date.pv_year << "-" << j_date.pv_month << "-" << j_date.pv_day << " B. C. E. "; return os;
   }

}

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALJULIAN_
