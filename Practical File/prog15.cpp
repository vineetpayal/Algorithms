#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> find_common_elements(vector<int>& nums1, vector<int>& nums2) {
    vector<int> common_elements;
    int i = 0;
    int j = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            common_elements.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return common_elements;
}

int main() {
    int m, n;
    cin >> m;
    vector<int> nums1(m);
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }
    
    cin >> n;
    vector<int> nums2(n);
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }
    
    vector<int> result = find_common_elements(nums1, nums2);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
