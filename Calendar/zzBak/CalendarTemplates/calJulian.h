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
template <typename T>
class tCalRataDie;

// begin class declaration
template <typename T>
class tCalJulian : public tCalBase<T>
{
   friend class tCalRataDie<T>;
   inline friend std::ostream& operator<<(std::ostream& os, const tCalJulian& j_date);
   public:
   // constructors
      tCalJulian(); // default
      tCalJulian(const tCalDate<T>& date);
      tCalJulian(const tCalJulian& julian);

   // assignment operator
      inline tCalJulian<T>& operator=(const tCalJulian& julian);
      inline tCalJulian<T>& operator=(const tCalDate<T>& date);

   // destructor
      ~tCalJulian();

   // accessors
      long int Year() const { return pv_year; }

   // other functionality
      inline bool isLeapYear() const;

      static inline long int Epoch() { return pv_epoch; }

   protected:
      tCalJulian(long int year, int month, int day);

   private:
      void     _ComputeFixed();

   private:
      long int pv_year;
      int      pv_day;
      int      pv_month;

      static const long int pv_epoch;

};

// include any inline code here
template <typename T>
inline tCalJulian<T>& tCalJulian<T>::operator=(const tCalJulian& julian)
{
// invoke the base class assignment as well
   (*static_cast<tCalBase<T>*>(this)) = julian;
   pv_year  = julian.pv_year;
   pv_month = julian.pv_month;
   pv_day   = julian.pv_day;

   return *this;
}

template <typename T>
inline tCalJulian<T>& tCalJulian<T>::operator=(const tCalDate<T>& date)
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
template <typename T>
inline bool tCalJulian<T>::isLeapYear() const
{
   if (pv_year > 0)
   {
      return (tCalFn<T>::Mod(pv_year, 4) ==0);
   }
   else
   {
      return (tCalFn<T>::Mod(pv_year, 4) == 3);
   }
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const tCalJulian<T>& j_date)
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

#include "calJulian.cpp"


/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALJULIAN_
