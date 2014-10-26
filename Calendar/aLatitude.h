#ifndef _A_LATITUDE_
#define _A_LATITUDE_
/**
  *File: aLatitude.h

  \Brief
    - this file declares class aLatitude. it represents the concept of latitude. essentially holds one
      data (angle) which represents latitude of a location. if the latitude is out of range (more than
      90 degre, plus or minus) then exits with an error.

    - all functionality is inlined and hence there is no separate implementation file.

  \Version  1.0 "@(#) aLatitude. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  \Authors
          - Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  \Date
          - 2007-05-30
  */

// system includes
// standard template
// local includes
#include "anException.h"

#include "anAngle.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration
class aLatitude
{
   friend std::ostream& operator<<(std::ostream& os, const aLatitude& p);
   typedef anException exception;
   public:
   // constructors
      aLatitude() : pv_degrees( 0 ), pv_minutes( 0 ), pv_seconds( 0 ) { /** defaults to equator. empty */ }
      aLatitude(const int& degrees, const int minutes = 0, const int seconds = 0)
         : pv_degrees( degrees ), pv_minutes( minutes ), pv_seconds( seconds ),
           pv_fracSeconds( 0.0 )
      {
         if ( degrees > 90 || degrees < -90 )
         {
            std::cout << "*** latitude out of range. exiting from aLatitude::aLatitude(int, int, int)"
                      << std::endl
                      << "*** :-(" << std::endl
                      << std::endl;
            ::exit( -1 );
         }
      }

      aLatitude(const aLatitude& lat)
         : pv_degrees( lat.pv_degrees ), pv_minutes( lat.pv_minutes ), pv_seconds( lat.pv_seconds ),
           pv_fracSeconds( lat.pv_fracSeconds )
      {
      // empty
      }

   // assignment operator
      aLatitude& operator=(const aLatitude& lat)
      {
         pv_degrees = lat.pv_degrees;
         pv_minutes = lat.pv_minutes;
         pv_seconds = lat.pv_seconds;
  
         pv_fracSeconds = lat.pv_fracSeconds;

         return *this;
      }

   // destructor
      ~aLatitude() { /** empty **/ }

   // accessors
      inline void Set(int degrees, int minutes, int seconds = 0, double fracSeconds = 0.0);
      inline void Set(double lat_d);

   protected:
   private:
      int pv_degrees;
      int pv_minutes;
      int pv_seconds;

      double pv_fracSeconds;  // not really needed. this holds fractional part of seconds.
};

// include any inline code here

/**
  \note
      - all accessors are inlined here.
  */
inline void aLatitude::Set(int degrees, int minutes, int seconds, double fracSeconds)
{
   pv_degrees = degrees;
   pv_minutes = minutes;
   pv_seconds = seconds;

   pv_fracSeconds = fracSeconds;
}

inline void aLatitude::Set(double lat_d)
{
   double resid = lat_d;
   pv_degrees = int( resid );    resid -= pv_degrees;    resid *= 60.0;
   pv_minutes = int( resid );    resid -= pv_minutes;    resid *= 60.0;
   pv_seconds = int( resid );    resid -= pv_seconds;
   pv_fracSeconds = resid;
}

inline std::ostream& operator<<(std::ostream& os, const aLatitude& lat)
{
   os << "[" << lat.pv_degrees << ", " << lat.pv_minutes << ", " << lat.pv_seconds << "] ";
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

#endif   // _A_LATITUDE_
