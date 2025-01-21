#include <stdio.h>
#include <stdlib.h>

char str[100], pat[50], rep[50], ans[100];
int s = 0, p = 0, r = 0, a = 0;
int flag = 0;

void string_match()
{
    while (str[s] != '\0')
    {
        p = 0;
        r = 0;
        if (str[s] == pat[0])
        {
            // checking for complete pattern match
            int temp_s = s;

            while (pat[p] != '\0')
            {
                if (pat[p] == str[temp_s])
                {
                    p++;
                    temp_s++;
                }
                else
                {
                    break;
                }
                
            }
            if (pat[p] == '\0')
            {
                flag = 1;
                s = temp_s;
                for(r=0; rep[r]!='\0'; r++)
                {
                    ans[a] = rep[r];
                    a++;
                }
            }
        }
        else
        {
            ans[a] = str[s];
            a++;
            s++;
        }
    }
    ans[a] = '\0';
}

int main()
{
    printf("Enter the main string: ");
    scanf("%s", str);

    printf("Enter the pattern string: ");
    scanf("%s", pat);

    printf("Enter the replace string: ");
    scanf("%s", rep);

    string_match();

    if (flag == 1)
    {
        printf("the resulting string is: %s\n", ans);
    }
    else
    {
        printf("Error: pattern string not found!\n");
    }

    return 0;
}