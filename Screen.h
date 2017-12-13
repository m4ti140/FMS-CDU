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
	void UpdatePageAmmount(int current, int number, bool isUp);
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

