#include "dir.h"
#include <dirent.h>
#include <string>
#include <cstdint>
#include <boost/filesystem.hpp>
#include <stdexcept>
#include <ctime>
#include <iostream>



using namespace std;


int main(int argc, char *argv[]) // Main program begin
{
	dirEntry_t *dirList;
 try
 {
	dirList = listDir(argv[1]); //Generate linked list from directory given in command line argument
	for(dirEntry_t *p = dirList; p!=nullptr; p=p->next) // Output the details of every item within the linked list
	{
		cout << "Name: " << p->name << endl;
		cout << "Date: " << p->date  << endl;
		cout << "Size: " << p->size << " bytes" << endl;
		
	}
	cout << "Number of list items constructed but not released= " << dirList->objCount() << '\n'; //Test if list generation has worked
	
	dirEntry_t* nodeIterator = dirList; //list deletion
	while(dirList != 0)
	{
		dirList= nodeIterator->next;
		delete nodeIterator;
		nodeIterator = dirList;
	}
	cout << "Number of list items constructed but not released= " << dirList->objCount() << '\n'; //Test if deletion has worked
 }
 catch(exception& e) //Exception Handler
 {
	 cout << "Exception occured: " << e.what() << endl;
 }
	
return 0;
} 
