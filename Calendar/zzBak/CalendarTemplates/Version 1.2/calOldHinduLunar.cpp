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
#if 0
#include "calBase.h"
#include "calOldHinduSolar.h"
#endif
//#include "calFn.h"
#include "calOldHinduLunar.h"

// const declarations
const char* calOldHinduLunar = 
   "@(#) calOldHinduLunar. implementation. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
// function prototypes
// forward declarations

// begin class implementation

// static data initialization

#if 0
const long int    calOldHinduLunar::pv_epoch = -1132959;
const long double calOldHinduLunar::pv_arya_LunarMonth = static_cast<long double>( 1577917500 ) /
                                                            static_cast<long double>( 53433336 );

const long double calOldHinduLunar::pv_arya_LunarDay = calOldHinduLunar::pv_arya_LunarMonth /
                                                            static_cast<long double>( 30 );
#endif

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
// empty
}

/**
  *Purpose: builds from lunar date
  */
calOldHinduLunar::calOldHinduLunar(const calDateOldHinduLunar& l_date)
   : pv_year( l_date.Year() ), pv_month( l_date.Month() ), 
     pv_leapMonth( l_date.isLeap() ), pv_day( l_date.Day() )
{
// empty
}


#if 0
calOldHinduLunar::calOldHinduLunar(const calOldHinduLunar& old_HLunar)
{
// empty
}
#endif

#if 0
calOldHinduLunar::calOldHinduLunar(const calOldHinduLunar& old_HL)
/*   : calBase( old_HL )//,
//     pv_year( old_HL.pv_year ), pv_month( old_HL.pv_month ), pv_leap_month(old_HL.pv_leap_month),
//     pv_day( old_HL.pv_day ) */
{
// empty
}


/**
  *Purpose: provides default constructor
  */
calOldHinduLunar::calOldHinduLunar()
   : pv_year( 1 ), pv_month( 1 ), pv_leap_month(false), pv_day( 1 )
{
   _ComputeFixed();
}

calOldHinduLunar::calOldHinduLunar(long int year, int month, bool is_leap, int day)
   : pv_year( year ), pv_month( month ), pv_leap_month( is_leap ), pv_day( day )
{
   _ComputeFixed();
}




calOldHinduLunar::calOldHinduLunar(const calDateOldHinduLunar& date)
   : pv_year( date.Year() ), pv_month( date.Month() ), pv_leap_month( date.isLeap() ), 
     pv_day( date.Day() )
{
   _ComputeFixed();
}



calOldHinduLunar& calOldHinduLunar::operator=(const calOldHinduLunar& old_HL)
{
// one can also do this through static_cast operator (page 947. Lippman and lajoie, 3rd ed.)
   (*static_cast<calBase*>(this)) = old_HL;

   pv_year  = old_HL.pv_year;
   pv_month = old_HL.pv_month;
   pv_leap_month = old_HL.pv_leap_month;
   pv_day   = old_HL.pv_day;

   return *this;
}

calOldHinduLunar& calOldHinduLunar::operator=(const calDateOldHinduLunar& date)
{
   pv_year       = date.Year();
   pv_month      = date.Month();
   pv_leap_month = date.isLeap();
   pv_day        = date.Day();

   _ComputeFixed();

   return *this;
}

std::ostream& calOldHinduLunar::operator<<(std::ostream& os, const calOldHinduLunar& old_HL)
{
   os << old_HL.pv_year << "-" << old_HL.pv_month << "-"  << old_HL.pv_leap_month << "-" 
      << old_HL.pv_day; return os;
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
#endif

#if 0
calOldHinduLunar::calOldHinduLunar(const calOldHinduLunar& old_HL)
   : calBase( old_HL ),
     pv_year( old_HL.pv_year ), pv_month( old_HL.pv_month ), pv_leap_month(old_HL.pv_leap_month),
     pv_day( old_HL.pv_day )
{
// empty
}

/**
  *Purpose: provides copy constructor
  */

#endif
   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

#if 0
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
   if ( !pv_leap_month && 
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
{
}

#endif // end of example


 