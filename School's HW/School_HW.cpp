#include <iostream>
#include <cmath>

using namespace std;

void check(int year,int days){
    if((year%4 == 0 && !(year%100 == 0)) || (year%4 == 0 && year%400 == 0)){
        cout<<"This is a leap year"<<endl;
        if(days == 29){
            cout<<2;
        }
    }

    if(days == 31){
        cout<<1<<" "<<" "<<3<<" "<<5<<" "<<7<<" "<<8<<" "<<10<<" "<<12;
    }
    if(days == 30){
        cout<<2<<" "<<4<<" "<<6<<" "<<9<<" "<<11;
    }
    if(days == 28){
        cout<<2;
    }


    
    


}
int main(){
    int year,days;
    cin>>year>>days;
    check(year,days);
}