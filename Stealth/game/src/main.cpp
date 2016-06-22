#include <iostream>
#include "application/ApplicationContainer.h"
#include "application/GameApplication.h"

#define APP_WIDTH 1280
#define APP_HEIGHT 720

int main(int argc, char* argv[])
{
#if GLFW_DLL
	std::cout << "GLFW_DLL" << std::endl;
#endif
	std::cout << "Main" << std::endl;

    ApplicationContainer applicationContainer;
    applicationContainer.init(APP_WIDTH, APP_HEIGHT);
    applicationContainer.runGame(30);
    return 0;
}

//-1073741515