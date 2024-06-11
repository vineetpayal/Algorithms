#include <iostream>
#include <vector>
using namespace std;

int solve(string text1, string text2, int i, int j, vector<vector<int>> &dp)
{
    if (i == text1.length() || j == text2.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (text1[i] == text2[j])
        return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1, dp);
    else
        return dp[i][j] = max(solve(text1, text2, i + 1, j, dp), solve(text1, text2, i, j + 1, dp));
}

string LCS(string text1, string text2)
{
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    int length = solve(text1, text2, 0, 0, dp);

    string longestString = "";
    int i = 0, j = 0;
    while (i < text1.length() && j < text2.length())
    {
        if (text1[i] == text2[j])
        {
            longestString += text1[i];
            i++;
            j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return longestString;
}

int main()
{
    string text1, text2;
    getline(cin, text1);
    getline(cin, text2);

    string longestString = LCS(text1, text2);
    cout << "Longest common subsequence: " << longestString << endl;
    cout << "Length: " << longestString.length() << endl;

    return 0;
}
