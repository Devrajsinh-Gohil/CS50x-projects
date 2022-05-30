#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// prototyping functions for compiler
int letters(string para);
int words(string para);
int sentences(string para);

int main(void)
{
    // prompting user for input
    string para = get_string("Text: ");

    // counting letters, words and sentences.
    int num_letters = letters(para);
    int num_words = words(para);
    int num_sentence = sentences(para);

    // calculating Coleman–Liau index
    float L = (num_letters * 100.00) / num_words ;
    float S = (num_sentence * 100.00) / num_words;
    float I = (0.0588 * L) - (0.296 * S) - 15.8;
    int grade = round(I);

    //printing output
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// a function to find alphabets in given text.
int letters(string para)
{
    int num_letters = 0;
    for (int i = 0, n = strlen(para) ; i < n; i++)
    {
        if (isalpha(para[i]))
        {
            num_letters++;
        }
    }
    return num_letters;
}

// function to find words in given text
int words(string para)
{
    int num_words = 0;
    for (int i = 0, n = strlen(para) ; i < n; i++)
    {
        if (isspace(para[i]))
        {
            num_words++;
        }
    }
    return num_words + 1;
}

// function to find sentences in gien text
int sentences(string para)
{
    int sentence = 0;
    for (int i = 0, n = strlen(para) ; i < n; i++)
    {
        if (para[i] == '.' || para[i] == '!' || para[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}