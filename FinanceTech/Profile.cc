//******************************************************************************
// Filename: Profile.cc
// Author(s): FinanceTech
// Date created: Nov 8, 2017
// Purpose: Implementation of Profile class
// Notes: 
//******************************************************************************

#include "Profile.h"

using std::endl;

Profile::Profile(string name, string address, string email, string phone,
		 map<char,int> dob)
   :name_(name), address_(address), email_(email), phone_number_(phone), dob_(dob)
{ }

void Profile::read(istream& in_stream)
{
   string profileString;
   
   getline(in_stream, profileString);
   
   vector<string> stringVector;
   vector<string> parsedProfile;
   vector<string> :: iterator it;

   stringVector.push_back(profileString);
   
   string word;

   for(it = stringVector.begin(); it!=stringVector.end(); ++it)
   {
      stringstream stream(*it);
      while(getline(stream,word,',') )
      {
	 parsedProfile.push_back(word);
      }
   }
   
   name_ = parsedProfile.at(2);
   address_ = parsedProfile.at(3);
   email_ = parsedProfile.at(4);
   phone_number_ = parsedProfile.at(5);
   dob_['d'] = stoi(parsedProfile.at(6));
   dob_['m'] = stoi(parsedProfile.at(7));
   dob_['y'] = stoi(parsedProfile.at(8));
}

void Profile::write(ostream& out_stream) const
{
   out_stream << name_ << "," << address_ << "," << email_ << ","
	      << phone_number_ << "," << dob_.at('y') << "," << dob_.at('m') << ","
	      << dob_.at('d') << endl;
}
