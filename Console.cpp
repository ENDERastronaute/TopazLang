//
// Created by leny on 08.02.24.
//

#include "Console.h"

void Console::progressBar(std::atomic<float> &progress, int total) {
    int barWidth = 70;
    int pos;
    float lastProgress = progress;

    do {
        if (progress != lastProgress) {
            std::cout << '[';

            pos = (int) ((float) barWidth * progress);

            for (int i = 0; i < barWidth; i++) {
                if (i < pos) std::cout << '=';
                else if (i == pos) std::cout << '>';
                else std::cout << ' ';
            }

            std::cout << "] " << int(progress * 100) << "%\r";
            std::cout.flush();

            lastProgress = progress;
        }
    } while (progress < (float) total);

    std::cout << '\n';
}
