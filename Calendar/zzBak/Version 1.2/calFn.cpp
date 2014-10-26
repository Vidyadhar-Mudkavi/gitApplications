/**
  *File: calFn.cpp

  *Description:

   this file implements the class calFn

  *Version: 1.2

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
// standard templates
// local includes
#include "calFn.h"
#include "calRataDie.h"
#include "calGregorian.h"

// const declarations
const char* calFn_id = 
   "@(#) calFn. implementation. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
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
calFn::calFn()
{
// empty
}

/**
  *Purpose: provides copy constructor
  */
calFn::calFn(const calFn& fn)
{
// empty
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

calFn& calFn::operator=(const calFn& fn)
{
   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

calFn::~calFn()
{
// empty
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          

/**
  * Fixed date of the k-day before fixed date (rd)
  * k-day of 0 means sunday, 1 means monday and so on.
  * Inputs are fixed date and weekday.
  */
int calFn::KDayBefore(const calRataDie& rd, int k)
{
   return KDayOnOrBefore(rd-1, k);
}

/**
  * Fixed date of the k-day after fixed date (rd)
  * k-day of 0 means sunday, 1 means monday and so on.
  * Inputs are fixed date and weekday.
  */
int calFn::KDayAfter(const calRataDie& rd, int k)
{
   return KDayOnOrBefore(rd()+7, k);
}

/**
  * Fixed date of the k-day on or before fixed date (rd)
  * k-day of 0 means sunday, 1 means monday and so on.
  * Inputs are fixed date and weekday.
  */
int calFn::KDayOnOrBefore(const calRataDie& rd, int k)
{
   return rd()-DayOfWeekFromFixed(rd-k);
}

/**
  * Residue class of the day of the week of date.
  * Inputs are fixed date. returns day of the week.
  */
int calFn::DayOfWeekFromFixed(const calRataDie& date)
{
   long int lindex = calFn::Mod(date(), 7);
   int index = static_cast<int>( calFn::Mod(date(), 7) );
   return index;
}

/**
  * Returns fixed date of the n-th k-day after Gregorian date. 
  * Inputs are integer, weekday and gregorain-date
  * k-day of 0 means sunday, 1 means monday and so on.
  */
int calFn::NthKDay(int n, int k, const calGregorian& g_date)
{
   if (n > 0)
   {
      return ( 7*n + KDayBefore(g_date.Fixed(), k) ); // return n-th k-day on or after date.
   }
   else
   {
      return ( 7*n + KDayAfter(g_date.Fixed(), k) ); // return n-th k-day on or before date.
   }
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


