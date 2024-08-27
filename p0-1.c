#include <stdio.h>

// Initializing the structs for each letter's
struct letterCount
{
    char letters[26];
    int count[26];
};

int numberOfLetter(char alphaLetter, char letterOfText, int currentCount)
{
    if ((letterOfText == alphaLetter) || (letterOfText + 32 == alphaLetter))
    {
        currentCount++;
    }

    return currentCount;
}

int main(void)
{

    // char filePath = scanf("%s", &filePath);
    FILE *file = fopen("alice.txt", "r");

    if (file == NULL)
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

    while (!feof(file))
    {
        char c = getc(file);

        for (int l = 0; l < sizeof(lc.letters); l++)
        {
            lc.count[l] = numberOfLetter(lc.letters[l], c, lc.count[l]);
        }
    }

    for (int l = 0; l < sizeof(lc.letters); l++)
    {
        printf("%c, %d\n", lc.letters[l], lc.count[l]);
    }

    fclose(file);
    return 0;
}
