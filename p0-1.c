#include <stdio.h>
#include <ctype.h>

// struct for letter count to keep track of counter
struct letterCount
{
    char letter;
    int count;
};

int main(int argc, char *argv[])
{
    // Array of structs for letters a-z
    struct letterCount letters[26];
    for (int i = 0; i < 26; i++)
    {
        letters[i].letter = 'a' + i;
        letters[i].count = 0;
    }


    char ch;
    // loop that scans the file
    while (!feof(stdin))
    {
        if (scanf("%c", &ch) == 1)
        {
            if (isalpha(ch)) // checks if character is a letter
            {
                ch = tolower(ch); // turns into lower case letter
                int index = ch - 'a';
                letters[index].count++;
            }
        }
    }

    //prints out the result
    for (int i = 0; i < 26; i++){
        if (letters[i].count > 0){
        printf("%c: %d\n", letters[i].letter, letters[i].count);
        }
    }
    return 0;
}
