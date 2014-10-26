/**
  *File: calOldHinduSolar.cpp

  *Description:

   this file implements the class calOldHinduSolar

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
// standard templates
// local includes
#include "calOldHinduSolar.h"
#include "calFn.h"

// const declarations
const char* calOldHinduSolar_id = 
   "@(#) calOldHinduSolar. implementation. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
// function prototypes
// forward declarations

// begin class implementation

// static data initialization
const long double calOldHinduSolar::pv_arya_solarYear = static_cast<long double>( 365 ) + 
                                                            ( static_cast<long double>( 149 ) /
                                                              static_cast<long double>( 576 )
                                                            );

const long double calOldHinduSolar::pv_arya_solarMonth = calOldHinduSolar::pv_arya_solarYear /
                                                            static_cast<long double>( 12 );

const long double calOldHinduSolar::pv_jovian_period  = static_cast<long double>( 4332 ) +
                                                            ( static_cast<long double>(  8261 ) /
                                                              static_cast<long double>( 30352 )
                                                            );

   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
  *Purpose: provides default constructor
  */
calOldHinduSolar::calOldHinduSolar()
   : pv_year( 1 ), pv_month( 1 ), pv_day( 1 )
{
   _ComputeFixed();
}


calOldHinduSolar::calOldHinduSolar(const calDate& date)
   : pv_year( date.Year() ), pv_month( date.Month() ), pv_day( date.Day() )
{
   _ComputeFixed();
}


calOldHinduSolar::calOldHinduSolar(long int year, int month, int day)
   : pv_year( year ), pv_month( month ), pv_day( day )
{
   _ComputeFixed();
}

/**
  *Purpose: provides copy constructor
  */
calOldHinduSolar::calOldHinduSolar(const calOldHinduSolar& old_HS)
   : calBase( old_HS ),
     pv_year( old_HS.pv_year ), pv_month( old_HS.pv_month ), pv_day( old_HS.pv_day )
{
// empty
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

calOldHinduSolar::~calOldHinduSolar()
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
void calOldHinduSolar::_ComputeFixed()
{
   long double t0, t1, t2, t3, t4;

   t0 = static_cast<long double>( pv_epoch );

   t1 = static_cast<long double>( pv_year ) * pv_arya_solarYear;

   t2 = static_cast<long double>( pv_month-1 ) * pv_arya_solarMonth;

   t3 = static_cast<long double>( pv_day );

   t4 = static_cast<long double>( 1.0/4.0 );    // brings it to midnight (hindu day at sunrise)

   long double fixed_fraction = t0 + t1 + t2 + t3 - t4;

   _Fixed( calFn::Floor( fixed_fraction ) );

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


