
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
        int** adjMatrix;
        MapGraph();
        void insert( int airport1, int airport2) const;
        void list();
        void shortestPath();
        void minimizeCosts();
};