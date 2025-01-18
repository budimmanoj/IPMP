#include<bits/stdc++.h>
using namespace std;
int usinghashing(vector <int> vec)
{
    int n=vec.size();
    map <int,int> mpp;
    for(int i=0;i<n;i++)  // map tc ->o(NlogM+M) sc ->o(m)
    {
        mpp[vec[i]]++;    // unordered tc ->o(N+M)   sc-> O(M)
    }
    for(auto it:mpp)
    {
        if(it.second%2==1)
        {
            return it.first;
        }
    }
    return -1;
}
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
    int xor_value=0;   //x^0=x and x^x=0
    for(int i=0;i<n;i++)
    {
       xor_value=(xor_value^vec[i]) ;
    }
    cout<<xor_value<<endl;
    cout<<usinghashing(vec)<<endl;
}