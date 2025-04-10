/** CSE250 Lab6 Main file.
 *
 * YOUR NAME HERE
 *
 * In this lab, you have to read a network description file
 * and find the shortest path between to given server
 * by displaying the list of IP address on that path
 *
 * Note: Before you begin
 *          Add your name and ID in each file (and in the project name)
 * 			Read this code carefully.. very carefully.. you need to understand it
 *       	Read the Network3.txt file and draw the network on paper
 *       	Trace the code and variables to see how the graph works
 *          Complete the code for the BinaryHeap AND debug it separately first
 *       	Write your own findShortestPath method (based on Dijkstra's algo)
 *       	Initially, debug your method using IPs that are directly connected
 *
 *
 * @author Your name
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
	myfile.open("Network3.txt");

	//Read the first line, and use it to create a disconnected network
	//A plit method is provided for you above
	string line;
	getline(myfile, line);
	vector<string> split_line = split(line, ',');
	Network* net = new Network(split_line);

	//Read the file line by line in order to add the connections to the network object
	//The first IP on each line is a server IP
	//Each following IP on the same line is a latency followed by a server connected to the 1st IP of the line
	//Thus we get [0] to [2] with latency [1]
	//Thus we get [0] to [4] with latency [3]
	//etc
	while (!myfile.eof()){
		getline(myfile, line);
		split_line = split(line, ',');
		string connection1 = split_line[0];
		for (int i = 1; i < split_line.size(); i+=2) {
			int latency = stoi(split_line[i]);
			string connection2 = split_line[i + 1];
			net->AddConnection(connection1, latency, connection2);
		}
	}

	//Don't forget to close the file once your done
	myfile.close();

	//Answer the following Query, output the shortest path in IP order..
	cout << net->FindShortestPath("168.213.182.122","7.9.30.185") << endl;
	//Correct output: Path found: 168.213.182.122,83.27.248.234,7.9.30.185 Latency = 24.300000
	cout << net->FindShortestPath("189.126.251.225", "150.220.177.120") << endl;
	cout << net->FindShortestPath("189.126.251.225", "106.140.246.211") << endl;
	cout << net->FindShortestPath("189.126.251.225", "102.130.212.124") << endl;
	cout << net->FindShortestPath("189.126.251.225", "168.135.60.189") << endl;

	return 0;
}
