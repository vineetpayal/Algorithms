#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool cmp(Item a, Item b)
{
    int r1 = (double)a.value / (double)a.weight;
    int r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

int fractionalKnapSack(Item arr[], int n, int w)
{
    sort(arr, arr + n, cmp);

    int currWeight = 0;
    int finalValue = 0;

    for (int i = 0; i < n; i++)
    {
        if (currWeight + arr[i].weight < w)
        {
            currWeight = currWeight + arr[i].weight;
            finalValue = finalValue + arr[i].value;
        }
        else
        {
            int remain = w - arr[i].weight;
            finalValue = finalValue + (double)(arr[i].value / arr[i].weight) * remain;
            break;
        }
    }
    return finalValue;
}

int main()
{
    int n;
    cin >> n;
    Item arr[n];
    for (int i = 0; i < n; i++)
    {
        int value, weight;
        cin >> value >> weight;
        arr[i].value = value;
        arr[i].weight = weight;
    }
    int w;
    cin >> w;
    int ans = fractionalKnapSack(arr, n, w);
    cout << ans << endl;
    return 0;
}