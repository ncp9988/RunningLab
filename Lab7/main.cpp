//
//  main.cpp
//  Lab7
//
//  Created by Chau Pham on 10/24/22.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string readName ( ifstream&infile )
{
    string firstName;
    infile >> firstName;
    return firstName;
}

int readTime (ifstream&infile)
{
    int minute, second;
    infile >> minute;
    infile.ignore(10, ':');
    infile>> second;
    return minute*60+second;

    
}

void object1(int heat) {
    ifstream infile;
    infile.open("Result.txt");
    string line;
    if (heat==1)
        getline(infile, line);
    else ;
    string name = readName(infile);
    string team = readName(infile);
    
    int time1= readTime(infile);
    int time2= readTime(infile);
    int time3= readTime(infile);

    cout << name << " "<< team <<" "<< (time1 + time2 + time3)<< " s" <<endl;
    
    //return 0;
}

int main ()
{
    object1(heat=1);
}




