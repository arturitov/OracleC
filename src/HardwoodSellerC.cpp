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
#include <stdlib.h>
#include "WoodItem.h"
using namespace std;

struct customer_data
{
	string name;
	string address;
	string date;
	std::vector<string> wood;
	std::vector<double> quty;
};

customer_data readInputFile(string);

int main() {

	string inputFile = "input.txt";
	customer_data customer;
	customer = readInputFile(inputFile);
	std::vector<double> delivery_time;
	double dt;
	double cost = 0.00;

	WoodItem Cherry("Cherry", 2.5, 5.95);
	WoodItem Curly_Maple("Curly_Maple", 2.5, 5.95);
	WoodItem Genuine_Mahogany ("Genuine_Mahogany", 3, 9.60);
	WoodItem Wenge("Wenge", 5, 22.35);
	WoodItem White_Oak("White_Oak", 2.3, 6.70);
	WoodItem Sawdust("Sawdust", 1, 1.5);

	for (int i = 0; i < customer.wood.size(); i++)
	{
		// Add check for over max amount
		if (customer.wood[i] == "Cherry")
		{
			// dt = Cherry.baseDeliveryTime * delivery_time(customer.wood[i+1]);
			// delivery_time.push_back(dt);
			cost += Cherry.price * customer.quty[i];
		}
		else if (customer.wood[i] == "Curly Maple")
		{
			// dt = Curly_Maple.baseDeliveryTime * delivery_time(customer.wood[i+1]);
			// delivery_time.push_back(dt);
			cost += Curly_Maple.price * customer.quty[i];
		}
		else if (customer.wood[i] == "Genuine Mahogany")
		{
			// dt = Genuine_Mahogany.baseDeliveryTime * delivery_time(customer.wood[i+1]);
			// delivery_time.push_back(dt);
			cost += Genuine_Mahogany.price * customer.quty[i];
		}
		else if (customer.wood[i] == "Wenge")
		{
			// dt = Wenge.baseDeliveryTime * delivery_time(customer.wood[i+1]);
			// delivery_time.push_back(dt);
			cost += Wenge.price * customer.quty[i];
		}
		else if (customer.wood[i] == "White Oak")
		{
			// dt = White_Oak.baseDeliveryTime * delivery_time(customer.wood[i+1]);
			// delivery_time.push_back(dt);
			cost += White_Oak.price * customer.quty[i];
		}
		else if (customer.wood[i] == "Sawdust")
		{
			// t = Sawdust.baseDeliveryTime * delivery_time(customer.wood[i+1]);
			// delivery_time.push_back(dt);
			cost += Sawdust.price * customer.quty[i];
		}
	}

	cout << cost << endl;

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
		    	customer.quty.push_back(stod(qty));
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
