# OsProject2BankerAlgorithm

Kevin Coran Operating Systems Project 2

The goal for this assignment to implement the banker's algorithm with a custom input file format.\
The bankers algorithm is used to allocate resources and prevent deadlock.\
It assures that the processes do not take more than is allowed and makes a safe sequence to execute.\
The code is compiled and run by the following commands:\
$g++ banker.cpp\
$./a.out

Expected Output:


![image](https://user-images.githubusercontent.com/73201894/143979830-25f65f7b-5574-4718-8a48-f1ddcd82456b.png)



I used the same environment as the previous project: Ubuntu virtual machine running vscode\
The only difference being that I did this project using c++ instead of c

The first problem was coming up with an input format.\
I decided that the first line would be the processes followed by the resources\
Then i input the allocation and max matrices with spaces in between and new lines between others.\
After inputting the file, It was down to implementing the actual algorithm.
