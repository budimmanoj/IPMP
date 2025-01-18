#include<bits/stdc++.h>
using namespace std;
int SingleElement(vector <int> vec,int n)
{
    int xr=0;
    for(auto it: vec)
    {
        xr=xr^it;
    }
    return xr;
}
int brute(vector <int> vec,int n)
{
    int count;
    for(int i=0;i<n;i++)
    {
        count=0;
        for(int j=0;j<n;j++)
        {
            if(vec[i]==vec[j]) count++;
        }
       if(count==1) return vec[i];
    }
    return -1;
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
     cout<<SingleElement(vec,n);
     cout<<endl;
     cout<<brute(vec,n);
     return 0;
}