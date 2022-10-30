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
    string name, team;
    int lap1, lap2, lap3;
    
    for (int i =1; i <= totalRunner("Result.txt"); i++)
    {
        name = readName(infile);
        team = readName(infile);
        lap1= readTime(infile);
        lap2= readTime(infile);
        lap3= readTime(infile);
        
        
        if (1==1)
        {
            total1 =(total1+ lap1);
            total2 =(total2+ lap2);
            total3 =(total3+ lap3);
        }
        
        
    }
//    if ( lap1 < total1/9)
//    {
//        below += name + " ";
//    }
//    else
//        above += name + " ";
//    if ( lap2 < total2/9)
//    {
//        below += name + " ";        }
//    else
//        above += name + " ";
//    if ( lap3 < total3/9)
//    {
//        below += name + " ";        }
//    else
//        above += name + " ";
    
    
    //cout << total1<< " " << total2 << " "<< total3 << endl;
   
    cout <<"Avg-lap1: "<< (total1/totalRunner("Result.txt"))/60<< ":"<<(total1/totalRunner("Result.txt"))%60<< "s"<< endl;
    

    cout <<"Avg-lap2: "<< (total2/totalRunner("Result.txt"))/60<< ":"<<(total2/totalRunner("Result.txt"))%60<< "s"<< endl;
    cout <<"Avg-lap3: "<< (total3/totalRunner("Result.txt"))/60<< ":"<<(total3/totalRunner("Result.txt"))%60<< "s"<< endl;

    cout << " ---------------------------------------------------------------"<< endl;
    
    
    


}


void object3(int heat) {
    cout << "OBJECT 3:" << endl;
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
    
   
    string below = "Below :";
    string above = "Abvove :";
    string name, team;
    int lap1, lap2, lap3;
    
    cout << "Lap" << setw(15) << "1"<< setw(10)<< "2"<< setw(10)<< "3" << endl;
    for (int i =1; i <= totalRunner("Result.txt"); i++)
    {
        name = readName(infile);
        team = readName(infile);
        lap1= readTime(infile);
        lap2= readTime(infile);
        lap3= readTime(infile);
        
        cout <<setw(8)<< name << setw(10)<< lap1/60 << ":"<< lap1%60<< setw(7)<< lap2/60 << ":"<< lap2%60<<setw(7)<< lap3/60 << ":"<< lap3%60<<endl;
        
        //cout << lap1 << " " << lap2 << " "<< lap3 << endl;
        
        
        if (lap1<lap2 )
            cout<<setw(28)<< "+"<<(lap2-lap1);
        else
            cout<<setw(28)<< "-"<<( lap1-lap2);
        if (lap2<lap3 )
            cout<<setw(9)<< "+"<< lap3-lap2<< endl;
        else
            cout<<setw(9)<< "-"<< lap2-lap3<<endl;
            
    }
    cout << " ---------------------------------------------------------------"<< endl;
    
}




void object4(int heat) {
    cout << "OBJECT 4:" << endl;
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
    
    string redTeam = " ";
    string blueTeam = " ";
    string greenTeam = " ";
    
    int red1 = 999;
    string redplace1= "";
    int red2 = 999;
    string redplace2 = "";
    int red3 = 999;
    string redplace3 = "";

    
    int blue1 = 999;
    string blueplace1= "";
    int blue2 = 999;
    string blueplace2 = "";
    int blue3 = 999;
    string blueplace3 = "";
    
    
    int g1 = 999;
    string gplace1= "";
    int g2 = 999;
    string gplace2 = "";
    int g3 = 999;
    string gplace3 = "";

    
    for (int i =1; i <= totalRunner("Result.txt"); i++)
    {
        string name = readName(infile);
        string team = readName(infile);
        
        int time1= readTime(infile);
        int time2= readTime(infile);
        int time3= readTime(infile);
        int total = time1 + time2 + time3;
       
        
        if (team == "Red")
        {
            if (total < red1)
            {
                red3 = red2;
                redplace3= redplace2;
                red2 = red1;
                redplace2= redplace1;
                red1 = total;
                redplace1 = name;
                
            }
            else if (total < red2)
            {
                redplace3 = redplace2;
                red3= red2;
                red2 = total;
                redplace2 = name;
            }
            else if (total < red3)
            {
                redplace3 = total;
                redplace3 = name;
            }
            
            
        }
        
        
        
        if (team == "Blue")
        {
            if (total < blue1)
            {
                blue3 = blue2;
                blueplace3= blueplace2;
                blue2 = blue1;
                blueplace2= blueplace1;
                blue1 = total;
                blueplace1 = name;
                
            }
            else if (total < blue2)
            {
                blueplace3 = blueplace2;
                blue3= blue2;
                blue2 = total;
                blueplace2 = name;
            }
            else if (total < blue3)
            {
                blue3 = total;
                blueplace3 = name;
            }
            
            
        }
        
        
        if (team == "Green")
        {
            if (total < g1)
            {
                g3 = g2;
                gplace3= gplace2;
                g2 = g1;
                gplace2= gplace1;
                g1 = total;
                gplace1 = name;
                
            }
            else if (total < g2)
            {
                gplace3 = gplace2;
                g3= g2;
                g2 = total;
                gplace2 = name;
            }
            else if (total < g3)
            {
                g3 = total;
                gplace3 = name;
            }
            
            
        }
        
        
        
    }
    cout << "Red: " << redplace1 << " "<< redplace2<< " " << redplace3<<", Overall time: " << (red1+red2+red3)/3/60 << ":" << (red1+red2+red3)/3%60 << "s (avg)"<< endl;
    cout << "Blue: " << blueplace1 << " "<< blueplace2<< " " << blueplace3<<", Overall time: " << (blue1+blue2+blue3)/3/60 << ":" << (blue1+blue2+blue3)/3%60 << "s (avg)"<< endl;
    cout << "Green: " << gplace1 << " "<< gplace2<< " " << gplace3<<", Overall time: " << (g1+g2+g3)/3/60 << ":" << (g1+g2+g3)/3%60 << "s (avg)"<< endl;

   
    cout << " ---------------------------------------------------------------"<< endl;
}










int main ()
{
   // cout << totalRunner("Result.txt")<<endl;
    object1(1);
    object1(2);

    object2(1);
    object2(2);
    
    object3(1);
    object3(2);
    
    object4(1);
    object4(2);

    

    }




