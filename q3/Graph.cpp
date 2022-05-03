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
        for( int j = i; j < size; j++) {
            if( adjMatrix[i][j] >= 0)
                sum += adjMatrix[i][j];
        }
    }
    return sum;
}

// Default constructor
MapGraph::MapGraph() {
    adjMatrix=nullptr;
}

// Destructor
MapGraph::~MapGraph() {
    for( int i = 0; i < size; i++)
        delete [] adjMatrix[i];
    delete [] adjMatrix;
}

// Constructor that initializes the square adjacency matrix
MapGraph::MapGraph( const int thisSize) { 
    size = thisSize;
    adjMatrix= new int*[size];
    for( int i = 0; i < size; ++i) {
        adjMatrix[i] = new int[size];
        for( int j = 0; j < size; ++j) {
            adjMatrix[i][j] = -1;        // changed this!!!!!!!!!!!!!!!!!!!!!!
            if( i == j)
                adjMatrix[i][j] = 0; 
        }    
    }
}

// countFlights method counts the number of flights from that airport
int MapGraph::countFlights( int airport) const {
    int c = 0;
    for( int i = 0; i < size; i++) {
        if( adjMatrix[airport][i] > 0) {
            c++;
        }
    }
    return c;
}

// insert method inserts a flight to the map between the two specified airports
bool MapGraph::insert( int airport1, int airport2, int duration) {
    if( adjMatrix == nullptr) {
        cout << "Initialize a map first!" << endl;
        return false;
    }
    else if( airport1 >= size || airport2 >= size || airport1 < 0 || airport2 < 0) {
        cout << "Illegal argument for airport index!" << endl;
        return false;
    }
    else if( adjMatrix[airport1][airport2] > 0 || adjMatrix[airport2][airport1] > 0) {
        cout << "Flight already exists." << endl;
        return true;
    }
    else {
        adjMatrix[airport1][airport2] = duration;
        adjMatrix[airport2][airport1] = duration;
        cout << "Inserted a new flight between " << airport1 << " and " << airport2 << "." << endl;
        cout << "   The number of flights from " << airport1 << " is " << countFlights( airport1) << "." << endl;
        return true;
    }
}

// list method lists the flights from a given airport
bool MapGraph::list( int airport) {
    if( adjMatrix == nullptr) {
        cout << "Initialize a map first!" << endl;
        return false;
    }
    if( airport >= size || airport < 0) {
        cout << "Illegal argument for airport index!" << endl;
        return false;
    }

    cout << "List of flights from " << airport << ":" << endl;
    for( int i = 0; i < size; i++) {
        if( adjMatrix[airport][i] > 0) {
            cout << "   " << airport << " to " << i << " with a duration of " << adjMatrix[airport][i] << "." << endl;
        }
    }
    cout << "   The number of flights is " << countFlights(airport) << "." << endl;
    return true;
}

// shortestPath method finds the minimum duration path from one airport to another
void MapGraph::shortestPath( int airport1, int airport2) {
    /*
    int* weight = new int[size];
    int* vertexSet = new int[size];
    int* indirectFlightPath = new int[size];
    indirectFlightPath[0] = airport1;

    int indirectFlightIndex = 1;
    int directFlightDuration = adjMatrix[airport1][airport2];  // might not exist! (-1)
    int indirectFlightDuration = 0;

    for(int i = 0; i < size; i++)
        vertexSet[i] = -1;
    
    vertexSet[0] = airport1;

	// Duration of direct flights to respective airports
	for (int v = 0; v < size; v++)
	    weight[v] = adjMatrix[airport1][v];

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
    delete [] vertexSet;*/
}


// minimizeCosts finds the minimum spanning tree of the graph using Prim's Algorithm
void MapGraph::minimizeCosts() {
    cout << "Total cost of operations before minimization: " << findTotalCost() << endl;
    
    // initialize the adjacency matrix of new graph
    int** newMatrix = new int*[size];
    for( int i = 0; i < size; ++i) {
        newMatrix[i] = new int[size];
        for( int j = 0; j < size; ++j) {
            newMatrix[i][j] = -1;
            if( i == j)
                newMatrix[i][j] = 0; 
        }    
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
                    if( (adjMatrix[v][j] > 0) && (adjMatrix[v][j] < minCost) && !visitedSet.contains(j)) {
                        currentVertex = v;
                        u = j;
                        minCost = adjMatrix[v][u];
                }
            }
        }
        visitedSet.add(u);
        newCost += adjMatrix[currentVertex][u];
        newMatrix[currentVertex][u] = adjMatrix[currentVertex][u];
        newMatrix[u][currentVertex] = adjMatrix[currentVertex][u];
    }

    for( int i = 0; i < size; i++)
        delete [] adjMatrix[i];
    delete [] adjMatrix;

    adjMatrix = newMatrix;
    cout << "Total cost of operations after minimization: " << findTotalCost() << endl;
}