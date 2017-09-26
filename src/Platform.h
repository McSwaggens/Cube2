// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Platform.h
	Description:
		OS specific preprocessor definitions
*/

#pragma once

#ifdef __linux
	
	#define LINUX
	
	#define UNIX
	
#elif __APPLE__
	
	#define OSX

	#define UNIX
	
#elif _WIN32
	
	#define WINDOWS
	
#endif