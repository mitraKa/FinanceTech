//*****************************************************************************                                                                               
// Filename: UserListTest.cc                                                         
// Author(s): FinanceTech                                                       
// Date created: Oct 24,2017                                                    
// Purpose:                                                                     
// Notes:                                                                       
//*****************************************************************************
#include "UserListTest.h"

void UserListTest::setUp()
{
  UserList_ptr = UserList::getInstance();
}

///test cases

///tests that if a user is found, it ruturns the correct customer pointer
void UserListTest::searchFoundTest()
{
   Customer* cust_ptr = new Customer();
  UserList_ptr->addCustomer(1 , cust_ptr);
  CPPUNIT_ASSERT(UserList_ptr->findCustomer(1) == cust_ptr);
}

///tests that if the user is not found nullptr is returned
void UserListTest::searchNotFoundTest()
{
  CPPUNIT_ASSERT(UserList_ptr->findCustomer(2) == nullptr);
}

///tests that only one userlist can be created
void UserListTest::singletonTest()
{
   CPPUNIT_ASSERT(UserList::getInstance() == UserList_ptr);
}
