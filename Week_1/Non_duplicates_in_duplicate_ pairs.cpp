#include<bits/stdc++.h>
using namespace std;
void nonduplicates(vector<int> vec,int n)
{
    int xr=0;
    for(int i=0;i<n;i++)
    {
        xr=xr^vec[i];
    }                                       // Time complexity : O(2N+B) B=Bit length 
                                            // Space complxity :O(1)
    int bitno=0;
    while(1)
    {
        if((xr&(1<<bitno))!=0) break;
        bitno++;
    }
    int zero=0,one=0;
    for(int i=0;i<n;i++)
    {
        if((vec[i]&(1<<bitno))!=0)
        one=one^vec[i];
        else 
        zero=zero^vec[i];
    }
    if(one>zero)
    swap(one,zero);
    cout<<zero<<" "<<one<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector <int> vec;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        vec.push_back(c);
    }
   nonduplicates(vec,n);
}