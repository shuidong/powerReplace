// powerRep.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Logger.h"
#include "flowCtrl.h"
#include <iostream>
int _tmain(int argc, _TCHAR* argv[])
{
	//setlocale( LC_ALL, "UTF-8" );
	Logger::debug("make sure you have put wordMap.txt and replaceFileList.txt with exe file. ");
	flowCtrl *fc = flowCtrl::getInstance();
	Logger::debug("begin load wordMap.txt...");
	bool wordMapOk = fc->loadWordMap("./wordMap.txt");
	if(!wordMapOk){
		Logger::debug("!!can not find wordMap.txt...");
		goto LAST;
	}

	Logger::debug("begin load replaceFileList.txt...");
	bool fileListOk = fc->loadReplaceFileList("./replaceFileList.txt");
	if(!fileListOk){
		Logger::debug("!!can not find replaceFileList.txt...");
		goto LAST;
	}

	Logger::debug("begin replace...");
	fc->doJob();

LAST:
	Logger::debug("please enter a number to finish the application.");
	int exit;
	std::cin >> exit;
	return 0;
}

