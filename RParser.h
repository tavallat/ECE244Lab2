//
//  RParser.h
//  lab3
//
//  Created by Tina Tavallaeian on 2017-10-15.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//

#ifndef RParser_h
#define RParser_h

#include <cstdlib>
#include "Node.h"
#include "Resistor.h"
#include <iostream>

#include <sstream>

#include <string>

#include <iomanip>
using namespace std;
extern Node* nodeArray;
extern Resistor* resArray;
extern int rIndex;


void insertRCommand(string Rname, float Rvalue, int node1, int node2, string extra);
void modifyCommand(string Rname, float newvalue, string extra);
void deleteRCommand(string Rname, string extra);
void printRCommand(string Rname, string extra);
void printNodeCommand(int nodevalue, string extra);
void printRCommand(string Rname);

#endif /* RParser_h */
