#include<bits/stdc++.h>
using namespace std;
string column_title(int  num)
{
    string title;
    while(num>0)
    {
        int rem=(num-1)%26;
        char val='A'+rem;
        num=(num-1)/26;
        title=title+val;
    }
    return title;
}
int main()
{
    int num;
    cin>>num;
    cout<<column_title(num);
}