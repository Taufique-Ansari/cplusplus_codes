#include <stdio.h>
int main()
{
    int i =1, n;
    printf("Enter no.");
    scanf("%d", &n);

    while(i <= n)
    {
        if(i%2 != 0)
            printf("%d\n", i);
        i = i + 1;
        
    }
    return 0;
}