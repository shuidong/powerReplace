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
	std::map<std::string, std::string> wordMap;/*<�洢�滻�ؼ��ֵ�key-value */
	std::list<std::string> fileList;/*<�洢��ת���ļ��б� */
};

