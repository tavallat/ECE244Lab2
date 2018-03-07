
/*
 this is the final file
 
 * File:  parser
 
 * Author: tavalla2
 * student #: 1003363022
 
 */

#include "RParser.h"
#include "Node.h"
#include "Resistor.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#define MAX_NODE_NUMBER 5000
using namespace std;
Node* nodeArray;
Resistor* resArray;
int rIndex;

void insertRCommand(string Rname, float Rvalue, int node1, int node2, string extra) {
    
    //this function deals with the cases where Rname is all, Rvalue is negative,
    //node1 and node2 are equal, node1 and node2 are out of range, too many and
    //too few arguments as well as printing the output if everything is done right
    //ensures the precision for the value is set to 2

    int nodes[2];
    nodes[0] = node1;
    nodes[1] = node2;
    
    
    cout << setprecision(2) << fixed;
    
    if (Rname == "all")
        
        cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
    
    
    else if (Rvalue < 0) //deals with the value of the resistance being negative
        
        cout << "Error: negative resistance" << endl;
    
    
    
    //if node 1 and node 2 were the same
    
    else if (node1 == node2)
        
        cout << "Error: both terminals of resistor connect to node " << node1
        
        << endl;
    
    //if the value of the nodes are too high
    
    else if (node1 > MAX_NODE_NUMBER || node1 < 0)
        
        cout << "Error: node " << node1 <<
        
        " is out of permitted range 0-5000" << endl;
    
    
    
    else if (node2 > MAX_NODE_NUMBER || node2 < 0)
        
        cout << "Error: node " << node2 <<
        
        " is out of permitted range 0-5000" << endl;
    
    
   //making sure i have enough arguments
    else if (Rname == "Rname" || Rvalue == 1000000000 || node1 == 4999 || node2 == 4998)
        
        cout << "Error: too few arguments" << endl;
    
    
    
    else if (extra != "extra")
        
        cout << "Error: too many arguments" << endl;
    
    // the program will get here only if everything has been successful
    
    else{
        //inserting the resistor into node array
        //inserting it into the resistor array
        resArray[rIndex] = Resistor(rIndex, Rname, Rvalue, nodes);
        rIndex = rIndex + 1;
        nodeArray[node1].addResistor(rIndex);
        
      

        
        
    cout << "Inserted: resistor " << Rname << " " << Rvalue << " Ohms " <<
        
    node1 << " -> " << node2 << endl;}

    
    
    return;
    
}

void modifyCommand(string Rname, float newvalue, string extra) {
    
    //this function takes care of negative resistance, too many and too few
    //it also generates the output if all is good
    
    cout << setprecision(2) << fixed;
    
    if (newvalue < 0)
        
        cout << "Error: negative resistance" << endl;
    
    
    else if (Rname == "all")
        
        cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
    
    
    
    else if (Rname == "Rname" || newvalue == 99999)
        
        cout << "Error: too few arguments" << endl;
    
    
    
    else if (extra != "extra")
        
        cout << "Error: too many arguments" << endl;
    
    
    
    else cout << "Modified: resistor " << Rname << " to " << newvalue << " Ohms"
        
        << endl;
    
    return;
    
}

void deleteRCommand(string Rname, string extra) {
    
    //this function deals with the output for the command
    
    if (Rname == "all")
        
        cout << "Deleted: all resistors" << endl;
    else
        
        cout << "Deleted: resistor " << Rname << endl;
    
    return;
    
}

void printRCommand(string Rname, string extra) {
    
    //this function deals with too many, too few as well as the output
    
    if (Rname == "all")
        
        cout << "Print: all resistors" << endl;
    
    else if (Rname == "Rname")
        
        cout << "Error: too few arguments" << endl;
    
    else if (extra != "extra")
        
        cout << "Error: too many arguments" << endl;
    
    else
        
        cout << "Print: resistor " << Rname << endl;
    
    return;
    
}

void printNodeCommand(int nodevalue, string extra) {
    
    //this function deals with too few, too many, range and output
    
    //if (nodevalue == 4999)
        //cout << "Error: too few arguments" << endl;
    
     if (nodevalue > MAX_NODE_NUMBER || nodevalue < 0)
        
        cout << "Error: node " << nodevalue <<
        
        " is out of permitted range 0-5000" << endl;
    
       else cout << "Print: node " << nodevalue << endl;
    
    return;
    
}

void printRCommand(string Rname) {
    //this function deals with output of the command printR
    
    if (Rname == "all")
        cout << "Print: all resistors" << endl;
    else
        cout << "Print: resistor " << Rname << endl;
    return;
}


