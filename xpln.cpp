#define _xpln_

//#include <cstdio>
#include <cstring>
#include <sstream>         //tbd
#include <string>
#include <fstream>
#include <cstdio>
//#include <iostream>

#include "XPLMDisplay.h"    
#include "XPLMGraphics.h"
#include "XPLMNavigation.h"
#include "XPLMMenus.h"
#include "XPWidgets.h"
#include "XPWidgetUtils.h"
#include "XPStandardWidgets.h"
#include "XPLMPlugin.h"
#include "XPLMUtilities.h"
#include "Pages.h"
//#include "functionlib.h"

#include "callbacks.h"      //callbacks here
//#include "widgetids.h"
//#include "datarefs.h"      //datarefs too

//XPLMWindowID wind;
//int lmb;

XPLMMenuID menuid;
int item;

//temp
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
	_l6 = 12,
};

void FMScreate(int x1, int y1)
{

	int x2 = x1 + 400;
	int y2 = y1 - 700;

	FMSwindow = XPCreateWidget(x1, y1, x2, y2, 1, "ExtFMS", 1, NULL, xpWidgetClass_MainWindow);
	XPSetWidgetProperty(FMSwindow, xpProperty_MainWindowHasCloseBoxes, 1);
	
	//screen substitute

	FMSscreen = XPCreateCustomWidget(x1 + 50, y1 - 30, x2 - 50, y1 - 275, 1, "", 0, FMSwindow, call::FMSdraw);

	//(x1 + 50, y1 - 30, x2 - 50, y1 - 275, 1, call::FMSdraw, NULL, NULL, NULL);

	//FMSscreen = XPCreateWidget(x1 + 50, y1 - 30, x2 - 50, y1 - 275, 1, NULL, 0, FMSwindow, xpWidgetClass_SubWindow);
	//XPSetWidgetProperty(FMSscreen, xpProperty_SubWindowType, xpSubWindowStyle_Screen);

	//Keys

	k::INIT_REF = XPCreateWidget(x1 + 50, y1 - 290, x1 + 100, y1 - 320, 1, "IN/RF", 0, FMSwindow, xpWidgetClass_Button);
	//XPSetWidgetProperty(k::INIT_REF, xpProperty_ButtonType, xpRadioButton);
	//XPSetWidgetProperty(k::INIT_REF, xpProperty_ButtonBehavior, xpButtonBehaviorPushButton);
	k::RTE = XPCreateWidget(x1 + 100, y1 - 290, x1 + 150, y1 - 320, 1, "RTE", 0, FMSwindow, xpWidgetClass_Button);
	k::CLB = XPCreateWidget(x1 + 150, y1 - 290, x1 + 200, y1 - 320, 1, "CLB", 0, FMSwindow, xpWidgetClass_Button);
	k::CRZ = XPCreateWidget(x1 + 200, y1 - 290, x1 +250, y1 - 320, 1, "CRZ", 0, FMSwindow, xpWidgetClass_Button);
	k::DES = XPCreateWidget(x1 + 250, y1 - 290, x1 +300, y1 - 320, 1, "DES", 0, FMSwindow, xpWidgetClass_Button);
	k::MENU = XPCreateWidget(x1 + 50, y1 - 320, x1 + 100, y1 - 350, 1, "MENU", 0, FMSwindow, xpWidgetClass_Button);
	k::LEGS = XPCreateWidget(x1 + 100, y1 - 320, x1 + 150, y1 - 350, 1, "LEGS", 0, FMSwindow, xpWidgetClass_Button);
	k::DEP_ARR = XPCreateWidget(x1 + 150, y1 - 320, x1 +200, y1 - 350, 1, "DP/AR", 0, FMSwindow, xpWidgetClass_Button);
	k::HOLD = XPCreateWidget(x1 + 200, y1 - 320, x1 + 250, y1 - 350, 1, "HOLD", 0, FMSwindow, xpWidgetClass_Button);
	k::PROG = XPCreateWidget(x1 + 250, y1 - 320, x1 + 300, y1 - 350, 1, "PROG", 0, FMSwindow, xpWidgetClass_Button);
	k::EXEC = XPCreateWidget(x1 + 320, y1 - 320, x1 + 370, y1 - 350, 1, "EXEC", 0, FMSwindow, xpWidgetClass_Button);
	k::N1_LIMIT = XPCreateWidget(x1 + 50, y1 - 350, x1 + 100, y1 - 380, 1, "N1LIM", 0, FMSwindow, xpWidgetClass_Button);
	k::PREV_PAGE = XPCreateWidget(x1 + 50, y1 - 380, x1 + 100, y1 - 410, 1, "PREV", 0, FMSwindow, xpWidgetClass_Button);
	k::NEXT_PAGE = XPCreateWidget(x1 + 100, y1 - 380, x1 + 150, y1 - 410, 1, "NEXT", 0, FMSwindow, xpWidgetClass_Button);
	k::FIX = XPCreateWidget(x1 + 100, y1 - 350, x1 + 150, y1 - 380, 1, "FIX", 0, FMSwindow, xpWidgetClass_Button);


	//alfa
	k::A = XPCreateWidget(x1 + 170, y1 - 370, x1 + 195, y1 - 385, 1, "A", 0, FMSwindow, xpWidgetClass_Button);
	k::B = XPCreateWidget(x1 + 210, y1 - 370, x1 + 235, y1 - 385, 1, "B", 0, FMSwindow, xpWidgetClass_Button);
	k::C = XPCreateWidget(x1 + 250, y1 - 370, x1 + 275, y1 - 385, 1, "C", 0, FMSwindow, xpWidgetClass_Button);
	k::D = XPCreateWidget(x1 + 290, y1 - 370, x1 + 315, y1 - 385, 1, "D", 0, FMSwindow, xpWidgetClass_Button);
	k::E = XPCreateWidget(x1 + 330, y1 - 370, x1 + 355, y1 - 385, 1, "E", 0, FMSwindow, xpWidgetClass_Button);
	k::F = XPCreateWidget(x1 + 170, y1 - 410, x1 + 195, y1 - 425, 1, "F", 0, FMSwindow, xpWidgetClass_Button);
	k::G = XPCreateWidget(x1 + 210, y1 - 410, x1 + 235, y1 - 425, 1, "G", 0, FMSwindow, xpWidgetClass_Button);
	k::H = XPCreateWidget(x1 + 250, y1 - 410, x1 + 275, y1 - 425, 1, "H", 0, FMSwindow, xpWidgetClass_Button);
	k::I = XPCreateWidget(x1 + 290, y1 - 410, x1 + 315, y1 - 425, 1, "I", 0, FMSwindow, xpWidgetClass_Button);
	k::J = XPCreateWidget(x1 + 330, y1 - 410, x1 + 355, y1 - 425, 1, "J", 0, FMSwindow, xpWidgetClass_Button);
	k::K = XPCreateWidget(x1 + 170, y1 - 450, x1 + 195, y1 - 465, 1, "K", 0, FMSwindow, xpWidgetClass_Button);
	k::L = XPCreateWidget(x1 + 210, y1 - 450, x1 + 235, y1 - 465, 1, "L", 0, FMSwindow, xpWidgetClass_Button);
	k::M = XPCreateWidget(x1 + 250, y1 - 450, x1 + 275, y1 - 465, 1, "M", 0, FMSwindow, xpWidgetClass_Button);
	k::N = XPCreateWidget(x1 + 290, y1 - 450, x1 + 315, y1 - 465, 1, "N", 0, FMSwindow, xpWidgetClass_Button);
	k::O = XPCreateWidget(x1 + 330, y1 - 450, x1 + 355, y1 - 465, 1, "O", 0, FMSwindow, xpWidgetClass_Button);
	k::P = XPCreateWidget(x1 + 170, y1 - 490, x1 + 195, y1 - 505, 1, "P", 0, FMSwindow, xpWidgetClass_Button);
	k::Q = XPCreateWidget(x1 + 210, y1 - 490, x1 + 235, y1 - 505, 1, "Q", 0, FMSwindow, xpWidgetClass_Button);
	k::R = XPCreateWidget(x1 + 250, y1 - 490, x1 + 275, y1 - 505, 1, "R", 0, FMSwindow, xpWidgetClass_Button);
	k::S = XPCreateWidget(x1 + 290, y1 - 490, x1 + 315, y1 - 505, 1, "S", 0, FMSwindow, xpWidgetClass_Button);
	k::T = XPCreateWidget(x1 + 330, y1 - 490, x1 + 355, y1 - 505, 1, "T", 0, FMSwindow, xpWidgetClass_Button);
	k::U = XPCreateWidget(x1 + 170, y1 - 530, x1 + 195, y1 - 545, 1, "U", 0, FMSwindow, xpWidgetClass_Button);
	k::V = XPCreateWidget(x1 + 210, y1 - 530, x1 + 235, y1 - 545, 1, "V", 0, FMSwindow, xpWidgetClass_Button);
	k::W = XPCreateWidget(x1 + 250, y1 - 530, x1 + 275, y1 - 545, 1, "W", 0, FMSwindow, xpWidgetClass_Button);
	k::X = XPCreateWidget(x1 + 290, y1 - 530, x1 + 315, y1 - 545, 1, "X", 0, FMSwindow, xpWidgetClass_Button);
	k::Y = XPCreateWidget(x1 + 330, y1 - 530, x1 + 355, y1 - 545, 1, "Y", 0, FMSwindow, xpWidgetClass_Button);
	k::Z = XPCreateWidget(x1 + 170, y1 - 570, x1 + 195, y1 - 585, 1, "Z", 0, FMSwindow, xpWidgetClass_Button);
	k::SP = XPCreateWidget(x1 + 210, y1 - 570, x1 + 235, y1 - 585, 1, "SP", 0, FMSwindow, xpWidgetClass_Button);
	k::DEL = XPCreateWidget(x1 + 250, y1 - 570, x1 + 275, y1 - 585, 1, "DEL", 0, FMSwindow, xpWidgetClass_Button);
	k::SLASH = XPCreateWidget(x1 + 290, y1 - 570, x1 + 315, y1 - 585, 1, "/", 0, FMSwindow, xpWidgetClass_Button);
	k::CLR = XPCreateWidget(x1 + 330, y1 - 570, x1 + 355, y1 - 585, 1, "CLR", 0, FMSwindow, xpWidgetClass_Button);

	//num
	k::N1 = XPCreateWidget(x1 + 50, y1 - 450, x1 + 70, y1 - 465, 1, "1", 0, FMSwindow, xpWidgetClass_Button);
	k::N2 = XPCreateWidget(x1 + 80, y1 - 450, x1 + 100, y1 - 465, 1, "2", 0, FMSwindow, xpWidgetClass_Button);
	k::N3 = XPCreateWidget(x1 + 110, y1 - 450, x1 + 130, y1 - 465, 1, "3", 0, FMSwindow, xpWidgetClass_Button);
	k::N4 = XPCreateWidget(x1 + 50, y1 - 490, x1 + 70, y1 - 505, 1, "4", 0, FMSwindow, xpWidgetClass_Button);
	k::N5 = XPCreateWidget(x1 + 80, y1 - 490, x1 + 100, y1 - 505, 1, "5", 0, FMSwindow, xpWidgetClass_Button);
	k::N6 = XPCreateWidget(x1 + 110, y1 - 490, x1 + 130, y1 - 505, 1, "6", 0, FMSwindow, xpWidgetClass_Button);
	k::N7 = XPCreateWidget(x1 + 50, y1 - 530, x1 + 70, y1 - 545, 1, "7", 0, FMSwindow, xpWidgetClass_Button);
	k::N8 = XPCreateWidget(x1 + 80, y1 - 530, x1 + 100, y1 - 545, 1, "8", 0, FMSwindow, xpWidgetClass_Button);
	k::N9 = XPCreateWidget(x1 + 110, y1 - 530, x1 + 130, y1 - 545, 1, "9", 0, FMSwindow, xpWidgetClass_Button);
	k::NDOT = XPCreateWidget(x1 + 50, y1 - 570, x1 + 70, y1 - 585, 1, ".", 0, FMSwindow, xpWidgetClass_Button);
	k::N0 = XPCreateWidget(x1 + 80, y1 - 570, x1 + 100, y1 - 585, 1, "0", 0, FMSwindow, xpWidgetClass_Button);
	k::NPM = XPCreateWidget(x1 + 110, y1 - 570, x1 + 130, y1 - 585, 1, "+/-", 0, FMSwindow, xpWidgetClass_Button);
	
	//lsk

	k::L_LSK1 = XPCreateWidget(x1 + 5, y1 - 68, x1 + 45, y1 - 85, 1, "---", 0, FMSwindow, xpWidgetClass_Button);
	k::L_LSK2 = XPCreateWidget(x1 + 5, y1 - 102, x1 + 45, y1 - 119, 1, "---", 0, FMSwindow, xpWidgetClass_Button);
	k::L_LSK3 = XPCreateWidget(x1 + 5, y1 - 136, x1 + 45, y1 - 153, 1, "---", 0, FMSwindow, xpWidgetClass_Button);
	k::L_LSK4 = XPCreateWidget(x1 + 5, y1 - 170, x1 + 45, y1 - 187, 1, "---", 0, FMSwindow, xpWidgetClass_Button);
	k::L_LSK5 = XPCreateWidget(x1 + 5, y1 - 204, x1 + 45, y1 - 221, 1, "---", 0, FMSwindow, xpWidgetClass_Button);
	k::L_LSK6 = XPCreateWidget(x1 + 5, y1 - 238, x1 + 45, y1 - 255, 1, "---", 0, FMSwindow, xpWidgetClass_Button);
	k::R_LSK1 = XPCreateWidget(x2 - 45, y1 - 68, x2 - 5, y1 - 85, 1, "---", 0, FMSwindow, xpWidgetClass_Button);
	k::R_LSK2 = XPCreateWidget(x2 - 45, y1 - 102, x2 - 5, y1 - 119, 1, "---", 0, FMSwindow, xpWidgetClass_Button);
	k::R_LSK3 = XPCreateWidget(x2 - 45, y1 - 136, x2 - 5, y1 - 153, 1, "---", 0, FMSwindow, xpWidgetClass_Button);
	k::R_LSK4 = XPCreateWidget(x2 - 45, y1 - 170, x2 - 5, y1 - 187, 1, "---", 0, FMSwindow, xpWidgetClass_Button);
	k::R_LSK5 = XPCreateWidget(x2 - 45, y1 - 204, x2 - 5, y1 - 221, 1, "---", 0, FMSwindow, xpWidgetClass_Button);
	k::R_LSK6 = XPCreateWidget(x2 - 45, y1 - 238, x2 - 5, y1 - 255, 1, "---", 0, FMSwindow, xpWidgetClass_Button);

	//additional
	k::LNAV = XPCreateWidget(x1 + 170, y1 - 610, x1 + 195, y1 - 625, 1, "L-Nav", 0, FMSwindow, xpWidgetClass_Button);
	XPSetWidgetProperty(k::LNAV, xpProperty_ButtonType, xpRadioButton);
	XPSetWidgetProperty(k::LNAV, xpProperty_ButtonBehavior, xpButtonBehaviorCheckBox);
	XPSetWidgetProperty(k::LNAV, xpProperty_ButtonState, 0);
	/*
	//screen, def format
	
	s::lt = XPCreateWidget(x1 + 55, y1 - 34, x2 - 55, y1 - 51, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::s1 = XPCreateWidget(x1 + 55, y1 - 58, x2 - 55, y1 - 68, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::l1 = XPCreateWidget(x1 + 55, y1 - 68, x2 - 55, y1 - 85, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::s2 = XPCreateWidget(x1 + 55, y1 - 92, x2 - 55, y1 - 102, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::l2 = XPCreateWidget(x1 + 55, y1 - 102, x2 - 55, y1 - 119, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::s3 = XPCreateWidget(x1 + 55, y1 - 126, x2 - 55, y1 - 136, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::l3 = XPCreateWidget(x1 + 55, y1 - 136, x2 - 55, y1 - 153, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::s4 = XPCreateWidget(x1 + 55, y1 - 160, x2 - 55, y1 - 170, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::l4 = XPCreateWidget(x1 + 55, y1 - 170, x2 - 55, y1 - 187, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::s5 = XPCreateWidget(x1 + 55, y1 - 194, x2 - 55, y1 - 204, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::l5 = XPCreateWidget(x1 + 55, y1 - 204, x2 - 55, y1 - 221, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::s6 = XPCreateWidget(x1 + 55, y1 - 228, x2 - 55, y1 - 238, 1, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -", 0, FMSwindow, xpWidgetClass_Caption);
	s::l6 = XPCreateWidget(x1 + 55, y1 - 238, x2 - 55, y1 - 255, 1, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, FMSwindow, xpWidgetClass_Caption);
	s::sp = XPCreateWidget(x1 + 55, y1 - 255, x2 - 55, y1 - 272, 1, "[]", 0, FMSwindow, xpWidgetClass_Caption);

	XPSetWidgetProperty(s::lt, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::s1, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::l1, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::s2, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::l2, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::s3, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::l3, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::s4, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::l4, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::s5, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::l5, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::s6, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::l6, xpProperty_CaptionLit, 1);
	XPSetWidgetProperty(s::sp, xpProperty_CaptionLit, 1);*/
	
	XPAddWidgetCallback(FMSwindow, call::FMShand);
	
}

void FMSmenu(void * mRef, void * iRef)
{
	if (!strcmp((char *)iRef, "FMS-CDU"))
	{
		if (menuitem == 0)
		{
			FMScreate(200, 800);
			menuitem = 1;
		}
		else
			if (!XPIsWidgetVisible(FMSwindow))
				XPShowWidget(FMSwindow);
	}
}

int navdata_parser(int mode, std::string search, Navaid* ret, std::ifstream* navFile)  //0 - parse and load everything (RAM!!!!), 1 - parse searching for a single earth_nav entry and add it to nodes_db, 2 - search for a single earth_fix entry and add to fixes_db, 3 - single earth_awy entry and add to segments_db, 4 - search both navaids and fixes and write the result into "ret"
{
	

	char system_path[512];
	char first;
	XPLMGetSystemPath(system_path);
	//LPCWSTR lpcwpath = 
	SetCurrentDirectoryA(system_path);
	//std::ifstream curNavFile;
	std::string buff;
	//navFile = new std::ifstream();
	bool inter = false;
	int found = 1;
	std::ifstream temp;
	std::ifstream* curNavFile;


	if(mode == 0 || mode ==1||mode ==4)//open earth_nav.dat
	{
		found = 1;
		if (navFile == NULL)
		{
			curNavFile = &temp;
			inter = true;
		}
		else curNavFile = navFile;
		if (curNavFile->is_open() == false) {

			curNavFile->open(".\\Custom Data\\earth_nav.dat");
			curNavFile->get(first);
			if (curNavFile->fail() || (first != 'I' && first != 'A'))
			{
				curNavFile->clear();
				if (curNavFile->is_open())curNavFile->close();
				curNavFile->open(".\\Resources\\default data\\earth_nav.dat");
				curNavFile->get(first);
			}
			if (curNavFile->fail() || (first != 'I' && first != 'A'))
			{
				MessageBox(NULL, (LPCTSTR) "navdata_parser error: no instance of earth_nav.dat available or the existing files are corrupted", (LPCTSTR)"Error", MB_OK);
				return -1;
			}


			
		

			//check data
			if (!curNavFile->is_open())return -1;

			getline(*curNavFile, buff); //header
			getline(*curNavFile, buff); //should be empty;
		}
		//initialize navaids
		Navaid nav;
		while (curNavFile->eof() == false && nav.id != search)
		{
			*curNavFile >> nav;
			switch (mode)
			{
			case(0):
				nodes_db.push_back(nav);
				break;
			case(1):
				if (nav.id == search)
				{
					nodes_db.push_back(nav);
				}
				break;
			case(4):
				if (nav.id == search)*ret = nav;
				break;
			}
		}
		if (curNavFile->eof() == true) found = 0;
		if (inter == true)
		{curNavFile->close();
		curNavFile->clear(); }
		
	}


	if (mode == 0 || mode == 2 || mode == 4)//open earth_fix.dat
	{
		found = 1;
		if (navFile == NULL)
		{
			curNavFile = &temp;
			inter = true;
		}
		else (curNavFile = navFile);
		if (curNavFile->is_open() == false) {                        //open file if no pointer provided

			curNavFile->open(".\\Custom Data\\earth_fix.dat");
			curNavFile->get(first);
			if (curNavFile->fail() || (first != 'I' && first != 'A'))
			{
				curNavFile->clear();
				if (curNavFile->is_open())curNavFile->close();
				curNavFile->open(".\\Resources\\default data\\earth_fix.dat");
				curNavFile->get(first);
			}
			if (curNavFile->fail() || (first != 'I' && first != 'A'))
			{
				MessageBox(NULL, (LPCTSTR) "navdata_parser error: no instance of earth_fix.dat available or the existing files are corrupted", (LPCTSTR)"Error", MB_OK);
				return -1;
			}

		
		//check data
		if (!curNavFile->is_open())return -1;
		buff.erase();
		getline(*curNavFile, buff); //header
		getline(*curNavFile, buff); //should be empty;
		}
	//initialize fixes

		Navaid fix(Fix);
		while (curNavFile->eof() == false && fix.id != search)
		{
			*curNavFile >> fix;
			switch (mode)
			{
			case(0):
				fixes_db.push_back(fix);
				break;
			case(2):
				if (fix.id == search)fixes_db.push_back(fix);
				break;
			case(4):
				if (fix.id == search)*ret = fix;
				break;
			}
			
		}
		if (curNavFile->eof() == true) found = 0;
		if (inter == true) {
			curNavFile->close();
			curNavFile->clear();
		}
	}


	if(mode==3||mode == 0) //open earth_awy.dat
	{
		found = 1;
		if (navFile == NULL)
		{
			curNavFile = &temp;
			inter = true;
		}
		else curNavFile = navFile;
		if (curNavFile->is_open() == false) {

			curNavFile->open(".\\Custom Data\\earth_awy.dat");
			curNavFile->get(first);
			if (curNavFile->fail() || (first != 'I' && first != 'A'))
			{
				curNavFile->clear();
				if (curNavFile->is_open())curNavFile->close();
				curNavFile->open(".\\Resources\\default data\\earth_awy.dat");
				curNavFile->get(first);
			}
			if (curNavFile->fail() || (first != 'I' && first != 'A'))
			{
				MessageBox(NULL, (LPCTSTR) "navdata_parser error: no instance of earth_awy.dat available or the existing files are corrupted", (LPCTSTR)"Error", MB_OK);
				return -1;
			}


			//check data
			if (!curNavFile->is_open())return -1;
			buff.erase();
			getline(*curNavFile, buff); //header
			getline(*curNavFile, buff); //should be empty;
		}
		Airway airway;
		//std::ofstream debug;
		//debug.open(".\\Resources\\plugins\\FMS-CDU\\read_log.txt", std::ios::out);
		size_t pos;
		while (curNavFile->eof() == false && mode == 0)
		{
			
		/*	if (buff == "99")
			{
				found = 0;
				break;
			}
			else
			{
				pos = buff.find(search);
				if (pos != std::string::npos) airway.ReadFromString(buff);
			}*/

			/*switch (mode)
			{
			case(0):
				*curNavFile >> airway;
				segments_db.push_back(airway);
				getline(*curNavFile, buff);
				
				break;
			case(3):
			//	int nodes_added = nodes_db.size();
			//	int fixes_added = fixes_db.size();						//record number of database entries in navaids and fixes BEFORE the line is read
				*curNavFile >> airway;
			//	nodes_added = nodes_db.size() - nodes_added;			//check how many entries were added during input run
			//	fixes_added = fixes_db.size() - fixes_added;
				if (std::any_of(airway.awy.begin(), airway.awy.end(), [=](std::string s) {return s == search; }) == false)
			//	{
			//		for (int i = 0; i < nodes_added; i++)nodes_db.pop_back();
			//		for (int i = 0; i < fixes_added; i++)fixes_db.pop_back();
			//	} //if it's not the airway we're looking for remove redundant navaids and fixes
			//	else	//else check if it isn't already added and push back the airway;
			//	{
					if(!std::any_of(segments_db.begin(), segments_db.end(), [&](Airway const& n) {
						if (n.path.front()==airway.path.front() && n.path.back()==airway.path.back()) return true;
					}))
					segments_db.push_back(airway);
				//}
				break;
			}
			debug << buff;
			//*curNavFile >> airway;*/
			*curNavFile >> airway;
			if (!curNavFile->eof())segments_db.push_back(airway);

		}
		if (curNavFile->eof() == true) found = 0;
		if (inter == true) {
			curNavFile->close();
			curNavFile->clear();
		}
	}
	return found;
}

void initialize_interface()
{
//	float fbuff;
	//int ibuff;

	//inop

	std::vector<std::string> buffer = { "", "", "", "", "", "", "                 INOP", "", "", "", "", "", "<BACK" };
	Screen buffs(buffer);
	inop = Page(buffs);
	inop.AddCb(Page::l_lsk_6, 0, fmf::go_back);

	//init ref screen

	buffer = {
		"               INIT/REF INDEX|1/1",
		"",
		"<IDENT|NAVDATA>",
		"",
		"<POS",
		"",
		"<PERF",
		"",
		"<TAKEOFF",
		"",
		"<APPROACH|SEL CONFIG>",
		"",
		"<OFFSET|MAINT>"
	};
	buffs = Screen(buffer);
	init_ref=Page(buffs);
	init_ref.AddRef(Page::l_lsk_1, 0, &ident);

	//blank screen

	buffer = { "", "", "", "", "", "", "", "", "", "", "", "", "" };
	buffs = Screen(buffer);
	blank=Page(buffs);

	//test screen

	buffer = {
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"--------------------------------XX-----------",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	};
	buffs = Screen(buffer);
	test = Page(buffs);

	//ident

	/*
	ident.AddCb(Page::l_lsk_1, 0, fmf::get_aircraft_desc);
	ident.AddCb(Page::l_lsk_2, 0, fmf::get_aircraft_ICAO);
	ident.AddCb(Page::l_lsk_3, 0, fmf::get_aircraft_tmax);
	*/
	
	buffer = {
		"             IDENT|1/1",
		"  MODEL|ENG RATING",
		"",
		"  NAV DATA|ACTIVE",
		"",
		"",
		"",
		"",
		"",
		" |SUPP DATA",
		"",
		"----------------------------------------------------------------",
		"<INDEX|POS INIT>"
	};
	buffs = Screen(buffer);
	ident = Page(buffs);
	fmf::disp_byte_l(2, 0, &ident, df::acf_ICAO, 4);    //model
	fmf::engine_rating();
	ident.AddRef(Page::l_lsk_6, 0, &init_ref);
	ident.AddRef(Page::r_lsk_6, 0, &pos_init);

	//pos init
	buffer = {
		"          POS INIT|1/1",
		"",
		"",
		"|CURRENT POS",
		"|□□□°□□.□ □□□□°□□.□",
		"",
		"",
		"",
		"",
		"",
		"",
		"------------------------------------------------------------",
		"<INDEX|ROUTE>"
	};
	buffs = Screen(buffer);
	pos_init = Page(buffs);
	pos_init.AddRef(Page::l_lsk_6, 0, &init_ref);
	pos_init.AddRef(Page::r_lsk_6, 0, &route);

	//route
	
	buffer = {
		"                  RTE|1/1",
		"ORIGIN|DEST",
		"----|----",
		" |FLT NO.",
		" |--------",
		"RUNWAY",
		"---",
		"",
		"",
		"",
		"",
		"",
		""
	};
	buffs = Screen(buffer);
	route = RoutePage(buffs);
	route.AddCb(Page::l_lsk_1, 0, fmf::select_origin);
	route.AddCb(Page::r_lsk_1, 0, fmf::select_destination);
	//route.AddField(Page::r_lsk_2, 0, "--------");
	//route.AddField(Page::l_lsk_3, 0, "---");
	
	//backup of route

	route_bup = route;

	buffer = {
		"                  LEGS|1/1",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		""
	};
	buffs = Screen(buffer);
	legs = LegsPage(buffs);
	legs.MarkList(0, 0, 6);
	legs_bup = legs;
	
}

void initialize_database()   //not working, XPLMNavRef doesn't seem to respond properly in v11
{

	XPLMNavRef nav_buff = XPLMGetFirstNavAid();
	XPLMNavRef nav_buff2;
	Navaid db_buff;
	while (nav_buff != XPLM_NAV_NOT_FOUND)
	{
		//db_buff = Navaid(nav_buff);
		if (db_buff.type == Airp) airport_db.push_back(db_buff);
		else nodes_db.push_back(db_buff);
		nav_buff2 = XPLMGetNextNavAid(nav_buff);
		nav_buff = nav_buff2;
	}
	
}

float DeferredInitACLOAD(float elapsedMe, float elapsedSim, int counter, void* inRefcon)
{
	std::string good_init = initialize_data();
	if (good_init != "datarefs|OK")
	{
		std::ostringstream errorcode;
		errorcode << "ERROR: dataref " << good_init << " not loaded";
		sp.Error(errorcode.str());
		return 0;
	}
	initialize_interface();
	//navdata_parser();
	return 0;
}


PLUGIN_API int XPluginStart(char * outName, char * outSig, char * outDesc)
{
	std::strcpy(outName, "FMS-CDU");
	std::strcpy(outSig, "mtrsh.proj.fmscdu");
	std::strcpy(outDesc, "window based aircraft independent FMS");
	
	item = XPLMAppendMenuItem(XPLMFindPluginsMenu(), "FMS-CDU", NULL, 1);
	menuid = XPLMCreateMenu("FMS-CDU", XPLMFindPluginsMenu(), item, FMSmenu, NULL);
	XPLMAppendMenuItem(menuid, "ExtFMS", (void *)"FMS-CDU", 1);
	//initialize_database();
	navdata_parser();
	//airfield_parser();
	remove("FMSdebug.txt");
	
	return 1;
}

PLUGIN_API void	XPluginStop(void)
{
	XPDestroyWidget(FMSwindow, 1);
	//XPLMDestroyWindow(wind);
}

PLUGIN_API void XPluginDisable(void)
{
}

PLUGIN_API int XPluginEnable(void)
{
	return 1;
}

PLUGIN_API void XPluginReceiveMessage(
	XPLMPluginID inFromWho, intptr_t inMessage, void * inParam)
{
	if (inFromWho == XPLM_PLUGIN_XPLANE) 
	{
		if (inMessage == XPLM_MSG_PLANE_LOADED)
		{
			
			int param;
			param = reinterpret_cast<int>(inParam);
			if (param == 0)
			{
				//reinit everytime user plane loads
				XPLMRegisterFlightLoopCallback(DeferredInitACLOAD, -10, NULL);
				XPLMRegisterFlightLoopCallback(floop::GetPosition, -15, NULL);
				XPLMRegisterFlightLoopCallback(floop::WindCalculation, 0, NULL);
				XPLMRegisterFlightLoopCallback(floop::LNav, 0, NULL);
				XPLMRegisterFlightLoopCallback(floop::updatenextleg, 0, NULL);
				XPLMRegisterFlightLoopCallback(floop::legsUpdate, 0, NULL);
				//XPLMRegisterFlightLoopCallback(floop::distancenext, 0, NULL);
				XPLMRegisterFlightLoopCallback(floop::turn, 0, NULL);
				//XPLMRegisterFlightLoopCallback(floop::distancesUpdate, 0, NULL);
				//XPLMRegisterFlightLoopCallback(floop::legNamesUpdate, 0, NULL);
				//XPLMRegisterFlightLoopCallback(floop::Update_engine_rating, 5, NULL);
			}

		}
	}
}