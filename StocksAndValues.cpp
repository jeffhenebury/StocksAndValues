// StocksAndValues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//prgram for creating a list of stock tickers and their company names

#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>  //for breaking down line into words
#include <algorithm> //for transform toupper

using namespace std;

//file pointer, to read in a file?
fstream fin; 

//create empty map container
map<string, string> ticker_and_company;

//create vector to hold the 2 strings before inserting into map
vector<string> row;


//user input
void userInput() {
    while (true) {
        //ask user for the ticker symbol, give back the company name
        string inpt;
        string tickerToCheck;
        std::cout << "Enter a ticker symbol (all caps please), and get the corresponding company." << endl;
        std::cout << "Or enter 'exit' to end the program." << endl;
        std::cout << "Ticker symol: ";
        cin >> inpt;
        std::cout << endl;
        transform(inpt.begin(), inpt.end(), inpt.begin(), toupper);

        if (inpt == "EXIT") {
            std::cout << "Exiting program." << endl;
            return;
        }
        if (ticker_and_company.find(inpt) != ticker_and_company.end()) {
            std::cout << "Ticker " << inpt << " is for company: " << ticker_and_company[inpt] << endl;
        };
        if (ticker_and_company.find(inpt) == ticker_and_company.end()) {
            std::cout << inpt << " is not a valid NYSE ticker, please try again." << endl;
        };
    };
}

int main()
{
    std::cout << "Hello World!\n";
    
    //**Dealing with the csv file...trying it as as .txt**
    fin.open("nyse-listed.csv", ios::in);       //open csv file

    if (!fin) { //deal with file open errors
        std::cout << "Error, could not open file." << std::endl;
        return -1;
    }
    //read data from the file as a String Vector
    string line, tAndCStrings, company, temp;
    char delimiter = ',';

    while (getline(fin, line))
    {
        row.clear();
        //read an entire row and store it in variable 'line';
        getline(fin, line);

        //stringstream s(line);   //for breaking into words
        std::cout << "TEST: what is 'line' getting read in: " << line << endl;

        //break it into two pieces at comma, THEN srore it into the 'row' vector
        stringstream ss(line);
        while (getline(ss, tAndCStrings, delimiter)){
            std::cout << "\tTEST: what is 'tAndCStrings': " << tAndCStrings << endl;
            row.push_back(tAndCStrings);
            
        };
        //put it into the map using the vector??
        // but only if the vector has 2 elements
        cout << "Vector size:" << row.size() << endl;
        if (row.size() > 0) {
            ticker_and_company[row[0]] = row[1];
            cout << "TEST, row[0]= " << row[0] << endl;
            cout << "TEST, row[1]= " << row[1] << endl;

        };
       
    };
        
        //read every column data of a row
        //store it in a string variable, 'word'
        /*
        while (getline(s, word, ',')) {
            row.push_back(word);
            cout << "TEST: what is 'word' getting added to vector: " << word << endl;
        }
        */
    
     //trying some manual insertion for now...
    /*
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
    */

    //iterate through the map, print keys and values
    map<string, string>::iterator itr;
    std::cout << "\nThe map gquiz1 is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (itr = ticker_and_company.begin(); itr != ticker_and_company.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
            << '\n';
    }
    
    cout << endl;
    
    //testing the map:


    //ask user for the ticker symbol, give back the company name
    userInput();

   

}
