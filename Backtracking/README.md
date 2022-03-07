# Backtracking
___
## 코드 example

- if (base condition에 해당하는 경우 (k==n))
  - 최종 상태에 따라, 가지치기 실시하여 옳은 것만 처리
  - return;
- else (base condition이 아닌 경우, for()문을 통해 (경우 i)의 결정)
  
  - (부가적인 조건을 이 단계에서 처리하여 시간복잡도를 최소화할 수 있다. ex)중복조건, 오름차순 조건)
  - 상태의 변화()
  - dfs 재귀함수 호출 (k+1)
  - 상태의 복귀()
 
```c++
  void sDecis(int x, int y, int dir, int sum){ // backtracking(dfs)
    ~~~
    copyBd(tmpBd, board, tmpfish, fish); // ** 이동 전에 임시 배열에 복사해둠
    ~~~
    for(int i=1; i<=3; i++){ 
        ~~~~
        if(!rangecheck(desX, desY)) break; // 범위 이상이면 어짜피 더 못가므로 제외 (부가적인 조건을 처리) 
        else{
            
            if(!board[desX][desY]) continue; // 먹을 것이 없으면 더 갈 수 있을 지도 모르니 건너뜀 (부가적인 조건을 처리)
        
            int eatf = board[desX][desY];
            int ndir = fish[eatf].tmpDir; // 상어의 방향 update
            tempsum = sum + eatf;
            
            stateChange(x, y, desX, desY, eatf, 1); // **상태 변화
            sDecis(desX, desY, ndir, tempsum); // **재귀 함수 호출
            stateChange(x, y, desX, desY, eatf, 0); // **상태 변화 복귀시킴    
        }
    }
    // **상태 되돌리는 함수
    copyBd(board, tmpBd, fish, tmpfish); // 임시 배열을 원래로 되돌림
}
```
