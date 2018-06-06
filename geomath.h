//Copyright(c) 2018 Mateusz Brzozowski
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

#pragma once
#include<cmath>
#include<algorithm>
#include"Aircraft.h"



Azimuth great_circle_in(Coord p1, Coord p2)
{
	float lon12;
	//float tan1y, tan1x;
	float tan2y, tan2x;
	//Azimuth a1(Azimuth::rad);
	Azimuth a2(Azimuth::rad);

	p1.SetMode(Coord::rad);
	p2.SetMode(Coord::rad);
	lon12 = p2.lon - p1.lon;
	//tan1y = sin(lon12);
	tan2y = sin(lon12);
	//tan1x = (cos(p1.lat)*tan(p2.lat)) - sin(p1.lat)*cos(lon12);
	tan2x = 0. - (cos(p2.lat)*tan(p1.lat)) + (sin(p2.lat)*cos(lon12));

	//a1 = atan2(tan1x, tan1y);
	a2 = atan2(tan2y, tan2x);

	a2.SetMode(Azimuth::deg);

	return a2;
}

Azimuth great_circle_out(Coord p1, Coord p2)
{

	float lon12;
	float tan1y, tan1x;
	//float tan2y, tan2x;
	Azimuth a1(Azimuth::rad);

	p1.SetMode(Coord::rad);
	p2.SetMode(Coord::rad);
	lon12 = p2.lon - p1.lon;
	tan1y = sin(lon12);
	//tan2y = sin(lon12);
	tan1x = (cos(p1.lat)*tan(p2.lat)) - sin(p1.lat)*cos(lon12);
	//tan2x = 0 - cos(p2.lat)*tan(p1.lat) - sin(p2.lat)*cos(lon12);

	a1 = atan2(tan1y, tan1x);
	//a2 = atan2(tan2x, tan2y);
	a1.SetMode(Azimuth::deg);

	return a1;

}

float great_circle_distance(Coord p1, Coord p2)
{
	double lon12, y, x, clat1, clat2, slat1, slat2, slon, clon;
	double ds;
	p1.SetMode(Coord::rad);
	p2.SetMode(Coord::rad);
	
	lon12 = p2.lon - p1.lon;
	clat1 = cos(p1.lat);
	clat2 = cos(p2.lat);
	slat1 = sin(p1.lat);
	slat2 = sin(p2.lat);
	slon = sin(lon12);
	clon = cos(lon12);

	y = sqrt(clat2*slon*clat2*slon + pow(clat1*slat2 - slat1 * clat2*clon, 2));
	x = slat1 * slat2 + clat1 * clat2*clon;
	ds = atan2(y, x)*180./PI;

	return ds * 60.;

}