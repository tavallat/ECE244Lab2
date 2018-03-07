
//  main.cpp
//  lab3
//  Created by Tina Tavallaeian on 2017-10-15.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.


#include <iostream>
#include "Node.h"
#include "Resistor.h" 
#include "RParser.h"
#include <cstdlib>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
    string command, line, input;
    int maxnode, maxres;
    rIndex = 0;
    cout << "> ";
    getline(cin, line);
    
    while (!cin.eof()) {
        stringstream linestream(line);
        
        //command is retracted from line stream
        linestream >> command;
        //going through each command and applying what is needed
        
        if (command == "maxVal"){
            linestream >> maxnode >> maxres;
            if (maxnode == 0 || maxres == 0)
                cout << "Error: maxVal arguments must be greater than 0" << endl;
            else{ //dynamically allocate two arrays in main
                nodeArray = new Node [maxnode+1];
                resArray = new Resistor [maxres];
                cout << "New network: max node number is " << maxnode << "; max resistors is " << maxres << endl;
                
            }
        }
        
        //***** insertR COMMAND *****
        else if (command == "insertR") {
            
            string Rname, extra;
            
            float Rvalue;
            
            int node1, node2;
            
            //initializing each variable
            
            Rname = "Rname";
            
            Rvalue = 1000000000;
            
            node1 = 4999;
            
            node2 = 4998;
            
            extra = "extra";
            
            linestream >> Rname;
            linestream >> Rvalue;
            linestream >> node1;
            //making sure the user doesnt enter decimal numbers
            char next;
            
            next = linestream.peek();
            
            
            if (next == '.' || next > 33) //this is to ensure the user dosent type a wrong character after
                cout << "Error: invalid argument" << endl;
            else {
                linestream >> node2;
                next = linestream.peek();
                if (next == '.' || next > 33 )
                    cout << "Error: invalid argument" << endl;
                
                else {
                    
                    linestream >> extra;
                    
                    if (Rvalue < 0) //negative resistance
                        
                        cout << "Error: negative resistance" << endl;
                    
                    
                    else if (linestream.fail() && !linestream.eof())
                        
                        cout << "Error: invalid argument" << endl; //if input is invalid
                    
                    else
                        insertRCommand(Rname, Rvalue, node1, node2, extra);
                    
                }
            }
        }
        
        
        //***** modifyR COMMAND *****
        
        else if (command == "modifyR") {
            
            string Rname, extra;
            
            float newvalue;
            
            Rname = "Rname"; //initialized value of newvalue
            
            newvalue = 99999; //initialized value of newvalue
            
            extra = "extra"; //initialized value of extra
            
            linestream >> Rname >> newvalue;
            
            char next;
            next = linestream.peek();
            if (next == '.' || next > 33)
                cout << "Error: invalid argument" << endl;
            
            else {
                linestream >> extra;
                
                if (linestream.fail() && !linestream.eof()) //if invalid argument
                    
                    
                    cout << "Error: invalid argument" << endl;
                
                else
                    
                    modifyCommand(Rname, newvalue, extra);
                
            }}
        
        //***** deleteR COMMAND *****
        
        else if (command == "deleteR") {
            
            string Rname, extra;
            //initializing the values
            Rname = "Rname";
            extra = "extra";
            //get the input from stream
            
            linestream >> Rname >>extra;
            if (Rname == "Rname")
                cout << "Error: too few arguments" << endl;
            
            else if (extra != "extra")
                cout << "Error: too many arguments" << endl;
            
            
            else if (linestream.fail() && !linestream.eof())
                
                cout << "Error: invalid argument" << endl;
            else
                
                deleteRCommand(Rname, extra);
        }
        
        //***** printNode COMMAND *****
        
        else if (command == "printNode") {
            int nodevalue;
            string extra;
            nodevalue = 4999; //initialized value
            extra = "extra"; //initialized value
            linestream >> nodevalue;
            char nextchar;
            if (linestream.fail() & linestream.eof())
                cout << "Error: too few arguments" << endl;
            
            else if (linestream.fail()) {
                //clear the integer to see whats up
                linestream.clear();
                string badinput;
                linestream >> badinput;
                //i have to check if badinput is all or not
                //MY ALL BLOCK
                
                if (badinput == "all") {
                    //i have to check if they inputed extra or not
                    linestream >> extra;
                    if (extra != "extra")
                        cout << "Error: too many arguments" << endl;
                    else
                        cout << "Print: all nodes" << endl;
                    
                    // by now i have dealt with all
                } else
                    cout << "Error: invalid argument" << endl;
            } //now lets consider all cases where an integer input can go wrong
            else {
                nextchar = linestream.peek ();
                
                if (nextchar == '.' || nextchar > 33)
                    cout <<"Error: invalid argument" << endl;
                
                else {
                    linestream >> extra;
                    
                    if (nodevalue < 0 || nodevalue > 5000)
                        cout << "Error: node " << nodevalue << " is out of permitted range 0-5000" << endl;
                    else if (nodevalue == 4999)
                        cout << "Error: too few arguments" << endl;
                    else if (nodevalue != 4999 && extra != "extra")
                        cout << "Error: too many arguments" << endl;
                    else if (extra != extra)
                        cout << "Error: too many arguments" << endl;
                    else
                        printNodeCommand(nodevalue, extra);
                }
            }
        }//****** PRINTR COMMAND ***************
        
        else if (command == "printR") {
            
            string Rname, extra;
            
            //initializing the values
            
            Rname = "Rname";
            
            extra = "extra";
            
            //get the input from stream
            
            linestream >> Rname >> extra;
            
            if (linestream.fail() && !linestream.eof())
                
                cout << "Error: invalid argument" << endl;
            
            else
                
                printRCommand(Rname, extra);
        } else
            
            cout << "Error: invalid command" << endl;
        
        linestream.ignore(1000, '\n');
        
        command = "hehe...nottoday"; //this is to ensure if the user
        //presses enter i dont get invalid command
        
        cout << "> ";
        getline(cin, line);
    }

    
    
    return (0);
    
}
