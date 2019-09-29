#include "dir.h"
#include <dirent.h>
#include <string>
#include <cstdint>
#include <boost/filesystem.hpp>
#include <stdexcept>
#include <ctime>
#include <iostream>



using namespace std;
namespace filesys = boost::filesystem;


dirEntry_t *dir_add(string _name, int64_t file_size, string _date, bool is_dir, bool is_file, dirEntry_t *node)
{
	node = new dirEntry_t (_name, file_size, _date, is_dir, is_file, node);
	cout << "Number of list items constructed but not released= " << node->objCount() << '\n'; //Test if deletion has worked
	return node;
	
}




int main(int argc, char *argv[]) // Main program begin
{
 try
 {
	dirEntry_t *head = nullptr;
	
	head = dir_add("red.exe", 2581, "21/01/2019", false, true, head);
	head = dir_add("blue.exe", 123, "21/03/2019", false, true, head);
	head = dir_add("green", 4556, "21/04/2019", true, false, head);
	
	for(dirEntry_t *p = head; p!=nullptr; p=p->next) // Output the details of every item within the linked list
	{
		cout << "Name: " << p->name << endl;
		cout << "Date: " << p->date  << endl;
		cout << "Size: " << p->size << " bytes" << endl;
		
	}
	
	dirEntry_t* nodeIterator = head; //list deletion
	while(head != 0)
	{
		head= nodeIterator->next;
		delete nodeIterator;
		nodeIterator = head;
	}
	cout << "Number of list items constructed but not released= " << head->objCount() << '\n'; //Test if deletion has worked
	
 }
 catch(exception& e) //Exception Handler
 {
	 cout << "Exception occured: " << e.what() << endl;
 }
	
return 0;
} 

