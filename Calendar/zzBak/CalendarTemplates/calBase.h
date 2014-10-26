#ifndef _CALBASE_
#define _CALBASE_
/**
  *File: calBase.h

  *Description:

   this file declares class calBase. this class forms the base for all the calendars.
   it will hold the rd date and provide comparator operators which will apply to all
   the derived classes.

  *Version: 1.2 "@(#) calBase. header. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

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

// begin class declaration
template <typename T>
class tCalBase
{
   public:
   // constructors
      tCalBase(long int fixed_date = 1) : pv_fixed(fixed_date) { /* empty */ } // default
      tCalBase(const tCalBase& tCal_base) : pv_fixed(tCal_base.pv_fixed) { /* empty */ }

   // assignment operator
      inline tCalBase& operator=(const tCalBase& tCal_base);

   // destructor
      ~tCalBase() { /* empty */ }

   // other functionality
      tCalRataDie<T> Fixed() const;
      inline long int operator-(const tCalBase& tCal_base) const;

      inline bool operator==(const tCalBase& tCal_base) const;
      inline bool operator> (const tCalBase& tCal_base) const;
      inline bool operator< (const tCalBase& tCal_base) const;
      inline bool operator>=(const tCalBase& tCal_base) const;
      inline bool operator<=(const tCalBase& tCal_base) const;
      inline bool operator!=(const tCalBase& tCal_base) const;

   protected:
      inline long int _Fixed() const;
      inline void     _Fixed(long int fixed);

   private:
      long int pv_fixed;   // the corresponding fixed date
};

// include any inline code here
template <typename T>
inline tCalBase<T>& tCalBase<T>::operator=(const tCalBase& tCal_base)
{
   pv_fixed = tCal_base.pv_fixed;
   return *this;
}

template <typename T>
inline long int tCalBase<T>::_Fixed() const
{
   return pv_fixed;
}

template <typename T>
inline void tCalBase<T>::_Fixed(long int fixed)
{
   pv_fixed = fixed;
}

template <typename T>
inline long int tCalBase<T>::operator-(const tCalBase& tCal_base) const
{
   return pv_fixed - tCal_base.pv_fixed;
}

template <typename T>
inline bool tCalBase<T>::operator==(const tCalBase& tCal_base) const
{
   return (pv_fixed == tCal_base.pv_fixed);
}

template <typename T>
inline bool tCalBase<T>::operator> (const tCalBase& tCal_base) const
{
   return (pv_fixed > tCal_base.pv_fixed);
}

template <typename T>
inline bool tCalBase<T>::operator< (const tCalBase& tCal_base) const
{
   return (pv_fixed < tCal_base.pv_fixed);
}

template <typename T>
inline bool tCalBase<T>::operator>=(const tCalBase& tCal_base) const
{
   return (pv_fixed >= tCal_base.pv_fixed);
}

template <typename T>
inline bool tCalBase<T>::operator<=(const tCalBase& tCal_base) const
{
   return (pv_fixed <= tCal_base.pv_fixed);
}

template <typename T>
inline bool tCalBase<T>::operator!=(const tCalBase& tCal_base) const
{
   return (pv_fixed != tCal_base.pv_fixed);
}


/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */ 
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALBASE_
