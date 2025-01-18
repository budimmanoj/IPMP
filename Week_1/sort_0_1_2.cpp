#include<bits/stdc++.h>
using namespace std;
vector <int> sort_0_1_2(vector <int> vec,int n)
{
    int count0=0;
    int count1=0;
    for(int i=0;i<n;i++)
    {
        if(vec[i]==0) count0++;                                        //TC->O(2N) SC->O(1)
        else if(vec[i]==1) count1++;
    }
    for(int i=0;i<n;i++)
    {
        if(i<count0) vec[i]=0;
        else if(i<(count0+count1)) vec[i]=1;
        else vec[i]=2;
    }
    return vec;
}
vector <int> dutch_national_flag(vector <int> vec,int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)                           //TC->O(N) SC->O(1)
    {
        if(vec[mid]==0)
        {
            swap(vec[low],vec[mid]);
            low++;
            mid++;
        }
        else if(vec[mid]==1)
        {
            mid++;
        }
        else  
        {
            swap(vec[mid],vec[high]);
            high--;
        }
    }
    return vec;
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
    vector<int> ans=sort_0_1_2(vec,n);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    ans=dutch_national_flag(vec,n);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}