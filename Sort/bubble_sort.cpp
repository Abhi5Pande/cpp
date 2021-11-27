#include<iostream>
#include<vector>
using namespace std;
void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void bubble_sort(vector<int> v , int n)
{
int i,j;
for(i=0;i<n;i++)
{
    for(j=0;j<n-i-1;j++)
    {
        if(v[j] > v[j+1])
            swap(v[j],v[j+1]);
    }
}
for(i = 0 ; i < n; i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void bubble_sort_desc(vector<int> v , int n)
{
int i,j;
for(i=0;i<n;i++)
{
    for(j=0;j<n-i-1;j++)
    {
        if(v[j] < v[j+1])
            swap(v[j],v[j+1]);
    }
}
for(i = 0 ; i < n; i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int main()
{
    vector<int> v = {4,2,3,1,6,5};
    int n  = v.size();
    bubble_sort(v,n);
    bubble_sort_desc(v,n);   
}