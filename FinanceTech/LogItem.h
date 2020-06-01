//******************************************************************************
// Filename: LogItem.h
// Author(s): FinanceTech
// Date created: 2017-10-25
// Purpose: Header for LogItem class
// Notes: 
//******************************************************************************

#ifndef LOGITEM_H
#define LOGITEM_H

#include <map>
#include <vector>

#include "Data.h"

/// \author FinanceTech
/// \date October 24, 2017
/// \brief LogItem is a Data subclass that stores basic data for an account
/// transaction.
class LogItem : public Data
{
  private:
   /* /// \brief Date of transaction. Map is keyed by char, but the only keys used
   /// are y, m, and d (year, month, and day)
   map<char, int> date_;

   /// \brief Amount of transaction
   int amount_;

   /// \brief Type of transaction
   string description_;
   */
  public:
   /// \brief Constructor
   LogItem(map<char,int> date, int amount, string description);

   /// \brief Reads properly formatted data from an input stream into the object
   /// \param[in] in_stream The input stream to be used (typically a file)
   void read(istream& in_stream);

   /// \brief Writes relevant data to an output stream in format that can be
   /// understood by LogItem::read
   /// \param[out] out_stream The output stream to be used (typically a file)
   void write(ostream& out_stream) const;

   /// \brief Account number of account number
   int accountNumber;

    /// \brief Date of transaction. Map is keyed by char, but the only keys used
   /// are y, m, and d (year, month, and day)
   map<char, int> date_;

   /// \brief Amount of transaction
   int amount_;

   /// \brief Type of transaction
   string description_;
};

#endif
