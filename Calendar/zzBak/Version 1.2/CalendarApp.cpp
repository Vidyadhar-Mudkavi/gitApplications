/**
  *File: CalendarApp.cpp

  *Description:

   this file test drives objects of type calRataDie
   defined in file calRataDie.h.

   The basic reference for the implementation of these calendars is
   "Calendrical Calculations - The Millennium Edition," by Edward M. Reingold
   and Nachum Dershowitz, Cambridge University Press, 2001.
   Acc No.: 78299/B9:17 P01/NAL

  *Version: 1.2

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:    2004-March-31
  */

// version id
const char* CalendarApp_id = 
   "@(#) CalendarApp. application. ver. 1.2. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";

// system includes
#include <iostream>
#include <iomanip>

// local includes
#include "cpuClock.h"
#include "anException.h"

#include "calRataDie.h"
#include "calJulianDayNumber.h"
#include "calGregorian.h"
#include "calJulian.h"
#include "calIso.h"
#include "calOldHinduSolar.h"

#include "zOHL.h"

#include "calDate.h"

// const declarations
// function prototypes
void TestCode();

// forward declarations

int main(int argc, char* argv[])
{
// store the invoking program name
   char* prg_name = argv[0];

// create an object of cpuClock and start it
   cpuClock clock;
   clock.Start();

// provide convenient i/o streams
   std::ostream& out = std::cout;
   std::istream& ein = std::cin;

// begin application
   try
   {
      TestCode();
   // create some objects (which will be used repeatedly later)
      calDate date;
      calGregorian g;
      calJulian j;
      calRataDie rd;
      calIso iso;
      calOldHinduSolar oldHS;

   // rather than build date using the followig (which works).
      date = calDate( -586,  7, 24);

   // it is safer to build a date using the following
      calYear  y;
      calMonth m;
      calDay   d;

      y = 1968;   m =  5;  d = 15;
      calDate bDay(y, m, d);
      g = bDay;
      out << "Day of week for: " << g << " is " << g.Fixed().DayOfWeek() << std::endl << std::endl;

      y = -1900;  m = 12;  d =  5;
      y =  1968;  m =  5;  d = 15;
      y =  1994;  m =  3;  d =  1;
      y =  -586;  m =  7;  d = 24;

      date.Set(y, m, d);

   // test gregorian calendar

   // test assignment, special construction etc.
      g = date;

      calGregorian g1(g);
      calGregorian g2;

      g2 = g;

      out << g << std::endl << std::endl;

      if ( g.isLeapYear() == true )
      {
         out << g.Year() << " is a leap year " << std::endl;
      }

      out << "Gregorian: " << g << "  => Fixed: " << g.Fixed() << std::endl;
      out << "Day of the week:      " << g.Fixed().DayOfWeek() << std::endl << std::endl;

      calDate g_ep_dt(-4713, 11, 24);
      calGregorian g_ep( g_ep_dt );

      calRataDie rd_g_ep = g_ep.Fixed();

      out << "Fixed from gregorian epoch: " << rd_g_ep << std::endl << std::endl;

   // RD to gregorian.
      rd = -1373427;    // -3760-09-07. Hebrew epoch
      rd = -1721424;    // -4713-11-24. Julian day epoch
      rd =  -214193;    // -0586-07-24. Table entry from book
      rd =       -1;    //  0000-12-30. A day before RD epoch
      rd =  -272787;    // -0746-02-18. Egyptian epoch
      rd =        1;    //  0001-01-01. RD epoch
      rd =   654415;    //  1792-09-22. French Revolutionary epoch.
      rd =   -61387;    // -0168-12-05. Table entry from book
      rd = -1132959;    // -3101-01-23. Hindu Kali Yuga
      rd =   671401;    //  1839-03-27. Table entry from book

      g = rd.Gregorian();

      out << "Fixed: " << rd << " => Gregorian(epoch): " << g << std::endl << std::endl;

   // RD to julian day numbers.
      rd = -214193;

      out << "Julian day number for " << rd << " is " << rd.JulianDayNumber() << std::endl;

      y = 1993;   m = 7;   d = 14;
      date.Set(y, m, d);

      g = date;

      rd = g.Fixed();

      out << "Julian day number for " << g << " is " << rd.JulianDayNumber() << std::endl
          << std::endl;

   // test Julian calendar
      y = -4713;
      m = 1;
      d = 1;
      date.Set(y, m, d);
      j = date;

      calJulian j1(j);
      calJulian j2;
      j2 = j1;

      rd = j.Fixed();
      out << "Julian day number for " << j << " is " << rd.JulianDayNumber() << std::endl
          << std::endl;

      y = -3761;   m = 10;   d =  7;   // Hebrew epoch (rd = 1,373,427)
      y = -3102;   m =  2;   d = 18;   // Hindu Kali Yuga (rd = -1,132,959)
      y =     1;   m =  1;   d =  3;   // Gregorian epoch (rd = 1)
      y =  1792;   m =  9;   d = 11;   // French Revolutionary (rd = 654,415)
      y = - 747;   m =  2;   d = 26;   // Egyptian epoch. (rd = -272,787)

      y = - 587;   m =  7;   d = 30;   // table entry (checked)

      date.Set(y, m, d);
      j = date;
      rd = j.Fixed();
      out << "Fixed date for " << j << " is " << rd << std::endl;

   // take the same rd and invert and check.
      out << "Julian date for rd: " << rd << "  is: " << rd.Julian() << std::endl;

   // check for Julian epoch (it is the Fixed date corresponding to
   // gregorian date of 0-12-30 (and it yields -1).
      y = 0;
      m = 12;
      d =30;

      date.Set(y, m, d);
      g = date;

      out << "Fixed from Gregorian (Julian epoch): " << g << " is: " << g.Fixed() << std::endl
          << std::endl;
      
   // RD to Julian.
      rd = -1721424;    // -4713-01-02. Julian day epoch
      rd =        1;    //  0001-01-03. RD epoch
      rd =   654415;    //  1792-09-11. French Revolutionary epoch.
      rd =  -272787;    // -0747-02-26. Egyptian epoch
      rd =       -1;    //  0001-01-01. Julian epoch
      rd =   -61387;    // -0169-12-08. Table entry from book
      rd =  -214193;    // -0587-07-30. Table entry from book
      rd = -1132959;    // -3102-02-18. Hindu Kali Yuga
      rd = -1373427;    // -3761-10-07. Hebrew epoch
      rd =   671401;    //  1839-03-15. Table entry from book
      
      j = rd.Julian();

      out << "Fixed:  " << rd << "           => Julian (epoch): " << j << std::endl;
      rd = j.Fixed();
      out << "Julian: " << j << " => RD (epoch): " << rd << std::endl << std::endl;

   // Test ISO calender
      calIsoDate isoDate;

      calWeek w;
      y = -586;   w = 29;  d = 7;
      isoDate.Set(y, w, d);
      iso = isoDate;

      calIso iso1 = iso;
      calIso iso2;
      iso2 = iso1;

      rd = iso.Fixed();
      out << "For IsoDate: " << iso << " Fixed = " << rd << std::endl;

      rd =   671401;    //  1839-13-03. Table entry from book
      rd =   -61387;    //  -168-49-03
      rd =   601716;    //  1648-24-03
      rd =  -214193;    // -0586-29-07. Table entry from book
      rd =   434355;    //  1190-12-05

      iso = rd.Iso();
      out << "Fixed:  " << rd << "           => ISO (epoch): " << iso << std::endl;
      rd = iso.Fixed();
      out << "ISO: " << iso << " => RD (epoch): " << rd << std::endl << std::endl;

   // what is the iso of todays date? (2004-04-16);
      y = 2004;   m = 4;   d = 19;
      date.Set(y, m, d);
      g = date;
      rd = g.Fixed();

      out << "Gregorian: " << g << "  => ISO: " << rd.Iso() << std::endl << std::endl;

   // date difference (gives number of days between two dates)
      calGregorian g_beg;
      calGregorian g_end;

      g_beg = calDate(1968, 5, 15);
      g_end = calDate(2004, 4, 16);
      out << "No of days between: " << g_beg << " and " 
          << g_end << "  = " << g_end-g_beg << std::endl << std::endl;


   // Old hindu calendars
      y = -3102;  m = 2;   d = 18;
      date.Set(y, m, d);
      j = date;
      rd = j.Fixed();
      g = rd.Gregorian();

      out << "Hindu epoch (in RD) = " << j.Fixed() << " => Julian date: " << j << std::endl 
          << "          Gregorian date is: " << g << std::endl << std::endl;


      calOldHinduSolar oldHS1 =  oldHS;
      calOldHinduSolar oldHS2;

      oldHS2 = oldHS1;

      out << "Arya solar year: " << std::setprecision(16) << oldHS.AryaSolarYear() << std::endl
          << "Jovian period: " << oldHS.JovianPeriod() << std::endl << std::endl;

      rd = -214193;
      rd =  764652;

      oldHS = rd.OldHinduSolar();

      out << "rd: " << rd << " => old hindu solar: " << oldHS << std::endl << std::endl;

      y = 2515;   m = 5;   d = 19;
      date.Set(y, m, d);

      oldHS = date;

      rd = oldHS.Fixed();

      out << "Old hindu solar date: " << oldHS << " => rd: " << rd << std::endl << std::endl;

   // there is some trouble in implementing calOldHinduLunar. dont know what it is
   // but we are not able to put the copy constructor in the implementation file.
   // zOHL is an imitation written afresh to settle this problem.
      zOHL old_hl;


      rd = -214193;
      rd =  764652;

      old_hl = rd.OldHinduLunar();

      out << "rd: " << rd << " => old hindu lunar: " << old_hl << std::endl << std::endl;

      bool lm;
      calDateOldHinduLunar l_date;
      y = 2515;   m = 6;   lm = false; d = 11;
      y = 5195;   m = 4;   lm = false; d =  6;
      l_date.Set(y, m, lm, d);

      old_hl = l_date;

      rd = old_hl.Fixed();
      g = rd.Gregorian();

      out << "Old hindu lunar date: " << old_hl << " => rd: " << rd << std::endl
          << "     Gregorian date: " << g << std::endl << std::endl;


      y = 1968;   m = 5;   d = 15;
      date.Set(y, m, d);
      g = date;

      rd = g.Fixed();

      old_hl = rd.OldHinduLunar();

      out << " Gregorian: " << g << " Old hindu lunar: " << old_hl << std::endl << std::endl;

      y = 5069;   m =  2;  lm = false; d = 19;
      l_date.Set(y, m, lm, d);
      old_hl = l_date;
      rd = old_hl.Fixed();
      g = rd.Gregorian();

      out << " Old hindu solar: " << old_hl << " Gregorian: " << g << std::endl << std::endl;

#if 0
   // old hindu lunisolar calendar
      calOldHinduLunar oldHL;

      rd = -214193;
      rd =  764652;

      oldHL = rd.OldHinduLunar();

      out << "rd: " << rd << " => old hindu lunar: " << oldHL << std::endl << std::endl;

      bool lm;
      calDateOldHinduLunar l_date;
      y = 2515;   m = 6;   lm = false; d = 11;
      y = 5195;   m = 4;   lm = false; d =  6;
      l_date.Set(y, m, lm, d);

      oldHL = l_date;

      rd = oldHL.Fixed();

      out << "Old hindu lunar date: " << oldHL << " => rd: " << rd << std::endl << std::endl;

#endif
   }

   catch (anException e)
   {
      out << std::endl << e << std::endl;
   }

// stop the clock and display cpu time
   clock.Stop();
   clock.Display();

// write a closure message and finish the program
   out << std::endl << "Program <"       << prg_name
       << "> completed successfully :-)"
       << std::endl;
   return 0;
}


// some test code
void TestCode()
{
   class aBase
   {
      public:
         aBase(int val=1) : pv_baseVal( val ) {}
      protected:
      private:
         int pv_baseVal;
   };

   class aDerived : public aBase
   {
      public:
         aDerived(int bVal = 1, int val = 1) : aBase( bVal ), pv_derivedVal( val ) {}
      protected:
      private:
         int pv_derivedVal;
   };

   aBase base1(5);
   aBase base2(3);

   base1 = base2;

   aDerived d1(6, 8);
   aDerived d2(16, 18);

   d1 = d2;

}
