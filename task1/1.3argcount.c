#define DEBUG 0

#include <stdlib.h>
#include <stdio.h>

int a2i(char* number);
int len(char* text);
int power(int base, int pwr);
void strcopy(char* target, char* source);
int strcompare(char* textA, char* textB);

int main(int argc, char** argv)
{
    int i;
    int keywords = 0;
    int integers = 0;
    int strings = 0;
    int flags = 0;
    char** args = malloc(sizeof(char*)*argc);
    int argsI = 0;
    for(i = 1; i < argc; i++)
    {
        int j;
        int chars_pres = 0;
        for(j=0; argv[i][j] && argv[i][j] != '-' && argv[i][j] != '='; j++)
        {
            chars_pres = 1;
        }
        if(argv[i][0] == '-' || argv[i][1] == 0)
        {
            for(j = 0; argv[i][j] != 0; j++)
            {
                if(argv[i][j] - '0' > 9 || argv[i][j] - '0' < 0)
                {
                    // 2938745823948275102938457928193821
                    strings++;
                    chars_pres = 1;
                    args[argsI++] = argv[i];
                    break;
                }
            }
            if(chars_pres == 0)
            {
                integers++;
                args[argsI++] = argv[i];
            }
        }
        else
        {
            flags++;{
            args[argsI++] = argv[i];
        }
    }

    printf("ints = %d\nstrings = %d\nflags = %d\nkeywords = %d\n",integers,strings,flags,keywords);
    printf("parsed arguments = %d\n",argsI);
    int* integers_array = malloc(sizeof(int) * integers);
    char** strings_array = malloc(sizeof(char*)*strings);
    char** flags_array = malloc(sizeof(char*)*flags);
    char** keywords_array = malloc(sizeof(char*)*keywords);
    int k = 0, s = 0, i = 0, f = 0;
    for(i = 0; i < argsI; i++)
    {
        switch(args[i][1])
        {
            case 'i':
            {
                integers_array[k++] = a2i(args[i]);
#if DEBUG
                printf("int = %d\n",integers_array[k-1]);
#endif
                break;
            }
            case 's':
            {
                strings_array[s] = malloc(sizeof(char)*len(args[i]));
                strcopy(strings_array[s++],args[i]);
#if DEBUG
                printf("string = %s\n",strings_array[s-1]);
#endif
                break;
            }
            case 'f':
            {
                flags_array[f] = malloc(sizeof(char)*len(args[i]));
                strcopy(flags_array[f++],args[i]);
                break;
            }
            case 'k':
            {
                keywords_array[k] = malloc(sizeof(char)*len(args[i]));
                strcopy(keywords_array[k++],args[i]);
                break;
            }
        }
    }

    if(strcompare("--greet",keywords_array[0]))
    {
        printf("yo! nigga %s\n",strings_array[0]);
    }
    else if(strcompare("--add",keywords_array[0]))
    {
        printf("result = %d\n",integers_array[0] + integers_array[1]);
    }
    else if(strcompare("--list",keywords_array[0]))
    {
        for(i = 0; i < k; i++)
        {
            printf("0. int = %d\n",integers_array[i]);
        }
        for(i = 0; i < s; i++)
        {
            printf("0. string = %s\n",strings_array[i]);
        }
        for(i = 0; i < k; i++)
        {
            printf("0. keyword = %s\n",keywords_array[i]);
        }
        for(i = 0; i < f; i++)
        {
            printf("0. flag = %s\n",flags_array[i]);
        }
    }

    return 0;
}

int a2i(char* number)
{
    int i;
    int ln = len(number);
#if DEBUG
    printf("len of num = %d\n",ln);
#endif
    int res = 0;
    for(i = 0; i < ln; i++)
    {
#if DEBUG
        int dc = number[i] - '0';
        int power = 0, add = 0;
        printf("resulting power = %d\n",power(10,ln-i-1));
#endif
        res += (number[i] - '0') * power(10,ln-i-1);
    }

    return res;
}

int len(char* text){int i=0;while(text[i++]); return i;}

int power(int base, int pwr)
{
    int i;
    int res = 1;
    for(i = 0; i < pwr; i++)
    {
        res *= base;
    }

    return res;
}

void strcopy(char* target, char* source)
{
    while(*target++ = *source++);
}

int strcompare(char* textA, char* textB)
{
    while(*textA++ == *textB++ && *textA);
    return !(textA[-1] - textB[-1]);
}
}