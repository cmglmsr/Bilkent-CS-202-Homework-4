#include <fstream>
#include <iostream>
#include "Graph.h"
using namespace std;

/*
* Title: Driver file
* Author: Mustafa Cem Gülümser
* ID: 22003430
* Section: 2
* Assignment: 4
* Description: Driver file that will be executed.
*/

int main( int arg, char* args[]) {
    int numOfAirports = 0;
    int numOfOperations = 0;
    string fileName = args[1];
    ifstream file;
    file.open( (fileName).c_str());

    if(!file.is_open()) {  // if the given file name does not exist
        cout<< "The file does not exist." << endl;
        return 0;
    }

    file >> numOfAirports;
    file >> numOfOperations;

    MapGraph map(numOfAirports);

    for( int operation = 1; operation <= numOfOperations; operation++) {
        string opCode = "";
        file >> opCode;
        int arg1 = 0; int arg2 = 0; int arg3 = 0;

        if( opCode == "I") {
            file >> arg1; file >> arg2; file >> arg3;
            if ( !map.insert( arg1, arg2, arg3))
                return 1;
        }
        else if( opCode == "L") {
            file >> arg1;
            if ( !map.list( arg1))
                return 1;
        }
        else if( opCode == "S") {

        }
        else if( opCode == "M") {
            map.minimizeCosts();
        }
        else {
            cout << "Illegal opCode!" << endl;
        }
    }
}