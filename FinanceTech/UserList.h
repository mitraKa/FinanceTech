//******************************************************************************
// Filename: UserList.h
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose: class to hold map of customers, key to access customer is their ID
// Notes: 
//******************************************************************************
#ifndef USERLIST_H
#define USERLIST_H
#include <iostream>
#include <map>
#include "Customer.h"

using namespace std;

///\brief UserList class is a singleton class that stores a map of customer
///pointers and IDs to be accessed by other classes
///\author FinanceTech
///\date Oct 24,2017
class UserList
{
 public:
  //customer ID and pointer to customer are created by customer class right?
  bool addCustomer(int ID, Customer* Customer_ptr);

  ///this function is used to find customer details
  ///will return valid customer pointer if customer ID is found
  ///will return null if customer ID is not found in map
  Customer* findCustomer(int ID);

  ///Deletes the customer with id_==ID
  ///\param[in] ID ID number of Customer to delete
  void deleteCustomer(int ID);
  
  ///Increments current_id_ and returns it
  int updateID();
  
  ///static UserList function which is used to get an instance of the class
  ///needed for Singleton pattern 
  static UserList* getInstance();
 private:
  ///static User List pointer
  static UserList* User_List_ptr;

  ///Keeps track of the id for the next User object
  int current_ID_;

  ///Sets to ID of current customer being "looked at"
  int curr_target_user_;

  ///Constructor of userlist is private
  ///singleton pattern will ensure this can only be created once
  ///cannot create customer via Constructor 
  UserList();

  ///Stores an ID (key) with the customer pointer (value),
  ///used to access customers
  map<int, Customer*> customer_vector_;

};

#endif
