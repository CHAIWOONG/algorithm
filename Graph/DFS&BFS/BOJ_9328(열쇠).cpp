#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int,int>;

int T,row,col,cnt=0,cflag=0;
string key;

char board[105][105];
int vis[105][105];
int keyArr[26]; // 알파벳 키 존재 배열

vector<pii> start;
queue<pii> q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bdReset(){ // testcase 초기화
    
    for(int i=0; i<row; i++) for(int j=0; j<col; j++){
        board[i][j] = 0; vis[i][j] = 0;
    }
    
    for(int i=0; i<26; i++) keyArr[i] = 0;
    
    while(!q.empty()) q.pop(); 
    start.clear();
    cflag =0;
    cnt =0;
}

void keyGet(){

    for(int i=0; i<key.length(); i++)
        if(key[i]!='0') keyArr[key[i]-'a'] ++;
}

int bfs(){
    
    while(!q.empty()){
        
        pii temp = q.front(); q.pop();
        
        if(board[temp.X][temp.Y]=='$') { // 해당 자리가 문서가 있는 곳일 때,
            cnt++;
            board[temp.X][temp.Y]='.';
            cflag=1;
        }
        
        for(int i=0; i<4; i++){
            int nx = temp.X + dx[i];
            int ny = temp.Y + dy[i];
            
            if(nx<0 || nx>=row || ny<0 || ny>=col) continue;
            if(vis[nx][ny] || board[nx][ny] == '*') continue;
            
            // 작동 조건
            if(board[nx][ny] == '.' || board[nx][ny]=='$'){ // 정상적인 상황일 때
                
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
            else if(board[nx][ny]>='A' && board[nx][ny]<='Z'){
                
                if(keyArr[board[nx][ny]-'A']){ // 대문자에 해당하는 key 존재 할 때
                    
                    cflag=1;
                    vis[nx][ny] = 1;
                    board[nx][ny]='.';
                    q.push({nx,ny});
                }
            }
            else if(board[nx][ny]>='a' && board[nx][ny]<='z'){
                
                keyArr[board[nx][ny]-'a'] ++; // 소문자이므로 키 획득
                cflag=1;
                vis[nx][ny] = 1;
                board[nx][ny]='.';
                q.push({nx,ny});
            }
        }
    }
    return cflag; // 변화가 생겼나 안생겼나 판단 flag
}

void doorOpen(const int& x, const int& y){
    
    if(board[x][y]>='A' && board[x][y]<='Z'){ // 대문자인 경우
        
        if(keyArr[board[x][y]-'A']){
            board[x][y]='.';
            start.push_back({x,y});
        }
    }
    else {// 소문자인 경우
        
        keyArr[board[x][y]-'a'] ++;
        board[x][y]='.';
        start.push_back({x,y});
    } 
}

void startGet(){ // board의 테두리에 대해서 문자의 상황에 따라서 시작점 가능 여부 판단
    
    for(int i=0; i<row; i++) for(int j=0; j<col; j++){
        if((i==0 || i==row-1 || j==0 || j==col-1)){
            if(board[i][j] == '.') start.push_back({i,j});
            else if(isalpha(board[i][j])) doorOpen(i,j);
            else if(board[i][j] == '$') start.push_back({i,j});
        }
    }
    
    for(auto& element:start){ // 시작점 queue에 push
        q.push({element.X,element.Y});
        vis[element.X][element.Y] =1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>T;
    
    while(T--){
        
        cin>>row>>col;
        
        for(int i=0; i<row; i++) for(int j=0; j<col; j++){
                char c; cin>>c;
                board[i][j] = c;
        }
        
        cin>>key; keyGet();
        
        while(1){
            
            startGet();
            int flag = bfs();
            if(flag==0) break;
            
            for(int i=0; i<row; i++) for(int j=0; j<col; j++) vis[i][j] = 0;
            cflag =0;
            start.clear();
        }

        cout<<cnt<<"\n";
        bdReset();
    }
    
    return 0;
}
