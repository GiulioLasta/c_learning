#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_replace_all(char *result, const char *src, const char *find, const char *replace)
{
    char *pos;
    char tmp[10000];
    int find_len = strlen(find);
    int replace_len = strlen(replace);

    strcpy(result, src);  // start with a copy of src

    while ((pos = strstr(result, find)) != NULL)
    {
        strcpy(tmp, pos + find_len);       // save everything after the match
        strcpy(pos, replace);              // write replacement at match position
        strcpy(pos + replace_len, tmp);    // append the saved part after
    }
}

int main()
{
    char *text   = malloc(10000);
    char *result = malloc(10000);
    int tmp;
    int nc = 0;

    while ((tmp = getchar()) != EOF)
    {
        text[nc] = tmp;
        nc++;
    }
    text[nc] = '\0';

    str_replace_all(result, text, "A", "BBBB");

    printf("%s\n", result);

    free(text);
    free(result);
    return 0;
}