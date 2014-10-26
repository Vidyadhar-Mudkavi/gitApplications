#ifndef _CALGREGORIAN_
#define _CALGREGORIAN_
/**
  *File: calGregorian.h

  *Description:

   this file declares class calGregorian.
   apart from storing year, month and day, the corresponding fixed date is also
   stored. this is useful in subtracting dates etc.

  *Version: 1.2 "@(#) calGregorian. header. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

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
template <typename T> class calRataDie;

#if 0
class calIso;
#endif

// begin class declaration
template <typename T>
class calGregorian : public calBase<T>
{
   friend class calRataDie<T>;
#if 0
   friend class calIso;
#endif
   inline friend std::ostream& operator<<(std::ostream& os, const calGregorian& g_date)
   {
      os << g_date.pv_year << "-" << g_date.pv_month << "-" << g_date.pv_day; return os;
   }

   public:
   // constructors
      calGregorian(); // default
      calGregorian(const calDate& date);
      calGregorian(const calGregorian& gregorian);

   // assignment operator
      inline calGregorian& operator=(const calGregorian& gregorian);
      inline calGregorian& operator=(const calDate& date);

   // destructor
      ~calGregorian();

   // accessors
      long int Year() const { return pv_year; }

   // other functionality
      inline bool isLeapYear() const;

      static inline long int Epoch() { return pv_epoch; }

   protected:
      calGregorian(long int year, int month, int day);

   private:
      void      _ComputeFixed();

   private:
      long int pv_year;
      int      pv_day;
      int      pv_month;

      static const long int pv_epoch;

};

// include any inline code here
template <typename T>
inline calGregorian<T>& calGregorian<T>::operator=(const calGregorian& gregorian)
{
#if 0
// explicitly invoke the assignment for the base
   (*this).calBase::operator = ( gregorian );
#endif

// one can also do this through static_cast operator (page 947. Lippman and lajoie, 3rd ed.)
   (*static_cast<calBase<T>*>(this)) = gregorian;

   pv_year  = gregorian.pv_year;
   pv_month = gregorian.pv_month;
   pv_day   = gregorian.pv_day;

   return *this;
}

template <typename T>
inline calGregorian<T>& calGregorian<T>::operator=(const calDate& date)
{
   pv_year  = date.Year();
   pv_month = date.Month();
   pv_day   = date.Day();

   _ComputeFixed();

   return *this;
}

/**
  *Purpose: asserts if the year is a leap year.
  
  * Note: in lisp implementation, it does not matter if x is negative in
          x mod y so long as y is positive. in c++, we must take care of
          this.
  */
template <typename T>
inline bool calGregorian<T>::isLeapYear() const
{
   long int year = pv_year < 0 ? -pv_year : pv_year;  // use absolute value

   return ( (year%4 == 0) && 
            ( (year%400 != 100) && (year%400 != 200) && (year%400 != 300) )
          );
}


#if 0
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const calGregorian<T>& g_date)
{
   os << g_date.pv_year << "-" << g_date.pv_month << "-" << g_date.pv_day; return os;
}
#endif

// code from .cpp implementaion.

/**
  *Purpose: provides default constructor
  */
template <typename T>
calGregorian<T>::calGregorian()
   : pv_year( 1 ), pv_month( 1 ), pv_day( 1 )
{
   _ComputeFixed();
}

template <typename T>
calGregorian<T>::calGregorian(const calDate& date)
   : pv_year( date.Year() ), pv_month( date.Month() ), pv_day( date.Day() )
{
   _ComputeFixed();
}

template <typename T>
calGregorian<T>::calGregorian(long int year, int month, int day)
   : pv_year( year ), pv_month( month ), pv_day( day )
{
   _ComputeFixed();
}

/**
  *Purpose: provides copy constructor
  */
template <typename T>
calGregorian<T>::calGregorian(const calGregorian& g)
   : calBase( g ),
     pv_year( g.pv_year ), pv_month( g.pv_month ), pv_day( g.pv_day )
{
// empty
}


   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

template <typename T>
calGregorian<T>::~calGregorian()
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
template <typename T>
void calGregorian<T>::_ComputeFixed()
{
   long int t0, t1, t2, t3, t4, t5, t6;

   long int epoch = pv_epoch;

   t0 = pv_epoch - 1;                           // days before the start of the calendar
   
   t1 = 365 * (pv_year - 1);                    // ordinary days since epoch

   t2 = calFn::FloorFrac( (pv_year-1), 4 );     // julian leap days since epoch

   t3 = calFn::FloorFrac( (pv_year-1), 100 );   // minus century years since epoch.
   
   t4 = calFn::FloorFrac( (pv_year-1), 400 );   // plus the years since epoch divisible by 400

   t5 = calFn::FloorFrac( (367 * pv_month - 362), 12 );  // days in prior months this year 
                                                         // assuming 30 day february

// correction for 28 or 29 day february
   t6 = 0;

   if ( pv_month > 2  && (isLeapYear() == true) )
   {
      t6 = -1;
   }
   else
   {
      if ( pv_month > 2 )
      {
         t6 = -2;
      }
   }

   _Fixed(t0 + t1 + t2 - t3 + t4 + t5 + t6 + pv_day);
   return;
}

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALGREGORIAN_
