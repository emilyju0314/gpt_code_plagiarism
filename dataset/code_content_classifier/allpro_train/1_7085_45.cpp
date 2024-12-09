#include <cstdio>

int main(void)
{
    char r[5], a[5];
    while (1){
        scanf("%s %s", r, a);
        if (r[0] == '0' && a[0] == '0') break;
        int hit = 0, blow = 0;
        for (int i = 0; i < 4; i++){
            if (r[i] == a[i]) hit++;
        }
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if (r[i] == a[j]) blow++;
            }
        }
        printf("%d %d\n", hit, blow - hit);
    }
    
    return (0);
}