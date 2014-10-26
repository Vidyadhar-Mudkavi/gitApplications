#ifndef _CALJULIANDAYNUMBER_
#define _CALJULIANDAYNUMBER_
/**
  *File: calJulianDayNumber.h

  *Description:

   this file declares class calJulianDayNumber

  *Version: 1.2 "@(#) calJulianDayNumber. header. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
#include <iostream>

// standard template
#include "calBase.h"

// local includes
// const declarations
// function prototypes
// forward declarations
template <typename T>
class calRataDie;

// begin class declaration

template <typename T>
class calJulianDayNumber : public calBase<T>
{
   friend inline std::ostream& operator<<(std::ostream& os, const calJulianDayNumber<T>& jd)
   {
      os << "(" << jd.IntegerPart() << ", " << jd.FractionalPart() << ") "; return os;
   }
   public:
   // constructors
      calJulianDayNumber(); // default
      calJulianDayNumber(long int integerPart, double fractionalPart = 0.0);
      calJulianDayNumber(long double jdn);
      calJulianDayNumber(const calJulianDayNumber<T>& jdn);

   // assignment operator
      calJulianDayNumber<T>& operator=(const calJulianDayNumber<T>& jdn);

   // destructor
      ~calJulianDayNumber();

   // accessors
      long int IntegerPart()    const { return static_cast<long int>(pv_value); }
      double   FractionalPart() const { return pv_value - static_cast<long int>(pv_value); }

      static long double Epoch() { return pv_epoch; }

//      static long int EpochIntegerPart() { return pv_epoch_integerPart; }

   // other functionality

//      calRataDie Fixed() const;

   protected:

   private:
      void _ComputeFixed();

   private:
      long double pv_value;

      static const long double pv_epoch;
};

// include any inline code here
#if 0
inline std::ostream& operator<<(std::ostream& os, const calJulianDayNumber& jd)
{
   os << "(" << jd.IntegerPart() << ", " << jd.FractionalPart() << ") "; return os;
}
#endif

// templatized .cpp implementation
template <typename T>
calJulianDayNumber<T>::calJulianDayNumber()
   : pv_value( 0.0 )
{
   _ComputeFixed();
}


template <typename T>
calJulianDayNumber<T>::calJulianDayNumber(long int integerPart, double fractionalPart)
   : pv_value( static_cast<long double>( static_cast<long double>(integerPart) + 
                                         static_cast<long double>(fractionalPart) 
                                       )
             )
{
   _ComputeFixed();
}


template <typename T>
calJulianDayNumber<T>::calJulianDayNumber(long double jdn)
   : pv_value( jdn )
{
   _ComputeFixed();
}

/**
  *Purpose: provides copy constructor
  */

template <typename T>
calJulianDayNumber<T>::calJulianDayNumber(const calJulianDayNumber<T>& jdn)
   : pv_value( jdn.pv_value )
{
// empty
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      


template <typename T>
calJulianDayNumber<T>& calJulianDayNumber<T>::operator=(const calJulianDayNumber<T>& jdn)
{
   pv_value    = jdn.pv_value;
   _ComputeFixed();
   return *this;
}


   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

template <typename T>
calJulianDayNumber<T>::~calJulianDayNumber()
{
// empty
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          

/**
  *Purpose: returns the fixed day corresponding to the Julian
            day number. the definition from the book is:
            moment-from-jd(jd) := jd + jd-epoch;
            fixed-from-jd(jd) := |_ moment-from-jd(jd) _|
                                 = |_ jd + jd-epoch _|
                                 = 
  */

template <typename T>
void calJulianDayNumber<T>::_ComputeFixed()
{
   calRataDie<T> fixed;
   _Fixed( calFn::Floor( pv_value + pv_epoch ) );
}


/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
// typedef calJulianDayNumber calJD;
// typedef calJulianDayNumber calJDN;
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALJULIANDAYNUMBER_
