#include <cstdlib>
#include <iostream>
#include <memory>
#include "application/ApplicationContainer.h"
#include "application/GameApplication.h"

#define APP_WIDTH 1280
#define APP_HEIGHT 720

using namespace std;

int main(int argc, char* argv[])
{
#if GLFW_DLL
	std::cout << "GLFW_DLL" << std::endl;
#endif
	std::cout << "Main" << std::endl;

    ApplicationContainer applicationContainer;
    ApplicationContainer::RESULT result = applicationContainer.init(APP_WIDTH, APP_HEIGHT);
    if (result == ApplicationContainer::FAILURE)
	    return EXIT_FAILURE;

    applicationContainer.runGame(30);
    return EXIT_SUCCESS;
}
