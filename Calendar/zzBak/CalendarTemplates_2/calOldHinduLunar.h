#ifndef _CAL_OLDHINDULUNAR_
#define _CAL_OLDHINDULUNAR_
/**
  *File: calOldHinduLunar.h

  *Description:

   this file declares class calOldHinduLunar

  *Version: 1.0 "@(#) calOldHinduLunar. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <iostream>

// standard template
// local includes
#include "calDate.h"
#include "calBase.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration
class calOldHinduLunar : public calBase
{
   friend class calRataDie;
   inline friend std::ostream& operator<<(std::ostream& os, const calOldHinduLunar& ohl);
   public:
   // constructors
      calOldHinduLunar(); // default
      calOldHinduLunar(const calDateOldHinduLunar l_date);
      calOldHinduLunar(const calOldHinduLunar& ohl);

   // assignment operator
      calOldHinduLunar& operator=(const calOldHinduLunar& ohl);
      calOldHinduLunar& operator=(const calDateOldHinduLunar& l_date);

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
      void  _ComputeFixed();

   private:
   // data
      long int pv_year;
      int      pv_month;
      int      pv_day;
      bool     pv_leapMonth;

   // constants
      static const long double pv_arya_LunarMonth;
      static const long double pv_arya_LunarDay;
      static const long int    pv_epoch;
};

// include any inline code here

inline std::ostream& operator<<(std::ostream& os, const calOldHinduLunar& ohl)
{
   char leap = (ohl.pv_leapMonth == true ? 't' : 'f');
   os << ohl.pv_year << "-" << ohl.pv_month << "-" << leap << "-" << ohl.pv_day;
   return os;
}
/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CAL_OLDHINDULUNAR_
