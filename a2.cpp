// a2.cpp
// Github repo: https://github.com/Duder5000/delta.git

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

			//copy data
			for(int i = 0; i < sv.size; i++){
				arr[i] = sv.get(i);
			}
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

		//~~~

	private:		
		int size;
		int cap;
		std::string * arr;
}; 


//~~~Functions for #12~~~
bool operator==(str_vec& a, str_vec& b){
	if(a.getSize() != b.getSize()){
		//if the size is different they cannot be the same so return false
		return false;
	}else{
		a.sort();
		b.sort();
		for(int i = 0; i < a.getSize(); i++){
			if(a.get(i) != b.get(i)){
				return false;
			}			
		}
	}
	return true;
}

bool operator!=(str_vec& a, str_vec& b){
	return !(a == b);
}


//~~~Test Functions~~~
void test01(){
	cout << "Starting test01 \n";
	str_vec alfa;
  	alfa.get(99);
  	alfa.get(-1);
}

void test02(){
	cout << "Starting test02 \n";
	str_vec charlie(5, "cat");
  	cout << charlie.get(3) << "\n";
}

void test02Error(){
	cout << "Starting test02 Error \n";
	str_vec charlie(-1, "cat");
}

void test03(){ 
	cout << "Starting test03 \n";
	str_vec delta(5, "dog");
	str_vec echo (delta);
	cout << echo.get(3) << "\n";
}

// test04 --> valgrind confirms it is working

void test05(){
	cout << "Starting test05 \n";
	str_vec foxtrot;
	foxtrot.append("cow");
	cout << "size = " << foxtrot.getSize() << "\n";
	cout << "capacity = " << foxtrot.getCap() << "\n";
	cout << "pct_used = " << foxtrot.pct_used() << "\n";
}

void test06(){
	cout << "Starting test06 \n";
	str_vec golf(5, "sheep");
	cout << "to_str() = " << golf.to_str() << "\n";

	cout << "print = ";
	golf.print(); 
	cout << "\n";

	cout << "println = ";
	golf.println();
}

void test07(){
	cout << "Starting test07 \n";
	str_vec hotel(5, "chicken");
	cout << "Before .set(): " << hotel.get(1) << "\n";
	hotel.set(1, "not a chicken");
	cout << "After .set(): " << hotel.get(1) << "\n";
}

void test08(){
	cout << "Starting test08 \n";
	str_vec india(5, "pig");
	india.append("lama");
	india.prepend("alpaca");
	india.println();
}

void test09(){
	cout << "Starting test09 \n";
	str_vec juliett(5, "cat");
	juliett.set(1, "dog");
  	juliett.append("fish");
  	juliett.prepend("rabbit");
	
	str_vec kilo(5, "qqq");
  	juliett.append(kilo);

  	juliett.println();
}

void test10(){
	cout << "Starting test10 \n";
	str_vec lima(5, "cat");
	lima.set(1, "dog");
  	lima.append("fish");
  	lima.prepend("rabbit");

  	lima.reverse();
  	lima.println();

  	lima.sort();
  	lima.println();
}

void test11(){
	cout << "Starting test11 \n";
	str_vec mike(5, "cat");

	mike.clear();
	cout << "size = " << mike.getSize() << ", cap = " << mike.getCap() << "\n";

	mike.squish();
	cout << "size = " << mike.getSize() << ", cap = " << mike.getCap() << "\n";
}

void test12(){
	cout << "Starting test12 \n";
	str_vec november(5, "cat");
	str_vec oscar(5, "cat");
	str_vec papa(4, "dog");
	str_vec quebec(5, "dog");

	cout << "== section \n";
	cout << "november == oscar boolen value: " << (november == oscar) << "\n";
	cout << "november == papa boolen value: " << (november == papa) << "\n";
	cout << "november == quebec boolen value: " << (november == quebec) << "\n";

	cout << "!= section \n";
	cout << "november != oscar boolen value: " << (november != oscar) << "\n";
	cout << "november != papa boolen value: " << (november != papa) << "\n";
	cout << "november != quebec boolen value: " << (november != quebec) << "\n";
}

int main() {
  cout << "~~~Assignment 02~~~\n";
  test01();
  test02();
  // test02Error();
  test03();
  cout << "Starting test04 \nvalgrind confirms it is working\n";
  test05();
  test06();
  test07();
  test08();
  test09();
  test10();
  test11();
  test12();
}








