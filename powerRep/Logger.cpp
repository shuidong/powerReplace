#include "stdafx.h"
#include "Logger.h"


Logger::Logger(void)
{
}


Logger::~Logger(void)
{
}

#include <iostream>
void Logger::debug(const char* info){
	std::cout << info << std::endl;
}

void Logger::debug(std::string info){
	std::cout << info << std::endl;
}
