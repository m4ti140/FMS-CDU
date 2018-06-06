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
#include <sstream>
#include <vector>

class Screen
{
public:
	Screen(const char** content);
	Screen(std::string* content);
	Screen(std::vector<std::string> content);
	Screen();
	Screen(const Screen& copy);
	Screen& operator=(const Screen& assign);
	~Screen();
	//void Draw();
	void Mod(int line, std::string mod);
	void LMod(int line, std::string mod);
	void RMod(int line, std::string mod);
	void Clear();
	void GetScrn(char(&container)[13][46]);
	char* GetLine(int line);
	void UpdatePageAmmount(int current, int number);
	std::string ReadLine(int line);
	std::string RReadLine(int line);
	std::string LReadLine(int line);
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

private:


	std::string* _content;


};

