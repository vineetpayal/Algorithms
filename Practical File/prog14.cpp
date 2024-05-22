#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findSum(vector<int> nums, int key){
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;

    while(i < j){
        if(nums[i] + nums[j] == key){
            cout<<nums[i]<<" "<<nums[j]<<endl;
            return;
        }else if(nums[i] + nums[j] < key){
            i++;
        }else{
            j--;
        }
    }
    cout<<"No such Element Exist"<<endl;
}

int main(){
    int T;
    cin>>T;

    while(T--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i = 0; i<n; i++){
            cin>>nums[i];
        }
        int key;
        cin>>key;
        findSum(nums,key);
    }
    return 0;
}