#ifndef _CALGREGORIAN_
#define _CALGREGORIAN_

/**
  *File: calGregorian.h

  *Description:

   this file declares class calGregorian.
   apart from storing year, month and day, the corresponding fixed date is also
   stored. this is useful in subtracting dates etc.

  *Version: 1.2 "@(#) calGregorian. header. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

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

// const declarations
// function prototypes

// forward declarations
template <typename T>
class tCalRataDie;
template <typename T>
class tCalIso;

// begin class declaration
template <typename T>
class tCalGregorian : public tCalBase<T>
{
   friend class tCalRataDie<T>;
   friend class tCalIso<T>;

   inline friend std::ostream& operator<<(std::ostream& os, const tCalGregorian<T>& g_date);

   public:
   // constructors
      tCalGregorian(); // default
      tCalGregorian(const tCalDate<T>& date);
      tCalGregorian(const tCalGregorian& gregorian);

   // assignment operator
      inline tCalGregorian& operator=(const tCalGregorian& gregorian);
      inline tCalGregorian& operator=(const tCalDate<T>& date);

   // destructor
      ~tCalGregorian();

   // accessors
      long int Year() const { return pv_year; }

   // other functionality
      inline bool isLeapYear() const;

      static inline long int Epoch() { return pv_epoch; }

   protected:
      tCalGregorian(long int year, int month, int day);

   private:
      void      _ComputeFixed();

   private:
      long int pv_year;
      int      pv_day;
      int      pv_month;

      static const long int pv_epoch;

};

// include any inline code here
template <typename T>
inline tCalGregorian<T>& tCalGregorian<T>::operator=(const tCalGregorian& gregorian)
{
#if 0
// explicitly invoke the assignment for the base
   (*this).tCalBase::operator = ( gregorian );
#endif

// one can also do this through static_cast operator (page 947. Lippman and lajoie, 3rd ed.)
   (*static_cast<tCalBase*>(this)) = gregorian;

   pv_year  = gregorian.pv_year;
   pv_month = gregorian.pv_month;
   pv_day   = gregorian.pv_day;

   return *this;
}

template <typename T>
inline tCalGregorian<T>& tCalGregorian<T>::operator=(const tCalDate<T>& date)
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
inline bool tCalGregorian<T>::isLeapYear() const
{
   long int year = pv_year < 0 ? -pv_year : pv_year;  // use absolute value

   return ( (year%4 == 0) && 
            ( (year%400 != 100) && (year%400 != 200) && (year%400 != 300) )
          );
}


template <typename T>
inline std::ostream& operator<<(std::ostream& os, const tCalGregorian<T>& g_date)
{
   os << g_date.pv_year << "-" << g_date.pv_month << "-" << g_date.pv_day; return os;
}


#include "calGregorian.cpp"

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALGREGORIAN_
