#ifndef _ELEVATION_
#define _ELEVATION_
/**
  *File: elevation.h

  *Description:

   this file declares class elevation. this is a simple storage class
   used to store elevation (terrestrial) of a place. used mainly
   to construct terrestrialLocation objects.

   everything is inlined for brewity and speed.

   NOTE: elevation is stored in meters.

  *Version: 1.0 "@(#) elevation. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:    2005-09-16
  */

// system includes
// standard template
// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration
class elevation
{
   public:
   // constructors
      elevation() : pv_value( 0 ) {}   // defaults to sea level.
      elevation(double value) : pv_value( value ) {}
      elevation(const elevation& elev) : pv_value( elev.pv_value ) {}

   // assignment operator
      elevation& operator=(const elevation& elev) { pv_value = elev.pv_value; return *this; }
      elevation& operator=(double value) { pv_value = value; return *this; }

   // destructor
      ~elevation() {};

   // accessors
      inline double  operator()() const;
      inline double& operator()();

   protected:
   private:
      double pv_value;  // value in meters only
};

// include any inline code here

// basic read function
inline double elevation::operator()() const
{
   return pv_value;
}

// both read and write function
// since [] requires an argument, cant use it here for write and
// reserve () for read. this is an exceptional case.
inline double& elevation::operator()()
{
   return pv_value;
}


/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _ELEVATION_
