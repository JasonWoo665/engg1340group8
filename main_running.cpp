#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Tons_of_commands.h"

using namespace std;

//*******************************//
//
//please delete the dynamic struct array at the end
//

int main() {
    Tons_of_commands Tons_of_commands;
	string filename,filename2;
	// number of items result from filter
	int filter_length;
	// used as string input receiver in interface
	string keyword;
	// used as character input receiver in interface
	char kw;
	// used as integer input receiver in interface
	int x, y;
	// the location of the selected item in main list
	int selected;
	// new item name and item amount after editing
	string edit_name;
	int edit_num;


	cout << "Please enter the filename of the main list: ";
	cin >> filename;
	cout << "Please enter the filename of the record list: ";
	cin >> filename2;

	// open the file containing data base
	int n = Tons_of_commands.itemcount(filename);

	list * mainlist = new list[100];
	list * SearchResult = new list[n];
	// store the result of a selected item
	list specific_list;
	// read the file to a list
	n = Tons_of_commands.read_file(filename, mainlist);
	cout << "List of data:" << endl;
	Tons_of_commands.printlist(mainlist, n);
	Tons_of_commands.read_filer(filename2, mainlist);
	cout << endl;
	cout << "List of record for the latest 7-time modifications(before editing):" << endl;
	Tons_of_commands.printlistr(mainlist, n);
	cout << endl;

	int command = 0;
	while (command != 7) {
		cout << "**************************************************************************" << endl;
		cout << "* Select a command to operate:                                           *" << endl;
		cout << "* 1. search data                                                         *" << endl;
		cout << "* 2. change and update the data                                          *" << endl;
		cout << "* 3. sort the data                                                       *" << endl;
		cout << "* 4. append new data                                                     *" << endl;
		cout << "* 5. show the list of data                                               *" << endl;
        cout << "* 6. to show the record of the latest 7-time modifications(after editing)*" << endl;
		cout << "* 7. EXIT                                                                *" << endl;
		cout << "**************************************************************************" << endl;
		cout << "->Enter your great command here : ";
		cin >> command;
		switch (command) {
		case 1:
			cout << "Please choose which kind of search to undergo: (1, 2, 3)" << endl;
			cout << "1. search by keyword" << endl;
			cout << "2. search by starting letter" << endl;
			cout << "3. search by number of stocks" << endl;
			int command1;
			cin >> command1;
			switch (command1) {
			case 1:
				cout << "Enter the keyword for searching : ";
				cin >> keyword;
				filter_length = Tons_of_commands.FilterByKeyword(mainlist, SearchResult, keyword, n);
				break;
			case 2:
				cout << "Enter the keyword for searching : ";
				cin >> kw;
				filter_length = Tons_of_commands.FilterByStarting(mainlist, SearchResult, kw, n);
				break;
			case 3:
				cout << "Enter the number x of stock for searching : ";
				cin >> x;
				cout << "1. Search for items >=x" << endl;
				cout << "2. Search for items <=x" << endl;
				bool choice;
				cin >> y;
				if (y == 1) {
					choice = true;
				}
				else if (y == 2) {
					choice = false;
				}
				else {
					break;
				}
				filter_length = Tons_of_commands.FilterByNum(mainlist, SearchResult, choice, x, n);
				break;
			default: continue;
			}
			if (filter_length == 0) {
				cout << "No result found" << endl;
			}
			else {
				cout << "----------|Search result|----------" << endl;
				Tons_of_commands.printlist(SearchResult, filter_length);
				cout << "-----------------------------------" << endl;
				cout << "Enter -1 to continue or choose an item to undergo operation : (1-" << filter_length << ")" << endl;
				cin >> x;
				if ((x > filter_length) || (x < 0)) {
					continue;
				}
				else {
					selected = Tons_of_commands.select(mainlist, SearchResult, n, x, specific_list);
					cout << "Select which kind of operation to undergo: " << endl;
					cout << "1. Delete the item" << endl;
					cout << "2. Edit the item" << endl;
					cout << "3. change the amount of item" << endl;
					cin >> y;
					switch (y) {
					case 1:
						Tons_of_commands.deleting(mainlist, selected, n);
						Tons_of_commands.update(mainlist, filename, n);
						Tons_of_commands.updater(mainlist,filename2,n);
						cout << "Item successfully deleted!" << endl;
						break;
					case 2:
						cout << "Please enter the new item name and number of stock : ";
						cin >> edit_name >> edit_num;
						Tons_of_commands.edit(mainlist, selected, n, edit_name, edit_num);
						Tons_of_commands.update(mainlist, filename, n);
						Tons_of_commands.updater(mainlist,filename2,n);
						cout << "Item successfully changed!" << endl;
						break;
					case 3:
						cout << "Please enter the change in amount of stock (can be positive or negative) : ";
						cin >> x;
						Tons_of_commands.adding(mainlist, selected, x);
						Tons_of_commands.update(mainlist, filename, n);
						Tons_of_commands.updater(mainlist,filename2,n);
						cout << "Stock number successfully changed!" << endl;
					}
				}
			}
			Tons_of_commands.alertcheck(mainlist,n);
			Tons_of_commands.update(mainlist, filename, n);
			Tons_of_commands.updater(mainlist, filename2, n);
			cout << "Enter any number to continue...  ";
			cin >> x;
			break;
		case 2:
			cout << "A suitable change.txt created? (Y/N)" << endl;
			cin >> kw;
			if (kw == 'Y') {
				Tons_of_commands.change(mainlist);
				Tons_of_commands.update(mainlist, filename, n);
				cout << filename << " changed!" << endl;
				cout << "Enter any number to continue...  ";
				cin >> x;
			}
			else if (kw == 'N') {
				Tons_of_commands.create_change(mainlist, n);
				cout << "change.txt created, input data in change.txt for operation" << endl;
				cout << "Enter any number to continue...  ";
				cin >> x;
				break;
			}
			Tons_of_commands.alertcheck(mainlist, n);
			Tons_of_commands.update(mainlist, filename, n);
			Tons_of_commands.updater(mainlist, filename2, n);
			break;
		case 3:
			cout << "Please choose the method of sorting: " << endl;
			cout << "1. sort by alphabetic order (ascending)" << endl;
			cout << "2. sort by alphabetic order (descending)" << endl;
			cout << "3. sort by stock number (ascending)" << endl;
			cout << "4. sort by stock number (descending)" << endl;
			cin >> x;
			switch (x) {
			case 1:
				Tons_of_commands.sorting_data(mainlist, n, filename, true, filename2);
				cout << "Data sorted!" << endl;
				break;
			case 2:
				Tons_of_commands.sorting_data(mainlist, n, filename, false, filename2);
				cout << "Data sorted!" << endl;
				break;
			case 3:
				Tons_of_commands.sorting_data_number(mainlist, n, filename, true, filename2);
				cout << "Data sorted!" << endl;
				break;
			case 4:
				Tons_of_commands.sorting_data_number(mainlist, n, filename, false, filename2);
				cout << "Data sorted!" << endl;
				break;
			default:
				cout << "Fail to sort the data." << endl;
				break;
			}
			Tons_of_commands.alertcheck(mainlist, n);
			cout << "Enter any number to continue...  ";
			cin >> x;
			break;
		case 4:
			cout << "Please enter the stock name and stock number to be appended to the data base : ";
			cin >> edit_name >> edit_num;
			Tons_of_commands.adding_data(filename, mainlist, edit_name, edit_num, n);
			Tons_of_commands.alertcheck(mainlist, n);
			cout << "Data appended." << endl;
			cout << "Enter any number to continue...  ";
			cin >> x;
			break;
		case 5:
			cout << "List of data:" << endl;
			Tons_of_commands.printlist(mainlist, n);
			Tons_of_commands.alertcheck(mainlist, n);
			Tons_of_commands.updater(mainlist, filename2, n);
			Tons_of_commands.update(mainlist, filename, n);
			cout << "Enter any number to continue...  ";
			cin >> x;
			break;
		case 6:
			cout << "List of record for the latest 7-time modifications(after editing):" << endl;
			Tons_of_commands.printlistr(mainlist, n);
			Tons_of_commands.alertcheck(mainlist, n);
			Tons_of_commands.update(mainlist, filename, n);
			Tons_of_commands.updater(mainlist, filename2, n);
			cout << endl;
			break;
		}//end of switch
	}//end of while(command !=7)

	return 0;
}
