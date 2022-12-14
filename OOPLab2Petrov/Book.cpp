#include "pch.h"
#include "Book.h"
#include <string>
#include "targetver.h"

using namespace std;

PetrovBook::PetrovBook()
{
}

PetrovBook::~PetrovBook()
{
}

IMPLEMENT_SERIAL(PetrovBook, CObject, 0)

void PetrovBook::create()
{
	string buff;
	cout << "Input title:" << endl;
	getline(cin >> ws, buff);
	title = buff.c_str();
	cout << "Input publishing year:" << endl;
	cin >> year;
	cout << "Input author name:" << endl;
	getline(cin >> ws, buff);
	author = buff.c_str();
	cout << endl;
}

void PetrovBook::output()
{
	cout << "Title: " << (LPCTSTR)title << endl;
	cout << "Year: " << year << endl;
	cout << "Author: " << (LPCTSTR)author << endl;
}

void PetrovBook::Serialize(CArchive& f)
{
	CObject::Serialize(f);
	if (f.IsStoring())
	{
		f << title << year << author;
	}
	else
	{
		f >> title >> year >> author;
	}
}


