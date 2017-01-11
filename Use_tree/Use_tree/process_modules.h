#pragma once
#include "binary_tree.h"

template <class T>
struct Elem;

struct Module;

struct Process;

class process_modules                
{
public:
	
	process_modules();
	
	void print_all_process();
	
	void print_modules_one_process();
	
	~process_modules();
private:
	HANDLE hStdOut;
	
	void getProcessList();

	void getModuleList(DWORD const dwProcessId, Elem <Process> *elem);

};

