#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

long long func(long a, long b){
    
    long long c;  
    while(b!=0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
 
    long long a,b;
    long long c;
    cin>>a>>b;
    
    if(a>=b) c = func(a,b);
    else  c = func(b,a);
    
    for(long long i=1; i<=c;i++){
        cout<<"1";
    }
    
    return 0;
}
