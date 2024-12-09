#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	int i, j;
	string s, st;
	map<char, string> toCode;
	map<string, char> toA;

	toCode['A'] = "00000";
	toCode['B'] = "00001";
	toCode['C'] = "00010";
	toCode['D'] = "00011";
	toCode['E'] = "00100";
	toCode['F'] = "00101";
	toCode['G'] = "00110";
	toCode['H'] = "00111";
	toCode['I'] = "01000";
	toCode['J'] = "01001";
	toCode['K'] = "01010";
	toCode['L'] = "01011";
	toCode['M'] = "01100";
	toCode['N'] = "01101";
	toCode['O'] = "01110";
	toCode['P'] = "01111";
	toCode['Q'] = "10000";
	toCode['R'] = "10001";
	toCode['S'] = "10010";
	toCode['T'] = "10011";
	toCode['U'] = "10100";
	toCode['V'] = "10101";
	toCode['W'] = "10110";
	toCode['X'] = "10111";
	toCode['Y'] = "11000";
	toCode['Z'] = "11001";
	toCode[' '] = "11010";
	toCode['.'] = "11011";
	toCode[','] = "11100";
	toCode['-'] = "11101";
	toCode['\''] = "11110";
	toCode['?'] = "11111";
	toA["101"] = ' ';
	toA["000000"] = '\'';
	toA["000011"] = ',';
	toA["10010001"] = '-';
	toA["010001"] = '.';
	toA["000001"] = '?';
	toA["100101"] = 'A';
	toA["10011010"] = 'B';
	toA["0101"] = 'C';
	toA["0001"] = 'D';
	toA["110"] = 'E';
	toA["01001"] = 'F';
	toA["10011011"] = 'G';
	toA["010000"] = 'H';
	toA["0111"] = 'I';
	toA["10011000"] = 'J';
	toA["0110"] = 'K';
	toA["00100"] = 'L';
	toA["10011001"] = 'M';
	toA["10011110"] = 'N';
	toA["00101"] = 'O';
	toA["111"] = 'P';
	toA["10011111"] = 'Q';
	toA["1000"] = 'R';
	toA["00110"] = 'S';
	toA["00111"] = 'T';
	toA["10011100"] = 'U';
	toA["10011101"] = 'V';
	toA["000010"] = 'W';
	toA["10010010"] = 'X';
	toA["10010011"] = 'Y';
	toA["10010000"] = 'Z';

	while (getline(cin, s)) {
		st = "";
		for (i = 0; i < s.size(); i++) st += toCode[s[i]];

		s = "";
		for (i = 0; i < st.size(); i++) {
			s += st.substr(i, 1);
			if (toA.count(s)) {
				cout<<toA[s];
				s = "";
			}
		}
		cout<<endl;
	}

	return 0;
}