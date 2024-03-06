#include <stdio.h>

int countSetBits(int num) 
{
    int count = 0;
    while (num) 
	{
        count += num & 1;
        num >>= 1;
    }

    return count;
}

int main() 
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    int result = countSetBits(num);
    
    printf("Number of set bits in %d is %d.\n", num, result);
    return 0;
}

