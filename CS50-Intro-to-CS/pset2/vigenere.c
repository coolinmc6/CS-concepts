/*
- This is just like the Caesar Cipher except that the keyword is the key and alters the character based on
the letter in the string.
- It is almost exactly the same and I could probably keep the same code and simply alter what the "key" variable
is from the Caesar cipher within the loop
*/

#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        string keyword = argv[1];

        for (int ch = 0; ch < strlen(keyword); ch++)
        {
            if (!isalpha(keyword[ch]))
            {
                return 1;
            }
        }

        string s = get_string("plaintext: ");
        char final[strlen(s)+1];

        // printf("Length: %d\n",  (int)strlen(s));

        // printf("Final String (BEFORE): %s\n", final);

        int keywordCount = 0;

        for (int j = 0; j < strlen(s)+1; j++)
        {
            if (j == strlen(s) + 1)
            {
                final[j] = (char)"\0";
            }

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

                int key;
                if(isupper(keyword[keywordCount % strlen(keyword)]))
                {
                    key = keyword[keywordCount % strlen(keyword)] - 65;
                }
                else
                {
                    key = keyword[keywordCount % strlen(keyword)] - 97;
                }

                // printf("%d\n", key);

                int letter = s[j];
                letter -= subtractor;
                letter += key;
                letter = letter % 26;
                letter += subtractor;
                final[j] = letter;
                // printf("%c\n", letter);
                keywordCount++;
            }
            else
            {
                final[j] = s[j];
                // printf("Non alpha-numeric: %c\n", s[j]);
            }
        }


        // printf("Final String (AFTER): %s\n", final);
        printf("ciphertext: %s\n", final);
    }
    else
    {
        return 1;
    }
}