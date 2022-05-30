#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int compute_score(string word, int POINTS[], string alpha);
// Points assigned to each letter of the alphabet


int main(void)
{
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1, POINTS, alpha);
    int score2 = compute_score(word2, POINTS, alpha);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word, int POINTS[], string alpha)
{
    // TODO: Compute and return score for string
    int len = strlen(word);
    int i, j;
    int score = 0;
    // running loop for letters in word
    for (i = 0; i < len; i++)
    {
        // running loop to find index of the letter
        for (j = 0; j < 26; j++)
        {
            // checking if the character is alphabet or not
            if (isalpha(word[i]))
            {
                //checking if character is in lowercase
                if (islower(word[i]))
                {
                    char temp = word[i];
                    word[i] = toupper(temp);
                    if (word[i] == alpha[j])
                    {
                        score += POINTS[j];
                        break;
                    }
                }
                else
                {
                    if (word[i] == alpha[j])
                    {
                        score += POINTS[j];
                        break;
                    }
                }
            }
        }
    }
    return score;
}
