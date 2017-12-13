#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
//#include "Data.h"
#include "Navaid.h"
#undef max
#include <limits>

extern std::vector<Navaid>airport_db;
extern std::vector<Navaid>nodes_db;
extern std::vector<Navaid>fixes_db;

int navdata_parser(int mode = 0, std::string search = "XXXXX", Navaid* ret = NULL, std::ifstream* curNavFile = NULL);

class Route
{
public:
	Route();
	~Route();
	Route(const Route& copy);
	Route& operator=(const Route& assign);
	std::string name;
	std::vector<Navaid*>path;
};

class Airway : public Route       //class used for Airway segments
{
private:
	std::string entryid, exitid, entryreg, exitreg, entrytype, exittype;
public:
	char dir;
	int cls;
	int base, top;
	std::vector<std::string>awy;
	Airway();
	Airway(Navaid* entry, Navaid* exit);
	Airway(const Airway& copy);
	~Airway();
	void ReadFromString(std::string input);
	Airway& operator=(const Airway& assign);
	friend std::istream& operator>>(std::istream& is, Airway& data);
	//friend std::ostringstream& operator>>(std::ostringstream& is, Airway& data);
};

class AirRoute  //class used for entire airways and pathfinding
{
private:
	std::vector<Navaid>vertices;
	std::vector<std::vector<int>>adjecents;
public:
	std::string name;
	std::vector<Airway>route;
	AirRoute();
	AirRoute(std::string tname, std::vector<Airway>troute);
	~AirRoute() {}
	std::vector<Navaid> BFS(const Navaid start, const Navaid end);
	std::vector<Airway> SegmentList(std::vector<Navaid> traversal);
};

class Flightplan
{
public:
	std::string name;
	std::deque<Navaid> path;
	std::deque<Airway> segments;
	std::deque<int> restrictions;
	std::deque<int> restr_rel;
	std::deque<int> elevation;
	std::deque<float> distances;
	std::deque<std::string> major_nodes;
	std::deque<int>node_indices;
	std::deque<std::string> airways;
	std::string origin, destination;
	const Airway direct;
	const Navaid discont_nav;
	const Airway discont_awy;
	//const Airway initial;

	Flightplan();
	~Flightplan() {}
	Flightplan(const Flightplan& copy);	
	Flightplan& operator=(const Flightplan& assign);
	void Origin(Navaid orig);
	void Destination(Navaid dest);
	//Navaid Current();
	void Next();
	//void Switch(Navaid over);
	void Wipe();
	bool IsEnroute();
	void AddWaypoint(Navaid wp);
	void AddAirway(AirRoute airway, int index);
	bool IsAirwaySelected();
	bool IsWaypointSelected();
private:
	bool _enroute;
	bool _discontinous;

};