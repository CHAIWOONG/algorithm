#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001

using namespace std;

int arr[MAX];

void primeArr(){
    
    for(int i=1; i<=MAX; i++)
        arr[i] = i;
    
    for(int i=2; i<=MAX; i++)
    {
        if(arr[i]==0) continue;
        for(int j=i+i; j<=MAX; j+=i){
            arr[j] = 0;
        }
    }
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    primeArr();
    
    while(1){
        
        cin>>n;
        if(n==0) break;

        int a=0,b=0;
        
        for(int i=3; i<=n; i++){
            
            if(arr[i] !=0 && arr[n-arr[i]]!=0 ) 
            {
                a = arr[i];
                b = arr[n-arr[i]];
                break;
            } 
        }
        
        if(a!=0 && b!=0) cout<<n<<" = "<<a<<" + "<<b;
        else cout<<"Goldbach's conjecture is wrong.";
        cout<<"\n";
  
    }
    return 0;
}
