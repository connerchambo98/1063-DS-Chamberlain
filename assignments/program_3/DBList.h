#include <iostream>
#include <string>

using namespace std;

struct Node{
  string Data;

  Node *Prev;
  Node *Next;
  Node(string x){
      Data = x;
      Prev = NULL;
      Next = NULL;
  }
};

class DBList{
private:
    Node *Head;
    Node *Tail;
    Node *Current;
    Node* _Find(string);
    void rPrint(Node*);
    void rPrint1(Node*);
public:
    DBList();
    void InsertFront(string);
    void InsertFront(Node*&);
    void InsertRear(string);
    void InsertRear(Node*&);
    void InsertInOrder(string);
    void PriorityInsert(string Data);
    bool Delete(string);   
    bool Find(string);     
    bool Update(string,string);   
    void Print(ofstream&);
    void Print(int, ofstream&);
    void rPrint();
    string deleteNode(Node*);
    string checkEvenOdd(int check);
};
