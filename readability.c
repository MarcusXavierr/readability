#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cs50.h>

void analysis();

int main(void)
{
    analysis();
}

void analysis()
{
    int grade;
    int lenght;
    float L;
    float S;
    int index;
    int counterWords = 0;
    int counterSentences = 0;
    int counterLetters = 0;
    printf("Type or paste an excerpt from a book and it will show you which age group that book is recommended\n");
    string text = get_string("Text: ");
    lenght = strlen(text);

    for (int i = 0; i < lenght; i++)
    {
        if (text[i] == ' ' || text[i + 1] == '\0')
        {
            // Verifica se há espaços
            counterWords++;
        }
    }

    for (int j = 0; j < lenght; j++)
    {
        if ((text[j] == '.' || text[j] == '?' || text[j] == '!') || text[j + 1] == '\0') // Verifica se há pontuação
        {
            counterSentences++;
        }
    }

    //Conta a quantidade de letras
    for (int k = 0; k < lenght; k++)
    {
        if ((text[k] >= 65 && text[k] <= 90) || (text[k] >= 97 && text[k] <= 122))
        {
            counterLetters++;
        }
    }
    L = (float)counterLetters * 100 / counterWords;
    S = (float)counterSentences * 100 / counterWords;

    index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf(" Under 6 years\n");
    }
    else if (index > 12)
    {
        printf("Older than 18 years\n");
    }
    else
    {
        printf("Age range: %i/%i years\n", index + 6,index + 7);
    }

}

