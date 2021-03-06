/**
  *File: calIso.cpp

  *Description:

   this file implements the class calIso

  *Version: 1.1

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
// standard templates
// local includes
#include "calIso.h"
#include "calRataDie.h"
#include "calGregorian.h"

// const declarations
const char* calIso_id = 
   "@(#) calIso. implementation. ver. 1.1. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
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
calIso::calIso(const calYear& year, const calWeek& week, const calDay& day)
   : pv_year( year() ), pv_week( week() ), pv_day( day() )
{
   _Fixed();
}

/**
  *Purpose: provides copy constructor
  */
calIso::calIso(const calIso& iso)
   : pv_year( iso.pv_year ), pv_week( iso.pv_week ), pv_day( iso.pv_day )
{
   _Fixed();
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

calIso& calIso::operator=(const calIso& iso)
{
   pv_year  = iso.pv_year;  pv_week = iso.pv_week;  pv_day = iso.pv_day;
   pv_fixed = iso.pv_fixed;
   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

calIso::~calIso()
{
// empty
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          


calRataDie calIso::Fixed() const
{
   return calRataDie( pv_fixed );
}

void calIso::_Fixed()
{
   int sunday   = 0;
   int december = 12;

   pv_fixed = calFn::NthKDay( pv_week, sunday, calGregorian(pv_year-1, december, 28) ) + pv_day;
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


