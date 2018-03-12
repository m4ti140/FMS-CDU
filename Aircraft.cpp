#include "Aircraft.h"


void Azimuth::Trim()
{
	if (_mode == deg)		//for degrees: add/subtract 360 degrees
	{		
		while (_heading < 0.) _heading += 360.;
		while (_heading > 360.) _heading -= 360.;
	}
	if (_mode == rad)		//for radians: add/subtract 2pi radians
	{
		while (_heading < 0.) _heading += 6.28318;
		while (_heading > 6.28318) _heading -= 6.28318;
	}
}

float Azimuth::GetDeg()
{
	if (_mode == deg) return _heading;
	else return _heading * 57.29578;
}

float Azimuth::GetRad()
{
	if (_mode == rad) return _heading;
	else return _heading / 57.29578;
}

void Azimuth::SetMode(Unit mode)
{
	if (mode == _mode) return;
	else
	{
		if (mode == rad) _heading = this->GetRad();
		if (mode == deg) _heading = this->GetDeg();
		_mode = mode;
	}
}

Azimuth& Azimuth::operator=(const Azimuth& assign)
{
	if (&assign == this) return *this;
	if (this->_mode == assign._mode) this->_heading = assign._heading;
	else
	{
		if (assign._mode == deg)  this->_heading = assign._heading / 57.29578;
		if (assign._mode == rad)  this->_heading = assign._heading * 57.29578;
	}
	return *this;
}

Azimuth& Azimuth::operator=(const float& assign)
{
	this->_heading = assign;
	this->Trim();
	return *this;
}

bool operator<(const Azimuth& lhs, const Azimuth& rhs)
{
	Azimuth temp = lhs;
	temp -= rhs;
	temp.SetMode(Azimuth::deg);
	if ((float)temp > 180.) return true;
	else return false;
}

bool operator==(const Azimuth& lhs, const Azimuth& rhs)
{
	if (lhs._mode == rhs._mode) return lhs._heading == rhs._heading;
	else
	{
		Azimuth tlhs = lhs;
		Azimuth trhs = rhs;

		tlhs.SetMode(Azimuth::deg);
		trhs.SetMode(Azimuth::deg);
		
		return tlhs._heading == trhs._heading;
	}
}

float AbsDiff(Azimuth a1, Azimuth a2)
{
	if (a1 < a2)
	{
		a2 -= a1;
		return a2;
	}
	else
	{
		a1 -= a2;
		return a1;
	}

}

Azimuth Azimuth::Rev()
{
	Azimuth ret = *this;
	ret -= 180.;
	return ret;
}

std::string Coord::GetString()
{
	std::ostringstream buff;	//stream object

	buff.flags(std::ios::fixed);
	buff.precision(1);

	float intpart;
	float frac;

	frac = modff(lat, &intpart); //separate fractional part for conversion

	if (lat > 0.) buff << "N";	//insert north or south hemisphere
	else buff << "S";

	if (fabsf(lat) < 10.) buff << "0";	//insert leading zeroes

	buff << (int)intpart << "*" << frac * 60 << " "; //insert degrees and minutes
	
	frac = modff(lon, &intpart);

	if (lon > 0.) buff << "E";
	else buff << "W";

	if (fabsf(lon) < 100.) buff << "0";
	if (fabsf(lon) < 10.) buff << "0";

	buff << (int)intpart << "*" << frac * 60;

	return buff.str();
}

int Coord::SetByString(const std::string& input)
{
	//format: 012345678901234567
	//format: cdd°dd.d cddd°dd.d
	//check if correct
	if (input.length() != 18) return 0;
	if (input[0] != 'N' && input[0] != 'S') return 0;
	if (input[9] != 'E' && input[9] != 'W') return 0;
	if (input[3] != '°' || input[13] != '°' || input[6] != '.' || input[16]!='.' || input[8]!=' ') return 0;
	if (!std::isdigit(input[1]) || !isdigit(input[2]) || !isdigit(input[4]) || !isdigit(input[5]) || !isdigit(input[7]) || !isdigit(input[10]) || !isdigit(input[11]) || !isdigit(input[12]) || !isdigit(input[14]) || !isdigit(input[15]) || !isdigit(input[17])) return 0;

	//read character by character
	lat = 10. * (input[1] - '0') + (input[2] - '0');
	lat += (10. * (input[4] - '0') + (input[5] - '0') + 0.1*(input[7] - '0')) / 60.;
	lon = 100. * (input[10] -'0') + 10. * (input[11] - '0') + (input[12] - '0');
	lon += (10. * (input[14] - '0') + (input[15] - '0') + 0.1*(input[17] - '0')) / 60.;
	return 1;
}

void Coord::SetMode(Unit mode)
{
	if (mode == _mode) return;
	else
	{
		if (mode == rad) {
			lat = lat RAD;
			lon = lon RAD;
		}
		if (mode == deg) {
			lat = lat DEG;
			lon = lon DEG;
		}
		_mode = mode;
	}
}