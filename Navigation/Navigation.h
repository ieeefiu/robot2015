#include <Main.h>
#include <Servo.h>
#include <Sensor.h>
#include <Follower.h>

namespace Navigate {

	bool detectedLine;
	bool detectedObject;
	bool detectedJunction;
	bool detectedBoundary;
	bool completedAboutTurn;
	bool completedModuleFunction;

	enum NavigationStates {
		NavStateInitial, 
		NavStateModuleFunction,
		NavStateEnterBoundary,
		NavStateFollowLine,
		NavStateJunctionTurn,
		NavStateExitBoundary,
		NavStateAboutTurn,
	};

	NavigationStates NavigationState = NavStateInitial;

	bool NavigationTickFunction() {
		
		switch(NavigationState)	{
		case NavStateInitial:
			NavigationState = NavStateModuleFunction;
			break;

		case NavStateModuleFunction:
			if(completedModuleFunction)
				NavigationState = NavStateModuleFunction;
			break;

		case NavStateExitBoundary:
			if(detectedObject)
				NavigationState = NavStateAboutTurn;
			else if(detectedLine)
				NavigationState = NavStateFollowLine;
			break;

		case NavStateFollowLine:
			if(detectJunction)
				NavigationState = NavStateJunctionTurn;
			else if(detectBoundary)
				NavigationState = NavStateEnterBoundary;
			break;

		case NavStateJunctionTurn:
			if(detectLine)
					NavigationState = NavStateFollowLine;
			break;

		case NavStateEnterBoundary:
			if(detectObject)
				NavigationState = NavStateModuleFunction;
			break;

		case NavStateAboutTurn:
			if(completedAboutTurn)
				NavigationState = NavStateExitBoundary;
			break;
		}

		switch(NavigationState)	{

		case NavStateInitial:		
			break;

		case NavStateModuleFunction:			
			break;

		case NavStateEnterBoundary:
			break;

		case NavStateFollowLine:
			break;

		case NavStateJunctionTurn:
			break;

		case NavStateExitBoundary:
			break;

		case NavStateAboutTurn:
			break;

		}

		return true;
	}

}
