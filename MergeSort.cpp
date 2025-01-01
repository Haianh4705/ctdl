#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int s1 = m-l+1;
    int s2 = r-m;
    int left[s1], right[s2];

    for (int i = 0; i<s1; i++) {
        left[i] = arr[l+i];
    }
    for (int i = 0; i<s2; i++) {
        right[i] = arr[m+i+1];
    }

    int i = 0, j = 0, k = l;
    while (i<s1 && j<s2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i<s1) {
        arr[k] = left[i];
        i++; k++;
    }

    while (j<s2) {
        arr[k] = right[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

main() {
    int n = 5;
    int arr[n] = {9,7,5,3,1};
    mergeSort(arr, 0, n-1);
    for (int i = 0; i<n; i++) {
        cout<<arr[i]<<' ';
    }
}
