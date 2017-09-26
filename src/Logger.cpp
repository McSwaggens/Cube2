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