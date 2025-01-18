#include<bits/stdc++.h>
using namespace std;
bool palindrome(int x)
{
    int n=x;
    int rev=0;
    while(1)
    {
        int rem=n%10;
        n=n/10;
        rev=rev*10+rem;
        if(n==0) break;
    }
    if(rev==x) return 1;
    return 0;
}
int main()
{
    int x;
    cin>>x;
    if(palindrome(x)) cout<<"palindrome";
    else cout<<"not a palindrome";
    return 0;
}