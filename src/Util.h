// Copyright 2017 Daniel Jones. All Rights Reserved.

/* Util.h
	Description:
		Utility methods
*/

#pragma once

#include <vector>
#include <algorithm>

namespace Util
{
	template<typename T>
	void RemoveVectorFromVector (std::vector<T>& vresult, std::vector<T>& vremove)
	{
		for (int i = 0; i < vremove.size(); i++)
		{
			T& t = vremove[i];
			vresult.erase (std::remove(vresult.begin(), vresult.end(), t), vresult.end());
		}
	}
}