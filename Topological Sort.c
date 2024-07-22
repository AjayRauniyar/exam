#include <stdio.h>
#include <stdlib.h>

int vis[10], s[10], top = -1, adj[10][10];
void dfs(int, int);

int main()
{
	int i, j, n = 4;
	printf("Enter the adjaceny matrix: \n");
	for (i = 0; i < n; i++)
	{
		vis[i] = 0;
		for (j = 0; j < n; j++)
			scanf("%d", &adj[i][j]);
	}

	for (i = 0; i < n; i++)
	{
		if (!vis[i])
			dfs(i, n);
	}

	printf("The topological sort is: \n");

	while (top != -1)
	{
		printf("%d->", s[top--] + 1);
	}

	return 0;
}

void dfs(int v, int n)
{
	int i;
	vis[v] = 1;
	for (i = 0; i < n; i++)
	{
		if (!vis[i] && adj[v][i])
		{
			dfs(i, n);

		}

	}
	s[++top] = v;
}