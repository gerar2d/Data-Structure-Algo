#include <iostream>
#include "p1-C2.h"
using namespace std;

int main(){

    // calling 3 main constructors
    TargetHeartRateZone a1; 
    TargetHeartRateZone a2(27, 194); 
    TargetHeartRateZone a3(a2);

    TargetHeartRateZone a4;

    // child class zone2 zone 3
    TargetHeartRateZone2 b1;
    TargetHeartRateZone3 c1;

    // adding the address of class TargetHeartZone2 and zone 3 to TargetHeartZone and access methods of Zone
    TargetHeartRateZone * ca1 = &b1; 
    TargetHeartRateZone * ca2 = &c1;
    cout<<endl;


    cout<<"Get a1:  ";
    a1.getAM();
    cout<<"Get a2:  ";
    a2.getAM();
    cout<<"Get a3:  ";
    a3.getAM();

    // using set function  to change values
    a1.setAM(30, 190);
    cout<<"a1 after set function:   ";
    a1.getAM();

    a2.setAM(40, 180);
    cout<<"a2 after set function:   ";
    a2.getAM();

    // operator overload from a2 to a4
    a4 = a2;
    cout<<"a4:  ";
    a4.getAM();

    // polymorphism
    cout<<"set function on b1(TargetHeartRateZone2) using polymorphism"<<endl;
    ca1->setAM(36, 184);
    ca1->getAM();
    cout<<ca1->zone()<<endl;

    cout<<"set function on c1(TargetHeartRateZone3) using polymorphism"<<endl;
    ca2->setAM(36, 180);
    ca2->getAM();
    cout<<ca2->zone()<<endl;

    cout<<endl;
    cout<<"use of destructor to free memory"<<endl;
}