#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main()
{
    int m, n;
    int i, j;
  /******************************************/
    int** p;
    scanf("%d%d", &m, &n);
    p = (int**)malloc(sizeof(int*) * m);
    for (i = 0; i < m; i++)
    {
        p[i] = (int*)malloc(sizeof(int)*n);
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
  /*****************************************/
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < m; i++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
 
    for (i = 0; i < m; i++)
        free(p[i]);
    free(p);
 
    return 0;
}
