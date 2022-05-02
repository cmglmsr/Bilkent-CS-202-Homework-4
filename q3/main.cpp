#include <fstream>
#include <iostream>
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

}