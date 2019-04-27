#ifndef TONS_OF_COMMANDS_H
#define TONS_OF_COMMANDS_H

#include "Tons_of_commands.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//the list for products
//name: the name of product
//number: the number of products
struct list {
	string name;
	int number;
	int rec[7];
};

class Tons_of_commands
{

    public:
        Tons_of_commands();
        void printlistr(list the_list[], int n);
        void printlist(list the_list[], int n);
        void updater(list mainlist[], string filename, int n);
        void change(list mainlist[]);
        void create_change(list mainlist[], int n);
        void update(list mainlist[], string filename, int n);
        void adding(list mainlist[], int location, int add);
        void edit(list mainlist[], int location, int n, string item_name, int number);
        void deleting(list mainlist[], int location, int &n);
        int select(list mainlist[], list chosen_list[], int n, int serial, list &selected);
        int FilterByNum(list mainlist[], list filtered[], bool range, int x, int n);
        int FilterByStarting(list mainlist[], list filtered[], char letter, int n);
        int FilterByKeyword(list mainlist[], list filtered[], string keyword, int n);
        void adding_data(string  filename,list mainlist[], string name,int num, int &n);
        void sorting_data_number(list mainlist[], int n, string filename, bool order);
        void sorting_data(list mainlist[], int n, string filename, bool order);
        void alertcheck(list mainlist[]);
        int read_file2(string filename, list mainlist[]);
        int read_file(string filename, list mainlist[]);
        int itemcount(string filename);


    protected:

    private:
};

#endif // TONS_OF_COMMANDS_H
