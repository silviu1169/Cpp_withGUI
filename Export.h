#pragma once
#include "Product.h"
#include "ProductRepository.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;
//Exports the list of products in a .csv file
void exportToCSV(string fileName,const vector <Product>& all);


//exports the list of products in a .html file
void exportToHTLM(string fileName, const vector <Product>& all);
