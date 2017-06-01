#pragma once
#include <string>
#include <map>
class util
{
public:
	util(void);
	~util(void);
	std::string catFile(const char* filePath);
	void writeFile(const char* filePath, std::string fileContent);
	void replaceOneByOne(std::string &input, std::map<std::string, std::string>&);
	std::string &MyReplace( std::string &String1, std::string String2, std::string String3 );
};

