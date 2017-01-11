#pragma once
#include "stdafx.h"
#include "process_modules.h"

using namespace std;

struct Process
{
	DWORD pid;      // ID process

	TCHAR name[MAX_PATH];  // name process

	vector <BYTE*> vec;    //  module adress  //vector <BYTE*> vec;

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
		vec = p2.vec;                 
		return *this;
	}

	friend wostream& operator <<(wostream& os, const Process& p1)
	{
		os << "ID : " << p1.pid << " Name : " << p1.name << endl;
		/*
		for (unsigned int i(0); i < p1.vec.size(); i++)
			os << p1.vec[i] << " ; ";
		*/
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
		vec = m2.vec;                 
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

process_modules::process_modules()
{
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	getProcessList();
}

void process_modules::getModuleList(DWORD const dwProcessId, Elem <Process> *elem) { //(HANDLE const hStdOut,
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

		                               //Insert ID process  in modul vector  //if (elem->data.pid)  
		tree_module.Search(tree_module.GetRoot(), elem2->data)->data.vec.push_back(elem->data.pid);

	} while (Module32Next(hSnapshot, &meModuleEntry));

	CloseHandle(hSnapshot);
}

void process_modules::getProcessList() {  //HANDLE CONST hStdOut
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

		getModuleList(peProcessEntry.th32ProcessID, elem);

	} while (Process32Next(hSnapshot, &peProcessEntry));

	CloseHandle(hSnapshot);
}

void process_modules::print_all_process()
{
	tree_proc.Print(tree_proc.GetRoot());
}

void process_modules::print_modules_one_process()
{
	Elem <Process> *pr;
	Elem <Module> module;
	DWORD temp;
	
	cout << "\nEnter ID process: ";
	cin >> temp;
	Elem <Process> _pr;
	_pr.data.pid = temp;
	pr = tree_proc.Search(tree_proc.GetRoot(), _pr.data);
	if (pr)
	{
		wcout << "\nProcess == " << pr->data.name << " == have modules :\n";
		for (unsigned int i(0); i < pr->data.vec.size(); i++)
		{
			module.data.pid = pr->data.vec[i];
			wcout << tree_module.Search(tree_module.GetRoot(), module.data)->data.name << endl;
			//wcout << pr->data.vec[i] << " ; ";
		}
	}
}

process_modules::~process_modules()
{
	ExitProcess(0);
}
	
