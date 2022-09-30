// OOPLab2Petrov.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "Container.h"
#include "OOPLab2Petrov.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: code your application's behavior here.
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            setlocale(LC_ALL, "Russian");
            PetrovContainer library;
            while (1)
            {
                cout << "Select option:" << endl << "0. Exit" << endl << "1. Add Book" << endl << "2. Clear list" << endl << "3. Display Books" << endl << "4. Save list to file" << endl << "5. Load list from file" << endl << endl;
                int a = 0;
                cin >> a;
                switch (a)
                {
                case 0:
                {
                    return 0;
                    break;
                }
                case 1:
                {
                    library.input();
                    break;
                }
                case 2:
                {
                    library.clear();
                    break;
                }
                case 3:
                {
                    library.display();
                    break;
                }
                case 4:
                {
                    cout << "Input file name: " << endl;
                    string name;
                    cin >> name;
                    library.SaveFile(name);
                    break;
                }
                case 5:
                {
                    cout << "Input file name: " << endl;
                    string name;
                    cin >> name;
                    library.LoadFile(name);
                    break;
                }
                }
            }
        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}
