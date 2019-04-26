#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//*******************************//
//
//please delete the dynamic struct array at the end
//

// printlist : print a list out
// input :  list the_list :the list to be printed
//          int n : the number of items inside the list

//the list for products
//name: the name of product
//number: the number of products
struct list{
    string name;
    int number;
};

// itemcount : count items inside the data base
// input : string filename : the file storing the data base
//output : number of items inside the data base

int itemcount(string filename){
    string useless;
    int count =0;
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail()){
        cout << "No such file exist!" <<endl;
        exit(1);
    }
    while (getline(fin,useless)){
        count++;
    }
    fin.close();
    return count;
}

//  read_file : reading the main file containing all data
//              used to update the list too
//  and save data inside an array
//  input : string filename : the name of the file
//          list mainlist   : the list for storing
//  output : int count : the number of items inside array

int read_file(string filename, list mainlist[]){
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



//  sorting_data  :   sort data in alphabetic order and output to a file (not case sensitive)
//                    and ask for replacing the original file or not
//  input   :   list mainlist[] : the list to be sorted
//              int  n          : the number of items in mainlist[]
//              string filename : filename of the original file
//  cin     :   query for save as or replacing current file

void sorting_data(list mainlist[], int n, string filename){
    string name_temp;
    int num_temp;

    //selection sort for the mainlist
    int m;
    for (int i=0; i<n-1; i++){
        m=i;
        for  (int j=i+1; j < n; j++){
            string str1 =mainlist[m].name;
            string str2 =mainlist[j].name;
            if (str1.compare(str2)>0){
                m=j;
            }
        }
        name_temp=mainlist[i].name;
        num_temp=mainlist[i].number;

        mainlist[i].name=mainlist[m].name;
        mainlist[i].number=mainlist[m].number;
        mainlist[m].name=name_temp;
        mainlist[m].number=num_temp;
    }
    char answer=' ';
    while ((answer != 'Y')&&(answer != 'N')){
        cout << "List sorted, replace the original file? (Y/N) ";
        cin >> answer;
        if (answer == 'Y'){
            ofstream fout;
            fout.open(filename.c_str());
            if (fout.fail()){
                cout << "fail to open "<<filename <<endl;
                exit(1);
            }
            //writing the result into a file
            for (int i=0; i<n; i++){
                fout << mainlist[i].name << ' ' << mainlist[i].number << endl;
            }
            fout.close();
        }
        else if(answer == 'N'){
            ofstream fout;
            fout.open("sorted list.txt");
            if (fout.fail()){
                cout << "fail to open sorted list.txt" <<endl;
                exit(1);
            }
            //writing the result into a file
            for (int i=0; i<n; i++){
                fout << mainlist[i].name << ' ' << mainlist[i].number << endl;
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

void sorting_data_number(list mainlist[], int n, string filename, bool order){
    string name_temp;
    int num_temp;
    int m;
    //selection sort for the mainlist
    for (int i=0; i<n-1; i++){
        m=i;
        for  (int j=i+1; j < n; j++){
            int a=mainlist[m].number;
            int b=mainlist[j].number;
            if (a>b){
                m=j;
            }
        }
        name_temp=mainlist[i].name;
        num_temp=mainlist[i].number;

        mainlist[i].name=mainlist[m].name;
        mainlist[i].number=mainlist[m].number;
        mainlist[m].name=name_temp;
        mainlist[m].number=num_temp;
    }
    //reverse the sorted list if it is in descending order
    if (!order){
        cout << "order!" <<endl;
        int start=0;
        int ending=n-1;
        while(start < ending){
            name_temp=mainlist[start].name;
            num_temp=mainlist[start].number;

            mainlist[start].name=mainlist[ending].name;
            mainlist[start].number=mainlist[ending].number;

            mainlist[ending].name=name_temp;
            mainlist[ending].number=num_temp;

            start++;
            ending--;
        }
    }

    char answer=' ';
    while ((answer != 'Y')&&(answer != 'N')){
        cout << "List sorted, replace the original file? (Y/N) ";
        cin >> answer;
        if (answer == 'Y'){
            ofstream fout;
            fout.open(filename.c_str());
            if (fout.fail()){
                cout << "fail to open "<<filename <<endl;
                exit(1);
            }
            //writing the result into a file
            for (int i=0; i<n; i++){
                fout << mainlist[i].name << ' ' << mainlist[i].number << endl;
            }
            fout.close();
        }
        else if(answer == 'N'){
            ofstream fout;
            fout.open("sorted list.txt");
            if (fout.fail()){
                cout << "fail to open sorted list.txt" <<endl;
                exit(1);
            }
            //writing the result into a file
            for (int i=0; i<n; i++){
                fout << mainlist[i].name << ' ' << mainlist[i].number << endl;
            }
            fout.close();
        }
    }
}

// adding_data  :   append data record to the file and update the main list
// input :  string filename :   the file to be appended
//          list mainlist[] : the main list storing data
//          string name: the new appended item name
//          int num : the new appended item num

 void adding_data(string  filename,list mainlist[], string name,int num){
    ofstream fout;
    fout.open(filename.c_str(),ios::app);
    if (fout.fail()){
        cout << "fail to open "<<filename <<endl;
        exit(1);
    }
    fout << name << ' ' <<num <<endl;
    read_file(filename,mainlist);
    fout.close();
}

// FilterByKeyword    :   search by keyword
// input : list mainlist[] : the main list storing data
//         list filtered[] : the list for storing filtered items
//         string keyword  : words containing keyword will be shown
//         int n           : number of items inside mainlist[]
// output :int             : number of items inside filtered[]

int FilterByKeyword(list mainlist[],list filtered[], string keyword, int n){
    //template for name in mainlist
    string temp;
    //number of items filtered
    int addcount=0;
    for (int i=0; i<n; i++){
        temp = mainlist[i].name;
        if (((temp.find(keyword,0))<(temp.length()))&&((temp.find(keyword,0))>=0)){
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

int FilterByStarting(list mainlist[],list filtered[], char letter, int n){
    //template for name in mainlist
    string temp;
    //number of items filtered
    int addcount=0;
    //upper/lower case sensitive
    char alt_letter;
    if (letter>=97)
        alt_letter=letter-32;
    else
        alt_letter=letter+32;
    //compare first character of every name to letter in mainlist
    for (int i=0; i<n; i++){
        temp = mainlist[i].name;
        if ((temp[0]==letter)||(temp[0]==alt_letter)){
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

int FilterByNum(list mainlist[],list filtered[], bool range,int x, int n){
    //number of items filtered
    int addcount=0;
    //compare number to every name in mainlist
    for (int i=0; i<n; i++){
        if (((mainlist[i].number >= x)&&(range))||((mainlist[i].number <= x)&&(!range))){
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

int select(list mainlist[], list chosen_list[], int n,int serial, list &selected){
    //serial number of selected item
    selected = chosen_list[serial-1];
    for (int i=0; i<n; i++){
        if (selected.name==mainlist[i].name)
            return i;
    }
    return -1;
}

//Deleting : delete an item from a list, items after the deleted one will shift forward
// input : list mainlist[] : the list containing all data
//         int location : the location of the selected item to be deleted in mainlist[]
//         int &n : number of items inside mainlist[]

void deleting(list mainlist[], int location, int &n){
    for (int i=location; i<n-1; i++){
        mainlist[i].name=mainlist[i+1].name;
        mainlist[i].number=mainlist[i+1].number;
    }
    mainlist[n-1].name = char(0);
    mainlist[n-1].number = 0;
    n-=1;
}

// Edit : change content of an item from a list
// input : list mainlist[] : the list containing all data
//         int location : the location of the selected item to be edited in mainlist[]
//         int n : number of items inside mainlist[]
//         string item_name : the new name of the selected item
//         int number : the new number of stock of the selected item

void edit(list mainlist[], int location, int n, string item_name, int number){
    for (int i=0; i<n; i++){
        if (i==location){
            mainlist[i].name=item_name;
            mainlist[i].number=number;
        }
    }
}

// adding : add the number of stock of an item from a list
// input : list mainlist[] : the list containing all data
//         int location : the location of the selected item to be edited in mainlist[]
//         int add : the  number of stock to be added to the selected item

void adding(list mainlist[], int location, int add){
        mainlist[location].number+=add;
    }

// update : update the file, usually used after adding, editing or deleting data
// input : list mainlist[] : the list containing all data
//         string filename : the file name saving the updated mainlist[]
//         int n : number of items inside mainlist[]

void update(list mainlist[], string filename, int n){
    //open the file for overwriting the old version
    ofstream fout;
    fout.open(filename.c_str());
    if (fout.fail()){
        cout << "fail to open "<<filename <<endl;
        exit(1);
    }
    for (int i=0; i<n; i++){
        fout << mainlist[i].name << ' ' << mainlist[i].number << endl;
    }
    fout.close();
}
//create_change : create change.txt for user to edit
void create_change(list mainlist[], int n){
    ofstream fout;
    fout.open("change.txt");
    if (fout.fail()){
        cout << "fail to open change.txt"<<endl;
        exit(1);
    }
    for (int i=0; i<n; i++){
        fout << mainlist[i].name << ' ' <<endl;
    }
    fout.close();
}

// change  : change the mainlist[] by adopting a change.txt file
// input   : list mainlist[] : the main list storing data being changed
void change(list mainlist[]){
    //number of lines in change.txt
    int n=  itemcount("change.txt");
    list * changelist = new list[n];
    read_file("change.txt",changelist);
    for (int i=0; i<n; i++){
        mainlist[i].number+=changelist[i].number;
    }
}


void printlist(list the_list[], int n){
    for (int i=0; i<n; i++){
        cout << i+1 << ". " <<the_list[i].name << " : " << the_list[i].number << endl;
    }
}


int main(){
    int n= itemcount("dalist.txt");
    int filter_length;
    string keyword;
    char kw;
    int x,y, seletcted;
    list * mainlist = new list[n];
    list * SearchResult = new list[n];
    list specific_list;
    n=read_file("dalist.txt", mainlist);
    printlist(mainlist, n);
    cout << "--------" <<endl;

    int command=0;
    while (command!=7){
    cout << "************************************************************************"<<endl;
    cout << "The current list is as above, select a command to operate:             *"<<endl;
    cout << "1. search data                                                         *"<<endl;
    cout << "2. change and update the data                                          *"<<endl;
    cout << "3. sort the data                                                       *"<<endl;
    cout << "4. append new data                                                     *"<<endl;
    cout << "5. show the list of data                                               *"<<endl;
    cout << "6. predict demand in the future                                        *"<<endl;
    cout << "7. EXIT                                                                *" <<endl;
    cout << "************************************************************************"<<endl;
    cout << "->Enter your great command here : ";
    cin >> command;
    switch (command){
    case 1:
        cout << "Please choose which kind of search to undergo: (1, 2, 3)"<<endl;
        cout << "1. search by keyword" <<endl;
        cout << "2. search by starting letter" <<endl;
        cout << "3. search by number of stocks" <<endl;
        int command1;
        cin >> command1;
        switch (command1){
        case 1:
            cout << "Enter the keyword for searching : ";
            cin >>keyword;
            filter_length = FilterByKeyword(mainlist, SearchResult, keyword, n);
            break;
        case 2:
            cout << "Enter the keyword for searching : ";
            cin >>kw;
            filter_length = FilterByStarting(mainlist, SearchResult, kw, n);
            break;
        case 3:
            cout << "Enter the number x of stock for searching : ";
            cin >>x;
            cout << "1. Search for items >=x"<<endl;
            cout << "2. Search for items <=x"<<endl;
            bool choice;
            cin >> y;
            if (y==1){
                choice=true;
            }
            else if(y==2){
                choice=false;
            }
            else{
                break;
            }
            filter_length = FilterByNum(mainlist, SearchResult, choice, x, n);
            break;
        default: continue;
        }
        if (filter_length==0){
            cout << "No result found" <<endl;
        }
        else{
            cout << "----------|Search result|----------"<<endl;
            printlist(SearchResult,filter_length);
            cout << "-----------------------------------"<<endl;
            cout << "Enter -1 to continue or choose an item to undergo operation : (1-" << filter_length<<")" <<endl;
            cin >>x;
            if (x>filter_length){
                continue;
            }
            else{
                seletcted=select(mainlist, SearchResult, n, x, specific_list);
                cout << "Select which kind of operation to undergo: "<<endl;
                cout << "1. Delete the item" << endl;
                cout << "2. Edit the item" <<endl;
                cout << "3. change the amount of item"<<endl;
                cin >> y;
                switch (y){
                case 1:
                    deleting(mainlist, seletcted, n);
                    break;
                case 2:

                    edit(mainlist,seletcted, n, )
                }
            }
        }
        cout << endl;
        break;
    case 2:


    }
    }
    return 0;
}
