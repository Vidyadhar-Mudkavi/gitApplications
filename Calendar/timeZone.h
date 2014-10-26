#ifndef _TIME_ZONE_
#define _TIME_ZONE_
/**
  *File: timeZone.h

  \Brief
   this file declares class timeZone. it contains time zone in hours and minutes of a location
   with respect to the Greenwich meridian. thus, for any location in India, the time zone
   will hold +5 and 30 (hours and minutes).

   has no implementation file. all functionality is inlined since this is a tiny class.

  \Version  1.0 "@(#) timeZone. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  \Authors
          - Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  \Date
          - 2007-05-30
  */

// system includes
// standard template
// local includes
#include "anException.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration
class timeZone
{
   inline friend std::ostream& operator<<(std::ostream& os, const timeZone& p);
   typedef anException exception;

   public:
   // constructors
      timeZone() : pv_hours( 0 ), pv_minutes( 0 ) { /* empty */ }
      timeZone(const int& hours, const int minutes = 0)
         : pv_hours( hours ), pv_minutes( minutes )
      {
      // empty
      }

      timeZone(const timeZone& tz) : pv_hours( tz.pv_hours ), pv_minutes( tz.pv_minutes ) { /* empty */ }

   // assignment operator
      timeZone& operator=(const timeZone& tz) { pv_hours = tz.pv_hours; pv_minutes = tz.pv_minutes; return *this; }

   // destructor
      ~timeZone() { /* empty */ }

   // accessors
      inline void Set(const int hours, const int minutes = 0);
      inline double operator()() const;

   protected:
   private:
      int pv_hours;
      int pv_minutes;
};

// include any inline code here

/**
  \note
      - all accessors are inlined here.
  */
inline double timeZone::operator()() const
{
   return ( static_cast<double>( pv_hours ) + ( static_cast<double>( pv_minutes ) / 60.0 ) );
}

inline void timeZone::Set(const int hours, const int minutes)
{
   pv_hours   = hours;
   pv_minutes = minutes;
}

inline std::ostream& operator<<(std::ostream& os, const timeZone& tz)
{
   os << "(" << tz.pv_hours << " h, " << tz.pv_minutes << " m) ";
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

#endif   // _TIME_ZONE_
