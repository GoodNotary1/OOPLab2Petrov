#pragma once

#include "pch.cpp"

using namespace std;

class PetrovBook :
	public CObject
{
public:
	DECLARE_SERIAL(PetrovBook);
	CString title;
	int year;
	CString author;

	PetrovBook();
	virtual ~PetrovBook();

	virtual void output();

	virtual void create();

	virtual void Serialize(CArchive& f);
};