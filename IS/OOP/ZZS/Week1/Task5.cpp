#include"stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;
const double c = 229792;
struct Planet
{
	char name[64];
	double distFromSum;
	double diam;
	double mass;
};
void readPlanet(Planet &p)
{
	cin >> p.name >> p.distFromSum >> p.diam >> p.mass;
}
void showPlanet(Planet &p)
{
	cout << p.name << " " << p.distFromSum << " " << p.diam << " " << p.mass << endl;
}
double lightTime(Planet &p)
{
	return p.distFromSum / c;
}
void readPlanetFile(const char *fileName,Planet *p, int sz)
{
	ifstream fin;
	fin.open(fileName, ios::in);
	if (fin.is_open())
	{
		for (int i = 0; i < sz; i++)
		{
			fin >> p[i].name >> p[i].distFromSum >> p[i].diam >> p[i].mass;
		}
		fin.close();
	}
	else
	{
		cerr << "Error opening file" << endl;
	}
}
void showPlanet(Planet *p, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		showPlanet(p[i]);
	}
}
void showPlanetBiggestDiameter(Planet *p, int sz)
{
	int i, maxp=0;
	for (i = 0; i < sz; i++)
	{
		if (p[i].diam > p[maxp].diam)
		{
			maxp = i;
		}
	}
	showPlanet(p[maxp]);
}
int main()
{
	Planet p;

	// (а) въвежда данни за планета от клавиатурата;
	readPlanet(p);

	// (б) извежда данните за планета;
	showPlanet(p);

	// (в) връща като резултат броя секунди, които са необходими на светлината да достигне от слънцето до планетата
	//	   (да се приeме, че светлината има скорост 299792 km / s и че разстоянието на планетата до слънцето е зададено в километри).
	double time = lightTime(p);

	// (г) създава едномерен масив от планети с фиксиран размер и въвежда данните за тях от текстов файл;
	Planet planets[8];
	readPlanetFile("planets.txt",planets, 8);

	// (д) извежда данните за планетите от масив, подаден на функцията като параметър;
	showPlanet(planets, 8);

	// (е) отпечатва данните за планетата с най-голям диаметър от масив, подаден на функцията като параметър;
	showPlanetBiggestDiameter(planets, 8);
	return 0;
}
/*

Да се дефинира структура Planet, определяща планета по име (сим-
волен низ), разстояние от слънцето, диаметър и маса (реални чис-
ла). Да се дефинират функции, изпълняващи следните действия:


*/
