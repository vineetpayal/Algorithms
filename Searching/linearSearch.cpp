#include <iostream>
#include <vector>
using namespace std;

// using iterations
int linearSearch(vector<int> &nums, int key)
{
    int l = nums.size();
    for (int i = 0; i < l; i++)
    {
        if (nums[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// using recursion
int RecurLinearSearch(vector<int> &nums, int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    else if (nums[n - 1] == key)
    {
        return n - 1;
    }
    return RecurLinearSearch(nums, n - 1, key);
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

    int pos_i = linearSearch(nums, key);         // using iteration
    int pos_r = RecurLinearSearch(nums, n, key); // using recursion

    cout << "Element found at index: " << pos_r << endl;
}