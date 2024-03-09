#include <iostream>
#include <vector>
using namespace std;

// using iteration
int binarySearch(vector<int> &nums, int key)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (nums[mid] == key)
        {
            return mid;
        }
        else if (key < nums[mid])
        {
            high = mid - 1;
        }
        else if (key > nums[mid])
        {
            low = mid + 1;
        }
    }
    return -1;
}

// using recursion
int RecurBinarySearch(vector<int> &nums, int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == nums[mid])
        {
            return mid;
        }
        else if (key < nums[mid])
        {
            return RecurBinarySearch(nums, low, mid - 1, key);
        }
        else
        {
            return RecurBinarySearch(nums, mid + 1, high, key);
        }
    }
    return -1;
}

int main()
{
    // input size
    int n;
    cout << "Enter size: ";
    cin >> n;

    // input array
    vector<int> nums(n);
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // input key
    int key;
    cout << "Enter key: ";
    cin >> key;

    int pos_i = binarySearch(nums, key);            // using iteration
    int pos_r = RecurBinarySearch(nums, 0, n, key); // using recursion

    cout << "Element found at index: " << pos_r << endl;
}