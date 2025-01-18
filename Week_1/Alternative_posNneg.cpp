#include<bits/stdc++.h>
using namespace std;
vector <int> Altrnate_pos_and_neg(vector<int> vec,int n)
{
    vector <int> pos,neg;
    for(int i=0;i<n;i++)
    {
        if(vec[i]>=0)
        {
            pos.push_back(vec[i]);
        }
        else 
        {
            neg.push_back(vec[i]);
        }
    }
    int siz=min(pos.size(),neg.size());
    for(int i=0;i<2*siz;i++)
    {
        if(i%2==0)
        {
            vec[i]=pos[(i/2)];
        }
        else
        {
            vec[i]=neg[(i-1)/2];
        }
    }
    int i=2*siz;
    if(pos.size()>neg.size())
    {
        int posindex=(i/2);
        while(i<n)
        {
            vec[i++]=pos[posindex++];
        }
    }
    else
    {
        int negindex=(i/2);
        while(i<n)
        {
            vec[i++]=neg[negindex++];
        }
    } 
    return vec;
}
vector <int> alternative(vector <int> vec,int n)
{
    vector <int> pos,neg;
    for(int i=0;i<n;i++)
    {
        if(vec[i]>0)
        {
            pos.push_back(vec[i]);
        }
        else 
        {
            neg.push_back(vec[i]);
        }
    }
    int pindex=0,nindex=0;
    int i=0;
    int clock=1;
    while((pindex<pos.size())&&(nindex<neg.size()))
    {
        if(clock)
        {
            vec[i]=pos[pindex];
            i++;
            pindex++;
            clock=0;
        }
        else
        {
            vec[i]=neg[nindex];
            i++;
            nindex++;
            clock=1;
        }
    }
    while(pindex<pos.size())
    {
        vec[i++]=pos[pindex++];
    }
    while(nindex<neg.size())
    {
        vec[i++]=neg[nindex++];
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
    vector<int> ans=Altrnate_pos_and_neg(vec,n);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    ans=alternative(vec,n);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
}