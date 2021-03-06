#include <stdio.h>

int number = 9;
int heap[9] = {7,6,5,8,3,5,9,1,6};

int main()
{
    // 전체 트리를 max heap으로
    for(int i =1;i<number; i++){
        int c = i;
        do{
            int root = (c-i)/2;
            if(heap[root] < heap[c]){
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        }while(c!=0);
    }
    
    // 크기를 줄여가며 heap 구성
    for(int i = number-1; i>=0; i--){
        
        // max heap의 root를 맨뒤로 이동
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = i;
        
        // heap 구조 다시 생성
        do{
            c = 2*root+1;
            // 자식 2개 중에 더 큰 값 찾기
            if(heap[c] < heap[c+1] && c<i-1){
                c++;
            }
            // 루트보다 자식이 더 크면 교환
            if(heap[root] < heap[c]&&c<i){
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while(c<i);
        
    }
    
    // 출력
    for(int i = 0; i<number; i++){
        printf("%d ", heap[i]);
    }

    return 0;
}
