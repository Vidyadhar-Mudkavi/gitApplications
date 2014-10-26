/**
  *File: calNames.cpp

  *Description:

   this file implements the classes declared in file calNames

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:
  */

// system includes
// standard templates
// local includes
#include "calNames.h"

// const declarations
const char* calNames_id = 
   "@(#) calNames. implementation. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";
// function prototypes
// forward declarations

// begin class implementation
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
  *Purpose: provides default constructor
  */
calNames::calNames()
{
}

/**
  *Purpose: provides copy constructor
  */
calNames::calNames(const calNames& cal_name)
{
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

calNames& calNames::operator=(const calNames& cal_name)
{
   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

calNames::~calNames()
{
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          


   ////////////////////////////////////////////
   // 
   // Gregorian Week Day names
   //

   ///////////////////////////////////////////////
   //
   // gregorian (and julian) name implementations
   //
calGregorianWeekDay::calGregorianWeekDay()
{

   std::cout << "***** building Week Day object *****" << std::endl << std::endl;
   pv_weekDay = new std::string[7];

   pv_weekDay[0] = "Sunday";
   pv_weekDay[1] = "Monday";
   pv_weekDay[2] = "Tuesday";
   pv_weekDay[3] = "Wednesday";
   pv_weekDay[4] = "Thursday";
   pv_weekDay[5] = "Friday";
   pv_weekDay[6] = "Saturday";
}


calGregorianMonth::calGregorianMonth()
{
   pv_month = new std::string[12];

   pv_month[ 0] = "January";
   pv_month[ 1] = "February";
   pv_month[ 2] = "March";
   pv_month[ 3] = "April";
   pv_month[ 4] = "May";
   pv_month[ 5] = "June";
   pv_month[ 6] = "July";
   pv_month[ 7] = "August";
   pv_month[ 8] = "September";
   pv_month[ 9] = "October";
   pv_month[10] = "November";
   pv_month[11] = "December";
}

   ///////////////////////////////////////////////
   //
   // hindu name implementations
   //
calHinduWeekDay::calHinduWeekDay()
{

   std::cout << "***** building HINDU Week Day object *****" << std::endl << std::endl;
   pv_weekDay = new std::string[7];

   pv_weekDay[0] = "ravivAra";
   pv_weekDay[1] = "sOmavAra";
   pv_weekDay[2] = "mangaLavAra";
   pv_weekDay[3] = "budhavAra";
   pv_weekDay[4] = "guruvAra";
   pv_weekDay[5] = "SukravAra";
   pv_weekDay[6] = "SanivAra";
}


calSamvatsara::calSamvatsara()
{

   std::cout << "***** building HINDU samvatsara object *****" << std::endl << std::endl;
   pv_samvat = new std::string[7];

   pv_samvat[ 0] = "vijaya";        pv_samvat[30] = "";
   pv_samvat[ 1] = "jaya";          pv_samvat[31] = "";
   pv_samvat[ 2] = "manmatha";      pv_samvat[32] = "";
   pv_samvat[ 3] = "durmukha";      pv_samvat[33] = "";
   pv_samvat[ 4] = "hEmalamba";     pv_samvat[34] = "";
   pv_samvat[ 5] = "viLamba";       pv_samvat[35] = "";
   pv_samvat[ 6] = "vikArin";       pv_samvat[36] = "";
   pv_samvat[ 7] = "Sarvari";       pv_samvat[37] = "";
   pv_samvat[ 8] = "plava";         pv_samvat[38] = "";
   pv_samvat[ 9] = "Subhakrit";     pv_samvat[39] = "";
   pv_samvat[10] = "Sobhana";       pv_samvat[40] = "";
   pv_samvat[11] = "krodhin";       pv_samvat[41] = "";
   pv_samvat[12] = "viSvAvasu";     pv_samvat[42] = "";
   pv_samvat[13] = "parAbhava";     pv_samvat[43] = "";
   pv_samvat[14] = "plavanga";      pv_samvat[44] = "";
   pv_samvat[15] = "kIlaka";        pv_samvat[45] = "";
   pv_samvat[16] = "saumya";        pv_samvat[46] = "";
   pv_samvat[17] = "sAdhAraNa";     pv_samvat[47] = "";
   pv_samvat[18] = "virodhakrit";   pv_samvat[48] = "";
   pv_samvat[19] = "paridhAvin";    pv_samvat[49] = "";
   pv_samvat[20] = "pramAdin";      pv_samvat[50] = "";
   pv_samvat[21] = "Ananda";        pv_samvat[51] = "";
   pv_samvat[22] = "rAkShasa";      pv_samvat[52] = "";
   pv_samvat[23] = "Anala";         pv_samvat[53] = "";
   pv_samvat[24] = "pingaLa";       pv_samvat[54] = "";
   pv_samvat[25] = "kAlayukta";     pv_samvat[55] = "";
   pv_samvat[26] = "siddhArtin";    pv_samvat[56] = "";
   pv_samvat[27] = "raudra";        pv_samvat[57] = "";
   pv_samvat[28] = "durmati";       pv_samvat[58] = "";
   pv_samvat[29] = "dundubhi";      pv_samvat[59] = "";
}

// follow this pattern for function comments

/**
  *Purpose: 
  *Returns: 
  *Params:  
  *Throws:  
  */

// here is an example
#if 0 // here is an example
/**
  *Purpose: 
      this function add the matrix passed as arg.

  *Returns: 
      matrixNode* ... pointer to a matrix node

  *Params:  
      ptr_mn -- a const pointer to matrix node
      gmn    -- general matrix node

  *Throws:  
      aMatrix::exception object
  */
matrixNode* aMatrix::Add(const matrixNode* ptr_mn, ...)
#endif // end of example


