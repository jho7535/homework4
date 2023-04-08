#include <stdio.h>
#include <stdlib.h>

int i, j;                                                                                            // int형 전역 변수 i, j 선언
void create_matrix(char name, int ***matrix, int *row, int *colunm);                                 // create_matrix 함수의 원형 선언
void print_matrix(int **matrix, int row, int colunm);                                                // print_matrix 함수의 원형 선언
void addition_matrix(int **matrixA, int rowA, int colunmA, int **matrixB, int rowB, int colunmB);    // addition_matrix 함수의 원형 선언
void subtraction_matrix(int **matrixA, int rowA, int colunmA, int **matrixB, int rowB, int colunmB); // subtraction_matrix 함수의 원형 선언
void free_matrix(int **matrix, int row);                                                             // free_matrix 함수의 원형 선언

int main()
{
    int rowA, columnA, rowB, columnB;              // int형 변수 rowA, columnA, rowB, columnB 선언
    int **matrixA, **matrixB;                      // int형 이중 포인터 변수 matrixA, matrixB 선언
    create_matrix('A', &matrixA, &rowA, &columnA); // A, matrixA의 주소, rowA의 주소, columnA의 주소를 매개변수로 받는 함수 create_matrix 실행
    create_matrix('B', &matrixB, &rowB, &columnB); // B, matriBA의 주소, rowB의 주소, columnB의 주소를 매개변수로 받는 함수 create_matrix 실행

    if (rowA == rowB && columnA == columnB)
    {                                                                       // rowA == rowB 이고 columnA == columnB 이면
        addition_matrix(matrixA, rowA, columnA, matrixB, rowB, columnB);    // matrixA, rowA, columnA, matrixB, rowB, columnB를 매개변수로 받는 함수 addition_matrix 실행
        subtraction_matrix(matrixA, rowA, columnA, matrixB, rowB, columnB); // matrixA, rowA, columnA, matrixB, rowB, columnB를 매개변수로 받는 함수 subtraction_matrix 실행
    }
    else
    {
        printf("rowA != rowB or columnA != columnB\n");
        printf("Addition and subtraction are impossible\n");
    //     free_matrix(matrixA, rowA); // matrixA, rowA를 매개변수로 받는 함수 free_matrix 실행
    //     free_matrix(matrixB, rowB); // matrixB, rowB를 매개변수로 받는 함수 free_matrix 실행
    //     exit(0); // 프로그램 종료
    }


    return 0;
}
void create_matrix(char name, int ***matrix, int *row, int *colunm)
// char형 변수 name, int형 삼중 포인터 변수 matrix, int형 포인터 변수 row, colunm를 매개변수로 갖는 void형 함수 create_matrix
// 행과 열의 크기를 입력 받고, 행렬의 값을 입력 받아 행렬을 동적 할당해주는 함수
{
    int x, y; // int형 변수 x, y 선언
    printf("Enter rows and columns of a matrix %c in order >> ", name);
    scanf("%d %d", &y, &x); // 값을 입력 받아 y, x에 대입
    *row = y;               // row에 y 값 대입
    *colunm = x;            // colunm에 x 값 대입

    *matrix = (int **)malloc(sizeof(int *) * y);       //*matrix에 (포인터의 크기 * y)만큼 메모리 할당
    for (i = 0; i < y; i++)                            // i를 0부터 1씩 증가시키며 y보다 작을 때까지 반복
        (*matrix)[i] = (int *)malloc(sizeof(int) * x); //(*matrix)[i]에 (int의 크기 * x )만큼 메모리 할당

    for (i = 0; i < y; i++) // i를 0부터 1씩 증가시키며 y보다 작을 때까지 반복
    {
        for (j = 0; j < x; j++) // j를 0부터 1씩 증가시키며 x보다 작을 때까지 반복
        {
            printf("[%d], [%d] Enter a value: ", i + 1, j + 1);
            scanf("%d", &(*matrix)[i][j]); // 값을 입력 받아 (*matrix)[i][j]에 대입
        }
        printf("\n");
    }
}
void print_matrix(int **matrix, int row, int colunm)
// int형 이중 포인터 변수 matrix, int형 변수 row, colunm를 매개변수로 갖는 void형 함수 print_matrix
// 행렬을 화면에 출력하는 함수
{
    for (i = 0; i < row; i++) // i를 0부터 1씩 증가시키며 row보다 작을 때까지 반복
    {
        for (j = 0; j < colunm; j++) // j를 0부터 1씩 증가시키며 x보다 작을 때까지 반복
        {
            printf("%3d", matrix[i][j]); // matrix[i][j] 값 출력
        }
        printf("\n");
    }
}
void addition_matrix(int **matrixA, int rowA, int colunmA, int **matrixB, int rowB, int colunmB)
// int형 이중 포인터 변수 matrixA, matrixB int형 변수 rowA, colunmA, rowB, colunmB를 매개변수로 갖는 void형 함수 addition_matrix
{
    int **matrixC;                                         // int형 이중 포인터 matrixC 선언
    matrixC = (int **)malloc(sizeof(int *) * rowA);        // matrixC에 (포인터의 크기 * rowA)만큼 메모리 할당
    for (i = 0; i < rowA; i++)                             // i를 0부터 1씩 증가시키며 rowA보다 작을 때까지 반복
        matrixC[i] = (int *)malloc(sizeof(int) * colunmA); // matrix[i]에 (int의 크기 * colunmA)만큼 메모리 할당

    for (i = 0; i < rowA; i++) // i를 0부터 1씩 증가시키며 rowA보다 작을 때까지 반복
    {
        for (j = 0; j < colunmA; j++)                      // j를 0부터 1씩 증가시키며 colunmA보다 작을 때까지 반복
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j]; // matrixA[i][j] + matrixB[i][j] 값을 matrixC[i][j]에 대입
    }

    printf("----------Addition Results----------\n\n");
    print_matrix(matrixC, rowA, colunmA); // matrixC, rowA, columnA를 매개변수로 받는 함수 print_matrix 실행

    free_matrix(matrixC, rowA); // matrixC, rowA를 매개변수로 받는 함수 free_matrix 실행
}
void subtraction_matrix(int **matrixA, int rowA, int colunmA, int **matrixB, int rowB, int colunmB)
// int형 이중 포인터 변수 matrixA, matrixB int형 변수 rowA, colunmA, rowB, colunmB를 매개변수로 갖는 void형 함수 subtraction_matrix
{
    int **matrixC;                                         // int형 이중 포인터 matrixC 선언
    matrixC = (int **)malloc(sizeof(int *) * rowA);        // matrixC에 (포인터의 크기 * rowA)만큼 메모리 할당
    for (i = 0; i < rowA; i++)                             // i를 0부터 1씩 증가시키며 rowA보다 작을 때까지 반복
        matrixC[i] = (int *)malloc(sizeof(int) * colunmA); // matrix[i]에 (int의 크기 * colunmA)만큼 메모리 할당

    for (i = 0; i < rowA; i++) // i를 0부터 1씩 증가시키며 rowA보다 작을 때까지 반복
    {
        for (j = 0; j < colunmA; j++)                      // j를 0부터 1씩 증가시키며 colunmA보다 작을 때까지 반복
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j]; // matrixA[i][j] - matrixB[i][j] 값을 matrixC[i][j]에 대입
    }

    printf("----------Subtraction Results----------\n\n");
    print_matrix(matrixC, rowA, colunmA); // matrixC, rowA, columnA를 매개변수로 받는 함수 print_matrix 실행

    free_matrix(matrixC, rowA); // matrixC, rowA를 매개변수로 받는 함수 free_matrix 실행
}
void free_matrix(int **matrix, int row) // int형 이중 포인터 변수 matrix, int형 포인터 변수 row를 매개변수로 갖는 void형 함수 free_matrix
{                             
    for (i = 0; i < row; i++) // i를 0부터 1씩 증가시키며 row보다 작을 때까지 반복
        free(matrix[i]);      // matrix[i]에 할당되었던 메모리 해제
    free(matrix);             // matrix에 할당되었던 메모리 해제
}