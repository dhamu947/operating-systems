#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n], i, j, bestBlockIdx;
    for (i = 0; i < n; i++) allocation[i] = -1;
    for (i = 0; i < n; i++) {
        bestBlockIdx = -1;
        for (j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i])
                if (bestBlockIdx == -1 || blockSize[j] < blockSize[bestBlockIdx])
                    bestBlockIdx = j;
        if (bestBlockIdx != -1) allocation[i] = bestBlockIdx, blockSize[bestBlockIdx] -= processSize[i];
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++) printf(" %d \t\t %d \t\t%s\n", i + 1, processSize[i], allocation[i] != -1 ? "" : "Not Allocated");
}

int main() {
    int blockSize[100], processSize[100], m, n, i;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the size of each memory block: \n");
    for (i = 0; i < m; i++) scanf("%d", &blockSize[i]);
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the size of each process: \n");
    for (i = 0; i < n; i++) scanf("%d", &processSize[i]);
    bestFit(blockSize, m, processSize, n);
    return 0;
}
