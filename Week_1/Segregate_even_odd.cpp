#include<bits/stdc++.h>
using namespace std;
vector <int> segregate(vector <int> vec,int n)
{
    int even=0;
    vector <int> arr;                                     // TC--> O(2N)  SC--> O(N)
    for(int i=0;i<n;i++)
    {
        arr.push_back(0);
    }
    for(int i=0;i<n;i++)
    {
        if(vec[i]%2==0) even++;
    }
    int e=0,o=0;
    for(int i=0;i<n;i++)
    {
        if(vec[i]%2==0) 
        {
            arr[e]=vec[i];
            e++;
        }
        else
        {
            arr[even+o]=vec[i];
            o++;
        }
    }
    return arr;
}

vector<int> hoares(vector<int> vec,int n)
{
    int l=0;
    int h=n-1;
    while(l<h)
    {
        if(vec[l]%2!=0)
        {
            if(vec[h]%2==0)
            {
                swap(vec[l],vec[h]);
                l++;
                h--;
            }
            else h--;
        } else {l++;}
    }
    return vec;
}
vector <int> additional(vector <int> vec,int n)
{
    int j=-1;
    for(int i=0;i<n;i++)
    {
        if(vec[i]%2!=0)
        {
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++)
    {
       if(vec[i]%2==0)
       {
        swap(vec[i],vec[j]);
        j++;
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
    vector<int> ans=segregate(vec,n);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    ans=hoares(vec,n);
    cout<<endl;
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    ans=additional(vec,n);
    cout<<endl;
    for(auto it: ans)
    {
        cout<<it<<" ";
    }

}