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
#if 0
#include "calGregorian.h"
#include "calJulianDayNumber.h"
#endif

// function prototypes
// forward declarations
template <typename T> class calGregorian;
template <typename T> class calJulianDayNumber;

#if 0
class calJulianDayNumber;
class calJulian;
class calIso;
class calOldHinduSolar;
class calOldHinduLunar;
#endif

// begin class declaration
template <typename T>
class calRataDie : public calBase<T>
{
   friend class calFn;
   friend class calGregorian<T>;
   friend inline std::ostream& operator<<(std::ostream& os, const calRataDie<T>& rd)
   {
      os << rd.pv_date; return os;
   }

   public:
   // constructors
      inline calRataDie(); // default
      inline calRataDie(long int date);
      inline calRataDie(const calRataDie<T>& rata_die);

   // assignment operator
      inline calRataDie<T>& operator=(const calRataDie<T>& rata_die);
      inline calRataDie<T>& operator=(long int fixed_date);

   // destructor
      inline ~calRataDie();

   // other functionality
      inline calGregorian<T> Gregorian() const;

      inline calJulianDayNumber<T> JulianDayNumber() const;
#if 0
      inline calJulian    Julian() const;
      inline calIso       Iso() const;
      inline calOldHinduSolar OldHinduSolar() const;
      inline calOldHinduLunar OldHinduLunar() const;
#endif

      inline long int     GregorianYear() const;

      inline std::string  DayOfWeek() const;
      inline calRataDie<T> operator-(long int decrement) const;

   protected:
      inline long int operator()() const { return pv_date; }
   private:
      long int pv_date;

      static calGregorianWeekDay pv_weekDay;
//      static char* pv_weekDay[7];
};

// include any inline code here

template <typename T>
inline std::string calRataDie<T>::DayOfWeek() const
{
   long int lindex = calFn::Mod(pv_date, 7);
   int index = static_cast<int>( calFn::Mod(pv_date, 7) );
   return pv_weekDay[ index ];
}

template <typename T>
inline calRataDie<T>& calRataDie<T>::operator=(long int fixed_date)
{
   pv_date = fixed_date; return *this;
}


template <typename T>
inline calRataDie<T> calRataDie<T>::operator-(long int decrement) const
{
   return calRataDie<T>(pv_date-decrement);
}

#if 0
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const calRataDie<T>& rd)
{
   os << rd.pv_date; return os;
}
#endif

// from .cpp implementation

/**
  *Purpose: provides default constructor. initializes to epoch.
  */
template <typename T>
inline calRataDie<T>::calRataDie()
   : pv_date( 1 )
{
// empty
}

template <typename T>
inline calRataDie<T>::calRataDie(long int date)
   : pv_date( date )
{
// empty
}

/**
  *Purpose: provides copy constructor
  */
template <typename T>
inline calRataDie<T>::calRataDie(const calRataDie& rd)
   : pv_date( rd.pv_date )
{
// empty
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

template <typename T>
inline calRataDie<T>& calRataDie<T>::operator=(const calRataDie<T>& rd)
{
   pv_date = rd.pv_date;
   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

template <typename T>
inline calRataDie<T>::~calRataDie()
{
// empty
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          

/**
  *Purpose: returns the corresponding gregorian calendar.
  */
template <typename T>
inline long int calRataDie<T>::GregorianYear() const
{
   const long int& date = pv_date;

   long int d_0;     // prior days
   long int n_400;   // completed 400 year cycles
   long int d_1;     // prior days not in n_400
   long int n_100;   // hundred year cycles not in n_400
   long int d_2;     // prior days not in n_400 or n_100
   long int n_4;     // four cycles not in n_400 or n_100
   long int d_3;     // prior days not in n_400, n_100 or n_4
   long int n_1;     // years not in n_400, n_100 or n_4
   long int year;    // the gregorian year

   d_0 = date - calGregorian<T>::Epoch();

   n_400 = calFn::FloorFrac( d_0, 146097);

   d_1   = calFn::Mod(d_0, 146097);           // d_1 is positive if d_0_abs is

   n_100 = calFn::FloorFrac( d_1, 36524);

   d_2 = calFn::Mod(d_1, 36524);

   n_4 = calFn::FloorFrac( d_2, 1461);

   d_3 = calFn::Mod(d_2, 1461);

   n_1 = calFn::FloorFrac( d_3, 365);

   year = 400 * n_400 + 100 * n_100 + 4 * n_4 + n_1;

   if ( (n_100 == 4) || (n_1 == 4) )
   {
      year = year;   // date is day 366 in a leap year
   }
   else
   {
      year += 1;     // date is ordinal day (1 + (d3 mod 365)) in (1+year)
   }

   return year;
}


/**
  *Purpose: returns the corresponding gregorian calendar.
  */
template <typename T>
inline calGregorian<T> calRataDie<T>::Gregorian() const
{
   long int year;
   int month;
   int day;

   long int prior_days;
   long int correction;

   long int date = pv_date;

   year = GregorianYear();

   calDate prior_date(year, 1, 1);
   calGregorian<T> g( prior_date );
   prior_days = date - g._Fixed();

// calculate the correction
   calDate march_first(year, 3, 1);
   calGregorian<T> g_march( march_first );

   if ( date < g_march._Fixed() )
   {
      correction = 0;
   }
   else
   {
      if ( (date >= g_march._Fixed()) && (g_march.isLeapYear() == true) )
      {
         correction = 1;
      }
      else
      {
         correction = 2;
      }
   }

   month = calFn::FloorFrac( (12 * (prior_days + correction) + 373), 367 );

   calDate curr(year, month, 1);
   calGregorian<T> g_curr( curr );
   day = date - g_curr._Fixed() + 1;

   return calGregorian<T>(year, month, day);
}

/**
  *Purpose: returns the corresponding julian day number
            defined in the book as
            jd-from-fixed(date) := jd-from-moment(date)
            jd-from-moment(date) := date - jd_epoch
            jd-epoch has integral and fractional part.
  */
template <typename T>
calJulianDayNumber<T> calRataDie<T>::JulianDayNumber() const
{
   return calJulianDayNumber<T>( static_cast<long double>(pv_date-calJulianDayNumber<T>::Epoch()) );
}


#if 0 // other calendar implementations yet to be adopted.
/**
  *Purpose: returns the corresponding Julian calendar.
  * p-65
  */
calJulian calRataDie::Julian() const
{
   long int year;
   int month;
   int day;

   long int prior_days; // this year
   long int correction;
   long int approx;     // nominal year

   long int date = pv_date;

   approx = calFn::FloorFrac( (4 * (date - calJulian::Epoch()) + 1464), 1461);

   year = (approx <=0) ? approx-1 : approx;

   calDate prior_date(year, 1, 1);
   calJulian j( prior_date );
   prior_days = date - j._Fixed();

// calculate the correction. to simulate 30-day feb
   calDate march_first(year, 3, 1);
   calJulian j_march( march_first );

   if ( date < j_march._Fixed() )
   {
      correction = 0;
   }
   else
   {
      if ( (date >= j_march._Fixed()) && (j_march.isLeapYear() == true) )
      {
         correction = 1;
      }
      else
      {
         correction = 2;
      }
   }

// assuming a 30-day feb
   month = calFn::FloorFrac( (12 * (prior_days + correction) + 373), 367 );

   calDate curr(year, month, 1);
   calJulian j_curr( curr );
   day = date - j_curr._Fixed() + 1;

   return calJulian(year, month, day);
}

/**
  *Purpose: returns the corresponding ISO calendar.
  * page 84
  */
calIso calRataDie::Iso() const
{
   long int year;
   int week;
   int day;

   long int approx;

   long int date = pv_date;
   long int dm3 = date - 3;
   calRataDie rd = dm3;
   approx = Gregorian().Year();

   calIso iso;
   calIsoDate isoDate(approx+1, 1, 1);
   iso = isoDate;

   if (date >= iso._Fixed())
   {
      year = approx + 1;
   }
   else
   {
      year = approx;
   }

   calIsoDate iso_date(year, 1, 1);
   iso = iso_date;
   week = calFn::FloorFrac( (date - iso._Fixed()), 7) + 1;

   day = calFn::Amod(date, 7);

   return calIso(year, week, day);
}

/**
  *Purpose: returns the corresponding old hindu solar calendar.
  * page 132 from "the book"
  */
calOldHinduSolar calRataDie::OldHinduSolar() const
{
   long double sun = static_cast<long double>( calOldHinduSolar::DayCount(pv_date) ) +
                     static_cast<long double>( 0.25 );

   long int year  = calFn::Floor( sun / calOldHinduSolar::AryaSolarYear() );

   long int month = calFn::Floor( sun / calOldHinduSolar::AryaSolarMonth() );
   month = calFn::Mod(month, 12) + 1;

   long double ld_day = calFn::ModLongDouble(sun, calOldHinduSolar::AryaSolarMonth());
   long int day = calFn::Floor( ld_day ) + 1;

   return calOldHinduSolar(year, static_cast<int>(month), static_cast<int>(day));
}


/**
  *Purpose: returns the corresponding old hindu lunar calendar.
            this is taken from page 137(?) of "the book"
            the return type is zOHL which is being rewritten
            owing to the "strange" problem encountered with
            writing of copy constructor in implementation file.
  */
calOldHinduLunar calRataDie::OldHinduLunar() const
{
#if 1
   long double sun = static_cast<long double>( calOldHinduLunar::DayCount(pv_date) ) +
                     static_cast<long double>( 0.25 );

   long double new_moon = sun - calFn::ModLongDouble(sun, calOldHinduLunar::AryaLunarMonth());
   
   long double new_moon_mod_solar_month = calFn::ModLongDouble(new_moon, calOldHinduSolar::AryaSolarMonth());
   bool leap_month = (  ( new_moon_mod_solar_month > 0 ) &&
                        ( calOldHinduSolar::AryaSolarMonth() - calOldHinduLunar::AryaLunarMonth() ) 
                              >= new_moon_mod_solar_month
                     );

   long int month = calFn::CeilFracLongDouble(new_moon, calOldHinduSolar::AryaSolarMonth());
   month = calFn::Mod(month, 12) + 1;

   long double ld_day = calFn::FloorFracLongDouble(sun, calOldHinduLunar::AryaLunarDay());
   long int li_day = static_cast<long int>( ld_day );

   long int day = calFn::Mod( li_day, 30) + 1;

   long int year  = calFn::CeilFracLongDouble( (new_moon + calOldHinduSolar::AryaSolarMonth()), 
                                      calOldHinduSolar::AryaSolarYear() )
                    - 1;

    return calOldHinduLunar(year, static_cast<int>(month), leap_month, static_cast<int>(day));
#else // test code to see if things work ok!
   long int year   = 1968;
   long int month  = 5;
   long int day    = 15;
   bool leap_month = false;

   calDateOldHinduLunar l_date;
   l_date.Set(year, month, leap_month, day);
   calOldHinduLunar old_HL;   // (l_date);
   old_HL = l_date;
   return old_HL;
#endif
}


#endif

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
// here are the alternate names
//typedef calRataDie calFixed;
//typedef calRataDie calRD;
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALRATADIE_
