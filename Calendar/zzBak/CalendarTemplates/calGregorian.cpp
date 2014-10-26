/**
  *File: calGregorian.cpp

  *Description:

   this file implements the class calGregorian

  *Version: 1.2

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <cmath>

// standard templates
// local includes
#include "calGregorian.h"
#include "calRataDie.h"
#include "calFn.h"

// const declarations
#if 0
const char* calGregorian_id = 
   "@(#) calGregorian. implementation. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
#endif
// function prototypes
// forward declarations

// begin class implementation
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
  *Purpose: provides default constructor
  */
template <typename T>
tCalGregorian<T>::tCalGregorian()
   : pv_year( 1 ), pv_month( 1 ), pv_day( 1 )
{
   _ComputeFixed();
}

template <typename T>
tCalGregorian<T>::tCalGregorian(const tCalDate<T>& date)
   : pv_year( date.Year() ), pv_month( date.Month() ), pv_day( date.Day() )
{
   _ComputeFixed();
}

template <typename T>
tCalGregorian<T>::tCalGregorian(long int year, int month, int day)
   : pv_year( year ), pv_month( month ), pv_day( day )
{
   _ComputeFixed();
}

/**
  *Purpose: provides copy constructor
  */
template <typename T>
tCalGregorian<T>::tCalGregorian(const tCalGregorian<T>& g)
   : tCalBase( g ),
     pv_year( g.pv_year ), pv_month( g.pv_month ), pv_day( g.pv_day )
{
// empty
}


   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

template <typename T>
tCalGregorian<T>::~tCalGregorian()
{
// empty
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          



/**
  *Purpose: evaluates the RD (RataDie) or Fixed date from a given
            date on the Gregorian calendar.
            this is calculated in various parts.
  */
template <typename T>
void tCalGregorian<T>::_ComputeFixed()
{
   long int t0, t1, t2, t3, t4, t5, t6;

   long int epoch = pv_epoch;

   t0 = pv_epoch - 1;                           // days before the start of the calendar
   
   t1 = 365 * (pv_year - 1);                    // ordinary days since epoch

   t2 = tCalFn<T>::FloorFrac( (pv_year-1), 4 );     // julian leap days since epoch

   t3 = tCalFn<T>::FloorFrac( (pv_year-1), 100 );   // minus century years since epoch.
   
   t4 = tCalFn<T>::FloorFrac( (pv_year-1), 400 );   // plus the years since epoch divisible by 400

   t5 = tCalFn<T>::FloorFrac( (367 * pv_month - 362), 12 );  // days in prior months this year 
                                                         // assuming 30 day february

// correction for 28 or 29 day february
   t6 = 0;

   if ( pv_month > 2  && (isLeapYear() == true) )
   {
      t6 = -1;
   }
   else
   {
      if ( pv_month > 2 )
      {
         t6 = -2;
      }
   }

   _Fixed(t0 + t1 + t2 - t3 + t4 + t5 + t6 + pv_day);
   return;
}

////////////////////////////////////////////////////
//
// older code replaced by new one above
//
#if 0 // this is the older implementation using built in floor. not to be used.
calRataDie calGregorian::Fixed() const
{
   long int t0, t1, t2, t3, t4, t5, t6;

   long int epoch = pv_epoch;

   t0 = pv_epoch - 1;   // days before the start of the calendar
   
   t1 = 365 * (pv_year - 1);  // ordinary days since epoch

// julian leap days since epoch
   t2 = floor( static_cast<long double>(pv_year-1) / static_cast<long double>(4)   );

// minus century years since epoch.
   t3 = floor( static_cast<long double>(pv_year-1) / static_cast<long double>(100) );
   
// plus the years since epoch divisible by 400
   t4 = floor( static_cast<long double>(pv_year-1) / static_cast<long double>(400) );

// days in prior months this year assuming 30 day february
   t5 = floor( static_cast<long double>(367 * pv_month - 362) / static_cast<long double>(12) );


// correction for 28 or 29 day february
   t6 = 0;

   if ( pv_month > 2  && (isLeapYear() == true) )
   {
      t6 = -1;
   }
   else
   {
      if ( pv_month > 2 )
      {
         t6 = -2;
      }
   }

   return calRataDie(t0 + t1 + t2 - t3 + t4 + t5 + t6 + pv_day);
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


