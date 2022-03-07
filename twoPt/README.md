# 투포인터
 - 배열을 따라 두 개의 포인터를 이동시키면서 데이터를 처리하는 알고리즘
 - 포인터 두 개는 모두 **한쪽 방향으로 움직인다.
___
## 코드 example
 - st=0, en=0으로 시작
 - 일반적으로 en을 증가시키면서 확인
 - 이후 st가 증가 되어야 하면 증가 후 위를 반복
```c++
  for (int st = 0; st < n; st++) { // pase마다 st는 n전까지 증가
        while (en < n &&  ~~~) en++; // 하나의 pase에서 en을 증가시키며 상태의 변화 확인
        if (en == n) break; // 만약 증가한 en이 n과 같아져 버리면 종료하는 분기가 필요한지 확인 (런타임오류 방지)
        ~~~
  }
```
```c++
  for(int st=0; st<n; st++){ // pase마다 st는 n전까지 증가
        while(en<n){ // 하나의 pase에서 en을 증가시키며 상태의 변화 확인
            if(used[a[en]]) break;
            used[a[en]] = 1;
            en++;
        }
        ans += (en-st); 
        used[a[st]] = 0; // st가 증가하게 될것이므로 바뀌어야하는 변화에 대처하고 st의 변화만 적용하여 나머지는 
  }
```
```c++
  int sum=0, st=0, en=0;
    while(1){
        if(sum>k) sum-=stick[++st]; // pase마다 st는 n전까지 증가
        else if(en==1000001){  // 만약 증가한 en이 n과 같아져 버려 종료하는 분기가 필요
            cout<<"0 0";
            break;
        }
        else sum+=stick[++en]; // 일반적인 경우에는 하나의 pase에서 en을 증가
        
        if(sum==k){  // 하나의 pase에서 en 증가에 따른 상태의 변화 확인
            cout<<st<<" "<<en;
            break;
        }
    }
```
___

# 슬라이딩 윈도우(Sliding Window)
 - 슬라이딩 윈도우는 배열을 따라 왼쪽에서 오른쪽으로 고정된 크기의 부분 배열을 이동하는 알고리즘
 - 배열의 크기가 N, 고정된 크기가 K인 경우 시간복잡도는 O(N+K)이다.
___
## 코드 example
