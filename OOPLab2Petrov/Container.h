#pragma once

#include <vector>
#include "Book.h"
#include "Classified.h"


class PetrovContainer
{
public:
	PetrovContainer();
	~PetrovContainer();

	vector<shared_ptr<PetrovBook>> PetrovBooks;

	void input();

	void clear();

	void display();

	void SaveFile(string name);

	void LoadFile(string name);
};