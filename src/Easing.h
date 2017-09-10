// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Easing.h
	Description:
		Easing functions
*/

#pragma once

namespace Easing
{
	namespace Quad
	{
		float In (float t);
		float Out (float t);
		float InOut (float t);
	}
	
	namespace Cubic
	{
		float In (float t);
		float Out (float t);
		float InOut (float t);
	}
	
	namespace Quart
	{
		float In (float t);
		float Out (float t);
		float InOut (float t);
	}
	
	namespace Quint
	{
		float In (float t);
		float Out (float t);
		float InOut (float t);
	}
}