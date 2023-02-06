#pragma once

class var
{
private:
	int _int;
	double _double;
	char* _string;
	char typeID; // -1 - по умолчанию, 0 - int, 1 - double, 2 - string
public:
	var();
	var(const int);
	var(const double);
	var(const char*);
	var(const var&);
	~var();
	void Print()const;
	
	void SetInt(const int);
	void SetDouble(const double);
	void SetString(const char*);

	int GetInt()const;
	double GetDouble()const;
	char* GetString()const;


	//var& operator=(const var&);
	//var operator+(const int)const;
	//var& operator+(const double);
	//var& operator+(const char*);
};
//var operator+(const var&, const int);

