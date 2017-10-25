/**
 * Author   : hmenn
 * Content  : Basic mastermind implementation for one step
 * Time     : 25.10.17
 */

#include <stdio.h>
#include <stdint.h>

#define CHIPPER_SIZE 4

typedef enum {
    E_COLOR_RED = 0,
    E_COLOR_BLUE,
    E_COLOR_YELLOW,
    E_COLOR_GREEN,
    E_COLOR_MAGENTA,
    E_COLOR_PINK,
    E_COLOR_BROWN,
    E_COLOR_BLACK,
    E_COLOR_WHITE
} te_colors;

void mastermind(uint8_t chipper[CHIPPER_SIZE], uint8_t userInput[CHIPPER_SIZE], uint8_t output[CHIPPER_SIZE]);

int main() {

    // fill output values with max(255)
    uint8_t output[CHIPPER_SIZE] = {0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t userInput[CHIPPER_SIZE] = {2, 0, 6, 5};
    uint8_t chippers[][CHIPPER_SIZE] = {{0, 2, 5, 6},
                                        {4, 5, 5, 2},
                                        {7, 7, 6, 6},
                                        {3, 2, 2, 2},
                                        {1, 7, 1, 2},
                                        {4, 4, 7, 6},
                                        {7, 3, 6, 1}};

    uint8_t *chipper = chippers[0];


    mastermind(chipper, userInput, output);
    fprintf(stderr, "Chipper:%d-%d-%d-%d\n", chipper[0], chipper[1], chipper[2], chipper[3]);
    fprintf(stderr, "Output:%d-%d-%d-%d\n", output[0], output[1], output[2], output[3]);

    return 0;
}

void mastermind(uint8_t chipper[CHIPPER_SIZE], uint8_t userInput[CHIPPER_SIZE], uint8_t output[CHIPPER_SIZE]) {
    uint8_t i = 0, j = 0;
    uint8_t outIndex = 0; // trace on output. For all founds set indexed location

    for (i = 0; i < CHIPPER_SIZE; ++i) {
        // if found right place,
        if (chipper[i] == userInput[i]) {
            output[outIndex] = E_COLOR_RED;
            ++outIndex;
        } else {
            // not found, search another locations
            for (j = 0; j < CHIPPER_SIZE; ++j) {
                // found in another location, add a white signal to output
                if (chipper[j] == userInput[i]) {
                    output[outIndex] = E_COLOR_WHITE;
                    ++outIndex;
                    break; // continue with next user input
                }
            }
        }
    }
}