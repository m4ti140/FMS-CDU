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

#include "scratchpad.h"



Scratchpad::Scratchpad()
{
	_buffer = "";
	cont = "";
	_output[0] = '[';
	for (int i = 1; i < 44; i++)
	{
		_output[i] = ' ';
	}
	_output[44] = ']';
	_output[45] = '\0';
	_errstatus = false;
	_change = false;
	_delmode = false;
}


Scratchpad::~Scratchpad()
{
}


void Scratchpad::Add(std::string input)
{
	if (_errstatus == false) 
	{
		if (_buffer.length() < 42) _buffer.append(input);
		cont = _buffer;
	}
	_change = true;
}
void Scratchpad::Clear()
{
	if (_errstatus)
	{
		_buffer = cont;
		//this->Draw();
		_errstatus = false;
	}
	if (_delmode)
	{
		_buffer = cont;
		_delmode = false;
	}
	else
	{
		if (_buffer.length() > 0) {
			_buffer.pop_back();
			cont = _buffer;
			//this->Draw();
		}
	}
	_change = true;
}

void Scratchpad::Clear_All()
{
	_buffer.erase();
	cont = _buffer;
	_change = true;
}
//void Del();
void Scratchpad::Error(std::string code)
{
	_buffer = code;
	_errstatus = true;
	//this->Draw();
	_change = true;
}

void Scratchpad::FlipSign()
{
	if (_errstatus == false) {
		if (_buffer.length() > 0) {
			if (_buffer.compare(0, 1, "-") == 0)_buffer.erase(_buffer.begin());
			else _buffer = "-" + _buffer;
		}
		else _buffer = "-";
		cont = _buffer;
		//this->Draw();
	}
	_change = true;
}

void Scratchpad::Del()
{
	if (!_delmode)
	{
		_buffer = "DELETE";
		_delmode = true;
		_change = true;
	}
}

void Scratchpad::Deleted()
{
	_buffer = cont;
	_delmode = false;
}

char* Scratchpad::GetSP()
{
	if (_change)
	{
		_buffer.copy(&_output[1], 42, 0);
		for (int i = _buffer.length() + 1; i < 44; i++)
		{
			_output[i] = ' ';
		}
		_change = false;
		return _output;
	}
	else
	{
		return _output;
	}
}
	