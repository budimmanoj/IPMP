#include<bits/stdc++.h>
using namespace std;
vector <int> usingsorting(vector<int> vec,int n)
{
    sort(vec.begin(),vec.end());
    int target=vec[0];
    vector <int> ans;                         // Time complexity : O(logN+N) 
                                                // Space complxity :O(N)
 
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(target==vec[i])
        {
            count++;
        }
        else
        {
            if(count%2==1)
            {
                ans.push_back(target);
                if(ans.size()==2) 
                {
                    if(ans[0]>ans[1])
                    {
                        swap(ans[0],ans[1]);
                    }return ans;
            }
            
                target=vec[i];
                count=1;
            
        }
    }
    
}
ans.push_back(vec[n-1]);
    if(ans[0]>ans[1])
    swap(ans[0],ans[1]);
    return ans;
}
void usingxor(vector<int> vec,int n)
{
    int xr=0;
    for(int i=0;i<n;i++)
    {
        xr=xr^vec[i];
    }                                       // Time complexity : O(2N+B) B=Bit length 
                                            // Space complxity :O(1)
    int bitno=0;
    while(1)
    {
        if((xr&(1<<bitno))!=0) break;
        bitno++;
    }
    int zero=0,one=0;
    for(int i=0;i<n;i++)
    {
        if((vec[i]&(1<<bitno))!=0)
        one=one^vec[i];
        else 
        zero=zero^vec[i];
    }
    if(one>zero)
    swap(one,zero);
    cout<<zero<<" "<<one<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        v.push_back(c);
   }
   vector <int> ans=usingsorting(v,n);
   for(auto it:ans)
   {
    cout<<it<<" ";
   }
   usingxor(v,n);
  
}
