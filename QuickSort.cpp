#include <iostream>
using namespace std;

int partition(int arr[], int l, int r) {
    int pi = arr[r];
    int i = l - 1;
    for (int j = l; j<r; j++) {
        if (arr[j] <= pi) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

main() {
    int n = 5;
    int arr[n] = {9,7,5,3,1};
    quickSort(arr, 0, n-1);
    for (int i = 0; i<n; i++) {
        cout<<arr[i]<<' ';
    }
}
