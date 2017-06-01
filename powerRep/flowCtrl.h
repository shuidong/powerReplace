#pragma once
#include <map>
#include <list>
class flowCtrl
{
public:
	
	~flowCtrl(void);
	static flowCtrl* getInstance();
	bool loadWordMap(const char* wordMapFilePath);
	bool loadReplaceFileList(const char* replaceFilePath);
	void doJob();

private:
	flowCtrl(void);
	static flowCtrl *instance;
	std::map<std::string, std::string> wordMap;/*<存储替换关键字的key-value */
	std::list<std::string> fileList;/*<存储待转换文件列表 */
};

