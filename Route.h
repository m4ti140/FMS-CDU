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
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
//#include "Data.h"
#include "Navaid.h"
//#include "Page.h"
//#include "Pages.h"
#undef max
#include <limits>

extern std::vector<Navaid>airport_db;
extern std::vector<Navaid>nodes_db;
extern std::vector<Navaid>fixes_db;

int navdata_parser(int mode = 0, std::string search = "-----", Navaid* ret = NULL, std::ifstream* curNavFile = NULL);

class Route			//unused
{
public:
	Route();
	~Route();
	Route(const Route& copy);
	Route& operator=(const Route& assign);
	std::string name;
	std::vector<Navaid*>path;
};

class Airway       //class used for Airway segments
{
private:
	std::string entryid, exitid, entryreg, exitreg;
	NavTypeNew entrytype, exittype;
	std::string awy;
public:
	std::string name;	//can be empty
	Navaid* entry, *exit;
	char dir;
	int cls;
	int base, top;
	Airway();
	Airway(std::string name);
	Airway(Navaid* entry, Navaid* exit);
	Airway(const Airway& copy);
	~Airway();
	//void ReadFromString(std::string input);
	Airway& operator=(const Airway& assign);
	friend std::istream& operator>>(std::istream& is, Airway& data);
	//friend std::ostringstream& operator>>(std::ostringstream& is, Airway& data);
	bool MapNavaids();
	bool CheckAwy(const std::string &iawy);
	Navaid* GetExit(const Navaid& entry);
};

extern const Airway direct;
extern const Navaid discont_nav;
extern const Airway discont_awy;
extern const Navaid empty_orig_dest;


class AirRoute  //class used for entire airways and pathfinding
{
private:
	std::vector<Navaid>vertices;
	std::vector<std::vector<int>>adjecents;
public:
	std::string name;
	std::vector<Airway>route;
	AirRoute();
	AirRoute(std::string tname) : name(tname) {}
	AirRoute(std::string tname, std::vector<Airway>troute);
	AirRoute(const AirRoute& copy) : vertices(copy.vertices), adjecents(copy.adjecents), name(copy.name), route(copy.route) {}
	AirRoute& operator=(const AirRoute& assign);
	~AirRoute() {}
	std::vector<Navaid> BFS(const Navaid start, const Navaid end);
	std::vector<Airway> SegmentList(std::vector<Navaid> traversal);
	bool CheckNavaid(Navaid find); //checks if the route includes selected navaid
	Navaid CheckNavaidID(std::string find); //searches for navaid id in the vertices;
};

extern AirRoute invalid;

typedef enum
{
	A = 1,
	B = -1,
	E = 0
}Rel;

class Leg
{
public:
	Navaid waypoint;		//target waypoint object
	Airway segment;			//airway object to fly via
	std::string airway_id;	//airway id string for pathfinder/route page display
	int restriction;		//altitude restriction
	Rel restrict_rel;		//below/above/exact
	int	elevation;			//actual altitude to fly at
	float distance;			//distance to waypoint along the route
	float heading;			//heading to said waypoint along the route
private:
	bool _isWaypoint;		//whether or not to include the leg on route page
	bool _discontinuity;	//discontinuity at this leg

public:
	//Leg() : waypoint(discont_nav), segment(direct), restriction(0), restrict_rel(A), elevation(0), distance(0.), _isWaypoint(true) {} 
	Leg(bool iswp = true, Navaid wp = discont_nav, Airway seg = direct, int rest = 0, Rel rel = A, int elev = 0, float dist = 0., std::string awid = "DIRECT") : waypoint(wp), segment(seg), restriction(rest), restrict_rel(rel), elevation(elev), distance(dist), _isWaypoint(iswp), airway_id(awid), _discontinuity(false) {}
	Leg(const Leg& copy) : waypoint(copy.waypoint), segment(copy.segment), airway_id(copy.airway_id), restriction (copy.restriction), restrict_rel(copy.restrict_rel), elevation(copy.elevation), distance(copy.distance), heading(copy.heading), _isWaypoint(copy._isWaypoint), _discontinuity(false) {}
	Leg& operator=(const Leg& assign);
	~Leg() {}
	bool isWaypoint() const { return _isWaypoint; }
	bool isDiscont() const { return _discontinuity; }
	void SetDiscont() { _discontinuity = true; }
	void SetCont() { _discontinuity = false; }
};

class Flightplan
{
private:
	bool _enroute;
	bool _discontinous;
public:
	std::string name;
	/*std::deque<Navaid> path;
	std::deque<Airway> segments;
	std::deque<int> restrictions;
	std::deque<int> restr_rel;
	std::deque<int> elevation;
	std::deque<float> distances;
	std::deque<std::string> major_nodes;
	std::deque<int>node_indices;
	std::deque<std::string> airways;*/
	std::deque<Leg> legs;
	std::vector<AirRoute> stored_awy;
	Navaid origin, destination;


	Flightplan();
	~Flightplan() {}
	Flightplan(const Flightplan& copy);	
	Flightplan& operator=(const Flightplan& assign);
	void Origin(Navaid orig);
	void Destination(Navaid dest);
	std::string GetDestName();
	std::string GetOrigName();
	//Navaid Current();
	void Next();
	//void Switch(Navaid over);
	void Wipe();
	bool IsEnroute();
	AirRoute &RecallRoute(std::string name);
	AirRoute &RecallRoute(int index);
	int FindWpIndex(int index);
	Leg& GetWp(int index);
	bool AddWaypoint(Navaid wp, int index);
	void DelWaypoint(int index);
	bool AddAirway(AirRoute airway, int index);
	void DelAirway(int index, bool forget=true);
	bool IsAirwaySelected(int index=0);
	bool IsWaypointSelected(int index = 0);
	void CheckContinuity();
	//bool UpdateRoutePage();


};

