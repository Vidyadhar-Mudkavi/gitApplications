#ifndef _CALOLDHINDUSOLAR_
#define _CALOLDHINDUSOLAR_
/**
  *File: calOldHinduSolar.h

  *Description:

   this file declares class calOldHinduSolar

  *Version: 1.0 "@(#) calOldHinduSolar. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:    2004 May 06
  */

// system includes
#include <iostream>

// standard template
// local includes
#include "calBase.h"
#include "calDate.h"

// const declarations
// function prototypes
// forward declarations
template <typename T>
class tCalRataDie;

// begin class declaration
template <typename T>
class tCalOldHinduSolar : public tCalBase<T>
{
   friend class tCalRataDie<T>;
   inline friend std::ostream& operator<<(std::ostream& os, const tCalOldHinduSolar<T>& old_HS);

   public:
   // constructors
      tCalOldHinduSolar(); // default
      tCalOldHinduSolar(const tCalDate<T>& date);
      tCalOldHinduSolar(const tCalOldHinduSolar& old_HS);

   // assignment operators
      inline tCalOldHinduSolar& operator=(const tCalOldHinduSolar& old_HS);
      inline tCalOldHinduSolar& operator=(const tCalDate<T>& date);

   // destructor
      ~tCalOldHinduSolar();

   // other functionality
      inline long int DayCount() const { return _Fixed() - pv_epoch; }
      
      static inline long int Epoch() { return pv_epoch; }
      static inline long double AryaSolarYear()  { return pv_arya_solarYear; }
      static inline long double AryaSolarMonth() { return pv_arya_solarMonth; }
      static inline long double JovianPeriod()   { return pv_jovian_period; }


   protected:
   // this one is used exclusively by RataDie.
      static inline long int DayCount(long int fixed_date) { return fixed_date - pv_epoch; }
      
      tCalOldHinduSolar(long int year, int month, int day);

   private:
      void      _ComputeFixed();

   private:
      long int pv_year;
      int      pv_month;
      int      pv_day;

      static const long double pv_arya_solarYear;
      static const long double pv_arya_solarMonth;
      static const long double pv_jovian_period;

      static const long int pv_epoch;
};

// include any inline code here
template <typename T>
inline tCalOldHinduSolar<T>& tCalOldHinduSolar<T>::operator=(const tCalOldHinduSolar& old_HS)
{
// one can also do this through static_cast operator (page 947. Lippman and lajoie, 3rd ed.)
   (*static_cast<tCalBase*>(this)) = old_HS;

   pv_year  = old_HS.pv_year;
   pv_month = old_HS.pv_month;
   pv_day   = old_HS.pv_day;

   return *this;
}

template <typename T>
inline tCalOldHinduSolar<T>& tCalOldHinduSolar<T>::operator=(const tCalDate<T>& date)
{
   pv_year  = date.Year();
   pv_month = date.Month();
   pv_day   = date.Day();

   _ComputeFixed();

   return *this;
}


template <typename T>
inline std::ostream& operator<<(std::ostream& os, const tCalOldHinduSolar<T>& old_HS)
{
   os << old_HS.pv_year << "-" << old_HS.pv_month << "-" << old_HS.pv_day; return os;
}


#if 0
/**
  *Purpose: asserts if the year is a leap year.
  
  * Note: in lisp implementation, it does not matter if x is negative in
          x mod y so long as y is positive. in c++, we must take care of
          this.
  */
inline bool tCalOldHinduSolar<T>::isLeapYear() const
{
   long int year = pv_year < 0 ? -pv_year : pv_year;  // use absolute value

   return ( (year%4 == 0) && 
            ( (year%400 != 100) && (year%400 != 200) && (year%400 != 300) )
          );
}
#endif

#include "calOldHinduSolar.cpp"

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALOLDHINDUSOLAR_

