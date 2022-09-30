#include "pch.h"
#include "Container.h"
#include <string>

using namespace std;

vector<shared_ptr<PetrovBook>> PetrovBooks;
vector<shared_ptr<PetrovBook>>::iterator it;

PetrovContainer::PetrovContainer()
{
}

PetrovContainer::~PetrovContainer()
{
	PetrovBooks.clear();
}

void PetrovContainer::input()
{
	shared_ptr<PetrovBook> temp;
	cout << "Is the book classified?" << endl << "0. No" << endl << "1. Yes" << endl;
	int a;
	cin >> a;
	cout << endl;

	switch (a)
	{
	case 0:
	{
		temp = make_shared<PetrovBook>();
		break;
	}
	case 1:
	{
		temp = make_shared<classified_book>();
		break;
	}
	}
	(*temp).create();
	PetrovBooks.push_back(temp);
}

void PetrovContainer::clear()
{
	PetrovBooks.clear();
}

void PetrovContainer::display()
{
	for (int i = 0; i < PetrovBooks.size(); i++)
	{
		PetrovBooks[i]->output();
		cout << endl;
	}
}

void PetrovContainer::SaveFile(string name)
{
	CFile file((LPCTSTR)(name.c_str()), CFile::modeCreate | CFile::modeWrite);
	CArchive f(&file, CArchive::store);

	f << PetrovBooks.size();
	
	for (auto it : PetrovBooks)
	{
		f << it.get();
	}
	f.Close();
	file.Close();
}

void PetrovContainer::LoadFile(string name)
{
	CFile file((LPCTSTR)(name.c_str()), CFile::modeRead);
	CArchive f(&file, CArchive::load);
	int n;
	int count;

	f >> count;
	f >> n;

	for (int i = 0; i < count; i++)
	{
		PetrovBook* temp = new PetrovBook;
		f >> temp;
		shared_ptr<PetrovBook> t(temp);
		PetrovBooks.push_back(t);
	}

	f.Close();
	file.Close();
}

