/**
  *File: calJulianDayNumber.cpp

  *Description:

   this file implements the class calJulianDayNumber

  *Version: 1.2

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
// standard templates
// local includes
#include "calRataDie.h"
#include "calJulianDayNumber.h"

// const declarations
const char* calJulianDayNumber_id = 
   "@(#) calJulianDayNumber. implementation. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
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

calJulianDayNumber::calJulianDayNumber()
   : pv_value( 0.0 )
{
   _ComputeFixed();
}


calJulianDayNumber::calJulianDayNumber(long int integerPart, double fractionalPart)
   : pv_value( static_cast<long double>( static_cast<long double>(integerPart) + 
                                         static_cast<long double>(fractionalPart) 
                                       )
             )
{
   _ComputeFixed();
}


calJulianDayNumber::calJulianDayNumber(long double jdn)
   : pv_value( jdn )
{
   _ComputeFixed();
}

/**
  *Purpose: provides copy constructor
  */

calJulianDayNumber::calJulianDayNumber(const calJulianDayNumber& jdn)
   : pv_value( jdn.pv_value )
{
// empty
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      


calJulianDayNumber& calJulianDayNumber::operator=(const calJulianDayNumber& jdn)
{
   pv_value    = jdn.pv_value;
   _ComputeFixed();
   return *this;
}


   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

calJulianDayNumber::~calJulianDayNumber()
{
// empty
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          

/**
  *Purpose: returns the fixed day corresponding to the Julian
            day number. the definition from the book is:
            moment-from-jd(jd) := jd + jd-epoch;
            fixed-from-jd(jd) := |_ moment-from-jd(jd) _|
                                 = |_ jd + jd-epoch _|
                                 = 
  */

void calJulianDayNumber::_ComputeFixed()
{
   calRataDie fixed;
   _Fixed( calFn::Floor( pv_value + pv_epoch ) );
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


