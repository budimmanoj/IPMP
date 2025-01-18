#include<bits/stdc++.h>
using namespace std;
int counting_sum_k(vector <int> vec,int n,int k)
{
    int sum=0,count=0;
    for(int i=0;i<n;i++)
    {                                                                      //TC->O(N^2)  SC->O(1)
        sum=0;
        for(int j=i;j<n;j++)
        {
            sum=sum+vec[j];
            if(sum==k) count++;
        }
    }
    return count;
}
int prefix_sum(vector <int> vec,int n,int k)
{
    unordered_map <int,int> mpp;                                           // TC->O(N)    SC->O(N)
    int sum=0;
    int count=0;
    mpp[0]=1;
    for(int i=0;i<n;i++)
    {
        sum=sum+vec[i];
        int diff=sum-k;
        count=count+mpp[diff];
        mpp[sum]++;
    }
    return count;

}
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector <int> vec;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        vec.push_back(c);
    }
    int  ans=counting_sum_k(vec,n,k);
   cout<<ans;
    cout<<endl;
    ans=prefix_sum(vec,n,k);
    cout<<ans;

}