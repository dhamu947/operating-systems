#include <stdio.h>
#include <stdbool.h>

#define FRAME_SIZE 3 // Size of the frame (number of frames)
#define PAGE_SIZE 6 // Size of the page reference string

void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("\n");
}

bool isPageInFrames(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

void FIFO(int pages[], int n) {
    int frames[FRAME_SIZE]; // Frames to store pages
    int frameIndex = 0; // Index for FIFO replacement
    int pageFaults = 0; // Count of page faults
    for (int i = 0; i < n; i++) {
        printf("Reference %d: Page %d | Frames:", i + 1, pages[i]);
        printFrames(frames, FRAME_SIZE);
        if (!isPageInFrames(frames, FRAME_SIZE, pages[i])) {
            frames[frameIndex] = pages[i]; // Replace the oldest page
            frameIndex = (frameIndex + 1) % FRAME_SIZE; // Increment index (FIFO)
            pageFaults++;
        }
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[PAGE_SIZE] = {1, 3, 0, 3, 5, 6}; // Page reference string
    printf("FIFO Page Replacement Algorithm Simulation:\n");
    FIFO(pages, PAGE_SIZE);
    return 0;
}
