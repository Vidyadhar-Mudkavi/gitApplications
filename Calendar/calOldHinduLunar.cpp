/**
  *File: calOldHinduLunar.cpp

  *Description:

   this file implements the class calOldHinduLunar

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
// standard templates
// local includes
#include "calOldHinduLunar.h"
#include "calOldHinduSolar.h"
#include "calFn.h"

// const declarations
const char* calOldHinduLunar_id = 
   "@(#) calOldHinduLunar. implementation. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
// function prototypes
// forward declarations

// begin class implementation

// static data
const long int    calOldHinduLunar::pv_epoch = -1132959;
const long double calOldHinduLunar::pv_arya_LunarMonth = static_cast<long double>( 1577917500 ) /
                                                            static_cast<long double>( 53433336 );

const long double calOldHinduLunar::pv_arya_LunarDay = calOldHinduLunar::pv_arya_LunarMonth /
                                                            static_cast<long double>( 30 );

   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
  *Purpose: provides default constructor
  */
calOldHinduLunar::calOldHinduLunar()
   : pv_year( 1 ), pv_month( 1 ), pv_leapMonth( false ), pv_day( 1 )
{
   _ComputeFixed();
}

/**
  *Purpose: provides copy constructor
  */
calOldHinduLunar::calOldHinduLunar(const calOldHinduLunar& ohl)
   : calBase( ohl ), 
     pv_year( ohl.pv_year ), pv_month( ohl.pv_month ), 
     pv_leapMonth( ohl.pv_leapMonth ), pv_day( ohl.pv_day )
{
// empty
}

calOldHinduLunar::calOldHinduLunar(const calDateOldHinduLunar l_date)
   : pv_year( l_date.Year() ), pv_month( l_date.Month() ), pv_day( l_date.Day() ),
     pv_leapMonth( l_date.isLeap() )
{
   _ComputeFixed();
}

calOldHinduLunar::calOldHinduLunar(long int year, int month, bool is_leap, int day)
   : pv_year( year ), pv_month( month ), pv_leapMonth( is_leap ), pv_day( day )
{
   _ComputeFixed();
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

calOldHinduLunar& calOldHinduLunar::operator=(const calOldHinduLunar& ohl)
{
// force assignment of base members (page 947. Lippman and lajoie, 3rd ed.)
   (*static_cast<calBase*>(this)) = ohl;

   pv_year      = ohl.pv_year;
   pv_month     = ohl.pv_month;
   pv_day       = ohl.pv_day;
   pv_leapMonth = ohl.pv_leapMonth;
   return *this;
}

calOldHinduLunar& calOldHinduLunar::operator=(const calDateOldHinduLunar& l_date)
{
   pv_year      = l_date.Year();
   pv_month     = l_date.Month();
   pv_day       = l_date.Day();
   pv_leapMonth = l_date.isLeap();

   _ComputeFixed();

   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

calOldHinduLunar::~calOldHinduLunar()
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
            date on the old hindu lunar calendar.
            this is calculated in various parts.
  */
void calOldHinduLunar::_ComputeFixed()
{
   long double t0, t2, t3;

   t0 = static_cast<long double>( pv_epoch );

   long double mina 
                = (12 * static_cast<long double>(pv_year) -1) * calOldHinduSolar::AryaSolarMonth();
   // lunar new year
   long double lunar_new_year 
                = pv_arya_LunarMonth * ( calFn::FloorFracLongDouble(mina, pv_arya_LunarMonth) + 1 );

   long double solar_month = calOldHinduSolar::AryaSolarMonth();
   if ( !pv_leapMonth && 
        (calFn::CeilFracLongDouble( (lunar_new_year - mina), 
                                    (calOldHinduSolar::AryaSolarMonth() - pv_arya_LunarMonth) ))
        <= pv_month )
   {
      t2 = pv_arya_LunarMonth * static_cast<long double>( pv_month );
   }
   else
   {
      t2 = pv_arya_LunarMonth * static_cast<long double>( pv_month -1 );
   }

   t3 = static_cast<long double>( pv_day - 1 ) * pv_arya_LunarDay + 0.75;

   long double fixed_fraction = t0 + lunar_new_year + t2 + t3;

   _Fixed( calFn::Floor( fixed_fraction ) );
}


/**
  *Purpose: asserts if the year is a leap year.
  
  * Note: in lisp implementation, it does not matter if x is negative in
          x mod y so long as y is positive. in c++, we must take care of
          this.
  */
bool calOldHinduLunar::isLeapYear() const
{
   long int year = pv_year;
   
   return ( calFn::ModLongDouble( 
            ( year * calOldHinduSolar::AryaSolarYear() - calOldHinduSolar::AryaSolarMonth() ),
            calOldHinduLunar::AryaLunarMonth() ) >= 
            ( static_cast<long double>( 23902504679 ) /
              static_cast<long double>( 1282400064 )
            ) 
          );
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


