/**
 * Author   : hmenn
 * Content  : Basic mastermind implementation for one step
 * Time     : 25.10.17
 */

#include <stdio.h>
#include <stdint.h>
#include <mem.h>

#define CHIPPER_SIZE 4

typedef enum {
    E_COLOR_RED = 0,
    E_COLOR_BLUE=1,
    E_COLOR_YELLOW=2,
    E_COLOR_GREEN=3,
    E_COLOR_MAGENTA=4,
    E_COLOR_PINK=5,
    E_COLOR_BROWN=6,
    E_COLOR_BLACK=7,
    E_COLOR_WHITE=8
} te_colors;

void mastermind(uint8_t chipper[CHIPPER_SIZE], uint8_t userInput[CHIPPER_SIZE], uint8_t output[CHIPPER_SIZE]);

int main() {

    // fill output values with max(255)
    uint8_t output[CHIPPER_SIZE] = {0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t userInput[CHIPPER_SIZE] = {2,5,5,6};
    uint8_t chippers[][CHIPPER_SIZE] = {{0, 2, 5, 6},
                                        {4, 5, 5, 2},
                                        {7, 7, 6, 6},
                                        {3, 2, 2, 2},
                                        {1, 7, 1, 2},
                                        {4, 4, 7, 6},
                                        {7, 3, 6, 1}};

    uint8_t *chipper = chippers[1];


    mastermind(chipper, userInput, output);

    fprintf(stderr, "Chipper  :%d-%d-%d-%d\n", chipper[0], chipper[1], chipper[2], chipper[3]);
    fprintf(stderr, "UserInput:%d-%d-%d-%d\n", userInput[0], userInput[1], userInput[2], userInput[3]);
    fprintf(stderr, "Output:%d-%d-%d-%d\n", output[0], output[1], output[2], output[3]);

    return 0;
}

void mastermind(uint8_t chipper[CHIPPER_SIZE], uint8_t userInput[CHIPPER_SIZE], uint8_t output[CHIPPER_SIZE]) {
    uint8_t i = 0, j = 0;
    uint8_t outIndex = 0; // trace on output. For all founds set indexed location
    uint8_t locations[CHIPPER_SIZE];

    // fill output with FF to close leds
    memset(output,0xFFFFFFFF,sizeof(uint8_t)*CHIPPER_SIZE);

    for (i = 0; i < CHIPPER_SIZE; ++i) {
        // if found right place,
        if (chipper[i] == userInput[i]) {
            locations[i]=1;
            output[outIndex] = E_COLOR_RED;
            ++outIndex;
        }
    }

    for(i=0;i<CHIPPER_SIZE;++i){
        if(locations[i]!=1){
            for(j=0;j<CHIPPER_SIZE;++j){
                if(locations[j]!=1 && chipper[j]==userInput[i]){
                    locations[j]=2;
                    output[outIndex]=E_COLOR_WHITE;
                    ++outIndex;
                }
            }
        }
    }


}