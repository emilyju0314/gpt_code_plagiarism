#include <string>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#define BUFSIZE 10
using namespace std;

int main(void){
    int c;
    char buf[BUFSIZE];
    cin >> buf;
    int times = atoi(buf);

    for(int i = 0; i < times; i++){
      cin >> buf;
      int hr, mn;
      double shrt, lng;
      buf[2] = '\0';
      hr = atoi(buf);
      mn = atoi(&buf[3]);
      shrt = hr * 30.0 + mn * 0.5;
      lng = mn * 6.0;
      double deg = fabs(lng - shrt);
      deg = (deg >180) ? (360-deg) : deg;
      if(deg < 30) cout << "alert" << endl;
      else if(deg < 90) cout << "warning" << endl;
      else cout << "safe" << endl;
    }
    return 0;
}