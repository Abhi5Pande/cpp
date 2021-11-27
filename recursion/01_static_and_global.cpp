// static and global variable are initialized only once, i.ie only 1 copy of it is made and evenin the retracing of the recursive function, its value does not change
#include<iostream>
using namespace std;
int fun(int n)
{
    static int x = 0;
    if(n>0)
    {
        x++;
        return fun(n-1) + x;
    }
}

int main()
{
int r = fun(6);
cout<<r;
}