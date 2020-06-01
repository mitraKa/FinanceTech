//******************************************************************************
// Filename: RecTrans.h
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose:simulates basics of a bank account
// Notes: 
//******************************************************************************

#ifndef RECTRANS_H
#define RECTRANS_H

#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "Data.h"

using namespace std;
///\brief Derived class of Data that simulates basics of a bank account.
///\author FinanceTech
///\date Oct 25,2017
class RecTrans : public Data
{
  public:
    RecTrans();
   RecTrans(int id,int d, string n, int am);
   void read(istream& in_stream);
   void write(ostream& out_stream) const;

   int id_;
   int day_rec_;
   string name_rec_;
   int amount_rec_;
   
  private:
   
};
#endif
