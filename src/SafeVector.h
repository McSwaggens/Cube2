// Copyright 2017 Daniel Jones. All Rights Reserved.

/* SafeVector.h
	Description:
		Safe Vector is a vector that caches new variables as well as variables that are to be deleted
*/

#pragma once

#include <vector>
#include <algorithm>

//?
//? ─── SAFEVECTOR ─────────────────────────────────────────────────────────────────
//?


template<typename T>
class SafeVector
{
public:
	
	std::vector<T> data;
	
	void Add (T t);
	void Remove (T t);
	
	std::vector<T> Sort ();
	
private:
	
	std::vector<T> remove_stack;
	std::vector<T> add_stack;
	
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
void SafeVector<T>::Remove (T t)
{
	this->remove_stack.push_back (t);
}


template<typename T>
std::vector<T> SafeVector<T>::Sort ()
{
	
	for (int i = 0; i < add_stack.size(); i++)
	{
		data.push_back (add_stack[i]);
	}
	
	for (int i = 0; i < remove_stack.size(); i++)
	{
		data.erase (std::remove(data.begin (), data.end (), remove_stack[i]), data.end());
	}
	
	std::vector<T> add_stack_copy = add_stack;
	
	remove_stack.clear ();
	add_stack.clear ();
	
	return add_stack_copy;
}


//? ────────────────────────────────────────────────────────────────────────────────
