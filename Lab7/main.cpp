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
    {
        getline(infile, line);
        cout << "Heat 1:"<< endl;
        
    }
    else
    {
        getline(infile, line);
//        getline(infile, line);
//        getline(infile, line);
//        getline(infile, line);
//        getline(infile, line);
//        getline(infile, line);
//        getline(infile, line);
//        getline(infile, line);
//        getline(infile, line);
//        getline(infile, line);
//        getline(infile, line);
//        getline(infile, line);

        cout << "Heat 2:"<< endl;
        
    };
    for (int i =1; i <= 21; i++)
    {
        string name = readName(infile);
        string team = readName(infile);
        
        int time1= readTime(infile);
        int time2= readTime(infile);
        int time3= readTime(infile);
        
        cout << name << " "<< team <<" "<< (time1 + time2 + time3)<< " s" <<endl;
    }
    
}

int main ()
{
    
        object1(1);
    
    }




