#include "stdafx.h"
#include "util.h"


util::util(void)
{
}


util::~util(void)
{
}

#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
std::string util::catFile(const char* filePath){
	std::ifstream ifs(filePath);
    if (ifs.fail())
    {
        std::cerr << "失敗" << std::endl;
        return "err!/*";
    }
    std::string str((std::istreambuf_iterator<char>(ifs)),
        std::istreambuf_iterator<char>());
    return str;
}

void util::writeFile(const char* filePath, std::string fileContent){
	std::fstream fs;
	fs.open(filePath, std::ios::out);
	if(! fs.is_open()) {
		return;
	}

	fs << fileContent << std::flush; // 改行。そして書き出す
	fs.close();
}

void util::replaceOneByOne(std::string &input, std::map<std::string, std::string> &keywords){
	for (std::map<std::string, std::string>::iterator it=keywords.begin(); it!=keywords.end(); ++it){
		const std::string &key = it->first;
		const std::string &value =it->second;
		this->MyReplace(input, key, value);
	}
}

//  文字列を置換する
std::string &util::MyReplace( std::string &String1, std::string String2, std::string String3 )
{
    std::string::size_type  Pos( String1.find( String2 ) );

    while( Pos != std::string::npos )
    {
        String1.replace( Pos, String2.length(), String3 );
        Pos = String1.find( String2, Pos + String3.length() );
    }

    return String1;
}