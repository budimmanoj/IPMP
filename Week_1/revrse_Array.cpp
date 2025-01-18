#include<bits/stdc++.h>
using namespace std;
void reverse(vector <int> & vec,int n)
{
   
    int i=0,j=n-1;
    while(i<j)
    {
        swap(vec[i],vec[j]);
        i++,j--;
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
    reverse(vec,n);
    for(auto it :vec)
    {
        cout<<it<<" ";
    }
    return 0;
}