# StocksAndValues

I found a data set in a .CSV file format that contained all 3,300 companies listed on the New York Stock Exchange and their corresponding stock ticker (for example, ‘CMI’ is the ticker symbol for ‘Cummins Inc. Common Stock’.) 
The program:
1.	Opens the .csv file, parses the data, and puts the first column (the ticker) into the map ‘key’ field and the second column (the company name) into the corresponding map ‘value’ field.
2.	When the map is completed, the program user can enter in any symbol to see the corresponding company. They can also type ‘everything’ to see the complete list or ‘exit’ to leave.
I tried two different methods for inserting the data. When testing with manual insertions, I used the insert(). However, because I was parsing the lines of data and breaking the long string on the comma to make it into two values, I ended up using an indexing method of insertion instead: 
ticker_and_company[row[0]] = row[1];
I used a few algorithms over the course of the program. From the map data structure, in addition to the insert() method, I used the  find() function, which returns an iterator to key, or an iterator to the end of the map if key is not found. I created a vector to hold each row of the file at a time, split the row on the comma, and insert each substring into the key and value pairs using stringsream and pushback(). I also used transform() from the general algorithm section of the STL library to turn user input to uppercase. 
A different algorithm that might be used is erase(). Say a company was unlisted from the New York Stock Exchange and a user wanted to remove the company for this list. The use of erase() could be used to remove an element out of the map.
