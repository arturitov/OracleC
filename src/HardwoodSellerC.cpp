//============================================================================
// Name        : HardwoodSellerC.cpp
// Author      : Esteban Parra
// Version     : 1
// Copyright   : It's free
// Description : Main class for the Hardwood Seller
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "WoodItem.h"
using namespace std;

struct customer_data
{
	string name;
	string address;
	string date;
	std::vector<string> wood;
};

customer_data readInputFile(string);

int main() {
	
	string inputFile = "input.txt";
	customer_data customer;
	customer = readInputFile(inputFile);

	return 0;
}

/*
 * Method to read the input file
 */
customer_data readInputFile(string inputFilePath) {

	ifstream myfile (inputFilePath);
	string line;
	string wd;
	string qty;

	customer_data customer;
	int run = 0;
	while(getline(myfile,line))
	{
	    std::stringstream   linestream(line);
	    std::string         value;
	    if (run == 0)
	    {
	    	getline(linestream,customer.name,';');
	    	getline(linestream,customer.address,';');
	    	getline(linestream,customer.date,';');
	    }
	    else{
	    	while(getline(linestream,wd,':') && getline(linestream,qty,';'))
	    	{
		    	customer.wood.push_back(wd);
		    	customer.wood.push_back(qty);
	    	}
	    }
	    run++;
	}
	return customer;
}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime() {
	double deliveryETA = 0.0;
	return deliveryETA;
}
