#include "Interface.h"
#include "UserList.h"
#include "Account.h"
#include "wrapperFunctions.h"

#include <fstream>
#include <iostream>

using namespace std;

void constructScreens(Customer* customerPtr);
string readProfileInfo(Customer* customerPtr);
void cleanCin(istream&);
void logout();

Interface MainMenu, ChooseAcc, ViewProfile, CreditAccOptions,
   DebitAccOptions, AdminOptions, AdminCustomerOptions;

bool loggedIn = true;

//Global members for wrapper functions
// login screen
int id;
Customer* customerPtr = nullptr;

int main()
{
   //**********************************************
   //Read Customers
   //**********************************************
   
   ifstream inFile;
   ifstream inFileAccounts;
   ifstream inFileRecTrans;
   
   inFile.open("customer.csv");
   inFileAccounts.open("accountIn.csv");
   inFileRecTrans.open("rectrans.csv");
   
   vector<Customer> customerVector;
   vector<Customer>::iterator it;
   map<char,int> dob = {{'d',01},{'m',01},{'y',01}};
   Profile p("name", "address","email","phone", dob);
   Customer customer(0,"pass",p);

   // Constructing Userlist
   UserList* userList = userList->getInstance();
   
   while(!inFile.eof())
   {
      Customer* customer_ptr = new Customer(0,"pass",p);
      customer_ptr->read(inFile);
      userList->addCustomer(customer_ptr->ID_number_,customer_ptr);
   }

   while(!inFileAccounts.eof())
   {
      Account* account_ptr = new Account(0,0,0);
      account_ptr->read(inFileAccounts);
      Customer* customer_ptr;
      customer_ptr = userList->findCustomer(account_ptr->id_);
      if(customer_ptr != nullptr)
      {
	 customer_ptr->account_vector_.push_back(account_ptr);
      }
   }
   
   while(!inFileRecTrans.eof())
   {
      RecTrans rec(0,0,"",0);
      Customer* customer_ptr ;
      Account* account_ptr= new Account(0,0,0);

      rec.read(inFileRecTrans);
      customer_ptr = userList->findCustomer(rec.id_);
      
      if(customer_ptr != nullptr)
      {
	 for(auto it = customer_ptr->account_vector_.begin();
	     it!=customer_ptr->account_vector_.end(); ++it)
	 {    
        
	    account_ptr=(*it);
	    account_ptr->recur_vector_.push_back(rec);
        
	 }
      }
   }
   
  login:
   
   customerPtr = nullptr;
   loggedIn = true;
   bool admin = false;
   
   
   // login screen
   string password;


   cout << "Login Screen"
      "\nUser ID: ";
    while(!(cin >> id) || userList->findCustomer(id) == nullptr)
    {
       if(id == 1000)
	  break;
       
      cout << "Incorrect username, try again." << endl;
      cleanCin(cin);
   }
 
// checks if the user is an admin
   if(id == 1000)
   {
      cout << "Enter Admin password: "; 
      while(!(cin >> password) || password != "password")
      {
	 cout << "Incorrect Admin password, try again." << endl;
	 cleanCin(cin);   
      }
      admin = true;

      cout << "Admin access granted" << endl;
   
      goto skip;
   }

   cout << "Password: ";
   while(!(cin >> password) || userList->findCustomer(id)->password_ != password)
   {
      cout << "Incorrect password, try again" <<endl;
      cleanCin(cin);
   }
   
   customerPtr = userList->findCustomer(id);
   
  skip:

   constructScreens(customerPtr);
   
   Interface current_screen = admin ? AdminOptions : MainMenu;
   
   while(loggedIn)
   {
      current_screen.draw();
      
      current_screen = (*current_screen.option());
   }
   
   goto login;

   return 0;
}

/// constructScreens
///\brief Constructs all Interfaces
void constructScreens(Customer* customerPtr)
{


   // Constructing MainMenu

   MainMenu.text_ =
      "Main Menu choices are:"
      "\n"
      "\n 1: Switch to Account screen"
      "\n 2: View profile"
      "\n a: Logout";

   MainMenu.interface_vector_.push_back(&ChooseAcc);
   MainMenu.interface_vector_.push_back(&ViewProfile);

   MainMenu.function_vector_.push_back(logout);

   //Constructing ViewProfile
   ViewProfile.text_ =
      "Profile:"
      "\n"
      + readProfileInfo(customerPtr) +
      "\n 1: Back";
   
   ViewProfile.interface_vector_.push_back(&MainMenu);
      
   
   // Constructing ChooseAcc

   ChooseAcc.text_ =
      "Account choices are:"
      "\n"
      "\n 1: Debit"
      "\n 2: Credit"
      "\n 3: Back";
      
   
   ChooseAcc.interface_vector_.push_back(&DebitAccOptions);
   ChooseAcc.interface_vector_.push_back(&CreditAccOptions);
   ChooseAcc.interface_vector_.push_back(&MainMenu);

   
   // Constructing DebitAccOptions

   DebitAccOptions.text_ =
      "Debit Account choices are:"
      "\n"
      "\n 1: Back"
      "\n a: Print transaction history"
      "\n b: Withdraw"
      "\n c: Deposit"
      "\n d: Transfer between accounts"; /// not implemented yet
   
   DebitAccOptions.interface_vector_.push_back(&ChooseAcc);
   
   DebitAccOptions.function_vector_.push_back(printTransactionHistoryWrapperDebit);
   DebitAccOptions.function_vector_.push_back(withdrawWrapper);
   DebitAccOptions.function_vector_.push_back(depositWrapper);
   DebitAccOptions.function_vector_.push_back(transferWrapperDebit);
   

   
   // Constructing CreditAccOptions

   CreditAccOptions.text_ =
      "Credit Account choices are:"
      "\n"
      "\n 1: Back"
      "\n a: Print transaction history";
   
   CreditAccOptions.interface_vector_.push_back(&ChooseAcc);
   
   CreditAccOptions.function_vector_.push_back(printTransactionHistoryWrapperCredit);

   // Constructing AdminOptions

   AdminOptions.text_ =
      "Admin options are:"
      "\n"
      "\n 1: Switch to Main Menu"
      "\n 2: Modify Customer Details"
      "\n a: Create a customer";
   
   AdminOptions.function_vector_.push_back(createCustomerWrapper);
   AdminOptions.interface_vector_.push_back(&MainMenu);
   AdminOptions.interface_vector_.push_back(&AdminCustomerOptions);
   

   // Constructing AdminCustomerOptions

   AdminCustomerOptions.text_ =
      "Admin Customer Options are:"
      "\n"
      "\n a: Open Account"
      "\n b: Close Account"
      "\n c: Edit Account"
      "\n d: Edit Profile"
      "\n 1: Back";
   
   AdminCustomerOptions.function_vector_.push_back(openAccountWrapper);
   AdminCustomerOptions.function_vector_.push_back(closeAccountWrapper);
   AdminCustomerOptions.function_vector_.push_back(editAccountWrapper);
   AdminCustomerOptions.function_vector_.push_back(editProfileWrapper);

   AdminCustomerOptions.interface_vector_.push_back(&AdminOptions);
}

/// readProfileInfo
///\brief reads user profile info and returns it as a string to be displayed
string readProfileInfo(Customer* customerPtr)
{
   string info = "No Customer selected";
   if(customerPtr)
   {
      info = "Name: " + customerPtr->my_profile_.name_ + "\n"
	 + "Address: " + customerPtr->my_profile_.address_ + "\n"
	 + "Phone Number: " + customerPtr->my_profile_.phone_number_ + "\n"
	 + "Email: " + customerPtr->my_profile_.email_ + "\n";
   }
   return info;
}


/// logout
///\brief logs the user out and breaks from the main loop
void logout()
{
   loggedIn = false;
}

