// Tests.cpp : Defines the entry point for the console application.
//

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <iostream>
//#include <Aircraft.h>
#include <geomath.h>


int main()
{
	Coord C(0., 0.);
	Coord E(0., 10.);
	Coord W(0., -10.);
	Coord N(10., 0.);
	Coord S(-10., 0.);

	Azimuth out1;
	Azimuth out2;
	Azimuth out3;

	float out4;

	out1 = great_circle_in(E, N);
	out2 = great_circle_in(S, N);
	out3 = great_circle_in(W, N);
	out4 = great_circle_distance(S, N);

	std::cout << out1 << " " << out2 << " " << out3 << " " << out4 << std::endl;
	system("PAUSE");

    return 0;
}

