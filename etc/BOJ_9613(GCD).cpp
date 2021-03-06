#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int func(int a, int b){
    
    int c;  
    while(b!=0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
 
    int n;  
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        int num;
        long long sum=0;
        
        cin>>num;
        vector<int> v(num);
        
        for(int j=0; j<num; j++){
            cin>>v[j];
        }
        
        for(int l1=0; l1<num-1; l1++){
            for(int l2 = l1+1; l2<num; l2++){
                
                int c;
                
                if(v[l1]>=v[l2]) c = func(v[l1],v[l2]);
                else c = func(v[l2],v[l1]);
                
                sum +=c;               
            } 
        }
        
        cout<<sum<<"\n";
    }

    return 0;
}
