#include <stdio.h>
//ANY NO & WITH 1 TELLS US IF IT'S ODD OR EVEN//
int main() 
{
    int no;
    
    printf("Enter an integer: ");
    scanf("%d", &no);

    if (no & 1) 
	{
        printf("%d is an odd number.\n", no);
    } 
	else 
	{
        printf("%d is an even number.\n", no);
    }
    
    return 0;
}

