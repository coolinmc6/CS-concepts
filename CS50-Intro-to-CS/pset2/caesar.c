#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // if an argument is NOT given when run, I return 1 (at the bottom) => so I pretty much exit
    if (argc == 2)
    {
        // this is the key => this is how the user is altering the text;

        int key = atoi(argv[1]);
        string s = get_string("plaintext: ");
        char final[strlen(s)];
        for (int j = 0; j < strlen(s); j++)
        {
            if (isalpha(s[j]))
            {
                int subtractor;
                // if upper, it changes what I return
                // so if uppercase, the subtractor is 65; lowercase = 97
                if (isupper(s[j]))
                {
                    subtractor = 65;
                }
                else
                {
                    subtractor = 97;
                }

                int letter = s[j];
                letter -= subtractor;
                letter += key;
                letter = letter % 26;
                letter += subtractor;
                final[j] = letter;
            }
            else
            {
                final[j] = s[j];
            }
        }

        printf("ciphertext: %s\n", final);
    }
    else
    {
        return 1;
    }


}