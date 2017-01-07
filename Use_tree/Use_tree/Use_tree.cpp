#include "stdafx.h"
#include "binary_tree.h"
#include "base_handle.hpp"

struct Module;

struct Process
{
	DWORD pid;      // ID process

	TCHAR name[MAX_PATH];  // name process

	vector <BYTE*> vec;    //  module adress

	Process *left = NULL,
		    *right = NULL,
		    *parent = NULL;

	bool operator<(Process& p2)
	{
		return (pid < p2.pid);
	}

	bool operator>(Process& p2)
	{
		return (pid > p2.pid);
	}
	
	bool operator!=(Process& p2)
	{
		return (pid != p2.pid);
	}

	Process& operator=(Process& p2)
	{
		pid = p2.pid;
		wcscpy_s(name, p2.name);
		vec = p2.vec;                 //???
		return *this;
	}

	friend wostream& operator <<(wostream& os, const Process& p1)
	{
		os << "ID : " << p1.pid << " Name : " << p1.name << endl;
				
		for (unsigned int i(0); i < p1.vec.size(); i++)
			os << p1.vec[i] << " ; ";

		return os;
	}
};

struct Module
{
	BYTE* pid;     // module adress 

	TCHAR name[MAX_MODULE_NAME32 + 1];  // name module

	DWORD id_proc;   // id process

	vector <DWORD> vec;  // id process

	Module *left = NULL,
		   *right = NULL,
		   *parent = NULL;

	bool operator<(Module m2)
	{
		return (pid < m2.pid);
	}

	
	bool operator>(Module m2)
	{
		return (pid > m2.pid);
	}
	
	bool operator!=(Module m2)
	{
		return (pid != m2.pid);
	}
	
	Module& operator=(Module m2)
	{
		pid = m2.pid;
		wcscpy_s(name, m2.name);
		vec = m2.vec;                 //???
		return *this;
	}

	friend wostream& operator <<(wostream& os, const Module& m1)
	{
		os << "ID : " << m1.pid << " Name : " << m1.name << endl;
		
		for (unsigned int i(0); i < m1.vec.size(); i++)
			os << m1.vec[i] << " ; ";

		return os;
	}
};

binary_tree <Process> tree_proc;
binary_tree <Module> tree_module;

void GetModuleList(HANDLE const hStdOut, DWORD const dwProcessId, Elem <Process> *elem) {
	MODULEENTRY32 meModuleEntry;
	//TCHAR szBuff[1024];
	//DWORD dwTemp;
	HANDLE CONST hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessId);
	if (INVALID_HANDLE_VALUE == hSnapshot) return;

	meModuleEntry.dwSize = sizeof(MODULEENTRY32);
	Module32First(hSnapshot, &meModuleEntry);
	do {
		/*
		wsprintf(szBuff, L"  ba: %08X, bs: %08X, %s\r\n",
		meModuleEntry.modBaseAddr, meModuleEntry.modBaseSize, meModuleEntry.szModule);
		WriteConsole(hStdOut, szBuff, lstrlen(szBuff), &dwTemp, NULL);
		*/
		Elem <Module> *elem2 = new Elem <Module>();

		elem2->data.pid = meModuleEntry.modBaseAddr;     //modul adress   
		
		elem2->data.id_proc = meModuleEntry.th32ProcessID;  // ID process

		wcscpy_s(elem2->data.name, meModuleEntry.szModule);  // module name

		if (tree_module.Search(tree_module.GetRoot(), elem2->data) == NULL)
			tree_module.Insert(elem2);                         //Insert node in tree

		elem->data.vec.push_back(meModuleEntry.modBaseAddr);   //Insert adress modul in vector processa
		
		if (elem->data.pid)                                     //Insert ID process  in modul vector
			tree_module.Search(tree_module.GetRoot(), elem2->data)->data.vec.push_back(elem->data.pid);

	} while (Module32Next(hSnapshot, &meModuleEntry));

	CloseHandle(hSnapshot);
}

VOID GetProcessList(HANDLE CONST hStdOut) {
	PROCESSENTRY32 peProcessEntry;
	//TCHAR szBuff[1024];
	//DWORD dwTemp;
	HANDLE CONST hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (INVALID_HANDLE_VALUE == hSnapshot) return;

	peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &peProcessEntry);
	do 
	{
		/*
		wsprintf(szBuff, L"=== %08X %s ===\r\n",
		peProcessEntry.th32ProcessID, peProcessEntry.szExeFile);
		WriteConsole(hStdOut, szBuff, lstrlen(szBuff), &dwTemp, NULL);
		*/
		Elem <Process> *elem = new Elem <Process>();

		elem->data.pid = peProcessEntry.th32ProcessID;    // ID process

		wcscpy_s(elem->data.name, peProcessEntry.szExeFile);   // name process

		tree_proc.Insert(elem);                              //insert in tree

		GetModuleList(hStdOut, peProcessEntry.th32ProcessID, elem);   

	} while (Process32Next(hSnapshot, &peProcessEntry));

	CloseHandle(hSnapshot);
}

int main()
{
	HANDLE CONST hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetProcessList(hStdOut);
	
	cout << "\nProcesses : \n\n";
	tree_proc.Print(tree_proc.GetRoot());
	//tree_proc.show_tree_depth();
	
	system("pause");
	cout << "\nModules : \n\n";
	tree_module.Print(tree_module.GetRoot());
	//tree_module.show_tree_depth();
	
	ExitProcess(0);
		
	return 0;
}

