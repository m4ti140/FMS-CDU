#pragma once
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

Airway::Airway() : Route(), dir('N'), base(0), top(600), cls(1) {}

Airway::Airway(Navaid* entry, Navaid* exit)
{
	name = "";
	path.push_back(entry);
	path.push_back(exit);
	dir = 'N';
	top = 600;
	base = 0;
	cls = 1;
	entryid = entry->id;
	exitid = exit->id;
	entryreg = entry->reg;
	exitreg = exit->reg;
	entrytype = entry->type;
	exittype = exit->type;
}

Airway::Airway(const Airway& copy) : Route(copy), dir(copy.dir), base(copy.base), top(copy.top), cls(copy.cls), awy(copy.awy), entryid(copy.entryid), exitid(copy.exitid), entryreg(copy.entryreg), exitreg(copy.exitreg), entrytype(copy.entrytype), exittype(copy.exittype) {}

Airway& Airway::operator=(const Airway& assign)
{
	Route::operator=(assign);
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

void Airway::ReadFromString(std::string input)
{
	// 070A CY 11  080A CY 11 N 2 280 600 NCAA
	int type;

	size_t pos=0;
	size_t pos2 = 0;
	std::string edit = input;
	std::vector<Navaid>::iterator it;
	std::stringstream convert;
	Navaid* navpt;

	while (edit[pos] == ' ')        //read entry id
	{
		pos++;
	}
	pos2 = edit.find(' ', pos);
	entryid = edit.substr(pos, pos2 - pos);
	pos = pos2;

	while (edit[pos] == ' ')        //read entry region
	{
		pos++;
	}
	pos2 = edit.find(' ', pos);
	entryreg = edit.substr(pos, pos2 - pos);
	pos = pos2;

	while (edit[pos] == ' ')        //read entry type
	{
		pos++;
	}
	pos2 = edit.find(' ', pos);
	convert << edit.substr(pos, pos2 - pos);
	pos = pos2;
	convert >> type;
	if(type == 11)
	{
		it = std::find_if(std::begin(fixes_db), std::end(fixes_db), [&](Navaid const& n) {return n.id == entryid; });
		if (it != fixes_db.end()) {
			while (it->reg != entryreg && it != fixes_db.end()) it = std::find_if(std::next(it), std::end(fixes_db), [&](Navaid const& n) {return n.id == entryid; });
		}
		if (it != fixes_db.end()) {
			navpt = &(*it);
			path.push_back(navpt);
		}
	}
	else
	{
		it = std::find_if(std::begin(nodes_db), std::end(nodes_db), [&](Navaid const& n) {return n.id == entryid; });
		if (it != nodes_db.end()) {
			while (it->reg != entryreg && it != nodes_db.end()) it = std::find_if(std::next(it), std::end(nodes_db), [&](Navaid const& n) {return n.id == entryid; });
		}
		if (it != nodes_db.end()) {
			navpt = &(*it);
			path.push_back(navpt);
		}
	}


	while (edit[pos] == ' ')        //read exit id
	{
		pos++;
	}
	pos2 = edit.find(' ', pos);
	exitid = edit.substr(pos, pos2 - pos);
	pos = pos2;

	while (edit[pos] == ' ')        //read exit region
	{
		pos++;
	}
	pos2 = edit.find(' ', pos);
	exitreg = edit.substr(pos, pos2 - pos);
	pos = pos2;

	while (edit[pos] == ' ')        //read exit type
	{
		pos++;
	}
	pos2 = edit.find(' ', pos);
	convert << edit.substr(pos, pos2 - pos);
	pos = pos2;
	convert >> type;
	if (type == 11)
	{
		it = std::find_if(std::begin(fixes_db), std::end(fixes_db), [&](Navaid const& n) {return n.id == exitid; });
		if (it != fixes_db.end()) {
			while (it->reg != exitreg && it != fixes_db.end()) it = std::find_if(std::next(it), std::end(fixes_db), [&](Navaid const& n) {return n.id == exitid; });
		}
		if (it != fixes_db.end()) {
			navpt = &(*it);
			path.push_back(navpt);
		}
	}
	else
	{
		it = std::find_if(std::begin(nodes_db), std::end(nodes_db), [&](Navaid const& n) {return n.id == exitid; });
		if (it != nodes_db.end()) {
			while (it->reg != exitreg && it != nodes_db.end()) it = std::find_if(std::next(it), std::end(nodes_db), [&](Navaid const& n) {return n.id == exitid; });
		}
		if (it != nodes_db.end()) {
			navpt = &(*it);
			path.push_back(navpt);
		}
	}

	while (edit[pos] == ' ')        //read direction
	{
		pos++;
	}
	pos2 = edit.find(' ', pos);
	dir = edit[pos];
	pos = pos2;

	while (edit[pos] == ' ')        //read class
	{
		pos++;
	}
	pos2 = edit.find(' ', pos);
	convert << edit.substr(pos, pos2 - pos);
	pos = pos2;
	convert >> cls;

	while (edit[pos] == ' ')        //read base
	{
		pos++;
	}
	pos2 = edit.find(' ', pos);
	convert << edit.substr(pos, pos2 - pos);
	pos = pos2;
	convert >> base;

	while (edit[pos] == ' ')        //read top
	{
		pos++;
	}
	pos2 = edit.find(' ', pos);
	convert << edit.substr(pos, pos2 - pos);
	pos = pos2;
	convert >> top;

	while(pos<edit.length()-1)
	{
		while (edit[pos] == ' ')        //read awy
		{
			pos++;
		}
		pos2 = edit.find('-', pos);
		if (pos2 == std::string::npos)
		{
			awy.push_back(edit.substr(pos, edit.length() - pos));
			return;
		}
		else
		{
			awy.push_back(edit.substr(pos, pos2 - pos));
		}
	}
}

std::istream& operator>>(std::istream& is, Airway& data)
{
	// 070A CY 11  080A CY 11 N 2 280 600 NCAA

	std::string name;
	int type;
	std::string region;
	std::vector<Navaid>::iterator it;
	Navaid* navpt;
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

	is >> data.entryreg >> data.entrytype >> data.exitid >> data.entryreg >> data.exittype;

	is >> data.dir >> data.cls >> data.base >> data.top;

	std::stringbuf airways;
	is.get(airways, '\n');

	size_t first = 0;
	size_t last = 0;
	if (airways.str().find('-', first) == std::string::npos) data.awy.push_back(airways.str());
	while ((last = airways.str().find('-', first)) != std::string::npos)
	{
		data.awy.push_back(airways.str().substr(first, last - 1));
		first = last + 1;
	}

	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return is;


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

		for (iFront = 0; iFront < vertices.size() && vertices[iFront] != *route[i].path.front(); iFront++);				//check if initial waypoint, is added save index if it is

		if (iFront == vertices.size())
		{
			vertices.push_back(*route[i].path.front());  //add it if not
			adjecents.push_back(temp);
		}

		for (iBack = 0; iBack < vertices.size() && vertices[iBack] != *route[i].path.back(); iBack++);					//same for final

		if (iBack == vertices.size())
		{
			vertices.push_back(*route[i].path.back());
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
	result.push_back(vertices[iStart]);

	while (current != iEnd)
	{
		result.push_back(vertices[predecessor[current]]);
		current = predecessor[current];
	}

	return result;

}
	
std::vector<Airway> AirRoute::SegmentList(std::vector<Navaid> traversal)
{
	std::vector<Airway> seglist;
	Airway cur;

	for (std::vector<Navaid>::iterator wpit=next(traversal.begin()); wpit != traversal.end(); ++wpit)
	{
		for (std::vector<Airway>::iterator segit = route.begin(); segit != route.end(); ++segit)
		{
			cur = *segit;
			if (cur.dir == 'N' || cur.dir == 'F')
				if (*cur.path.front() == *prev(wpit) && *cur.path.back() == *wpit) seglist.push_back(cur);
			if (cur.dir == 'N' || cur.dir == 'B')
				if (*cur.path.front() == *wpit && *cur.path.back() == *prev(wpit)) seglist.push_back(cur);
		}
	}

	return seglist;
}

Flightplan::Flightplan() : name("--------"), origin("----"), destination("----"), _enroute(false), _discontinous(false), direct([&] {Airway dir; dir.name = "DIRECT"; return dir; }()), discont_nav([&] {Navaid disc; disc.name = "□□□□□"; return disc; }()), discont_awy([&] {Airway disc; disc.name = "□□□□□"; return disc; }()) {}

Flightplan::Flightplan(const Flightplan& copy) : name(copy.name), origin(copy.origin), destination(copy.destination), path(copy.path), restrictions(copy.restrictions), elevation(copy.elevation), _enroute(false), _discontinous(copy._discontinous), distances(copy.distances) {}

Flightplan& Flightplan::operator=(const Flightplan& assign)
{
	this->elevation = assign.elevation;
	this->name = assign.name;
	this->path = assign.path;
	this->segments = assign.segments;
	this->distances = assign.distances;
	this->restrictions = assign.restrictions;
	this->destination = assign.destination;
	this->origin = assign.origin;
	this->_enroute = assign._enroute;
	this->_discontinous = assign._discontinous;
	this->major_nodes = assign.major_nodes;
	this->airways = assign.airways;
	return *this;
}

void Flightplan::Wipe()
{
	name = "--------";
	segments.clear();
	distances.clear();
	elevation.clear();
	path.clear();
	restrictions.clear();
	destination = "----";
	origin = "----";
	_enroute = false;
	_discontinous = false;
	major_nodes.clear();
	airways.clear();
}

bool Flightplan::IsEnroute()
{
	return _enroute;
}

void Flightplan::Origin(Navaid orig)
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
}

void Flightplan::Destination(Navaid dest)
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
	if(path.size()>1)path.pop_front();
	if(segments.size()>1)segments.pop_front();
	if(restrictions.size()>1)restrictions.pop_front();
	if(restr_rel.size()>1)restr_rel.pop_front();
	if(elevation.size()>1)elevation.pop_front();
	if(distances.size()>1)distances.pop_front();
}

bool Flightplan::IsAirwaySelected()   //returns whether or not the airway has been selected for the current segment.
{
	return airways.size() > major_nodes.size();
}

bool Flightplan::IsWaypointSelected()  //returns whether the last airway segment ends in a waypoint
{
	return airways.size() <= major_nodes.size();   //path ends in a defined waypoint
}

void Flightplan::AddWaypoint(Navaid wp)     //don't call without dest and orig set
{

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
	

}

void Flightplan::AddAirway(AirRoute airway, int index)
{
	
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

}