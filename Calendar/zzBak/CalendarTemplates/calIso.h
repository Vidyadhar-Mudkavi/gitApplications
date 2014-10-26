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
template <typename T>
class tCalRataDie;

// begin class declaration
template <typename T>
class tCalIso : public tCalBase<T>
{
   friend class tCalRataDie<T>;
   inline friend std::ostream& operator<<(std::ostream& os, const tCalIso& iso_date);

   public:
   // constructors
      tCalIso(const calYear& year=1, const calWeek& week=1, const calDay& day=1); // default
      tCalIso(const tCalIso& iso);

   // assignment operator
      tCalIso& operator=(const tCalIso& iso);
      tCalIso& operator=(const calIsoDate& date);

   // destructor
      ~tCalIso();

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
template <typename T>
inline tCalIso<T>& tCalIso<T>::operator=(const calIsoDate& date)
{
   pv_year  = date.Year();
   pv_week  = date.Week();
   pv_day   = date.Day();

   _ComputeFixed();

   return *this;
}


template <typename T>
inline std::ostream& operator<<(std::ostream& os, const tCalIso<T>& iso_date)
{
   os << iso_date.pv_year << "-" << iso_date.pv_week << "-" << iso_date.pv_day; return os;
}

#include "calIso.cpp"

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALISO_
