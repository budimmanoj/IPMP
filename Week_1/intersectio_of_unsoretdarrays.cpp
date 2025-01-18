#include<bits/stdc++.h>
using namespace std;
vector <int> usingsorting(vector <int> v1,int n,vector <int> v2,int m)
{
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int i=0,j=0;
    int prev=INT_MAX;
    vector <int> ans;
    while(i<n&&j<m)
    {
        if(v1[i]<v2[j])
        {
            i++;
            
        }
        else if(v1[i]>v2[j]) j++;
        else 
        {
            if(prev!=v1[i])
            {
                
            ans.push_back(v1[i]);
            
            prev=v1[i];
            }
            i++;
            j++;
        }
    }
    return ans;
}
vector <int> usingmap(vector <int> v1,int n,vector <int> v2,int m)
{
    unordered_map <int,int> mpp;
    vector <int> ans;
    for(int i=0;i<n;i++)
    {
        if(mpp.find(v1[i])==mpp.end())
        {
            mpp[v1[i]]++;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(mpp[v2[i]]==1)
        {
            ans.push_back(v2[i]);
            mpp[v2[i]]++;
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n;
    vector <int> vec1,vec2;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        vec1.push_back(c);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int c;
        cin>>c;
        vec2.push_back(c);
    }
    vector <int> ans=usingsorting(vec1,n,vec2,m);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
ans=usingmap(vec1,n,vec2,m);
 for(auto it:ans)
    {
        cout<<it<<" ";
    }
}