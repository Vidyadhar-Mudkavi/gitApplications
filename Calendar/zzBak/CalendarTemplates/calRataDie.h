#ifndef _CALRATADIE_
#define _CALRATADIE_

/**
  *File: calRataDie.h

  *Description:

   this file declares class calRataDie

  *Version: 1.2 "@(#) calRataDie. header. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <iostream>

// standard template

// local includes
#include "calFn.h"
#include "calBase.h"
#include "calNames.h"


// function prototypes
// forward declarations
template <typename T>
class tCalGregorian;
template <typename T>
class tCalJulianDayNumber;
template <typename T>
class tCalJulian;
template <typename T>
class tCalIso;
template <typename T>
class tCalOldHinduSolar;
template <typename T>
class tCalOldHinduLunar;

// begin class declaration
template <typename T>
class tCalRataDie : public tCalBase<T>
{
   friend class tCalFn<T>;
   friend class tCalGregorian<T>;
   friend inline std::ostream& operator<<(std::ostream& os, const tCalRataDie<T>& rd);

   public:
   // constructors
      tCalRataDie(); // default
      tCalRataDie(long int date);
      tCalRataDie(const tCalRataDie& rata_die);

   // assignment operator
      tCalRataDie& operator=(const tCalRataDie& rata_die);
      inline tCalRataDie& operator=(long int fixed_date);

   // destructor
      ~tCalRataDie();

   // other functionality
      tCalGregorian<T> Gregorian() const;
      tCalJulian<T>    Julian() const;
      tCalIso<T>       Iso() const;
      tCalOldHinduSolar<T> OldHinduSolar() const;
      tCalOldHinduLunar<T> OldHinduLunar() const;

      tCalJulianDayNumber<T> JulianDayNumber() const;

      long int     GregorianYear() const;

      inline std::string  DayOfWeek() const;
      inline tCalRataDie<T> operator-(long int decrement) const;

   protected:
      long int operator()() const { return pv_date; }

   private:
      long int pv_date;

      static calGregorianWeekDay pv_weekDay;
//      static char* pv_weekDay[7];
};

// include any inline code here
template <typename T>
inline std::string tCalRataDie<T>::DayOfWeek() const
{
   long int lindex = tCalFn<T>::Mod(pv_date, 7);
   int index = static_cast<int>( tCalFn<T>::Mod(pv_date, 7) );
   return pv_weekDay[ index ];
}

template <typename T>
inline tCalRataDie<T>& tCalRataDie<T>::operator=(long int fixed_date)
{
   pv_date = fixed_date; return *this;
}


template <typename T>
inline tCalRataDie<T> tCalRataDie<T>::operator-(long int decrement) const
{
   return tCalRataDie(pv_date-decrement);
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const tCalRataDie<T>& rd)
{
   os << rd.pv_date; return os;
}

#include "calRataDie.cpp"

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
// here are the alternate names
// typedef template <typename T> tCalRataDie<T> tCalFixed<T>;

// template <typename T> typedef tCalRataDie tCalRD<T>;
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALRATADIE_
