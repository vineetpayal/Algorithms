#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMaxCount(int ind, int N, vector<int> &prices, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return N * prices[0];
    }

    if (dp[ind][N] != -1)
    {
        return dp[ind][N];
    }

    int notTake = 0 + findMaxCount(ind - 1, N, prices, dp);
    int take = INT_MIN;

    if ((ind + 1) <= N)
    {
        take = prices[ind] + findMaxCount(ind, N - (ind + 1), prices, dp);
    }
    return dp[ind][N] = max(take, notTake);
}

int rodCut(vector<int> &prices, int N)
{
    vector<vector<int>> dp(N, vector<int>(N + 1, -1));
    return findMaxCount(N - 1, N, prices, dp);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> prices(N);
        for (int i = 0; i < N; i++)
        {
            cin >> prices[i];
        }

        int maxProfit = rodCut(prices, N);
        cout << maxProfit << endl;
    }
}