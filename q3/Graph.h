#include "LinkedList.h"

/*
* Title: Graph Data Structure for the Map
* Author: Mustafa Cem Gülümser
* ID: 22003430
* Section: 2
* Assignment: 4
* Description: Header for the MapGraph class. This class contains the methods for the program.
*/


class MapGraph {
    public:
        int size;          // number of airports
        List* adjList;
        MapGraph();
        ~MapGraph();
        MapGraph( const int size);
        int countFlights( int airport) const;
        bool insert( int airport1, int airport2, int duration);
        bool list( int airport);
        void shortestPath( int airport1, int airport2);
        void minimizeCosts();
        int findTotalCost();
};