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
	