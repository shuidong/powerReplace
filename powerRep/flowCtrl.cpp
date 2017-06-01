#include "stdafx.h"

#include "flowCtrl.h"
#include "Logger.h"

#include <string>
flowCtrl * flowCtrl::instance = 0;

flowCtrl::flowCtrl(void)
{
}


flowCtrl::~flowCtrl(void)
{
}

flowCtrl* flowCtrl::getInstance(){
	if(flowCtrl::instance == NULL){
		flowCtrl::instance = new flowCtrl();
	}
	return flowCtrl::instance;
}

#include <fstream>
#include <iostream>
bool flowCtrl::loadWordMap(const char* wordMapFilePath){
	this->wordMap = std::map<std::string, std::string>();
	std::ifstream ifs(wordMapFilePath);
	std::string str;
	if (ifs.fail())
	{
		std::cerr << "失敗" << std::endl;
		return false;
	}

	//std::fstream fs;
	//fs.open("keywords.txt", std::ios::out);
	/*if(! fs.is_open()) {
		return EXIT_FAILURE;
	}*/

	while (getline(ifs, str))
	{
		int index = str.find("':'");
		if(index <= 0){
			continue;
		}
		std::string key = str.substr(1, index - 1);
		std::string value = str.substr(index + 3, str.length()- index - 4);
		//std::cout << key << "____" << value << "=" << str << std::endl;
		//Logger::debug(str.c_str());
		this->wordMap.insert(std::pair<std::string, std::string>("'" + key + "'", "\"" + value + "\""));
		this->wordMap.insert(std::pair<std::string, std::string>("\"" + key + "\"", "\"" + value + "\""));

		// シンプルに書き出す
		//fs << key << std::endl; // 改行。そして書き出す
		//fs << std::flush; // 書き出すだけ
	}
	//fs.close();
	return true;
}

bool flowCtrl::loadReplaceFileList(const char* replaceFilePath){
	this->fileList = std::list<std::string>();
	std::ifstream ifs(replaceFilePath);
	std::string str;
	if (ifs.fail())
	{
		std::cerr << "失敗" << std::endl;
		return false;
	}

	while (getline(ifs, str))
	{

		//std::cout << str << std::endl;
		//Logger::debug(str.c_str());
		//this->wordMap.insert(std::pair<std::string, std::string>("'" + key + "'", "\"" + value + "\""));
		this->fileList.push_back(str);
	}
	return true;
}

#include "util.h"
void flowCtrl::doJob(){
	util* util = new ::util();
	int allFileCount = this->fileList.size();
	int finishCount = 0;
	std::list<std::string>::iterator it;
	for(it=this->fileList.begin();it!=this->fileList.end();it++)
	{
		std::string tem = *it;
		std::string fileTxt = util->catFile(tem.c_str());
		
		//std::cout << fileTxt << std::endl;
		util->replaceOneByOne(fileTxt, this->wordMap);
		util->writeFile(tem.append(".luo").c_str(), fileTxt);

		finishCount++;
		std::cout << "Progress ( " << finishCount << " / " << allFileCount <<")" << std::endl;
	}
}
