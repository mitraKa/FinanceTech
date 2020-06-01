//******************************************************************************
// Filename: Profile.h
// Author(s): FinanceTech
// Date created: Oct 26, 2017
// Purpose: Derived class of Data with the attributes of a customer profile
// Notes: 
//******************************************************************************

#ifndef PROFILE_H
#define PROFILE_H

#include <map>
#include <vector>
#include <string>
#include "Data.h"

/// \author FinanceTech
/// \date Oct 26, 2017
/// \brief Profile is a Data subclass that stores basic personal info for a
/// Customer object
class Profile : public Data
{
  public:

   ///Constructor
   /// \param[in] name User's name
   /// \param[in] address User's address
   /// \param[in] email User's email address
   /// \param[in] phone User's phone number
   /// \param[in] dob User's date of birth
   Profile(string name, string address, string email, string phone, map<char,int> dob);
   
   ///User's name
   string name_;

   ///User's address
   string address_;

   ///User's email address
   string email_;

   ///User's phone number
   string phone_number_;

   ///User's date of birth
   map<char,int> dob_;

   /// \brief Reads properly formatted data from an input stream into the object
   /// \param[in] in_stream The input stream to be used (typically a file)
   void read(istream& in_stream);

   /// \brief Writes relevant data to an output stream in format that can be
   /// understood by Profile::read
   /// \param[out] out_stream The output stream to be used (typically a file)
   void write(ostream& out_stream) const;
   
};

#endif
