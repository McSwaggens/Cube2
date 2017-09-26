// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Logger.h
	Description:
		Logs information to the terminal or to a file.
*/

#pragma once

#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <stdarg.h>


#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define FILE "[File: ", __FILENAME__, "] "
#define LINE "[Line: ", __LINE__, "] "
#define FILE_LINE "[File: ", __FILENAME__, ", Line: ", __LINE__, "] "

#define POINTER (void*)

#define FLAG 1 << 

enum LogType : unsigned char
{
	INFO			= FLAG 0, // Random information, doesn't have to be important.
	WARNING			= FLAG 1, // Possible error, probably important to know.
	ERROR			= FLAG 2, // Something has gone terribly wrong, could crash the engine.
	DEBUG			= FLAG 3, // Information that is relevant for debugging purposes.
};

#undef FLAG


std::string LoggerGetLogTypeString (unsigned char t);

//? ────────────────────────────────────────────────────────────────────────────────


inline void LoggerAdd (std::ostringstream&)
{
}

template<typename T, typename... Args>
inline void LoggerAdd (std::ostringstream& stream, T&& t, Args&&... args)
{
	stream << std::forward<T>(t);
	LoggerAdd (stream, std::forward<Args>(args)...);
}

template<typename... Args>
inline void Log (unsigned char log_type, Args&&... args)
{
	std::ostringstream stream;
	stream << "[" << LoggerGetLogTypeString(log_type) << "]" << "\t";
	LoggerAdd (stream, std::forward<Args>(args)...);
	stream << "\n";
	printf (stream.str().c_str());
}
