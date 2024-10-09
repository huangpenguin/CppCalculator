#include "CLI_calculator.h"

void CLI_calculator::run_option(int argc, char* argv[])
{
    if (argc == 2 )
    {
        std::string arg = argv[1];
        if (arg == "--version" || arg == "-v")
        {
            displayVersion(); // F001-001, F001-002, F001-003
        }
        else if (arg == "--help" || arg == "-h")
        {
            displayHelp(); 
        }
        else
        {
            std::cerr << "unknown argument " << arg << " please refer to help: " << std::endl;
            displayHelp(); 
        }
        exit(0);
        return;
    }
    else if(argc >= 2)
    {
        std::cerr << "too many arguments, please refer to help: " << std::endl;
        displayHelp(); 
        exit(0);
        return;
    }
}

void CLI_calculator::displayVersion()
{
    std::cout << "CLICalculator 1.0.0" << std::endl; // F001-002
}

void CLI_calculator::displayHelp()
{
    std::cout << "usage: CLICal [--version|-v] [--help|-h]" << std::endl; // F002
}

void CLI_calculator::mainLoop()
{   
    std::string input;
    while (true)
    {
        std::cout << ">>> "; 
        if (!std::getline(std::cin, input)) 
        {
            if (std::cin.eof()) 
            {
                std::cout << "Exiting..." << std::endl;
                break;
            }
        }
        if (input.empty())
        {
            continue; 
        }
        try {
            Information info = parser.parse(input,calculator_memory);
            if (info.get_length() == 0)
            {
                continue;
            }

            int result = calculator.calculate(info.getTokens(), calculator_memory);
            std::cout <<"ANS=" << result << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

  
     
