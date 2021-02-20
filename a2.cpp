// a2.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Alex Soames
// St.# : 301 292 784
// Email: asoames@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough detail
// so that someone can see the exact source and extent of the borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have not
// seen solutions from other students, tutors, websites, books, etc.
//
/////////////////////////////////////////////////////////////////////////

//
// These are the only permitted includes: don't include anything else.
//

#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <algorithm>       
#include <cassert>

using namespace std;

/*
Write a test function for *each* major method/function to ensure it is
correct.
*/

class str_vec {
	public:
		//~~~Default Constructor~~~
		str_vec(){
			size = 0;
			cap = 10;
			arr = new std::string[cap];
		}

		//~~~Constructor for #2~~~
		str_vec(int n, std::string s){
			if(n < 0){
				cmpt::error("In str_vec --> constructor for #2 --> error n < 0");
			}else{
				size = n;
				cap = n;
				arr = new std::string[cap];
				arr[1] = s;
				for(int i = 0; i < cap; i++){
					arr[i] = s;
				}
			}
		}

		//~~~Constructor for #3~~~
		str_vec(str_vec& sv){
			size = sv.size;
			cap = sv.cap;
			arr = new std::string[cap];
		}

		//~~~Destructor for #4

		std::string getAtIndex(int i){
			if(i > size){
				cout << "Nothing at location \n";
			}
			return arr[i];
		}

		void setAtIndex(std::string x, int i){
			arr[i] = x;
		}


		void adder(std::string x){
			arr[size++] = x;
		}


	private:		
		int size;
		int cap;
		std::string * arr;

}; 


int main() {
  cout << "~~~Assignment 02~~~\n";
  
  str_vec alfa;
  alfa.getAtIndex(99);

  str_vec bravo(5, "cat");
  cout << bravo.getAtIndex(0) << "\n";

  // str_vec charlie(-1, "cat");

  str_vec delta(bravo);
  cout << bravo.getAtIndex(0) << "\n";

}












































































//~~~