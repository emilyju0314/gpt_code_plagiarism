#include <iostream>
using namespace std;

int main()
{
  while (true)
  {
    char board[8][8];
    for (int i=0; i<8; i++)
    {
      for (int j=0; j<8; j++)
      {
        cin >> board[i][j];
      }
    }

    bool flag = false;
    for (int i=0; i<8; i++)
    {
      for (int j=0; j<8; j++)
      {
        if ( board[i][j] == '1' )   //  ブロックがあれば
        {
          if ( board[i+3][j] == '1' )
          {
            cout << 'B' << endl;
          }
          else if ( board[i][j+3] == '1' )
          {
            cout << 'C' << endl;
          }
          else if ( board[i+2][j-1] == '1' )
          {
            cout << 'D' << endl;
          }
          else if ( board[i+1][j+2] == '1' )
          {
            cout << 'E' << endl;
          }
          else if ( board[i+2][j+1] == '1' )
          {
            cout << 'F' << endl;
          }
          else if ( board[i+1][j-1] == '1' )
          {
            cout << 'G' << endl;
          }
          else
          {
            cout << 'A' << endl;
          }
          flag = true;
        }
        if (flag) break;
      }
      if (flag) break;
    }

    char dummy;
    cin >> noskipws;
    cin >> dummy >> dummy;
    cin >> skipws;
    if ( cin.eof() ) break;
  }
}