#include<stdio.h>
int main()
{
int a[]={6,2,1,5,3};
int *q;
q=a;
printf("%p\t",a);
printf("%p\t",a+1);
printf("%d\t",a[2]);
printf("%d\t",*(a+2));// equi to a[2]
printf("%d\t",*a+2);//a is still a pointer to an integer array. However, the expression *a+2 adds 2 to the value pointed to by a. This is because the dereference operator * has higher precedence than the addition operator +. So this statement prints the integer value at the first element of the array pointed to by a, added by 2.

printf("%d\t",*(q+2));
printf("%p\t",&a[0]+1);//add at index 1
printf("%p\t",&a+1);//one more from the end of array
//q++;
printf("%p\t",q);
printf("%p",&q);

return 0;
}
//0061FF0C        0061FF10        1       1       1       0061FF20        0061FF0C        0061FF08