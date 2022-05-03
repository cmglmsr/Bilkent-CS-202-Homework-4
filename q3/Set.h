
/*
* Title: Set Data Structure
* Author: Mustafa Cem Gülümser
* ID: 22003430
* Section: 2
* Assignment: 4
* Description: Header for the Set class.
*/

class set {
    public:
    int size;
    int* elements;
    set();
    set( int s);
    ~set();
    void add( int element);
    bool isEmpty();
    void display();
    bool contains( int e);
};