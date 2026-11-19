#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> closestDigit = {
    {0, 8},
    {1, 7},
    {2, -1},
    {3, 9},
    {4, -1},
    {5, 6},
    {6, 5},
    {7, 1},
    {8, 9},
    {9, 8}};

bool isValidTime(const string &t)
{
    int hour = (t[0] - '0') * 10 + (t[1] - '0');
    int minute = (t[3] - '0') * 10 + (t[4] - '0');
    return hour >= 0 && hour <= 12 && minute >= 0 && minute < 60;
}

int getCost(const string &a, const string &b, int x, int y)
{
    int h1 = (a[0] - '0') * 10 + (a[1] - '0');
    int m1 = (a[3] - '0') * 10 + (a[4] - '0');
    int h2 = (b[0] - '0') * 10 + (b[1] - '0');
    int m2 = (b[3] - '0') * 10 + (b[4] - '0');
    return abs(h1 - h2) * x + abs(m1 - m2) * y;
}

string getNearestTime(const string &s, int x, int y)
{
    string best = "";
    int minCost = INT_MAX;

    for (int i = 0; i < 5; i++)
    {
        if (s[i] == ':')
            continue;

        int d = s[i] - '0';
        if (closestDigit[d] == -1)
            continue;

        string candidate = s;
        candidate[i] = char('0' + closestDigit[d]);

        if (!isValidTime(candidate))
            continue;

        int cost = getCost(s, candidate, x, y);
        if (cost < minCost || (cost == minCost && candidate < best))
        {
            minCost = cost;
            best = candidate;
        }
    }

    if (best.empty())
        return "No closest valid time possible";
    return best;
}

int main()
{

    string s;
    int x, y;
    getline(cin, s);
    cin >> x >> y;

    cout << getNearestTime(s, x, y);
    return 0;
}
