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
