/**
  *File: calRataDie.cpp

  *Description:

   this file implements the class calRataDie

  *Version: 1.2

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <cmath>

// standard templates
#include <string>

// local includes
#include "calRataDie.h"
#include "calGregorian.h"
#include "calJulian.h"
#include "calIso.h"
#include "calJulianDayNumber.h"
#include "calOldHinduSolar.h"
#include "calOldHinduLunar.h"
#include "calOldHinduLunar.h"

#include "calFn.h"

#if 0
// const declarations
const char* calRataDie_id = 
   "@(#) calRataDie. implementation. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
#endif

// function prototypes
// forward declarations

// static data initialization
#if 0
char* tCalRataDie<T>::pv_weekDay[7] = { "Sunday",    "Monday",   "Tuesday", 
                                        "Wednesday", "Thursday", "Friday", 
                                        "Saturday" 
                                      };
#endif

template <typename T>
calGregorianWeekDay tCalRataDie<T>::pv_weekDay;

// begin class implementation
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
  *Purpose: provides default constructor. initializes to epoch.
  */
template <typename T>
tCalRataDie<T>::tCalRataDie()
   : pv_date( 1 )
{
// empty
}

template <typename T>
tCalRataDie<T>::tCalRataDie(long int date)
   : pv_date( date )
{
// empty
}

/**
  *Purpose: provides copy constructor
  */
template <typename T>
tCalRataDie<T>::tCalRataDie(const tCalRataDie& rd)
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
tCalRataDie<T>& tCalRataDie<T>::operator=(const tCalRataDie& rd)
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
tCalRataDie<T>::~tCalRataDie()
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
long int tCalRataDie<T>::GregorianYear() const
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

   d_0 = date - tCalGregorian<T>::Epoch();

   n_400 = tCalFn<T>::FloorFrac( d_0, 146097);

   d_1   = tCalFn<T>::Mod(d_0, 146097);           // d_1 is positive if d_0_abs is

   n_100 = tCalFn<T>::FloorFrac( d_1, 36524);

   d_2 = tCalFn<T>::Mod(d_1, 36524);

   n_4 = tCalFn<T>::FloorFrac( d_2, 1461);

   d_3 = tCalFn<T>::Mod(d_2, 1461);

   n_1 = tCalFn<T>::FloorFrac( d_3, 365);

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
tCalGregorian<T> tCalRataDie<T>::Gregorian() const
{
   long int year;
   int month;
   int day;

   long int prior_days;
   long int correction;

   long int date = pv_date;

   year = GregorianYear();

   tCalDate<T> prior_date(year, 1, 1);
   tCalGregorian<T> g( prior_date );
   prior_days = date - g._Fixed();

// calculate the correction
   tCalDate<T> march_first(year, 3, 1);
   tCalGregorian<T> g_march( march_first );

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

   month = tCalFn<T>::FloorFrac( (12 * (prior_days + correction) + 373), 367 );

   tCalDate<T> curr(year, month, 1);
   tCalGregorian<T> g_curr( curr );
   day = date - g_curr._Fixed() + 1;

   return tCalGregorian<T>(year, month, day);
}

/**
  *Purpose: returns the corresponding Julian calendar.
  * p-65
  */
template <typename T>
tCalJulian<T> tCalRataDie<T>::Julian() const
{
   long int year;
   int month;
   int day;

   long int prior_days; // this year
   long int correction;
   long int approx;     // nominal year

   long int date = pv_date;

   approx = tCalFn<T>::FloorFrac( (4 * (date - tCalJulian<T>::Epoch()) + 1464), 1461);

   year = (approx <=0) ? approx-1 : approx;

   tCalDate<T> prior_date(year, 1, 1);
   tCalJulian<T> j( prior_date );
   prior_days = date - j._Fixed();

// calculate the correction. to simulate 30-day feb
   tCalDate<T> march_first(year, 3, 1);
   tCalJulian<T> j_march( march_first );

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
   month = tCalFn<T>::FloorFrac( (12 * (prior_days + correction) + 373), 367 );

   tCalDate<T> curr(year, month, 1);
   tCalJulian<T> j_curr( curr );
   day = date - j_curr._Fixed() + 1;

   return tCalJulian<T>(year, month, day);
}

/**
  *Purpose: returns the corresponding ISO calendar.
  * page 84
  */
template <typename T>
tCalIso<T> tCalRataDie<T>::Iso() const
{
   long int year;
   int week;
   int day;

   long int approx;

   long int date = pv_date;
   long int dm3 = date - 3;
   tCalRataDie<T> rd = dm3;
   approx = Gregorian().Year();

   tCalIso<T> iso;
   tCalIsoDate<T> isoDate(approx+1, 1, 1);
   iso = isoDate;

   if (date >= iso._Fixed())
   {
      year = approx + 1;
   }
   else
   {
      year = approx;
   }

   tCalIsoDate<T> iso_date(year, 1, 1);
   iso = iso_date;
   week = tCalFn<T>::FloorFrac( (date - iso._Fixed()), 7) + 1;

   day = tCalFn<T>::Amod(date, 7);

   return tCalIso<T>(year, week, day);
}

/**
  *Purpose: returns the corresponding old hindu solar calendar.
  * page 132 from "the book"
  */
template <typename T>
tCalOldHinduSolar<T> tCalRataDie<T>::OldHinduSolar() const
{
   long double sun = static_cast<long double>( tCalOldHinduSolar<T>::DayCount(pv_date) ) +
                     static_cast<long double>( 0.25 );

   long int year  = tCalFn<T>::Floor( sun / tCalOldHinduSolar<T>::AryaSolarYear() );

   long int month = tCalFn<T>::Floor( sun / tCalOldHinduSolar<T>::AryaSolarMonth() );
   month = tCalFn<T>::Mod(month, 12) + 1;

   long double ld_day = tCalFn<T>::ModLongDouble(sun, tCalOldHinduSolar<T>::AryaSolarMonth());
   long int day = tCalFn<T>::Floor( ld_day ) + 1;

   return tCalOldHinduSolar<T>year, static_cast<int>(month), static_cast<int>(day));
}


/**
  *Purpose: returns the corresponding old hindu lunar calendar.
            this is taken from page 137(?) of "the book"
            the return type is zOHL which is being rewritten
            owing to the "strange" problem encountered with
            writing of copy constructor in implementation file.
  */
template <typename T>
tCalOldHinduLunar<T> tCalRataDie<T>::OldHinduLunar() const
{
#if 1
   long double sun = static_cast<long double>( tCalOldHinduLunar<T>::DayCount(pv_date) ) +
                     static_cast<long double>( 0.25 );

   long double new_moon = sun - tCalFn<T>::ModLongDouble(sun, tCalOldHinduLunar<T>::AryaLunarMonth());
   
   long double new_moon_mod_solar_month = tCalFn<T>::ModLongDouble(new_moon, tCalOldHinduSolar<T>::AryaSolarMonth());
   bool leap_month = (  ( new_moon_mod_solar_month > 0 ) &&
                        ( tCalOldHinduSolar<T>::AryaSolarMonth() - tCalOldHinduLunar<T>::AryaLunarMonth() ) 
                              >= new_moon_mod_solar_month
                     );

   long int month = tCalFn<T>::CeilFracLongDouble(new_moon, tCalOldHinduSolar<T>::AryaSolarMonth());
   month = tCalFn<T>::Mod(month, 12) + 1;

   long double ld_day = tCalFn<T>::FloorFracLongDouble(sun, tCalOldHinduLunar<T>::AryaLunarDay());
   long int li_day = static_cast<long int>( ld_day );

   long int day = tCalFn<T>::Mod( li_day, 30) + 1;

   long int year  = tCalFn<T>::CeilFracLongDouble( (new_moon + tCalOldHinduSolar<T>::AryaSolarMonth()), 
                                      tCalOldHinduSolar<T>::AryaSolarYear() )
                    - 1;

    return tCalOldHinduLunar(year, static_cast<int>(month), leap_month, static_cast<int>(day));
#else // test code to see if things work ok!
   long int year   = 1968;
   long int month  = 5;
   long int day    = 15;
   bool leap_month = false;

   tCalDateOldHinduLunar<T> l_date;
   l_date.Set(year, month, leap_month, day);
   tCalOldHinduLunar<T> old_HL;   // (l_date);
   old_HL = l_date;
   return old_HL;
#endif
}

#if 0
/**
  *Purpose: returns the corresponding old hindu solar calendar.
  * page 137 from "the book"
  */
template <typename T>
tCalOldHinduLunar<T> tCalRataDie<T>::OldHinduLunar() const
{
#if 0
   long double sun = static_cast<long double>( tCalOldHinduLunar<T>::DayCount(pv_date) ) +
                     static_cast<long double>( 0.25 );

   long double new_moon = sun - tCalFn<T>::ModLongDouble(sun, tCalOldHinduLunar<T>::AryaLunarMonth());
   
   long double new_moon_mod_solar_month = tCalFn<T>::ModLongDouble(new_moon, tCalOldHinduSolar<T>::AryaSolarMonth());
   bool leap_month = (  ( new_moon_mod_solar_month > 0 ) &&
                        ( tCalOldHinduSolar<T>::AryaSolarMonth() - tCalOldHinduLunar<T>::AryaLunarMonth() ) 
                              >= new_moon_mod_solar_month
                     );

   long int month = tCalFn<T>::CeilFracLongDouble(new_moon, tCalOldHinduSolar<T>::AryaSolarMonth());
   month = tCalFn<T>::Mod(month, 12) + 1;

   long double ld_day = tCalFn<T>::FloorFracLongDouble(sun, tCalOldHinduLunar<T>::AryaLunarDay());
   long int day = tCalFn<T>::Mod( ld_day, 30) + 1;

   long int year  = tCalFn<T>::CeilFracLongDouble( (new_moon + tCalOldHinduSolar<T>::AryaSolarMonth()), 
                                      tCalOldHinduSolar<T>::AryaSolarYear() )
                    - 1;

    return tCalOldHinduLunar<T>(year, static_cast<int>(month), leap_month, static_cast<int>(day));

#else // test code to see if things work ok!
   long int year   = 1968;
   long int month  = 5;
   long int day    = 15;
   bool leap_month = false;

   tCalDateOldHinduLunar<T> l_date;
   l_date.Set(year, month, leap_month, day);
   tCalOldHinduLunar<T> old_HL(l_date);
   return old_HL;
#endif
}
#endif

/**
  *Purpose: returns the corresponding julian day number
            defined in the book as
            jd-from-fixed(date) := jd-from-moment(date)
            jd-from-moment(date) := date - jd_epoch
            jd-epoch has integral and fractional part.
  */
template <typename T>
tCalJulianDayNumber<T> tCalRataDie<T>::JulianDayNumber() const
{
   return tCalJulianDayNumber<T>( static_cast<long double>(pv_date-tCalJulianDayNumber<T>::Epoch()) );
}


//////////////////////////////////////////////////
//
//  old codes replaced by new ones above.
//

#if 0 // this is the old code. has some problems in evaluating mods and so on
// for negative arguments.
template <typename T>
long int tCalRataDie<T>::GregorianYear() const
{
   const long int& date = pv_value;

   long int d_0;     // prior days
   long int n_400;   // completed 400 year cycles
   long int d_1;     // prior days not in n_400
   long int n_100;   // hundred year cycles not in n_400
   long int d_2;     // prior days not in n_400 or n_100
   long int n_4;     // four cycles not in n_400 or n_100
   long int d_3;     // prior days not in n_400, n_100 or n_4
   long int n_1;     // years not in n_400, n_100 or n_4
   long int year;    // the gregorian year

   long int d_0_abs; // to ensure positive mod results, use this.

   d_0 = date - tCalGregorian::Epoch();

   n_400 = floor( static_cast<long double>(d_0) / static_cast<long double>(146097) );

   d_0_abs = (d_0 < 0 ? -d_0 : d_0);   // to ensure positive mod results
   d_1   = d_0_abs % 146097;           // d_1 is positive if d_0_abs is

   n_100 = floor( static_cast<long double>(d_1) / static_cast<long double>(36524) );

   d_2 = d_1 % 36524;

   n_4 = floor( static_cast<long double>(d_2) / static_cast<long double>(1461) );

   d_3 = d_2 % 1461;

   n_1 = floor( static_cast<long double>(d_3) / static_cast<long double>(365) );

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
#endif

#if 0 // this is the older implementation using built in floor. not to be used.
tCalGregorian<T> tCalRataDie<T>::Gregorian() const
{
   long int year;
   int month;
   int day;

   long int prior_days;
   long int correction;

   long int date = pv_value;

   year = GregorianYear();

   tCalDate prior_date(year, 1, 1);
   tCalGregorian g( prior_date );
   prior_days = date - (g.Fixed())();

// calculate the correction
   tCalDate march_first(year, 3, 1);
   tCalGregorian g_march( march_first );

   if ( date < (g_march.Fixed())() )
   {
      correction = 0;
   }
   else
   {
      if ( (date >= (g_march.Fixed())()) && (g_march.isLeapYear() == true) )
      {
         correction = 1;
      }
      else
      {
         correction = 2;
      }
   }

   month = floor(  static_cast<long double>(12 * (prior_days + correction) + 373) / static_cast<long double>(367) );

   tCalDate curr(year, month, 1);
   tCalGregorian g_curr( curr );
   day = date - (g_curr.Fixed())() + 1;

   return tCalGregorian(year, month, day);
}
#endif


// follow this pattern for function comments

/**
  *Purpose: 
  *Returns: 
  *Params:  
  *Throws:  
  */

// here is an example
#if 0 // here is an example
/**
  *Purpose: 
      this function add the matrix passed as arg.

  *Returns: 
      matrixNode* ... pointer to a matrix node

  *Params:  
      ptr_mn -- a const pointer to matrix node
      gmn    -- general matrix node

  *Throws:  
      aMatrix::exception object
  */
matrixNode* aMatrix::Add(const matrixNode* ptr_mn, ...)
#endif // end of example


