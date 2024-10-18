#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <string.h>

//--- STRING.H ---
size_t my_strlen(const char *str)
{
    int i = 0;
    while(str[i] != '\0') i++;
    return i;
}
char *my_strcat(char *destination, const char *source)
{
    size_t len_destination = my_strlen(destination);
    size_t len_source = my_strlen(source);

    int j = 0;
    size_t i;

    for(i = len_destination; i < len_destination + len_source; i++)
    {
        destination[i] = source[j++];
    }
    destination[i] = '\0';

    return destination;
}
char *my_strncat(char *destination, const char *source, size_t num)
{
    size_t len_destination = my_strlen(destination);

    int j = 0;
    size_t i;

    for(i = len_destination; i < len_destination + num; i++)
    {
        destination[i] = source[j++];
    }
    destination[i] = '\0';

    return destination;
}
int my_strcmp(const char *str1, const char *str2)
{
    int i = 0;

    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
        {
            if(str1[i] < str2[i]) return -1;
            else return 1;
        }
        i++;
    }

    return 0;
}
int my_strncmp(const char *str1, const char *str2, size_t num)
{
    int i = 0;

    while(str1[i] != '\0' && str2[i] != '\n' && i < num)
    {
        if(str1[i] != str2[i])
        {
            if(str1[i] < str2[i]) return -1;
            else return 1;
        }
        i++;
    }

    return 0;
}
char *my_strcpy(char *destination, const char *source)
{
    size_t len_source = my_strlen(source);

    size_t i;
    for(i = 0; i < len_source; i++)
    {
        destination[i] = source[i];
    }
    destination[i] = '\0';

    return destination;
}
char *my_strncpy(char *destination, const char *source, size_t num)
{
    size_t len_source = my_strlen(source);

    size_t i;
    for(i = 0; i < num; i++)
    {
        if(i >= len_source) destination[i] = '\0';
        else destination[i] = source[i];
    }

    destination[i] = '\0';

    return destination;
}
char *my_strdup(const char *str1)
{
    char *out = malloc(my_strlen(str1));
    if(out == NULL) return NULL;

    size_t i;
    for(i = 0; i < my_strlen(str1); i++)
    {
        out[i] = str1[i];
    }
    out[i] = '\0';

    return out;
}
char *my_strchr(const char *str, int character)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == character) return (char*)str + i;
        i++;
    }
    return NULL;
}
char *my_strrchr(const char *str, int character)
{
    size_t i = my_strlen(str) - 1;

    while(i > 0)
    {
        if(str[i] == character) return (char*)str + i;
        i--;
    }

    return NULL;
}

//--- CTYPE.H ---
int my_isalpha(int c)
{
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return 1;
    return 0;
}
int my_isupper(int c)
{
    if(c >= 'A' && c <= 'Z') return 1;
    return 0;
}
int my_islower(int c)
{
    if(c >= 'a' && c <= 'z') return 1;
    return 0;
}
int my_isdigit(int c)
{
    if(c >= 0 && c <= 9) return 1;
    return 0;
}
int my_isalnum(int c)
{
    if((c >= 'a' && c <= 'z') ||
       (c >= 'A' && c <= 'Z') ||
       (c >= 0 && c <= 9))
        return 1;
    return 0;
}
int my_toupper(int c)
{
    if(my_islower(c)) return c - ' ';
    return c;
}
int my_tolower(int c)
{
    if(my_isupper(c)) return c + ' ';
    return c;
}

int main()
{
    printf("==== CTYPE.H ====\n");
    printf("--isalpha--\n");
    printf("%d %d %d\n",
           my_isalpha('a'),
           my_isalpha('B'),
           my_isalpha(9)
           );

    printf("--isupper--\n");
    printf("%d %d %d\n",
           my_isupper('a'),
           my_isupper('F'),
           my_isupper(11)
           );

    printf("--islower--\n");
    printf("%d %d %d\n",
           my_islower('c'),
           my_islower('R'),
           my_islower(4)
           );

    printf("--isdigit--\n");
    printf("%d %d %d\n",
           my_isdigit('h'),
           my_isdigit('J'),
           my_isdigit(2)
           );

    printf("--isalnum--\n");
    printf("%d %d %d %d\n",
           my_isalnum('g'),
           my_isalnum('T'),
           my_isalnum(2),
           my_isalnum('&')
           );

    printf("--toupper--\n");
    printf("%c %c %d\n",
           my_toupper('a'),
           my_toupper('B'),
           my_toupper(7)
           );

    printf("--tolower--\n");
    printf("%c %c %d\n",
           my_tolower('t'),
           my_tolower('G'),
           my_tolower(5)
           );

    printf("==== STRING.H ====\n");
    printf("--strlen--\n");
    printf("%llu %llu %llu\n",
           my_strlen("ala"),
           my_strlen("Ala ma kota a kot biega."),
           my_strlen("")
           );

    printf("--strcat--\n");
    char str1[32] = {};
    my_strcat(str1, "ala ");
    my_strcat(str1, "ma ");
    my_strcat(str1, "kota.");
    my_strcat(str1, "");
    printf("%s\n", str1);

    printf("--strncat--\n");
    char str2[32] = {0};
    my_strncat(str2, "ala ma kota", 3);
    my_strncat(str2, "ma", 2);
    my_strncat(str2, "", 4);
    my_strncat(str2, " lorem ipsum lorem ipsum", 10);
    printf("%s\n", str2);

    printf("--strcmp--\n");
    printf("%d %d %d\n",
           my_strcmp("kajak", "kajak"),
           my_strcmp("abcA", "abcB"),
           my_strcmp("abcB", "abcA")
           );

    printf("--strncmp--\n");
    printf("%d %d %d\n",
           my_strncmp("abcA", "abcB", 4),
           my_strncmp("abc", "abb", 2),
           my_strncmp("abZ", "abC", 3)
           );

    printf("--strcpy--\n");
    char str3[32] = "Ala";
    my_strcpy(str3, "kajak");
    printf("%s\n", str3);
    my_strcpy(str3, "");
    printf("'%s'\n", str3);
    my_strcpy(str3, "diwandiawdnwadndiwa");
    printf("%s\n", str3);

    printf("--strncpy--\n");
    char str4[32] = "dwad";
    my_strncpy(str4, "ala ma kota", 6);
    printf("%s\n", str4);
    my_strncpy(str4, "", 9);
    printf("'%s'\n", str4);
    my_strncpy(str4, "kajak", 10);
    printf("%s\n", str4);

    printf("--strdup--\n");
    char* str5 = my_strdup("ala ma kota");
    printf("%s\n", str5);
    char* str6 = my_strdup("");
    printf("'%s'\n", str6);
    free(str5);
    free(str6);

    printf("--strchr--\n");
    printf("%s\n%s\n",
           my_strchr("ala ma kota", 'a'),
           my_strchr("kajak", 'j')
           );
    char *str7 = my_strchr("woda", 'z');
    if(str7 == NULL) printf("Letter not found\n");

    printf("--strrchr--\n");
    printf("%s\n%s\n%s\n",
           my_strrchr("ala ma kota", 't'),
           my_strrchr("kajak", 'a'),
           my_strchr("woda", 'w')
           );

    char *str8 = my_strchr("woda", 'z');
    if(str8 == NULL) printf("Letter not found\n");
}