// Mario less
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // initialize height variable
    int height;
    do
    {
        height = get_int("How high do you want the pyramid? ");
    }
    // only accept the value if height is less than 24 AND greater than 0
    while (height >= 24 || height < 0);


    // there will be 'height' number of rows
    for (int i = 0; i < height; i++)
    {
        int spaces = height - 1 - i;
        int hashes = height - spaces;
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        // gives the extra #
        printf("#");
        for (int k = 0; k < hashes; k++)
        {
            printf("#");
        }
        printf("\n");
    }

}