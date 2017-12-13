#pragma once
#include "XPLMDataAccess.h"
#include "XPLMUtilities.h"
#include <string>
#include <vector>
#include <algorithm>

namespace df
{
	XPLMDataRef acf_en_type;		    //r
	XPLMDataRef acf_tmax;				//r
	XPLMDataRef acf_ICAO;				//r	
	XPLMDataRef acf_descrip;			//r
	XPLMDataRef acf_pmax;				//r

	XPLMDataRef autopilot_mode;			//rw
	XPLMDataRef autopilot_state;		//rw
	XPLMDataRef autopilot_disconnect;	//rw
	XPLMDataRef heading_mode;			//r
	XPLMDataRef altitude_mode;			//r
	XPLMDataRef flight_director_mode;	//rw
	XPLMDataRef autopilot_on;			//r

	XPLMDataRef current_altitude;		//rw
	XPLMDataRef altitude;				//rw
	XPLMDataRef vertical_velocity;		//rw
	XPLMDataRef airspeed;				//rw
	XPLMDataRef airspeed_is_mach;		//rw
	XPLMDataRef heading_mag;			//rw
	XPLMDataRef heading_roll_mode;		//rw
	XPLMDataRef nav_steer_deg_mag;		//rw
	XPLMDataRef syn_hold_deg;			//rw      pitch hold
	XPLMDataRef mode_hnav;				//rw
	XPLMDataRef mode_gls;				//rw
	XPLMDataRef override_nav_heading;   //rw

	XPLMDataRef latitude;				//r
	XPLMDataRef longitude;				//r
	XPLMDataRef elevation;				//r
	XPLMDataRef true_theta;				//r     pitch
	XPLMDataRef true_phi;				//r		roll
	XPLMDataRef true_psi;				//r		heading (true)
	XPLMDataRef mag_psi;				//r		heading magnetic
	XPLMDataRef alpha;					//r
	XPLMDataRef beta;					//r
	XPLMDataRef vpath;					//r
	XPLMDataRef hpath;					//r
	XPLMDataRef groundspeed;			//r
	XPLMDataRef indicated_airspeed;		//rw
	XPLMDataRef true_airspeed;			//r
	XPLMDataRef magnetic_variation;		//r
	XPLMDataRef vh_ind;					//r

}

std::string initialize_data()
{
	if ((df::acf_en_type = XPLMFindDataRef("sim/aircraft/prop/acf_en_type")) == NULL) return "acf_en_type";
	if ((df::acf_ICAO = XPLMFindDataRef("sim/aircraft/view/acf_ICAO")) == NULL)return "acf_ICAO";
	if ((df::acf_tmax = XPLMFindDataRef("sim/aircraft/engine/acf_tmax")) == NULL)return "acf_tmax";
	if ((df::acf_descrip = XPLMFindDataRef("sim/aircraft/view/acf_descrip")) == NULL)return "acf_descrip";
	if ((df::acf_pmax = XPLMFindDataRef("sim/aircraft/engine/acf_pmax")) == NULL)return "acf_pmax";
	if ((df::autopilot_mode = XPLMFindDataRef("sim/cockpit/autopilot/autopilot_mode")) == NULL)return "autopilot_mode";
	if ((df::autopilot_state = XPLMFindDataRef("sim/cockpit/autopilot/autopilot_state")) == NULL)return "autopilot_state";
	if ((df::autopilot_disconnect = XPLMFindDataRef("sim/cockpit/warnings/annunciators/autopilot_disconnect")) == NULL)return "autopilot_disconnect";
	if ((df::heading_mode = XPLMFindDataRef("sim/cockpit2/autopilot/heading_mode")) == NULL)return "heading_mode";
	if ((df::altitude_mode = XPLMFindDataRef("sim/cockpit2/autopilot/altitude_mode")) == NULL)return "altitude_mode";
	if ((df::flight_director_mode = XPLMFindDataRef("sim/cockpit2/autopilot/flight_director_mode")) == NULL)return "flight_director_mode";
	if ((df::autopilot_on = XPLMFindDataRef("sim/cockpit2/autopilot/autopilot_on")) == NULL)return "autopilot_on";

	if ((df::current_altitude = XPLMFindDataRef("sim/cockpit/autopilot/current_altitude")) == NULL)return "current_altitude";
	if ((df::altitude = XPLMFindDataRef("sim/cockpit/autopilot/altitude")) == NULL)return "altitude";
	if ((df::vertical_velocity = XPLMFindDataRef("sim/cockpit/autopilot/vertical_velocity")) == NULL)return "vertical_velocity";
	if ((df::airspeed = XPLMFindDataRef("sim/cockpit/autopilot/airspeed")) == NULL)return "airspeed";
	if ((df::airspeed_is_mach = XPLMFindDataRef("sim/cockpit/autopilot/airspeed_is_mach")) == NULL)return "airspeed_is_mach";
	if ((df::heading_mag = XPLMFindDataRef("sim/cockpit/autopilot/heading_mag")) == NULL)return "heading_mag";
	if ((df::heading_roll_mode = XPLMFindDataRef("sim/cockpit/autopilot/heading_roll_mode")) == NULL)return "heading_roll_mode";
	if ((df::nav_steer_deg_mag = XPLMFindDataRef("sim/cockpit/autopilot/nav_steer_deg_mag")) == NULL)return "nav_steer_deg_mag";
	if ((df::syn_hold_deg = XPLMFindDataRef("sim/cockpit/autopilot/syn_hold_deg")) == NULL)return "syn_hold_deg";
	if ((df::mode_hnav = XPLMFindDataRef("sim/cockpit/autopilot/mode_hnav")) == NULL)return "mode_hnav";
	if ((df::mode_gls = XPLMFindDataRef("sim/cockpit/autopilot/mode_gls")) == NULL)return "mode_gls";
	if ((df::override_nav_heading = XPLMFindDataRef("sim/operation/override/override_nav_heading")) == NULL)return "override_nav_heading";

	if ((df::latitude = XPLMFindDataRef("sim/flightmodel/position/latitude")) == NULL)return "latitude";
	if ((df::longitude = XPLMFindDataRef("sim/flightmodel/position/longitude")) == NULL)return "longitude";
	if ((df::elevation = XPLMFindDataRef("sim/flightmodel/position/elevation")) == NULL)return "elevation";
	if ((df::true_theta = XPLMFindDataRef("sim/flightmodel/position/true_theta")) == NULL)return "true_theta";
	if ((df::true_phi = XPLMFindDataRef("sim/flightmodel/position/true_phi")) == NULL)return "true_phi";
	if ((df::true_psi = XPLMFindDataRef("sim/flightmodel/position/true_psi")) == NULL) return "true_psi";
	if ((df::mag_psi = XPLMFindDataRef("sim/flightmodel/position/mag_psi")) == NULL)return "mag_psi";
	if ((df::alpha = XPLMFindDataRef("sim/flightmodel/position/alpha")) == NULL)return "alpha";
	if ((df::beta = XPLMFindDataRef("sim/flightmodel/position/beta")) == NULL)return "beta";
	if ((df::vpath = XPLMFindDataRef("sim/flightmodel/position/vpath")) == NULL)return "vpath";
	if ((df::hpath = XPLMFindDataRef("sim/flightmodel/position/hpath")) == NULL)return "hpath";
	if ((df::groundspeed = XPLMFindDataRef("sim/flightmodel/position/groundspeed")) == NULL)return "groundspeed";
	if ((df::indicated_airspeed = XPLMFindDataRef("sim/flightmodel/position/indicated_airspeed")) == NULL)return "indicated_airspeed";
	if ((df::true_airspeed = XPLMFindDataRef("sim/flightmodel/position/true_airspeed")) == NULL)return "true_airspeed";
	if ((df::magnetic_variation = XPLMFindDataRef("sim/flightmodel/position/magnetic_variation")) == NULL)return "magnetic_variation";
	if ((df::vh_ind = XPLMFindDataRef("sim/flightmodel/position/vh_ind")) == NULL)return "vh_ind";

	return "datarefs|OK";
}