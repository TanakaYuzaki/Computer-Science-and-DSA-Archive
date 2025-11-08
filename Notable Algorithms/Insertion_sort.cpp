#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin>>n;

    int array[n];
    for(int i = 0; i < n; i++){
        cin>>array[i];
    }

    for(int i = 0; i < n; i++){
        int pointer_left = i-1;
        int pointer_right = i;
        while(array[pointer_left] > array[pointer_right] && pointer_left >= 0){
            int temp = array[pointer_left];
            array[pointer_left] = array[pointer_right];
            array[pointer_right] = temp;
            
            pointer_left -= 1;
            pointer_right -= 1;
        }
    }
    for(int i = 0; i < n; i++){
        cout<<array[i]<<" ";
    }
}
