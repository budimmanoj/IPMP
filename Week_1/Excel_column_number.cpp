#include<iostream>
using namespace std;
int column_number(string title)
{
    int n=title.length();
    int val=0;
    for(int i=0;i<n;i++)
    {
        val=val*26+(title[i]-'A'+1);
    }
    return val;
}
int main()
{
    string s;
    cin>>s;
    cout<<column_number(s);
    return 0;
}