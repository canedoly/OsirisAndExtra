#include "../Config.h"
#include "../Interfaces.h"
#include "../Memory.h"

#include "Tickbase.h"

#include "../SDK/Entity.h"
#include "../SDK/UserCmd.h"

int targetTickShift{ 0 };
int tickShift{ 0 };
int shiftCommand{ 0 };
int shiftedTickbase{ 0 };

int Tickbase::getCorrectTickbase(int commandNumber) noexcept
{
	const int tickBase = localPlayer->tickBase();

	if (commandNumber == shiftCommand)
		return tickBase - shiftedTickbase;
	else if (commandNumber == shiftCommand + 1)
		return tickBase + shiftedTickbase;

	return tickBase;
}

//If you have dt enabled, you need to shift 13 ticks, so it will return 13 ticks
//If you have hs enabled, you need to shift 7 ticks, so it will return 7 ticks
int Tickbase::getTargetTickShift() noexcept
{
	return targetTickShift;
}

int Tickbase::getTickshift() noexcept
{
	return tickShift;
}

void Tickbase::resetTickshift() noexcept
{
	shiftedTickbase = tickShift;
	tickShift = 0;
}