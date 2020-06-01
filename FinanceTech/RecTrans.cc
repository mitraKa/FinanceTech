//******************************************************************************
// Filename: RecTrans.cc
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose:simulates basics of a bank account
// Notes: 
//******************************************************************************

#include "RecTrans.h"

RecTrans::RecTrans()
{
}
RecTrans::RecTrans(int id=0,int d=0, string n="", int am=0)
   :id_{id},day_rec_{d},name_rec_{n},amount_rec_{am}
{
   //recur_vector_.push_back(this);
}

void RecTrans::read(istream& in_stream)
{
   string accountString;
   
   getline(in_stream, accountString);
   
   vector<string> stringVector;
   vector<string> parsedAccount;
   vector<string>::iterator it;

   stringVector.push_back(accountString);
   
   string word;

   for(it = stringVector.begin(); it!=stringVector.end(); ++it)
   {
      stringstream stream(*it);
      while(getline(stream,word,',') )
      {
	 parsedAccount.push_back(word);
      }
   }

   //string dayRec;
   //string am;
   id_=stoi(parsedAccount.at(0));
   name_rec_ = parsedAccount.at(1);
   day_rec_ = stoi(parsedAccount.at(2));
   amount_rec_ = stoi(parsedAccount.at(3));

   //dayRec = stoi(dayRec,nullptr,0);
   //amountRec = stoi(amountRec,nullptr,0);
   
   
}
void RecTrans::write(ostream& out_stream) const
{
   out_stream << id_ <<','
	      << day_rec_<<','
	      << name_rec_<<','
	      << amount_rec_
	      <<endl;
}
