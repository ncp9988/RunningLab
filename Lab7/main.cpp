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


int totalRunner (string fileName)
{
    ifstream infile;
    infile.open(fileName);
    string line;
    int x =0;
    while (true)
    {
        getline (infile, line);
        if (line == "Heat 2:")
            break;
        x++;
    }
    return x-2;
}

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
        string runner;
        for (int i =0; i <= totalRunner("Result.txt")+1 ; i++)
            getline(infile, runner);
        
        cout << "Heat 2:"<< endl;
    };
    
    
    int place1time = 999;
    string place1 = "";
    int place2time = 999;
    string place2 = "";
    int place3time = 999;
    string place3 = "";
    
    
    for (int i =1; i <= totalRunner("Result.txt"); i++)
    {
        string name = readName(infile);
        string team = readName(infile);
        
        int time1= readTime(infile);
        int time2= readTime(infile);
        int time3= readTime(infile);
        int total =time1 + time2 + time3;
       
        cout << name << " "<< team <<" "<< total<< " s" <<endl;
        
        
        if (total < place1time)
        {
            place3time = place2time;
            place3= place2;
            place2time = place1time;
            place2= place1;
            place1time = total;
            place1 = name + team;
            
        }
        else if (total < place2time)
        {
            place3time = place2time;
            place3= place2;
            place2time = total;
            place2 = name + team;
        }
        else if (total < place3time)
        {
            place3time = total;
            place3 = name + team;
        }
    }
    cout << " "<< endl;

    cout << "1st: " <<place1 << ", 2nd "<< place2 <<" 3rd "<< place3<<endl;
    cout << " "<< endl;


}







int main ()
{
    cout << totalRunner("Result.txt")<<endl;
    object1(1);
    object1(2);

    //object2(1);
    }




