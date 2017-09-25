// Copyright 2017 Daniel Jones. All Rights Reserved.

/* SafeVector.h
	Description:
		Safe Vector is a vector that caches new variables as well as variables that are to be deleted
*/

#pragma once

#include <vector>
#include <algorithm>
#include "Util.h"

//?
//? ─── SAFEVECTOR ─────────────────────────────────────────────────────────────────
//?


template<typename T>
class SafeVector
{
public:
	
	std::vector<T> data;
	std::vector<T> add_stack;
	
	void Add (T t);
	std::vector<T> Sort (std::vector<T>& remove_stack);
};



//?
//? ─── IMPLEMENTATION ─────────────────────────────────────────────────────────────
//?



template<typename T>
void SafeVector<T>::Add (T t)
{
	this->add_stack.push_back (t);
}


template<typename T>
std::vector<T> SafeVector<T>::Sort (std::vector<T>& remove_stack)
{
	if (add_stack.size() == 0)
	{
		return std::vector<T>();
	}
	
	
	if (remove_stack.size() > 0)
	{
		Util::RemoveVectorFromVector<T> (add_stack, remove_stack);
	}
	
	for (int i = 0; i < add_stack.size(); i++)
	{
		data.push_back (add_stack[i]);
	}
	
	std::vector<T> add_stack_copy = add_stack;
	
	add_stack.clear ();
	
	return add_stack_copy;
}


//? ────────────────────────────────────────────────────────────────────────────────
