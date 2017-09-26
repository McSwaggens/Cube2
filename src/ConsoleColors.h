// Copyright 2017 Daniel Jones. All Rights Reserved.

/* ConsoleColors.h
	Description:
		Includes appropriate console color declarations based on platform.
		Also predefines the colors as blank
*/

#pragma once

#include "Platform.h"


#ifdef UNIX

	#include "ConsoleColors_UNIX.h"

#elif WINDOWS

	//TODO: Windows support for console colors

#else
	
	#define RESET		""
	#define BOLD		""
	#define UNDERLINE	""
	#define RED			""
	#define GREEN		""
	#define YELLOW		""
	#define MAGENTA		""
	#define BLUE		""
	#define CYAN		""
	#define WHITE		""
	
#endif