/**
  *File: calBase.cpp

  \Brief
    - this file implements the class calBase. this forms the base class
      for all calendars.

  \Version  1.2

  \Authors
          - Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  \Date
  */

// system includes
// standard templates
// local includes
#include "calBase.h"
#include "calRataDie.h"

// const declarations
const char* calBase_id = 
   "@(#) calBase. implementation. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
// function prototypes
// forward declarations

// begin class implementation
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

#if 0
   /**
  *Purpose: provides default constructor
  */
calBase::calBase()
   : pv_fixed( 1 )
{
// empty
}

/**
  *Purpose: provides copy constructor
  */
calBase::calBase(const calBase& cal_base)
   : pv_fixed( cal_base.pv_fixed )
{
// empty
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

calBase& calBase::operator=(const calBase& cal_base)
{
   pv_fixed = cal_base.pv_fixed;
   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

calBase::~calBase()
{
// empty
}
#endif

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          
calRataDie calBase::Fixed() const
{
   return calRataDie( pv_fixed );
}

// follow this pattern for function comments

/**
  \Brief
  \Return
  \Params
  \Throws
  */

// here is an example
#if 0 // here is an example
/**
  \Brief
    - this function add the matrix passed as arg.

  \Return
    - matrixNode* ... pointer to a matrix node

  \Param
    - ptr_mn -- a const pointer to matrix node
    - gmn    -- general matrix node

  \Throws
    - aMatrix::exception object
  */
matrixNode* aMatrix::Add(const matrixNode* ptr_mn, ...)
#endif // end of example


