#include <stdio.h>


int main()
{
    char name[30], name1[30], name2[30], v[30], *p, *q, *r, *s;
    int vowel = 0;

    printf("Enter a word: ");
    scanf(" %s", name);

    p = name;
    while(*p != '\0')
    {
        if(*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' || *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U')
            vowel++;
        p++;
    }
    printf("\nNumber of vowels: %d", vowel);

    p = name;
    q = name1;
    r = v;
    while(*p != '\0')
    {
        if(*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' || *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U')
        {
            *r = *p;
            r++;
        }
        else
        {
            *q = *p;
            q++;
        }
        p++;
    }
    *q = '\0';
    *r = '\0';
    q = name1;
    printf("\nYour name without vowels: %s", q);

    p = name;
    q = name1;
    r--;
    s = name2;
    while(*p != '\0')
    {
        if(*p == *q)
        {
            *s = *q;
            s++;
            q++;
        }
        else
        {
            *s = *r;
            s++;
            r--;
        }
        p++;
    }
    *s = '\0';
    s = name2;
    printf("\nYour name with reversed vowels: %s\n", s);

    return 0;
}
