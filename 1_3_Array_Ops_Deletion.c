#include <stdio.h>
int main()
{
    int a[50], size, pos, item, i;
    printf("Enter size of array:");
    scanf("%d", &size);
    if (size > 50)
    {
        printf("Enter value less than 50 ! cant insert!");
    }
    else
    {
        printf("Enter elements in array:");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("Enter the position from where you whant to delete the number");
        scanf("%d", &pos);
        if (pos <= 0 || pos > size)
        {
            printf("INVALID");
        }
        else
        {
            item = a[pos - 1];
            for (i = pos - 1; i < size - 1; i++)
            {
                a[i] = a[i + 1];
            }
            size--;

            printf("Elements in the Array are:");
            for (i = 0; i < size; i++)
            {
                printf("%d", a[i]);
            }
            printf("\nThe deleted element was: %d", item);
        }
    }
    return 0;
}
//For deletion in beginning
// for ( i = 0; i < size-1; i++)
// {
//     a[i]=a[i+1];
// }
// size--;
//from directly replacing method best algo will take O(1)