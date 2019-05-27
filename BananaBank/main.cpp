#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <cstdlib>
#include <sstream>

using namespace std;

int addition (int d, int e)
{
	int f;
	f = d + e;
	return f;
}

int subtraction (int g, int h)
{
	int i;
	i = g - h;
	return i;
}

float transfer (float contExpeditor){

    int sumaTransferata;
    cout << "Cat doriti sa transferati: ";
    cin >> sumaTransferata;
    if (sumaTransferata > contExpeditor)
    {
        cout << "Fonduri insuficiente!";
sumaTransferata=0;
    }
    else


cout << "\nSuma a fost transferata cu succes!";

return sumaTransferata;
}

int main(void)
{
	int a;
	float b = 10000;
	float cont2 = 500;
	string cont2cod;
	int sumTransf;
	int c;
	int j;
	const int CR = 13;
	std::string s;

	retry:
	j = 0;
	s = "0";
	cout<< "Welcome to BananaBank !!!\n"<<endl;
	cout<< "Introduceti PIN-ul: ";
    do
	{
		j = _getch();
		if (isdigit(j))
			{
				s += (char)j;
				cout << "*";
			}
	}
	while (j != CR);

	stringstream convert(s);
	if ( !(convert >> j) )
		j = 0;
	system ("CLS");

	if (j == 1234)
	{
		goto proceed;
	}
	else
	{
		system ("CLS");
		cout<< "Invalid pin.";
		system ("CLS");
		goto retry;
	}

	proceed:
	cout<< "\nSucces..........................";
	system ("CLS");

	repeat:
	cout<< "\nSelectati optiunea dorita:\n"<<endl;
	cout<< "[1] Interogare sold\n[2] Retragere\n[3] Depozitare \n[4] Transfer\n\n";
	cout<< "Optiunea dvs. este: ";
	cin>> a;
	system ("CLS");

	if (a==1)
	{
		cout<< "\nAveti in cont: " << b <<" lei";
	}
	else if (a==2)
	{
		cout<< "\nIntroduceti ce suma doriti sa retrageti: ";
		cin>> c;
		system ("CLS");
		if (c>b)
		{
			cout<< "\nFonduri insuficiente!";
		}
		else if (c<=0)
		{
			cout<< "\nEroare, suma nu poate fi mai mica de 1.";
		}
		else
		{
		b = subtraction (b, c);
		cout<< "\nTranzactie finalizata!\n Suma ramasa in cont: " << b <<" lei";
		}
	}
	else if (a==3)
	{
		cout<< "\nIntroduceti ce suma doriti sa depozitati: ";
		cin>> c;
		system ("CLS");
		if (c<=0)
		{
			cout<< "\nEroare, suma nu poate fi mai mica de 1.";
		}
		else
		{
			b = addition (b, c);
			cout<< "\nTranzactie finalizata!\n Suma curenta: " << b <<" lei";
		}
	}
	else if (a==4){
    cout << "\n Introduceti contul destinatar: ";
    cin >> cont2cod;

    sumTransf =transfer(b);
    b= subtraction (b, sumTransf);
    cont2 = addition (cont2, sumTransf);
    cout << "\n Contul destinatar are acum: " << cont2 << " lei";

	}
	else
	{
		cout<< "\n\nOptiune invalida.";
		goto repeat;
		return 0;
	}

	last:
	cout<< "\n\nDoriti sa reveniti la meniul principal?\n";
	cout<< "[1] DA\n[2] NU\n\n" << "Optiunea dvs. este: ";
	cin>>c;
	system ("CLS");
	if (c==1)
	{
		goto repeat;
	}
	else
	{
		end:
		system ("CLS");
		cout<< "\nMultumim ca ati folosit serviciile BananaBank!\nLa revedere!"<<endl;
		return 0;
	}
}
