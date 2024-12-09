#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
  int i, jd[4] = {0,0,0,0};
  char s[100000];
  scanf("%s",s);
  for(i = 0;i < strlen(s);i++){
    if(isdigit(s[i])){
      jd[1] = 1;
    }else if(isupper(s[i])){
      jd[2] = 1;
    }else if(islower(s[i])){
      jd[3] = 1;
    }
  }
  if(strlen(s) >= 6){
    jd[0] = 1;
  }
  for(i = 0;i < 4;i++){
    if(!jd[i]){
      break;
    }
  }
  if(i == 4){
    printf("VALID\n");
  }else{
    printf("INVALID\n");
  }
  return 0;
}