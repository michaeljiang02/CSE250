/** CSE250 Lab5 Main file.
 *
 * Michael Jiang
 *
 * In this lab, you have to read a network description file
 * and find the shortest path between to given server
 * by displaying the list of IP address on that path
 *
 * Note: Before you begin
 *          Add your name and ID in each file (and in the project name)
 * 			Read this code carefully.. very carefully.. you need to understand it
 *       	Read the Network2025.txt file and draw the network on paper
 *       	Trace the code and variables to see how the graph works
 *       	Write your own findShortestPath method (based on breadth first search)
 *       	Initially, debug your method using IPs that are directly connected
 *
 *			In this lab, we will use C++ vector which is like a resizable array
 *			In this lab, we will use C++ unordered_map which is a hash table
 *			In this lab, we will use C++ stack
 *			In this lab, we will use C++ queue
 *			In this lab, we will use an enum
 *			In this lab, you will program a singly linked list with only 'addfirst'
 *			In this lab, you will program your own graph (network) class
 *			In this lab, you will program breadth first search on a graph
 *
 * @author Michael Jiang
 *
 */

#include <iostream>		//general IO stream
#include <fstream>		//file IO stream
#include <sstream> 		//string IO stream
#include <vector>		//C++ vector ADT
#include <string>		//C++ string
using namespace std;

#include "Network.h"


/** This function splits will help you convert each line of text into a list of IPs
 *  Solution 1.3 from https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
 *  Each line of the network file will have a comma delimited list of IP addresses.
 *
 *  It takes a line store as a C++ string,
 *  breaks it down using delimiter, and
 *  returns it into a vector ADT
 */
vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;							//Vector to store each tokens
   string token;									//Temp token string variable
   istringstream tokenStream(s);					//Turn the string s into a stream
   while (getline(tokenStream, token, delimiter))  {//Read one token at a time
      tokens.push_back(token);						//Put it at the end of the vector
   }
   return tokens;									//Return the vector of tokens
}

int main() {

	//Open the file
	ifstream myfile;
	myfile.open("Network2025.txt");

	//Read the first line, and use it to create a disconnected network
	//A split method is provided for you above
	string line;
	getline(myfile, line);
	vector<string> split_line = split(line, ',');
	Network* net = new Network(split_line);

	//Read the file line by line in order to add the connections to the network object
	//The first IP on each line is a server IP
	//Each following IP on the same line is a server connected to the 1st IP of the line
	while (!myfile.eof()){
		getline(myfile, line);
		split_line = split(line, ',');
		string connection1 = split_line[0];
		for (int i = 1; i < split_line.size(); i++) {
			net->AddConnection(connection1, split_line[i]);
		}
	}

	//Don't forget to close the file once your done
	myfile.close();

	//Answer the following Query, output the shortest path in IP order..
	cout << net->FindShortestPath("156.54.164.27","239.101.227.2") << endl;
	//Correct output: Path found: 156.54.164.27,158.163.53.63,156.140.59.121,239.101.227.2
	cout << net->FindShortestPath("190.17.60.22", "98.136.34.166") << endl;
	cout << net->FindShortestPath("190.17.60.22", "223.122.154.117") << endl;
	cout << net->FindShortestPath("190.17.60.22", "11.64.80.23") << endl;
	cout << net->FindShortestPath("187.92.39.116", "112.70.131.241") << endl;

	return 0;
}
