///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            Program-2: Priority Queue
// Files:            animals.txt, input_data.txt, 
//                  priority_out.txt, and priority_queue.cpp
//
// Semester:         1063 Data Structures - Spring 2018
//
// Author:           Conner Chamberlain
// Email:            conner.chamberlain@aol.com
// Description:      This program creates a priority list
//                   based queue using a class with methods
//                   to allow for pushing and popping  
//                   animal names based on commands in
//                   the input_data.txt file. It loops 
//                   through the file and uses string
//                   comparisons to indicate which method
//                   from the class to use in order to
//                   prioritize the queue based on name length.
//                   Ties are handled by alphabetical order.
//       
/////////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Node
{	
  string val;
	Node* next;
	Node() 
	{	
	  val = " ";
		next = NULL;
	}
	Node(string v)
	{	
	  val = v;
		next = NULL;
	}
};

/**
*class Queue:
* This uses nodes to create a list based queue with 
* a linked list to aid in pushing and popping items
* to and from the queue
* methods within this class:
*-prioritizeQueue
*-pop
*-pop
*-push
*-empty
*-print
*/
class Queue
{
private:
	Node* Front;
	Node* Rear;
public:
	/**
	* Queue
	* constructor
	* params:
	*     - none
	*/
	Queue()
	{	
	  //initializes the front and rear to NULL
	  Front = Rear = NULL;
	}

/**
* method void prioritizeQueue:
*      Sorts the items in the queue based on length.
* Params:
*      none
* Returns
*      void
*/
  void prioritizeQueue()
	{
	  Node *temp = Front;

		if(empty())
		{  
		  return;
		}
    //prepares the words for possible swapping
		while (temp->next != NULL)
		{	
		  string firstWord = temp->val;
			string secondWord = temp->next->val;
      
      //Handles if the first word is longer than the next
			if (firstWord.length()>secondWord.length())
			{	
				temp->val = secondWord;
				temp->next->val = firstWord;
			}
      
      //Handles if the first word is equal in length to the
      //next 
			else if (firstWord.length() == secondWord.length())
			{	
			  if (firstWord>secondWord)
				{	
				  temp->val = secondWord;
					temp->next->val = firstWord;
				}
			}
			temp = temp->next;
		}
	}
	
/**
* method string pop:
*      Pops a name off of the queue
* Params:
*      none
* Returns
*      string
*/
string pop()
	{	
	  if (!empty())
		{
		  Node* temp = Front;   
			string v = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			return v;
		}
		else
		{	
		  cout << "error: cannot pop off empty queue." << endl;
			return " ";
		}
	}



/**
* method bool pop:
*      pops an animal name off of the queue
* Params:
*      [string] v - the item to be popped off the queue
* Returns
*      void
*/
	bool pop(string &v)
	{	if (!empty())
		{	Node* temp = Front;   // temp pointer so we can delete node
			string t = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			v = t;
			return true;
		}
		else
		{	cout << "error: cannot pop off empty queue." << endl;
			return false;
		}
	}

/**
* method void push:
*      Pushes an animal name on the queue
* Params:
*      [string] val - the valur to be pushed onto the queue
* Returns
*      void
*/
  void push(string v)
	{	Node* n = new Node(v);
		// handle the empty case
		if (empty())
		{
		  Front = n;
			Rear = n;
		}
		else
		{	// not empty add to rear
			Rear->next = n;
			Rear = n;
		}
	}

/**
* method bool empty:
*      checks if the queue is empty
* Params:
*      none
* Returns
*      bool
*/
  bool empty()
	{	
	  return (Front == NULL);
	}

/**
* method void print:
*      Prints every item still on the queue.
* Params:
*      none
* Returns
*      void
*/
  void print()
	{	
	  Node* temp = Front;
		while (temp)
		{	
		  cout << temp->val << "->";
			temp = temp->next;
		}
		cout << '\n';
	}


/**
* function string first:
*      Returns the first item in the queue
* Params:
*      none
* Returns
*      string
*/
  string first()
  { 
    // Checks the first item in queue and returns it
    //for use.
    while (!empty())
    { 
      return Front->val;
    }
    return "";
  }
  
/**
* function outfileNames:
*      Prints the remaining names to an outfile based on
*  word length priority.
* Params:
*      outfile
* Returns
*      void
*/
  void outfileNames(ofstream &outfile)
  { 
    int outfiled = 1;
    Node *temp = Front;
		while (temp)
		{	
		  outfile << outfiled++ << " " << temp->val << '\n';
			temp = temp->next;
		}
  }
};

int main()
{	
  int popped = 1;
  Queue Q;
	string animal, action;
	int nodecount = 0;      
	                        
	//Allows for use of the input_data.txt file and creates
	//an outfile for displaying the outcome of the program.
	
  fstream infile;
	infile.open("input_data.txt");
	ofstream outfile;
	outfile.open("priority_out.txt");
	outfile << "Animals Popped off the Queue:" << '\n' << '\n';
	
	//This loops through the input_data.txt file
	//to handle the commands in the file.
	while (infile >> action)
	{	
	  //Handles the push action command from the
    //input_data.txt file by commanding the 
    //next name in the list (the animal name to
    //be pushed) using the push method.
	  if (action == "push")
		{	
		  infile >> animal;
			Q.push(animal);
			nodecount++;
		} 
    //Handles the pop action command from the
    //input_data.txt file by commanding the 
    //next name in the list (the animal name to
    //be popped) using the pop method.
		else if (action == "pop")
		{ 
		  if (Q.first() != "") 
		  { 
		    outfile<<popped++<< " " <<Q.first()<< '\n';
		  }
		  Q.pop(animal);
    	nodecount--;
			if (nodecount < 0)  
			{ 
			  nodecount = 0;   
			} 
		} 

    if (nodecount > 1)    
    { 
      //This is where the items are prioritized
      //using the prioritizeQueue method from
      //the class
      for(int i = 0; i < nodecount - i ; i++) 
      { 
        Q.prioritizeQueue();
      } 
    } 
	} 
	
	outfile << '\n' << "Animals Remaining on the Queue (in order of priority):" << '\n' << '\n';
	
	//Outfiles the remaining items in the queue in their
	//prioritized order.
	Q.outfileNames(outfile);
	infile.close();
	outfile.close();
	return 0;
}

