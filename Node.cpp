//
//  Node.cpp
//  lab3
//
//  Created by Tina Tavallaeian on 2017-10-15.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//

#include "Node.h"
#include <iostream>




Node::Node() //my constructor sets numres to 0 and sets all values in resIDArray to -1
: numRes(0)
{
    for (int i = 0; i < MAX_RESISTORS_PER_NODE; ++i) // Preset the resIDArray to -1s
    {
        resIDArray[i] = -1;
    }
}

//destructor of the object
Node::~Node(){}


bool Node::canAddResistor(int rIndex) //makes sure i am able to add a resistor
{
    if (numRes == 5)
        return false;
    else
        return true;
}

void Node::addResistor(int rIndex) //adds the index of the resistor to my resIDArray
{   
    resIDArray[numRes] = rIndex;
    ++numRes;
}
