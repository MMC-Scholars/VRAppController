#define _CRT_SECURE_NO_WARNINGS
/* Written by Michael Trunk */
/* This program acts as a pseudo-shell meant to switch between different VR applications */

#include "program_ops.h"
#include "string"
#include "iostream"
#include "stdio.h"
#include "Windows.h"



int main(int argc, const char* argv[]) {

	if (!fileExists(APP_LIST_FILENAME)) {
		printf("Failed to open file %s\n", APP_LIST_FILENAME);
		system("pause");
		return 1;
	}
	if (!loadProgramsFromFile(APP_LIST_FILENAME)) {
		system("pause");
		return 1;
	}

	printf("\n\n\n\n\n");
	//Start up SteamVR and wait a short time for it to get set up
	if (!runProgramByName(NAME_STEAMVR, false)) {
		printf("ERROR: Failed to start SteamVR\n");
		printf("%i", GetLastError());
	}
	printf("Starting the office in... ");
	sleepCountdown(STEAMVR_WAITTIME);
	runProgramByName("BOWLING");
	system("pause");

	//Now run the office
	//runProgramByName(NAME_OFFICE);
}