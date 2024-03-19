#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

int blocks[MAX_BLOCKS], num_blocks;

void initializeBlocks() {
    printf("Enter number of memory blocks: ");
    scanf("%d", &num_blocks);

    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < num_blocks; i++) {
        scanf("%d", &blocks[i]);
    }
}

int firstFit(int size) {
    for (int i = 0; i < num_blocks; i++) {
        if (blocks[i] >= size) {
            blocks[i] -= size;
            return i;
        }
    }
    return -1; // No suitable block found
}

int main() {
    initializeBlocks();

    int choice, size;
    while (1) {
        printf("\n1. Allocate Memory\n2. Display Memory Blocks\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size of memory to allocate: ");
                scanf("%d", &size);
                int block_index = firstFit(size);
                if (block_index != -1) {
                    printf("Memory allocated successfully in block %d\n", block_index + 1);
                } else {
                    printf("Failed to allocate memory: No suitable block found\n");
                }
                break;
            case 2:
                printf("Memory Blocks:\n");
                for (int i = 0; i < num_blocks; i++) {
                    printf("Block %d: %d\n", i + 1, blocks[i]);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
