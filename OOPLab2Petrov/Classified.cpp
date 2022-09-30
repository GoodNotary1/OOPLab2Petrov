#include "pch.h"
#include "Classified.h"

using namespace std;

classified_book::classified_book()
{
}

classified_book::~classified_book()
{
}

IMPLEMENT_SERIAL(classified_book, PetrovBook, 1)

void classified_book::create()
{
	PetrovBook::create();

	cout << "Input security level:" << endl;
	cin >> sec_level;
	cout << "Input number of approved users:" << endl;
	cin >> appr_user_num;
}

void classified_book::output()
{
	PetrovBook::output();

	cout << "Security level: " << sec_level << endl;
	cout << "Number of approved users: " << appr_user_num << endl;
}

void classified_book::Serialize(CArchive& f)
{
	PetrovBook::Serialize(f);
	if (f.IsStoring())
	{
		f << sec_level << appr_user_num;
	}
	else
	{
		f >> sec_level >> appr_user_num;
	}
}