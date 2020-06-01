//******************************************************************************
// Filename: Data.h
// Author(s): FinanceTech
// Date created: Oct 25, 2017
// Purpose: Pure abstract base class that allows reading and writing
// Notes: 
//******************************************************************************

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/// \author FinanceTech
/// \date Oct 25, 2017
/// \brief Pure abstract base class that allows reading and writing

class Data
{
  public:

   ///Reads object from istream to set values
   /// \param[in] in_stream istream that is being read
   virtual void read(istream& in_stream) = 0;

   ///writes an objects data to the ostream
   /// \param[in] out_stream ostream that is being written to
   virtual void write(ostream& out_stream) const = 0;
};

#endif

