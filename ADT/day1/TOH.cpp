#include<iostream>
using namespace std;
void TOH(int n,int &c,char A='a',char B='b',char C='c'){
    if(n>0){
        TOH(n-1,c,A,C,B);
        c++;
        TOH(n-1,c,B,A,C);
    }
}
int main()
{
    int n;
    cin>>n;
    int c;
    TOH(n,c);
    cout<<c;
}