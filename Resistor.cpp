//
//  Resistor.cpp
//  lab3
//
//  Created by Tina on 2017-10-15.
//  Copyright © 2017 Tina. All rights reserved.
//

#include "Resistor.h"
#include <iomanip>
#include "Node.h"
using namespace std;
//the defualt constructor
Resistor:: Resistor(){}

//the constructor
Resistor:: Resistor (int rIndex_,string name_,double resistance_,int endpoints_[2]) {
    rIndex = rIndex_;
    name = name_;
    resistance = resistance_;
    endpointNodeIDs [0] = endpoints_[0];
    endpointNodeIDs [1] = endpoints_[1];
}

//resistor destructor
Resistor::~Resistor() {
    
}

//this function returns the name of resistor
string Resistor::getName() const
{
    return name;
}

//this function returns the resistor value of the resistor
double Resistor::getResistance() const
{
    return resistance;
}

//sets the resistance of the resistor to the given value
void Resistor::setResistance(double resistance_)
{
    resistance = resistance_;
}




