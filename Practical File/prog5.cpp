#include <iostream>
#include <vector>
using namespace std;

vector<int> sequence(vector<int> nums)
{
    vector<int> ans;
    for(int i = 0; i<nums.size();i++){
        for(int j = i+1;j<nums.size(); j++){
            for(int k = j+1; k<nums.size(); k++){
                if((nums[i]+nums[j]) == nums[k]){
                    ans.push_back(i);
                    ans.push_back(j);
                    ans.push_back(k);
                    return ans;
                }
            }
        }
    }
    return ans;
}

int main(){
    int T;
    cin>>T;
    //Test cases
    while(T--){
        int size;
        cin>>size;
        vector<int> nums(size);
        for(int i = 0; i<size;i++){
            cin>>nums[i];
        }
        vector<int> ans = sequence(nums);
        if(!ans.empty()){
            for(int i = 0; i< ans.size(); i++){
                cout<<ans[i]<<", ";
            }
            cout<<endl;
        } else{
            cout<<"No sequence found"<<endl;
        }
    }
    return 0;
}