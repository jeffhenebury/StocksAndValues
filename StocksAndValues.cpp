// StocksAndValues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//prgram for creating a list of stock tickers and their company names

#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <fstream>

using namespace std;

fstream fin; //file pointer, to read in a file?



int main()
{
    std::cout << "Hello World!\n";

    //create empty map container
    map<string, string> ticker_and_company;

    /* 
    fin.open("nyse-listed.csv", ios::in);       //open csv file

    if (!fin) { //deal with file open errors
        std::cout << "Error, could not open file." << std::endl;
        return -1;
    }
    */

    //trying some manual insertion for now...
    ticker_and_company.insert(pair<string, string>("A", "Agilent Technologies, Inc. Common Stock"));
    ticker_and_company.insert(pair<string, string>("AA", "Alcoa Inc. Common Stock"));
    ticker_and_company.insert(pair<string, string>("AA$B", "Alcoa Inc. Depository Shares Representing 1/10th Preferred Convertilble Class B Series 1"));
    ticker_and_company.insert(pair<string, string>("AAC", "AAC Holdings, Inc. Common Stock"));
    ticker_and_company.insert(pair<string, string>("AAN", "Aaron's, Inc. Common Stock"));
    ticker_and_company.insert(pair<string, string>("AAP", "Advance Auto Parts Inc Advance Auto Parts Inc W/I"));
    ticker_and_company.insert(pair<string, string>("AAT", "American Assets Trust, Inc. Common Stock"));
    ticker_and_company.insert(pair<string, string>("AAV", "Advantage Oil & Gas Ltd  Ordinary Shares"));
    ticker_and_company.insert(pair<string, string>("AB", "Allianceberstein Holding L.P.  Units"));
    ticker_and_company.insert(pair<string, string>("ABB", "ABB Ltd Common Stock"));
    ticker_and_company.insert(pair<string, string>("ABBV", "AbbVie Inc. Common Stock"));
    ticker_and_company.insert(pair<string, string>("ABC", "AmerisourceBergen Corporation (Holding Co) Common Stock"));
  
    //iterate through the map, print keys and values

    map<string, string>::iterator itr;
    cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = ticker_and_company.begin(); itr != ticker_and_company.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
            << '\n';
    }
    cout << endl;

    //ask user for the ticker symbol, give back the company name


   

}
