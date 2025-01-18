#include<bits/stdc++.h>
using namespace std;
vector <int> movezeros(vector <int> vec,int n)
{
    int i=0,j=-1;
    for(i=0;i<n;i++)
    {
        if(vec[i]==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1) return vec;
    for(int i=j+1;i<n;i++)
    {
        if(vec[i]!=0)
        {
            swap(vec[i],vec[j]);
            j++;
        }
    }
    return vec;
}
vector <int> another(vector <int> vec,int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(vec[i]!=0)
        {
            swap(vec[i],vec[count++]);
        }
    }
    return  vec;
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
    vector <int> ans=movezeros(vec,n);
    for(auto it:ans)
    {
        cout<<it<<" ";

    }
    cout<<endl;
    ans=another(vec,n);
    for(auto it:ans)
    {
        cout<<it<<" ";

    }
}