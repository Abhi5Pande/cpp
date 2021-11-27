#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int solve(vector<int> v, int res)
{
    int vsize = v.size();
    sort(v.begin(), v.end());
    int min = v[vsize - 1];
    int l = 0, r = 0;
    for (int i = vsize - 1; i > 0; i--)
    {
        int j = 0;
        int sub = v[i] - v[0];
        while (sub >= res || j < v.size())
        {
            sub = v[i] - v[j];
            
            if (abs(sub-res) < min)
            {
                min = abs(sub-res);
                r = i;
                l = j;
            }
            j++;
        }
    }
    return v[r] + v[l];
}
int main() {
    int res, n, i;
    cin >> res >> n;
    vector<int> v;
    for (i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    int x = solve(v, res);
    cout << x << endl;
}