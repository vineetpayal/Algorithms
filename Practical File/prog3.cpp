#include<bits/stdc++.h>
using namespace std;

int jumpSearch(vector<int>& arr, int key,int & count){
    int n = arr.size();
    int start = 0, end = 2;
    while(end < n && arr[end] <= key){
        count++;
        start = end;
        end = end*2;
        if(end > n-1)
            end = n;
    }
    for(int i=start; i<end ;i++){
        count++;
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main(){
    int T, size = 0, key;
    
    cin>>T;
    
    while(T--){       
        cin>>size;
        vector<int>nums(size);
        int count = 0;
        for(int i=0;i<size;i++)
            cin>>nums[i];
        cin>>key;
        if(jumpSearch(nums, key, count) != -1)
            cout<<"Present "<< count<<endl;
        else
            cout<<"Not Present"<< count<<endl;
    }
    return 0;
}
