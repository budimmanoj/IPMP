#include<bits/stdc++.h>
using namespace std;
vector<int> usingxor(vector<int> vec,int n)
{
    int xr=0;
    for(int i=0;i<n;i++)
    {
        xr=xr^vec[i];
        xr=xr^(i+1);
    }
    int bitno=0;
    while(1)
    {
        if((xr&(1<<bitno))!=0) break;
        bitno++;
    }
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++)
    {
        if((vec[i]&(1<<bitno))==0)
        {
            zero=zero^vec[i];
        }
        else one=one^vec[i];
    }
    for(int i=0;i<n;i++)
    {
        if(((i+1)&(1<<bitno))==0) zero=zero^(i+1);
        else one =one^(i+1);
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(vec[i]==zero)
        {
            count++;
        }
    }
    if(count==2) return {zero,one};
    return {one,zero};
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
    int sum=0;
    int ssum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+vec[i];
        ssum=ssum+vec[i]*vec[i];
    }
    int diff_of_sums=(n*(n+1))/2-(sum); //d1
   int diff_of_sumsquares=(n*(n+1)*(2*n+1))/6-ssum;  //d2
   int d1=diff_of_sums;
   int d2=diff_of_sumsquares;
    int b=((d2/d1)+d1)/2;
    int a=((d2/d1)-d1)/2;
    cout<<a<<" "<<b<<endl;

    vector <int> v=usingxor(vec,n);
    for(auto it:v)
    {
        cout<<it<<endl;
    }
}