#include <iostream>
#include <algorithm>
#include <list>
#include <deque> 
#include <vector> 
#include <string> 

using namespace std;


deque<int> makeArr(string s){
    
    string num;
    deque<int> dq;
    //int a;
    
    for(int i=1; i<s.size()-1; i++){ // 입력 형식에 따라서 앞,뒤의 [,]는 제거한 채로 파악
        
        if((s[i] >='0' && s[i] <= '9') ){ // 문자열 원소가 숫자일 경우 일단 숫자 변수에 추가
            
            num+=s[i];
        }
        else{ // 문자열 원소가 ','일 경우 그 앞에 까지 저장된 num 변수를 잘라서 숫자로 덱에 추가
            
            int a = stoi(num);
            dq.push_back(a);
            num = "";
        }
    }
    
    if(num!="") // 마지막 남은 배열의 숫자에 대해서 덱에 추가한다.
    {
        int a = stoi(num);
        dq.push_back(a);
        num = "";
    }
    
    return dq;
}


void PrintDeq(const deque<int>& dq){ // 인자로 입력받은 덱에 대한 출력 형식에 맞춘 출력문
    
    cout << '[';
	for (int i = 0; i < dq.size(); i++) {
		cout << dq[i];
		if (i != dq.size() - 1) cout << ',';
	}
	cout << ']' << "\n";
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T--){
        
        string func,arr;
        int n, rev=0,flag=0;
        deque<int> deq;
        
        cin>>func>>n>>arr;
        
        deq = makeArr(arr);

        for(int i=0; i<func.size(); i++){

            
            if(func[i]=='R'){
                rev++;        //R의 입력 만큼 덱을 reverse하게 되면 시간복잡도가 매우 증가한다.
                              // 이에 따라서 R의 입력 횟수를 먼저 세서 홀수, 짝수로 추후에 파악
            }
            else if(func[i]=='D'){
                if(deq.empty()) flag=1;  // 덱이 비어있는데 D가 입력되면 오류 상황이므로 flag 변수로 판단
                if(rev%2!=0)deq.pop_back(); //R이 홀수일 경우 실제로 뒤집히고, 짝수일 경우 다시 돌아올 것임
                else deq.pop_front();     // 뒤집히면 앞에서 pop, 뒤집히지 않으면 뒤에서 pop하면 됨
            }
        }

        if(flag) cout<<"error\n";
        else {
            if(rev%2!=0) reverse(deq.begin(), deq.end()); // rev가 홀수로 뒤집힌 경우이므로 한번만 뒤집으면 됨 
            PrintDeq(deq); // 이에 대한 덱의 출력
        }
    }
    
    
    return 0;
}
