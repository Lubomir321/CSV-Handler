#include "CSVWriter.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
CSVWriter::CSVWriter(const char* f) :
	fieldsCnt(0), header(NULL)
{
	output(f);
}
CSVWriter::~CSVWriter()
{
	for (unsigned int i = 0; i < fieldsCnt; ++i)
		delete[] header[i];
	delete[] header;
}
std::fstream& CSVWriter::output()
{
	return file;
}
void CSVWriter::output(const char* f)
{
	if (file.is_open())
		file.close();
	file.open(f, std::ios::out | std::ios::trunc);
}
void CSVWriter::addField(const char* n)
{
	if (!n) return;
	char** temp = new char* [fieldsCnt + 1];
	for (unsigned int i = 0; i < fieldsCnt; ++i)
		temp[i] = header[i];
	delete[] header;
	temp[fieldsCnt] = new char[strlen(n) + 1];
	strcpy(temp[fieldsCnt], n);
	header = temp;
	++fieldsCnt;
}
void CSVWriter::writeHeader()
{
	if (!fieldsCnt) return;
	file << '\"' << header[0] << '\"';
	for (unsigned int i = 1; i < fieldsCnt; ++i)
		file << ", \"" << header[i] << '\"';
	file << std::endl;
}
void CSVWriter::writeRow(const CSVRow& r)
{
	if (!fieldsCnt) return;
	file << '\"' << (r[0u] ? r[0u] : "NULL") << '\"';
	for (unsigned int i = 1; i < fieldsCnt; ++i)
		file << ", \"" << (r[i] ? r[i] : "NULL") << '\"';
	file << std::endl;
}