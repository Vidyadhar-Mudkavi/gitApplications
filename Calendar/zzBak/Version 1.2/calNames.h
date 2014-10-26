#ifndef _CALNAMES_
#define _CALNAMES_
/**
  *File: calNames.h

  *Description:

   this file declares a number of calendar name classes. calNames is just a generic name.


  *Version: 1.0 "@(#) calNames. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:    2004-Apr-21
  */

// system includes
#include <iostream>

// standard template
#include <string>

// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration
class calNames
{
   public:
   // constructors
      calNames(); // default
      calNames(const calNames& cal_names);

   // assignment operator
      calNames& operator=(const calNames& cal_names);

   // destructor
      ~calNames();

   protected:
   private:
};

/////////////////////////////////////////////////////////////
//
// gregorian (and julian) names
//
class calGregorianWeekDay
{
   public:
      calGregorianWeekDay();
      inline std::string operator[](int index) const;

      ~calGregorianWeekDay() { delete [] pv_weekDay; }
   protected:
      inline void CheckRange(int index) const;

   private:
      std::string* pv_weekDay;

   // prevent copy and assignment
      calGregorianWeekDay(const calGregorianWeekDay& weekDay);
      calGregorianWeekDay& operator=(const calGregorianWeekDay& weekDay);
};


class calGregorianMonth
{
   public:
      calGregorianMonth();
      inline std::string operator[](int index) const;

      ~calGregorianMonth() { delete [] pv_month; }
  
   protected:
      inline void CheckRange(int index) const;

   private:
      std::string* pv_month;

   // prevent copy and assignment
      calGregorianMonth(const calGregorianMonth& month);
      calGregorianMonth& operator=(const calGregorianMonth& month);
};


/////////////////////////////////////////////////////////////
//
// hindu names
//
class calHinduWeekDay
{
   public:
      calHinduWeekDay();
      inline std::string operator[](int index) const;

      ~calHinduWeekDay() { delete [] pv_weekDay; }
   protected:
      inline void CheckRange(int index) const;

   private:
      std::string* pv_weekDay;

   // prevent copy and assignment
      calHinduWeekDay(const calHinduWeekDay& weekDay);
      calHinduWeekDay& operator=(const calHinduWeekDay& weekDay);
};


class calSamvatsara
{
   public:
      calSamvatsara();
      inline std::string operator[](int index) const;

      ~calSamvatsara() { delete [] pv_samvat; }
   protected:
      inline void CheckRange(int index) const;

   private:
      std::string* pv_samvat;

   // prevent copy and assignment
      calSamvatsara(const calSamvatsara& samvat);
      calSamvatsara& operator=(const calSamvatsara& samvat);
};


// include any inline code here

/////////////////////////////////////////////////////////////////////
//
// gregorian inline implementation
//
inline std::string calGregorianWeekDay::operator[](int index) const
{
   CheckRange(index);
   return pv_weekDay[index];
}

inline void calGregorianWeekDay::CheckRange(int index) const
{
   if ( (index < 0) || (index >= 7) )
   {
      std::cout << "Index out of range in calGregorianWeekDay::CheckRange." << std::endl;
      throw "Error in calGregorianWeekDay::CheckRange :-(";
   }
   return;
}


inline std::string calGregorianMonth::operator[](int index) const
{
   CheckRange(index);
   return pv_month[index];
}

inline void calGregorianMonth::CheckRange(int index) const
{
   if ( (index < 0) || (index >= 12) )
   {
      std::cout << "Index out of range in calGregorianMonth::CheckRange." << std::endl;
      throw "Error in calGregorianMonth::CheckRange :-(";
   }
   return;
}


/////////////////////////////////////////////////////////////////////
//
// hindu inline implementation
//
inline std::string calHinduWeekDay::operator[](int index) const
{
   CheckRange(index);
   return pv_weekDay[index];
}

inline void calHinduWeekDay::CheckRange(int index) const
{
   if ( (index < 0) || (index >= 7) )
   {
      std::cout << "Index out of range in calHinduWeekDay::CheckRange." << std::endl;
      throw "Error in calHinduWeekDay::CheckRange :-(";
   }
   return;
}

inline std::string calSamvatsara::operator[](int index) const
{
   CheckRange(index);
   return pv_samvat[index];
}

inline void calSamvatsara::CheckRange(int index) const
{
   if ( (index < 0) || (index >= 60) )
   {
      std::cout << "Index out of range in calSamvatsara::CheckRange." << std::endl;
      throw "Error in calSamvatsara::CheckRange :-(";
   }
   return;
}

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
typedef calGregorianWeekDay calJulianWeekDay;
typedef calGregorianMonth   calJulianMonth;
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALNAMES_
