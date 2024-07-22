#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 6
void main()
{
    int i, j, n;
    printf("\n Enter number of vertices : ");
    scanf("%d", &n);
    int cost[SIZE][SIZE];
    bool  visited[SIZE];
    int srcVertex = 0;
    printf("\n Enter cost matrix (0 for same vertices and 999 if no edge) : \n\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    for (int i = 0; i < n; i++)
        visited[i] = false;

    visited[srcVertex] = true;
    int source = 0, tot_cost = 0, target = 0;
    printf("Edges: \n");
    for (int i = 1; i < n; i++)
    {
        int min = INT_MAX;

        for (int j = 0; j < n; j++)
        {
            if (visited[j])
            {

                for (int k = 0; k < n; k++)
                {
                    if (!visited[k] && min > cost[j][k])
                    {
                        min = cost[j][k];
                        source = j;
                        target = k;
                    }
                }
            }
        }
        visited[target] = true;
        printf("(source %d) -> (target %d) = min %d\n", source, target, min);
        tot_cost += min;
    }
    printf("\nMinimum cost of Spanning Tree: %d", tot_cost);
}

/*
Enter number of vertices : 6

Enter cost matrix (0 for same vertices and 999 if no edge) :

0 6 1 3 999 999
6 0 5 999 3 999
1 5 0 5 6 4
3 999 5 0 999 2
999 3 6 999 0 6
999 999 4 2 6 0

*/
