#include <iostream>
#include <string>
#include "Account.h"

Account::Account()
{
   balance_ = 0;
   account_number_=0;
   id_ = 0;
}
Account::Account(int id, int b,int an)
   :balance_{b} , id_{id}
{
   if (an >= 110000000 && an < 111000000) // CreditCard
   {
      interest_rate_ = 0.05;
      min_balance_ = 10000;
   }
   else if (an >= 101000000 && an < 110000000) // saving
   {
      interest_rate_ = 0.02;
      min_balance_ = 500;
     
   }
  
   else //Chequing (100
   {
      interest_rate_ = 0;
      min_balance_ = 0;
   }
}

void Account::read(istream& in_stream)
{
   // Reads the line from the file
   string accountString;
   
   getline(in_stream, accountString);
//   cout<<accountString<<endl;
   vector<string> stringVector1;
   vector<string> parsedAccount;
   vector<string> :: iterator it;

   stringVector1.push_back(accountString);
   
   string word;

   for(it = stringVector1.begin(); it!=stringVector1.end(); ++it)
   {
      stringstream stream(*it);
      while(getline(stream,word,',') )
      {
	 parsedAccount.push_back(word);
      }
   }
   // cout << stringVector1.size()<<endl;
   id_ = stoi(parsedAccount.at(0));
   account_number_ = stoi(parsedAccount.at(1));
   balance_ = stoi(parsedAccount.at(2));

   
}
void Account::write(ostream& out_stream) const
{
   out_stream << id_ <<','
	      << account_number_ << ','
	      <<balance_ <<','
	      <<endl;
}


void Account::editInfo()
{
   int choice;
   
   cout<<"Please Select the following Options"<<endl;
   cout<<"1: Change the Balance" <<endl;
   cout<<"2: Change interest Rate"<<endl;
   cout<<"3: Add recurring Transaction"<<endl;
   cout<<"4: Delete from recurring Transaction"<<endl;
   cout<<"5: Change the Minimum Balance" <<endl;
   cout<<"6: Edit recurring Transaction" <<endl;

   while(!(cin >> choice) || choice > 6 || choice < 1)
   {
      cout << "Invalid input, please try again" << endl;
      cin.clear();
      while(cin.peek() != '\n')
      {
	 cin.ignore();
      }
      cin.ignore();
   }

   switch (choice)
   {
      case 1:
      {
     cout<<"Enter the new Balance"<<endl;
     cin>>balance_;
     break;
      }
      case 2:
      {
     cout<<"Enter the new interest Rate"<<endl;
     cin>>interest_rate_;
     break;
      }
      case 3:
      {
	 RecTrans rt(0,0,"",0);
	 cout << "Enter the user ID" <<endl;
	 cin>>rt.id_;
	 cout<<"Enter the day of the recurring transaction"<<endl;
	 cin>>rt.day_rec_;
	 cout<<"Enter the Name of the recurring transaction" <<endl;
	 cin>>rt.name_rec_;
	 cout<<"Enter the amount of the new recurring transaction"<<endl;
	 cin>>rt.amount_rec_;
	 recur_vector_.push_back(rt);
	 break;
      }
      case 4:
      {
	 RecTrans r1(0, 0, "",0);
     cout<<"Enter the name of the recurring transaction you want to delete"<<endl;
     cin>>r1.name_rec_;
     vector<RecTrans>::iterator it;
     for(it=recur_vector_.begin(); it!=recur_vector_.end(); ++it)
     {
        if (it->name_rec_ == r1.name_rec_)
        {
           //recur_vector_.erase(it);
        }
     }
     break;
      }
      
      case 5:
      {
     cout<< "Change the Minimum Balance"<<endl;
     cin>> min_balance_;
     break;
      }
      case 6:
      {
	 string input;
	 int value;
	 RecTrans r2(0,0,"",0);
	 cout<< "Edit recurring Transaction"<<endl;
	 cin>> r2.name_rec_;
	 cout<< "Edit day or amount" << endl;
	 cin>> input >>value;
	 if(input == "day")
	    r2.day_rec_ = value;
	 else if (input =="amount")
	    r2.amount_rec_ = value;
       
	 break;
      }
   }
   
}
void Account::printTransactionHistory()
{
   int ReqMonth;
   int ReqYear;
   cout<<"Please Enter the month you want the history"<<endl;
   cin>>ReqMonth;
   cout<<"Please enter the year you want the history"<<endl;
   cin>>ReqYear;
   vector<RecTrans>::iterator RecIt;
   vector<LogItem>::iterator tempIt;
 
   cout<<setw(80)<<left<<"TRANSACTION HISTORY"<<setfill('*')<<endl;
   cout<<setw(25)<<"DAY"<<setw(25)<<"DESCRIPTION"<<setw(25)<<"AMOUNT"<<endl;
   tempVect = logitem_vector_;

   for (RecIt = recur_vector_.begin();RecIt !=recur_vector_.end();RecIt++)
   {
      map<char,int> tempMap ;
      tempMap.insert(pair<char,int>('d',RecIt->day_rec_));
      tempMap.insert(pair<char,int>('m',ReqMonth));
      tempMap.insert(pair<char,int>('y',ReqYear));
      LogItem log(tempMap , RecIt->amount_rec_ , RecIt->name_rec_);
      tempVect.push_back(log);
   }
    for(int d=1 ;d <= 31 ; d++)
   {
      for (tempIt = tempVect.begin();tempIt != tempVect.end();tempIt++)
      {
	 if(tempIt->date_.at('d')== d)
	    cout<<setfill(' ')<<ReqYear<<"/"<<ReqMonth<<"/"<<tempIt->date_.at('d')
		<<setw(17)<<right<<setfill(' ')<<tempIt->description_<<setw(25)<<tempIt->amount_<<endl;
      }
   }
}

// updates the balance
void Account:: update()
{
    int total=0;
    vector<RecTrans>::iterator it;
     for(it=recur_vector_.begin();it!=recur_vector_.end();it++)
     {
        total += it->amount_rec_;
     }
     // total recurring transaction amount
     balance_= balance_ - total;
     // total amount after interest rate
     balance_ = balance_ -(balance_ * interest_rate_); 
   
}

