#include <iostream>
using namespace std;

void permutate(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << " ";
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[i], s[l]);
            permutate(s, l + 1, r);
            swap(s[i], s[l]);
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        permutate(s, 0, s.length() - 1);
        cout << endl;
    }
    return 0;
}
