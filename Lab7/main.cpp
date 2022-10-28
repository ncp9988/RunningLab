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
    cout << "OBJECT 1:" << endl;
    cout << " " << endl;

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
    cout << "1st: " <<place1 << ", 2nd: "<< place2 <<" 3rd: "<< place3<<endl;
    cout << " ---------------------------------------------------------------"<< endl;
}



void object2(int heat) {
    cout << "OBJECT 2:" << endl;
    cout << " " << endl;

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
    
    int total1 = 0;
    int total2 = 0;
    int total3 = 0;
    string below = "Below :";
    string above = "Abvove :";

    
    for (int i =1; i <= totalRunner("Result.txt"); i++)
    {
        string name = readName(infile);
        string team = readName(infile);
        int lap1= readTime(infile);
        int lap2= readTime(infile);
        int lap3= readTime(infile);
        
        if (1==1)
        {
            total1 =(total1+ lap1);
            total2 =(total2+ lap2);
            total3 =(total3+ lap3);
            
        }
        
        
    }
    cout << total1<< " " << total2 << " "<< total3 << endl;
   
    

    cout <<"Avg-lap1: "<< (total1/totalRunner("Result.txt"))/60<< ":"<<(total1/totalRunner("Result.txt"))%60<< "s"<< endl;
    

    cout <<"Avg-lap2: "<< (total2/totalRunner("Result.txt"))/60<< ":"<<(total2/totalRunner("Result.txt"))%60<< "s"<< endl;
    cout <<"Avg-lap3: "<< (total3/totalRunner("Result.txt"))/60<< ":"<<(total3/totalRunner("Result.txt"))%60<< "s"<< endl;

    cout << " ---------------------------------------------------------------"<< endl;
}


//if ( lap1 < total1)
//{
//    below += name + " ";
//}
//else
//    above += name + " ";
//if ( lap2 < total2)
//{
//    below += name + " ";        }
//else
//    above += name + " ";
//if ( lap3 < total3)
//{
//    below += name + " ";        }
//else
//    above += name + " ";


cout << below << endl;
//cout << above << endl;


int main ()
{
   // cout << totalRunner("Result.txt")<<endl;
    object1(1);
    object1(2);

    object2(1);
    object2(2);

    }




