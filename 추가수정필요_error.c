// 이상해서 추가 수정 필요한 코드들


// 희소행렬의 전치 연산 함수
// 희소행렬 (Sparse Matrix) 많은 항드이 0으로 구성

#include <stdio.h>
#define SIZE 50

typedef struct {
    int row;
    int col;
    int value;
} term;

void smTranspose(term a[], term b[]);
void init(term a[]);


void main(void) {

    term a[11], b[11];
    init(a);
    int i;

    for (i = 0; i < 11; i++) {
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
    }

    smTranspose(a, b);
    printf("\n");

    for (i = 0; i < 11; i++) {
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
    }

    return 0;

}


void init(term a[]) {
    a[0].row = 8; a[0].col = 7; a[0].value = 10;

    a[1].row = 0; a[1].col = 2; a[1].value = 2;
    a[2].row = 0; a[2].col = 3; a[2].value = 12;
    a[3].row = 1; a[3].col = 4; a[3].value = 7;
    a[4].row = 2; a[4].col = 0; a[4].value = 23;
    a[5].row = 3; a[5].col = 3; a[5].value = 31;
    a[6].row = 4; a[6].col = 1; a[6].value = 14;
    a[7].row = 4; a[7].col = 5; a[7].value = 25;
    a[8].row = 5; a[8].col = 0; a[8].value = 0;
    a[9].row = 6; a[9].col = 0; a[9].value = 52;
    a[10].row = 7; a[10].col = 4; a[10].value = 11;
}




void smTranspose(term a[], term b[]) {
    int m, n, v, i, j, p;

    // 희소행렬 a의 행, 열, 0이 아닌 원소 수
    m = a[0].row;
    n = a[0].col;
    v = a[0].value;

    // 희소행렬 b의 첫 행은
    // a의 행, 열, 0이 아닌 원소 수 대입
    b[0].row = n;
    b[0].col = m;
    b[0].value = v;

    // a에서 값이 0이 아닌 원소가 있는 경우에,
    // 해당 원소의 행번호, 열번호, 값을 b의 1향부터 삽입
    if (v > 0) {
        p = 1;
        for (i = 0; i < n; i++)
            for (j = 1; j <= v; j++)
                if (a[j].col == i) {
                    b[p].row = a[j].col;
                    b[p].col = a[j].row;
                    b[p].value = a[j].value;
                    p++;
                }
    }
}


