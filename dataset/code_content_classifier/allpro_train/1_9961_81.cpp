#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int i, j;
    char T[1001] = {'\0'};
    char P[1001] = {'\0'};
    scanf("%s", T);
    scanf("%s", P);

    int lengtht = strlen(T);
    int lengthp = strlen(P);
    for (i = 0; i < lengtht; i++)
    {
        for (j = 0; j < lengthp && P[j] == T[i + j]; j++);
        if (j == lengthp)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}

