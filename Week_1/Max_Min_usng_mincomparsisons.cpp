#include<bits/stdc++.h>
using namespace std;
vector <int> brute(vector <int>vec ,int n)
{
    int maxi,mini;
    if(vec[0]>vec[1])
        {
            maxi=vec[0];
            mini=vec[1];
        }
        else                                         // Time complexity -> O(N) SC->O(1)  No of comparsions 2*(n-2)+1
        {
            maxi=vec[1];
            mini=vec[0];
        }
        for(int i=2;i<n;i++)
        {
            if(vec[i]>maxi) maxi=vec[i];
            if(vec[i]<mini) mini=vec[i];
        }
        return {mini,maxi};
}
vector <int> usingpairs(vector<int> vec,int n)
{
    int i;
    int maxi,mini;
    if(n%2==0)
    {
        if(vec[0]>vec[1])
        {                      // Time complexity -> O(N) SC->O(1)  
                               //No of comparsions 3*(n-2)/2+1 (n=even)
                               //                  3*(n-1)/2  (n=odd)
            maxi=vec[0];
            mini=vec[1];
        }
        else
        {
            maxi=vec[1];
            mini=vec[0];
        }
        i=2;
    }
    else
    {
        maxi=mini=vec[0];
        i=1;
    }
    while(i<n-1)
    {
        if(vec[i]<vec[i+1])
        {
            maxi=max(vec[i+1],maxi);
            mini=min(vec[i],mini);
        }
        else
        {
            maxi=max(maxi,vec[i]);
            mini=min(mini,vec[i+1]);
        }
        i=i+2;
    }
    return {mini,maxi};
}
vector <int> divide(vector<int> vec,int low,int mid,int high)
{
    if(low==high) return {vec[low],vec[low]};
    if(high==low+1)
    {
        int maxi,mini;
        if(vec[low]>vec[high])
        {
            maxi=vec[low];
            mini=vec[high];
        }
        else
        {
            mini=vec[low];
            maxi=vec[high];
        }
        return {mini,maxi};
    }
    vector<int> left=divide(vec,low,(low+mid)/2,mid);
    vector<int> right=divide(vec,mid+1,(mid+high+1)/2,high);
    int maxi,mini;
     if(right[0]>left[0]) mini=left[0];
        else mini=right[0];
        if(left[1]<right[1]) maxi=right[1];
        else maxi=left[1];
        return {mini,maxi};
}
vector <int> recursion(vector <int> vec,int n)
{
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    vector <int> ans=divide(vec,low,mid,high);
    return ans;
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
    vector<int> ans =usingpairs(vec,n);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    ans=brute(vec,n);
    cout<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    ans=recursion(vec,n);
    cout<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }

}