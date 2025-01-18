#include<bits/stdc++.h>
using namespace std;
vector<int> hashing(vector<int> vec,int n)
{
    map <int,int> freq;
    vector<int> ls;
    for(int i=0;i<n;i++)
    {
        freq[vec[i]]++;
        if(freq[vec[i]]>(n/3))
        {
            ls.push_back(vec[i]);
        }
        if(ls.size()==2) break;
    }
    return ls;
}
vector <int> moors(vector<int> vec,int n)
{
    
    int el1=INT_MAX;
    int el2=INT_MAX;
    int count1=0;
    int count2=0;
    vector<int> ls; 
    for(int i=0;i<n;i++)
    {
        if(count1==0&&el2!=vec[i])
        {
            count1++;
            el1=vec[i];
        }
        else if(count2==0&&el1!=vec[i])
        {
            count2++;
            el2=vec[i];
        }
        else if(el1==vec[i]) count1++;
        else if(el2==vec[i]) count2++;
        else 
        {
            count1--;
            count2--;
        }
    }
    count1=0;
    count2=0;
    for(int i=0;i<n;i++)
    {
        if(el1==vec[i])  count1++;
        if(el2==vec[i]) count2++;
    }
    int target=(n/3);
    if(count1>target)
    {
        ls.push_back(el1);
    }
   if(count2>target) ls.push_back(el2);
    if(ls.size()==0) return {-1,-1};
    return ls;

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
    vector <int> ans=hashing(vec,n);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    ans=moors(vec,n);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}
