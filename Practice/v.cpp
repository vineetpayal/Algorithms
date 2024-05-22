#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int partition(vector<int> &nums, int l, int r, int &cmp, int &swp)
{
    int x = rand() % (r - l + 1)+l;
    swp++;
    swap(nums[x], nums[r]);

    int pivot = nums[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        cmp++;
        if (nums[j] < pivot)
        {
            i++;
            swp++;
            swap(nums[i], nums[j]);
        }
    }
    swp++;
    swap(nums[i + 1], nums[r]);
    return i + 1;
}

int quickSort(vector<int> &nums, int l, int r, int &cmp, int &swp)
{
    if (l < r)
    {
        int pi = partition(nums, l, r, cmp, swp);
        quickSort(nums, l, pi - 1, cmp, swp);
        quickSort(nums, pi + 1, r, cmp, swp);
    }
}

void sort_array(vector<int> &nums)
{
    int cmp = 0, swp = 0;
    quickSort(nums, 0, nums.size() - 1, cmp, swp);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << "Comparisons: " << cmp << endl;
    cout << "swaps: " << swp << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort_array(arr);
    }
    return 0;
}
