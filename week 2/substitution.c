#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

//-----------------------
// prototyping functions
int is_not_alpha(string key);
string capitalize(string key);
string encrypt(string plain_text, int text_len, string plain_key, string key);
int is_reapeat(string cap_key, string plain_key);

//------------------------
// main function
int main(int argc, string argv[])
{
    string key;
    string plain_key;
    string cap_key;
    // validating command-line input
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // validating key
    else
    {
        key = argv[1];
        plain_key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        cap_key = capitalize(key);

        // validating key length
        int key_len = strlen(key);
        if (key_len < 26 || key_len > 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        // validating only alphabets in key
        else if (is_not_alpha(key))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        // checking that any alphabet is not repeated.
        else if (is_reapeat(cap_key, plain_key))
        {
            printf("Elements should not be repeated.\n");
            return 1;
        }
    }

    // prompting for user input
    string plain_text = get_string("plaintext: ");
    int text_len = strlen(plain_text);

    // ciphering plaintext
    string cipher_text = encrypt(plain_text, text_len, plain_key, key);
    printf("ciphertext: %s\n", cipher_text);
    return 0;
}

//----------------------------
// section of functions.

// function to check that there is no other characters then alpha in key
int is_not_alpha(string key)
{
    int i, c = 0;
    for (i = 0; i < 26; i++)
    {
        if (isalpha(key[i]))
        {
            c++;
        }
    }
    if (c < 26)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to capitalize
string capitalize(string key)
{
    int i;
    for (i = 0; i < 26; i++)
    {
        if (islower(key[i]))
        {
            char temp3 = key[i];
            key[i] = toupper(temp3);
        }
    }
    return key;
}

// function for ciphering text
string encrypt(string plain_text, int text_len, string plain_key, string key)
{
    // initializing ciphertext
    string cipher_text = plain_text;

    // loops for ciphering
    int i, j;
    for (i = 0; i < text_len; i++)
    {
        for (j = 0; j < 26; j++)
        {
            // checking if plaintext character is lower
            if (islower(plain_text[i]))
            {
                char temp1 = plain_text[i];
                cipher_text[i] = toupper(temp1);

                if (cipher_text[i] == plain_key[j])
                {
                    cipher_text[i] = key[j];
                    char temp2 = cipher_text[i];
                    cipher_text[i] = tolower(temp2);
                    break;
                }
                char temp2 = cipher_text[i];
                cipher_text[i] = tolower(temp2);
            }
            else if (cipher_text[i] == plain_key[j])
            {
                cipher_text[i] = key[j];
                break;
            }
        }
    }
    return cipher_text;
}

// function to find reapeating elements
int is_reapeat(string cap_key, string plain_key)
{
    int i,j;
    int ele_count[26] = {0};
    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (cap_key[i] == plain_key[j])
            {
                ele_count[j]++;
                if (ele_count[j] > 1 || ele_count[j] < 1)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}