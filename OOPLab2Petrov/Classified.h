#pragma once

#include "Book.h"

using namespace std;

class classified_book : public PetrovBook
{
public:
	DECLARE_SERIAL(classified_book);

	int sec_level;
	int appr_user_num;

	classified_book();
	~classified_book();

	void output();

	void create();

	void Serialize(CArchive& f);
};