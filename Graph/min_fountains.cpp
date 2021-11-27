#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
int n;
cin>>n;
int a[n],i,range[n][2],j;
for (i=0;i<n;i++)
{
    cin>>a[i];
}
for(i=0;i<n;i++)
{
//range[i][0] = max(0,i-a[i]);
//range[i][1] = min(n-1,i+a[i]);
range[i][0] =0;
range[i][1] =1;
}
for(i=0;j<n;i++)
{
    for(j=0;j<2;j++)
    {
        cout<<range[i][j]<<" ";
    }
    cout<<endl;
}
    return 0;
}
