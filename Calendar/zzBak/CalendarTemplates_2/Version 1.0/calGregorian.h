#ifndef _CALGREGORIAN_
#define _CALGREGORIAN_
/**
  *File: calGregorian.h

  *Description:

   this file declares class calGregorian

  *Version: 1.0 "@(#) calGregorian. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <iostream>

// standard template
// local includes
#include "calDate.h"

// const declarations
// function prototypes
// forward declarations
class calRataDie;
class calIso;

// begin class declaration
class calGregorian
{
   friend class calRataDie;
   friend class calIso;

   inline friend std::ostream& operator<<(std::ostream& os, const calGregorian& g_date);
   public:
   // constructors
      calGregorian(); // default
      calGregorian(const  calDate& date);
      calGregorian(const calGregorian& gregorian);

   // assignment operator
      inline calGregorian& operator=(const calGregorian& gregorian);
      inline calGregorian& operator=(const calDate& date);

   // destructor
      ~calGregorian();

   // accessors
      long int Year() const { return pv_year; }

   // other functionality
      inline bool isLeapYear() const;

      calRataDie Fixed() const;

      static inline long int Epoch() { return pv_epoch; }
   protected:
      calGregorian(long int year, int month, int day);
   private:
      long int pv_year;
      int      pv_day;
      int      pv_month;

      static const long int pv_epoch;

};

// include any inline code here
inline calGregorian& calGregorian::operator=(const calGregorian& gregorian)
{
   pv_year  = gregorian.pv_year;
   pv_month = gregorian.pv_month;
   pv_day   = gregorian.pv_day;
   return *this;
}

inline calGregorian& calGregorian::operator=(const calDate& date)
{
   pv_year  = date.Year();
   pv_month = date.Month();
   pv_day   = date.Day();
   return *this;
}

/**
  *Purpose: asserts if the year is a leap year.
  
  * Note: in lisp implementation, it does not matter if x is negative in
          x mod y so long as y is positive. in c++, we must take care of
          this.
  */
inline bool calGregorian::isLeapYear() const
{
   long int year = pv_year < 0 ? -pv_year : pv_year;  // use absolute value

   return ( (year%4 == 0) && 
            ( (year%400 != 100) && (year%400 != 200) && (year%400 != 300) )
          );
}

inline std::ostream& operator<<(std::ostream& os, const calGregorian& g_date)
{
   os << g_date.pv_year << "-" << g_date.pv_month << "-" << g_date.pv_day; return os;
}

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALGREGORIAN_
