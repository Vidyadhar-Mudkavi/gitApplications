/**
  *File: calIso.cpp

  *Description:

   this file implements the class calIso

  *Version: 1.2

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

#if 0
// const declarations
const char* calIso_id = 
   "@(#) calIso. implementation. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
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
tCalIso<T>::tCalIso(const calYear& year, const calWeek& week, const calDay& day)
   : pv_year( year() ), pv_week( week() ), pv_day( day() )
{
   _ComputeFixed();
}

/**
  *Purpose: provides copy constructor
  */
template <typename T>
tCalIso<T>::tCalIso(const tCalIso& iso)
   : tCalBase( iso ),
     pv_year( iso.pv_year ), pv_week( iso.pv_week ), pv_day( iso.pv_day )
{
// empty
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

template <typename T>
tCalIso<T>& tCalIso<T>::operator=(const tCalIso& iso)
{
// must invoke the base class assignment as well
   (*static_cast<tCalBase*>(this)) = iso;
   pv_year  = iso.pv_year;  pv_week = iso.pv_week;  pv_day = iso.pv_day;
   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

template <typename T>
tCalIso<T>::~tCalIso()
{
// empty
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          

template <typename T>
void tCalIso<T>::_ComputeFixed()
{
   int sunday   = 0;
   int december = 12;

   _Fixed( tCalFn<T>::NthKDay( pv_week, sunday, tCalGregorian<T>(pv_year-1, december, 28) ) + pv_day );
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


