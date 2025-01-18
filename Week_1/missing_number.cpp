#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        vec.push_back(c);
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+vec[i];
    }
    cout<<(((n+1)*(n+2))/2)-sum<<endl;
}