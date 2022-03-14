# Tree Algorithm
___
## Minimum cost Spanning Tree algorithm
### Kruscal 알고리즘
- union-find의 사용을 통하여 O(ElogE)

### Prim 알고리즘
- 프림 알고리즘의 시간복잡도는 O(ElogE)
___
## 세그먼트 트리
### 세그먼트 트리 생성
```c++
  // a: 배열 A
  // tree: 세그먼트 트리
  // node: 노드 번호
  // node에 저장되어 있는 합의 범위가 start - end
  void init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
      if (start == end) { // 리프노드인 경우이므로 배열의 그 수를 직접 저장
          tree[node] = a[start];
      } else {
          init(a, tree, node*2, start, (start+end)/2); // 왼쪽 자식 재귀
          init(a, tree, node*2+1, (start+end)/2+1, end); // 오른쪽 자식 재귀
          tree[node] = tree[node*2] + tree[node*2+1];
      }
  }
```
### 구간의 합 구하기
- [left,right]와 [start,end]가 겹치지 않는 경우 => 더 이상 탐색을 이어나갈 필요가 없으므로 0을 리턴해 탐색을 종료
- [left,right]가 [start,end]를 완전히 포함하는 경우 => 모두 포함되기 때문에 더 이상 호출을 하지 않고 tree[node]를 리턴해 탐색을 종료
- [start,end]가 [left,right]를 완전히 포함하는 경우 => 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색을 시작
- [left,right]와 [start,end]가 겹쳐져 있는 경우 (1, 2, 3 제외한 나머지 경우) => 다시 탐색을 시작

```c++
  long long query(vector<long long> &tree, int node, int start, int end, int left, int right) {
      if (left > end || right < start) { // 겹치지 않는 경우
          return 0;
      }
      if (left <= start && end <= right) { // 구간이 전체를 완전히 포함하는 경우
          return tree[node];
      }
      long long lsum = query(tree, node*2, start, (start+end)/2, left, right);
      long long rsum = query(tree, node*2+1, (start+end)/2+1, end, left, right);
      return lsum + rsum;
  }
```
___
