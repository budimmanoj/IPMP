#include<iostream>
#include<vector>
using namespace std;
vector<int> union_array(vector<int> arr1,vector<int> arr2)
{
    vector<int> unio;
    int i=0,j=0;
    int n1=arr1.size(),n2=arr2.size();
    while(i<n1&&j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            if(unio.size()==0||unio.back()!=arr1[i])
            {
                unio.push_back(arr1[i]);
            }
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            if(unio.size()==0||unio.back()!=arr2[j])
            {
                unio.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n1)
    {
        if(unio.back()!=arr1[i]) 
        unio.push_back(arr1[i]);
        i++;
    }
    while(j<n2)
    {
        if(unio.back()!=arr2[j]) 
        unio.push_back(arr2[j]);
        j++;
    }
    return unio;
}
vector<int> intersection(vector<int> arr1,vector<int> arr2)
{
    vector<int> inter;
    int i=0,j=0;
    int n1=arr1.size(),n2=arr2.size();
    while(i<n1&&j<n2)
    {
        if(arr1[i]==arr2[j])
        {
            inter.push_back(arr1[i]);
            i++,j++;
        }
        else if(arr1[i]<arr2[j]) i++;
        else j++;
    }
    return inter;
}

//main fucn
int main()
{
    int n1,n2;
    cin>>n1;
    vector<int> arr1;
    for(int i=0;i<n1;i++) 
    {
        int c;
        cin>>c;
        arr1.push_back(c);
    } 
    cin>>n2;
    vector<int> arr2;
     for(int i=0;i<n2;i++) 
    {
        int c;
        cin>>c;
        arr2.push_back(c);
    }
    vector<int>unio=union_array(arr1,arr2);
    vector <int> inter=intersection(arr1,arr2);
    for(auto it:unio)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it: inter )
    {
        cout<<it<<" ";
    }
}