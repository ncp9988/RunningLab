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
ifstream infile;


int smaller (int x, int y)
{
    if (x <y)
    return x;
    return y;
}
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

int getRunnerTime ( string name, int heatNumber)
{
    string line;
    if (heatNumber==1)
    {
       // getline(infile, line);
        name = readName(infile);
        string team = readName(infile);
        
        int time1= readTime(infile);
        int time2= readTime(infile);
        int time3= readTime(infile);
        int total =time1 + time2 + time3;
        
        return total;

    }
    else
    {
       // getline(infile, line);
        string runner;
        for (int i =0; i <= totalRunner("Result.txt")+1 ; i++)
            getline(infile, runner);
        name = readName(infile);
        string team = readName(infile);
        
        int time1= readTime(infile);
        int time2= readTime(infile);
        int time3= readTime(infile);
        int total =time1 + time2 + time3;
        return total;

    }
    
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







void object5(int heat) {
    cout << "OBJECT 5:" << endl;
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
    
    
    
    
    int Rresult1=0;
    int Rresult2=0;
    int Rresult3=0;
    int Rresult4=0;
    int Rresult5=0;
    int Rresult6=0;
    
    string Rstring1="";
    string Rstring2="";
    string Rstring3="";
    string Rstring4="";
    string Rstring5="";
    string Rstring6="";


    
    
    int Bresult1=0;
    int Bresult2=0;
    int Bresult3=0;
    int Bresult4=0;
    int Bresult5=0;
    int Bresult6=0;
    
    string Bstring1="";
    string Bstring2="";
    string Bstring3="";
    string Bstring4="";
    string Bstring5="";
    string Bstring6="";
    
    int Gresult1=0;
    int Gresult2=0;
    int Gresult3=0;
    int Gresult4=0;
    int Gresult5=0;
    int Gresult6=0;
    
    string Gstring1="";
    string Gstring2="";
    string Gstring3="";
    string Gstring4="";
    string Gstring5="";
    string Gstring6="";


    string team;
    
    for (int i =1; i <= totalRunner("Result.txt"); i++)
    {
        string name = readName(infile);
        string team = readName(infile);
        
        int lap1= readTime(infile);
        int lap2= readTime(infile);
        int lap3= readTime(infile);
       
        if ( team == "Red")
        {
            if ( name == "Ayako")
            {
                Rresult1 += lap1;
                Rresult2 += lap1;
                Rresult3 += lap2;
                Rresult4 += lap2;
                Rresult5 += lap3;
                Rresult6 += lap3;
                
                Rstring1= "Ayako(lap1)  ";
                Rstring2= "Ayako(lap1)  ";
                Rstring3= "Ayako(lap2)  ";
                Rstring4= "Ayako(lap2)  ";
                Rstring5= "Ayako(lap3)  ";
                Rstring6= "Ayako(lap3)  ";
            }
            if ( name == "Mallory" )
            {
                Rresult1 += lap2;
                Rresult2 += lap3;
                Rresult3 += lap1;
                Rresult4 += lap3;
                Rresult5 += lap1;
                Rresult6 += lap2;
                
                Rstring1 += "Mallory(lap2)  ";
                Rstring2 += "Mallory(lap3)  ";
                Rstring3 += "Mallory(lap1)  ";
                Rstring4 += "Mallory(lap3)  ";
                Rstring5 += "Mallory(lap1)  ";
                Rstring6 += "Mallory(lap2)  ";

                
            }
            
            if (name == "Yuki")
            {
                Rresult1 += lap3;
                Rresult2 += lap2;
                Rresult3 += lap3;
                Rresult4 += lap1;
                Rresult5 += lap2;
                Rresult6 += lap1;
                
                Rstring1 += "Yuki(lap3)  ";
                Rstring2 += "Yuki(lap2)  ";
                Rstring3 += "Yuki(lap3)  ";
                Rstring4 += "Yuki(lap1)  ";
                Rstring5 += "Yuki(lap2)  ";
                Rstring6 += "Yuki(lap1)  ";


            }
        }
            if ( team == "Blue")
            {
                if ( name == "Akano")
                {
                    Bresult1 += lap1;
                    Bresult2 += lap1;
                    Bresult3 += lap2;
                    Bresult4 += lap2;
                    Bresult5 += lap3;
                    Bresult6 += lap3;
                    
                    Bstring1= "Akano(lap1)  ";
                    Bstring2= "Akako(lap1)  ";
                    Bstring3= "Akako(lap2)  ";
                    Bstring4= "Akako(lap2)  ";
                    Bstring5= "Akako(lap3)  ";
                    Bstring6= "Akako(lap3)  ";
                }
                if ( name == "Rika" )
                {
                    Bresult1 += lap2;
                    Bresult2 += lap3;
                    Bresult3 += lap1;
                    Bresult4 += lap3;
                    Bresult5 += lap1;
                    Bresult6 += lap2;
                    
                    Bstring1 += "Rika(lap2)  ";
                    Bstring2 += "Rika(lap3)  ";
                    Bstring3 += "Rika(lap1)  ";
                    Bstring4 += "Rika(lap3)  ";
                    Bstring5 += "Rika(lap1)  ";
                    Bstring6 += "Rika(lap2)  ";
                }
                
                if (name == "Felicity")
                {
                    Bresult1 += lap3;
                    Bresult2 += lap2;
                    Bresult3 += lap3;
                    Bresult4 += lap1;
                    Bresult5 += lap2;
                    Bresult6 += lap1;
                    
                    Bstring1 += "Felicity(lap3)  ";
                    Bstring2 += "Felicity(lap2)  ";
                    Bstring3 += "Felicity(lap3)  ";
                    Bstring4 += "Felicity(lap1)  ";
                    Bstring5 += "Felicity(lap2)  ";
                    Bstring6 += "Felicity(lap1)  ";



                }
            }
        if ( team == "Green")
        {
            if ( name == "Itsuki")
            {
                Gresult1 += lap1;
                Gresult2 += lap1;
                Gresult3 += lap2;
                Gresult4 += lap2;
                Gresult5 += lap3;
                Gresult6 += lap3;
                
                
                Gstring1= "Itsuki(lap1)  ";
                Gstring2= "Itsuki(lap1)  ";
                Gstring3= "Itsuki(lap2)  ";
                Gstring4= "Itsuki(lap2)  ";
                Gstring5= "Itsuki(lap3)  ";
                Gstring6= "Itsuki(lap3)  ";
            }
            if ( name == "Kaito" )
            {
                Gresult1 += lap2;
                Gresult2 += lap3;
                Gresult3 += lap1;
                Gresult4 += lap3;
                Gresult5 += lap1;
                Gresult6 += lap2;
                
                Gstring1 += "Kaito(lap2)  ";
                Gstring2 += "Kaito(lap3)  ";
                Gstring3 += "Kaito(lap1)  ";
                Gstring4 += "Kaito(lap3)  ";
                Gstring5 += "Kaito(lap1)  ";
                Gstring6 += "Kaito(lap2)  ";
            }
            
            if (name == "Shizuku")
            {
                Gresult1 += lap3;
                Gresult2 += lap2;
                Gresult3 += lap3;
                Gresult4 += lap1;
                Gresult5 += lap2;
                Gresult6 += lap1;
                
                Gstring1 += "Shizuku(lap3)  ";
                Gstring2 += "Shizuku(lap2)  ";
                Gstring3 += "Shizuku(lap3)  ";
                Gstring4 += "Shizuku(lap1)  ";
                Gstring5 += "Shizuku(lap2)  ";
                Gstring6 += "Shizuku(lap1)  ";
            }
        }
        
        
    }
    
    
    cout << "Final Red team "<<smaller ( Rresult1 , smaller(Rresult2,smaller (Rresult3, smaller(Rresult4, smaller (Rresult5, Rresult6)))))/60 << ":"<<smaller ( Rresult1 , smaller(Rresult2,smaller (Rresult3, smaller(Rresult4, smaller (Rresult5, Rresult6)))))%60 << " s"<< endl;
    if ( smaller ( Rresult1 , smaller(Rresult2,smaller (Rresult3, smaller(Rresult4, smaller (Rresult5, Rresult6))))) == Rresult1)
        cout << Rstring1 << endl;
    if ( smaller ( Rresult1 , smaller(Rresult2,smaller (Rresult3, smaller(Rresult4, smaller (Rresult5, Rresult6))))) == Rresult2)
        cout << Rstring2 << endl;
    if ( smaller ( Rresult1 , smaller(Rresult2,smaller (Rresult3, smaller(Rresult4, smaller (Rresult5, Rresult6))))) == Rresult3)
        cout << Rstring3 << endl;
    if ( smaller ( Rresult1 , smaller(Rresult2,smaller (Rresult3, smaller(Rresult4, smaller (Rresult5, Rresult6))))) == Rresult4)
        cout << Rstring4 << endl;
    if ( smaller ( Rresult1 , smaller(Rresult2,smaller (Rresult3, smaller(Rresult4, smaller (Rresult5, Rresult6))))) == Rresult5)
        cout << Rstring5 << endl;
    if ( smaller ( Rresult1 , smaller(Rresult2,smaller (Rresult3, smaller(Rresult4, smaller (Rresult5, Rresult6))))) == Rresult6)
        cout << Rstring6 << endl;
    
    
    
    cout << "Final Blue team "<<smaller ( Bresult1 , smaller(Bresult2,smaller (Bresult3, smaller(Bresult4, smaller (Bresult5, Bresult6)))))/60 << ":"<<smaller ( Bresult1 , smaller(Bresult2,smaller (Bresult3, smaller(Bresult4, smaller (Bresult5, Bresult6)))))%60 << " s"<< endl;
    if ( smaller ( Bresult1 , smaller(Bresult2,smaller (Bresult3, smaller(Bresult4, smaller (Bresult5, Bresult6))))) == Bresult1)
        cout << Bstring1 << endl;
    if ( smaller ( Bresult1 , smaller(Bresult2,smaller (Bresult3, smaller(Bresult4, smaller (Bresult5, Bresult6))))) == Bresult2)
        cout << Bstring2 << endl;
    if ( smaller ( Bresult1 , smaller(Bresult2,smaller (Bresult3, smaller(Bresult4, smaller (Bresult5, Bresult6))))) == Bresult3)
        cout << Bstring3 << endl;
    if ( smaller ( Bresult1 , smaller(Bresult2,smaller (Bresult3, smaller(Bresult4, smaller (Bresult5, Bresult6))))) == Bresult4)
        cout << Bstring4 << endl;
    if ( smaller ( Bresult1 , smaller(Bresult2,smaller (Bresult3, smaller(Bresult4, smaller (Bresult5, Bresult6))))) == Bresult5)
        cout << Bstring5 << endl;
    if ( smaller ( Bresult1 , smaller(Bresult2,smaller (Bresult3, smaller(Bresult4, smaller (Bresult5, Bresult6))))) == Bresult6)
        cout << Bstring6 << endl;
    
    
    
    cout << "Final Green team "<<smaller ( Gresult1 , smaller(Gresult2,smaller (Gresult3, smaller(Gresult4, smaller (Gresult5, Gresult6)))))/60 << ":"<<smaller ( Gresult1 , smaller(Gresult2,smaller (Gresult3, smaller(Gresult4, smaller (Gresult5, Gresult6)))))%60 << " s"<< endl;
    if ( smaller ( Gresult1 , smaller(Gresult2,smaller (Gresult3, smaller(Gresult4, smaller (Gresult5, Gresult6))))) == Bresult6)
        cout << Bstring6 << endl;
    if ( smaller ( Gresult1 , smaller(Gresult2,smaller (Gresult3, smaller(Gresult4, smaller (Gresult5, Gresult6))))) == Bresult1)
        cout << Bstring1 << endl;
    if ( smaller ( Gresult1 , smaller(Gresult2,smaller (Gresult3, smaller(Gresult4, smaller (Gresult5, Gresult6))))) == Bresult2)
        cout << Bstring2 << endl;
    if ( smaller ( Gresult1 , smaller(Gresult2,smaller (Gresult3, smaller(Gresult4, smaller (Gresult5, Gresult6))))) == Bresult3)
        cout << Bstring3 << endl;
    if ( smaller ( Gresult1 , smaller(Gresult2,smaller (Gresult3, smaller(Gresult4, smaller (Gresult5, Gresult6))))) == Bresult4)
        cout << Bstring4 << endl;
    if ( smaller ( Gresult1 , smaller(Gresult2,smaller (Gresult3, smaller(Gresult4, smaller (Gresult5, Gresult6))))) == Bresult5)
        cout << Bstring5 << endl;
    


    cout << " ---------------------------------------------------------------"<< endl;
}



//void object6()
//{
//    cout << "OBJECT 6:" << endl;
//    cout << " " << endl;
//
//    ifstream infile;
//    infile.open("Result.txt");
//    string line;
//
//    string nameH1, teamH1, nameH2, teamH2;
//    int time1H1, time2H1, time3H1, time1H2, time2H2, time3H2;
//
//    for (int i =1; i <= totalRunner("Result.txt"); i++)
//    {
//
//        getline(infile, line);
//        nameH1 = readName(infile);
//        teamH1 = readName(infile);
//
//        time1H1 = readTime(infile);
//        time2H1 = readTime(infile);
//        time3H1 = readTime(infile);
//
//
//        getline(infile, line);
//        string runner;
//
//        for (int i =0; i <= totalRunner("Result.txt")+1 ; i++)
//            getline(infile, runner);
//
//        nameH2 = readName(infile);
//        teamH2 = readName(infile);
//
//        time1H2 = readTime(infile);
//        time2H2 = readTime(infile);
//        time3H2 = readTime(infile);
//
//        cout << nameH1 << " "<< teamH1 << " "<< time1H1<< " "<< time2H1<< " "<< time3H1<< endl;
//        cout << nameH2 << " "<< teamH2 << " "<< time1H2<< " "<< time2H1<< " "<< time3H1<< endl;
//    }
//    //    cout << " ---------------------------------------------------------------"<< endl;
//
//}
    

    
    

//void object6(int heat) {
//    cout << "OBJECT 6:" << endl;
//    cout << " " << endl;
//
//    ifstream infile;
//    infile.open("Result.txt");
//    string line;
//    int total1;
//    int total2;
//    string name, team;
//
//
//    if (heat==1)
//    {
//        getline(infile, line);
//        cout << "Heat 1:"<< endl;
//        for (int i =1; i <= totalRunner("Result.txt"); i++)
//        {
//            string name = readName(infile);
//            string team = readName(infile);
//
//            int time1= readTime(infile);
//            int time2= readTime(infile);
//            int time3= readTime(infile);
//            total1 = time1 + time2 + time3;
//
//
//            cout << name << " "<< team <<" "<< total1<< " s" <<endl;
//
//        }
//
//    }
//    else
//    {
//        getline(infile, line);
//        string runner;
//        for (int i =0; i <= totalRunner("Result.txt")+1 ; i++)
//            getline(infile, runner);
//
//        cout << "Heat 2:"<< endl;
//        for (int i =1; i <= totalRunner("Result.txt"); i++)
//        {
//            string name = readName(infile);
//            string team = readName(infile);
//
//            int time1= readTime(infile);
//            int time2= readTime(infile);
//            int time3= readTime(infile);
//            total2 =time1 + time2 + time3;
//
//            cout << name << " "<< team <<" "<< total2<< " s" <<endl;
//
//
//        }
//       // int different = total1- total2;
//        cout << different << endl;
//        //cout << name << " "<< team <<" "<< total1<< " s" <<endl;
//        //cout << name << " "<< team <<" "<< total2<< " s" <<endl;
//
//    };
//
//
//
//
//
//    cout << " "<< endl;
//    cout << " ---------------------------------------------------------------"<< endl;
//}


void object6(string filename)
{
    string line;
    ifstream infile;
    infile.open(filename);
    getline(infile, line);
    
    // for each runner
    for ( int i =0; i < totalRunner("Result.txt"); i++)
    {
        // get runner name
        string name;
        infile >> name;
        int seconds = getRunnerTime(name,1) ;
        int seconds2 = getRunnerTime(name,2) ;
        cout << seconds<<endl;
        cout << seconds2<<endl;
        int difference = abs(seconds - seconds2);
        getline (infile,line);
        cout << difference << endl;
    }
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
    
    object5(1);
    object5(2);
    
    object6("Result.txt");
    object6("Result.txt");



    

    }








