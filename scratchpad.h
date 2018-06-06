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
	char _output[46];

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

