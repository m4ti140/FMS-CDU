#pragma once
#include <string>
#include "XPWidgetUtils.h"
#include "XPWidgetDefs.h"
#include "XPStandardWidgets.h"
#include "XPWidgets.h"
#include "widgetids.h"

class Scratchpad
{
private:
	bool _errstatus;
	bool _delmode;
	bool _change;
	char _output[45];

	std::string _buffer;

public:
	Scratchpad();
	~Scratchpad();
	//void Draw()
	//{
	//	_output = "[" + _buffer + "]";
		//XPSetWidgetDescriptor(s::sp, _output.c_str());
	//}
	void Add(std::string input);
	void Clear();
	void Clear_All();
	void FlipSign();
	void Del();
	void Deleted();
	bool isDel() { return _delmode; };
	void Error(std::string code);
	char * GetSP();
	std::string cont;


};

