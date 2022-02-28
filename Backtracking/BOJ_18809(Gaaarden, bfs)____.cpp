#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int,int>;

int row,col,green,red,mx = 0, siz;

int board[51][51];
int G_dis[51][51]; // 초록색 배양액 bfs distance 배열
int R_dis[51][51]; // 빨간색 배양액 bfs distance 배열
int flower[51][51]; // 꽃의 좌표 저장

int colorArr[51]; // 백트래킹 배양액 투입 좌표 조합 저장 배열

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pii> v; // board[][]=2의 좌표 저장
queue<pii> Rq;
queue<pii> Gq;

void arrInit(){ // bfs 종료 후, 배열 초기화
    
    for(int i=0; i<row; i++) for(int j=0; j<col; j++){
        G_dis[i][j] = 0;
        R_dis[i][j] = 0;
        flower[i][j] = 0;
    }    
}

int bfs(){

    int flowercnt = 0;
    
    // 빨간색 배양액 뿌리고, 그 다음 초록색 뿌려서 거리가 같으면 꽃이피고 더이상 안퍼짐
    while(!Rq.empty() || !Gq.empty()){ //**********둘 중에 하나의 queue가 빌 때 까지
        
        int rqtmp = Rq.size(); //****************
        int gqtmp = Gq.size();
        
        while(rqtmp--){ // 빨간색 배양액 부터 bfs, 
               // ***** queue가 빌 때 까지 진행하는 것이 아니라 초기의 queue size 만큼만 반복하므로 하나의 term에서 빨간색과 초록색이 번갈아 가면서 진행된다 
            
            pii Rtemp = Rq.front(); Rq.pop();
            
            // 현재 자리에 꽃이 이미 피었는지 확인
            if(flower[Rtemp.X][Rtemp.Y]) continue;
            
            for(int i=0; i<4; i++){
            
                int Rnx = Rtemp.X + dx[i];
                int Rny = Rtemp.Y + dy[i];
                
                if(Rnx<0 || Rnx>=row || Rny<0 || Rny>=col) continue;
                // ****************빨간색이 먼저 되므로, 초록색이 된 부분에서 뒤늦게 거리가 같을 수 없다
                if(R_dis[Rnx][Rny] || G_dis[Rnx][Rny] || flower[Rnx][Rny] || !board[Rnx][Rny]) continue;
                
                R_dis[Rnx][Rny] = R_dis[Rtemp.X][Rtemp.Y] + 1;
                Rq.push({Rnx,Rny});
            }
        }
        
        while(gqtmp--){ // 이후 초록색 배양액 bfs
            
            pii temp = Gq.front(); Gq.pop();
            
            // 현재 자리에 꽃이 이미 피었는지 확인
            if(flower[temp.X][temp.Y]) continue;
            
            for(int i=0; i<4; i++){
                
                int Gnx = temp.X + dx[i];
                int Gny = temp.Y + dy[i];
                
                if(Gnx<0 || Gnx>=row || Gny<0 || Gny >=col) continue;
                if(G_dis[Gnx][Gny] || flower[Gnx][Gny] || !board[Gnx][Gny]) continue;
                
                // 빨간색과 거리가 같으면 꽃이 핌
                // 더이상 queue에 넣지 않고 꽃의 좌표 저장 + 꽃 개수 증가
                if(R_dis[Gnx][Gny] == G_dis[temp.X][temp.Y] +1){ 
                    flower[Gnx][Gny] = 1;
                    flowercnt++;
                }
                else {
                    G_dis[Gnx][Gny] = G_dis[temp.X][temp.Y] +1;
                    Gq.push({Gnx,Gny});
                }
            }
        }
    }
    
    arrInit(); // ********************dis와 flower 좌표 초기화
    while(!Gq.empty()) Gq.pop();
    while(!Rq.empty()) Rq.pop();
    return flowercnt;
}

int colorCheck(){ // R과 G를 개수에 맞게 + 모두 다 썻는지 판단

    int Gcnt = 0, Rcnt = 0;
    
    for(int i=0; i<siz; i++){
        if(colorArr[i] == 1) Rcnt++;
        else if(colorArr[i] == 2) Gcnt++;
    }
    
    if(Gcnt == green && Rcnt == red ) return 1;
    else return 0;
}

void colorDecis(int k){ // 숫자 2인 땅에서 (R or G를 뿌릴지), (안 뿌릴지) 조합 
    
    if(k == siz){
        
        if(colorCheck()){ // 조합에서 R과 G를 개수에 맞게 + 모두 다 쓴 경우만 bfs 진행

            for(int i=0; i<v.size(); i++){ // 배양액 좌표를 각각의 queue에 저장
                
                if(colorArr[i] == 1){
                    Rq.push({v[i].X, v[i].Y});
                    R_dis[v[i].X][v[i].Y] = 1;
                }
                else if(colorArr[i] == 2){
                    Gq.push({v[i].X, v[i].Y});
                    G_dis[v[i].X][v[i].Y] = 1;
                }
            }
            int tempflower = bfs();
            if(mx < tempflower) mx = tempflower;
        }
        return;
    }
    else{ // 중복 가능, 오름차순 필요 X
        for(int i=0; i<3; i++){ // ************안뿌림 = 0, R뿌림 = 1, G뿌림 =2
            colorArr[k] = i;
            colorDecis(k+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>row>>col>>green>>red;
    
    for(int i=0; i<row; i++) for(int j=0; j<col; j++){
        cin>>board[i][j];
        if(board[i][j] == 2) v.push_back({i,j}); // 배양액 가능 좌표만 vector저장
    }
    siz = v.size();
    
    if(green && red ) colorDecis(0); // G배양액과 R 배양액이 모두 있어야 꽃이 피므로
    cout<<mx;
    return 0;
}

