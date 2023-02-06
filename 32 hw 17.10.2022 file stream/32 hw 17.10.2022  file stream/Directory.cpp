#include "Directory.h"
#include <fstream>
#include <iostream>

Directory::Directory() = default;

Directory::Directory(string _company_name, string _owner, string _phone_number, string _address, string _occupation)
	:company_name(_company_name), owner(_owner), phone_number(_phone_number), address(_address), occupation(_occupation)
{
	cout << "Constructor by params\n";
}

Directory::Directory(const Directory& obj)
	: Directory::Directory(obj.company_name, obj.owner, obj.phone_number, obj.address, obj.occupation) 
{
	cout << "Constructor by object\n";
}

void Directory::SetCompanyName(string _company_name)
{
	company_name = _company_name;
}
void Directory::SetOwner(string _owner)
{
	owner = _owner;
}
void Directory::SetPhoneNumber(string _phone_number)
{
	phone_number = _phone_number;
}
void Directory::SetAddress(string _address)
{
	address = _address;
}
void Directory::SetOccupation(string _occupation)
{
	occupation = _occupation;
}

string Directory::GetCompanyName() 
{
	return company_name; 
}
string Directory::GetOwner() 
{ 
	return owner; 
}
string Directory::GetPhoneNumber()
{ 
	return phone_number;
}
string Directory::GetAddress()
{ 
	return address; 
}
string Directory::GetOccupation() 
{ 
	return occupation; 
}

void Directory::Print()
{
	cout << "Company name: " << company_name << endl
		 << "Owner: " << owner << endl
		 << "Phone number: " << phone_number << endl
		 << "Address: " << address << endl
		 << "Occupation: " << occupation << endl << endl;
}
void Directory::Save()
{
	ofstream save("Directory.txt", ios::app);
	save << company_name << endl
		<< owner << endl
		<< phone_number << endl
		<< address << endl
		<< occupation << endl;
	save.close();
}
void Directory::Read()
{
	Directory temp;
	ifstream print("Directory.txt");
	do
	{
		print >> temp.company_name >> temp.owner >> temp.phone_number >> temp.address >> temp.occupation;
		cout << "Company name: " << temp.company_name << endl
			<< "Owner: " << temp.owner << endl
			<< "Phone number: " << temp.phone_number << endl
			<< "Address: " << temp.address << endl
			<< "Occupation: " << temp.occupation << endl << endl;
	} while (!print.eof());
	print.close();
}

 //Методы
void Directory::SearchByCompanyName(string _company_name)
{
	// Создаём объект нашего типа
	Directory temp;

	// Создаём объект типа ifstream
	ifstream read("Directory.txt");

	while (!read.eof())
	{
		read >> temp.company_name >> temp.owner >> temp.phone_number >> temp.address >> temp.occupation;
		if (_company_name == temp.company_name)
		{
			cout << "Company name: " << temp.company_name << endl
				 << "Owner: " << temp.owner << endl
				 << "Phone number: " << temp.phone_number << endl
				 << "Address: " << temp.address << endl
				 << "Occupation: " << temp.occupation << endl << endl;
			break;
		}
	}
	// закрываем
	read.close();
}

void Directory::SearchByOwner(string _owner)
{
	// Создаём объект нашего типа
	Directory temp;

	// Создаём объект типа ifstream
	ifstream read("Directory.txt");

	while (!read.eof())
	{
		read >> temp.company_name >> temp.owner >> temp.phone_number >> temp.address >> temp.occupation;
		if (_owner == temp.owner)
		{
			cout << "Company name: " << temp.company_name << endl
				<< "Owner: " << temp.owner << endl
				<< "Phone number: " << temp.phone_number << endl
				<< "Address: " << temp.address << endl
				<< "Occupation: " << temp.occupation << endl << endl;
			break;
		}
	}
	// закрываем
	read.close();
}

void Directory::SearchByPhoneNumber(string _phone_number)
{
	// Создаём объект нашего типа
	Directory temp;

	// Создаём объект типа ifstream
	ifstream read("Directory.txt");

	while (!read.eof())
	{
		read >> temp.company_name >> temp.owner >> temp.phone_number >> temp.address >> temp.occupation;
		if (_phone_number == temp.phone_number)
		{
			cout << "Company name: " << temp.company_name << endl
				<< "Owner: " << temp.owner << endl
				<< "Phone number: " << temp.phone_number << endl
				<< "Address: " << temp.address << endl
				<< "Occupation: " << temp.occupation << endl << endl;
			break;
		}
	}
	// закрываем
	read.close();
}

void Directory::SearchByOccupation(string _occupation)
{
	// Создаём объект нашего типа
	Directory temp;

	// Создаём объект типа ifstream
	ifstream read("Directory.txt");

	while (!read.eof())
	{
		read >> temp.company_name >> temp.owner >> temp.phone_number >> temp.address >> temp.occupation;
		if (_occupation == temp.occupation)
		{
			cout << "Company name: " << temp.company_name << endl
				<< "Owner: " << temp.owner << endl
				<< "Phone number: " << temp.phone_number << endl
				<< "Address: " << temp.address << endl
				<< "Occupation: " << temp.occupation << endl << endl;
			break;
		}
	}
	// закрываем
	read.close();
}


// Функции
Directory SearchByCompanyName(string _company_name)
{
	// Создаём объект нашего типа
	Directory temp;

	string na, ow, ph, ad, oc;

	// Создаём объект типа ifstream
	ifstream read("Directory.txt");
	while (!read.eof())
	{
		read >> na >> ow >> ph >> ad >> oc;

		if (na == _company_name)
		{
			temp.SetCompanyName(na);
			temp.SetOwner(ow);
			temp.SetPhoneNumber(ph);
			temp.SetAddress(ad);
			temp.SetOccupation(oc);
			break;
		}
	}
	
	read.close();	// закрываем
	return temp;
}

Directory SearchByOwner(string _owner)
{
	// Создаём объект нашего типа
	Directory temp;

	string na, ow, ph, ad, oc;

	// Создаём объект типа ifstream
	ifstream read("Directory.txt");
	while (!read.eof())
	{
		read >> na >> ow >> ph >> ad >> oc;

		if (ow == _owner)
		{
			temp.SetCompanyName(na);
			temp.SetOwner(ow);
			temp.SetPhoneNumber(ph);
			temp.SetAddress(ad);
			temp.SetOccupation(oc);
			break;
		}
	}

	read.close();	// закрываем
	return temp;
}

Directory SearchByPhoneNumber(string _phone_number)
{
	// Создаём объект нашего типа
	Directory temp;

	string na, ow, ph, ad, oc;

	// Создаём объект типа ifstream
	ifstream read("Directory.txt");
	while (!read.eof())
	{
		read >> na >> ow >> ph >> ad >> oc;

		if (ph == _phone_number)
		{
			temp.SetCompanyName(na);
			temp.SetOwner(ow);
			temp.SetPhoneNumber(ph);
			temp.SetAddress(ad);
			temp.SetOccupation(oc);
			break;
		}
	}

	read.close();	// закрываем
	return temp;
}

Directory SearchByOccupation(string _occupation)
{
	// Создаём объект нашего типа
	Directory temp;

	string na, ow, ph, ad, oc;

	// Создаём объект типа ifstream
	ifstream read("Directory.txt");
	while (!read.eof())
	{
		read >> na >> ow >> ph >> ad >> oc;

		if (oc == _occupation)
		{
			temp.SetCompanyName(na);
			temp.SetOwner(ow);
			temp.SetPhoneNumber(ph);
			temp.SetAddress(ad);
			temp.SetOccupation(oc);
			break;
		}
	}

	read.close();	// закрываем
	return temp;
}