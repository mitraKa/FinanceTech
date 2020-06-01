//******************************************************************************
// Filename: Customer.cc
// Author(s): FinanceTech
// Date created: 2017-11-14
// Purpose: Header for Customer class
// Notes: 
//******************************************************************************

#include "Customer.h"
#include "UserList.h"

Customer::Customer(int id, string password, Profile p)
   : User(id,password), my_profile_(p)
{}

void Customer::editProfile(int current_id)
{
   UserList *ulist_ptr = UserList::getInstance();
   Customer *cust_ptr = ulist_ptr->findCustomer(current_id);
   
   cout<<"Select what you would like to edit: " <<endl
       <<"1. Address"<<endl
       <<"2. Email"<<endl
       <<"3. Phone Number"<<endl<<endl;
   int answer;
   cin>>answer;

   switch(answer)
   {
      case 1: //Address
      {
	 string newAddress;
	cout<<"Enter new address: ";
	cin>>newAddress;
	cust_ptr->my_profile_.address_=newAddress;
	break;
      }

      case 2: //Email
      {
	 string newEmail;
	 cout<<"Enter new email: ";
	 cin>>newEmail;
	 cust_ptr->my_profile_.email_=newEmail;
	 break;
      }

      case 3: //Phone
      {
	 string newPhone;
	 cout<<"Enter new phone: ";
	 cin>>newPhone;
	 cust_ptr->my_profile_.phone_number_=newPhone;
	 break;
      }
   }
}

void Customer::read(istream& in_stream)
{
   //User::read(in_stream);
   //my_profile_.read(in_stream);

   string customerString;
   
   getline(in_stream, customerString);
   //cout<<customerString<<endl;
   vector<string> stringVector;
   vector<string> parsedCustomer;
   vector<string>::iterator it;

   stringVector.push_back(customerString);
   //cout<<customerString<<endl;
/**
   for(auto it = stringVector.begin(); it!=stringVector.end(); ++it)
   {
      cout << (*it)<<endl;//->stringVector<<endl;
      }
**/
   string word;

   for(it = stringVector.begin(); it!=stringVector.end(); ++it)
   {
      stringstream stream(*it);
      while(getline(stream,word,',') )
      {
	 parsedCustomer.push_back(word);
      }
   }

   //for(auto it = parsedCustomer.begin(); it!=parsedCustomer.end(); ++it)
   //{
   //   cout << (*it)<<endl;//->stringVector<<endl;
   //}

   ID_number_ = stoi(parsedCustomer.at(0));
   password_ = parsedCustomer.at(1);
   my_profile_.name_ = parsedCustomer.at(2);
   my_profile_.address_ = parsedCustomer.at(3);
   my_profile_.email_ = parsedCustomer.at(4);
   my_profile_.phone_number_ = parsedCustomer.at(5);
   my_profile_.dob_['y'] = stoi(parsedCustomer.at(6));
   my_profile_.dob_['m'] = stoi(parsedCustomer.at(7));
   my_profile_.dob_['d'] = stoi(parsedCustomer.at(8));
   //cout<<ID_number_<<password_<<my_profile_.name_<<endl;
}

void Customer::write(ostream& out_stream) const
{
   out_stream
      << ID_number_ << ','
      << password_ << ','
      << my_profile_.name_ << ','
      << my_profile_.address_ << ','
      << my_profile_.email_ << ','
      << my_profile_.phone_number_ << ','
      << my_profile_.dob_.at('y') << ','
      << my_profile_.dob_.at('m') << ','
      << my_profile_.dob_.at('d')
      <<endl;
}

