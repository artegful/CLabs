#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

wchar_t * GetText(void);
void CorrectMistakes(wchar_t * text);

int main()
{
    wchar_t * text;
    setlocale(LC_ALL, "RU_ru");
    text = GetText();
    CorrectMistakes(text);
    printf("%ls\n", text);
    free(text);
    return 0;
}

wchar_t * GetText(void)
{
    unsigned int len_max = 128;
    unsigned int current_size = 0;
    wchar_t *pStr = malloc(len_max * sizeof(wchar_t));
    current_size = len_max;
    printf("\nВведите текст: ");
    if(pStr != NULL)
    {
        int c = EOF;
        unsigned int i = 0;
        while ((c = getwchar()) != '\n' && c != EOF)
        {
            pStr[i++]=(wchar_t)c;
            if(i == current_size)
            {
                current_size = i+len_max;
                pStr = realloc(pStr, current_size);
                if(!pStr)
                {
                    printf("Relocation error\n");
                }
            }
        }
        pStr[i] = '\0';
        printf("\nТекст: %ls\n\n", pStr);
    }
    else
    {
        printf("Malloc error\n");
    }
    return pStr;
}

void CorrectMistakes(wchar_t * text)
{
    int i;
    for(i = 0; text[i] != '\0'; i++)
    {
        if((text[i] == L'ж' || text[i] == L'ш' || text[i] == L'Ж' || text[i] == L'Ш'))
        {
            if (text[i + 1] == L'ы')
            {
                text[i+1] = L'и';
            }
            else if(text[i + 1] == L'Ы')
            {
                text[i+1] = L'И';
            }
        }
        else if((text[i] == L'ч' || text[i] == L'щ' || text[i] == L'Ч' || text[i] == L'Щ'))
        {
            if (text[i + 1] == L'ю')
            {
                text[i+1] = L'у';
            }
            else if (text[i + 1] == L'Ю')
            {
                text[i+1] = L'У';
            }
            else if (text[i + 1] == L'я')
            {
                text[i+1] = L'а';
            }
            else if (text[i + 1] == L'Я')
            {
                text[i+1] = L'А';
            }
        }
    }
}
