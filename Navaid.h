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
#include "XPLMNavigation.h"
#include <string>
#include <sstream>
#include <streambuf>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>

	/*typedef enum
	{

		Unkn = 0b0,
		Airp = 0b1,
		NDB = 0b10,
		VOR = 0b100,
		ILS = 0b1000,
		Loc = 0b10000,
		GS = 0b100000,
		OM = 0b1000000,
		MM = 0b10000000,
		IM = 0b100000000,
		Fix = 0b1000000000,
		DME = 0b10000000000

	}NavType;*/

typedef enum
{
	Unkn = 0,
	Airp = 1,
	NDB = 2,
	VOR = 3,
	Loc_ILS = 4,
	Loc_SA = 5,
	GS = 6,
	OM = 7,
	MM = 8,
	IM = 9,
	Fix = 11,
	DME = 12,
	DME_SA = 13,
	FAP = 14,
	GBAS = 15,
	LTP = 16,
	EOFType = 99
}NavTypeNew;

struct Navaid
{

	Navaid();
	Navaid(std::string tid);
	Navaid(NavTypeNew type);
	Navaid(XPLMNavRef source);
	Navaid(const Navaid& copy);
	Navaid& operator=(const Navaid& assign);
	friend bool operator==(const Navaid& compare1, const Navaid& compare2);
	friend bool operator!=(const Navaid& compare1, const Navaid& compare2);
	friend std::istream& operator>>(std::istream& is, Navaid& data);
	~Navaid();
	

	NavTypeNew type;
	float lat, lon;
	float heading;
	int elev;
	int range;
	int freq;
	std::string id, name, reg, regid;
	


};

class Airport : public Navaid
{
	Airport();
};