#include<iostream>
using namespace std;
int findGCD(int a,int b){   //a>b Always
    //base condition:
    if(b==0)return a;
    //compute:
    return findGCD(b,a%b);
}
int findLCM(int a,int b){  //a>b Always
    return (a*b)/findGCD(a,b);
}
int main(){
    int a,b;
    cin>>a>>b;
    if(a<b){
        swap(a,b);
    }
    // cout<<a<<" "<<b;
    cout<<findGCD(a,b)<<endl;
    cout<<findLCM(a,b);
}