#include <iostream>

using namespace std;

int main()
{
	int precision;
	cin >> precision;

	short e[precision];
	short skladnik[precision];

	for (int i = 0; i < precision; i++)
		e[i] = skladnik[i] = 0;

	e[0] = skladnik[0] = 1;

	int fact = 1;
	int zeros = 0;

	int pos;

	while (zeros<precision)
	{

		//zliczamy ilosc zer w skladniku
		zeros = 0;
		while (skladnik[zeros] == 0)
			zeros++;


		//dzielimy skladnik[] przez fact
		int temp = 0;
		for (pos = zeros; pos < precision; pos++)
		{
			temp = temp * 10 + skladnik[pos];
			skladnik[pos] = temp / fact;
			temp = temp - fact*skladnik[pos];
		}


		//dodajemy nowo uzyskany skladnik[] do e[]
		int overflow = 0;
		for (int i = precision-1; i >=0; i--)
		{
			e[i] = skladnik[i] + e[i] + overflow;
			overflow = e[i] / 10;
			e[i] = e[i] % 10;
		}

		//zwiekszamy fact
		fact++;
	}

	for(int i =0;i<precision;i++)
        cout << e[i];

	return 0;
}
