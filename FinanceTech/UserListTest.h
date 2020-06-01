//*****************************************************************************                                                                               
// Filename: UserListTest.h                                                          
// Author(s): FinanceTech                                                       
// Date created: Oct 24,2017                                                    
// Purpose:                                                                     
// Notes:                                                                       
//*****************************************************************************

#ifndef USERLIST_TEST_H
#define USERLIST_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Customer.h"
#include "UserList.h"

class UserListTest: public CppUnit::TestFixture
{
  ///macros to create Test Suite
  CPPUNIT_TEST_SUITE(UserListTest);
  CPPUNIT_TEST(searchFoundTest);
  CPPUNIT_TEST(searchNotFoundTest);
  CPPUNIT_TEST(singletonTest);
  CPPUNIT_TEST_SUITE_END();

 public:
  void setUp();
  void searchFoundTest();
  void searchNotFoundTest();
  void singletonTest();
 private:
  UserList* UserList_ptr;
};

#endif
