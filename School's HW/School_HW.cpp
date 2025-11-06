#include <iostream>
#include <cmath>

using namespace std;

bool check(int number){
    if(number < 0){
        return false;
    }
    int root =  static_cast<int>(sqrt(number));
    return root*root == number;
}
int main(){
    int number;
    cin>>number;
    cout<<check(number);
}