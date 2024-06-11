// N meetings in a room;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting
{
    int start;
    int end;
    int pos;
};

bool cmp(meeting m1, meeting m2)
{
    if (m1.end < m2.end)
    {
        return true;
    }
    else if (m1.end > m2.end)
    {
        return false;
    }
    else if (m1.pos <= m2.pos)
    {
        return true;
    }
    return false;
}

int maxMeetings(int s[], int e[], int n)
{
    struct meeting meetings[n];
    for (int i = 0; i < n; i++)
    {
        meetings[i].start = s[i];
        meetings[i].end = e[i];
        meetings[i].pos = i + 1;
    }

    sort(meetings, meetings + n, cmp);

    int limit = meetings[0].end;
    int count = 0;

    for (int i = 1; i < n; i++)
    {
        if (meetings[i].start > limit)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    int s[n];
    int e[n];

    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> e[i];
    }

    int ans = maxMeetings(s, e, n);
    cout << "Max Meetings that can be performed: " << ans << endl;
}