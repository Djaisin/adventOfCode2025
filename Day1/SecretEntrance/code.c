#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    parsing(const char *line, int *totalNumber, int *zeroCounter)
{

    int number = atoi(line + 1);
    if (line[0] == 'R')
    {
        *totalNumber += number;
        while (*totalNumber > 99)
            *totalNumber = *totalNumber - 100;
    }
    else
    {
        *totalNumber -= number;
        while (*totalNumber < 0)
            *totalNumber = (100 + *totalNumber);
    }
    if (*totalNumber == 0)
        (*zeroCounter)++;
}

void    readfile(const char* filename) 
{
    char line[256];
    int zeroCounter = 0, totalNumber = 50;
    FILE* file = fopen(filename, "r");

    while (fgets(line, sizeof(line), file)) 
        parsing(line, &totalNumber, &zeroCounter);
    fclose(file);
    printf("zeroCounter: %d\n", zeroCounter);
}

int main(int argc, char** argv) 
{
    readfile("./puzzleInput.txt");
    return 0;
}