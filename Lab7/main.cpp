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


int main() {
    string firstName, lastName;
    
    cout <<readName (firstName,lastName )<< endl;;


    return 0;
}

string readName ( string firstName, string lastName )
{
    ifstream infile;
    infile.open ("Result.txt");
    string header;
    infile >> header;
    getline(infile, header);
    infile >> firstName >> lastName;
    cout << firstName << " "<< lastName<< endl;
    return 0;
}


