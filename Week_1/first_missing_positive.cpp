#include<bits/stdc++.h>
using namespace std;
int hashing(vector<int> vec,int n)
{
    int hash[n+2]={0};
    for(int i=0;i<n;i++)
    {
        if(vec[i]>0&&(vec[i]<=n))                       // TC->O(2N)  SC->O(N)
        {
            hash[vec[i]]=1;
        }
    }
    for(int i=1;i<n+2;i++)
    {
        if(hash[i]==0) return i;
    }
}
int brute(vector  <int> vec,int n)
{
    for(int i=1;i<=n;i++)
    {                                           // TC->O(N^2) SC->O(1)
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if(i==vec[j])
            {
                flag=1;
                break;
            } 
        }
        if(!flag) return i;
    }
    return n+1;
}
int optimal(vector <int> vec,int n)
{
    for(int i=0;i<n;i++)
    {
        if(vec[i]<0) vec[i]=0;
    }                                                 // TC-> O(3N) SC->O(1)
    for(int i=0;i<n;i++)
    {
        int index=abs(vec[i]);
        if(index<=n&&index>0)
        {
            if(vec[index-1]==0)
            {
                vec[index-1]=INT_MIN;   //marking 0 as vewiwed inddex  if zero present in rcheck it is not marked 
            }
            else
            {
                vec[index-1]=-abs(vec[index-1]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(vec[i]>=0)return i+1;
    }
    return n+1;
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
    int ans=hashing(vec,n);
    cout<<ans<<endl;
    ans=brute(vec,n);
    cout<<ans<<endl;
    ans=optimal(vec,n);
    cout<<ans<<endl;
}