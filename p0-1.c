#include <stdio.h>

// Initializing the structs for each letter's
struct letterCount
{
    char letters[26];
    int count[26];
};

int numberOfLetter(char alphaLetter, char letterOfText, int currentCount)
{
    char lowerLetter = alphaLetter + 32; //adds 32 to the letter to get lowercase version
    if ((letterOfText == alphaLetter) || (letterOfText == lowerLetter))
    {
        currentCount++;
    }

    return currentCount;
}

int main(void)
{
    if (stdin == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    struct letterCount lc;

    for (int i = 0; i < sizeof(lc.letters); i++)
    {
        lc.letters[i] = 'A' + i;
        lc.count[i] = 0;
    }

    while (!feof(stdin))
    {
        char c = getc(stdin);

        for (int l = 0; l < sizeof(lc.letters); l++)
        {
            lc.count[l] = numberOfLetter(lc.letters[l], c, lc.count[l]);
        }
    }

    for (int l = 0; l < sizeof(lc.letters); l++)
    {
        printf("%c, %d\n", lc.letters[l], lc.count[l]);
    }

    return 0;
}
