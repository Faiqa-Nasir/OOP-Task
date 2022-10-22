#include<iostream>
#include<string>
using namespace std;
class books {
	string name;
public:
	books()
	{
		name = "";
	}
	books(string h)
	{
		cout << "books constructor called\n";
		name = h;
	}
	~books()
	{
		cout << "books destructor called\n";
	}
	string getname()
	{
		return name;
	}
	void print() {
		cout << "name of book is " << name << endl;
	}
	books(books& obj)
	{
		cout << "copy constructor called\n";
		name = obj.name;
	}
};
class courses {
	books *startingoutwithc;
	int numberofcourses;
public:
	courses():startingoutwithc() {
		numberofcourses = 0;
	}
	~courses()
	{
		delete startingoutwithc;
		cout << "courses destructor called\n";
	}
	courses(books &obj, int n) 
	{
		startingoutwithc = new books(obj);
		cout << "courses constructor called\n";
		numberofcourses = n;
	}
	void print()
	{
		cout << "number of courses is " << numberofcourses << endl;
		startingoutwithc->print();
	}
};
int main()
{
	books mf("Tony");
	
	
	{courses x(mf, 7); }
	
	cout <<"out\n"<< mf.getname();

	//if you use the new operator with the pointer of the contained class, 
	//you will have to delete 
	// it in the destructor of the container class
	//as well cz it will call a copy constructorand as a 
	//result of that a pointer will be pointing to a brand ne copy
	//of the contained class that was passed.

}