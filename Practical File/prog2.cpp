#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    int comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++; // Count comparisons
        if (arr[mid] == key) {
            return mid; // Key found
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; 
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        int result = binarySearch(arr, n, key);
        if (result != -1) {
            cout << "Key found at index " << result << endl;
        } else {
            cout << "Key not found" << endl;
        }

        cout << "Number of comparisons: " << n << endl;
    }

    return 0;
}
