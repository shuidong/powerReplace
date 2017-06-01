#pragma once
#include <map>
#include <list>
#include <string>
class Logger
{
public:
	Logger(void);
	~Logger(void);
	void static debug(const char* info);
	void static debug(std::string info);
	void static dumpWordMap(std::map<std::string, std::string>);
	void static dumpFileList(std::list<std::string>);
};

