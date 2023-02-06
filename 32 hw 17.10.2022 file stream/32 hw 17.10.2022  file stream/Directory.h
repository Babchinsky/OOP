#pragma once
#include <string>
using namespace std;

class Directory
{
private:
	string company_name;
	string owner;
	string phone_number;
	string address;
	string occupation;
public:
	Directory();
	Directory(string _company_name, string _owner, string _phone_number, string _address, string _occupation);
	Directory(const Directory& obj);
	

	void SetCompanyName(string _company_name);
	void SetOwner(string _owner);
	void SetPhoneNumber(string _phone_number);
	void SetAddress(string _address);
	void SetOccupation(string _occupation);

	string GetCompanyName();
	string GetOwner();
	string GetPhoneNumber();
	string GetAddress();
	string GetOccupation();

	void Print();
	void Save();
	void Read();

	void SearchByCompanyName(string _company_name);
	void SearchByOwner(string _owner);
	void SearchByPhoneNumber(string _phone_number);
	void SearchByOccupation(string _occupation);
};

Directory SearchByCompanyName(string _company_name);
Directory SearchByOwner(string _owner);
Directory SearchByPhoneNumber(string _phone_number);
Directory SearchByOccupation(string _occupation);