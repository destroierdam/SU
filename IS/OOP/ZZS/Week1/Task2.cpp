#include"stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;
struct Polar
{
	double r;
	double phi;
};
struct Rect
{
	double x;
	double y;
};
Rect polarToRect(Polar v)
{
	Rect temp;
	temp.x = v.r * cos(v.phi);
	temp.y = v.r * sin(v.phi);
	return temp;
}
Polar rectToPolar(Rect v)
{
	Polar temp;
	temp.r = sqrt(v.x*v.x + v.y*v.y);
	temp.phi = atan(v.y / v.x);
	return temp;
}
void showRect(Rect v, bool format = false)
{
	if (format) cout << "x coordinate: ";
	cout << v.x;

	cout << " ";

	if (format) cout << "y coordinate: ";
	cout << v.y;

	cout << endl;
}
void showPolar(Polar v, bool format = false)
{
	if (format) cout << "radius: ";
	cout << v.r;

	cout << " ";

	if (format) cout << "angle: ";
	cout << v.phi;
	
	cout << endl;
}
int main()
{
	int n;
	char choise;
	Polar polar[128];
	Rect rect[128];

	cout << "Choose vector form(p-polar,r-rectangular): ";
	cin >> choise;
	cout << "Number of vectors: ";
	cin >> n;
	switch (choise)
	{
	case 'r':
		for (int i = 0; i < n; i++)
		{
			cin >> rect[i].x >> rect[i].y;
			polar[i] = rectToPolar(rect[i]);
		}
		for (int i = 0; i < n; i++)
		{
			showPolar(polar[i], true);
		}
		break;
	case 'p':
		for (int i = 0; i < n; i++)
		{
			cin >> polar[i].r >> polar[i].phi;
			rect[i] = polarToRect(polar[i]);
		}
		for (int i = 0; i < n; i++)
		{
			showRect(rect[i], true);
		}
		break;
	}

	return 0;
}
/*

Да се дефинират структурите polar и rect, задаващи вектор с по-
лярни и с правоъгълни координати съответно. Да се дефинират
функции, които преобразуват вектор, зададен чрез правоъгълни
координати, в полярни координати и обратно, както и функции,
които извеждат вектор, зададен чрез полярните си и чрез правоъ-
гълните си координати.
В главната функция да се дава възможност за избор на режим
на въвеждане: r – за въвеждане в правоъгълни и p – в полярни
координати. За всеки избран режим да се въведат произволен брой
вектори, да се преобразуват в другия режим и да се изведат.

*/
