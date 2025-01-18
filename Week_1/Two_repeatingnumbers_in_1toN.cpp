#include<bits/stdc++.h>
using namespace std;
vector <int> usingsorting(vector <int> vec,int n)
{
    sort(vec.begin(),vec.end());                            //TC->O(NlogN) SC->O(2)
    vector <int> ls;
    for(int i=0;i<n-1;i++)
    {
        if(vec[i]==vec[i+1]) ls.push_back(vec[i]);
        if(ls.size()==2)  return  ls;
    }
    return ls;
}
vector <int> usingxor(vector<int> vec,int n)
{
    int xr=0;                                  //TC->O(3N) SC->O(1)
    for(int i=0;i<n;i++)
    {
        if(i>1) xr=xr^(i-1);
        xr=xr^vec[i];
    }
    int bitno=0;
    while(1)
    {
        if((xr&(1<<bitno))!=0) break;
        bitno++;
    }
    int one=0,zero=0;
    for(int i=0;i<n;i++)
    {
        if((vec[i]&(1<<bitno))!=0) one=one^vec[i];
        else zero=zero^vec[i];
    }
    for(int i=1;i<n-1;i++)
    {
        if((i)&(1<<bitno)!=0) one=one^i;
        else zero=zero^i;
    }
    return {zero,one};
}
vector <int> marking(vector <int> vec,int n)
{
    vector <int> ans;
    for(int i=0;i<n;i++)
    {
        int index=abs(vec[i]);
        if(vec[index]<0)
        {                                        //TC->O(N) SC->O(1)
            ans.push_back(index);
            if(ans.size()==2) return ans;
        }
        else
        {
            vec[index]=vec[index]*-1;
        }
    }
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
    vector <int> ans=usingsorting(vec,n);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    ans=usingxor(vec,n);
    cout<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    ans=marking(vec,n);
    cout<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }

}