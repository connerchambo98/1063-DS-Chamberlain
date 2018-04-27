/////////////////////////////////////////////////////////////////////////////////////////////
// ProgramName: Program-3
// Author: Conner Chamberlain
// Description: 
//     This program reads in animal names into a doubly-linked
// list. It then prompts the user to enter a number that will
// serve as the random number seed. It then prompts the user
// to enter a number that acts as the multiplier. If the 
// number is even, the pointer moves to the right and vice
// versa. Animals are then removed based on the random number 
// until one animal is left. This animal is then declared the
// winner (the animal names are read in from a .txt file).
// This is all made possible from the class with methods
// for checking conditions and loops to initiate said methods
// in main.cpp.
// Course: 1063 Data Structures
// Semester: Spring 2018
// Date: 27 04 2018
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

#include "DBList.h"

using namespace std;

int main() 
{
  
  DBList List;
  
  //allow for manipulation
  string first;       
  string second;       
  
  int listSize = 0;   
  
  int rand = 0; 
  
  int num = 0;    
  
  int length = 0; 
  
   
  
  
  //prompts user to enter the random number seed
  cout << "Please enter a number that will serve as the random seed:" << endl;
  
  cin >> rand;    
  
  srand(rand);
  
  //allows for use of the animal file
  ifstream fin("animals.txt");
  
  //creates the outfile for the program
  ofstream outfile("eliminated.txt");
  
  // outfile of my header
  outfile << "///////////////////////////////////////" << endl;
  outfile << "//ProgramName: Program-3" << endl;
  outfile << "//Author: Conner Chamberlain" << endl;
  outfile << "//Description: " << endl;
  outfile << "//This program reads in animal names into a doubly-linked" << endl;
  outfile << "//list. It then prompts the user to enter a number that will" << endl;
  outfile << "//serve as the random number seed. It then prompts the user" << endl;
  outfile << "//to enter a number that acts as the multiplier. If the" << endl;
  outfile << "//number is even, the pointer moves to the right and vice" << endl;
  outfile << "//versa. Animals are then removed based on the random number" << endl;
  outfile << "//until one animal is left. This animal is then declared the" << endl;
  outfile << "//winner (the animal names are read in from a .txt file)." << endl;
  outfile << "//This is all made possible from the class with methods" << endl;
  outfile << "//for checking conditions and loops to initiate said methods" << endl;
  outfile << "//in main.cpp." << endl;
  outfile << "//Course: 1063 Data Structures" << endl;
  outfile << "//Semester: Spring 2018" << endl;
  outfile << "//Date: 27 04 2018" << endl;
  outfile << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
  
  // inserts the items into the list
  while(!fin.eof()){
    
    fin >> first;
    
    listSize++;         
    
    List.InsertRear(first);
    
  }
  
  // resets the list
  fin.clear();
  fin.seekg(0, std::ios::beg); // back to the start!
  
    
  //prompts user for a number
  cout << "Choose a number between 1 and 13: " << endl;
  
  cin >> num;       
  
  // prompts user for another number if the first number 
  // was not between 1 and 13
  while(num > 13 || num < 1)
  {
    cout << "Number must be between 1 and 13: " << endl;
    
    cin >> num;
  }
  // outfiles the multiplier chosen
  outfile << "The chosen multiplier: " << num << endl;
  
  // loop for checking conditions
  while(!fin.eof())
  {
    // gives first animal
    fin >> first;
    
    outfile << "First: ";
    
    while(listSize > 1){

    length = first.length() * num;
    
    second = List.checkEvenOdd(length);
        
    // prints out every 11 animals removed
    if(listSize % 11 == 0)
    {
      outfile << "- " << second << endl;
      
      cout << " " << second << endl;
    }
        else
        {
          cout << " " << second << endl;
        }
        
        fin >> first;
        
        listSize--;
      }
    }
    //prints the results
    List.Print(outfile);
}

