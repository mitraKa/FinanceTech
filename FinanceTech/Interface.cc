//******************************************************************************
// Filename: Interface.cc
// Author(s): FinanceTech
// Date created: Nov 7,2017
// Purpose: Produces a screen based on user input
// Notes: 
//******************************************************************************

#include "Interface.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void Interface::draw()
{
   cout << text_ << endl;
}

Interface* Interface::option()
{   
   char option;
   cin >> option;
   
   cin.clear();	 
   while (cin.peek() != '\n') {
      // eats until the end of line
      cin.ignore();
   }
   cin.ignore();

   switch(option)
   {
      case 'a':
      {
	 (*function_vector_[0])();
	 return this;
      }
      case 'b':
      {
	 (*function_vector_[1])();
	 return this;
      }
      case 'c':
      {
	 (*function_vector_[2])();
	 return this;
      }
      case 'd':
      {
	 (*function_vector_[3])();
	 return this;
      }
      case 'e':
      {
	 (*function_vector_[4])();
	 return this;
      }
      case '1':
	 return interface_vector_[0];
      case '2':
	 return interface_vector_[1];
      case '3':
	 return interface_vector_[2];
      default:
      {
	 cout << "Invalid option" << endl;
	 return this;
      }
   }
}


