#include <iostream>
#include <array>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

//Exercise 1 : A system for blood pressure records

class Date{  // defining a class Date. 
    protected:
    int day;
    int month;
    int year;

    public:
  
    Date(const int day,const int month,const int year){ //user defined constructor
        
        this->day=day;
        this->month=month;
        this->year=year;
    }

    int getDay(){ //defining a getter to get the day of the result
        return day;
    }

    int getMonth(){ //defining a getter to get the month of the result
        return month;
    }

    int getYear(){ //defining a getter to get the year of the result
        return year;
    }
};

class Blood{  //define a class Blood
    protected:
    int systolic;
    int diastolic;
    Date date;

    public:
    Blood(const int systolic, const int diastolic, const Date date):
    date(date) {
        this->systolic=systolic;
        this->diastolic=diastolic;
    };

    int getSystolic(){ //getter of systolic 
        return systolic;
    }

    int getDiastolic(){ //getter of diastolic 
        return diastolic;
    }

    Date getDate(){ //getter for the date 
        return date;
    }
};

class Patient{
    protected:
    string name; //declaring a string attribute
    vector <Blood> table; //this vector stores blood class objects 

    public:
    Patient(string name){
        this->name=name;
        this->table=vector <Blood>();
    };

    void addRecord(Blood dailyPressure){ //method taking as its argument an object of the class Blood and puts the result into the vector declared above. 
        table.push_back(dailyPressure);
    };

    void getTable(){  //declaring a void method which prints the the blood test results associated with specific patients; 
        for(int i=0;i<table.size();i++){
            cout << "Systolic pressure: " << table[i].getSystolic() << ", Diastolic pressure: " << table[i].getDiastolic() << ", Date: " << table[i].getDate().getDay()<< "/" << table[i].getDate().getMonth() << "/" << table[i].getDate().getYear()<<endl;
            cout<<endl;
        }
    }
    // Q2: defining a method which prints: 
//- if all systolic values were below 140, "no measurement was too high"
//- The average diastolic blood pressure
//-the list of maximal pressure records for a patient


    void printReport(){

        cout<<"Report for the patient "<< this->name << ":"<< endl;
        int sumDiastolic=0;
        double avgDiastolic=0.0; // Double representing the average diastolic data. 
        vector<Blood> highestAbnormalSys=vector<Blood>();
        int maximum=140; // declaring an integer maximum for the blood pressure. 

        for(int i=0;i<table.size();i++){ // a for loop which adds the diastolic data of each single patient 

            sumDiastolic+=table[i].getDiastolic();

            if (table[i].getSystolic()>maximum){ // checking whether the systolic data of patients is higher than the maximum of 140 defined above. 
                highestAbnormalSys.clear();
                highestAbnormalSys.push_back(table[i]);
                maximum=table[i].getSystolic();
            }
            else if (table[i].getSystolic()==maximum){
                highestAbnormalSys.push_back(table[i]);
            }
        }

        if (highestAbnormalSys.size()==0){ //displaying on the screen that no measurement is too high when the all the systolic data are below 140. 
            cout << "No measurement was too high" << endl;
        }
        else{
            cout << "Abnormal systolic measurements:" << endl; //when the systolic pressure is abnormally high, the abnormal data is stored of the vector dedicated to abnormla observations. 
            for(int i=0;i<highestAbnormalSys.size();i++){
                cout << "Systolic pressure: " << highestAbnormalSys[i].getSystolic() << ", Diastolic pressure: " << highestAbnormalSys[i].getDiastolic() << ", Date: " << highestAbnormalSys[i].getDate().getDay()<< "/" << highestAbnormalSys[i].getDate().getMonth() << "/" << highestAbnormalSys[i].getDate().getYear()<<endl;
            }
        }
        avgDiastolic=sumDiastolic/table.size();
        cout<<"The average diastolic pressure was: "<<avgDiastolic<<endl;
        cout<<endl;
    }
}
;


//Final Executable function
int main(){
    //Q1
    Patient mary=Patient("Mary");
    mary.addRecord(Blood(94,61, Date(2,5,2013)));
    mary.addRecord(Blood(97,65, Date(3,5,2013)));
    mary.addRecord(Blood(144,99, Date(4,5,2013)));
    mary.addRecord(Blood(123,88, Date(5,5,2013)));
    mary.addRecord(Blood(177,110, Date(6,5,2013)));
    mary.addRecord(Blood(145,89, Date(7,5,2013)));

    //Q2
    mary.printReport();

    //Q3
    Patient john = Patient("John");
    john.addRecord(Blood(88,57, Date(15,5,2013)));
    john.addRecord(Blood(95,61, Date(16,5,2013)));
    john.addRecord(Blood(114,80, Date(17,5,2013)));
    john.addRecord(Blood(151,96, Date(18,5,2013)));
    john.addRecord(Blood(176,104, Date(19,5,2013)));
    john.addRecord(Blood(176,110, Date(20,5,2013)));
    john.printReport();

    return 0;
}

