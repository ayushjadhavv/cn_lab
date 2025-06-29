#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FRAMES 50

int main() {
    int totalFrames, windowSize;
    printf("Enter total number of frames to send: ");
    scanf("%d", &totalFrames);
    printf("Enter window size: ");
    scanf("%d", &windowSize);

    int sentUpto = 0;
    srand(time(NULL));

    while (sentUpto < totalFrames) {
        int windowEnd = sentUpto + windowSize;
        if (windowEnd > totalFrames) windowEnd = totalFrames;

        printf("\nSending frames: ");
        for (int i = sentUpto; i < windowEnd; i++)
            printf("[%d] ", i);

        // Simulate random ACK loss
        int ackLoss = rand() % (windowEnd - sentUpto);  // loss within window
        int ackFrame = sentUpto + ackLoss;

        printf("\nACK lost for Frame %d. Go-Back-N triggered.\n", ackFrame);
        printf("Resending from Frame %d...\n", ackFrame);

        sentUpto = ackFrame;  // Go back to that frame
    }

    printf("\nAll frames sent successfully with Go-Back-N.\n");
    return 0;
}
