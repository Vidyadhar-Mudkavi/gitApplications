/**
  *File: calRataDie.cpp

  *Description:

   this file implements the class calRataDie

  *Version: 1.0

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
#include "calFn.h"

// const declarations
const char* calRataDie_id = 
   "@(#) calRataDie. implementation. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
// function prototypes
// forward declarations


// static data initialization
char* calRataDie::pv_weekDay[7] = { "Sunday",    "Monday",   "Tuesday", 
                                    "Wednesday", "Thursday", "Friday", 
                                    "Saturday" 
                                  };
// begin class implementation
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
  *Purpose: provides default constructor. initializes to epoch.
  */
calRataDie::calRataDie()
   : pv_date( 1 )
{
// empty
}

calRataDie::calRataDie(long int date)
   : pv_date( date )
{
// empty
}

/**
  *Purpose: provides copy constructor
  */
calRataDie::calRataDie(const calRataDie& rd)
   : pv_date( rd.pv_date )
{
// empty
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

calRataDie& calRataDie::operator=(const calRataDie& rd)
{
   pv_date = rd.pv_date;
   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

calRataDie::~calRataDie()
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
long int calRataDie::GregorianYear() const
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

   d_0 = date - calGregorian::Epoch();

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

calGregorian calRataDie::Gregorian() const
{
   long int year;
   int month;
   int day;

   long int prior_days;
   long int correction;

   long int date = pv_date;

   year = GregorianYear();

   calDate prior_date(year, 1, 1);
   calGregorian g( prior_date );
   prior_days = date - (g.Fixed())();

// calculate the correction
   calDate march_first(year, 3, 1);
   calGregorian g_march( march_first );

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

   month = calFn::FloorFrac( (12 * (prior_days + correction) + 373), 367 );

   calDate curr(year, month, 1);
   calGregorian g_curr( curr );
   day = date - (g_curr.Fixed())() + 1;

   return calGregorian(year, month, day);
}

/**
  *Purpose: returns the corresponding Julian calendar.
  * p-65
  */
calJulian calRataDie::Julian() const
{
   long int year;
   int month;
   int day;

   long int prior_days;
   long int correction;
   long int approx;

   long int date = pv_date;

   approx = calFn::FloorFrac( (4 * (date - calJulian::Epoch()) + 1464), 1461);

   year = (approx <=0) ? approx-1 : approx;

   calDate prior_date(year, 1, 1);
   calJulian j( prior_date );
   prior_days = date - (j.Fixed())();

// calculate the correction
   calDate march_first(year, 3, 1);
   calJulian j_march( march_first );

   if ( date < (j_march.Fixed())() )
   {
      correction = 0;
   }
   else
   {
      if ( (date >= (j_march.Fixed())()) && (j_march.isLeapYear() == true) )
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
   calJulian j_curr( curr );
   day = date - (j_curr.Fixed())() + 1;

   return calJulian(year, month, day);
}

/**
  *Purpose: returns the corresponding ISO calendar.
  * p-84
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
   if (date >= (iso.Fixed()).pv_date)
   {
      year = approx + 1;
   }
   else
   {
      year = approx;
   }

   calIsoDate iso_date(year, 1, 1);
   iso = iso_date;
   week = calFn::FloorFrac( (date - (iso.Fixed()).pv_date), 7) + 1;

   day = calFn::Amod(date, 7);

   return calIso(year, week, day);
}




/**
  *Purpose: returns the corresponding julian day number
            defined in the book as
            jd-from-fixed(date) := jd-from-moment(date)
            jd-from-moment(date) := date - jd_epoch
         jd-epoch has integral and fractional part.
  */
calJulianDayNumber calRataDie::JulianDayNumber() const
{
   return calJulianDayNumber( static_cast<long double>(pv_date-calJulianDayNumber::Epoch()) );
}


//////////////////////////////////////////////////
//
//  old codes replace by new ones above.
//

#if 0 // this is the old code. has some problems in evaluating mods and so on
// for negative arguments.
long int calRataDie::GregorianYear() const
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

   d_0 = date - calGregorian::Epoch();

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
calGregorian calRataDie::Gregorian() const
{
   long int year;
   int month;
   int day;

   long int prior_days;
   long int correction;

   long int date = pv_value;

   year = GregorianYear();

   calDate prior_date(year, 1, 1);
   calGregorian g( prior_date );
   prior_days = date - (g.Fixed())();

// calculate the correction
   calDate march_first(year, 3, 1);
   calGregorian g_march( march_first );

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

   calDate curr(year, month, 1);
   calGregorian g_curr( curr );
   day = date - (g_curr.Fixed())() + 1;

   return calGregorian(year, month, day);
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


