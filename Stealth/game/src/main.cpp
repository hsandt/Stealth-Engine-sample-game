#include <cstdlib>
#include <exception>
#include <iostream>

#include "application/StealthGameApplication.h"

#define APP_WIDTH 1280
#define APP_HEIGHT 720

using namespace std;

int main(int argc, char* argv[])
{
	StealthGameApplication gameApplication;
	gameApplication.setTitle("Stealth C++");
	gameApplication.setInitialWindowSize(1280, 720);

	try {
		gameApplication.init();
		gameApplication.run();
	} catch (const exception& e) {
		cout << "[main] Exception caught: " << e.what() << endl;
		return EXIT_FAILURE;
	}

    return EXIT_SUCCESS;
}
