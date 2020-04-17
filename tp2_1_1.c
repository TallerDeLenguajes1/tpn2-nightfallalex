#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 5

int main()
{
    int f,c;
    double mt[N][M];
    //…
    for(c = 0;c<N; c++)
    {
            for(f = 0;f<N; f++)
            {
           
            printf("%lf", mt[f][c]);
            
            }
        
        printf("\n");
    }
}
