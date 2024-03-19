#include <iostream>
#include <vector>
#include <cstdlib> 

using namespace std;

int partition(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

void quicksort(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        int pivot_index = rand() % (high - low + 1) + low;
        swap(arr[pivot_index], arr[high]);
        int pivot = partition(arr, low, high, comparisons, swaps);
        quicksort(arr, low, pivot - 1, comparisons, swaps);
        quicksort(arr, pivot + 1, high, comparisons, swaps);
    }
}

void sort_array(vector<int>& arr) {
    int comparisons = 0, swaps = 0;
    quicksort(arr, 0, arr.size() - 1, comparisons, swaps);
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort_array(arr);
    }
    return 0;
}
