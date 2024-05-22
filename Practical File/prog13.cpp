#include <iostream>
#include <vector>
#include <map>
using namespace std;

void findMaxOccurence(vector<char>& arr) {
    vector<int> count(256, 0);

    for (char c : arr) {
        count[c]++;
    }

    int max_count = -1;
    char max_char;
    for (int i = 0; i < 256; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            max_char = i;
        }
    }

    if (max_count > 1) {
        cout << max_char << " - " << max_count << endl;
    } else {
        cout << "No Duplicates Present" << endl;
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<char> alphabets(n);
        for(int i = 0; i<n; i++){
            cin>>alphabets[i];
        }
        findMaxOccurence(alphabets);
    }
    return 0;
}