#include "stdafx.h"
#include "process_modules.h"

void RussianMessage(char *message)
{
	char rmessage[256];
	CharToOemA(message, rmessage);
	std::cout << rmessage;
}

int main()
{
	process_modules pr;

	pr.print_all_process();
	
	int flag;
	do
	{
		pr.print_modules_one_process();
		RussianMessage("Хотите продолжить: 1 - Да , 0 - Нет\n");
		cin >> flag;
		if (!flag) return 0;
	} while (1);
	
	/*
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
	*/	
	return 0;
}

