#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int> nums,int key){
    for(int i = 0; i<nums.size();i++){
        if(nums[i] == key){
            return i;
        }
    }
    return -1;
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
        int key;
        cin>>key;
        int pos = linearSearch(nums,key);
        if(pos != -1){
            cout<<"Present "<<pos +1<<endl;
        }else{
            cout<<"Not Present"<<endl;
        }
    }
    return 0;
}