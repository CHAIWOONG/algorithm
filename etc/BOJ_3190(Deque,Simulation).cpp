#include <iostream>
#include <algorithm>
#include <deque> 
#include <vector> 
#include <utility>
#include <string>

using namespace std;

int board[101][101]; // 보드판의 배열

char moving[10001]; // 뱀의 이동 명령 저장

int snakePos[101][101]; // 뱀의 위치 저장

deque<pair<int,int>> snake; // 뱀의 이동에 대해 덱 사용


pair<int,int> direct_decision(int direction) // D와 L 입력 개수에 대한 이동 pair 판단
{
    
    pair<int,int> a; 
    
    if(direction>=0)
    {
        switch (direction%4) { 
            case 1: 
                a =  {1,0};
                break;
            case 2: 
                a = {0,-1};
                break;
            case 3: 
                a = {-1,0};
                break;
            default:  //case 0
                a = {0,1} ;
                break;
        }
    }
    else if(direction<0) // Left의 명령이 더 클 때
    {
        switch ((-direction)%4) { 
            case 1: 
                a = {-1,0} ;
                break;
            case 2: 
                a = {0,-1};
                break;
            case 3: 
                a = {1,0};
                break;
            default:  //case 0
                a = {0,1} ;
                break;
        }
    }
    
    return a;
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int start_row=1,start_col=1;
    snake.push_back({start_row,start_col});  // 뱀 초기화
    snakePos[start_row][start_col] = 1;
    
    // 보드와 사과의 위치 초기화
    int board_size,apple_num;
    cin>>board_size>>apple_num;
    
    int apl_row,apl_col;
    for(int i=0; i<apple_num; i++)   
    {
        cin>>apl_row>>apl_col;
        board[apl_row][apl_col] = 1;
    }
    
    // 뱀의 이동 명령 배열 초기화
    int snake_turn;
    cin>>snake_turn;
    
    for(int i=0; i<snake_turn; i++) 
    {
        int gtime;
        char direct;
        cin>>gtime>>direct;
        moving[gtime] = direct;
    }
    
    int timeCount = 0;
    int direction = 0; // D-L
    
    while(1){
        
        timeCount+=1; // 1초부터 시작
        
        auto direct_pair = direct_decision(direction); // 해당 시간에서 방향 받음
        auto element4 = snake.front();
        
        int head_row = element4.first + direct_pair.first;   
        int head_col = element4.second + direct_pair.second; // 머리가 될 위치 업데이트
        
        // 벽에 부딪히는 경우 종료
        if( head_row<1 || head_row>board_size || head_col<1 || head_col>board_size )
        {
            break;
        }
        else // 부딪히지 않은 경우 지속
        {
            // 뱀의 이동 명령이 존재할 때,
            if(moving[timeCount] == 'D') direction++;
            else if(moving[timeCount] == 'L') direction--;
            
            // 뱀이 사과를 먹을 때 머리만 증가, 꼬리 유지
            if (board[head_row][head_col]) 
            {
                board[head_row][head_col] = 0; // 먹은 사과는 제거
                snake.push_front({head_row,head_col});
                
                // 이미 뱀의 몸통 존재하는지 아닌지 판단
                if(snakePos[head_row][head_col] == 1) break;
                else snakePos[head_row][head_col] = 1;
            }
            else // 사과 먹지 않을 때 머리 증가, 꼬리 제거
            {
                
                snake.push_front({head_row,head_col});
                
                // 이미 뱀의 몸통 존재하는지 아닌지 판단
                if(snakePos[head_row][head_col] == 1) break; 
                else 
                {
                    
                    snakePos[head_row][head_col] = 1;
                    auto element3 = snake.back();
                    snakePos[element3.first][element3.second] = 0;
                    snake.pop_back();
                }
            }
        }
        
    }
    cout<<timeCount;
    
    return 0;
}
