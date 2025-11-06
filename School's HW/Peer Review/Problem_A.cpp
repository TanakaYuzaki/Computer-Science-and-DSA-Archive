#include <iostream>
using namespace std;

int max_k_sum(int array[], int n, int k){
    int left = 0;
    int right = 0;
    int current = 0;
    int result;
    for(int i; i < k; i++){
        current += array[i];
        right++;
    }


    while(right < n){
        if(result < current){
            result = current;
        }
        current -= array[left];
        current += array[right];
        left += 1;
        right += 1;


    }

    return result;

}

int main(){
    int n,k;
    cin>>n>>k;

    int array[n];
    for(int i = 0; i < n; i++){
        cin>>array[i];
    }

    int result = max_k_sum(array,n,k);
    cout<<result;
}
