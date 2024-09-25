﻿#include <iostream>
#include "CSVWriter.h"
#include "CSVReader.h"
#include "CSVRow.h"

int main()
{
    CSVRow row;
    row.addField("Student name");
    row.addField("Faculty Number");
    row.addField("E-mail");
    row.addField("Age");
    row.addValue("Dimitur");
    row.addValue("12345");
    row.addValue("pitko@mitko.com");
    row.addValue("20");
 
    CSVWriter writer("test.csv");
    writer.addField("Student name");
    writer.addField("Faculty Number");
    writer.addField("E-mail");
    writer.addField("Age");
    writer.writeHeader();
    writer.writeRow(row);
    row.clearValues();
    row.addValue("Georgi");
    row.addValue("43123");
    row.addValue("joro@tosho.bg");
    row.addValue("21");
    writer.writeRow(row);
    //Copy to other csv
    CSVReader reader("test.csv");
    CSVWriter writer1("copy.csv");
    row = reader.readHeader();
    const char* element;
    for (unsigned int i = 0; element = row.field(i); i++)
        writer1.addField(element);
    writer1.writeHeader();
    //for (reader.readRow(row); row[0u]; reader.readRow(row))
    //{
    //   // writer1.writeRow(row);
    //    //row.clearValues();
    //}
    //return 0;
    
}

