#pragma once
#include "CSVRow.h"

#ifndef __CSVWRITER_HEADER_INCLUDED

class CSVWriter
{
public:
	CSVWriter(const char* f);
	~CSVWriter();
	std::fstream& output();
	void output(const char* f);
	void addField(const char* n);
	void writeHeader();
	void writeRow(const CSVRow& r);
protected:
	char** header;
	unsigned int fieldsCnt;
	std::fstream file;
private:
	//The copy of objects is forbidden
	CSVWriter(const CSVWriter&);
	void operator=(const CSVWriter&);
};

#endif // !__CSVWRITER_HEADER_INCLUDED
