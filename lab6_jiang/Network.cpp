/*
 * Network.cpp
 *
 * YOUR NAME HERE
 *
 *      Author: Rivest, 2025
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

#include "Network.h"
#include "BinaryHeap.h"



/** Constructs a network given a list of IP addresses
 *
 * @param IPList	Array of strings of each server's IP
 *
  */
Network::Network(const vector<string>& IPList) {
	//Debug statement
	cout << "Building a network of " << IPList.size() << " servers" << endl;
	//Fix the network size
	m_NetworkSize = IPList.size();
	//Saves the server IPs
	m_Vertex2IP = IPList;
	//Allocate space for adjacency lists
	//By default there are no connections, so all nullptr
	m_EdgeLists = new EdgeListNode*[m_NetworkSize];
	for (int i=0; i<IPList.size(); i++) {
		m_EdgeLists[i] = nullptr;
	}
	//Fill a hash table for fast search using IP
	for (int i=0; i<IPList.size(); i++) {
		m_IP2Vertex.insert({IPList[i], i});
	}
}

/** Frees up all allocated memory. */
Network::~Network() {
	delete[] m_EdgeLists;
}

/** Number of servers in the network */
int Network::GetNetworkSize(){
	return m_NetworkSize;
}

/** This adds a connection between two computers based on their IPs
 *  (in the adjacency edge linked list).
 *
 *  Note that it will add the edge to the adjacency list of both servers.
 *
 * @param server1	IP of the server at one end
 * @param Latency	Latency (ping time) between the servers
 * @param server2	IP of the server at the other end
 */
void Network::AddConnection(const string& server1, const double latency, const string& server2){
	//Extract servers index from IPs
	int v1 =  m_IP2Vertex[server1];
	int v2 =  m_IP2Vertex[server2];
	//Debug statement
	cout << "Adding edge (" << server1 << "," << server2 << ")" << endl;
	//Add the edge v1 to s2
	EdgeListNode* edge1 = new EdgeListNode();
	edge1->v1 = v1;
	edge1->w = latency;//Lab6
	edge1->v2 = v2;
	edge1->next = m_EdgeLists[v1];
	m_EdgeLists[v1] = edge1;
	//Add the edge v2 to v1
	//Note that since this is in the adjacency list of v2, we flip the vs
	EdgeListNode* edge2 = new EdgeListNode();
	edge2->v1 = v2;//see!
	edge2->w = latency;//Lab6
	edge2->v2 = v1;//so the index adjacent to v2 is v1
	edge2->next = m_EdgeLists[v2];
	m_EdgeLists[v2] = edge2;
}

/** This method must search the graph, starting on the homeServer
 * vertex, for the shortest path (in numbers of connections) to
 * the targetServer (or destination).
 *
 *   When such a path is found, it should be in the following format:
 *   homeServer,IP(1),IP(2),IP(k-1),targetServer
 *   eg: net.findShortestPath("168.213.182.122","7.9.30.185")
 *   Correct output: Path found: 168.213.182.122,83.27.248.234,7.9.30.185 Latency = 24.300000
 *
 * @param homeServer	IP of the starting point
 * @param targetServer	IP of the destination server
 * @return a C++ string as described above
 */

string Network::FindShortestPath(const string& homeServer, const string& targetServer) {
	//You need your own priority queue for Dijkstra Algorithm
	//PS: Make sure you initialize all your distances to INF
	BinaryHeap myheap(m_NetworkSize);//Lab6
	//You can use a stack... if you need to ;-)
	stack<string> mystack;

	//I suggest you first convert the IP strings back into indexes
	int home = m_IP2Vertex[homeServer];
	int destination = m_IP2Vertex[targetServer];
	//Debug statement
	cout << "Finding fastest path from  " << home << " to " << destination << endl;

	double* distances = new double[m_NetworkSize]; //Lab6
	int* parents = new int[m_NetworkSize];
	for (int i=0; i<m_NetworkSize; i++) {
		distances[i] = std::numeric_limits<double>::max();//Lab6
		parents[i] = -2;
	}

	//Enqueue the starting point
	distances[home] = 0;
	parents[home] = -1;
	myheap.decreaseKey(home,  0);

	//While there are nodes to process
	while (!myheap.isEmpty()) {
		int v = myheap.extractMin();
		EdgeListNode* neighbor = m_EdgeLists[v];
		while (neighbor != nullptr) {
			int v_prime = neighbor->v2;
			if (distances[v_prime] > distances[v] + neighbor->w) {
				parents[v_prime] = v;
				distances[v_prime] = neighbor->w + distances[v];
				myheap.decreaseKey(v_prime, distances[v_prime]);
			}
			neighbor = neighbor->next;
		}
	}
	int walker = destination;
	double totalLatency = distances[walker];
	while (parents[walker] >= 0) {
		mystack.push(m_Vertex2IP[walker]);
		walker = parents[walker];
	}
	if (walker != home) {
		return "Path from " + homeServer + " to " + targetServer + " not found!";
	}

	mystack.push(m_Vertex2IP[walker]);
	string return_string = "Shortest path: ";
	while (!mystack.empty()) {
		return_string += mystack.top() + ", ";
		mystack.pop();
	}
	return_string += "Latency: " + to_string(totalLatency);
	delete[] distances;
	delete[] parents;
	return return_string;
}


