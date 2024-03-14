#include<iostream>
#include<vector>
using namespace std;

int diff(vector<int> nums,int key){
    int count = 0;
    for(int i = 0; i< nums.size();i++){
        for(int j = i+1; j< nums.size(); j++){
            if(nums[i] - nums[j] == key || nums[j] - nums[i] == key){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int size,key;
        cin>>size;
        vector<int> nums(size);
        for(int i = 0; i < size; i++){
            cin>>nums[i]; 
        }
        cin>>key;
        int count = diff(nums,key);
        cout<<"Count: "<<count<<endl;
    }
}