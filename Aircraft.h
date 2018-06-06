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
#include<string>
#include<sstream>
#include<cmath>
#include<cctype>

#define PI 3.14159265
#define RAD *PI/180.
#define DEG *180./PI
#define R1 3440.0695

class Azimuth
{
public:
	typedef enum
	{
		deg = 0,
		rad = 1
	}Unit;
protected:
	float _heading;
	Unit _mode;
	void Trim();
public:

	Azimuth() : _heading(0.), _mode(deg) {}
	Azimuth(Unit mode) : _heading(0.), _mode(mode) {}
	Azimuth(const Azimuth& copy) : _heading(copy._heading), _mode(copy._mode) {}
	Azimuth(const float& copy) : _heading(copy), _mode(deg) { Trim(); }

	float GetRad();
	float GetDeg();
	void SetMode(Unit mode);

	Azimuth& operator=(const Azimuth& assign);  //doesn't switch unit
	Azimuth& operator=(const float& assign);
	~Azimuth() {}
	operator float() const { return _heading; }

	Azimuth& operator+=(const float& rhs) { _heading += rhs; Trim(); return *this; }
	Azimuth& operator+=(const Azimuth& rhs) { _heading += rhs._heading; Trim(); return *this; }
	Azimuth& operator-=(const Azimuth& rhs) { _heading -= rhs._heading; Trim(); return *this; }
	Azimuth& operator-=(const float& rhs) { _heading -= rhs; Trim(); return *this; }
	Azimuth& operator*=(const float& rhs) { _heading *= rhs; Trim(); return *this; }
	Azimuth& operator/=(const float& rhs) { _heading /= rhs; Trim(); return *this; }

	friend Azimuth operator+(Azimuth lhs, const Azimuth& rhs) { lhs += rhs; return lhs; }
	friend Azimuth operator+(Azimuth lhs, const float& rhs) { lhs += rhs; return lhs; }
	friend Azimuth operator+(const float& lhs, Azimuth rhs) { rhs += lhs; return rhs; }

	friend Azimuth operator-(Azimuth lhs, const Azimuth& rhs) { lhs -= rhs; return rhs; }
	friend Azimuth operator-(Azimuth lhs, const float& rhs) { lhs -= rhs; return lhs; }
	friend Azimuth operator-(float lhs, Azimuth rhs) { lhs -= rhs._heading; rhs._heading = lhs; rhs.Trim(); return rhs; }

	friend Azimuth operator*(Azimuth lhs, const float& rhs) { lhs *= rhs; return lhs; }
	friend Azimuth operator*(const float& lhs, Azimuth rhs) { rhs *= lhs; return rhs; }

	friend Azimuth operator/(Azimuth lhs, const float& rhs) { lhs /= rhs; return lhs; }

	friend bool operator<(const Azimuth& lhs, const Azimuth& rhs); //lhs - reference azimuth, rhs - target azimuth, returns true if the reference is in left semicricle relative to the target
	friend bool operator>(const Azimuth& lhs, const Azimuth& rhs) { return rhs < lhs; } //right semicricle
	friend bool operator<=(const Azimuth& lhs, const Azimuth& rhs) { return !(lhs > rhs); }
	friend bool operator>=(const Azimuth& lhs, const Azimuth& rhs) { return !(lhs < rhs); }

	friend bool operator==(const Azimuth& lhs, const Azimuth& rhs);  //will convert to everything to degrees if units disagree
	friend bool operator!=(const Azimuth& lhs, const Azimuth& rhs) { return !(lhs == rhs); }

	friend float AbsDiff(Azimuth a1, Azimuth a2);
	Azimuth Rev();

};

struct Coord
{

	typedef enum
	{
		deg = 0,
		rad = 1
	}Unit;

	Unit _mode;

	float lat;
	float lon;

	Coord() :lat(0.), lon(0.), _mode(deg) {}
	Coord(float slat, float slon) : lat(slat), lon(slon), _mode(deg) {}
	~Coord() {}

	void SetMode(Unit mode);

	std::string GetString();
	int SetByString(const std::string& input);
	

};

struct Aircraft
{

	float airspeed;
	float fuel_state;
	float max_fuel;
	float mass;
	float max_mass;
	Azimuth heading;
	Azimuth next_heading;
	Azimuth prev_heading;
	float lift;
	float drag;
	float lon;
	float lat;
	float alt;
	float windspeed;
	float winddir;

	Aircraft() : heading(Azimuth::deg), next_heading(Azimuth::deg), prev_heading(Azimuth::deg) {}
	~Aircraft() {}
};



