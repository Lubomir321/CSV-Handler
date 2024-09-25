#include "CSVReader.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
const unsigned int MAX_ELEMENT_LEN = 1024;
CSVReader::CSVReader(const char* f)
{
	input(f);
}
std::fstream& CSVReader::input()
{
	return file;
}
void CSVReader::input(const char* f)
{
	if (file.is_open())
		file.close();
	file.open(f, std::ios::in);
}
CSVRow CSVReader::readHeader()
{
	char** row = NULL;
	unsigned int cnt = readLine(row);
	CSVRow result(row, cnt);
	for (unsigned int i = 0; i < cnt; ++i)
		delete[] row[i];
	delete[] row;
	return result;
}
unsigned int CSVReader::readLine(char**& row)
{
	char* element;
	unsigned int cnt = 0;
	char ch;
	do
	{
		element = getElement();
		append(row, element, cnt);
		++cnt;
		ch = file.get();
	} while (file.good() && ch != '\n');
	return cnt;
}
char* CSVReader::getElement()
{
	char buffer[MAX_ELEMENT_LEN];
	file.ignore(MAX_ELEMENT_LEN, '\"');
	if (file.eof()) return NULL;
	file.getline(buffer, MAX_ELEMENT_LEN, '"');
	char* result = new char[strlen(buffer) + 1];
	return strcpy(result, buffer);
}
void CSVReader::append(char**& row, char* elem, unsigned cnt) const
{
	char** res = new char* [cnt + 1];
	for (unsigned int i = 0; i < cnt; i++)
		res[i] = row[i];
	res[cnt] = elem;
	delete row;
	row = res;
}