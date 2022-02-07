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

macierz operator+(const macierz& l, const macierz& p)
{
	if (l.k == p.k && l.w == p.w)
	{
		macierz temp(l.k, l.w);
		for (int i = 0; i < p.w; i++)
		{
			for (int j = 0; j < p.k; j++)
				temp.tab[i][j] = l.tab[i][j] + p.tab[i][j];
		}
		return temp;
	}
	else
		throw 2;
}

macierz operator-(const macierz& l, const macierz& p)
{
	if (l.k == p.k && l.w == p.w)
	{
		macierz temp(l.k, l.w);
		for (int i = 0; i < p.w; i++)
		{
			for (int j = 0; j < p.k; j++)
				temp.tab[i][j] = l.tab[i][j] - p.tab[i][j];
		}
		return temp;
	}
	else
		throw 3;
}

macierz operator*(const macierz& l, const macierz& p)
{
	if (l.k == p.w)
	{
		macierz temp(l.w, p.k);
		for (int i = 0; i < l.w; i++)
			for (int k = 0; k < p.k; k++)
			{
				for (int j = 0; j < l.k; j++)
					temp.tab[i][k] += l.tab[i][j] * p.tab[j][k];
			}
		return temp;
	}
	else
		throw 4;
}

void main()
{
	macierz a(3, 2);
	a.wypelnij();
	a.drukuj();
	try
	{
		a.wyznacznik();
	}
	catch (int e)
	{
		cout << endl;
		cout << "\tWyjatek numer " << e << "! Sprawdz rozmiar macierzy!!!" << endl;
		cout << endl;
	}
	macierz b(3, 3);
	cout << "Wpisz kolejne komorki macierzy B" << endl;
	b.wypelnijsam();
	cout << "Macierz B" << endl;
	b.drukuj();
	cout << "Wyznacznik macierzy B: " << b.wyznacznik() << endl;
	cout << "Operator = -> C=B" << endl;
	macierz c = b;
	cout << "Macierz B" << endl;
	b.drukuj();
	cout << "Macierz C" << endl;
	c.drukuj();
	cout << "Operator + -> D=B+C" << endl;
	macierz d = b + c;
	cout << "Macierz B" << endl;
	b.drukuj();
	cout << "Macierz C" << endl;
	c.drukuj();
	cout << "Macierz D" << endl;
	d.drukuj();
	cout << "Operator + -> gdy rozne rozmiary macierzy E=A+B" << endl;
	try
	{
		macierz e = a + b;
	}
	catch (int e)
	{
		cout << endl;
		cout << "\tWyjatek numer " << e << "! Sprawdz rozmiar macierzy!!!" << endl;
		cout << endl;
	}
	cout << "Tak samo z operatorem -" << endl;
	cout << "Operator - -> F=B-C" << endl;
	macierz f = b - c;
	cout << "Macierz B" << endl;
	b.drukuj();
	cout << "Macierz C" << endl;
	c.drukuj();
	cout << "Macierz F" << endl;
	f.drukuj();
	cout << "Operator * -> G=B*C" << endl;
	macierz g = c * b;
	cout << "Macierz B" << endl;
	b.drukuj();
	cout << "Macierz C" << endl;
	c.drukuj();
	cout << "Macierz G" << endl;
	g.drukuj();
	cout << "Operator * -> gdy wymiary macierzy nie pozwalaja na mnozenie H=A*B" << endl;
	try
	{
		macierz h = a * b;
	}
	catch (int e)
	{
		cout << endl;
		cout << "\tWyjatek numer " << e << "! Sprawdz rozmiar macierzy!!!" << endl;
		cout << endl;
	}
}