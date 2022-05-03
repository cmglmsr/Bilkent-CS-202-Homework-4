#include "Graph.h"
#include "Set.h"
#include <iostream>
using namespace std;

/*
* Title: Graph Data Structure for the Map
* Author: Mustafa Cem Gülümser
* ID: 22003430
* Section: 2
* Assignment: 4
* Description: Source code for the implementation of MapGraph
*/

// Helper methods

int MapGraph::findTotalCost() {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i; j < size; j++) {
            if( adjList[i].contains(j)) {
                sum += adjList[i].getDuration( j);
            }
        }
    }
    return sum;
}

// Default constructor
MapGraph::MapGraph() {
    adjList = nullptr;
}

// Destructor
MapGraph::~MapGraph() {
    delete [] adjList;
}

// Constructor that initializes the adjacency list
MapGraph::MapGraph( const int thisSize) { 
    size = thisSize;
    adjList = new List[size];
    for( int i = 0; i < size; ++i) {
        adjList[i] = *(new List());
    }
}

// countFlights method counts the number of flights from that airport
int MapGraph::countFlights( int airport) const {
    return adjList[airport].getLength();
}

// insert method inserts a flight to the map between the two specified airports
bool MapGraph::insert( int airport1, int airport2, int duration) {
    if( adjList == nullptr) {
        cout << "Initialize a map first!" << endl;
        return false;
    }
    else if( airport1 >= size || airport2 >= size || airport1 < 0 || airport2 < 0) {
        cout << "Illegal argument for airport index!" << endl;
        return false;
    }
    else if( adjList[airport1].contains(airport2) || adjList[airport2].contains(airport1)) {
        cout << "Flight already exists." << endl;
        return true;
    }
    else {
        adjList[airport1].insert( 1, airport2, duration);
        adjList[airport2].insert( 1, airport1, duration);
        cout << "Inserted a new flight between " << airport1 << " and " << airport2 << "." << endl;
        cout << "   The number of flights from " << airport1 << " is " << countFlights( airport1) << "." << endl;
        return true;
    }
}

// list method lists the flights from a given airport
bool MapGraph::list( int airport) {
    if( adjList == nullptr) {
        cout << "Initialize a map first!" << endl;
        return false;
    }
    if( airport >= size || airport < 0) {
        cout << "Illegal argument for airport index!" << endl;
        return false;
    }

    cout << "List of flights from " << airport << ":" << endl;
    for( int i = 0; i < size; i++) {
        if( adjList[airport].contains(i)) {
            cout << "   " << airport << " to " << i << " with a duration of " << adjList[airport].getDuration(i) << "." << endl;
        }
    }
    cout << "   The number of flights is " << countFlights(airport) << "." << endl;
    return true;
}

// shortestPath method finds the minimum duration path from one airport to another
void MapGraph::shortestPath( int airport1, int airport2) {
    int* weight = new int[size];
    int* indirectFlightPath = new int[size];
    set vertexSet;
    
    indirectFlightPath[0] = airport1;
    int indirectFlightIndex = 1;
    int directFlightDuration = adjList[airport1].getDuration(airport2);  // might not exist! (-1)
    int indirectFlightDuration = 0;

    vertexSet.add(airport1);

	// Duration of direct flights to respective airports
	for (int v = 0; v < size; v++)
	    weight[v] = adjList[airport1].getDuration(v);  // -1 if not exists

	// Steps 2 through n
	while( true) {

        // Find the smallest weight[v] such that v is not in vertexSet
        int minWeight = 99999;
        int minWeightVertex = -1;
        for( int i = 0; i < size; i++) {
            if( i == airport1 || weight[i] == -1 || i == airport2)
                continue;
            if( !checkIfExists( vertexSet, size, i) && weight[i] < minWeight) {
                minWeightVertex = i;
                minWeight = weight[i];
            }
        }

        indirectFlightPath[ indirectFlightIndex] = minWeightVertex;
        indirectFlightDuration += minWeight;

        // Add v to vertexSet
        addIfNotExists( vertexSet, size, minWeightVertex);

        // For all vertices u adjacent to v but not in vertexSet
	    for (int u = 0; u < size; u++) {
           if( adjMatrix[minWeightVertex][u] > 0 && !checkIfExists(vertexSet, size, u)) {
                if (weight[u] > weight[minWeightVertex] + adjMatrix[minWeightVertex][u])
	                weight[u] = weight[minWeightVertex]+ adjMatrix[minWeightVertex][u];
                    indirectFlightPath[indirectFlightIndex] = u;
                    indirectFlightIndex++;
           }
        }
	}

    delete [] indirectFlightPath;
    delete [] weight;
    delete [] vertexSet;
}


// minimizeCosts finds the minimum spanning tree of the graph using Prim's Algorithm
void MapGraph::minimizeCosts() {
    cout << "Total cost of operations before minimization: " << findTotalCost() << endl;
    
    // initialize the adjacency list of new graph
    List* newList = new List[size];
    for( int i = 0; i < size; ++i) {
        newList[i] = *(new List());
    }

    int currentVertex = 0;
    int u = 0;
    int newCost = 0;
    set visitedSet;
    visitedSet.add( currentVertex); // mark the 0th airport as visited

    while( visitedSet.size < this->size) {

        int minCost = 99999;
        // find least cost edge
        for( int i = 0; i < visitedSet.size; i++) {
            int v = visitedSet.elements[i];
            for( int j = 0; j < size; j++) {
                    if( (adjList[v].contains(j)) && (adjList[v].getDuration(j) < minCost) && !visitedSet.contains(j)) {
                        currentVertex = v;
                        u = j;
                        minCost = adjList[v].getDuration(j);
                }
            }
        }
        visitedSet.add(u);
        newCost += adjList[currentVertex].getDuration(u);
        newList[currentVertex].insert(1, u, adjList[currentVertex].getDuration(u));
        newList[u].insert(1, currentVertex, adjList[currentVertex].getDuration(u));
    }
    delete [] adjList;

    adjList = newList;
    cout << "Total cost of operations after minimization: " << findTotalCost() << endl;
}