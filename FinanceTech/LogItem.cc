//******************************************************************************
// Filename: LogItem.h
// Author(s): FinanceTech
// Date created: 2017-10-25
// Purpose: Header for LogItem class
// Notes: 
//******************************************************************************

#include "LogItem.h"

LogItem::LogItem(map<char,int> date, int amount, string description)
   :date_(date), amount_(amount), description_(description)
{}

void LogItem::read(istream& in_stream)
{
   string logItemString;

   getline(in_stream, logItemString);

   vector<string> stringVector;
   vector<string> parsedLogItem;
   vector<string> :: iterator it;

   stringVector.push_back(logItemString);

   string word;

   for(it = stringVector.begin(); it!=stringVector.end(); ++it)
   {
      stringstream stream(*it);
      while(getline(stream,word,',') )
      {
	 parsedLogItem.push_back(word);
      }
   }
   
   accountNumber = stoi(parsedLogItem.at(0));
   date_['y'] = stoi(parsedLogItem.at(1));
   date_['m'] = stoi(parsedLogItem.at(2));
   date_['d'] = stoi(parsedLogItem.at(3));
   amount_ = stoi(parsedLogItem.at(4));
   description_ = parsedLogItem.at(5);
}

void LogItem::write(ostream& out_stream) const
{
   // Missing acc #
   out_stream << accountNumber <<',' << date_.at('y') <<','<< date_.at('m')
	      <<','<< date_.at('d')<< amount_ << ',' << description_<< endl;

}
