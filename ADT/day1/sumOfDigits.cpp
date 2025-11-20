//first rule always read input and output format properly
//if you done that you are half-way done...
#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int num){  //retunns the sum of digits
    if(num<0){
        return -1*sumOfDigits((-1)*num);
    }
    //base condition:
    if(num>=0 && num<=9){  
        return num;
    }
    //compute:
    return (num%10)+sumOfDigits(num/10);
}
void solve() {
    int num;
   cin>>num;
   int temp=num;
   int sum=0;
   while(temp!=0){
      sum+=(temp%10);
      temp/=10;
   }
   cout<<sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        // solve();  //normal approch
        int num;cin>>num;  
        cout<<sumOfDigits(num);  //recursive approach
    }
    return 0;
}