#pragma once

class Aircraft
{
public:
	float airspeed;
	float fuel_state;
	float max_fuel;
	float mass;
	float max_mass;
	float heading;
	float next_heading;
	float prev_heading;
	float lift;
	float drag;
	float lon;
	float lat;
	float alt;
	float windspeed;
	float winddir;

	Aircraft();
	~Aircraft();
};

