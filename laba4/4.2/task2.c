#include <stdio.h>
#include <string.h>
#define N 12

int main()
{
    int d;
    int m;
    int y;
    int score;
    char min[N];
    int minScore;
    char max[N];
    int maxScore;
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char buffer[N];
    char is_first = '1';
    FILE *fp;
    fp = fopen("input.txt", "r"); 
    if (!fp) 
    {
        printf("No file found\n");
        return 1;
    }
    while (fgets(buffer, N, fp) != NULL)
    {
        if(buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        if(sscanf(buffer, "%d.%d.%d", &d, &m, &y) == 3 && d >= 0 && m >= 0 && y >= 0)
        {
            if((d > months[m-1] || m > 12) && !(m == 2 && d == 29 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))))
            {
                printf("%s, no such date\n", buffer);
            }
            else
            {
                score = y * 10000 + m * 100 + d;
                if(is_first)
                {
                    strcpy(min, buffer);
                    minScore = score;
                    strcpy(max, buffer);
                    maxScore = score;
                    is_first = '\0';
                }
                else
                {
                    if(score > maxScore)
                    {
                        maxScore = score;
                        strcpy(max, buffer);
                    }
                    else if(score < minScore)
                    {
                        minScore = score;
                        strcpy(min, buffer);
                    }
                    printf("%d.%d.%d\n", d, m, y);
                }
            }
        }
        else 
        {
            printf("%s is invalid\n", buffer);
        }
    }
    fclose(fp);
    fp = fopen("output.txt", "w");
    if(is_first)
    {
        printf("There were no appropriate dates\n");  
    }
    else
    {
        printf("%s is max\n", max);
        printf("%s is min\n", min);
        if(fp != NULL)
        {
            fprintf(fp, "%s is max\n", max);
            fprintf(fp, "%s is min\n", min);
        }
        fclose(fp);
    }
    return 0;
}
