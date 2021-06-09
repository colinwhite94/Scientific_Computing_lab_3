/*
 Colin White
 May 23, 2018
 Lab 3
 This program: You are an engineer assigned to a program to develop a relatively cheap vehicle to deliver satellites to
 earth orbit. During launch of the vehicle, the rocket must reach a vertical velocity larger than 1000 m/s during the
 first 40 seconds after launch. The rocket’s instruments include an altimeter. Your job is to write a program to take
 the numerical derivative of the altitude data to find the velocity.
 */
#include <iostream>
#include <cmath>
#include <fstream> // allows input and output to files
using namespace std;

int main() {

    double t1 = 0; //time 1
    double t2 = 0; //time 2
    double t3 = 0; //time 3
    double a1 = 0; //altitude 1
    double a2 = 0; //altitude 2
    double a3 = 0; //altitude 3
    double v2 = 0; //velocity
    double step_size = 0; //signifies amount of data points user wants to skip
    int i = 1; //counter

    //Takes user input
   cout << "Enter desired step size" << endl << endl;
   cin >> step_size;

    ifstream fin; //if stream = input file. fin = arbitrary name
    fin.open("alt_data.txt"); //reading from this file
    ofstream  fout; //of stream output file. fopen = arbitrary name
    fout.open("lab3point1results.txt"); //writing to this file

    fin >> t1 >> a1; //read first line into the
    int interval = step_size/.100000; //the interval is determined by the step size
    for (i=0;i<interval;i++) //the for loop runs in order to skip the right number of data rows
        fin >> t2 >> a2;

    //this while loop will run till the end of the file.
    while(!fin.eof()){

        int interval = step_size/.100000; //the interval is determined by the step size
        for (i=0;i<interval;i++) //the for loop runs in order to skip the right number of data rows
            fin >> t3 >> a3; //time 2 altitude 2 are read

        //fin >> t3 >> a3; //time 3 and altitude 3 are read in
        v2 = (a3 -  a1)/(t3 -  t1); //the central deference is used to calculate velocity
        fout << t2 << "\t" << a2 << "\t" << v2 <<endl; //the time, altitude, and velocity are printed
        t1 = t2; //reindexing time
        t2 = t3; //reindexing time
        a1 = a2; //reindexing altitude
        a2 = a3; //reindexing altitude
        //fin >> t3 >> a3; //reading time 3, altitude 3
    }
    fin.close(); //Close both the input and the output files
    fout.close();
    return 0;
}
