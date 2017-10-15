#include <cstdlib>
#include <exception>
#include <iostream>

#include "application/StealthGameApplication.h"
#include "application/RunMode.h"

#define APP_WIDTH 1280
#define APP_HEIGHT 720

using namespace std;

int main(int argc, char* argv[])
{
	StealthGameApplication gameApplication;
	gameApplication.setTitle("Stealth C++");
	gameApplication.setInitialWindowSize(1280, 720);

	// don't catch exceptions at all, so that exception can be debugged directly where it occurs
//	try {
		gameApplication.init(RunMode::Play);
		gameApplication.run();
//	} catch (const exception& e) {
//		throw;  // prefer throwing to see a message at the end
//		cout << "[main] Exception caught: " << e.what() << endl;
//		return EXIT_FAILURE;
//	}

    return EXIT_SUCCESS;
}
