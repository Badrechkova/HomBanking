#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include<sstream>
#include<Windows.h>
#include<C:\Users\badrb\OneDrive\Bureau\C++\RSAFunctions.h>


using namespace std;

int main (){

    string ans;
    double a, b;
    
    do
    {
        //The filter's delimeters----------------------
            cout << "Enter the minmal age: ";
            cin >> a;
            cout << endl;
            cout << "Enter the maximum age: ";
            cin >> b;
            cout << endl;
           
            if (a > b or a*b<=0 or (a<0 and b<0)) { cout << "Enter a valid interval." << endl; }
            else
            {

            //To read the file-----------------------------
            string line;
            ifstream data("Data.txt");
            if (data.is_open())
            {
                ofstream results;
                ofstream encResults;
                encResults.open("Encrypted_Results.txt");
                results.open("Results.txt");
                while (getline(data, line))
                {
                    double age = stod(line.substr(16, 19));
                    if (Enc_RSA(a - 1) < Enc_RSA(age) and Enc_RSA(age) < Enc_RSA(b + 1))
                    {
                        encResults << Enc_RSA(age) << endl;
			results << Dec_RSA(Enc_RSA(age)) << endl;
                    }

                }
                data.close();
            }
            else cout << "Unable to open file";
     
            //One read the data in the file Encrypted_Results.txt---
            ifstream enResults("Encrypted_Results.txt");
            if (enResults.is_open())
            {
                while (getline(enResults, line))
                {
                    cout << line << '\n' << endl;
                }
                enResults.close();
            }
            else cout << "Unable to open file";

            //-------------------------------------------

            //One read the data in the file Results.txt---
            ifstream results("Results.txt");
            if (results.is_open())
            {
                while (getline(results, line))
                {
                    cout << line << '\n' << endl;
                }
                results.close();
            }
            else cout << "Unable to open file";

            //-------------------------------------------
            cout << "Try again ? (y/n): ";
            cin >> ans;
        }
     
    } 
    
    while (ans == "y" );
    
	return 0;}
