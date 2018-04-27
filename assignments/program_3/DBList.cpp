#include <iostream>
#include <string>
#include <fstream>
#include "DBList.h"

using namespace std;


DBList::DBList(){
  Head = NULL;
  Tail = NULL;
  Current = NULL;
}

/**
 * InsertFront 
 *     Inserts a value at the front of the list by calling 
 *     actual insert with a node.
 * Params:
 *     string : data element to be inserted
 */
void DBList::InsertFront(string Data){
  Node* Temp = new Node(Data);
  InsertFront(Temp);

}

/**
 * InsertFront 
 *     Inserts a value at the front
 * Params:
 *     Node* &Temp : allows formation of the node and 
 *     linking to the other nodes
 */
void DBList::InsertFront(Node* &Temp){
  //empty list 
  //forming a node
  if(!Head){
    Head = Temp;
    Tail = Temp;
    Tail->Next = Head;
    Current = Temp;
    Head->Prev = Tail;
  }else{
    //links everything to each other to make a circular DLL
    Temp->Next = Head;
    Temp->Prev = Tail;
    Head->Prev = Temp;
    Tail->Next = Temp;
    Head = Temp;
    Current = Head;
  }
}

/**
 * InsertRear 
 *     Inserts a value at the rear of the list by calling 
 *     actual insert with a node.
 * Params: 
 *      Node* &Temp : allows formation of the node and 
 *      linking to the other nodes
 *     
 */

void DBList::InsertRear(Node* &Temp){
  //empty list 
  //calls InsertFront
  if(!Head){
    DBList::InsertFront(Temp);
  }else{
    //links everything to each other to make a circular DLL
    Tail->Next = Temp;
    Temp->Prev = Tail;
    Tail=Temp;
    Temp->Next = Head;
    Head->Prev = Tail;
    Current = Tail;
  }
}

/**
 * InsertRear 
 *     Inserts a value at the rear .
 * Params: 
 *        string: data to be inserted
 *     
 */
void DBList::InsertRear(string Data){
  if(!Head){
    DBList::InsertFront(Data);
  }else{
    Node* Temp = new Node(Data);
    InsertRear(Temp);
  }
}


/**
 * Delete:
 *     checks to see if deletion is possible
 * Params: 
 *      string x: checks to see if the string 
 *      is available for deletion
 * Returns: boolean
 *     
 */
bool DBList::Delete(string x){
  //One node 
  if(Head == Tail && Head->Data==x){
    delete Head;
    Head = NULL;
    Tail = NULL;
    Current = NULL;
    return true;
  //Beginning of list
  }else if(Head->Data == x){
    Head = Head->Next;
    Current = Head;
    delete Head->Prev;
    Head->Prev = Tail;
    return true;
  //End of list
  }else if(Tail->Data == x){
    Tail = Tail->Prev;
    delete Tail->Next;
    Tail->Next = Head;
    Current = Tail;
    return true;
  //Middle of list
  }else{
    Node* Location = DBList::_Find(x);
    if(Location){
      //very loopy
      Location->Prev->Next = Location->Next;
      Location->Next->Prev = Location->Prev;
      Current = Location->Next;
      delete Location;
      return true;
    }
  }
  return false; 
}

/**
 * Find 
 *      searches for a string 
 * Params:
 *       string x- in order to check if the string exists
 * Returns:
 *        false
 */
bool DBList::Find(string x){
  return false;
}

/**
 * Print 
 *     Prints out the winner of the program
 * Params: int columns and ofstream &outfile:
 *    allows the program to print out the winner 
 * 
 *     
 */
void DBList::Print(int columns,ofstream &outfile){
  Node *Temp = Head;
  int count = 1;
  
  while(Temp != Tail){
    Temp = Temp->Next;
    if(columns && count % columns == 0)
    count++;
  }
  outfile <<"WINNER: " << Tail->Data<< "!!" << endl;
}

/**
 * Print 
 *     allows for calling of the print function
 * Params: Node* &Temp : 
 *      ofstream &outfile : allows outfiling
 *     
 */
void DBList::Print(ofstream &outfile){
  DBList::Print(0,outfile);
}

/**
 * _Find 
 *     Searches for a key string
 * Params: string key: the key string the method
 * searches for
 *     
 */
Node* DBList::_Find(string key){
  Node* Temp = Head;
  
  while(Temp){
    if (Temp->Data == key){
      return Temp;
    }
    Temp = Temp->Next;
  }
  return NULL;
}


/**
 * checkEvenOdd
 *     checks if the number is even or odd to determine
 *  if the list will go left or right
 * Params: int check: the integer that is used to 
 * determine the direction
 * 
 * Returns : DeleteNode(temp)
 *     
 */

string DBList::checkEvenOdd(int check){
  Node *temp = Current;  
  
  if(check % 2 == 0)
  {
    for(int i=0; i < check; i++)
    {
      Current = Current->Next;
    }
    
    temp = Current;
  }
  else
  {
    for(int i =0; i < check; i++)
    {
      Current = Current->Prev;
    }
    
    temp = Current;
  }

    Current = Current->Next;
    
    return deleteNode(temp);
}
/**
 * deleteNode 
 *     deletes a node to eliminate the animals
 * Params: Node* temp : allows for traversal and deletion
 *     
 */

string DBList::deleteNode(Node* temp){
  if(temp == Head)
  {
      Head = Head->Next;
  }
  
  if(temp == Tail)
  {
      Tail = Tail->Prev;
  }
  
  temp->Prev->Next = temp->Next;
  
  temp->Next->Prev = temp->Prev;
  
  return temp->Data;
  
  delete temp;
}


