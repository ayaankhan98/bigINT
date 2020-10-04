#include<iostream>
using namespace std;
int main()
{
    int no;
    cin>>no;
    int rev=0;
    while(no>0)
    {
        rev=rev*10 + no%10;
        no=no/10;
    }
    cout<<rev;
}