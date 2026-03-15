#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define MAXGOAL 8

int my_getline(char line[], int maxline);
void copy(char *to, char *from);

int main()
{
    int len;
    char line[MAXLINE];
    char results[MAXLINE * 10] = "";
    char *end = results;  // pointer that tracks where to append next

    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        if (len > MAXGOAL)
        {
            copy(end, line);   // copy into current end position
            end = end + len;   // move end pointer forward by line length
        }
    }

    printf("long lines:\n%s\n", results);
    return 0;
}

int my_getline(char *s, int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *(s + i) = c;       // pointer arithmetic instead of s[i]
    if (c == '\n')
    {
        *(s + i) = c;
        ++i;
    }
    *(s + i) = '\0';
    return i;
}

void copy(char *to, char *from)
{
    while (*from != '\0')   // walk from pointer forward
    {
        *to = *from;        // dereference both and copy
        to++;
        from++;
    }
    *to = '\0';
}