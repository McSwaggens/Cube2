#include "Logger.h"

std::string LoggerGetLogTypeString (unsigned char t)
{
	std::stringstream stream;
	if (t & INFO)
	{
		stream << " Info";
	}
	if (t & WARNING)
	{
		stream << " Warning";
	}
	if (t & ERROR)
	{
		stream << " Error";
	}
	if (t & DEBUG)
	{
		stream << " Debug";
	}
	
	std::string str = stream.str();
	
	str.erase(str.begin(), str.begin()+1);
	
	return str;
}

std::string LoggerGetLogTypeColor (unsigned char t)
{
	// Order the if statements from most important to least important,
	// this is to avoid the infos white color from overriding the errors red color-
	// when using multiple types in the bitflag.
	
	if (t & ERROR)
	{
		return BOLD RED;
	}
	else
	if (t & WARNING)
	{
		return BOLD YELLOW;
	}
	else
	if (t & DEBUG)
	{
		return CYAN;
	}
	else
	if (t & INFO)
	{
		return WHITE;
	}
	else
	{
		return RESET;
	}
}