#ifndef _CALISO_
#define _CALISO_
/**
  *File: calIso.h

  *Description:

   this file declares class calIso

  *Version: 1.2 "@(#) calIso. header. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

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
class calRataDie;

// begin class declaration
class calIso : public calBase
{
   friend class calRataDie;
   inline friend std::ostream& operator<<(std::ostream& os, const calIso& iso_date);

   public:
   // constructors
      calIso(const calYear& year=1, const calWeek& week=1, const calDay& day=1); // default
      calIso(const calIso& iso);

   // assignment operator
      calIso& operator=(const calIso& iso);
      calIso& operator=(const calIsoDate& date);

   // destructor
      ~calIso();

   // other functionality

   protected:

   private:
      void     _ComputeFixed();

   private:
      long int pv_year;
      int      pv_week;
      int      pv_day;
};

// include any inline code here
inline calIso& calIso::operator=(const calIsoDate& date)
{
   pv_year  = date.Year();
   pv_week  = date.Week();
   pv_day   = date.Day();

   _ComputeFixed();

   return *this;
}


inline std::ostream& operator<<(std::ostream& os, const calIso& iso_date)
{
   os << iso_date.pv_year << "-" << iso_date.pv_week << "-" << iso_date.pv_day; return os;
}

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALISO_
