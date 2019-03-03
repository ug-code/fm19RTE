#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

struct CurrentMemory
{
	DWORD_PTR currentAddress;
	DWORD_PTR currentValue;
};



void About() {
	//12 no red
	//10 no green
	//7 no default color
	/*
	for (int k = 1; k < 255; k++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
		cout << k << " I want to be nice today!" << endl;
	}*/

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "----------------------------------------------------\n" << endl;
	cout << "     FM19 REAL TIME EDITOR\n" << endl;
	cout << "     Author  :   ug-code" << endl;
	cout << "     website :   https://github.com/ug-code " << endl;
	cout << "     version :   fm 19 v19.1.1 1159619 (64) \n" << endl;
	cout << "----------------------------------------------------\n\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);


}


CurrentMemory FindDmaAddy(HANDLE hProcHandle, DWORD_PTR BaseAddress, DWORD_PTR offsets[], int PointerLevel)
{
	DWORD_PTR pointer = BaseAddress;
	DWORD_PTR pTemp;
	DWORD_PTR pointerAddr;
	CurrentMemory currentMemory;
	for (int c = 0; c < PointerLevel; c++)
	{
		if (c == 0)
		{
			ReadProcessMemory(hProcHandle, (LPCVOID)pointer, &pTemp, sizeof(pTemp), NULL);
		}

		pointerAddr = pTemp + offsets[c];
		ReadProcessMemory(hProcHandle, (LPCVOID)pointerAddr, &pTemp, sizeof(pTemp), NULL);
	}
	currentMemory.currentAddress = pointerAddr;
	currentMemory.currentValue = pTemp;
	return currentMemory;
}


char readChar(HANDLE hProcess, DWORD64 address) {
	char value;
	ReadProcessMemory(hProcess, (LPVOID)address, &value, sizeof(char), NULL);
	return value;
}


char* readBuffer(HANDLE hProcess, DWORD64 address, SIZE_T size) {
	char* buffer = new char[size];
	ReadProcessMemory(hProcess, (LPVOID)address, buffer, size, NULL);
	return buffer;
}


int readInt(HANDLE hProcess, DWORD64 address) {
	DWORD_PTR tempAdress;
	ReadProcessMemory(hProcess, (LPVOID)address, &tempAdress, sizeof(address), NULL);
	return tempAdress;
}

string myInt2text(SIZE_T value) {

	string  temp = "";
	unsigned char *p = (unsigned char *)&value;

	for (int i = 0; i < sizeof(p); ++i)
	{
		temp += p[i];
	}
	return temp;
}



HANDLE GameLoad(LPCSTR windowName) {
	DWORD procID;
	HWND hwnd = FindWindowA(NULL, windowName);
	if (hwnd == NULL) {
		cout << "Cannot find windows." << endl;
		getchar();
		exit(-1);
	}
	GetWindowThreadProcessId(hwnd, &procID);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, false, procID);
	if (procID == NULL) {
		cout << "Cannot obtain process" << endl;
		getchar();
		exit(-1);
	}
	return phandle;
}


DWORD_PTR FindMemoryAddress(HANDLE pHandle, DWORD_PTR BaseAddr, DWORD_PTR  offsets[], int countOffset)
{
	DWORD_PTR tempAdress;
	ReadProcessMemory(pHandle, (VOID*)(BaseAddr), &tempAdress, sizeof(tempAdress), NULL);
	for (int i = 0; i < countOffset; i++) //Loop trough the offsets
	{
		ReadProcessMemory(pHandle, (VOID*)(tempAdress + offsets[i]), &tempAdress, sizeof(tempAdress), NULL);
	}
	//cout << "baseaddress" << hex << tempAdress << endl;

	return tempAdress;
}


int WritePointer(HANDLE pHandle, DWORD_PTR BaseAddr, int newValue, DWORD_PTR offsets[], int countOffset) {

	CurrentMemory currentMemory = FindDmaAddy(pHandle, BaseAddr, offsets, countOffset);
	//DWORD_PTR ipBaseAdress = BaseAddr + offsets[0] + offsets[1] + offsets[2] + offsets[3] + offsets[4];
	//cout << "ipBaseAdress" << hex << ammoAddr << endl;

	return WriteProcessMemory(pHandle, (VOID*)(currentMemory.currentAddress), &newValue, sizeof(newValue), NULL);
}


//delete file then create new file
ofstream fileWrite(string filename) {
	ifstream infile(filename);
	if (infile.good()) {
		remove(filename.c_str());
	}

	ofstream searchFile;
	searchFile.open(filename, std::ios_base::app);
	return searchFile;
}

//Current Folder
string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}








#endif

