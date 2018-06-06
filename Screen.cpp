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

//#include <strstream>
#include "Screen.h"
#include "widgetids.h"
#include "XPWidgets.h"
#include "XPStandardWidgets.h"
#include "XPWidgetUtils.h"

/*Screen::Screen(const char* content)
{
	_content =
}*/

Screen::Screen()
{
	_content = new std::string[13];
	for (int i = 0; i < 13; i++) _content[i] = "";

}

Screen::Screen(const char** content)
{
	_content = new std::string[13];
	for (int i = 0; i < 13; i++) _content[i] = content[i];
}

Screen::Screen(std::string* content)
{
	_content = new std::string[13];
	for (int i = 0; i < 13; i++) _content[i] = content[i];
}

Screen::Screen(const Screen& copy)
{
	_content = new std::string[13];
	for (int i = 0; i < 13; i++) _content[i] = copy._content[i];
}

Screen::Screen(std::vector<std::string> content)
{
	_content = new std::string[13];
	for (int i = 0; i < 13; i++) _content[i] = content[i];
}

Screen& Screen::operator=(const Screen& assign)
{
	if (this == &assign)return *this;
	else
	{
		for (int i = 0; i < 13; i++) this->_content[i] = assign._content[i];
		return *this;
	}
}

Screen::~Screen()
{
	delete [] _content;
}

/*void Screen::Draw()
{
	XPSetWidgetDescriptor(s::lt, _content[0].c_str());
	XPSetWidgetDescriptor(s::s1, _content[1].c_str());
	XPSetWidgetDescriptor(s::l1, _content[2].c_str());
	XPSetWidgetDescriptor(s::s2, _content[3].c_str());
	XPSetWidgetDescriptor(s::l2, _content[4].c_str());
	XPSetWidgetDescriptor(s::s3, _content[5].c_str());
	XPSetWidgetDescriptor(s::l3, _content[6].c_str());
	XPSetWidgetDescriptor(s::s4, _content[7].c_str());
	XPSetWidgetDescriptor(s::l4, _content[8].c_str());
	XPSetWidgetDescriptor(s::s5, _content[9].c_str());
	XPSetWidgetDescriptor(s::l5, _content[10].c_str());
	XPSetWidgetDescriptor(s::s6, _content[11].c_str());
	XPSetWidgetDescriptor(s::l6, _content[12].c_str());
}*/

void Screen::Clear()
{
	for (int i = 0; i < 13; i++) _content[i] = "";
}

void Screen::Mod(int line, std::string mod)
{
	_content[line] = mod;
	//this->Draw();
}

void Screen::LMod(int line, std::string mod)
{
	std::size_t posit = _content[line].std::string::find_first_of("|");
	if (posit == std::string::npos)
	{
		_content[line] = mod;
	}
	else
	{
		_content[line].erase(0, posit);
		_content[line].insert(0, mod);
	}
}

void Screen::RMod(int line, std::string mod)
{
	std::size_t posit = _content[line].std::string::find_first_of("|");
	if (posit == std::string::npos)
	{
		_content[line].append("|");
		_content[line].append(mod);
	}
	else
	{
		_content[line].erase(posit + 1);
		_content[line].append(mod);
	}
}

void Screen::GetScrn(char (&container)[13][46]) //formats screen for drawing and returns as a 46/13 2D array of chars
{
	std::size_t pos;
	std::string* buffer;
	buffer = new std::string[13];

	for (int i = 0; i < 13; i++)
	{
		buffer[i].assign(_content[i]);  //make a copy of contents
	}

	for (int i = 0; i < 13; i++)
	{
		pos = buffer[i].find('|');
		if (pos != std::string::npos)
		{
			buffer[i].replace(pos, 1, " ");  //replace formatting character '|' with enough spaces to stretch the string to screen
			while (buffer[i].length() < 45)
			{
				buffer[i].insert(pos, " ");
			}
		}
		if (buffer[i].length() > 45)
		{
			buffer[i].resize(45);   //cut the line if it's too long
		}
		while (buffer[i].length() < 45) buffer[i].append(" "); //add trailing spaces
	}
	
	for (int i = 0; i < 13; i++)
	{
		buffer[i].copy(container[i], 45, 0); //copy contents onto the array passed in argument
		container[i][45] = '\0';
	}
	delete[] buffer;
}

char * Screen::GetLine(int line)
{
	std::size_t pos;
	std::string buffer;
	//buffer = new std::string[13];

	buffer.assign(_content[line]);  //make a copy of contents

	pos = buffer.find('|');
	if (pos != std::string::npos)
	{
		buffer.replace(pos, 1, " ");  //replace formatting character '|' with enough spaces to stretch the string to screen
		while (buffer.length() < 45)
		{
			buffer.insert(pos, " ");
		}
	}
	if (buffer.length() > 45)
	{
		buffer.resize(45);   //cut the line if it's too long
	}
	while (buffer.length() < 45) buffer.append(" ");

	char* container;
	container =new char[46];
	buffer.copy(container, 45, 0);
	container[45] = '\0';

	return container;

}

void Screen::UpdatePageAmmount(int current, int number)
{
	std::ostringstream buff;
	buff << current + 1 << "/" << number;
	RMod(_lt, buff.str());
	
}

std::string Screen::ReadLine(int line)
{
	return _content[line];
}

std::string Screen::RReadLine(int line)
{
	size_t posit = _content[line].std::string::find_first_of("|");
	if (posit == std::string::npos)
	{
		return "";
	}
	else
	{
		return _content[line].substr(posit + 1, std::string::npos);
	}
}

std::string Screen::LReadLine(int line)
{
	size_t posit = _content[line].std::string::find_first_of("|");
	if (posit == std::string::npos)
	{
		return _content[line];
	}
	else
	{
		return _content[line].substr(0, posit - 1);
	}
}