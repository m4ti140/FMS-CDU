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

#include "Page.h"

Page::Page(Screen init)
{
	//Screen temp = *init;

	cont.push_back(init);
	std::vector<tempf>tempfunc;
	std::vector<Page*>tempmap;
	std::vector<void*>tempdb;
	for (int i = 0; i < 12; i++)
	{
		tempfunc.push_back(invalid_entry);
		tempmap.push_back(NULL);
	//	tempdb.push_back(NULL);
	}
	functions.push_back(tempfunc);
	callmap.push_back(tempmap);
	//databases.push_back(tempdb);
	_currpage = 0;
	_modstatus = false;
	_listStartLine = 99;
	_listStartPage = 99;
	_listPerPage = 5;
}

Page::Page()
{
	Screen temp;
	cont.push_back(temp);
	std::vector<tempf>tempfunc;
	std::vector<Page*>tempmap;
	for (int i = 0; i < 12; i++)
	{
		tempfunc.push_back(invalid_entry);
		tempmap.push_back(NULL);
	}
	functions.push_back(tempfunc);
	callmap.push_back(tempmap);
	_currpage = 0;
	_modstatus = false;
	_listStartLine = 99;
	_listStartPage = 99;
	_listPerPage = 5;
}

Page::Page(const Page& copy)
{
	
	cont = copy.cont;
	functions = copy.functions;
	callmap = copy.callmap;
	_currpage = copy._currpage;
	_modstatus = copy._modstatus;
	_listStartLine = copy._listStartLine;
	_listStartPage = copy._listStartPage;
	_listPerPage = copy._listPerPage;
}

Page& Page::operator=(const Page& assign)
{
	if (this == &assign)return *this;
	else
	{
		this->cont = assign.cont;
		this->functions = assign.functions;
		this->callmap = assign.callmap;
		this->_currpage = assign._currpage;
		this->_modstatus = assign._modstatus;
		this->_listStartLine = assign._listStartLine;
		this->_listStartPage = assign._listStartPage;
		this->_listPerPage = assign._listPerPage;
		return *this;
	}
	
}

Page::~Page()
{
	functions.erase(functions.begin(), functions.end());
	callmap.erase(callmap.begin(), callmap.end());
}

void Page::AddPage(Screen init)
{
	cont.push_back(init);
	std::vector<tempf>tempfunc;
	std::vector<Page*>tempmap;
	for (int i = 0; i < 12; i++) //for every LSK set a placeholder function
	{
		tempfunc.push_back(invalid_entry);
		tempmap.push_back(NULL);
	}
	functions.push_back(tempfunc);
	callmap.push_back(tempmap);
	for (int i = 0; i < cont.size(); i++)cont[i].UpdatePageAmmount(i, cont.size());
}

void Page::AddPage()
{
	Screen temp;
	cont.push_back(temp);
	std::vector<tempf>tempfunc;
	std::vector<Page*>tempmap;
	for (int i = 0; i < 12; i++)
	{
		tempfunc.push_back(invalid_entry);
		tempmap.push_back(NULL);
	}
	functions.push_back(tempfunc);
	callmap.push_back(tempmap);
	for (int i = 0; i < cont.size(); i++)cont[i].UpdatePageAmmount(i, cont.size());
}

void Page::DelPage()
{
	cont.pop_back();
	functions.pop_back();
	callmap.pop_back();
	//databases.pop_back();
	for (int i = 0; i < cont.size(); i++)cont[i].UpdatePageAmmount(i, cont.size());
	if (_currpage >= cont.size()) _currpage = cont.size() - 1;
}

Page* Page::Callback(int select, void* input)
{
	return (*functions[_currpage][select])(select, input, this);
}

void Page::AddCb(int select, int page, Page*(*func)(int, void*, Page*))
{
	functions[page][select] = func;
}

void Page::AddRef(int select, int page, Page* target)
{
	callmap[page][select] = target;
	AddCb(select, page, call_page);
}

/*

void Page::AddField(int select, int page, std::string init, void* database)
{
	AddCb(select, page, copy_paste);
	if (database != NULL) databases[page][select] = database;
	switch(select)
	{
	
	case r_lsk_1:
	case r_lsk_2:
	case r_lsk_3:
	case r_lsk_4:
	case r_lsk_5:
	case r_lsk_6:
		cont[page].RMod(select + 1, init);
		break;
	case l_lsk_1:
	case l_lsk_2:
	case l_lsk_3:
	case l_lsk_4:
	case l_lsk_5:
	case l_lsk_6:
		cont[page].LMod(select + 2, init);
		break;

	}
}
*/

int Page::GetSubpage()
{
	return _currpage;
}

//void Page::Execute()
//{
//	execf();
//}
//
//void Page::SetExec(void(*nexecf)())
//{
//	execf = nexecf;
//}
void Page::SetPage(int subpage)
{
	if(subpage>=0&&subpage<cont.size())
	_currpage = subpage;
}

void Page::SetLastPage()
{
	_currpage = cont.size() - 1;
}

int Page::ListIndex(int select)
{
	return (select - _listStartLine) / 2 + _listPerPage * (_currpage - _listStartPage);
}

int Page::ListLSK(int index, int side)
{
#ifdef _DEBUG
	std::ofstream debug;
	debug.open("FMSdebug.txt", std::ios_base::app);
	debug << "Page::ListLSK: index = " << index << ", side = " << side << std::endl;
#endif
	return ((index + _listStartLine) % _listPerPage) * 2 + side;
}

void Page::MarkList(int select, int page, int perpage)
{
	_listStartLine = select;
	_listStartPage = page;
	_listPerPage = perpage;
}

void Page::RefreshList(std::deque<std::string>data, int side, int line)
{
	int page, verse, callbackpos;      //index of required screen and index of the lsk and line on that screen
	for (int i=0; i < data.size(); ++i)
	{
		page = (i + _listStartLine) / _listPerPage + _listStartPage;
		if (page >= cont.size())
		{
			AddPage();
			cont[page].LMod(_lt, cont[page - 1].LReadLine(_lt));
		}
		verse = ((((i + _listStartLine) % _listPerPage) + 1) * 2)-line;
		callbackpos = (((i + _listStartLine + 1) % _listPerPage) * 2) + side;
		if (side)cont[page].RMod(verse, data[i]);
		else cont[page].LMod(verse, data[i]);
		if (callbackpos < 2)
		{
			page++;
			if (page >= cont.size())
			{
				AddPage();
				cont[page].LMod(_lt, cont[page - 1].LReadLine(_lt));
			}
		}
		AddCb(callbackpos, page, functions[_listStartPage][_listStartLine * 2 + side]);
	}
}

void LegsPage::RefreshList(const std::deque<Leg>& data)
{
	int page, verse, callbackpos;      //index of required screen and index of the lsk and line on that screen
	for (int i = 0; i < data.size(); ++i)
	{
		page = (i + _listStartLine) / _listPerPage + _listStartPage;
		if (page >= cont.size())
		{
			AddPage();
			cont[page].LMod(_lt, cont[page - 1].LReadLine(_lt));
		}
		verse = ((((i + _listStartLine) % _listPerPage) + 1) * 2);
		callbackpos = (((i + _listStartLine + 1) % _listPerPage) * 2);
		//cont[page].RMod(verse, data[i]);
		cont[page].LMod(verse, data[i].waypoint.id);	//update id

		std::ostringstream buff;

		buff << data[i].elevation<< "/" << data[i].restriction;  //update restrictions

		cont[page].RMod(verse, buff.str());   

		std::ostringstream buff2;

		buff2 << data[i].heading;        //update heading

		cont[page].LMod(verse - 1, buff2.str());

		std::ostringstream buff3;

		buff3 << data[i].distance;		//update distance

		cont[page].RMod(verse - 1, buff3.str());
		if (callbackpos < 2)
		{
			page++;
			if (page >= cont.size())
			{
				AddPage();
				cont[page].LMod(_lt, cont[page - 1].LReadLine(_lt));
			}
		}
		AddCb(callbackpos, page, functions[_listStartPage][_listStartLine * 2]);
	}
}

void RoutePage::RefreshList(const std::deque<Leg>& data)
{
#ifdef _DEBUG
	std::ofstream debug;
	debug.open("FMSdebug.txt", std::ios_base::app);
#endif
	int page, verse, callbackpos;      //index of required screen and index of the lsk and line on that screen
	int wp_index = 0;
	for (int i = 0; i < data.size(); ++i)
	{
		page = (wp_index + _listStartLine) / _listPerPage + _listStartPage;
#ifdef _DEBUG
		debug << "page=" << page << std::endl;
#endif
		if (page >= cont.size())
		{
			AddPage();
			cont[page].LMod(_lt, cont[page - 1].LReadLine(_lt));
			cont[page].Mod(_s1, cont[page - 1].ReadLine(_s1));
		}
		verse = ((((wp_index + _listStartLine) % _listPerPage) + 1) * 2);
#ifdef _DEBUG
		debug << "verse=" << verse << std::endl;
#endif
		callbackpos = ListLSK(wp_index) + 2;
		callbackpos %= 12;
#ifdef _DEBUG
		debug << "callbackpos=" << callbackpos << std::endl << "i=" << i<<std::endl;
#endif
		//cont[page].RMod(verse, data[i]);
		if (data[i].isWaypoint())
		{
			cont[page].LMod(verse, data[i].airway_id);	//update airway

			cont[page].RMod(verse, data[i].waypoint.id); //update waypoint

			if (callbackpos < 2)
			{
				page++;
				if (page >= cont.size())
				{
					AddPage();
					cont[page].LMod(_lt, cont[page - 1].LReadLine(_lt));
				}
			}
			AddCb(callbackpos, page, functions[1][0]);
			AddCb(callbackpos+1, page, functions[1][1]);

			wp_index++;
#ifdef _DEBUG
			debug << "wp_index=" << wp_index << std::endl;
#endif
		}
	}
	int endpage = wp_index / _listPerPage + _listStartPage + 1;
	if (cont.size() > endpage) cont.erase(cont.begin() + endpage, cont.end());
	wp_index %= _listPerPage;
	for (int i = wp_index + 1; i < 6; i++)
	{
		AddCb(2 * i, endpage - 1, invalid_entry);
	}
	
	
}

//void Page::RefreshList(std::deque<std::string>data, int side, int line)
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



void Page::NextPage()
{
	if(_currpage<cont.size()-1)_currpage++;
}

void Page::PrevPage()
{
	if (_currpage > 0)_currpage--;
}

Page* Page::invalid_entry(int select, void* input, Page* output)
{
	static_cast<Scratchpad*>(input)->Error("INVALID ENTRY");
	return NULL;
}

Page* Page::call_page(int select, void* input, Page* output)
{
	int subpage = output->GetSubpage();
	return output->callmap[subpage][select];
}

Page* Page::copy_paste(int select, void* input, Page* output)
{
	Scratchpad* edit;
	int target, side, page;
	side = select % 2; //check if it's the left or right
	if (side == 0)   //left side
	{
		target = select + 2;
		page = output->GetSubpage();
		edit = static_cast<Scratchpad*>(input);
		if (edit->isDel())
		{
			output->cont[page].LMod(target, "----");
			edit->Deleted();
		}
		else if (edit->cont == "") edit->Add(output->cont[page].LReadLine(target)); //copy
		else {
			output->cont[page].LMod(target, edit->cont);   //enter
			edit->Clear_All();
		}
	}
	if (side == 1)  //right side
	{
		target = select + 1;
		page = output->GetSubpage();
		edit = static_cast<Scratchpad*>(input);
		if (edit->isDel())
		{
			output->cont[page].RMod(target, "----");
			edit->Deleted();
		}
		else if (edit->cont == "") edit->Add(output->cont[page].RReadLine(target));
		else {
			output->cont[page].RMod(target, edit->cont);
			edit->Clear_All();
		}
	}
	return output;
}

