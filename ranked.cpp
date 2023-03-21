#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct data{
    string stuName;
    string fathers_name;
    float average_score;
};

int main()
{
    int numbr;

cout<<setw(30)<<"Hello! This program lets you compute the rank of students. "<<endl<<endl;
   
cout<<"How many number of students are there? ";
cin>>numbr;
 cout<<endl;
 
 data info[numbr], take_val;
        for(int i=0; i<numbr; i++){

    cout<<"Enter the name of student "<<i+1<<" "; 
    cin>>info[i].stuName;
    cout<<"Enter his/her father's name ";
    cin>> info[i].fathers_name;
    cout<<"Enter the average score of the student ";
    cin>> info[i].average_score;
    cout<<endl;
        }
        for(int i=0; i<numbr-1; i++){
            for(int j= i+1; j<numbr; j++){
          
        if (info[j].average_score > info[i].average_score){
            
            take_val= info[i];
            info[i]=info[j];
            info[j]=take_val;
            
        }   
        else continue;
            }
        }

cout<<"----------The students' rank is displayed as follows---------"<<endl<<endl;

for(int i=0; i<numbr; i++){
    cout<<i+1<<"."<<" "<<info[i].stuName<<" "<<info[i].fathers_name<<" "<<info[i].average_score<<endl;
}

    return 0;
}
