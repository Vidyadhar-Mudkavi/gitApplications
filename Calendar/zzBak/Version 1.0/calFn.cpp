/**
  *File: calFn.cpp

  *Description:

   this file implements the class calFn

  *Version: 1.0

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
   "@(#) calFn. implementation. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
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


int calFn::KDayBefore(const calRataDie& rd, int k)
{
   return KDayOnOrBefore(rd-1, k);
}

int calFn::KDayAfter(const calRataDie& rd, int k)
{
   return KDayOnOrBefore(rd()+7, k);
}

int calFn::KDayOnOrBefore(const calRataDie& rd, int k)
{
   return rd()-DayOfWeekFromFixed(rd-k);
}


int calFn::DayOfWeekFromFixed(const calRataDie& date)
{
   long int lindex = calFn::Mod(date(), 7);
   int index = static_cast<int>( calFn::Mod(date(), 7) );
   return index;
}

int calFn::NthKDay(int n, int k, const calGregorian& g_date)
{
   if (n > 0)
   {
      return ( 7*n + KDayBefore(g_date.Fixed(), k) );
   }
   else
   {
      return ( 7*n + KDayAfter(g_date.Fixed(), k) );
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


