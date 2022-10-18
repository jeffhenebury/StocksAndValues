// StocksAndValues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//program for creating a map of stock tickers and their company names
//user can query with a stock ticker and get the company name back

#include <iostream>
#include <map>  //make a map to hold key-value pairs
#include <iterator>
#include <string>
#include <fstream>
#include <vector>   //use a vector for the two rows of the csv file
#include <sstream>  //for breaking down line into words
#include <algorithm> //for transform toupper

using namespace std;

//file pointer, to read in a file?
fstream fin; 
//create empty map container
map<string, string> ticker_and_company;
//create vector to hold the 2 strings before inserting into map
vector<string> row;

//iterate through the map, print keys and values
void printEverything() {
    map<string, string>::iterator itr;
    std::cout << "\nThe map gquiz1 is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (itr = ticker_and_company.begin(); itr != ticker_and_company.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
            << '\n';
    }
};

//user input method
void userInput() {
    while (true) {
        //ask user for the ticker symbol, give back the company name
        string inpt;
        string tickerToCheck;
        std::cout << "Enter a ticker symbol (all caps please), and get the corresponding company from the New York Stock Exchange." << endl;
        std::cout << "Or enter 'everything' to get a list of all 2,400+ companies!" << endl;
        std::cout << "Enter a ticker symbol (all caps please), and get the corresponding company." << endl;
        std::cout << "Or enter 'exit' to end the program." << endl;
        std::cout << "Ticker symbol: ";
        cin >> inpt;
        std::cout << endl;
        transform(inpt.begin(), inpt.end(), inpt.begin(), toupper); //bring it to upper case

        if (inpt == "EXIT") {
            std::cout << "Exiting program. Goodbye!" << endl;
            return;
        }
        if (inpt == "EVERYTHING") {
            std::cout << "Here's a list of all of them!" << endl;
            printEverything();
            cout << "*******************************" << endl;
        }
        if (ticker_and_company.find(inpt) != ticker_and_company.end()) {
            std::cout << "Ticker " << inpt << " is for company: " << ticker_and_company[inpt] <<"\n\n";
        };
        //if not everything and not in list, give error message
        if (inpt != "EVERYTHING" && ticker_and_company.find(inpt) == ticker_and_company.end()) {
            std::cout << inpt << " is not a valid NYSE ticker, please try again." << endl;
        };
    };
}

void mapMaker(string fileName) {
    //**opening the csv file**
    fin.open(fileName, ios::in);       //open csv file

    if (!fin) { //deal with file open errors
        std::cout << "Error, could not open file." << std::endl;
        return;
    }
    //read data from the file as a String Vector
    string line, tAndCStrings, company, temp;
    char delimiter = ',';

    while (getline(fin, line))
    {
        row.clear();
        //read an entire row and store it in variable 'line';
        getline(fin, line);

        //std::cout << "TEST: what is 'line' getting read in: " << line << endl;

        //break it into two pieces at comma, THEN srore it into the 'row' vector
        stringstream ss(line);
        while (getline(ss, tAndCStrings, delimiter)) {
            //std::cout << "\tTEST: what is 'tAndCStrings': " << tAndCStrings << endl;
            row.push_back(tAndCStrings);

        };
        //put it into the map using the vector... but only if the vector has 2 elements
        //cout << "TEST, Vector size:" << row.size() << endl;
        if (row.size() > 0) {
            ticker_and_company[row[0]] = row[1];
            //cout << "TEST, row[0]= " << row[0] << endl;
            //cout << "TEST, row[1]= " << row[1] << endl;
        };

    };
};

int main()
{
    //open the file, parse the contents, and make a map
    mapMaker("nyse-listed.csv");

    //ask user for the ticker symbol, give back the company name
    userInput();
    
     //TEST: manual insertion of data into the map ...
    /*
    ticker_and_company.insert(pair<string, string>("A", "Agilent Technologies, Inc. Common Stock"));
    ticker_and_company.insert(pair<string, string>("AA", "Alcoa Inc. Common Stock"));
    ticker_and_company.insert(pair<string, string>("AA$B", "Alcoa Inc. Depository Shares Representing 1/10th Preferred Convertilble Class B Series 1"));
    */
}
