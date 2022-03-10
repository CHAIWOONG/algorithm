# 이분 탐색(Binary Search)
- 정렬되어 있는 데이터에서 원하는 값을 찾을 때 효율적으로 사용할 수 있는 알고리즘 O(logn)의 시간복잡도

- 이분 탐색(Binary Search)은 결정 문제(Decision Problem)의 답이 이분적일 때 사용할 수 있는 탐색 기법
이때 결정 문제는 답이 Yes or No인 문제를 의미하며 (이분 탐색 문제에서는) 보통 1개의 parameter를 가짐

```c++
  // left는 첫 인덱스
  int left = 0;
  // right는 마지막 인덱스
  int right = v.size()-1; 
  int mid;

  while (left <= right)
  {
    mid = (left + right) / 2;
    // 탐색 완료한 경우 해당 인덱스 반환
    if (target == v[mid])
      return mid;
    else
    {
      // 중간 값이 더 큰 경우 중간 값 왼쪽 부분을 탐색하기 위해 right 값을 설정한다.
      if (target < v[mid])
        right = mid - 1;
      // 중간 값이 더 작은 경우 중간 값 오른쪽 부분을 탐색하기 위해 left 값을 설정한다.
      else
        left = mid + 1;
    }
  }
  // 탐색에 실패한 경우(값이 존재하지 않는 경우)
  return -1;
```
___
## 특정한 수를 찾는 문제, 특정한 수가 몇 개 있는지를 물어보는 문제

___
## 중복 제거

___
## 좌표 압축

___
## Parametric Search
- 특정 값을 구하라는 문제(최대 값, 최소 값을 구하라)를 결정 문제로 바꿔서 생각하는 방법
- 특정 조건에 맞는 최대 값을 구하라 => 값 X가 특정 조건에 맞는가? => 이분 탐색을 이용하여 알맞는 X값을 찾음
- 결정 문제로 바꾸고 생각하는 X가 연속된 값이어야 함
### Parametric Search 과정
- 1. 정답이 될 수 있는 X의 범위를 설정한다.
- 2. START에는 X의 최소값, LAST에는 X의 최대값을 설정한다.
- 3. START와 LAST의 중간값인 MID를 결정한 후 MID가 정답이 될 수 있는지 판단한다.
- 4. MID가 정답이 가능한지, 아닌지에 따라 START와 LAST의 범위를 줄여 2번 과정을 반복한다.
    이 과정에서 사용하는 것이 이분탐색이다.
- 참고) 파라메트릭 서치 조건에 따라 X는 연속된 형태를 가지고 있기 때문에 이분탐색이 가능하다.
