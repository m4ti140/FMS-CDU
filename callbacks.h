#pragma once
//#include <windows.h>
#include <stack>
#include <sstream>
#include "XPLMGraphics.h"
#include "XPLMDisplay.h"
#include "XPLMDataAccess.h"
#include "XPWidgets.h"
#include "XPLMProcessing.h"
#include "XPWidgetUtils.h"
#include "Screen.h"
#include "scratchpad.h"
#include "widgetids.h"
#include "Pages.h"
#include "Data.h"
#include "Page.h"
#include "XPUIGraphics.h"
#include "datarefs.h"
#include "XPLMPlanes.h"
//#include <algorithm>

#define N_TO_LBF *=0.224809;
#define W_TO_HP *=0.00134102;
#define PI 3.14159265
#define RAD *PI/180.
#define DEG *180./PI

bool menuitem;
Scratchpad sp;
std::stack<Page*>history;
Page* currpage = &init_ref;
char cache[13][46];
bool pagechange = true;
char current_aircraft_path[512];
char current_aircraft_file[256];
void(*execute)() = NULL;
bool lnav = false;
size_t distindex = 1;

namespace call 
{
	
	int FMSdraw(XPWidgetMessage inMessage, XPWidgetID inWidget, intptr_t inParam1, intptr_t inParam2)
	{
		if (inMessage == xpMsg_Draw)
		{
			int left, right, top, bottom;
			XPGetWidgetGeometry(inWidget, &left, &top, &right, &bottom);
			XPDrawWindow(left, bottom, right, top, xpWindow_Screen);

			if (pagechange == true) 
			{
				(*currpage).cont[(*currpage).GetSubpage()].GetScrn(cache);
				pagechange = false;
			}

			float color1[] = { 1.0, 1.0, 1.0 };
			float color2[] = { 0.0, 1.0, 1.0 };

			int line = top - 15;
			for (int i = 0; i <= 12; i += 2)
			{
				XPLMDrawString(color1, left + 15, line, &cache[i][0], NULL, xplmFont_Basic);
				line -= 34;
			}
			line = top - 32;
			for (int i = 1; i <= 11; i += 2)
			{
				XPLMDrawString(color2, left + 15, line, &cache[i][0], NULL, xplmFont_Basic);
				line -= 34;
			}
			XPLMDrawString(color1, left + 15, line, sp.GetSP(), NULL, xplmFont_Basic);
			return 1;
		}
		else return 0;
	}
	/*void keyhand(XPLMWindowID inWindowID, char inKey, XPLMKeyFlags inFlags, char inVirtualKey, void * inRefcon, int losingFocus)
	{
		return;
	}
	int clhand(XPLMWindowID inWindowID, int x, int y, XPLMMouseStatus inMouse, void * inRefcon)
	{
		return 1;
	}*/
	
	

	int FMShand(XPWidgetMessage inMessage, XPWidgetID inWidget, intptr_t inParam1, intptr_t inParam2)
	{
		Page* tester = NULL;
		//close button
		if (inMessage == xpMessage_CloseButtonPushed)
		{
			if (menuitem == 1)XPHideWidget(FMSwindow);
			else MessageBox(NULL, (LPCTSTR) "FMSHand Error: menuitem == 0; the window to be hidden does not exist", (LPCTSTR)"Error", MB_OK);
			return 1;
		}

		//virtual keyboard

		if (inParam1 ==  (intptr_t)k::A && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("A");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::B && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("B");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::C && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("C");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::D && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("D");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::E && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("E");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::F && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("F");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::F && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("F");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::G && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("G");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::H && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("H");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::I && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("I");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::J && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("J");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::K && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("K");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::L && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("L");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::M && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("M");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::N && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("N");

			return 1;
		}
		if (inParam1 ==  (intptr_t)k::M && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("M");

			return 1;
		}
		if (inParam1 ==  (intptr_t)k::O && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("O");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::P && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("P");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::Q && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("Q");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::R && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("R");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::S && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("S");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::T && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("T");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::U && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("U");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::V && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("V");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::W && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("W");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::X && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("X");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::Y && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("Y");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::Z && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("Z");
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::CLR && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Clear();
			return 1;
		}
		if (inParam1 ==  (intptr_t)k::SP && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add(" ");
			return 1;
		}
		if (inParam1 == (intptr_t)k::SLASH && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("/");
			return 1;
		}
		if (inParam1 == (intptr_t)k::N1 && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("1");
			return 1;
		}
		if (inParam1 == (intptr_t)k::N2 && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("2");
			return 1;
		}if (inParam1 == (intptr_t)k::N3 && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("3");
			return 1;
		}if (inParam1 == (intptr_t)k::N4 && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("4");
			return 1;
		}if (inParam1 == (intptr_t)k::N5 && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("5");
			return 1;
		}if (inParam1 == (intptr_t)k::N6 && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("6");
			return 1;
		}if (inParam1 == (intptr_t)k::N7 && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("7");
			return 1;
		}if (inParam1 == (intptr_t)k::N8 && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("8");
			return 1;
		}
		if (inParam1 == (intptr_t)k::N9 && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("9");
			return 1;
		}
		if (inParam1 == (intptr_t)k::N0 && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add("0");
			return 1;
		}
		if (inParam1 == (intptr_t)k::NDOT && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Add(".");
			return 1;
		}
		if (inParam1 == (intptr_t)k::NPM && inMessage == xpMsg_PushButtonPressed)
		{
			sp.FlipSign();
			return 1;
		}
		if (inParam1 == (intptr_t)k::DEL && inMessage == xpMsg_PushButtonPressed)
		{
			sp.Del();
			return 1;
		}

		//LSK processing

		if (inParam1 == (intptr_t)k::L_LSK1 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::l_lsk_1, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}

		if (inParam1 == (intptr_t)k::L_LSK2 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::l_lsk_2, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}
		if (inParam1 == (intptr_t)k::L_LSK3 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::l_lsk_3, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}
		if (inParam1 == (intptr_t)k::L_LSK4 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::l_lsk_4, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}
		if (inParam1 == (intptr_t)k::L_LSK5 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::l_lsk_5, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}
		if (inParam1 == (intptr_t)k::L_LSK6 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::l_lsk_6, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}
		if (inParam1 == (intptr_t)k::R_LSK1 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::r_lsk_1, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}
		if (inParam1 == (intptr_t)k::R_LSK2 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::r_lsk_2, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}
		if (inParam1 == (intptr_t)k::R_LSK3 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::r_lsk_3, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}
		if (inParam1 == (intptr_t)k::R_LSK4 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::r_lsk_4, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}
		if (inParam1 == (intptr_t)k::R_LSK5 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::r_lsk_5, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}
		if (inParam1 == (intptr_t)k::R_LSK6 && inMessage == xpMsg_PushButtonPressed)
		{
			tester = currpage->Callback(Page::r_lsk_6, &sp);
			if (tester != NULL)
			{
				history.push(currpage);
				currpage = tester;
				pagechange = true;
			}
			return 1;
		}

		//function keys

		if (inParam1 == (intptr_t)k::INIT_REF && inMessage == xpMsg_PushButtonPressed)
		{
			history.push(&init_ref);
			currpage = &init_ref;
			pagechange = true;
			return 1;
		}

		if (inParam1 == (intptr_t)k::RTE && inMessage == xpMsg_PushButtonPressed)
		{
			history.push(&route);
			currpage = &route;
			pagechange = true;
			return 1;
		}

		if (inParam1 == (intptr_t)k::EXEC && inMessage == xpMsg_PushButtonPressed)
		{
			if(execute != NULL) execute();
			pagechange = true;
			return 1;
		}

		if (inParam1 == (intptr_t)k::NEXT_PAGE && inMessage == xpMsg_PushButtonPressed)
		{
			currpage->NextPage();
			pagechange = true;
			return 1;
		}

		if (inParam1 == (intptr_t)k::PREV_PAGE && inMessage == xpMsg_PushButtonPressed)
		{
			currpage->PrevPage();
			pagechange = true;
			return 1;
		}

		if (inParam1 == (intptr_t)k::LEGS && inMessage == xpMsg_PushButtonPressed)
		{
			history.push(&legs);
			currpage = &legs;
			pagechange = true;
			return 1;
		}

		return 0;
	}
	
	/*
	int FMSdraw(XPLMDrawingPhase inPhase, int inOrder, void * inRefcon)
	{
		return 1;
	}*/
}

namespace floop
{

	/*float Update_engine_rating(float elapsedMe, float elapsedSim, int counter, void* inRefcon)
	{
		engine_rating();
		return 5.0;
	}
	*/
	float GetPosition(float elapsedMe, float elapsedSim, int counter, void* inRefcon)
	{
		aircraft.lat = XPLMGetDataf(df::latitude);
		aircraft.lon = XPLMGetDataf(df::longitude);
		aircraft.alt = XPLMGetDataf(df::elevation);
		return 0.1;
	}

	float WindCalculation(float elapsedMe, float elapsedSim, int counter, void* inRefcon)
	{
		float vt;
		float vg;
		float beta;

		vt = XPLMGetDataf(df::true_airspeed);
		vg = XPLMGetDataf(df::groundspeed);
		beta = XPLMGetDataf(df::beta);

		aircraft.heading = XPLMGetDataf(df::true_psi);
		aircraft.windspeed = sqrt(vt*vt + vg*vg - 2.*vt*vg*cos(beta RAD));
		aircraft.winddir = 180. - asin(vg / aircraft.windspeed*sin(beta RAD)) DEG;

		return 1.0;

	}

	/*float LNav(float elapsedMe, float elapsedSim, int counter, void* inRefcon)
	{
		float lon12;
		float lon01;
		float dec;
		float beta;
		float dist;

		lon12 = active_flightplan.legs.front().waypoint.lon RAD - aircraft.lon RAD;

		aircraft.next_heading = atan2(sin(lon12), (cos(aircraft.lat RAD)*tan(active_flightplan.legs.front().waypoint.lat RAD) - sin(aircraft.lat RAD)*cos(lon12))) DEG;   //calculate great circle bearing to next waypoint

		dist = 3440.0695* acos(sin(aircraft.lat RAD)*sin(active_flightplan.legs.front().waypoint.lat RAD) + cos(aircraft.lat RAD)*cos(active_flightplan.legs.front().waypoint.lat RAD)*cos(lon12));

		active_flightplan.legs.front().distance = dist;

		if (aircraft.next_heading < 0) aircraft.next_heading += 360.;

		if (lnav == false)return 0.;			//if lnav has been turned off, stop flightloop;

		if (active_flightplan.legs.front().segment.name == active_flightplan.direct.name)   //if direct
		{
			aircraft.heading = XPLMGetDataf(df::true_psi);
			dec = XPLMGetDataf(df::magnetic_variation);
			beta = XPLMGetDataf(df::beta);

			if ((aircraft.heading - aircraft.next_heading) < -20 || (aircraft.heading - aircraft.next_heading) > 20) XPLMSetDataf(df::heading_mag, aircraft.next_heading + dec);
			else XPLMSetDataf(df::heading_mag, aircraft.next_heading + dec - beta);
		}
		else				//between waypoints
		{
			char segdir;
			segdir = active_flightplan.legs.front().segment.dir;

			if (segdir == 'F')
			{
				lon01 = active_flightplan.legs.front().segment.path.front()->lon RAD - aircraft.lon RAD;

				aircraft.prev_heading = atan2(sin(lon01), (cos(aircraft.lat RAD)*tan(active_flightplan.legs.front().segment.path.front()->lat RAD) - sin(aircraft.lat RAD)*cos(lon01))) DEG;

				if (aircraft.next_heading < 0) aircraft.next_heading += 360.;
			}

			if (segdir == 'B')
			{
				lon01 = active_flightplan.legs.front().segment.path.back()->lon RAD - aircraft.lon RAD;

				aircraft.prev_heading = atan2(sin(lon01), (cos(aircraft.lat RAD)*tan(active_flightplan.legs.front().segment.path.back()->lat RAD) - sin(aircraft.lat RAD)*cos(lon01))) DEG;

				if (aircraft.next_heading < 0) aircraft.next_heading += 360.;
			}

			if (segdir == 'N')
			{
				if (*active_flightplan.legs.front().segment.legs.front().waypoint == active_flightplan.legs.front().waypoint)
				{
					lon01 = active_flightplan.legs.front().segment.path.back()->lon RAD - aircraft.lon RAD;

					aircraft.prev_heading = atan2(sin(lon01), (cos(aircraft.lat RAD)*tan(active_flightplan.legs.front().segment.path.back()->lat RAD) - sin(aircraft.lat RAD)*cos(lon01))) DEG;

					if (aircraft.next_heading < 0) aircraft.next_heading += 360.;
				}
				else
				{
					lon01 = active_flightplan.legs.front().segment.path.front()->lon RAD - aircraft.lon RAD;

					aircraft.prev_heading = atan2(sin(lon01), (cos(aircraft.lat RAD)*tan(active_flightplan.legs.front().segment.path.front()->lat RAD) - sin(aircraft.lat RAD)*cos(lon01))) DEG;

					if (aircraft.next_heading < 0) aircraft.next_heading += 360.;
				}
			}

			aircraft.heading = XPLMGetDataf(df::true_psi);
			dec = XPLMGetDataf(df::magnetic_variation);
			beta = XPLMGetDataf(df::beta);

			if ((aircraft.heading - aircraft.next_heading) < -20 || (aircraft.heading - aircraft.next_heading) > 20) XPLMSetDataf(df::heading_mag, aircraft.next_heading + dec - (aircraft.next_heading - aircraft.prev_heading + 180.));
			else XPLMSetDataf(df::heading_mag, aircraft.next_heading + dec - beta - (aircraft.next_heading - aircraft.prev_heading + 180));

		}
		return 1.0;
	}*/

	float distancenext(float elapsedMe, float elapsedSim, int counter, void* inRefcon)   //update distances to consecutive waypoints
	{
		if (active_flightplan.legs.size() < 2) return -5;

		if (distindex >= active_flightplan.legs.size())
		{
			distindex = 1;
		}
		float lon12 = active_flightplan.legs[distindex].waypoint.lon RAD - active_flightplan.legs[distindex - 1].waypoint.lon RAD;

		active_flightplan.legs[distindex].distance = active_flightplan.legs[distindex - 1].distance + (3440.0695 * acos(sin(active_flightplan.legs[distindex - 1].waypoint.lat RAD)*sin(active_flightplan.legs[distindex].waypoint.lat RAD) + cos(active_flightplan.legs[distindex - 1].waypoint.lat RAD)*cos(active_flightplan.legs[distindex].waypoint.lat RAD)*cos(lon12)));

		distindex++;

		return -5;
	}

	/*float distancesUpdate(float elapsedMe, float elapsedSim, int counter, void* inRefcon)
	{
		std::deque<std::string>dist;

		for (size_t i = 0; i < active_flightplan.legs.size(); i++)
		{
			std::ostringstream buff;
			buff << active_flightplan.legs[i].distance;
			dist.push_back(buff.str());
		}
		legs.RefreshList(dist, 1, 0);
		return 2.0;
	}*/

	/*float legNamesUpdate(float elapsedMe, float elapsedSim, int counter, void* inRefcon)
	{
		std::deque<std::string>names;
		for (size_t i = 0; i < active_flightplan.path.size(); i++)
		{
			names.push_back(active_flightplan.path[i].id);
		}
		legs.RefreshList(names, 0, 0);
		return 2.0;
	}*/

	/*float turn(float elapsedMe, float elapsedSim, int counter, void* inRefcon)
	{
		if (active_flightplan.path.size() <= 1) return 0.5;

		float disttoturnstart, vg, nextturn;
		int bank = XPLMGetDatai(df::heading_roll_mode);
		if (bank = 0)
		{
			XPLMSetDatai(df::heading_roll_mode, 30);
			bank = 30;
		}
		vg = XPLMGetDataf(df::groundspeed);

		float turnrad = vg*vg / (68417.1112*tan(bank RAD));

		float lon12 = active_flightplan.path[1].lon RAD - active_flightplan.legs.front().waypoint.lon RAD;

		nextturn = atan2(sin(lon12), (cos(active_flightplan.legs.front().waypoint.lon RAD)*tan(active_flightplan.path[1].lat RAD) - sin(active_flightplan.legs.front().waypoint.lon RAD)*cos(lon12))) DEG;

		float dif = nextturn - aircraft.next_heading;

		if (dif > 180) dif -= 360;
		if (dif < 180) dif += 360;

		dif = abs(dif);

		if (dif > 150)
		{
			if (active_flightplan.legs.front().distance < 5)
			{
				active_flightplan.Next();
				current_flightplan.Next();
			}
			return 0.5;

		}

		disttoturnstart = tan(0.5*dif)*turnrad;

		if (disttoturnstart < active_flightplan.legs.front().distance)
		{
			active_flightplan.Next();
			current_flightplan.Next();
		}

		return 0.5;

	}*/

}

namespace fmf
{

	void activate_flightplan();
	void engine_rating()
	{
		float fbuff;
		int ibuff;
		//std::string buffer;
		//fbuff = XPLMGetDataf(df::acf_tmax);
		//ibuff = XPLMGetDatai(df::acf_en_type);
		/*std::ostringstream debug;
		debug << fbuff;
		char debugc[240];
		debug.str().copy(debugc, 240, 0);
		XPLMDebugString(debugc);*/
		//std::cout << fbuff << std::endl;
		fbuff = XPLMGetDataf(df::acf_tmax);
		if (fbuff!=0)                        //jet/rocket engine
		{
			
		
				//fbuff /= 1000;
				fbuff N_TO_LBF;
				fbuff += 0.5; 
				std::ostringstream cbuff;
				//cbuff << ibuff << " ";
				ibuff = static_cast<int>(fbuff);
				
				cbuff << ibuff << "lbf";
				ident.cont[0].RMod(2, cbuff.str());
			

		}
		else {
			fbuff = XPLMGetDataf(df::acf_pmax);
			if (fbuff != 0) //prop engine
			{

				fbuff W_TO_HP;
				fbuff += 0.5;
				std::ostringstream cbuff;
				//cbuff << ibuff << " ";
				ibuff = static_cast<int>(fbuff);

				cbuff << ibuff << "HP";
				ident.cont[0].RMod(2, cbuff.str());
			}
			else
			{
				std::ostringstream cbuff;
				cbuff << "----";
				ident.cont[0].RMod(2, cbuff.str());
			}
		}
		pagechange = true;
	}
	void disp_byte(Page* output, XPLMDataRef data)
	{
		int size = XPLMGetDatab(data, NULL, NULL, NULL);
		char * content;
		content = new char[size];
		XPLMGetDatab(data, content, 0, size);
		std::string temp;
		int subpage = output->GetSubpage();
		output->cont[subpage].Clear();
		for (int i = 0; i < 13; i++)
		{

			temp.assign(&content[i*45], 45);
			output->cont[subpage].Mod(i, temp);
			if (45 * i > size) break;
		}
	}

	void disp_byte_l(int line, int subpage /*-1 - current*/, Page* output, XPLMDataRef data, int length /*-1 - all*/)   
	{
		int size;
		if(length ==-1)size = XPLMGetDatab(data, NULL, NULL, NULL);
		else size = length;
		char * content;
		content = new char[size];
		XPLMGetDatab(data, content, 0, size);
		std::string temp;
		int subp;
		if(subpage == -1) subp = output->GetSubpage();
		else subp = subpage;
		//output->cont[subpage].Clear();
		temp.assign(content, size);
		output->cont[subp].Mod(line, temp);
		//if (45 * i > size) break;
	}

	void disp_float(Page* output, XPLMDataRef data)
	{
		float content = XPLMGetDataf(data);
		int subpage = output->GetSubpage();
		//std::string temp;
		std::ostringstream conv;
		conv << content;
		//temp = conv.str();
		output->cont[subpage].Clear();
		output->cont[subpage].Mod(0, conv.str());
	}

	Page* go_back(int select, void* input, Page* output)
	{
		currpage = history.top();
		history.pop();
		pagechange = true;
		return NULL;
	}

	Page* get_aircraft_desc(int select, void* input, Page* output)
	{
		XPLMDataRef desc = XPLMFindDataRef("sim/aircraft/view/acf_descrip");
		if (desc == NULL)
		{
			sp.Error("DATA NOT FOUND");
			return NULL;
		}
		fmf::disp_byte(output, desc);
		pagechange = true;
		return NULL;
	}

	Page* get_aircraft_ICAO(int select, void* input, Page* output)
	{
		XPLMDataRef desc = XPLMFindDataRef("sim/aircraft/view/acf_ICAO");
		if (desc == NULL)
		{
			sp.Error("DATA NOT FOUND");
			return NULL;
		}
		fmf::disp_byte(output, desc);
		pagechange = true;
		return NULL;
	}

	Page* get_aircraft_tmax(int select, void* input, Page* output)
	{
		XPLMDataRef desc = XPLMFindDataRef("sim/aircraft/engine/acf_tmax");
		if (desc == NULL)
		{
			sp.Error("DATA NOT FOUND");
			return NULL;
		}
		fmf::disp_float(output, desc);
		pagechange = true;
		return NULL;
	}
	Page* select_origin(int select, void* input, Page* output)
	{
		Scratchpad* edit = static_cast<Scratchpad*>(input);

		if (edit->isDel())
		{
			Page::copy_paste(select, input, output);
			current_flightplan.Wipe();
			return NULL;
		}

		std::string ID = edit->cont;
		XPLMNavRef ap = XPLMFindNavAid(NULL, ID.c_str(), NULL, NULL, NULL, xplm_Nav_Airport);
		if (ap == XPLM_NAV_NOT_FOUND)
		{
			edit->Error("NOT IN DATABASE");
		}
		else
		{
			Navaid origin(ap);
			Page::copy_paste(select, input, output);
			current_flightplan.Origin(ap);
		}
		pagechange = true;
		return NULL;
	}
	Page* select_destination(int select, void* input, Page* output)
	{
		Scratchpad* edit = static_cast<Scratchpad*>(input);

		if (edit->isDel())
		{
			Page::copy_paste(select, input, output);
			Navaid del;
			del.id = "----";
			current_flightplan.Destination(del);
			return NULL;
		}

		std::string ID = edit->cont;
		int elevation;
		XPLMNavRef ap = XPLMFindNavAid(NULL, ID.c_str(), NULL, NULL, NULL, xplm_Nav_Airport);
		if (ap == XPLM_NAV_NOT_FOUND)
		{
			edit->Error("NOT IN DATABASE");
		}
		else
		{
			Navaid destination(ap);
			Page::copy_paste(select, input, output);
			current_flightplan.Destination(ap);
			execute = activate_flightplan;
			
		}
		pagechange = true;
		return NULL;
	}

	Page* select_waypoint(int select, void* input, Page* output);
	Page* select_airway(int select, void* input, Page* output);

	void add_route_page()
	{
		std::vector<std::string>buffer = {
			"                  RTE|x/x",
			"VIA|TO",
			"-----|-----",
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
		Screen buff(buffer);
		route.AddPage(buff);
		int ammount = route.cont.size() - 1;        //page index to add callbacks to
		route.AddCb(Page::r_lsk_1, ammount, select_waypoint);
		route.AddCb(Page::l_lsk_1, ammount, select_airway);
		if (ammount <= 1) route.MarkList(Page::l_lsk_1, 1, 6);
		pagechange = true;
	}
	
	Page* select_waypoint(int select, void* input, Page* output)
	{
#ifdef _DEBUG
		std::ofstream debug;
		debug.open("FMSdebug.txt", std::ios_base::app);
#endif
		Scratchpad* edit = static_cast<Scratchpad*>(input);
		int index = route.ListIndex(select);

		if (edit->isDel())
		{
			current_flightplan.DelWaypoint(index);
			route.RefreshList(current_flightplan.legs);
			execute = activate_flightplan;
			pagechange = true;
			return NULL;
		}

		std::string ID = edit->cont;

		std::vector<Navaid>::iterator node;
		std::vector<Airway>::iterator seg;

		Navaid result;

		//if (!current_flightplan.IsAirwaySelected(index))    //if we don't have airway for this segment
		//{
			node = std::find_if(fixes_db.begin(), fixes_db.end(), [&](Navaid const& n) {return n.id == ID; });
			if (node == fixes_db.end())
			{
				node = std::find_if(nodes_db.begin(), nodes_db.end(), [&](Navaid const& n) {return n.id == ID; });
				if(node == nodes_db.end())
				{
					sp.Error("NOT IN DATABASE");
					return NULL;
				}
				else
				{
					result = *node;
				}
			}
			else
			{
				result = *node;
			}
		//}
		//else                                      //if we have an airway
		//{
		//	AirRoute current_awy = current_flightplan.RecallRoute(index);
		//	result = current_awy.CheckNavaidID(ID);
		//	if (result == NULL)
		//	{
		//		sp.Error("INVALID ENTRY");
		//		return NULL;
		//	}
		//}
		//{
		//	seg = std::find_if(segments_db.begin(), segments_db.end(), [&](Airway const& n)    //for each segment in database 
		//	{
		//		if (std::any_of(n.awy.begin(), n.awy.end(), [=](std::string s) {return s == current_flightplan.airways.back(); })) //check if it's a part of the airway
		//		{
		//			if (n.legs.front().waypoint->id == ID)                             //if yes check if the segment includes this waypoint and store the pointer to this waypoint in db
		//			{
		//				result = n.legs.front().waypoint;
		//				return true;
		//			}
		//			if (n.path.back()->id == ID)
		//			{
		//				result = n.path.back();
		//				return true;
		//			}
		//			else return false;
		//		}
		//		else return false;
		//	});
		//	if (seg == segments_db.end())
		//	{
		//		sp.Error("INVALID ENTRY");
		//		return NULL;
		//	}
		//}
#ifdef _DEBUG
			debug << "adding wp" << std::endl;
#endif
		bool added = current_flightplan.AddWaypoint(result,index);
		//Page::copy_paste(select, input, output);       //add text to route page, this will be depracated
		//int ammount = route.cont.size() - 1;
		/*if (!current_flightplan.IsAirwaySelected())
		{
			if (select == Page::r_lsk_6 && route.cont.size()<=(route.GetSubpage()+1))
			{
				add_route_page();
			}
			else
			{
				route.AddCb(select + 1, ammount, select_airway);
				route.AddCb(select + 2, ammount, select_waypoint);
			}
		}*/

		if (added) {
#ifdef _DEBUG
			debug << "wp added" << std::endl;
#endif
			route.RefreshList(current_flightplan.legs);
			execute = activate_flightplan;
			pagechange = true;
		}
		else
		{
			sp.Error("INVALID ENTRY");
		}
		sp.Clear_All();
#ifdef _DEBUG
		debug << "exiting" << std::endl;
#endif
		return NULL;
	}

	Page* select_airway(int select, void* input, Page* output)
	{
		Scratchpad* edit = static_cast<Scratchpad*>(input);

#ifdef _DEBUG
		std::ofstream debug;
		debug.open("FMSdebug.txt", std::ios_base::app);
#endif

		int index = route.ListIndex(select);

		if (edit->isDel())
		{
			current_flightplan.DelAirway(index);
			route.RefreshList(current_flightplan.legs);
			execute = activate_flightplan;
			pagechange = true;
			return NULL;
		}

		std::string airway_id = edit->cont;

		if (index == 0)		//first waypoint - no SID support yet
		{
			sp.Error("INVALID ENTRY");
			return NULL;
		}
#ifdef _DEBUG
		debug << "preaparing AirRoute object" <<std::endl;
#endif
		AirRoute airway;
		airway = current_flightplan.RecallRoute(airway_id);

#ifdef _DEBUG
		debug << "recalled: " << airway.name << std::endl;
#endif

		if (airway.name == invalid.name)
		{
#ifdef _DEBUG
			debug << "Searching db" << std::endl;
#endif
			std::vector<Airway>temp;
			for (std::vector<Airway>::iterator it = segments_db.begin(); it != segments_db.end(); ++it)
			{
#ifdef _DEBUG
				if (it == segments_db.begin()) debug << "iterating" << std::endl;
#endif
				if (it->CheckAwy(airway_id))
				{
#ifdef _DEBUG
					debug << "found segment" <<std::endl;
#endif
					temp.push_back(*it);
					if (!temp.back().MapNavaids())
					{
						sp.Error("DATABASE ERRORS FOUND");
						return NULL;
					}
#ifdef _DEBUG
					debug << "mapped " << temp.back().entry->id << " " << temp.back().exit->id << std::endl;
					debug << "Checking for duplicate" << std::endl;
#endif
					for (int i = temp.size() - 2; i >= 0; i--)
					{
						if (temp[i].entry == temp.back().entry && temp[i].exit == temp.back().exit)
						{
							temp.pop_back();
							i = -1;
#ifdef _DEBUG
							debug << "Duplicate found, removing..." << std::endl;
#endif
						}
					}
				}
			}
			if (temp.empty())
			{
#ifdef _DEBUG
				debug << "querry not found" << std::endl;
#endif
				sp.Error("NOT IN DATABASE");
				return NULL;
			}
			airway = AirRoute(airway_id, temp);
#ifdef _DEBUG
			debug << "airway retrieved" << std::endl;
#endif
		}

#ifdef _DEBUG
		debug << "running AddAirway" << std::endl;
#endif
		if (current_flightplan.AddAirway(airway, index))
		{
#ifdef _DEBUG
			debug << "Airway added" << std::endl;
#endif
			route.RefreshList(current_flightplan.legs);
			execute = activate_flightplan;
			pagechange = true;
			sp.Clear_All();
			return NULL;
		}
		else
		{
			sp.Error("INVALID ENTRY");
			return NULL;
		}
		
		//if (index > 0 && current_flightplan.IsWaypointSelected(index) && current_flightplan.IsWaypointSelected(index-1)) //we have an entry and exit and we just selected an airway to follow, now we have to find a path as airway might be diverging (it shouldn't)
		//{
		//	std::vector<Airway>temp;
		//	bool hasEntry=false, hasExit=false;
		//	//std::vector<bool>visited;
		//	//iterate through database and find all segments of this airway
		//	for (std::vector<Airway>::iterator it = segments_db.begin(); it != segments_db.end(); ++it)
		//	{
		//		if (it->CheckAwy(airway_id))
		//		{
		//			temp.push_back(*it);
		//			if (temp.back().MapNavaids())
		//			{
		//				sp.Error("DATABASE ERROR");
		//				return NULL;
		//			}
		//			if (*(temp.back().entry) == current_flightplan.GetWp(index - 1).waypoint || *(temp.back().exit) == current_flightplan.GetWp(index - 1).waypoint) hasEntry = true;
		//			if (*(temp.back().entry) == current_flightplan.GetWp(index).waypoint || *(temp.back().exit) == current_flightplan.GetWp(index).waypoint) hasExit = true;
		//			
		//		}
		//	}
		//	if (hasEntry == true && hasExit == true)
		//	{
		//		AirRoute airway(airway_id, temp);
		//		current_flightplan.AddAirway(airway, index);
		//		execute = activate_flightplan;
		//		route.RefreshList(current_flightplan.legs);
		//		pagechange = true;
		//		return NULL;
		//	}
		//	else
		//	{
		//		temp.clear();
		//		sp.Error("INVALID ENTRY");
		//		return NULL;
		//	}
		//	/*std::vector<Navaid>traversal_path;/*
		//	traversal_path=airway.BFS(current_flightplan.path[index - 1], current_flightplan.path[index]);
		//	current_flightplan.AddAirway(airway_id, traversal_path);*/
		//	
		//}

		//return NULL;
	}

	void activate_flightplan()
	{
		//check if origin and destination are present

		if (current_flightplan.origin == empty_orig_dest || current_flightplan.destination == empty_orig_dest)return;

		//check if they match the content

		//if (current_flightplan.origin != current_flightplan.legs.front().waypoint.id || current_flightplan.destination != current_flightplan.path.back().name) return;

		//if not copy the current route to active

		active_flightplan = current_flightplan;

		//and add the route list page

		if(route.cont.size()<=1) add_route_page();
		legs = legs_bup;
		legs.RefreshList(active_flightplan.legs);

		//route.SetExec(NULL);

		execute = NULL;

		//XPLMSetFlightLoopCallbackInterval(floop::GetPosition, -1, 1, NULL);
	//	XPLMSetFlightLoopCallbackInterval(floop::WindCalculation, -1, 1, NULL);
		//XPLMSetFlightLoopCallbackInterval(floop::LNav, -2, 1, NULL);
		//XPLMSetFlightLoopCallbackInterval(floop::distancenext, -3, 1, NULL);
		//XPLMSetFlightLoopCallbackInterval(floop::legNamesUpdate, -4, 1, NULL);
		//XPLMSetFlightLoopCallbackInterval(floop::distancesUpdate, -5, 1, NULL);
		//XPLMSetFlightLoopCallbackInterval(floop::turn, -6, 1, NULL);

		pagechange = true;

	}
}

