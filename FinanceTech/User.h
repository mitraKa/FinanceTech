//******************************************************************************
// File name: User.h
// Author(s): FinanceTech
// Date created: Oct 26, 2017
// Purpose: Derived abstract base class of Data
// Notes: 
//******************************************************************************

#ifndef USER_H
#define USER_H

#include "Data.h"

/// \author FinanceTech
/// \date Oct 26, 2017
/// \brief User is a Data subclass that stores basic identification and login
/// information
class User : public Data
{

   //protected:
   
   ///User's ID
   //int ID_number_;

   ///User's password
   //string password_;
  public:

   int ID_number_;
   ///Constructor
   /// \param[in] id The user's ID number
   /// \param[in] password The user's password
   // Note: may need id to be const, since ID_number_ is const
   User(int temp_id = 0, string temp_password = "password");

   ///prompts the user to change User data members
   /// \param[in] current_id The ID of the Customer whose Profile to edit
   //virtual void editProfile(int current_id)=0;

   void read(istream& in_stream);

   void write(ostream& out_stream) const;
   
   ///User's password
   string password_;
   
  

};

#endif
