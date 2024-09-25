#pragma once

#include "CSVRow.h"
#ifndef __CSVREADER__HEADER_INCLUDED_

class CSVReader 
{
public:
	CSVReader(const char* f);
	std::fstream& input();
	void input(const char* f);
	CSVRow readHeader();
	void readRow(CSVRow& r);
protected:
	unsigned int readLine(char**& row);
	char* getElement();
	void append(char**& row, char* elem, unsigned int cnt) const;
protected:
	std::fstream file;
private:
	//The copy of objects if forbidden
	CSVReader(const CSVReader&);
	void operator=(const CSVReader&);
};
#endif // !__CSVREADER__HEADER_INCLUDED_
