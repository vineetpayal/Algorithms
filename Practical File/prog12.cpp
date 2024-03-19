#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickselect(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == k) {
            return arr[pivotIndex];
        } else if (pivotIndex < k) {
            return quickselect(arr, pivotIndex + 1, high, k);
        } else {
            return quickselect(arr, low, pivotIndex - 1, k);
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cin >> k;
        int result = quickselect(arr, 0, n - 1, k - 1);
        if (result != -1) {
            cout << "Kth smallest element: " << result << endl;
        } else {
            cout << "not present" << endl;
        }
    }
    return 0;
}
