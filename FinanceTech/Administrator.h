//******************************************************************************
// Filename: Administrator.h
// Author(s): FinanceTech
// Date created: 2017-10-24
// Purpose: Header for Administrator class
// Notes: 
//******************************************************************************

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

/// \author FinanceTech
/// \date October 24, 2017
/// \brief Administrator is a User subclass that includes the functionalities
/// required for administrative modification of accounts and other users.

#include "User.h"
#include "Account.h"

class Administrator : public User
{
  public:
   /// \brief Constructor
   Administrator(string password);

   /// \brief Gives options for modifying a Customer's profile
   /// \param[in] target_id ID of Customer whose profile to edit
   void editProfile(int target_id);

   /// \brief Gives options for modifying an Account
   /// \param[in/out] target_account Account to edit
   void editAccount(Account* target_account);

   /// \brief Deletes a Customer and removes all related data
   /// \param[in] target_id ID of Customer whose profile to edit
   /// \param[out] returns true if customer successfully deleted, else
   /// throws exception
   bool deleteCustomer(int target_id);

   /// \brief Creates a new Customer (and Profile)
   bool createCustomer();

   /// \brief Gives options for opening a new account
   /// \param[in] target_id ID of customer whose profile to edit
   void openAccount(int target_id);

   /// \brief Closes an account
   /// \param[in/out] target_account Account to delete
   void closeAccount(int target_id);

};

#endif
