﻿#pragma once
#include "Route.h"

std::vector<Navaid>airport_db;
std::vector<Navaid>nodes_db;
std::vector<Navaid>fixes_db;



Route::Route()
{
	name = "";
}

Route::~Route()
{	
}

Route::Route(const Route& copy)
{
	name = copy.name;
path = copy.path;
}

Route& Route::operator=(const Route& assign)
{
	if (this == &assign) return *this;
	else
	{
		this->name = assign.name;
		this->path = assign.path;
return *this;
	}
}

Airway::Airway() : entry(NULL), exit(NULL), dir('N'), base(0), top(600), cls(1) {}

Airway::Airway(Navaid* ientry, Navaid* iexit)
{
	//name = "";
	entry = ientry;
	exit = iexit;
	dir = 'N';
	top = 600;
	base = 0;
	cls = 1;
	/*entryid = entry->id;
	exitid = exit->id;
	entryreg = entry->reg;
	exitreg = exit->reg;
	entrytype = entry->type;
	exittype = exit->type;*/
}

Airway::Airway(const Airway& copy) : name(copy.name), entry(copy.entry), exit(copy.exit), dir(copy.dir), base(copy.base), top(copy.top), cls(copy.cls), awy(copy.awy), entryid(copy.entryid), exitid(copy.exitid), entryreg(copy.entryreg), exitreg(copy.exitreg), entrytype(copy.entrytype), exittype(copy.exittype) {}

Airway& Airway::operator=(const Airway& assign)
{
	this->name = assign.name;
	this->entry = assign.entry;
	this->exit = assign.exit;
	this->dir = assign.dir;
	this->base = assign.base;
	this->top = assign.top;
	this->cls = assign.cls;
	this->awy = assign.awy;
	this->entryid = assign.entryid;
	this->exitid = assign.exitid;
	this->entryreg = assign.entryreg;
	this->exitreg = assign.exitreg;
	this->entrytype = assign.entrytype;
	this->exittype = assign.exittype;
	return *this;
}

Airway::~Airway() {}

//void Airway::ReadFromString(std::string input)   //depracated
//{
//	// 070A CY 11  080A CY 11 N 2 280 600 NCAA
//	int type;
//
//	size_t pos=0;
//	size_t pos2 = 0;
//	std::string edit = input;
//	std::vector<Navaid>::iterator it;
//	std::stringstream convert;
//	Navaid* navpt;
//
//	while (edit[pos] == ' ')        //read entry id
//	{
//		pos++;
//	}
//	pos2 = edit.find(' ', pos);
//	entryid = edit.substr(pos, pos2 - pos);
//	pos = pos2;
//
//	while (edit[pos] == ' ')        //read entry region
//	{
//		pos++;
//	}
//	pos2 = edit.find(' ', pos);
//	entryreg = edit.substr(pos, pos2 - pos);
//	pos = pos2;
//
//	while (edit[pos] == ' ')        //read entry type
//	{
//		pos++;
//	}
//	pos2 = edit.find(' ', pos);
//	convert << edit.substr(pos, pos2 - pos);
//	pos = pos2;
//	convert >> type;
//	if(type == 11)
//	{
//		it = std::find_if(std::begin(fixes_db), std::end(fixes_db), [&](Navaid const& n) {return n.id == entryid; });
//		if (it != fixes_db.end()) {
//			while (it->reg != entryreg && it != fixes_db.end()) it = std::find_if(std::next(it), std::end(fixes_db), [&](Navaid const& n) {return n.id == entryid; });
//		}
//		if (it != fixes_db.end()) {
//			navpt = &(*it);
//			path.push_back(navpt);
//		}
//	}
//	else
//	{
//		it = std::find_if(std::begin(nodes_db), std::end(nodes_db), [&](Navaid const& n) {return n.id == entryid; });
//		if (it != nodes_db.end()) {
//			while (it->reg != entryreg && it != nodes_db.end()) it = std::find_if(std::next(it), std::end(nodes_db), [&](Navaid const& n) {return n.id == entryid; });
//		}
//		if (it != nodes_db.end()) {
//			navpt = &(*it);
//			path.push_back(navpt);
//		}
//	}
//
//
//	while (edit[pos] == ' ')        //read exit id
//	{
//		pos++;
//	}
//	pos2 = edit.find(' ', pos);
//	exitid = edit.substr(pos, pos2 - pos);
//	pos = pos2;
//
//	while (edit[pos] == ' ')        //read exit region
//	{
//		pos++;
//	}
//	pos2 = edit.find(' ', pos);
//	exitreg = edit.substr(pos, pos2 - pos);
//	pos = pos2;
//
//	while (edit[pos] == ' ')        //read exit type
//	{
//		pos++;
//	}
//	pos2 = edit.find(' ', pos);
//	convert << edit.substr(pos, pos2 - pos);
//	pos = pos2;
//	convert >> type;
//	if (type == 11)
//	{
//		it = std::find_if(std::begin(fixes_db), std::end(fixes_db), [&](Navaid const& n) {return n.id == exitid; });
//		if (it != fixes_db.end()) {
//			while (it->reg != exitreg && it != fixes_db.end()) it = std::find_if(std::next(it), std::end(fixes_db), [&](Navaid const& n) {return n.id == exitid; });
//		}
//		if (it != fixes_db.end()) {
//			navpt = &(*it);
//			path.push_back(navpt);
//		}
//	}
//	else
//	{
//		it = std::find_if(std::begin(nodes_db), std::end(nodes_db), [&](Navaid const& n) {return n.id == exitid; });
//		if (it != nodes_db.end()) {
//			while (it->reg != exitreg && it != nodes_db.end()) it = std::find_if(std::next(it), std::end(nodes_db), [&](Navaid const& n) {return n.id == exitid; });
//		}
//		if (it != nodes_db.end()) {
//			navpt = &(*it);
//			path.push_back(navpt);
//		}
//	}
//
//	while (edit[pos] == ' ')        //read direction
//	{
//		pos++;
//	}
//	pos2 = edit.find(' ', pos);
//	dir = edit[pos];
//	pos = pos2;
//
//	while (edit[pos] == ' ')        //read class
//	{
//		pos++;
//	}
//	pos2 = edit.find(' ', pos);
//	convert << edit.substr(pos, pos2 - pos);
//	pos = pos2;
//	convert >> cls;
//
//	while (edit[pos] == ' ')        //read base
//	{
//		pos++;
//	}
//	pos2 = edit.find(' ', pos);
//	convert << edit.substr(pos, pos2 - pos);
//	pos = pos2;
//	convert >> base;
//
//	while (edit[pos] == ' ')        //read top
//	{
//		pos++;
//	}
//	pos2 = edit.find(' ', pos);
//	convert << edit.substr(pos, pos2 - pos);
//	pos = pos2;
//	convert >> top;
//
//	while(pos<edit.length()-1)
//	{
//		while (edit[pos] == ' ')        //read awy
//		{
//			pos++;
//		}
//		pos2 = edit.find('-', pos);
//		if (pos2 == std::string::npos)
//		{
//			awy.push_back(edit.substr(pos, edit.length() - pos));
//			return;
//		}
//		else
//		{
//			awy.push_back(edit.substr(pos, pos2 - pos));
//		}
//	}
//}

std::istream& operator>>(std::istream& is, Airway& data)
{
	// 070A CY 11  080A CY 11 N 2 280 600 NCAA

	std::string name;
	int type;
	std::string region;
	//std::vector<Navaid>::iterator it;
	//Navaid* navpt;
	//Navaid nav;
	std::ifstream file;

	/*for (int i = 0; i < 2; i++)
	{

		is >> name;

		if (name == "99")
		{
			is.setstate(std::ios::eofbit);
			return is;
		}

		is >> region >> type;

		if ((NavTypeNew)type == Fix)
		{
			it = std::find_if(std::begin(fixes_db), std::end(fixes_db), [&](Navaid const& n) {return n.id == name; });
			if(it!=fixes_db.end())while (it->reg != region && it!=fixes_db.end()) it = std::find_if(std::next(it), std::end(fixes_db), [&](Navaid const& n) {return n.id == name; });
			/*if (it == fixes_db.end())
			{
				int found;
				do
				{
					found = navdata_parser(2, name, NULL, &file);
					if (found = 0)break;
				} while (fixes_db.back().name != name || fixes_db.back().reg != region);
				if (found == 0) throw found;
				it = std::prev(fixes_db.end());
			}
		}
		else
		{
			it = std::find_if(std::begin(nodes_db), std::end(nodes_db), [&](Navaid const& n) {return n.id == name; });
			if(it!=nodes_db.end())while (it->reg != region && it!=nodes_db.end()) it = std::find_if(std::next(it), std::end(nodes_db), [&](Navaid const& n) {return n.id == name; });
			/*if (it == nodes_db.end())
			{
				int found;
				do
				{
					found = navdata_parser(1, name, NULL, &file);
					if (found = 0)break;
				} while (nodes_db.back().name != name || nodes_db.back().reg != region);
				if (found == 0) throw found;
				it = std::prev(nodes_db.end());
			}
		}
		
		if (file.is_open())file.close();

		navpt = &(*it);
		data.path.push_back(navpt);
	}*/

	is >> data.entryid;

	if (data.entryid == "99")
	{
		is.setstate(std::ios::eofbit);
		return is;
	}

	is >> data.entryreg >> type;

	data.entrytype = static_cast<NavTypeNew>(type);
	
	is >> data.exitid >> data.exitreg >> type;

	data.exittype = static_cast<NavTypeNew>(type);

	is >> data.dir >> data.cls >> data.base >> data.top >> data.awy;

	/*std::stringbuf airways;
	is.get(airways, '\n');

	size_t first = 0;
	size_t last = 0;
	if (airways.str().find('-', first) == std::string::npos) data.awy.push_back(airways.str());
	while ((last = airways.str().find('-', first)) != std::string::npos)
	{
		data.awy.push_back(airways.str().substr(first, last - 1));
		first = last + 1;
	}

	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
	return is;


}

bool Airway::MapNavaids()
{
	std::vector<Navaid>::iterator it;
	std::vector<Navaid>* db;

	if (entrytype == Fix)   //select proper database
	{
		db = &fixes_db;
	}
	else
	{
		db = &nodes_db;
	}

	it = db->begin();

	while (it != db->end() && entryid != it->id || entryreg != it->reg || entrytype != it->type) ++it;		//find the navaid with these id, type and region in database

	//repeat for exit

	if (it == db->end()) return false;		//return false if we did not find the navaid in database (bad entry)
	else entry = &(*it);

	if (exittype == Fix)   //select proper database
	{
		db = &fixes_db;
	}
	else
	{
		db = &nodes_db;
	}

	it = db->begin();

	while (it != db->end() && exitid != it->id || exitreg != it->reg || exittype != it->type) ++it;		//find the navaid with these id and region in database

	if (it == db->end()) return false;		//return false if we did not find the navaid in database (bad entry)
	else exit = &(*it);

	return true;		//navaids mapped, return true

}

bool Airway::CheckAwy(const std::string &iawy)
{
//#ifdef _DEBUG
//	std::ofstream debug;
//	debug.open("FMSdebug.txt", std::ios::app);
//#endif
	int i = 0;									//index
	int off = 0;								//offset
	const int lend = awy.size();				//awy size
	const int qend = iawy.size();				//iawy size
//#ifdef _DEBUG
//	debug << "lend=" << lend << std::endl << "qend=" << qend << std::endl << awy <<std::endl;
//#endif
	while ((i+off) < lend)					//until we reach the end of the airway list
	{
//#ifdef _DEBUG
//		debug << "off=" << off << " ";
//#endif
		while (awy[i+off] == iawy[i])			//while the current character in querry is matched with the first character from the list at current offset
		{
//#ifdef _DEBUG
//			debug << awy[i + off] << "@i=" << i << " " << std::endl;
//#endif
			i++;								//iterate to next character
			if (i == qend && i+off == lend || awy[i+off]=='-') return true;	//if we reached the end of querry return true (successfully found the searched id on the list)
			if ((i + off) == lend) return false;	//if the above is false and we reached the end of list return false
		}
		//past this point we failed to match a character
		while ((i+off)!=lend && awy[i+off] != '-')					//iterate to the list separator (hyphen)
		{
			i++;
		}
		off += i+1;								//set offset to the first character past the separator
		i = 0;									//reset the index
	}
	return false;								//if we got to this point, we have searched through the whole list and found nothing
}

Navaid* Airway::GetExit(const Navaid& ientry)
{
	if (ientry == *entry && dir == 'F' || dir == 'N')		//if it's entry and this direction is permitted
	{
		return exit;
	}
	if (ientry == *exit && dir == 'B' || dir == 'N')		//same for exit
	{
		return entry;
	}
	return NULL;											//null pointer if it's impossible to fly the airway in this direction
}

/*std::ostringstream& operator>>(std::ostringstream& is, Airway& data)
{
	// 070A CY 11  080A CY 11 N 2 280 600 NCAA

	std::string name;2
	int type;
	std::string region;
	std::vector<Navaid>::iterator it;
	Navaid* navpt;
	//Navaid nav;
	std::ifstream file;

	for (int i = 0; i < 2; i++)
	{

		is >> name;

		if (name == "99")
		{
			is.setstate(std::ios::eofbit);
			return is;
		}

		is >> region >> type;

		if ((NavTypeNew)type == Fix)
		{
			it = std::find_if(std::begin(fixes_db), std::end(fixes_db), [&](Navaid const& n) {return n.id == name; });
			if (it != fixes_db.end())while (it->reg != region && it != fixes_db.end()) it = std::find_if(std::next(it), std::end(fixes_db), [&](Navaid const& n) {return n.id == name; });
			if (it == fixes_db.end())
			{
				int found;
				do
				{
					found = navdata_parser(2, name, NULL, &file);
					if (found = 0)break;
				} while (fixes_db.back().name != name || fixes_db.back().reg != region);
				if (found == 0) throw found;
				it = std::prev(fixes_db.end());
			}
		}
		else
		{
			it = std::find_if(std::begin(nodes_db), std::end(nodes_db), [&](Navaid const& n) {return n.id == name; });
			if (it != nodes_db.end())while (it->reg != region && it != nodes_db.end()) it = std::find_if(std::next(it), std::end(nodes_db), [&](Navaid const& n) {return n.id == name; });
			if (it == nodes_db.end())
			{
				int found;
				do
				{
					found = navdata_parser(1, name, NULL, &file);
					if (found = 0)break;
				} while (nodes_db.back().name != name || nodes_db.back().reg != region);
				if (found == 0) throw found;
				it = std::prev(nodes_db.end());
			}
		}

		if (file.is_open())file.close();

		navpt = &(*it);
		data.path.push_back(navpt);
	}

	is >> data.dir >> data.cls >> data.base >> data.top;

	std::stringbuf airways;
	is.get(airways, '\n');

	size_t first = 0;
	size_t last = 0;
	while ((last = airways.str().find('-', first)) != std::string::npos)
	{
		data.awy.push_back(airways.str().substr(first, last - 1));
		first = last + 1;
	}
	return is;

}
*/

const Airway direct = [] {Airway dir; dir.name = "DIRECT"; return dir; }();
const Navaid discont_nav = [] {Navaid disc; disc.name = "□□□□□"; return disc; }();
const Airway discont_awy = [] {Airway disc; disc.name = "□□□□□"; return disc; }();
const Navaid empty_orig_dest = [] {Navaid ordest; ordest.name = "----"; return ordest; }();
AirRoute invalid("INVALID");

AirRoute::AirRoute() : name("") {}

AirRoute::AirRoute(std::string tname, std::vector<Airway>troute)
{
	name = tname;
	route = troute;
	int iFront, iBack;
	for (int i = 0; i < route.size(); i++)
	{
		/*
		if (std::find(vertices.begin(), vertices.end(), *route[i].path.front()) == vertices.end())
		{
			vertices.push_back(*route[i].path.front());
		}
		if (std::find(vertices.begin(), vertices.end(), *route[i].path.vector::back()) == vertices.end())
		{
			vertices.push_back(*route[i].path.back());
		}
		*/
		std::vector<int>temp;

		for (iFront = 0; iFront < vertices.size() && vertices[iFront] != *route[i].entry; iFront++);				//check if initial waypoint, is added save index if it is

		if (iFront == vertices.size())
		{
			vertices.push_back(*route[i].entry);  //add it if not
			adjecents.push_back(temp);
		}

		for (iBack = 0; iBack < vertices.size() && vertices[iBack] != *route[i].exit; iBack++);					//same for final

		if (iBack == vertices.size())
		{
			vertices.push_back(*route[i].exit);
			adjecents.push_back(temp);
		}

		if (route[i].dir == 'N' || route[i].dir == 'F')				//if airway is forward or both, add final to initial's adjecency list
		{
			adjecents[iFront].push_back(iBack);
		}
		if (route[i].dir == 'N' || route[i].dir == 'B')				//if airway is backward or both, add initial to final's adjecency list
		{
			adjecents[iBack].push_back(iFront);
		}

	}
}

AirRoute& AirRoute::operator=(const AirRoute& assign)
{
	this->adjecents = assign.adjecents;
	this->route = assign.route;
	this->vertices = assign.vertices;
	this->name = assign.name;
	return *this;
}

std::vector<Navaid> AirRoute::BFS(const Navaid start, const Navaid end)
{

	std::vector<bool>visited;		//discovery status
	std::vector<int>distance;		//best distance from end
	std::vector<int>predecessor;	//index of the preceding vertex on the shortest route
	for (int i = 0; i < vertices.size(); i++)
	{
		visited.push_back(false);					//set all to undiscovered
		distance.push_back(1000);					//set all shortest path to a lot
		predecessor.push_back(vertices.size() + 1);	//set all predecessors to no data (will check if index is out of range when necessary)
	}
	std::queue<int>to_check;		//queue of vertices to explore
	
	int iEnd;  //will hold the final index

	for (iEnd = 0; iEnd < vertices.size() && vertices[iEnd] != end; iEnd++);		//find the index of endpoint

	int current;

	visited[iEnd] = true;
	distance[iEnd] = 0;
	predecessor[iEnd] = iEnd;
	to_check.push(iEnd);

	while (!to_check.empty())
	{
		current = to_check.front();
		to_check.pop();
		for (int i = 0; i < adjecents[current].size(); i++)
		{
			if (!visited[adjecents[current][i]])
			{
				to_check.push(adjecents[current][i]);
				visited[adjecents[current][i]] = true;
				if (distance[adjecents[current][i]] > distance[current] + 1)
				{
					distance[adjecents[current][i]] = distance[current] + 1;
					predecessor[adjecents[current][i]] = current;
				}
			}
		}
	}

	int iStart;
	for (iStart = 0; iStart < vertices.size() && vertices[iStart] != start; iStart++);
	
	current = iStart;
	std::vector<Navaid>result;

	if (visited[iStart] == false) return result; //no path

	result.push_back(vertices[iStart]);

	do
	{

		current = predecessor[current];
		result.push_back(vertices[current]);
		
	} while (current != iEnd);

	return result;			//includes first and last

}
	
std::vector<Airway> AirRoute::SegmentList(std::vector<Navaid> traversal)
{
	std::vector<Airway> seglist;
	Airway cur;

	seglist.push_back(discont_awy);  //to keep indexes synced

	for (std::vector<Navaid>::iterator wpit=next(traversal.begin()); wpit != traversal.end(); ++wpit)
	{
		for (std::vector<Airway>::iterator segit = route.begin(); segit != route.end(); ++segit)
		{
			cur = *segit;
			if (cur.dir == 'N' || cur.dir == 'F')
				if (*cur.entry == *prev(wpit) && *cur.exit == *wpit) seglist.push_back(cur);
			if (cur.dir == 'N' || cur.dir == 'B')
				if (*cur.entry == *wpit && *cur.exit == *prev(wpit)) seglist.push_back(cur);
		}
	}

	return seglist;    //first element is nonsense
}

bool AirRoute::CheckNavaid(Navaid find)
{
	for (std::vector<Navaid>::iterator it; it != vertices.end(); ++it)
	{
		if (*it == find)return true;
	}
	return false;
}

Navaid AirRoute::CheckNavaidID(std::string find)
{
	for (std::vector<Navaid>::iterator it; it != vertices.end(); ++it)
	{
		if (it->id == find) return *it;
	}
	return NULL;
}

Leg& Leg::operator=(const Leg& assign)
{
	this->airway_id = assign.airway_id;
	this->distance = assign.distance;
	this->elevation = assign.elevation;
	this->heading = assign.heading;
	this->restriction = assign.restriction;
	this->restrict_rel = assign.restrict_rel;
	this->segment = assign.segment;
	this->waypoint = assign.waypoint;
	this->_discontinuity = false;
	this->_isWaypoint = assign._isWaypoint;
	return *this;
}

Flightplan::Flightplan() : name("--------"), origin(empty_orig_dest), destination(empty_orig_dest), _enroute(false), _discontinous(false) {}

Flightplan::Flightplan(const Flightplan& copy) : name(copy.name), origin(copy.origin), destination(copy.destination), _enroute(false), _discontinous(copy._discontinous), legs(copy.legs) {}

Flightplan& Flightplan::operator=(const Flightplan& assign)
{
	//this->elevation = assign.elevation;
	this->name = assign.name;
	this->legs = assign.legs;
	//this->path = assign.path;
	//this->segments = assign.segments;
	//this->distances = assign.distances;
	//this->restrictions = assign.restrictions;
	this->destination = assign.destination;
	this->origin = assign.origin;
	this->_enroute = assign._enroute;
	this->_discontinous = assign._discontinous;
//	this->major_nodes = assign.major_nodes;
	//this->airways = assign.airways;
	return *this;
}

void Flightplan::Wipe()
{
	name = "--------";
	/*segments.clear();
	distances.clear();
	elevation.clear();
	path.clear();
	restrictions.clear();*/
	destination = discont_nav;
	origin = discont_nav;
	_enroute = false;
	_discontinous = false;
	legs.clear();
	/*major_nodes.clear();
	airways.clear();*/
}

bool Flightplan::IsEnroute()
{
	return _enroute;
}


void Flightplan::Origin(Navaid orig)
{
	origin = orig;
}
/*
{
	if (_enroute)    //in flight/after taking runway
	{
		if (origin != orig.id)
		{
			_enroute = false;
			origin = orig.id;
			path.push_front(orig);
			segments.push_front(direct);
			distances.push_front(0);
			restrictions.push_front(orig.elev);
			elevation.push_front(orig.elev);
			restr_rel.push_front(0);

		}
	}
	else      
	{
		if (origin != orig.id)   //check if actually changing
		{
			if (path.empty())   //there is no active plan
			{
				path.push_front(orig);
				segments.push_front(direct);
				restrictions.push_front(orig.elev);
				elevation.push_front(orig.elev);
				restr_rel.push_front(0);
				distances.push_front(0);
				origin = orig.id;
			}
			else     //there is - wipe and create new
			{
				this->Wipe();
				path.push_front(orig);
				segments.push_front(direct);
				distances.push_front(0);
				restrictions.push_front(orig.elev);
				elevation.push_front(orig.elev);
				restr_rel.push_front(0);
				origin = orig.id;
			}
		}
	}
}*/

//bool Flightplan::UpdateRoutePage()
//{
//	int page, verse, callbackpos;      //index of required screen and index of the lsk and line on that screen
//	for (int i = 0; i < data.size(); ++i)
//	{
//		page = (i + _listStartLine) / _listPerPage + _listStartPage;
//		if (page >= cont.size())
//		{
//			AddPage();
//			cont[page].LMod(_lt, cont[page - 1].LReadLine(_lt));
//		}
//		verse = ((((i + _listStartLine) % _listPerPage) + 1) * 2) - line;
//		callbackpos = (((i + _listStartLine + 1) % _listPerPage) * 2) + side;
//		if (side)cont[page].RMod(verse, data[i]);
//		else cont[page].LMod(verse, data[i]);
//		if (callbackpos < 2)
//		{
//			page++;
//			if (page >= cont.size())
//			{
//				AddPage();
//				cont[page].LMod(_lt, cont[page - 1].LReadLine(_lt));
//			}
//		}
//		AddCb(callbackpos, page, functions[_listStartPage][_listStartLine * 2 + side]);
//	}
//}


void Flightplan::Destination(Navaid dest)
{
	destination = dest;
	Leg fin(false, dest);
	legs.push_back(fin);
}



std::string Flightplan::GetDestName()
{
	return destination.name;
}

std::string Flightplan::GetOrigName()
{
	return origin.name;
}
/*
{
	if (dest.id == "----")
	{
		path.pop_back();
		segments.pop_back();
		restrictions.pop_back();
		distances.push_back(0);
		elevation.pop_back();
		restr_rel.pop_back();
		destination = dest.id;
	}
	if (destination != dest.id)
	{
		if (path.empty())   //no active plan
		{
			path.push_back(dest);
			segments.push_back(direct);
			restrictions.push_back(dest.elev);
			distances.push_back(0);
			restr_rel.push_back(0);
			elevation.push_back(dest.elev);
			destination = dest.id;
		}
		else
		{
			if (path.front().id == origin && path.size() == 1)   //first node is the origin and it is the only element i.e. during initialization
			{
				path.push_back(dest);
				segments.push_back(direct);
				restrictions.push_back(dest.elev);
				distances.push_back(0);
				elevation.push_back(dest.elev);
				destination = dest.id;
				restr_rel.push_back(0);
			}
			else                                //first element is not origin or there are more elements then one i.e. there must be a destination already
			{
				path.pop_back();
				path.push_back(dest);
				segments.pop_back();
				segments.push_back(direct);
				distances.pop_back();
				distances.push_back(0);
				restrictions.pop_back();
				restrictions.push_back(dest.elev);
				elevation.pop_back();
				elevation.push_back(dest.elev);
				restr_rel.pop_back();
				restr_rel.push_back(0);
				destination = dest.id;
			}
		}
	}
}
*/

/*void Flightplan::Switch(Navaid over)
{
	int find = -1;
	for (int i = 0; i < path.size(); i++)
	{
		if (path[i] == over)
		{

		}
	}

}*/

void Flightplan::Next()
{
	if (!_enroute) _enroute = true;
	legs.pop_front();
}

bool Flightplan::IsAirwaySelected(int index)   //returns whether or not the airway has been selected for the current segment.
{
	//return airways.size() > major_nodes.size();
	index = FindWpIndex(index);
	if (legs[index].segment.name != direct.name && legs[index].segment.name != discont_awy.name) return true;
	else return false;
}

bool Flightplan::IsWaypointSelected(int index)  //returns whether the last airway segment ends in a waypoint
{
	index = FindWpIndex(index);
	return legs[index].waypoint!=discont_nav;
}

int Flightplan::FindWpIndex(int index)
{
	int wp_in = 0;
	const int len = legs.size();
	int i = -1;
	while (i != index && wp_in<len)
	{
		if (legs[wp_in].isWaypoint())i++;
		wp_in++;
	}
	return wp_in-1;
}

Leg& Flightplan::GetWp(int index)
{
	index = FindWpIndex(index);
	return legs[index];
}

AirRoute& Flightplan::RecallRoute(std::string name)
{
	if (stored_awy.empty())return invalid;
	std::vector<AirRoute>::iterator it;
	for (it = stored_awy.begin(); it != stored_awy.end(); ++it)
	{
		if ((*it).name == name) return *it;
	}
	return invalid;
}

AirRoute& Flightplan::RecallRoute(int index)
{
	index = FindWpIndex(index);
	std::string airway_name = legs[index].airway_id;
	return RecallRoute(airway_name);
}

bool Flightplan::AddWaypoint(Navaid wp, int index)     //don't call without dest and orig set
{
	index = FindWpIndex(index);
	if (index >= legs.size()) //at the end
	{
		Leg wp_leg(true, wp, direct, wp.elev, A, wp.elev); //create new leg
		legs.push_back(wp_leg);
		CheckContinuity();
		return true;
	}
	else		//existing leg
	{
		if (!IsAirwaySelected(index))	//is airway to specified
		{
			legs[index].waypoint = wp;
			CheckContinuity();
			return true;
		}
		else
		{
			if (!RecallRoute(index).CheckNavaid(wp)) return false;	//is this waypoint on that airway
			else
			{
				if (!IsWaypointSelected(index - 1)) return false;	//is previous waypoint specified	
				else												//if yes, rerun AddAirway for this leg
				{
					legs[index].waypoint = wp;
					DelAirway(index, false);
					AddAirway(RecallRoute(index), index);
					CheckContinuity();
					return true;
				}
			}
		}
	}
	//CheckContinuity();
}
/*{

	if (wp.elev == 0)
	{
		elevation.insert(--elevation.end(), -1);
		restrictions.insert(--restrictions.end(), -1);
		restr_rel.insert(--restr_rel.end(), 0);
	}
	else
	{
		elevation.insert(--elevation.end(), wp.elev);
		restrictions.insert(--restrictions.end(), wp.elev + 100);
		restr_rel.insert(--restr_rel.end(), 1);
	}
	major_nodes.push_back(wp.id);
	path.push_back(wp);
	int index = path.size()-1;
	node_indices.push_back(index);
	segments.push_back(direct);
	distances.push_back(0);
	airways.push_back("DIRECT");
	

}*/

void Flightplan::DelAirway(int index, bool forget)
{
	//int start_index;
	index = FindWpIndex(index);
	legs[index].segment = direct;
	if(forget)legs[index].airway_id = direct.name;

	for (int i = index - 1; legs[i].isWaypoint() == false; i--)
	{
		legs.erase(legs.begin() + i);
	}

	CheckContinuity();
}

void Flightplan::DelWaypoint(int index)
{
	index = FindWpIndex(index);
	if (legs[index].segment.name == discont_awy.name || legs[index].segment.name == direct.name)
	{
		legs.erase(legs.begin() + index);
	}
	else
	{
		legs[index].waypoint = discont_nav;
		DelAirway(index, false);
		if ((index + 1) < legs.size()) DelAirway(index + 1);
	}

	CheckContinuity();
}

bool Flightplan::AddAirway(AirRoute airway, int index)
{
	index = FindWpIndex(index);
	if (index >= legs.size()) //at the end
	{
		Leg aw_leg(true, discont_nav, direct, 0, A, 0, 0., airway.name);
		legs.push_back(aw_leg);
		stored_awy.push_back(airway);
		CheckContinuity();
		return true;
	}
	else
	{
		if (!airway.CheckNavaid(legs[index].waypoint)) return false;
		if (!airway.CheckNavaid(legs[index - 1].waypoint))return false;

		std::vector<Navaid> path = airway.BFS(legs[index-1].waypoint, legs[index].waypoint);
		if (path.empty())return false;
		std::vector<Airway> seg = airway.SegmentList(path);
		std::deque<Leg>::iterator it;
		legs[index].segment = seg.back();
		for (int i = path.size()-2; i >= 0; i--)
		{
			it = legs.begin() + index;
			Leg temp(false, path[i], seg[i], seg[i].base, A, 0, 0., airway.name);
			legs.insert(it, temp);
		}
		CheckContinuity();
		return true;
	}
	//else
	//{
	//	if (legs[index - 1].waypoint != discont_nav && legs[index].waypoint != discont_nav) //if we have both waypoints
	//	{
	//		std::vector<Navaid> path = airway.BFS(legs[index-1].waypoint, legs[index].waypoint);
	//		std::vector<Airway> seg = airway.SegmentList(path);
	//		std::deque<Leg>::iterator it;
	//		legs[index].segment = seg.back();
	//		for (int i = path.size()-2; i >= 0; i--)
	//		{
	//			it = legs.begin() + index;
	//			Leg temp(false, path[i], seg[i], seg[i].base, A, 0, 0., airway.name);
	//		}
	//	}
	//}
	//CheckContinuity();

}
/*{
	
	std::vector<Airway>seglist;          //first: start node -> second node, last: previous to last -> last     
	std::vector<Navaid>nodes;            //start to end

	int start, end;
	for (int i = 0; i < path.size(); i++)
	{
		if (path[i].name == major_nodes[node_indices[index - 1]]) start = i;
		if (path[i].name == major_nodes[node_indices[index]]) end = i;
	}

	std::deque<Navaid>::iterator nav1, nav2;
	std::deque<Airway>::iterator seg1, seg2;

	nav1 = path.begin() + start;
	nav2 = path.begin() + end;
	seg1 = segments.begin() + start;
	seg2 = segments.begin() + end;

	nodes = airway.BFS(path[start], path[end]);
	seglist = airway.SegmentList(nodes);			//potential bugs

	if (end - start > 1)
	{
		path.erase(next(nav1), nav2);               //delete nodes from next after start to last before end
		segments.erase(next(seg1), next(seg2));     //delete segments from the one leading to the next node after start to the one leading to the end node (1 more then nodes)
	}

	path.insert(next(nav1), next(nodes.begin()), prev(nodes.end()));          //insert after start ignoring first and last elements
	segments.insert(next(seg1), seglist.begin(), seglist.end());			//insert after path to start, all elements

	node_indices[index] = node_indices[index - 1] + nodes.size() - 2;

}*/

void Flightplan::CheckContinuity()
{
	bool discont = false;
	for (int i = 0; i < legs.size(); i++)
	{
		if (legs[i].segment.name == direct.name)
		{
			if (legs[i].waypoint == discont_nav)
			{
				discont = true;
				legs[i].SetDiscont();
			}
			else
			{
				legs[i].SetCont();
			}
		}
		if (legs[i].segment.name == discont_awy.name)
		{
			discont = true;
			legs[i].SetDiscont();
		}
		if (legs[i].segment.name != discont_awy.name && legs[i].segment.name != direct.name)
		{
			if (legs[i].waypoint == discont_nav)
			{
				discont = true;
				legs[i].SetDiscont();
			}
			else
			{
				Navaid* check = legs[i].segment.GetExit(legs[i - 1].waypoint);
				if (*check != legs[i].waypoint)
				{
					discont = true;
					legs[i].SetDiscont();
				}
				else
				{
					legs[i].SetCont();
				}
			}
		}
	}
	_discontinous = discont;
}