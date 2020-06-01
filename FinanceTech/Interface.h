//******************************************************************************
// Filename: Interface.h
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose: Produces a screen based on user input
// Notes: 
//******************************************************************************

#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <string>

using namespace std;

///\brief This is the Interface class
///This class draws the interface ("screen") based on menu options, and handles
///user input
///\author FinanceTech
///\date Oct 25,2017
class Interface {

  private:

   ///Simulates time passing for all accounts (only accessible by administrator)
   void update();

  public:
   
   ///Constructor of interface
   Interface(){};

   ///Destructor of Interface
   ~Interface(){};
   
   ///Prints out the interface, and performs "screen refreshes"
   void draw();

   ///Handles choosing interface and functions based on user input
   Interface* option();

   ///Vector of interface objects ("screens" to be drawn)
   vector<Interface*> interface_vector_;

   ///Allows users to call functions from other classes
   vector<void(*)()> function_vector_;
   
   ///Text to be output when draw() is called
   string text_;
   
};

#endif
