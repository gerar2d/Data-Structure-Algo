#include <iostream>
using namespace std;


class TargetHeartRateZone {
    public:
        TargetHeartRateZone();
        TargetHeartRateZone(int aage, int mmhr);
        TargetHeartRateZone(TargetHeartRateZone& x);
        // Destrutor       
        ~TargetHeartRateZone(){ cout<<"Destrutor"<<endl; }

        virtual int zone(){ 
            int targetzone1 = mhr*.60;
            cout<<"zone1: "<<targetzone1<<" Very Light"<<endl;
            }
        
        void setAM(int a, int b);
        void getAM();

        void operator = (const TargetHeartRateZone &z);
        
    protected:
         int age, mhr;
};

//default constructor
TargetHeartRateZone::TargetHeartRateZone(){
    age = mhr = 0;
}

//parameterized constructor
TargetHeartRateZone::TargetHeartRateZone(int aage, int mmhr){
    age = aage;
    mhr = mmhr;
}

//copy constructor
TargetHeartRateZone::TargetHeartRateZone(TargetHeartRateZone& a){
    age = a.age;
    mhr = a.mhr;
}

// set function
void TargetHeartRateZone::setAM(int a, int b){
    age = a;
    mhr = b;
}

// get function
void TargetHeartRateZone::getAM(){
    cout<<"age: "<<age<<" maximum heart rate: "<<mhr<<endl;
}


// overloaded assigment operator
void TargetHeartRateZone::operator = (const TargetHeartRateZone &z){
    age = z.age;
    mhr = z.mhr;
}

class TargetHeartRateZone2: public TargetHeartRateZone{
    public:
        TargetHeartRateZone2() : TargetHeartRateZone(){
            age = mhr = 0;
        }
};


class TargetHeartRateZone3: public TargetHeartRateZone{
    public:
        TargetHeartRateZone3() : TargetHeartRateZone(){
            age = mhr = 0;
        }
};