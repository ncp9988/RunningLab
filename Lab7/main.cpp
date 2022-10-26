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

string readName ( string firstName, string lastName );
int readTime ( int minute, int second );



int main() {
    ifstream infile;
    infile.open("Result.txt");
    string line;
    getline(infile, line);
    string name = readName(infile);
    string team = readName(infile);
    
    

    
    return 0;
}

string readName ( ifstream&infile )
{
    int minute, second;
    string firstName;
    infile >> firstName;
    return firstName;
}

int readTime (ifstream&infile)
{
    int minute, second;
    string header;
    getline(infile, header);
    string firsName, team;
    getline (infile, firstName);
    getline (infile, team);
    infile >> minute;
    infile.ignore(10, ':');
    infile>> second;
    return minute*60+second;

    

    return 0;
}
