#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool hasDuplicates(vector<int> nums){
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == nums[i-1]){
            return true;
        }
    }
    return false;
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

        if(hasDuplicates(nums)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        cout<<endl;
    }
    return 0;
}