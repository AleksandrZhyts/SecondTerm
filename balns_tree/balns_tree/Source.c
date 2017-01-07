#include "stdafx.h"
#include "binary_tree.h"
#include <Vector>
#include <windows.h>
#include <tlhelp32.h>
/*
struct Module;

typedef Module* PModule;


struct Process
{
HANDLE pid;
std::wstring name;
vector <PModule> vec;
};

typedef Process* PProcess;

struct Module
{
HMODULE pid;
std::wstring name;
vector <PProcess> vec;
};
*/
//binary_tree <int>tree;

/*
void init_tree(int size, int, int, int, int, int, int, int, int, int, int, int, int, int)
{
int* ptr = &size;
Elem <int>* temp;

for (int i(0); i < size; i++)
{
temp = new Elem<int>();
temp->data = *(++ptr);
tree.Insert(temp);
}
}
*/

void PrintModuleList(HANDLE const hStdOut, DWORD const dwProcessId) {
	MODULEENTRY32 meModuleEntry;
	TCHAR szBuff[1024];
	DWORD dwTemp;
	HANDLE CONST hSnapshot = CreateToolhelp32Snapshot(
		TH32CS_SNAPMODULE, dwProcessId);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return;
	}

	meModuleEntry.dwSize = sizeof(MODULEENTRY32);
	Module32First(hSnapshot, &meModuleEntry);
	do {
		wsprintf(szBuff, L"  ba: %08X, bs: %08X, %s\r\n",
			meModuleEntry.modBaseAddr, meModuleEntry.modBaseSize,
			meModuleEntry.szModule);
		WriteConsole(hStdOut, szBuff, lstrlen(szBuff), &dwTemp, NULL);
	} while (Module32Next(hSnapshot, &meModuleEntry));

	CloseHandle(hSnapshot);
}

VOID PrintProcessList(HANDLE CONST hStdOut) {
	PROCESSENTRY32 peProcessEntry;
	TCHAR szBuff[1024];
	DWORD dwTemp;
	HANDLE CONST hSnapshot = CreateToolhelp32Snapshot(
		TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return;
	}

	peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &peProcessEntry);
	do {
		wsprintf(szBuff, L"=== %08X %s ===\r\n",
			peProcessEntry.th32ProcessID, peProcessEntry.szExeFile);
		WriteConsole(hStdOut, szBuff, lstrlen(szBuff), &dwTemp, NULL);
		PrintModuleList(hStdOut, peProcessEntry.th32ProcessID);
	} while (Process32Next(hSnapshot, &peProcessEntry));

	CloseHandle(hSnapshot);
}


int main()
{
	/*
	init_tree(13, 45, 30, 50, 27, 39, 46, 90, 15, 38, 40, 70, 103, 105);

	tree.Print(tree.GetRoot());

	tree.show_tree_depth();

	system("pause");

	tree.Del(tree.Search(tree.GetRoot(), 39));

	tree.Print(tree.GetRoot());

	cout << tree.Search(tree.GetRoot(), 30)->data << endl;
	*/

	HANDLE CONST hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	PrintProcessList(hStdOut);
	ExitProcess(0);





	return 0;
}

