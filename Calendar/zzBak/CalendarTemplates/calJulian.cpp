/**
  *File: calJulian.cpp

  *Description:

   this file implements the class calJulian

  *Version: 1.2

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <cmath>

// standard templates
// local includes
#include "calJulian.h"
#include "calRataDie.h"
#include "calFn.h"

#if 0
// const declarations
const char* calJulian_id = 
   "@(#) calJulian. implementation. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
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
tCalJulian<T>::tCalJulian()
   : pv_year( 1 ), pv_month( 1 ), pv_day( 1 )
{
   _ComputeFixed();
}

template <typename T>
tCalJulian<T>::tCalJulian(const tCalDate<T>& date)
   : pv_year( date.Year() ), pv_month( date.Month() ), pv_day( date.Day() )
{
   _ComputeFixed();
}

template <typename T>
tCalJulian<T>::tCalJulian(long int year, int month, int day)
   : pv_year( year ), pv_month( month ), pv_day( day )
{
   _ComputeFixed();
}

/**
  *Purpose: provides copy constructor
  */
template <typename T>
tCalJulian<T>::tCalJulian(const tCalJulian<T>& j)
   : tCalBase( j ),
     pv_year( j.pv_year ), pv_month( j.pv_month ), pv_day( j.pv_day )
{
// empty
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //    (inline implementation)
   //                                      


   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

template <typename T>
tCalJulian<T>::~tCalJulian()
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
            date on the Julian calendar.
            this is calculated in various parts.
  */
template <typename T>
void tCalJulian<T>::_ComputeFixed()
{
   long int t0, t1, t2, t3, t4;

   long int epoch = pv_epoch;

   t0 = pv_epoch - 1;   // days before the start of the calendar

   long int year = (pv_year<0) ? pv_year+1 : pv_year;
   
   t1 = 365 * (year - 1);  // ordinary days since epoch

// julian leap days since epoch
   t2 = tCalFn<T>::FloorFrac( (year-1), 4 );

// days in prior months this year assuming 30 day february
   t3 = tCalFn<T>::FloorFrac( (367 * pv_month - 362), 12 );

// correction for 28 or 29 day february
// leap year check is made on pv_year and not on year. so merely use isLeapYear function.
   t4 = 0;

   if ( pv_month > 2  && (isLeapYear() == true) )
   {
      t4 = -1;
   }
   else
   {
      if ( pv_month > 2 )
      {
         t4 = -2;
      }
   }

   _Fixed( t0 + t1 + t2 + t3 + t4 + pv_day );
   return;
}

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


