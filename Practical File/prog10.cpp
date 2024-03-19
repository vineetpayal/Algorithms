#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int low, int mid, int high, int& comparisons) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    int inversions = 0;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            inversions += (mid - i + 1);
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return inversions;
}

int mergeSort(vector<int>& arr, int low, int high, int& comparisons) {
    int inversions = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;
        inversions += mergeSort(arr, low, mid, comparisons);
        inversions += mergeSort(arr, mid + 1, high, comparisons);
        inversions += merge(arr, low, mid, high, comparisons);
    }
    return inversions;
}

void sort_array(vector<int>& arr) {
    int comparisons = 0;
    int inversions = mergeSort(arr, 0, arr.size() - 1, comparisons);
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Inversions: " << inversions << endl;
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
