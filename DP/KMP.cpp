#include <iostream>
#include <vector>
using namespace std;

// Compute the Longest Prefix Suffix (LPS) array
void computeLPS(const string &pattern, vector<int> &lps)
{
    int m = pattern.size();
    lps.resize(m);

    int j = 0; // Length of the previous longest prefix suffix

    for (int i = 1; i < m; ++i)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = lps[j - 1];
        }

        if (pattern[i] == pattern[j])
        {
            j++;
        }

        lps[i] = j;
    }
}

// KMP pattern matching
void kmpSearch(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();

    vector<int> lps;
    computeLPS(pattern, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;

    kmpSearch(text, pattern);

    return 0;
}
