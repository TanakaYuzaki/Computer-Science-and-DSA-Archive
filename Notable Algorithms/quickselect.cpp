#include <iostream>
using namespace std;

// Partition function (similar to Lomuto partition scheme)
int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // choose last element as pivot
    int i = left;           // place for swapping

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    // swap pivot into correct position
    int temp = arr[i];
    arr[i] = arr[right];
    arr[right] = temp;

    return i; // pivot index
}

// Iterative Quickselect
int quickSelect(int arr[], int n, int k) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k) {
            return arr[pivotIndex]; // found kth smallest
        } else if (pivotIndex < k) {
            left = pivotIndex + 1; // search right side
        } else {
            right = pivotIndex - 1; // search left side
        }
    }
    return -1; // should not happen if k is valid
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // find 3rd smallest (0-based index → k=2)

    int result = quickSelect(arr, n, k-1); // k-1 for 0-based
    cout << k << "rd smallest element is: " << result << endl;

    return 0;
}
