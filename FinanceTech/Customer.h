//******************************************************************************
// Filename: Customer.h
// Author(s): FinanceTech
// Date created: 2017-10-24
// Purpose: Header for Customer class
// Notes: 
//******************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H

/// \author FinanceTech
/// \date October 24, 2017
/// \brief Customer is a User subclass that includes a Profile object to
/// represent the customer's basic information, and a vector of Account
/// pointers to keep track of which accounts belong to that customer.

#include<vector>

#include "User.h"
//#include "Administrator.h"
#include "Profile.h"
#include "Account.h"

class Customer : public User
{
   //friend Administrator;
   
  private:
   

  public:
   /// \brief Each customer has a single Profile object to represent their
   /// basic information
   Profile my_profile_;
   
   /// \brief Constructor
   Customer(int id, string password, Profile p);

   /// \brief Includes pointers to all Accounts owned by this customer
   vector<Account*> account_vector_;

   void editProfile(int current_id);

   /// \brief Reads properly formatted data from an input stream into the object
   /// \param[in] in_stream The input stream to be used (typically a file)
   void read(istream& in_stream);

   /// \brief Writes relevant data to an output stream in format that can be
   /// understood by LogItem::read
   /// \param[out] out_stream The output stream to be used (typically a file)
   void write(ostream& out_stream) const;
};

#endif
