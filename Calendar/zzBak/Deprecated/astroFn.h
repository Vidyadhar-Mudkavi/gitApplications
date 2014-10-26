#ifndef _ASTROFN_
#define _ASTROFN_
/**
  *File: astroFn.h

  *Description:

   this file declares class astroFn. this class is a function object which
   encapsulates all the astronomical functions.

   related classes are also defined here. these are
      terrestrialLocation, latitude, longitude, elevation, timeZone

   from book: Calendrical calculations by Reingold and Dershowitz

  *Version: 1.0 "@(#) astroFn. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:    2005-09-12
  */

// system includes
#include <iostream>

// standard template
// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration
class astroFn
{
   public:
   // test function
      inline static void Dummy();
   // destructor
      ~astroFn();

   protected:
   private:
   // constructors
      astroFn(); // default
      astroFn(const astroFn& astro_function);

   // assignment operator
      astroFn& operator=(const astroFn& astro_function);
};


// include any inline code here

inline void astroFn::Dummy()
{
   std::cout << " >> test function astroFn::Dummy() << " << std::endl;
}

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _ASTROFN_
