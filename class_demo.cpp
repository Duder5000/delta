#include <iostream>
#include <string>
#include "cmpt_error.h"
using namespace std;

// Integer Vector class
// Class members are PRIVATE by default
class int_vec{
public:
	// Constructors and Destructor
	// Make an empty vector - i.e. write CONSTRUCTORs
	// A CONSTRUCTOR is a special method (class functions are 
	// referred to as *methods*) that initializes the attributes
	// (member variables) of a class
	// A constructor *must* have exactly the same name as the class
	// and it has *no* return type
	// Classes often have multiple constructors - each with different
	// paramater lists
	// The DEFAULT CONSTRUCTOR has no parameters
	// TO DO - write more constructors

	// static const - const means it can't be changed
	// static (in this context) - means that there is one and only one instance
	// of the variable for the entire class - not one per object
	static const int initial_capacity = 4;

	// Default constructor - uses an intialization list
	int_vec() : capacity(initial_capacity),size(0),arr(new int[capacity]){}

	// Default constructor - old version, no initalization list
	/*
	int_vec(){
		capacity = 4;
		size = 0;
		arr = new int[capacity];
	}
	*/

	// Constructor to fill a vector of a given size with a given value
	int_vec(int sz, int fill_value) : capacity(sz), 
		size(sz),arr(new int[capacity])
	{
		for(int i=0; i < sz; i++)
		{
			arr[i] = fill_value;
		}
	}

	// Copy Constructor
	// Note that if no copy constructor is written by the programmer
	// a copy constructor is generated for the class
	// BUT - it performs a *shallow* copy where the bit values of the
	// attributes are copied to the new object
	// Note that pointers store *addresses*, therefore a shallow copy
	// copies the address of the existing array - but does *not* make
	// a new - separate - array for the new object
	// THEREFORE if our class allocates space in dynamic memory we must
	// write our own copy constructor that makes a *deep* copy where
	// we explicitly allocate separate space in the free store for the
	// new object
	// COPY CONSTRUCTORs are important not just for explicitly calling
	// to make a copy of an exisiting object. They are also used to make
	// copies of arguments in functions that have pass-by-value
	// parameters of the class
	// e.g. void foo(int_vec iv) - note that iv is passed by value
	// When you pass by value you make a copy of the argument - which
	// uses the copy constructor
	int_vec(const int_vec & other)
	: capacity(other.capacity), size(other.size), arr(new int[capacity])
	{
		// Copy the contents of the parameter
		for(int i = 0; i < size; ++i){
			arr[i] = other.arr[i];
		}
	}
	
	// Destructor - destructors have the same name as the class name
	// except that they are preceded by a tilde (~), with no parameters
	// Note the compiler auto-generates a destructor if one is not
	// written - *but* it doesn't deallocate any memory
	// RULE - if your class allocates dynamic memory (using new) you 
	// *must* write a destructor to deallocate it (using delete)
	// The destructor is called when:
	//		an *object* that was created in dynamic memory using new
	//		is explicitly deleted using delete AND
	//		when an object on the stack goes out of scope
	// DO NOT explicitly call a destructor
	~int_vec()
	{
		// Print statement for demonstration purposes only
		cout << "deleting object with arr[0] = " << arr[0] << endl;
		delete[] arr;
	}

	// Getters and Setters

	// Overload operator[] to allow int_vec[int]
	// When overloading binary operators e.g. x + y there are two *operands*
	// i.e. x and y. They are usually given really imaginative names:
	// x is referred as the left-hand operand and y is referred to as the
	// right-hand operans (wow).
	// WHEN writing overloaded operators that are members of a class the
	// LH operand must be the CALLING OBJECT, the RH operand is the parameter
	// op[] must return an int (because int_vecs store integers)
	// the LH operand is the calling object so is implicit in the prototype
	// the RH operand is the parameter
	// Returning a reference (&) to an int allows us to change the elements of the 
	// underlying array
	int& operator[](int i){
		// Note by convention there is no error checking
		return arr[i];
	}

	// Proof of concept that you can have multiple overloaded operators
	// with *different* parameter lists
	// NOTE: this particular op[] makes very little sense ...
	/*
	int& operator[](string s){
		// Note by convention there is no error checking
		cout << s << ": ";
		return arr[0];
	}
	*/

	// Constant version of op[] for statements like:
	//	const int_vec v(10, 42);
	int operator[](int i) const{
		// Note by convention there is no error checking
		return arr[i];
	}

	// Retrieve an element of the vector at a given index
	// Making method const prevents changes to the class attributes
	int get(int i) const{
		// Throw error if i is out of legal range
		if(i < 0 || i >= size)
		{
			cmpt::error("i is out of legal range");
		}
		//size = 13; // BAD, prevented by method being const
		return arr[i];
	}

	// Returns size - number of elements stored in array
	// Making method const prevents changes to the class attributes
	// The *this* pointer is a pointer to the calling object
	int get_size() const{
		//return this->size;
		return size;
	}

	// Change the value of an element at a given index
	void set(int i, int x){
		// Throw error if i is out of legal range
		if(i < 0 || i >= size)
		{
			cmpt::error("i is out of legal range");
		}
		arr[i] = x;
	}

	// Insert a value at the end of the vector
	void append(int x){
		if(size == capacity){
			// Make a new array of twice the capacity and copy the 
			// contents of the existing array into it
			capacity = 2 * capacity;
			int* new_arr = new int[capacity];

			// Copy elements
			for(int i = 0; i < size; ++i){
				new_arr[i] = arr[i];
			}

			delete[] arr; //deallocate memory associated with original array
			arr = new_arr; //assigning address of new_arr to arr
		}
		
		arr[size++] = x;
		// arr[size] = x;
		// ssize++;
	}

	// Prints the contents of the vector
	void print() const{
		if(size == 0){
			cout << "{}";
		}else{
			cout << "{";
			cout << arr[0];
			for(int i = 1; i < size; ++i){
				cout << ", " << arr[i];
			}
			cout << "}";
		}
	}

	private:
	// Class attributes are typically made private, private class 
	// attributes *can* be accessed from inside the *same* class
	// but not from functions outside the class
	int capacity;
	int size;
	int * arr;
};

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();

int main()
{
	//test1();
	//cout << "finished test1" << endl;
	//test2();
	//cout << "finished test2" << endl;
	//test3();
	//test4(); //append
	//test5(); //copy constructor
	test6();
	test7();

	return 0;
}

void test1()
{
	int_vec iv; //declare an int_vec OBJECT
				//using the default constructor - i.e. no parameters
	//iv.capacity = 100;

	iv.append(1);
	iv.append(2);

	cout << "iv.get(0) = " << iv.get(0) << endl;
	cout << "iv.get(1) = " << iv.get(1) << endl;

	cout << "about to exit test1" << endl;
}

void test2()
{
	int_vec* piv = new int_vec();

	piv->append(42);
	piv->append(243);

	cout << "piv.get(0) = " << piv->get(0) << endl;
	cout << "piv.get(1) = " << piv->get(1) << endl;
	delete piv;
	cout << "about to exit test2" << endl;
}

void test3()
{
	int_vec iv(10, 42); //uses the "fill" constructor

	//for(int i=0; i < 100; i++) // error size and capacity are 10
	for(int i=0; i < iv.get_size(); i++)
	{
		cout << iv.get(i) << endl;
	}
}

void test4()
{
	int_vec iv;
	for(int i = 0; i < 17; i++){
		iv.append(i+1);
	}
	iv.print();
	cout << endl;
}

void test5()
{
	int_vec iv1;

	iv1.append(1);
	iv1.append(2);
	// {1,2}, size = 2, capacity = 4

	// Make a copy
	int_vec iv2(iv1);
	//int_vec iv3("bob"); //error because there is no int_vec(string)

	// Print iv1 and iv2
	cout << "IV1:";
	iv1.print();
	cout << endl;
	cout << "IV2:";
	iv2.print();
	cout << endl << endl;

	// Change iv2
	iv2.append(3);
	iv2.set(1, 42);

	// Print iv1 and iv2
	cout << "change iv2" << endl;
	cout << "IV1:";
	iv1.print();
	cout << endl;
	cout << "IV2:";
	iv2.print();
	cout << endl;
	cout << "IV2 size = " << iv2.get_size() << endl;
	cout << endl << endl;
}

void test6()
{
	int_vec iv1;
	for(int i = 0; i < 17; i++){
		iv1.append(i+1);
	}
	for(int i = 0; i < iv1.get_size(); i++){
		iv1[i] = 100;
	}
	for(int i = 0; i < iv1.get_size(); i++){
		cout << iv1[i] << " ";
	}

	cout << endl << "Print elements of a const int_vec" << endl;
	const int_vec iv2(10, 42);
	for(int i = 0; i < iv2.get_size(); i++){
		cout << iv2[i] << " ";
	}
	cout << endl;

	// cout << iv1["bob"] << endl; // look what weird nonsense you can do!
}

void test7()
{
	// Note that the . operator is the member (of) operator and there is no
	// declared int_vec
	// The :: is the SCOPE RESOLUTION OPERATOR used to give a fully-qualified
	// name
	cout << "initial capacity = " << int_vec::initial_capacity;
	cout << endl;

	// cout << iv1["bob"] << endl; // look what weird nonsense you can do!
}