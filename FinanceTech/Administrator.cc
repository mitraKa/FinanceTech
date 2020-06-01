//******************************************************************************
// Filename: Administrator
// Author(s): FinanceTech
// Date created: 2017-11-14
// Purpose: Header for Customer class
// Notes: 
//******************************************************************************
#include "Administrator.h"
#include "Customer.h"
#include "UserList.h"
#include "AccountFactory.h"

Administrator::Administrator(string password)
   : User(1000, password)
{}

void Administrator::editProfile(int target_id)
{
   UserList *ulist_ptr = UserList::getInstance();
   Customer *cust_ptr = ulist_ptr->findCustomer(target_id);
   int answer;
   
  cout << "Would you like to edit the customer's:" << endl
	<< "1. Name" << endl
	<< "2. Address" << endl
	<< "3. Email address" << endl
	<< "4. Phone number" << endl
       << "5. Date of birth" << endl << endl;

  cin >> answer;
  switch (answer)
  {
     case 1: //Name
     {
	string newName;
	cout<<"Enter new name: ";
	cin>>newName;
	cust_ptr->my_profile_.name_ = newName;
	break;
     }

     case 2: //Address
     {
	string newAddress;
	cout<<"Enter new address: ";
	cin>>newAddress;
	cust_ptr->my_profile_.address_=newAddress;
	break;
     }

     case 3: //Email
     {
	string newEmail;
	cout<<"Enter new email: ";
	cin>>newEmail;
	cust_ptr->my_profile_.email_=newEmail;
	break;
     }

     case 4: //Phone
     {
	string newPhone;
	cout<<"Enter new phone number: ";
	cin>>newPhone;
	cust_ptr->my_profile_.phone_number_=newPhone;
	break;
     }

     case 5: //DOB
     {
	int d,m,y;
	cout<<"Enter day: ";
	cin>>d;
	cout<<"Enter month: ";
	cin>>m;
	cout<<"Enter year: ";
	cin>>y;
	cust_ptr->my_profile_.dob_.at('d')=d;
	cust_ptr->my_profile_.dob_.at('m')=m;
	cust_ptr->my_profile_.dob_.at('y')=y;
     }
  }
}

void Administrator::editAccount(Account* target_account)
{
   target_account->editInfo();
   //UserListName;
}

//Returns true if customer successfully deleted
bool Administrator::deleteCustomer(int target_id)
{
   UserList *ulist_ptr = UserList::getInstance();
   Customer *cust_ptr = ulist_ptr->findCustomer(target_id);

   if (cust_ptr == nullptr)
   {
      return false;
      //throw(CustomerNotFoundError);
      //need warnings: "This customer does not exist"
   }
   //what if customer not found?
   
   if(cust_ptr->account_vector_.empty())
   {
      ulist_ptr->deleteCustomer(target_id); //map.erase(target_id)
      return true;
   }

   return false;
   
   //throw(InvalidRemovalError);
   //need warnings: "This user has accounts,they must be closed first"
}

bool Administrator::createCustomer()
{ 
   string name;
   cout << "Customer Name: ";
   cin >> name;

   string password;
   cout << "Customer Password: ";
   cin >> password;
   
   string address;
   cout << "Customer Address: ";
   cin >> address;
   
   string email;
   cout << "Customer email: ";
   cin >> email;

   string phNumber;
   cout << "Customer phone number: XXX-XXXX";
   cin >> phNumber;

   int day, month, year;
   cout << "Enter customer DOB: "<<endl
	<<"Day: ";
   cin >> day;
   cout <<  "Month: ";
   cin >> month;
   cout <<  "Year: ";
   cin >> year;
  
   map<char,int> dob;
   dob['d'] = day;
   dob['m'] = month;
   dob['y'] = year;

   Profile new_profile(name, address, email, phNumber, dob);

   UserList *ulist_ptr = UserList::getInstance();
   
   int new_id = ulist_ptr->updateID();
   
   Customer *new_customer = new Customer(new_id, password, new_profile);
   cout<<"NEW ID= "<<new_id<<endl;
   if(ulist_ptr->addCustomer(new_id, new_customer))
   {
      return true;
   }

   return false;


   //throw(DuplicateIDError);
   //need warnings: Customer ID already exists
}

//return account pointer so that can be edited once open
void Administrator::openAccount(int target_id)
{
   UserList *ulist_ptr = UserList::getInstance();
   Customer *cust_ptr = ulist_ptr->findCustomer(target_id);
   
   cout<<"What kind of account would you like to open?"<<endl
       << "1. Chequing"<<endl
       << "2. Savings"<<endl
       << "3. Credit Card"<<endl
       << "4. Line of Credit"<<endl;
   
   int input;
   cin >> input;

   AccountFactory acctFact;
   //cout<< typeid(cust_ptr).name()<<endl;
   acctFact.makeAccount(input, cust_ptr);
}

void Administrator::closeAccount(int target_id)
{
   UserList *ulist_ptr = UserList::getInstance();
   Customer *cust_ptr = ulist_ptr->findCustomer(target_id);
   int accountNumber;

   cout<<"Which account do you want to close?"<<endl;
   
   for(auto it=cust_ptr->account_vector_.begin(); it!=cust_ptr->account_vector_.end(); ++it)
   {
      cout<<(*it)->account_number_<<endl;
   }

   cout << "Enter account number of account you want to close: ";
   cin >> accountNumber;

   for(auto it=cust_ptr->account_vector_.begin(); it!=cust_ptr->account_vector_.end(); ++it)
   {
      if((*it)->account_number_ == accountNumber)
      {
	it = cust_ptr->account_vector_.erase(it);
      }
   }

}

