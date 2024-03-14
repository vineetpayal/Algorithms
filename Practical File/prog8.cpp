#include<iostream>
#include<vector>
using namespace std;

pair<int,int> selectionSort(vector<int> &nums){
    pair<int,int> ans;
    for(int i = 0; i < nums.size() -1; i++){
        int min = i;
        for(int j= i+1; j<nums.size(); j++){
            ans.first++; //comparisons
            if(nums[j] < nums[min]){
                min = j;
            }
        }
        if(i != min){
            ans.second++;//shifts
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
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
        pair<int,int> ans = selectionSort(nums);

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