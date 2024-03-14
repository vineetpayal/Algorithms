#include<iostream>
#include<vector>
using namespace std;

pair<int,int> insertionSort(vector<int> &nums){
    int j,key;
    pair<int,int> ans;
    for(int i = 1; i<nums.size(); i++){
        key = nums[i];
        j = i-1;
        while(j>=0 && nums[j] > key){
            ans.first++; //comparisons
            ans.second++; //shifts
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
        ans.second++; //shifts

    }
    return ans;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int size;
        cin>>size;
        vector<int> nums(size);
        for(int i = 0; i< size; i++){
            cin>>nums[i];
        }
        pair<int,int> ans = insertionSort(nums);

        //Printing the sorted array
        for(int i = 0; i< size; i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        cout<<"Comparisons: "<<ans.first<<endl;
        cout<<"Shifts: "<<ans.second<<endl;
    }
    return 0;
}