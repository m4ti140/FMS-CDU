#pragma once
#include <string>
#include "Screen.h"
#include "scratchpad.h"
#include "Route.h"
#include <vector>
#include <deque>



class Page
{

protected:
	int _listStartLine;
	int _listStartPage;
	int _listPerPage;
public:
	Page(Screen init);
	Page();
	Page(const Page& copy);
	Page& operator=(const Page& assign);
	~Page();

	void AddPage(Screen init);
	void AddPage();
	void DelPage();
	Page* Callback(int select, void* input);
	void AddCb(int select, int page, Page*(*func)(int, void*, Page*));
	void AddRef(int select, int page, Page* target);
	//void AddField(int select, int page, std::string init, void* database=NULL);
	int GetSubpage();
	//void Execute();
	//void SetExec(void(*nexecf)());
	int ListIndex(int select); //for ordered lists: return index of item we select
	int ListLSK(int index, int side=0); //for ordered lists: return LSK code for the given index, left side = 0, right side = 1 
	void MarkList(int select, int page, int perpage=6); //mark beginning of a list
	void RefreshList(std::deque<std::string>data, int side=0, int line=0);     //0 - left, 1 - right; 1-subline, 0-line
	
	void NextPage();
	void PrevPage();

	enum
	{
		_lt = 0,
		_s1 = 1,
		_l1 = 2,
		_s2 = 3,
		_l2 = 4,
		_s3 = 5,
		_l3 = 6,
		_s4 = 7,
		_l4 = 8,
		_s5 = 9,
		_l5 = 10,
		_s6 = 11,
		_l6 = 12
	};
	enum
	{
		l_lsk_1 = 0,
		r_lsk_1 = 1,
		l_lsk_2 = 2,
		r_lsk_2 = 3,
		l_lsk_3 = 4,
		r_lsk_3 = 5,
		l_lsk_4 = 6,
		r_lsk_4 = 7,
		l_lsk_5 = 8,
		r_lsk_5 = 9,
		l_lsk_6 = 10,
		r_lsk_6 = 11
	};

protected:
	typedef Page*(*tempf)(int select, void* input, Page* output);

public:
	std::vector<Screen> cont;
	std::vector<std::vector<tempf>> functions;
	std::vector<std::vector<Page*>> callmap;
	//std::vector<std::vector<void*>> databases;
	//void(*execf)();


	
	static Page* invalid_entry(int select, void* input, Page* output);
	static Page* call_page(int select, void* input, Page* output);
	static Page* copy_paste(int select, void* input, Page* output);
protected:

	int _currpage;
	bool _modstatus;
	
	
};

class LegsPage : public Page
{
public:
	void RefreshList(const std::deque<Leg>& data);  
	using Page::Page;
};

class RoutePage : public Page
{
public:
	void RefreshList(const std::deque<Leg>& data);
	using Page::Page;
};