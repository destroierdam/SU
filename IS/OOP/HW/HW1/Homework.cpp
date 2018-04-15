#include"stdafx.h"
#include<iostream>
#include"Jedi.h"
#include"Stormtrooper.h"
#include"Planet.h"
#include"JediTemple.h"
#include"Army.h"
#include"System.h"
#include"Galaxy.h"
#include"GalacticRepublic.h"

int main()
{
	Jedi yoda;

    return 0;
}
/*

	Да се направи клас Jedi в който да има name(char*), rank(char* / enum), midi - chlorian(double / float), planet(Planet), spicies(char*), militaryRank(char*).

	Да се направи клас Stormtrooper в който да има id(char*), rank(enum), type(char*), planet(Planet).

	Да се направи клас Planet name(char*), planetSystem(char*), republic(char*) - име на притежаващата я република.

	Да се направи клас JediTemple в който да има jedi(Jedi*).

	Да се направи клас Army в който да има troops(Stormtrooper*).

	Да се направи клас Galaxy в който да има име на галактиката и planets(Planet*).

	Да се направи клас GalacticRepublic в който да има име на републиката, jediTemple(JediTemple), Army(army), galaxy(Galaxy).

	В JediTemple, трябва да могат да се добавят нови Jedi и да се премахват.
	
	В Army, трябва да могат да се добавят нови Stormtrooper и да се премахват.

	В Galaxy, трябва да могат да се добавят нови Planet и да се премахват.

	Желателно е операциите да бъдат извършвани посредством подходящ оператор.

	Да могат да се принтират всички Jedi на една планета и 
	да могат да се принитрат всички Stormtrooper на една планета, и 
	да могат да се принтират всички планети в галактика.

	Трябва информацията за Jedi, Stormtrooper и Planet да се пази в отделни файлове.т.е 
	Един файл за Jedi, един файл за Stormtrooper и един за Planet.



	Една система е доминирана от дадена република, ако съответната притежава повечето планети, но не по - малко от 3.
	
	Казваме, че една република доминира дадена галактика, ако 
	армията превъзхожда количествено джедаите и владее повечето системи в нея.
	 
	Да се напише функция, която по подадени републики и галактика определя доминиращата.
	Да се напише функция, която “създава” карта на галактиките с доминиращите ги републики, 
	като резултата го записва в текстов файл както следва : [Име на галактика] - [Име на република]

*/
