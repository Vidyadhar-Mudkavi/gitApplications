#ifndef _CALFN_
#define _CALFN_
/**
  *File: calFn.h

  *Description:

   this file declares class calFn which is a collection of commonly
   used calendar functions such as Floor, Mod and so on. no
   instance of this is ever created.

  *Version: 1.2 "@(#) calFn. header. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

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
template <typename T>
class tCalRataDie;
template <typename T>
class tCalGregorian;

// begin class declaration
template <typename T>
class tCalFn
{
   public:

   // these are general math functions but specifically implemented here
   // note that we cannot directly user the floor and ceiling functions
      inline static long int FloorFrac(long int num, long int den);
      inline static long int FloorFracLongDouble(long double num, long double den);
      inline static long int Mod(long int x, long int y);
      inline static long double ModLongDouble(long double x, long double y);
      inline static long int Amod(long int x, long int y);
      inline static long int Floor(long double d);
      inline static long int CeilFrac(long int num, long int den);
      inline static long int CeilFracLongDouble(long double num, long double den);

   // calendar related general functions
   // cycle of days
      static int KDayBefore(const tCalRataDie<T>& rd, int k);
      static int KDayOnOrBefore(const tCalRataDie<T>& rd, int k);

      static int KDayAfter(const tCalRataDie<T>& rd, int k);
      static int NthKDay(int n, int k, const tCalGregorian<T>& g_date);

      static int DayOfWeekFromFixed(const tCalRataDie<T>& rd);

   // destructor
      ~tCalFn();

   protected:
   private:
   // constructors
      tCalFn(); // default
      tCalFn(const tCalFn& cf);

   // assignment operator
      tCalFn<T>& operator=(const tCalFn& class_var);
};

// include any inline code here
template <typename T>
inline long int tCalFn<T>::FloorFrac(long int num, long int den)
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

// is there a case of "exactly" divisible? hard to say.
// will not do this here and now.
template <typename T>
inline long int tCalFn<T>::FloorFracLongDouble(long double num, long double den)
{
   long double frac = num/den;

   return (frac < 0 ? (-static_cast<long int>(-frac)-1) : static_cast<long int>(frac));
}


template <typename T>
inline long int tCalFn<T>::Floor(long double d)
{
   return (d < 0 ? (-static_cast<long int>(-d) - 1) : static_cast<long int>(d));
}

/**
  *Purpose: Takes the modulo of x and y. it appears
            that when x is exactly divisible by y,
            the modulo value is equal to y! this 
            is taken care of by the if statement.
            (it is a result of FloorFrac doing
             floating point comuputation.)
  */
template <typename T>
inline long int tCalFn<T>::Mod(long int x, long int y)
{
   long int modulo = (x - y * FloorFrac(x, y));
   if (modulo == y) modulo = 0;

   return modulo;
//   return (x - y * FloorFrac(x, y));
}

template <typename T>
inline long double tCalFn<T>::ModLongDouble(long double x, long double y)
{
   long double modulo = (x - y * FloorFracLongDouble(x, y));
   long double diff = modulo - y;
   long double abs_diff = ( diff < 0 ? -diff : diff );
   if ( abs_diff < 1.0e-10 ) modulo = 0;

   return modulo;
//   return (x - y * FloorFrac(x, y));
}


template <typename T>
inline long int tCalFn<T>::Amod(long int x, long int y)
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

template <typename T>
inline long int tCalFn<T>::CeilFrac(long int num, long int den)
{
// first check if num is exactly divisible by den (do integer arithmetic)
   long int abs_num = (num < 0) ? -num : num;
   long int abs_den = (den < 0) ? -den : den;

   if ( (abs_num/abs_den)*abs_den == abs_num )
   {
      return num/den;
   }

   long double frac = static_cast<long double>(num) / static_cast<long double>(den);

   return (frac < 0 ? (-static_cast<long int>(-frac)) : (static_cast<long int>(frac) +1));
}

// is there a case of "exactly" divisible? hard to say.
// will not do this here and now.
template <typename T>
inline long int tCalFn<T>::CeilFracLongDouble(long double num, long double den)
{
   long double frac = num/den;

   return (frac < 0 ? (-static_cast<long int>(-frac)) : (static_cast<long int>(frac)+1));
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
