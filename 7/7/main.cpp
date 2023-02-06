#include <iostream>			// стандартная библиотека ввода/вывода
#include <iomanip>			// для форматированния вывода в консоль
#include <windows.h>		// для форматированния вывода в консоль
#include <ctime>			// время, для подсчёта стажа
using namespace std;		// используем пространство имён std

class Payment
{
private: // реализация
	char* full_name;						// Фамилия-Имя-Отчество				(вводим)
	short year_of_admission;				// Год поступления					(вводим)
	short allowance_percentage;				// Процент надбавки					(вводим)	Если больше проработал
	short days_worked_per_month;			// Отработанных дней в месяце		(вводим)
	short number_of_working_days;			// Количество рабочих дней в месяце (вводим)	
	int salary;								// Оклад / Грязными					(вводим)

	float accrued;							// Чистыми / Начисления суммы		(вычисляем)
	float retained;							// Удержанная сумма					(вычисляем)
	short experience;						// Cтаж								(вычисляем)

	static short withholding;				// % в пенсионный фонд				(неизменно)
	static short income_tax;				// % подоходный налог				(неизменно)

public:	// интерфейс
	Payment();													// конструктор по умолчанию
	Payment(const char*, short, short, short, short, int);		// конструктор с параметрами
	Payment(Payment&);											// конструктор с копированием
	~Payment();													// деструктор

	void Input();												// Функция ввода
	void Print()const;											// функция вывода в консоль

	float CalcRetained();										// Вычисляем удержанную сумму
	float CalcAccrued();										// Вычисляем начисленную сумму
	short CalcExperience();										// Вычисляем стаж
	
	// Set
	void SetFullName(const char*);
	void SetYearOfAdmission(short);
	void SetAllowancePercentage(short);
	void SetDaysWorkedPerMonth(short);
	void SetNumberOfWorkingDays(short);
	void SetSalary(int);
	void SetAccrued(float);
	void SetRetained(float);
	void SetExperience(short);

	// Get
	char* GetFullName()const;
	short GetYearOfAdmission()const;
	short GetAllowancePercentage()const;
	short GetDaysWorkedPerMonth()const;
	short GetNumberOfWorkingDays()const;
	int  GetSalary()const;
	float GetAccrued()const;
	float GetRetained()const;
	short GetExperience()const;
	short GetWithholding()const;
	short GetIncomeTax()const;
};

short Payment::withholding = 1;	// пенсинный фонд %
short Payment::income_tax = 13; // налог %
Payment::Payment()
{
	cout << "Contructor by default" << endl;
	full_name = nullptr;
	year_of_admission = 0;
	allowance_percentage = 0;
	days_worked_per_month = 0;
	number_of_working_days = 0;
	accrued = 0;
	salary = 0;
	experience = 0;
	retained = 0;
}
Payment::Payment(const char* _full_name, short _year_of_admission, short _allowance_percentage,
				 short _days_worked_per_month, short _number_of_working_days, int _salary)
{
	cout << "Constructor by params" << endl;
	full_name = new char[strlen(_full_name) + 1];				// выделяем память для фио, + 1 для нуль-терминатора
	strcpy_s(full_name, strlen(_full_name) + 1, _full_name);	// безопасно копируем фио

	year_of_admission = _year_of_admission;
	allowance_percentage = _allowance_percentage;
	days_worked_per_month = _days_worked_per_month;
	number_of_working_days = _number_of_working_days;
	salary = _salary;
	experience = CalcExperience();
	retained = CalcRetained();
	accrued = CalcAccrued();
}
Payment::Payment(Payment& obj)
{
	cout << "Constructor by copy" << endl;
	full_name = new char[strlen(obj.full_name) + 1];					// выделяем память для фио, + 1 для нуль-терминатора
	strcpy_s(full_name, strlen(obj.full_name) + 1, obj.full_name);		// безопасно копируем фио

	year_of_admission = obj.year_of_admission;
	allowance_percentage = obj.allowance_percentage;
	days_worked_per_month = obj.days_worked_per_month;
	number_of_working_days = obj.number_of_working_days;
	salary = obj.salary;
	experience = CalcExperience();
	retained = CalcRetained();
	accrued = CalcAccrued();
}
Payment::~Payment()
{
	cout << "Destructor" << endl;
	delete[]full_name;		// Очищаем кучу

	year_of_admission = 0;
	allowance_percentage = 0;
	days_worked_per_month = 0;
	number_of_working_days = 0;
	accrued = 0;
	salary = 0;
	experience = 0;
	retained = 0;
}

void Payment::SetFullName(const char* _full_name)
{
	if (full_name != nullptr) delete[]full_name;// проверка на наличие
	full_name = new char[strlen(_full_name) + 1];
	strcpy_s(full_name, strlen(_full_name) + 1, _full_name);
}
void Payment::SetYearOfAdmission(short _year_of_admission)
{
	year_of_admission = _year_of_admission;
}
void Payment::SetAllowancePercentage(short _allowance_percentage)
{
	allowance_percentage = _allowance_percentage;
}
void Payment::SetDaysWorkedPerMonth(short _days_worked_per_month)
{
	days_worked_per_month = _days_worked_per_month;
}
void Payment::SetNumberOfWorkingDays(short _number_of_working_days)
{
	number_of_working_days = _number_of_working_days;
}
void Payment::SetSalary(int _salary)
{
	salary = _salary;
}
void Payment::SetAccrued(float _accrued)
{
	accrued = _accrued;
}
void Payment::SetRetained(float _retained)
{
	retained = _retained;
}
void Payment::SetExperience(short _experience)
{
	experience = _experience;
}

char* Payment::GetFullName()const
{
	return full_name;
}
short Payment::GetYearOfAdmission()const
{
	return year_of_admission;
}
short Payment::GetAllowancePercentage()const
{
	return allowance_percentage;
}
short Payment::GetDaysWorkedPerMonth()const
{
	return days_worked_per_month;
}
short Payment::GetNumberOfWorkingDays()const
{
	return number_of_working_days;
}
int Payment::GetSalary()const
{
	return salary;
}
float Payment::GetAccrued()const
{
	return accrued;
}
float Payment::GetRetained()const
{
	return retained;
}
short Payment::GetExperience()const
{
	return experience;
}
short Payment::GetWithholding()const
{
	return withholding;
}
short Payment::GetIncomeTax()const
{
	return income_tax;
}

void Payment::Input()
{
	cout << setw(40) << "Фамилия-Имя-Отчество: ";
	char* buf = new char[80];
	cin.getline(buf, 80);

	if (full_name != nullptr) delete[] full_name;

	full_name = new char[strlen(buf) + 1];
	strcpy_s(full_name, strlen(buf) + 1, buf);
	delete[]buf;



	cout << setw(40) << "Год поступления: ";
	cin >> year_of_admission;
	cout << setw(40) << "Процент надбавки: ";
	cin >> allowance_percentage;
	cout << setw(40) << "Количество отработанных дней: ";
	cin >> days_worked_per_month;
	cout << setw(40) << "Количество рабочих дней в месяце: ";
	cin >> number_of_working_days;
	cout << setw(40) << "Оклад (зарплата без вычета): ";
	cin >> salary;

}
void Payment::Print()const
{
	cout << setw(35) << "ФИО: "  << full_name << endl;
	cout << setw(35) << "Год поступления: " << year_of_admission << endl;
	cout << setw(35) << "Процент надбавки: " << allowance_percentage << endl;
	cout << setw(35) << "Отработанных дней в месяце: " << days_worked_per_month << endl;
	cout << setw(35) << "Количество рабочих дней в месяце: " << number_of_working_days << endl;
	cout << setw(35) << "Пенсионный фонд: " << withholding << "%\n";
	cout << setw(35) << "Оклад: " << '$' << salary << endl;
	cout << setw(35) << "Подоходный налог: " << income_tax << "%\n\n";
	cout << setw(35) << "Начисленаа сумма: " << '$' << accrued << endl;
	cout << setw(35) << "Удержанная сумма: " << '$' << accrued << endl;
	cout << setw(35) << "Cтаж: " << experience << " лет/год(а)\n";

}

float Payment::CalcAccrued()
{
	float salary_per_day = salary * 1.00 / number_of_working_days;
	accrued = salary_per_day * days_worked_per_month * (1.0 + experience / 100.0) - retained;

	return accrued;
}
float Payment::CalcRetained()
{
	retained = salary * withholding / 100.0;									// Отчисления в пенсионный фонд
	retained += (salary - salary * withholding / 100.0) * income_tax / 100.0;	// Подоходный налог
	return retained;
}
short Payment::CalcExperience()
{
	time_t current_time;
	current_time = time(NULL);
	short current_year = 1970 + current_time / 31537970;

	experience = current_year - year_of_admission;
	return  experience;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Payment obj1("Бабчинский Алексей Павлович", 2017, 2, 19, 22, 35000);
	//obj1.Input();
	cout << endl << endl;
	Payment obj2 = obj1;
	obj2.Print();
}