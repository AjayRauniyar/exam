#include <stdio.h>
int count = 0;

void printSolution(int n, int i, int set[], int subset[], int size, int target)
{
	if (target == 0)
	{
		printf("\nSubset %d : ", ++count);
		for (int j = 0; j < size; j++)
			printf("%d\t", subset[j]);
		printf("\n");
		return;
	}
	if (i == n)
		return;
	printSolution(n, i + 1, set, subset, size, target);
	if (set[i] <= target)
	{
		subset[size] = set[i];
		printSolution(n, i + 1, set, subset, size + 1, target - set[i]);
	}
}
int main()
{
	int set[10], subset[10];
	int n, i, target;
	printf("\nEnter the number range : ");
	scanf("%d", &n);
	printf("\nEnter the numbers in the set : ");
	for (i = 0; i < n; i++)
		scanf("%d", &set[i]);
	printf("\nEnter Target : ");
	scanf("%d", &target);
	printSolution(n, 0, set, subset, 0, target);
	if (count == 0)
		printf("\nThere are no subsets\n");
	return 0;
}