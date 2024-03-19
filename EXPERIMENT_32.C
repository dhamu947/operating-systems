#include <stdio.h>
#include <stdbool.h>

#define FRAME_SIZE 3
#define PAGE_SIZE 6

void LRU(int pages[], int n) {
    int frames[FRAME_SIZE] = {-1};
    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        printf("Reference %d: Page %d | Frames: %d %d %d\n", i + 1, pages[i], frames[0], frames[1], frames[2]);
        bool found = false;
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            int leastRecentlyUsed = 0;
            for (int j = 1; j < FRAME_SIZE; j++) {
                if (frames[j] < frames[leastRecentlyUsed]) {
                    leastRecentlyUsed = j;
                }
            }
            frames[leastRecentlyUsed] = pages[i];
            pageFaults++;
        }
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[PAGE_SIZE] = {1, 3, 0, 3, 5, 6};
    printf("LRU Page Replacement Algorithm Simulation:\n");
    LRU(pages, PAGE_SIZE);
    return 0;
}
