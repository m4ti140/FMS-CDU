#pragma once
#include<cmath>
#include<algorithm>
#include"Aircraft.h"



Azimuth great_circle_out(Coord p1, Coord p2)
{
	float lon12;
	//float tan1y, tan1x;
	float tan2y, tan2x;
	//Azimuth a1(Azimuth::rad);
	Azimuth a2(Azimuth::rad);

	p1.SetMode(Coord::rad);
	p2.SetMode(Coord::rad);
	lon12 = p2.lon - p2.lon;
	//tan1y = sin(lon12);
	tan2y = sin(lon12);
	//tan1x = (cos(p1.lat)*tan(p2.lat)) - sin(p1.lat)*cos(lon12);
	tan2x = 0 - cos(p2.lat)*tan(p1.lat) - sin(p2.lat)*cos(lon12);

	//a1 = atan2(tan1x, tan1y);
	a2 = atan2(tan2x, tan2y);

	a2.SetMode(Azimuth::deg);

	return a2;
}

Azimuth great_circle_in(Coord p1, Coord p2)
{

	float lon12;
	float tan1y, tan1x;
	//float tan2y, tan2x;
	Azimuth a1(Azimuth::rad);

	p1.SetMode(Coord::rad);
	p2.SetMode(Coord::rad);
	lon12 = p2.lon - p2.lon;
	tan1y = sin(lon12);
	//tan2y = sin(lon12);
	tan1x = (cos(p1.lat)*tan(p2.lat)) - sin(p1.lat)*cos(lon12);
	//tan2x = 0 - cos(p2.lat)*tan(p1.lat) - sin(p2.lat)*cos(lon12);

	a1 = atan2(tan1x, tan1y);
	//a2 = atan2(tan2x, tan2y);
	a1.SetMode(Azimuth::deg);

	return a1;

}

float great_circle_distance(Coord p1, Coord p2)
{
	float lon12;
	float coss;
	p1.SetMode(Coord::rad);
	p2.SetMode(Coord::rad);
	lon12 = p2.lon - p1.lon;

	coss = sin(p1.lat)*sin(p2.lat) + cos(p1.lon)*cos(p2.lon)*cos(lon12);
	return R1 * acos(coss);
}