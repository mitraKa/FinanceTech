//*****************************************************************************
// Filename: Tester.cc                                                          
// Author(s): FinanceTech                                                       
// Date created: Nov 4,2017                                                    
// Purpose:                                                                     
// Notes:                                                                       
//*****************************************************************************

//## Please pipe the file "Test.in" into this executable so InterfaceTest ##//
//## can parse the input. ex. "Tester < Test.in" ##//

#include <cppunit/TextTestRunner.h>
//#include "UserListTest.h"
#include "CreditCardTest.h"
//#include "ChequingTest.h"

using namespace CppUnit;
///simple main function to run test suites 
int main()
{
   TextTestRunner runner;
   //runner.addTest(UserListTest::suite());
   //runner.addTest(UserTest::suite());
   runner.addTest(CreditCardTest::suite());
   //runner.addTest(ChequingTest::suite());
   
   runner.run();
   return 0;
}
