#include<iostream>
#include<string>
using namespace std;

void smallToLarge( char& a )
{
    if( 'a' <= a && a <= 'z' )
        a -= ( 'a' - 'A' );
}

void LargeToSmall( char& a )
{
    if( 'A' <= a && a <= 'Z' )
        a += ( 'a' - 'A' );
}

int main()
{
    string s;
    char c;

    while( cin >> s >> c )
    {
        int a = s.size();

        if( c == 'X' )
            break;
        else if( c == 'U' || c == 'L' )
        {
            c == 'U' ? smallToLarge(s[0]) : LargeToSmall(s[0]);
            for( int i = 0; i < a; i++ )
                if( s[i] == '_' )
                    smallToLarge(s[i+1]);
                else
                    cout << s[i];
        }
        else
        {
            LargeToSmall(s[0]);
            for( int i = 0; i < a; i++ )
            {
                if( 'A' <= s[i] && s[i] <= 'Z' )
                {
                    cout << '_';
                    LargeToSmall(s[i]);
                }
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}
