#include "CLI_calculator.h"

int main(int argc, char** argv)
{
    CLI_calculator app;
    app.run_option(argc, argv);
    app.mainLoop();
    return 0;
}
