// Arkanoid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <time.h>
#include <stdlib.h>

#include "inc/Game.h"
#include "inc/Framework.h"

int main(int argc, char* argv[])
{
	int widthScreen, heightScreen;
	srand(time(NULL));
	heightScreen = widthScreen = 0;
	if (argc > 1) {

		// Finding the window size in the command-line
		char* pStrSize = nullptr;
		int i = argc - 1;
		while (i > 0 || pStrSize == nullptr) {
			if (strcmp(argv[i], "-window") == NULL) {
				pStrSize = (i + 1) < argc ? argv[i + 1] : nullptr;
			}
			i--;
		}

		// Conversion char* window size to int
		if (pStrSize != nullptr) {
			int i = 0;
			while (isdigit(pStrSize[i])) {
				widthScreen = widthScreen * 10 + int(pStrSize[i] - '0');
				i++;
			}
			i++;
			while (isdigit(pStrSize[i])) {
				heightScreen = heightScreen * 10 + int(pStrSize[i] - '0');
				i++;
			}
		}
	}

	return run(new Game(widthScreen, heightScreen));
}