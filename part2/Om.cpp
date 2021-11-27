#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int solve(int l , int r , int a[],int n)
{
int arr[r-l+1],k=0;
unordered_map<int,int> m(0);
for(int i = l-1 ; i < r ; i++)
    {
        arr[k++] = a[i];
        m[a[i]]++;
    }
sort(arr,arr+r-l+1);
int s_max = arr[r-l];
for(auto x : m)
{
    if(x.second == s_max)
        return x.first;
}
return 0;10
}
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
    cin>>a[n];
int t;
while(t--){
    int l,r;
    cin>>l>>r;
    int x = solve(l,r,a,n);
    cout<<x<<endl;
}
}
