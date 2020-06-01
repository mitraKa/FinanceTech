//******************************************************************************
// File name: User.cc
// Author(s): FinanceTech
// Date created: Nov 14, 2017
// Purpose: Derived abstract base class of Data
// Notes: 
//******************************************************************************

#include "User.h"

User::User(int temp_id, string temp_password)
   : ID_number_(temp_id),password_(temp_password)
{}

void User::read(istream& in_stream)
{
   string customerString;
   
   getline(in_stream, customerString);
   cout<<customerString;
   vector<string> stringVector;
   vector<string> parsedCustomer;
   vector<string>::iterator it;

   stringVector.push_back(customerString);
   
   string word;

   for(it = stringVector.begin(); it!=stringVector.end(); ++it)
   {
      stringstream stream(*it);
      while(getline(stream,word,','))
      {
	 parsedCustomer.push_back(word);
      }
   }
   
   //string tempID = parsedCustomer.at(0);
   //int tempIDlen = tempID.length();
   
   ID_number_ = stoi(parsedCustomer.at(0));
   password_ = parsedCustomer.at(1);
}

void User::write(ostream& out_stream) const
{
   out_stream << ID_number_ << "," << password_ << endl;
}
