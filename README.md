# engg1340group8
Project idea:
2. Commodity inventory system (Marco)
 
**Problem statement:**

Issue statement:
Using traditional methods (paper & manpower) to manage stock information is expensive, inefficient, unreliable. Using software system can remedy these disabilities of traditional methods.

Vision:
Software system can provide sustainability and reliability. The status or information of the commodities would be clearly stated(by method of graphs or statistical data). The managers of the shops can make decision easily, accurately and also to speed up working process.

Method:
To solve the problem, the system will include the following elements: file input and output, sorting data records, searching data records, adding data records, editing data records and deleting data records.  

In practical, the program is expected to adopt filters to search for commodity, append new commodity data, delete obsolete commodity data , update commodity data, which prompts a better inventory management.  Also, inventory status will alerts when it is nearly “out-of-stock” or when it is currently “out-of-stock” in order to prevent a short in commodity.

Assumption:
1. If there is a change in all amount of all types of data, user need to input the change in amount in change.txt
2. The maximum ammount of types of commedity is limited within 100.
3. Inputs are in valid data type, invalid inputs with corect datatype will be skipped and the program will be recursed.
4. A basic commedity txt document containing some data exist.
5. (record).txt(for record) and (data).txt(for data) must be prepared before running the code.
6. The txt file containing the current data is not named as "change.txt" or "record.txt".  These two file name will be used by some features.
7. the order and number of items in text files of record.txt, data.txt and change.txt should be the same. The samples are shown below:  
 _**(data).txt(for data) samples**  
pen 0 Out-of-stock  
apple 468 In-stock  
orange 6 In-stock  
applepie 594 In-stock  
bucket 522 In-stock  
candy 528 In-stock  
sugar 84 In-stock  
rubber 540 In-stock  
pencil 3402 In-stock  
book 0 Out-of-stock  
towel 270 In-stock_   
 _**(record).txt(for record) sample**  
pen 21 58 34 54 64 78 0  
apple 0 21 58 34 54 64 468  
orange 5 10 70 20 80 86 6  
applepie 56 213 60 324 521 307 594  
bucket 60 180 70 600 230 250 522  
candy 70 600 230 250 546 300 528  
sugar 80 69 90 100 90 56 84  
rubber 10 260 700 685 230 456 540  
pencil 506 900 3045 6245 3000 2300 3402  
book 15 70 45 60 50 78 0  
towel 45 678 540 640 135 200 270_   
 _**change.txt (for changing) sample**  
pen 0  
apple 468  
orange 6  
applepie -3  
bucket 522  
candy 528  
sugar 84  
rubber -6  
pencil 3402  
book 0  
towel 270_   




**Problem setting:**
With an increasing demand in renowned bands, an inventory with inventory with abundant commodity is crucial.  To meet the target, a reliable, efficient and multifunctioning inventory system is needed.  Under the control and management of the system, profit can be maximized and unwanted waste, say, exceed stock, can be reduced.  To meet the demand, a commodity inventory system is being developed.

**basic program features introduction:**
In the beginning of the program, user can select 6 commands to operate.  The 7th command means to leave the program.  The commands are as follow:

1. Search data:
   data can be searched by 3 methods: 
      search by a keyword,
      search by a the starting letter,
      search by number of commedities (either larger or smaller than the inputted value)
   The user can locate a commedity type in the search result list and do 3 operations on it:
      delete the located commedity,
      edit the located commedity (both in the name of the  commedity and amount of the commedity)
      add number of the type of the located commedity

2. Change in all data:
   A change.txt will be provided to the user to input changes in different kinds of commedities.   After that, the the original file containing data will commit changes in all data and rewrite the original txt file.
   
3. Sorting of data:
   The program can sort data in both ascending and descending order, alphabetic order (base on the item ) and numeric order (base on the number of stocks).  Used can decide to rewrite the original data txt by the sorted one or create a new txt file named "sorted.txt" to save the sorted result.  (The sorted.txt will be rewritted if another sorting is proceeded)

4. Append new data:
   If the user forget to input some data, they can append a new data to the data txt.  The data base will update immediately after the amendment.
   
5. Showing the data
   The program will show both the current data and past records.  Difference in data saving in the program and data saving in txt won't have any difference during program compilation.
   
**Extra program feature(s):**
1. The data base (the txt file containing all data) will update immediately after any amendment.
2. Fours types of sorting are provided, the sorted data can either rewrite the original data file or being presented in another file (sorted.txt).
3. Past data records (up to the 7th last editted record) can be traced
4. Data is managed as fast as possible as the sorting functions used the selection sort
