#pragma once
#include <iostream>

using namespace std;


class macierz
{
public:
	macierz() : w(100), k(100)
	{
		cout << "\t\t\t\t\tdomyslna macierz 100x100" << endl;
		tab = new int* [w];
		for (int i = 0; i < w; i++)
			tab[i] = new int[k];
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < k; j++)
				tab[i][j] = 0;
		}
	}

	macierz(int x, int y) : w(x), k(y)
	{
		cout << "\t\t\t\t\tmacierz parametryczna o rozmiarze " << w << "x" << k << endl;
		tab = new int* [w];
		for (int i = 0; i < w; i++)
			tab[i] = new int[k];
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < k; j++)
				tab[i][j] = 0;
		}
	}
	macierz(const macierz& m)
	{
		w = m.w;
		k = m.k;
		tab = new int* [w];
		for (int i = 0; i < w; ++i)
			tab[i] = new int[k];
		for (int i = 0; i < w; ++i)
			for (int j = 0; j < k; ++j)
				tab[i][j] = m.tab[i][j];

	}
	~macierz()
	{
		for (int i = 0; i < w; i++)
			delete[] tab[i];
		delete[] tab;
	}

	void wypelnij()
	{
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < k; j++)
				tab[i][j] = i + 1;
		}
	}

	void wypelnijsam()
	{
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < k; j++)
			{
				int t;
				cin >> t;
				tab[i][j] = t;
			}
		}
	}

	void drukuj()
	{
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < k; j++)
				cout << tab[i][j] << "\t";
			cout << endl;
		}
	}

	int wyznacznik()
	{
		if (w == k)
		{
			if (w == 2)
				return tab[0][0] * tab[1][1] - tab[1][0] * tab[0][1];
			else if (w == 3)
				return tab[0][0] * tab[1][1] * tab[2][2] + tab[0][1] * tab[1][2] * tab[2][0] + tab[0][2] * tab[1][0] * tab[2][1] - tab[0][2] * tab[1][1] * tab[2][0] - tab[1][2] * tab[2][1] * tab[0][0] - tab[0][1] * tab[1][0] * tab[2][2];
			else
				cout << "no bez przesady - maksymalny rozmiar macierzy to 3x3" << endl;
		}
		else
		{
			throw 1;
		}
	}

	macierz operator=(const macierz& a)
	{
		macierz temp(w, k);
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < k; j++)
				temp.tab[i][j] = a.tab[i][j];
		}
		return temp;
	}


	int GetW() { return w; }
	int GetK() { return k; }

	//private:
	int w;
	int k;
	int** tab;
};