#include "Tons_of_commands.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdio>
using namespace std;

//the list for products
//name: the name of product
//number: the number of products

Tons_of_commands::Tons_of_commands()
{
    //constructor only, ignore it
}

// itemcount : count items inside the data base
// input : string filename : the file storing the data base
//output : number of items inside the data base

int Tons_of_commands::itemcount(string filename) {
	string useless;
	int count = 0;
	ifstream fin;
	fin.open(filename.c_str());
	if (fin.fail()) {
		cout << "No such file exist!" << endl;
		exit(1);
	}
	while (getline(fin, useless)) {
		count++;
	}
	fin.close();
	return count;
}

//  read_file(1,2,r) : reading the file containing data in different type
//              used to update the list too
//              and save data inside an array
//  input : string filename : the name of the file
//          list mainlist   : the list for storing
//  output : int count : the number of items inside array

int Tons_of_commands::read_file(string filename, list mainlist[]) {
	//template for reading data in the file
	string reading_name;
	int reading_num;
	string reading_str;

	//open the file
	ifstream fin;
	fin.open(filename.c_str());
	if (fin.fail()) {
		cout << "No such file exist!" << endl;
		exit(1);
	}
	//reading data inside the file
	int count = 0;
	bool canread = true;
	while (canread) {
		int assign_box;
		assign_box = count / 3;
		if (count % 3 == 0) {
			if (fin >> reading_name) {
				mainlist[assign_box].name = reading_name;
			}
			else {
				canread = false;
			}
		}
		else 
			if (count %3 ==1 ){
				if (fin >> reading_num) {
					mainlist[assign_box].number = reading_num;
				}
			else {
				canread = false;
			}
			}
			else 
				if (count %3 == 2) 
					fin >> reading_str;
				else
					canread = false;	
				
		count++;
	}
	fin.close();
	return count / 3;
}

// read_file2 : To read txt file in the format of change.txt
int Tons_of_commands::read_file2(string filename, list mainlist[]){
    //template for reading data in the file
    string reading_name;
    int reading_num;

    //open the file
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail()){
        cout << "No such file exist!" <<endl;
        exit(1);
    }
    //reading data inside the file
    int count=0;
    bool canread=true;
    while (canread){
        int assign_box;
        assign_box=count/2;
        if (count%2==0){
            if (fin >> reading_name){
                mainlist[assign_box].name=reading_name;
            }
            else{
                canread=false;
            }
        }
        else{
            if (fin >> reading_num){
                mainlist[assign_box].number=reading_num;
            }
            else{
                canread=false;
            }
        }
        count++;
    }
    fin.close();
    return count/2;
}

void Tons_of_commands::read_filer(string filename, list mainlist[]){
	string reading_name;
    int reading_num;
    //open the file
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail()){
        cout << "No such file exist!" <<endl;
        exit(1);
    }
    //reading data inside the file
    int count=0;
    int i = 0;
    bool canread=true;
    while (canread){
    	if (i%8 == 0){
    		if (fin >> reading_name){	
    			i += 1;
    		}
    		else
    			canread = false;
    	
    	}
    	else
    		if (fin >> reading_num){
				mainlist[i/8].rec[i%8-1] = reading_num;
    			i += 1;
    		}
    		else
    			canread = false;
		}
}
// update/updater : update the file, usually used after adding, editing or deleting data
// input : list mainlist[] : the list containing all data
//         string filename : the file name saving the updated mainlist[]
//         int n : number of items inside mainlist[]

void Tons_of_commands::update(list mainlist[], string filename, int n) {
	//open the file for overwriting the old version
	ofstream fout;
	fout.open(filename.c_str());
	if (fout.fail()) {
		cout << "fail to open " << filename << endl;
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		fout << mainlist[i].name << ' ' << mainlist[i].number << ' ';
		if (mainlist[i].number <= 0)
			fout << "Out-of-stock" << endl;
		else
			fout << "In-stock" << endl;
	}
	fout.close();
}
//Updater : to update the record of record.txt (a txt file containing past data)
// input  : list mainlist[] : the largest list containing all current data
//          string filename : the filename of the record.txt
//          int n : the number of items in the largest list containing all current data
void Tons_of_commands::updater(list mainlist[], string filename, int n) {
	//open the file for overwriting the old version
	ofstream fout;
	fout.open(filename.c_str());
	if (fout.fail()) {
		cout << "fail to open " << filename << endl;
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		fout << mainlist[i].name << " ";		
		for (int j = 0; j < 7; j++){
			fout << mainlist[i].rec[j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

// alert : check and give alert to outofstock item
void Tons_of_commands::alertcheck(list mainlist[]) {
	for (int i = 0; i < itemcount("dalist.txt"); i++) {
		if (mainlist[i].number <= 0) {
			cout << "** "<<mainlist[i].name << " is out-of-stock! Please increase the inventory! **" << endl;
		}
	}
}

//  sorting_data  :   sort data in alphabetic order and output to a file (not case sensitive)
//                    and ask for replacing the original file or not
//  input   :   list mainlist[] : the list to be sorted
//              int  n          : the number of items in mainlist[]
//              string filename : filename of the original file
//              bool order      : true = ascending order, false = descending order
//  cin     :   query for save as or replacing current file

void Tons_of_commands::sorting_data(list mainlist[], int n, string filename, bool order, string filename2) {
	string name_temp;
	int num_temp;
	int arr_temp[7];
	//selection sort for the mainlist
	int m;
	for (int i = 0; i < n - 1; i++) {
		m = i;
		for (int j = i + 1; j < n; j++) {
			string str1 = mainlist[m].name;
			string str2 = mainlist[j].name;
			if (str1.compare(str2) > 0) {
				m = j;
			}
		}
		name_temp = mainlist[i].name;
		num_temp = mainlist[i].number;
		for (int z = 0; z < 7; z++){
			arr_temp[z] = mainlist[i].rec[z];
		}

		mainlist[i].name = mainlist[m].name;
		mainlist[i].number = mainlist[m].number;
		for (int z = 0; z < 7; z++){
			mainlist[i].rec[z] = mainlist[m].rec[z];
		}
		mainlist[m].name = name_temp;
		mainlist[m].number = num_temp;
		for (int z = 0; z < 7; z++){
			mainlist[m].rec[z] = arr_temp[z];
		}
	}

	//reverse the sorted list if it is in descending order
	if (!order) {
		int start = 0;
		int ending = n - 1;
		while (start < ending) {
			name_temp = mainlist[start].name;
			num_temp = mainlist[start].number;
			for (int z = 0; z < 7; z++){
				arr_temp[z] = mainlist[start].rec[z];
			}

			mainlist[start].name = mainlist[ending].name;
			mainlist[start].number = mainlist[ending].number;
			for (int z = 0; z < 7; z++){
				mainlist[start].rec[z] = mainlist[ending].rec[z];
			}

			mainlist[ending].name = name_temp;
			mainlist[ending].number = num_temp;
			for (int z = 0; z < 7; z++){
				mainlist[ending].rec[z] = arr_temp[z];
			}

			start++;
			ending--;
		}
	}

	char answer = ' ';
	while ((answer != 'Y') && (answer != 'N')) {
		cout << "List sorted, replace the original file? (Y/N) ";
		cin >> answer;
		if (answer == 'Y') {
			ofstream fout;
			fout.open(filename.c_str());
			if (fout.fail()) {
				cout << "fail to open " << filename << endl;
				exit(1);
			}
			//writing the result into a file
			for (int i = 0; i < n; i++) {
				fout << mainlist[i].name << ' ' << mainlist[i].number << " ";
				if (mainlist[i].number <= 0)
					fout << "Out-of-stock" << endl;
				else
					fout << "In-stock" << endl;
			}
			fout.close();
			updater(mainlist,filename2,n);
		}
		else if (answer == 'N') {
			ofstream fout;
			fout.open("sorted list.txt");
			if (fout.fail()) {
				cout << "fail to open sorted list.txt" << endl;
				exit(1);
			}
			//writing the result into a file
			for (int i = 0; i < n; i++) {
				fout << mainlist[i].name << ' ' << mainlist[i].number << " ";
				if (mainlist[i].number <= 0)
					fout << "Out-of-stock" << endl;
				else
					fout << "In-stock" << endl;
			}
			fout.close();
		}
	}
}

//  sorting_data_number  :  sort data by number of stock of each item
//                          and ask for replacing the original file or not
//  input   :   list mainlist[] : the list to be sorted
//              int  n          : the number of items in mainlist[]
//              string filename : filename of the original file
//              bool order      : true = ascending order, false = descending order
//  cin     :   query for save as or replacing current file

void Tons_of_commands::sorting_data_number(list mainlist[], int n, string filename, bool order, string filename2) {
	string name_temp;
	int num_temp;
	int m;
	int arr_temp[7];
	//selection sort for the mainlist
	for (int i = 0; i < n - 1; i++) {
		m = i;
		for (int j = i + 1; j < n; j++) {
			int a = mainlist[m].number;
			int b = mainlist[j].number;
			if (a > b) {
				m = j;
			}
		}
		name_temp = mainlist[i].name;
		num_temp = mainlist[i].number;
		for (int z = 0; z < 7; z++){
				arr_temp[z] = mainlist[i].rec[z];
			}

		mainlist[i].name = mainlist[m].name;
		mainlist[i].number = mainlist[m].number;
		for (int z = 0; z < 7; z++){
				mainlist[i].rec[z] = mainlist[m].rec[z];
			}
		mainlist[m].name = name_temp;
		mainlist[m].number = num_temp;
		for (int z = 0; z < 7; z++){
				mainlist[m].rec[z] = arr_temp[z];
			}
	}
	//reverse the sorted list if it is in descending order
	if (!order) {
		int start = 0;
		int ending = n - 1;
		while (start < ending) {
			name_temp = mainlist[start].name;
			num_temp = mainlist[start].number;
			for (int z = 0; z < 7; z++){
				arr_temp[z] = mainlist[start].rec[z];
			}
			

			mainlist[start].name = mainlist[ending].name;
			mainlist[start].number = mainlist[ending].number;
			for (int z = 0; z < 7; z++){
				mainlist[start].rec[z] = mainlist[ending].rec[z];
			}

			mainlist[ending].name = name_temp;
			mainlist[ending].number = num_temp;
			for (int z = 0; z < 7; z++){
				mainlist[ending].rec[z] = arr_temp[z];
			}
			

			start++;
			ending--;
		}
	}

	char answer = ' ';
	while ((answer != 'Y') && (answer != 'N')) {
		cout << "List sorted, replace the original file? (Y/N) ";
		cin >> answer;
		if (answer == 'Y') {
			ofstream fout;
			fout.open(filename.c_str());
			if (fout.fail()) {
				cout << "fail to open " << filename << endl;
				exit(1);
			}
			//writing the result into a file
			for (int i = 0; i < n; i++) {
				fout << mainlist[i].name << ' ' << mainlist[i].number << " ";
				if (mainlist[i].number <= 0)
					fout << "Out-of-stock" << endl;
				else
					fout << "In-stock" << endl;
			}
			fout.close();
			updater(mainlist,filename2,n);
		}
		else if (answer == 'N') {
			ofstream fout;
			fout.open("sorted list.txt");
			if (fout.fail()) {
				cout << "fail to open sorted list.txt" << endl;
				exit(1);
			}
			//writing the result into a file
			for (int i = 0; i < n; i++) {
				fout << mainlist[i].name << ' ' << mainlist[i].number << " ";
				if (mainlist[i].number <= 0)
					fout << "Out-of-stock" << endl;
				else
					fout << "In-stock" << endl;
			}
			fout.close();
		}
	}
}

// adding_data  :   append data record to the file
// input :  string filename :   the file to be appended
//          list mainlist[] : the main list storing data
//          string name: the new appended item name
//          int num : the new appended item number
//          int n : the number of item inside mainlist

void Tons_of_commands::adding_data(string  filename,list mainlist[], string name,int num, int &n){
    ofstream fout;
    fout.open(filename.c_str(),ios::app);
    if (fout.fail()){
        cout << "fail to open "<<filename <<endl;
        exit(1);
    }
    fout << name << ' ' <<num <<endl;
    fout.close();
    mainlist[n].name = name;
    mainlist[n].number = num;
    for (int i = 0; i < n;i++)
		mainlist[n].rec[i] = 0;
	mainlist[n].rec[n] = num;
    n+=1;
}

// FilterByKeyword    :   search by keyword
// input : list mainlist[] : the main list storing data
//         list filtered[] : the list for storing filtered items
//         string keyword  : words containing keyword will be shown
//         int n           : number of items inside mainlist[]
// output :int             : number of items inside filtered[]

int Tons_of_commands::FilterByKeyword(list mainlist[], list filtered[], string keyword, int n) {
	//template for name in mainlist
	string temp;
	//number of items filtered
	int addcount = 0;
	for (int i = 0; i < n; i++) {
		temp = mainlist[i].name;
		if (((temp.find(keyword, 0)) < (temp.length())) && ((temp.find(keyword, 0)) >= 0)) {
			filtered[addcount].name = temp;
			filtered[addcount].number = mainlist[i].number;
			addcount++;
		}
	}
	return addcount;
}

// FilterByStarting   :   filter by starting letter
// input : list mainlist[] : the main list storing data
//         list filtered[] : the list for storing filtered items
//         char letter     : words starting with the letter will be shown
//                           (upper/lower case sensitive, support alphabets only)
//         int n           : number of items inside mainlist[]
// output :int             : number of items inside filtered[]

int Tons_of_commands::FilterByStarting(list mainlist[], list filtered[], char letter, int n) {
	//template for name in mainlist
	string temp;
	//number of items filtered
	int addcount = 0;
	//upper/lower case sensitive
	char alt_letter;
	if (letter >= 97)
		alt_letter = letter - 32;
	else
		alt_letter = letter + 32;
	//compare first character of every name to letter in mainlist
	for (int i = 0; i < n; i++) {
		temp = mainlist[i].name;
		if ((temp[0] == letter) || (temp[0] == alt_letter)) {
			filtered[addcount].name = temp;
			filtered[addcount].number = mainlist[i].number;
			addcount++;
		}
	}
	return addcount;
}

// FilterByNum   :   filter by stock number
// input : list mainlist[] : the main list storing data
//         list filtered[] : the list for storing filtered items
//         bool range      : true = search for items having num larger than x
//                           false = search for items having num smaller than x
//         int x           : compared to num of items in mainlist
//         int n           : number of items inside mainlist[]
// output :int addcount    : number of items inside filtered[]

int Tons_of_commands::FilterByNum(list mainlist[], list filtered[], bool range, int x, int n) {
	//number of items filtered
	int addcount = 0;
	//compare number to every name in mainlist
	for (int i = 0; i < n; i++) {
		if (((mainlist[i].number >= x) && (range)) || ((mainlist[i].number <= x) && (!range))) {
			filtered[addcount].name = mainlist[i].name;
			filtered[addcount].number = mainlist[i].number;
			addcount++;
		}
	}
	return addcount;
}

// Select : select an item from a filtered list and return the position of the
//          location of the selected item in mainlist[]
// intput : list chosen_list[] : a filtered list for operation
//          list mainlist[] : the list containing all data
//          int n : number of items inside mainlist[]
//          list &selected : the list item selected
// output : the location of the selected item in mainlist[]

int Tons_of_commands::select(list mainlist[], list chosen_list[], int n, int serial, list &selected) {
	//serial number of selected item
	selected = chosen_list[serial - 1];
	for (int i = 0; i < n; i++) {
		if (selected.name == mainlist[i].name)
			return i;
	}
	return -1;
}

//Deleting : delete an item from a list, items after the deleted one will shift forward
// input : list mainlist[] : the list containing all data
//         int location : the location of the selected item to be deleted in mainlist[]
//         int &n : number of items inside mainlist[]

void Tons_of_commands::deleting(list mainlist[], int location, int &n) {
	for (int i = location; i < n - 1; i++) {
		mainlist[i].name = mainlist[i + 1].name;
		mainlist[i].number = mainlist[i + 1].number;
		for (int z = 0; z < 7; z++){
				mainlist[i].rec[z] = mainlist[i+1].rec[z];
			}
		
	}
	mainlist[n - 1].name = char(0);
	mainlist[n - 1].number = 0;
	for (int z = 0; z < 7; z++){
				mainlist[n-1].rec[z] = 0;
		}
	n -= 1;
}

// Edit : change content of an item from a list
// input : list mainlist[] : the list containing all data
//         int location : the location of the selected item to be edited in mainlist[]
//         int n : number of items inside mainlist[]
//         string item_name : the new name of the selected item
//         int number : the new number of stock of the selected item

void Tons_of_commands::edit(list mainlist[], int location, int n, string item_name, int number) {
	for (int i = 0; i < n; i++) {
		if (i == location) {
			mainlist[i].name = item_name;
			mainlist[i].number = number;
			for (int z = 0; z < 7-1; z++){
				mainlist[i].rec[z] = 0;
			}
			mainlist[i].rec[7-1] = number;
		}
	}
}


// adding : add the number of stock of an item from a list
// input : list mainlist[] : the list containing all data
//         int location : the location of the selected item to be edited in mainlist[]
//         int add : the  number of stock to be added to the selected item

void Tons_of_commands::adding(list mainlist[], int location, int add) {
	if (mainlist[location].number + add > 0) {
		mainlist[location].number += add;
	}
	else
		if (mainlist[location].number + add <= 0) {
			mainlist[location].number = 0;
			cout << "Alert! " << mainlist[location].name << " is out-of-stock" << endl;
		}
	for (int i = 0; i < 7-1; i ++ ){
		mainlist[location].rec[i] =  mainlist[location].rec[i+1];
	}
	mainlist[location].rec[7-1] = mainlist[location].number;
}

//create_change : create change.txt for user to edit
void Tons_of_commands::create_change(list mainlist[], int n) {
	ofstream fout;
	fout.open("change.txt");
	if (fout.fail()) {
		cout << "fail to open change.txt" << endl;
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		fout << mainlist[i].name << ' ' << 0 << endl;
	}
	fout.close();
}

// change  : change the mainlist[] by adopting a change.txt file
// input   : list mainlist[] : the main list storing data being changed
void Tons_of_commands::change(list mainlist[]) {
	//number of lines in change.txt
	int n = itemcount("change.txt");
	list * changelist = new list[n];
	read_file2("change.txt", changelist);
	for (int i = 0; i < n; i++) {
		mainlist[i].number += changelist[i].number;
		for (int j = 0; j < 7-1; j ++ ){
			mainlist[i].rec[j] =  mainlist[i].rec[j+1];
		}
		mainlist[i].rec[7-1] = mainlist[i].number;
	}
	
}



// printlist : print a list out
// input :  list the_list :the list to be printed
//          int n : the number of items inside the list
void Tons_of_commands::printlist(list the_list[], int n) {
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". " << the_list[i].name << " : " << the_list[i].number << " ";
		if (the_list[i].number <= 0)
			cout << " : "<< "Out-of-stock" << endl;
		else
			cout << " : "<< "In-stock" << endl;
	}
}

// printlistr : print record.txt in specific format
// input :  list the_list :the list to be printed
//          int n : the number of items inside the list
void Tons_of_commands::printlistr(list the_list[], int n) {
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". " << the_list[i].name << " ";		
		for (int j = 0; j < 7; j++){
			cout << the_list[i].rec[j] << " ";
		}
		cout << endl;
	}
}
//calculate summation
double Tons_of_commands::summaty(int sumarr[],int n) {
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum = sum + sumarr[i];
	}
	return sum;
}
//calculate summation
double Tons_of_commands::summatxx(int sumarr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum = sum + (i+1)*(i+1);
	}
	return sum;
}
//calculate summation
double Tons_of_commands::summatxx(int sumarr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum = sum + (i+1)*(i+1);
	}
	return sum;
}
double Tons_of_commands::summatxy(int sumarr1[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum = sum + sumarr1[i]*(i+1);
	}
	return sum;
}
//calculate summation
double Tons_of_commands::summatx(int n){
    int sum = 0;
    for (int i = 1; i < n+1; i++){
        sum += i;
    }
    return sum;
}
//calculate least square method
double Tons_of_commands::lsm(int arr[], int n) {
	double bx, bc, x, y, xy, xx;
	xy = summatxy(arr, n);
	xx = summatxx(arr, n);
	x = summatx(n)/n;
	y = summaty(arr, n)/n;
	bx = (xy-n*x*y)/(xx-n*x*x);
	bc = y- bx*x;
	cout << bx << " "<< bc;
	return 0;
}
