#ifndef _CALDATE_
#define _CALDATE_
/**
  *File: calDate.h

  *Description:

   this file declares class calDate. this class is a standard representation of
   date. it is composed of year, month and day which are also implemented (inline)
   as tiny classes.

  *Version: 1.0 "@(#) calDate. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

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
class calGregorian;
class calJulian;

// begin class declaration
// supporting classes declared here itself. (deviating from convention for convenience).

// class for year. builds to default year 1. (beginning of gregorian)
class calYear
{
   public:
      calYear(long int year = 1) : pv_value( year ) {}
      calYear(const calYear& year) : pv_value( year.pv_value ) {}
      calYear& operator=(const calYear& year) {
         pv_value = year.pv_value; return *this;
      }

      calYear& operator=(long int year) {
         pv_value = year; return *this;
      }
   
      long int operator()() const { return pv_value; }
   protected:
   private:
      long int pv_value;
};

// class for month. builds to default month 1 (january). (beginning of gregorian)
class calMonth
{
   public:
      calMonth(int month = 1) : pv_value( month ) {}
      calMonth(const calMonth& month) : pv_value( month.pv_value ) {}
      calMonth& operator=(const calMonth& month) {
         pv_value = month.pv_value; return *this;
      }

      calMonth& operator=(int month) {
         pv_value = month; return *this;
      }
   
      long int operator()() const { return pv_value; }
   protected:
   private:
      int pv_value;
};

// class for week. builds to default week 1.
class calWeek
{
   public:
      calWeek(int week = 1) : pv_value( week ) {}
      calWeek(const calWeek& week) : pv_value( week.pv_value ) {}
      calWeek& operator=(const calWeek& week) {
         pv_value = week.pv_value; return *this;
      }

      calWeek& operator=(int week) {
         pv_value = week; return *this;
      }
   
      long int operator()() const { return pv_value; }
   protected:
   private:
      int pv_value;
};



// class for day. builds to default day 1. (beginning of gregorian)
class calDay
{
   public:
      calDay(int day = 1) : pv_value( day ) {}
      calDay(const calDay& day) : pv_value( day.pv_value ) {}
      calDay& operator=(const calDay& day) {
         pv_value = day.pv_value; return *this;
      }

      calDay& operator=(int day) {
         pv_value = day; return *this;
      }
   
      long int operator()() const { return pv_value; }
   protected:
   private:
      int pv_value;
};

class calDate
{
   friend class calGregorian;
   friend class calJulian;

   public:
   // constructors
      calDate(const calYear& year = 1, const calMonth& month = 1, const calDay& day = 1)
         : pv_year( year() ), pv_month( month() ), pv_day( day() ) {
      }
      
      calDate(const calDate& date)
         : pv_year( date.pv_year ), pv_month( date.pv_month ), pv_day( date.pv_day ) {
      }
   
   // assignment operator
      calDate& operator=(const calDate& date) {
         pv_year = date.pv_year; pv_month = date.pv_month; pv_day = date.pv_day;
         return *this;
      }

   // destructor
      ~calDate() {}

   // accessors
      inline void Set(const calYear& year, const calMonth& month, const calDay& day);


   protected:
   private:
   // helpers used by friends
      inline long int Year()  const { return pv_year;  }
      inline      int Month() const { return pv_month; }
      inline      int Day()   const { return pv_day;   }

   // data
      long int pv_year;
      int      pv_month;
      int      pv_day;
};


class calIsoDate
{
   friend class calIso;
   public:
   // constructors
      calIsoDate(const calYear& year = 1, const calWeek& week = 1, const calDay& day = 1)
         : pv_year( year() ), pv_week( week() ), pv_day( day() ) {
      }
      
      calIsoDate(const calIsoDate& date)
         : pv_year( date.pv_year ), pv_week( date.pv_week ), pv_day( date.pv_day ) {
      }
   
   // assignment operator
      calIsoDate& operator=(const calIsoDate& date) {
         pv_year = date.pv_year; pv_week = date.pv_week; pv_day = date.pv_day;
         return *this;
      }

   // destructor
      ~calIsoDate() {}

   // accessors
      inline void Set(const calYear& year, const calWeek& week, const calDay& day);


   protected:
   private:
   // helpers used by friends
      inline long int Year() const { return pv_year;  }
      inline      int Week() const { return pv_week; }
      inline      int Day()  const { return pv_day;   }

   // data
      long int pv_year;
      int      pv_week;
      int      pv_day;
};


// include any inline code here
inline void calDate::Set(const calYear& year, const calMonth& month, const calDay& day)
{
   pv_year = year(); pv_month = month();  pv_day = day();
}


inline void calIsoDate::Set(const calYear& year, const calWeek& week, const calDay& day)
{
   pv_year = year(); pv_week = week();  pv_day = day();
}

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _CALDATE_
