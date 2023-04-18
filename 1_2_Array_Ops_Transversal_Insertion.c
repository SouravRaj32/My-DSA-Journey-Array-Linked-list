#include <stdio.h>
//This method is for sorted array
int main()
{
    int a[50], size, i, num, pos;
    printf("Enter size of array:");
    scanf("%d", &size); // if size > 50 print overflow cant insert in else block write below code
    if (size > 50)
    {
        printf("Enter value less than 50 ! cant insert!");
    }
    else
    {
        printf("Enter elements of array:");
        for (i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("Elements in Array are:");
        for (i = 0; i < size; i++)
        {
            printf("%d", a[i]);
        }
        printf("Enter the data u want to insert:");
        scanf("%d", &num);
        printf("Enter Position on which you want to insert:");
        scanf("%d", &pos);
        if (pos <= 0 || pos > size + 1)
        { // bound checking
            printf("INVALID pos! enter between 1 and 5");
        }
        else
        {
            for (i = size - 1; i >= pos - 1; i--)
            {
                a[i + 1] = a[i];//moving to right 
            }
            a[pos - 1] = num;//putting num to its place
            size++;

            
        }
        printf("Elements in Array are:");
            for (i = 0; i < size; i++)
            {
                printf("%d", a[i]);
            }
    }

    return 0;
}
//Best case TC O(1) Worst Case TC O(n) ie O(n-p) p depends on position
//beginning 
//for(i=size-1;i>=0;i--){
//   a(i+1)=a[i];
//}
//a[0]=num;
//size++;
//In unsorted array we can get best TC ie O(1) by this 
//a[size]=a[pos-1];
//a[pos-1]=num;
