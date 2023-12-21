#include "Employee.h"													// Defines class Employee
#include "Map.h"		
#include "Book.h"												// Defines template Map<Key, Value>
#include <iostream>

#include <string>

using namespace std;

typedef unsigned int ID; 	
typedef string Name;											// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees
typedef Map<Name, Book> LibraryDatabase; 									// Database of employees



//employees
void addEmployees(Database& database);
void modifyEmployees(Database& database);
void searchDatabase(Database& database);
void addDataWithSameKey(Database& database);

//books 
void addBooks(LibraryDatabase& database);
void modifyBooks(LibraryDatabase& database);
void searchLibraryDatabase(LibraryDatabase& database);
void addLibDataWithSameKey(LibraryDatabase& database);


void testDatabase();
void testLibraryDatabase();


int main() {
   testDatabase();
   testLibraryDatabase();
   return 0;
}

void testDatabase()
{
	Database database;
    addEmployees(database);

    Database newDatabase = database;
    newDatabase.add(830505432, Employee("Ewa Nowak", "chairwoman", 43));
    modifyEmployees(newDatabase);

    cout << "\n\nOriginal database:" << endl << database << endl;
    cout << "\n\nModified database:" << endl << newDatabase << endl;

    database = newDatabase;

    cout << "\n\nDatabase after the assignment:" << endl << database << endl;
    
    cout << "\n\nSearch employee database for employee that doesnt exist:" << endl;
    searchDatabase(database);
    cout << "\nAdd employee with same key: " << endl;
    addDataWithSameKey(database);
    
}


void testLibraryDatabase()
{	
	cout<<"\n\nLibrary database"<<endl;
	
	LibraryDatabase library; 
    addBooks(library);
    cout << "\n\nOriginal library database:" << endl << library << endl;
    
    LibraryDatabase newlibrary = library;
    newlibrary.add("My little princess", Book("Farah Patzelt", "Comedy", 150));
    modifyBooks(newlibrary);

    //cout << "\n\nOriginal library database:" << endl << library << endl;
    cout << "\n\nModified library database:" << endl << newlibrary << endl;

    library = newlibrary;

    cout << "\n\nDatabase after the assignment:" << endl << library << endl;
    
    cout << "\n\nSearch library database for book that doesnt exist:" << endl;
    searchLibraryDatabase(library);
    cout << "\nAdd book with same key: " << endl;
    addLibDataWithSameKey(library);
}


void addEmployees(Database& database) {
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
}

void modifyEmployees(Database& database) {
	Employee* employeePtr;

	employeePtr = database.find(510212881);								// Find employee using its ID
	employeePtr->position = "salesman";									// Modify the position of employee
	
	employeePtr = database.find(761028073);								// Find employee using its ID
	employeePtr->age = 29;												// Modify the age of employee
}

void searchDatabase(Database& database) {
	Employee* employeeptr;
	
	employeeptr = database.find(761028072);
	
	cout<<"\n" << employeeptr<<endl;
}
	
void addDataWithSameKey(Database& database)
{
	database.add(761028073, Employee("Ham Kowalski", "adminstartor", 78)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,

}

void addBooks(LibraryDatabase& database)
{
	database.add("My little princess", Book("Farah Patzelt", "Comedy", 150));
	database.add("Kornelia is the coolest" , Book("Kindy LObster", "Mystery", 200));
	database.add("Who took the pizza?", Book("Jam Smith", "Sc-fi", 60));
	
}

void modifyBooks(LibraryDatabase& database)
{
	Book* bookptr;

	bookptr = database.find("My little princess");								// Find employee using its ID
	bookptr->pages = 20;	
	bookptr = database.find("Who took the pizza?");								// Find employee using its ID
	bookptr->category = "Horror";									// Modify the position of employee
			

}
void searchLibraryDatabase(LibraryDatabase& database)
{
	Book* bookptr;
	
	//book that doesnt exist shoudl return null (0)
	bookptr = database.find("My little king");
	
	cout<<bookptr<<endl;
	
}
void addLibDataWithSameKey(LibraryDatabase& database)
{
	database.add("My little princess", Book("Cindy FReestone", "horror", 15));
}
