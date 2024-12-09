#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, N, M;
	char inst[200001];
	int Pmax[400], Pmin[400], Psum[400], NumP;
	int qL, qR, Val, Max, Min, partL, partR;
	int base;

	cin >> T;
	while (T--)
	{
		cin >> N >> M >> inst;
		
		NumP = (N + 499) / 500;
		for (int p = 0; p < NumP - 1; p++)
		{
			Pmax[p] = 0, Pmin[p] = 0, Psum[p] = 0;
			base = 500 * p;
			for (int i = 0; i < 500; i++)
			{
				if (inst[base + i] == '+')
				{
					Psum[p]++;
					Pmax[p] = max(Pmax[p], Psum[p]);
				}
				else
				{
					Psum[p]--;
					Pmin[p] = min(Pmin[p], Psum[p]);
				}
			}
		}
		Pmax[NumP - 1] = 0, Pmin[NumP - 1] = 0, Psum[NumP - 1] = 0;
		for (int i = 500 * (NumP - 1); i < N; i++)
		{
			if (inst[i] == '+')
			{
				Psum[NumP - 1]++;
				Pmax[NumP - 1] = max(Pmax[NumP - 1], Psum[NumP - 1]);
			}
			else
			{
				Psum[NumP - 1]--;
				Pmin[NumP - 1] = min(Pmin[NumP - 1], Psum[NumP - 1]);
			}
		}

		while (M--)
		{
			cin >> qL >> qR;
			Val = 0, Max = 0, Min = 0;
			partL = --qL / 500, partR = --qR / 500;

			for (int p = 0; p < partL; p++)
			{
				Max = max(Max, Val + Pmax[p]);
				Min = min(Min, Val + Pmin[p]);
				Val += Psum[p];
			}
			for (int i = 500 * partL; i < qL; i++)
			{
				if (inst[i] == '+')
				{
					Val++;
					Max = max(Max, Val);
				}
				else
				{
					Val--;
					Min = min(Min, Val);
				}
			}
			base = min(500 * (partR + 1), N);
			for (int i = qR + 1; i < base; i++)
			{
				if (inst[i] == '+')
				{
					Val++;
					Max = max(Max, Val);
				}
				else
				{
					Val--;
					Min = min(Min, Val);
				}
			}
			for (int p = partR + 1; p < NumP; p++)
			{
				Max = max(Max, Val + Pmax[p]);
				Min = min(Min, Val + Pmin[p]);
				Val += Psum[p];
			}

			cout << Max - Min + 1 << "\n";
		}
	}
}