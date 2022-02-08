#include <iostream>
#include "macierz.h"
using namespace std;



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