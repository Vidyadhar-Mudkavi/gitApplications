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
template <typename T> class calRataDie;

// begin class declaration
template <typename T>
class calBase
{
   public:
   // constructors
      calBase(long int fixed_date = 1) : pv_fixed(fixed_date) { /* empty */ } // default
      calBase(const calBase& cal_base) : pv_fixed(cal_base.pv_fixed) { /* empty */ }

   // assignment operator
      inline calBase& operator=(const calBase& cal_base);

   // destructor
      ~calBase() { /* empty */ }

   // other functionality
      inline calRataDie<T> Fixed() const;
      inline long int operator-(const calBase& cal_base) const;

      inline bool operator==(const calBase& cal_base) const;
      inline bool operator> (const calBase& cal_base) const;
      inline bool operator< (const calBase& cal_base) const;
      inline bool operator>=(const calBase& cal_base) const;
      inline bool operator<=(const calBase& cal_base) const;
      inline bool operator!=(const calBase& cal_base) const;

   protected:
      inline long int _Fixed() const;
      inline void     _Fixed(long int fixed);

   private:
      long int pv_fixed;   // the corresponding fixed date
};

// include any inline code here

template <typename T>
inline calBase<T>& calBase<T>::operator=(const calBase& cal_base)
{
   pv_fixed = cal_base.pv_fixed;
   return *this;
}

template <typename T>
inline long int calBase<T>::_Fixed() const
{
   return pv_fixed;
}

template <typename T>
inline void calBase<T>::_Fixed(long int fixed)
{
   pv_fixed = fixed;
}

template <typename T>
inline long int calBase<T>::operator-(const calBase& cal_base) const
{
   return pv_fixed - cal_base.pv_fixed;
}

template <typename T>
inline bool calBase<T>::operator==(const calBase& cal_base) const
{
   return (pv_fixed == cal_base.pv_fixed);
}

template <typename T>
inline bool calBase<T>::operator> (const calBase& cal_base) const
{
   return (pv_fixed > cal_base.pv_fixed);
}

template <typename T>
inline bool calBase<T>::operator< (const calBase& cal_base) const
{
   return (pv_fixed < cal_base.pv_fixed);
}

template <typename T>
inline bool calBase<T>::operator>=(const calBase& cal_base) const
{
   return (pv_fixed >= cal_base.pv_fixed);
}

template <typename T>
inline bool calBase<T>::operator<=(const calBase& cal_base) const
{
   return (pv_fixed <= cal_base.pv_fixed);
}

template <typename T>
inline bool calBase<T>::operator!=(const calBase& cal_base) const
{
   return (pv_fixed != cal_base.pv_fixed);
}

// code from .cpp implementation
template <typename T>
inline calRataDie<T> calBase<T>::Fixed() const
{
   return calRataDie<T>( pv_fixed );
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
