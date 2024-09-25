#pragma once
#include <fstream>
#include <iostream>
#ifndef __CSVROW_HEADER_INCLUDED_

class CSVRow
{
public:
	CSVRow(char** field = NULL, unsigned int n = 0);
	CSVRow(const CSVRow& row);
	~CSVRow();
	CSVRow& operator=(const CSVRow& right);
	void addField(const char* name);
	void addValue(const char* v);
	const char* field(unsigned int n) const;
	const char* operator[](unsigned int n) const;
	const char* operator[](const char* f) const;
	void clearValues();
protected:
	char** copyRow(char** const data, unsigned int cnt);
	void clearRow(char** row);
	void deleteRow(char** row);
	char** addToRow(char** row, const char* value);
private:
	char** header;
	char** values;
	unsigned int fieldsCnt;
};

#endif // !__CSVROW_HEADER_INCLUDED_
