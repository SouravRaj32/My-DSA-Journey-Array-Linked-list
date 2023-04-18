#include <stdio.h>

int main() {
    int a[2][3], i, j;
    printf("Enter the Elements:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("The Elements are:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    //row major
    //a[i][j]=base +((i*n)+j)*size;

    //where index starts with 1
    //a[i][j]=base + [((i-1)*n)+(j-1)]*size

    //column major
    //a12=(((2*2)+1)*4)+100
    //a[i][j]=base+((j*m)+i)*size

    //where index starts with 1
    //a[i][j]=base + [((j-1)*m)+(i-1)]*size
    return 0;
}
