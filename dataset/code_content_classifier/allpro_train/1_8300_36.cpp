#include<stdio.h>

char *era; 
int year;

void translate(int ad, int month, int day);

int main(void)
{
    int ad, month, day;
    while((scanf("%d %d %d", &ad, &month, &day)) != EOF) {
        if (ad <= 1867) {
            printf("pre-meiji\n");
        } else if (ad == 1868 && month <= 8) {
            printf("pre-meiji\n");
        } else if (ad == 1868 && month == 9 && day <= 7) {
            printf("pre-meiji\n");
        } else {
        translate(ad, month, day);
            printf("%s %d %d %d\n", era, year, month, day);
        }
   }
   return 0;
}

void translate(int ad, int month, int day)
{
    if ((ad <= 1911) || (ad == 1912 && month <= 6) || (ad == 1912 && month == 7 && day <= 29)) {
        era = "meiji";
        year = ad - 1868 + 1;
    } else if ((ad <= 1925) || (ad == 1926 && month <= 11) || (ad == 1926 && month == 12 && day <= 24)) {
        era = "taisho";
        year = ad - 1912 + 1;
    } else if ((ad <= 1988) || (ad == 1989 && month == 1 && day <= 7)) {
        era  = "showa";
        year = ad - 1925;
    } else {
        era = "heisei";
        year = ad -1988;
    }
}
        
        
    