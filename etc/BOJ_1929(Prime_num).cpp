#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int m,n;
    int arr[1000001];
    
    cin>>m>>n;
    
    for(int i=1; i<=n; i++)
        arr[i] = i;
    
    for(int i=2; i<=n; i++)
    {
        if(arr[i]==0) continue;
        for(int j=i+i; j<=n; j+=i){
            arr[j] = 0;
        }
    }
    
    for(int i=m; i<=n; i++)
    {
        if(arr[i] !=0 && i!=1) cout<<arr[i]<<"\n"; 
    }
    
    return 0;
}
