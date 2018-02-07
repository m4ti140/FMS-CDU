#pragma once
#include "Navaid.h"



Navaid::Navaid()
{
	lat = lon = 0.0;
	freq = elev = range = 0;
	type = Unkn;
	heading = 0.0;
	id = name = reg = regid = "";

}

Navaid::Navaid(std::string tid)
{
	lat = lon = 0.0;
	freq = elev = range = 0;
	type = Unkn;
	heading = 0.0;
	name = reg = regid = "";
	
}

Navaid::Navaid(XPLMNavRef source)
{
	//prepare temporary storage for items that need additional conversion
	XPLMNavType ttype;
	float height;
	char *cid, *cname;
	cid = new char[32];
	cname = new char[256];

	//get data from X Plane
	XPLMGetNavAidInfo(source, &ttype, &lat, &lon, &height, &freq, &heading, cid, cname, NULL);

	//convert type
	double temp;
	int temp2;

	int inttype = static_cast<int>(ttype);
	if (inttype == 0) type = Unkn;
	if (inttype > 0 && inttype < 512) { 
		temp = log2(inttype) + 1;
		temp2 = static_cast<int>(temp);
		type = static_cast<NavTypeNew>(temp2); }
	if (inttype >= 512)
	{
		temp = log2(inttype) + 2;
		temp2 = static_cast<int>(temp);
		type = static_cast<NavTypeNew>(temp2);
	}
	//reconstruct id and name
	id = std::string(cid);
	name = std::string(cname);

	//convert elevation
	elev = static_cast<int>(height);

	//clean up
	delete[] cid;
	delete[] cname;

}

Navaid::Navaid(NavTypeNew ttype)
{
	lat = lon = 0.0;
	freq = elev = range = 0;
	type = ttype;
	heading = 0.0;
	id = name = reg = regid = "";
}

Navaid::Navaid(const Navaid& copy)
{
	lat = copy.lat;
	lon = copy.lon;
	freq = copy.freq;
	elev = copy.elev;
	type = copy.type;
	heading = copy.heading;
	id = copy.id;
	name = copy.name;
	reg = copy.reg;
	regid = copy.regid;
	range = copy.range;
}

Navaid& Navaid::operator=(const Navaid& assign)
{
	if (this == &assign)return *this;
	else
	{
		this->lat = assign.lat;
		this->lon = assign.lon;
		this->elev = assign.elev;
		this->freq = assign.freq;
		this->type = assign.type;
		this->heading = assign.heading;
		this->id = assign.id;
		this->name = assign.name;
		this->reg = assign.reg;
		this->regid = assign.regid;
		this->range = assign.range;
		return *this;
	}
}

bool operator==(const Navaid& c1, const Navaid& c2)
{
	return (c1.elev == c2.elev && c1.freq == c2.freq && c1.heading == c2.heading && c1.id == c2.id && c1.lat == c2.lat && c1.lon == c2.lon && c1.name == c2.name && c1.range == c2.range && c1.reg == c2.reg && c1.regid == c2.regid && c1.type == c2.type);
}

bool operator!=(const Navaid& c1, const Navaid& c2)
{
	return !(c1 == c2);
}

std::istream& operator>>(std::istream& is, Navaid& data)
{
	int ttype;

	if (data.type == Fix)
	{
		// 33.492513889    9.217400000  07EBA ENRT DT 2118994

		is >> data.lat;
		if (data.lat > 90.)
		{
			if (data.lat == 99) is.setstate(std::ios::eofbit);
			else is.setstate(std::ios::failbit);
			return is;
		}
		is >> data.lon >> data.id >> data.regid >> data.reg >> ttype;
		//ttype takes ARINC424 wpt type, unused for now
		return is;
	}

	//3   9.037802778    7.285102778     1191    11630   130     -2.000  ABC ENRT DN ABUJA VOR/DME

	
	is >> ttype;
	if (ttype > 16)
	{
		if (ttype == 99) is.setstate(std::ios::eofbit);
		else is.setstate(std::ios::failbit);
		return is;
	}
	is >> data.lat >> data.lon >> data.elev >> data.freq >> data.range >> data.heading >> data.id >> data.regid >> data.reg;
	std::stringbuf buf;
	is.get(buf, '\n');
	data.name = buf.str();
	data.type = static_cast<NavTypeNew>(ttype);

	//debug
	/*
	std::ofstream out;
	out.open("debug.log", std::ios::out);
	out << "type: " << data.type << std::endl;
	out << "coordinates: " << data.lon << " " << data.lat << std::endl;
	out << "elevation: " << data.elev << std::endl;
	out << "frequency: " << data.freq << std::endl;
	out << "range: " << data.range << std::endl;
	out << "heading: " << data.heading << std::endl;
	out << "ID: " << data.id << std::endl;
	out << "Regional ID: " << data.regid << std::endl;
	out << "Region: " << data.reg <<std::endl;
	out << "Name: " << data.name;
	out.close();
	*/
	return is;

}

/*Navaid::Navaid(XPLMNavRef source)
{
	XPLMNavType outtype;
	char outid[32], outname[256], outreg;
	XPLMGetNavAidInfo(source, &outtype, &lat, &lon, &elev, &freq, &heading, outid, outname, &outreg);
	type = static_cast<NavType>(outtype);
	const char* end = std::find(outid, outid + sizeof(outid), '\0');
	id.assign(outid);
	name.assign(outname);
	reg.push_back(outreg);
}*/

Navaid::~Navaid()
{
}

Airport::Airport()
{
	lat = lon = 0.0;
	elev = 0;
	freq = 0;
	type = Airp;
	heading = 0.0;
	id = name = reg = "";
}