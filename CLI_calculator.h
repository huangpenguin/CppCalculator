
#pragma once
#include <string>
#include <vector>
#include "Parser.h"
#include "Calculator.h"
#include "Memory.h"
#include "Information.h"
#include <iostream>
#include <algorithm>
#include <cctype>

class CLI_calculator
{
public:
	CLI_calculator()=default;
	void run_option(int argc, char* argv[]);
	void mainLoop();
private:
	Memory calculator_memory;
	Parser parser;
	Calculator calculator;

	void displayVersion();
	void displayHelp();


};

