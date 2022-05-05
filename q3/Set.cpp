#include "Set.h"
#include <iostream>

/*
* Title: Set Data Structure
* Author: Mustafa Cem Gülümser
* ID: 22003430
* Section: 2
* Assignment: 4
* Description: Implementation for the Set class.
*/

set::set() {
    size = 0;
    elements = NULL;
}

set::set( int s) {
    size = s;
    elements = new int[s];
}

set::~set() {
    delete[] elements;
}

bool checkIfExists( int*& arr, const int size, const int element) {
    for( int i = 0; i < size; i++)
        if( arr[i] == element)
            return true;
    return false;
}

void set::add( int element) {
    if( !checkIfExists( elements, size, element)) {
        size++;
        int* newElements = new int[ size];
        for( int i = 0; i < size - 1; i++) {
            newElements[i] = elements[i];
        }
        newElements[size-1] = element;
        delete [] elements;
        elements = newElements;
    }
}

bool set::isEmpty() {
    return size == 0;
}

void set::display() {
    std::cout << "Displaying set: ";
    for( int i = 0; i<size; i++)
        std::cout << elements[i] << " ";
    std::cout << std::endl;
}

bool set::contains( int e) {
    for( int i = 0; i < size; i++)
        if( elements[i] == e)
            return true;
    return false;
}