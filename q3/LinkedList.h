
/*
* Title: Linked List header file
* Author: Mustafa Cem Gülümser
* ID: 22003430
* Section: 2
* Assignment: 4
* Description: Header file for Linked List
*/

typedef int ListItemType;

class List{

// constructors and destructor:
public:
   List();                  // default constructor
   List(const List& aList); // copy constructor
   ~List();                 
   // list operations:
   bool isEmpty() const;

   int getLength() const;

   bool retrieve(int index, 
		            ListItemType& dataItem) const;

   bool insert(int index, ListItemType newItem, ListItemType newWeight);

   bool remove(int index);

   void display();
   bool contains( int key);
   int getDuration( int key);

private:

   struct ListNode{      // a node on the list
      ListItemType vertex; // a data item on the list
      ListItemType weight;
      ListNode *next;    // pointer to next node
   };


   int       size;  // number of items in list
   ListNode *head;  // pointer to linked list 
				    // of items


   ListNode *find(int index) const;
   // Returns a pointer to the index-th node
   // in the linked list
};
