#include "Graph.h"
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
        for( int j = 0; j < size; ++j)
            adjMatrix[i][j] = 0;
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

void MapGraph::insert( int airport1, int airport2, int duration) {
    if( adjMatrix == nullptr) {
        cout << "Initialize a map first!" << endl;
        return;
    }
    else if( airport1 >= size || airport2 >= size || airport1 < 0 || airport2 < 0) {
        cout << "Illegal argument for airport index!" << endl;
        return;
    }
    else if( adjMatrix[airport1][airport2] > 0)
        cout << "Flight already exists." << endl;
    else {
        adjMatrix[airport1][airport2] = duration;
        cout << "Inserted a new flight between " << airport1 << " and " << airport2 << "." << endl;
        cout << "   The number of flights from " << airport1 << " is " << countFlights( airport1) << "." << endl;
    }
}
