#ifndef _CALOLDHINDULUNAR_
#define _CALOLDHINDULUNAR_
/**
  *File: calOldHinduLunar.h

  *Description:

   this file declares class calOldHinduLunar.
   Lunisolar calendar.

  *Version: 1.0 "@(#) calOldHinduLunar. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <iostream>

// standard template
// local includes
#include "calBase.h"
#include "calDate.h"
#include "calFn.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration

class calOldHinduLunar
{
   inline friend std::ostream& operator<<(std::ostream& os, const calOldHinduLunar& old_HL);
   public:
   // constructors
      calOldHinduLunar();  // default
      calOldHinduLunar(const calDateOldHinduLunar& l_date);
      calOldHinduLunar(const calOldHinduLunar& old_HL);

   // assignment operator
   protected:
   private:
      long int pv_year;
      int      pv_month;
      bool     pv_leapMonth;
      int      pv_day;
};

#if 0
class calOldHinduLunar : public calBase
{
   friend class calRataDie;
//   friend std::ostream& operator<<(std::ostream& os, const calOldHinduLunar& old_HL);

   public:
   // constructors
      calOldHinduLunar(); // default
      calOldHinduLunar(const calDateOldHinduLunar& date);
      calOldHinduLunar(const calOldHinduLunar& old_HL);

   // assignment operators
      calOldHinduLunar& operator=(const calOldHinduLunar& old_HL);
      calOldHinduLunar& operator=(const calDateOldHinduLunar& date);

   // destructor
      ~calOldHinduLunar();

   // other functionality
      long int DayCount() const { return _Fixed() - pv_epoch; }

      bool isLeapYear() const;
      
      static long int    Epoch()          { return pv_epoch; }
      static long double AryaLunarMonth() { return pv_arya_LunarMonth; }
      static long double AryaLunarDay()   { return pv_arya_LunarDay; }

   protected:
   // this one is used exclusively by RataDie.
      static inline long int DayCount(long int fixed_date) { return fixed_date - pv_epoch; }
      
      calOldHinduLunar(long int year, int month, bool is_leap, int day);

   private:
      void      _ComputeFixed();

   private:
      long int pv_year;
      int      pv_month;
      bool     pv_leap_month;
      int      pv_day;

//      static const long double pv_arya_solarYear;
      static const long double pv_arya_LunarMonth;
      static const long double pv_arya_LunarDay;

//      static const long double pv_jovian_period;

      static const long int pv_epoch;
};
#endif



// include any inline code here

inline std::ostream& operator<<(std::ostream& os, const calOldHinduLunar& old_HL)
{
   char leap = ( old_HL.pv_leapMonth == true ? 't' : 'f' );
   os << old_HL.pv_year << "-" << old_HL.pv_month << "-" << leap << "-"
      << old_HL.pv_day;
   return os;
}

#if 0
inline std::ostream& operator<<(std::ostream& os, const calOldHinduLunar& old_HS)
{
   os << old_HS.pv_year << "-" << old_HS.pv_month << "-"  << old_HS.pv_leap_month << "-" 
      << old_HS.pv_day; return os;
}
#endif


#if 0
inline calOldHinduLunar::calOldHinduLunar(const calOldHinduLunar& old_HL)
   : calBase( old_HL ),
     pv_year( old_HL.pv_year ), pv_month( old_HL.pv_month ), pv_leap_month(old_HL.pv_leap_month),
     pv_day( old_HL.pv_day )
{
// empty
}
#endif

#if 0
inline calOldHinduLunar& calOldHinduLunar::operator=(const calOldHinduLunar& old_HL)
{
// one can also do this through static_cast operator (page 947. Lippman and lajoie, 3rd ed.)
   (*static_cast<calBase*>(this)) = old_HL;

   pv_year  = old_HL.pv_year;
   pv_month = old_HL.pv_month;
   pv_leap_month = old_HL.pv_leap_month;
   pv_day   = old_HL.pv_day;

   return *this;
}

inline calOldHinduLunar& calOldHinduLunar::operator=(const calDateOldHinduLunar& date)
{
   pv_year       = date.Year();
   pv_month      = date.Month();
   pv_leap_month = date.isLeap();
   pv_day        = date.Day();

   _ComputeFixed();

   return *this;
}

inline std::ostream& operator<<(std::ostream& os, const calOldHinduLunar& old_HS)
{
   os << old_HS.pv_year << "-" << old_HS.pv_month << "-"  << old_HS.pv_leap_month << "-" 
      << old_HS.pv_day; return os;
}



/**
  *Purpose: asserts if the year is a leap year.
  
  * Note: in lisp implementation, it does not matter if x is negative in
          x mod y so long as y is positive. in c++, we must take care of
          this.
  */
inline bool calOldHinduLunar::isLeapYear() const
{
   long int year = pv_year;
   
   return ( calFn::ModLongDouble( 
            ( year * calOldHinduSolar::AryaSolarYear() - calOldHinduSolar::AryaSolarMonth() ),
      calOldHinduLunar::AryaLunarMonth() ) >= 
      ( static_cast<long double>( 23902504679 ) /
        static_cast<long double>( 1282400064 )
      ) );
      
}
#endif


/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALOLDHINDULUNAR_
