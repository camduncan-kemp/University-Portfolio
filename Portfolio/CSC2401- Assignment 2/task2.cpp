#include "dir.h"
#include <dirent.h>
#include <string>
#include <cstdint>
#include <boost/filesystem.hpp>
#include <stdexcept>
#include <ctime>
#include <iostream>



using namespace std;



void spacer(int number, string filler)
{
	while(number > 0)
	{
		cout << filler;
		number--;
	}
}

void listDirTree(string dirPath, int level)
{
	string tab = "    ";
	dirEntry_t *dirList = listDir(dirPath); //Generate linked list from directory given in command line argument
	spacer(level, tab);
	cout << "Directory: " << dirPath << endl;
	for(dirEntry_t *p = dirList; p!=nullptr; p=p->next)
	{
		
		
		if(p->isFile)
		{
			spacer(level, tab);
			cout << "Name: " << p->name << endl;
			spacer(level, tab);
			cout << "Date: " << p->date  << endl;
			spacer(level, tab);
			cout << "Size: " << p->size << " bytes" << endl;
		}
		else if(p->isDir)
		{
			string newPath = dirPath + "/" + p->name;
			listDirTree(newPath, level+1);
		}
		else
		{
			cout << p->name << " unknown directory entity." << endl;
		}
	}
	dirEntry_t* nodeIterator = dirList; //list deletion
	while(dirList != 0)
	{
		dirList= nodeIterator->next;
		delete nodeIterator;
		nodeIterator = dirList;
	}
	cout << "Number of list items constructed but not released= " << dirList->objCount() << '\n'; //Test if deletion has worked
	
}


int main(int argc, char *argv[]) // Main program begin
{
 try
 {
	listDirTree(argv[1], 0);
		
 }
 catch(exception& e) //Exception Handler
 {
	 cout << "Exception occured: " << e.what() << endl;
 }
	
return 0;
} 
