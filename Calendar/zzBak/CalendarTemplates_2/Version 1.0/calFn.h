#ifndef _CALFN_
#define _CALFN_
/**
  *File: calFn.h

  *Description:

   this file declares class calFn which is a collection of commonly
   used calendar functions such as Floor, Mod and so on. no
   instance of this is ever created.

  *Version: 1.0 "@(#) calFn. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
// standard template
// local includes
// const declarations
// function prototypes
// forward declarations
class calRataDie;
class calGregorian;

// begin class declaration
class calFn
{
   public:

   // these are general math functions but specifically implemented here
   // note that we cannot directly user the floor and ceiling functions
      inline static long int FloorFrac(long int num, long int den);
      inline static long int Mod(long int x, long int y);
      inline static long int Amod(long int x, long int y);
      inline static long int Floor(long double d);

   // calendar related general functions
   // cycle of days
      static int KDayBefore(const calRataDie& rd, int k);
      static int KDayOnOrBefore(const calRataDie& rd, int k);

      static int KDayAfter(const calRataDie& rd, int k);
      static int NthKDay(int n, int k, const calGregorian& g_date);

      static int DayOfWeekFromFixed(const calRataDie& rd);


   // destructor
      ~calFn();

   protected:
   private:
   // constructors
      calFn(); // default
      calFn(const calFn& cf);

   // assignment operator
      calFn& operator=(const calFn& class_var);
};

// include any inline code here
inline long int calFn::FloorFrac(long int num, long int den)
{
// first check if num is exactly divisible by den (do integer arithmetic)
   long int abs_num = (num < 0) ? -num : num;
   long int abs_den = (den < 0) ? -den : den;
   if ( (abs_num/abs_den)*abs_den == abs_num )
   {
      return num/den;
   }

   long double frac = static_cast<long double>(num) / static_cast<long double>(den);
   return (frac < 0 ? (-static_cast<long int>(-frac)-1) : static_cast<long int>(frac));
}

inline long int calFn::Floor(long double d)
{
   return (d < 0 ? (-static_cast<long int>(d) - 1) : static_cast<long int>(d));
}

/**
  *Purpose: Takes the modulo of x and y. it appears
            that when x is exactly divisible by y,
            the modulo value is equal to y! this 
            is taken care of by the if statement.
            (it is a result of FloorFrac doing
             floating point comuputation.)
  */
inline long int calFn::Mod(long int x, long int y)
{
   long int modulo = (x - y * FloorFrac(x, y));
   if (modulo == y) modulo = 0;
   return modulo;
//   return (x - y * FloorFrac(x, y));
}

inline long int calFn::Amod(long int x, long int y)
{
   return ( Mod(x,y) == 0 ? y : Mod(x, y) );
#if 0
   if ( Mod(x, y) == 0)
   {
      return y;
   }
   else
   {
      return ( Mod(x, y) );
   }
#endif
}


/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALFN_
