#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;
    int firstOccurrence = -1, lastOccurrence = -1;

    // fiding fist occurence
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            firstOccurrence = mid;
            right = mid - 1;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // If key not found
    if (firstOccurrence == -1) {
        return 0;
    }
    // Finding last occurrence
    left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            lastOccurrence = mid;
            left = mid + 1;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    int count = lastOccurrence - firstOccurrence + 1;
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int key;
        cin >> key;
        int count = binarySearch(arr, key);
        if (count > 0) {
            cout << key << " - " << count << endl;
        } else {
            cout << "Key not present" << endl;
        }
    }
    return 0;
}
