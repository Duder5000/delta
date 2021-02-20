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
		//~~~Default Constructor for #1~~~
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

		//~~~Destructor for #4~~~
		~str_vec(){
			delete[] arr;
		}


		//~~~Size getter for #5~~~
		int getSize() const{
			return size;
		}

		//~~~Cap getter for #5~~~
		int getCap() const{
			return cap;
		}

		//~~~pct_used for #5~~~
		double pct_used() const{
			// double x;
			// x = (double)size / (double)cap;
			// return (x);
			return (double)size / (double)cap;
		}

		//~~~to_str for #6~~~
		std::string to_str() const{
			std::string result = "[";
			for(int i=0; i<size; i++){
				result += "\"" + arr[i];
				if(i == size-1){
					result += "\"";
				}else{
					result += "\", ";
				}
			}
			result += "]";
			return result;
		}

		//~~~print for #6~~~
		void print() const{
			cout << to_str();
		}

		//~~~println for #6~~~
		void println() const{
			cout << to_str() << "\n";
		}

		//~~~get for #7~~~
		std::string get(int i) const{
			if(i > size || i < 0){
				cout << "Cannot get index " << i << ", exceeds exist \n";
				return "error!";
			}else{
				return arr[i];
			}
		}


		//~~~set for #7~~~
		void set(int i, std::string s){
			if(i > size || i < 0){
				cout << "Cannot get index " << i << ", does not exist \n";
			}else{
				arr[i] = s;
			}
		}

		//~~~Helper function for #8
		void sizeAdjust(){
			if(size == cap){
				cap = 2 * cap;
				std::string * new_arr = new std::string[cap];

				for(int i = 0; i < size; i++){
					new_arr[i] = arr[i];
				}

				delete[] arr; 
				arr = new_arr; 
			}
		}

		//~~~append for #8~~~
		void append(std::string s){
			sizeAdjust();
		
			size += 1;
			arr[size-1] = s;
		}

		//~~~prepend for #8~~~
		void prepend(std::string s){
			sizeAdjust();
		
			std::string * prepend_arr = new std::string[cap];

			prepend_arr[0] = s;
			for(int i = 1; i < size; i++){
				prepend_arr[i] = arr[i];
			}

			delete[] arr; 
			arr = prepend_arr;
		}

		//~~~append(other) for #9~~~
		void append(str_vec& other){
			for (int i = 0; i < other.getSize(); i++){
				std::string tmp = other.get(i);
				append(tmp);
			}
		}

		//~~~reverse for #10~~~
		void reverse(){
			std::string * reverse_arr = new std::string[cap];

			int j = 0;
			for(int i = size-1; i >= 0; i--){
				reverse_arr[j] = arr[i];
				j++;
			}

			delete[] arr; 
			arr = reverse_arr; 			
		}

		//~~~sort for #10~~~
		void sort(){
			std::sort(arr, arr + size);
		}

		//~~~clear for #11~~~
		void clear(){
			delete[] arr; 
			size = 0;
			arr = new std::string[cap];
		}

		//~~~squish for #11~~~
		void squish(){
			std::string * squish_arr = new std::string[size];

			for(int i = 0; i < size; i++){
				squish_arr[i] = arr[i];
			}

			delete[] arr; 
			arr = squish_arr; 
			cap = size;
		}

	private:		
		int size;
		int cap;
		std::string * arr;
}; 


int main() {
  cout << "~~~Assignment 02~~~\n";
  
  str_vec alfa;
  alfa.get(99);
  alfa.get(-1);

  str_vec bravo(5, "cat");
  // cout << bravo.get(0) << "\n";

  // str_vec charlie(-1, "cat");

  str_vec delta(bravo);
  // cout << bravo.get(0) << "\n";
  // cout << bravo.getSize() << "\n";
  // cout << bravo.getCap() << "\n";
  // cout << bravo.pct_used() << "\n";
  // bravo.print();
  // bravo.println();

  bravo.set(1, "dog");
  // cout << "bravo.get(1) = " << bravo.get(1) << "\n";

  bravo.append("fish");
  // cout << bravo.get(bravo.getSize()-1) << "\n";

  bravo.prepend("rabbit");
  cout << bravo.get(0) << "\n";

  str_vec echo(5, "qqq");
  bravo.append(echo);
  bravo.println();

  bravo.reverse();  
  bravo.println();

  bravo.sort();  
  bravo.println();

  // bravo.clear();  
  // bravo.println();

  bravo.squish();
  bravo.println();
}








