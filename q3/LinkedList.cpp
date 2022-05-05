#include "LinkedList.h"    
#include <cstddef>     
#include <iostream>     
using namespace std;

/*
* Title: Linked List class
* Author: Mustafa Cem Gülümser
* ID: 22003430
* Section: 2
* Assignment: 4
* Description: Implementation for Linked List
*/

List::List(): size(0), head(NULL){}
List::~List(){
   while (!isEmpty())
      remove(1);
}
bool List::isEmpty() const{
   return size == 0;
}
int List::getLength() const{

   return size;

}
List::ListNode *List::find(int index) const{
   if ( (index < 1) || (index > getLength()) )
      return NULL;
   else{ 
      ListNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }
}  
bool List::retrieve(int index, ListItemType& dataItem) const {
   if ((index < 1) || (index > getLength()))
      return false;

   ListNode *cur = find(index);
   dataItem = cur->vertex;
   return true;
}
bool List::insert(int index, ListItemType newItem, ListItemType newWeight) {
   int newLength = getLength() + 1;
   if ((index < 1) || (index > newLength))
      return false;
   ListNode *newPtr = new ListNode;
   size = newLength;
   newPtr->vertex = newItem;
   newPtr->weight = newWeight;
   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      ListNode *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;
}
bool List::remove(int index) {

   ListNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   --size;
   if (index == 1){
      cur = head;  
      head = head->next;
   }
   else{
      ListNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;
   
   return true;

}
void List::display() {
    for( ListNode* ptr = head; ptr != NULL; ptr=ptr->next) {
        cout << ptr->vertex <<endl;
    }
}
bool List::contains( int key) {
    for( ListNode* ptr = head; ptr != NULL; ptr=ptr->next) {
        if( ptr->vertex == key)
            return true;
    }
    return false;
}
int List::getDuration( int key) {
    for( ListNode* ptr = head; ptr != NULL; ptr=ptr->next) {
        if( ptr->vertex == key)
            return ptr->weight;
    }
    return 9999;
}