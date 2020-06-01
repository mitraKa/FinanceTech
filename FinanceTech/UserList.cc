///UserList.cc
//*****************************************************************************                                                                               
// Filename: UserList.cc                                                          
// Author(s): FinanceTech                                                       
// Date created: Nov 4,2017                                                    
// Purpose:                                                                     
// Notes:                                                                       
//*****************************************************************************
#include "UserList.h"

using namespace std;

///UserList constructor 
UserList::UserList()
   : current_ID_(0)
{
}

///addCustomer function
bool UserList::addCustomer(int ID, Customer* Customer_ptr)
{
//  map<int , Customer*>::iterator it;
//  for(it = customer_vector_.begin(); it != customer_vector_.end(); it++)
//    {
//      if(it->first == ID)
//	{
//	  return false;
//	}
//    }
   // cout<<"TEST0"<<endl;
   if(customer_vector_.count(ID))
   {
      return false;
   }
   // cout<<"TEST1"<<endl;
   customer_vector_[ID] = Customer_ptr;
   return true;
}

//findCustomer function
Customer* UserList::findCustomer(int ID)
{
   if(customer_vector_.count(ID))
   {
      return customer_vector_.find(ID)->second;
   }
   else
      return nullptr;
      
//  map<int , Customer*>::iterator it;
//  for(it = customer_vector_.begin(); it != customer_vector_.end(); it++)
//    {
//      if(it->first == ID)
//	{
//	  return it->second;
//	}
//    }
//  //if element not found 
//  return nullptr;
}

void UserList::deleteCustomer(int ID)
{
   map<int,Customer*>::iterator it = customer_vector_.find(ID);
   customer_vector_.erase(it);
}


int UserList::updateID()
{
   return ++current_ID_;
}


UserList* UserList::getInstance()
{
  if(User_List_ptr == nullptr)
    {
      User_List_ptr = new UserList();
    }
  return User_List_ptr;
}

UserList* UserList::User_List_ptr = nullptr;



