#include"Animal.h"
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <array>
using namespace std;

int main()
{
	//IAnimal* ptr = nullptr;
	//ptr = new Cat("Mursik", 3.4, "Uk"); // указатель на кота
	//Cat* cat = static_cast<Cat*>(ptr);

	Cat* cat = nullptr;
	Dog* dog = nullptr;
	Pinguin* pin = nullptr;
	Dolphin* dol = nullptr;

	list<Cat> lcat;
	list<Dog> ldog;
	list<Pinguin> lpin;
	list<Dolphin> ldol;


	string _name;
	string cont;
	double k;
	int pos;
	while (true)
	{
		system("pause");
		system("cls");
		int var = 0;
		cout << "What do you want to do: \n"
			<< "1.Add animal\n"
			<< "2.Remove animal\n"
			<< "3.Search animal\n"
			<< "4.Insrert\n"
			<< "5.Print\n"
			<< "6.Search and edit\n";
		cin >> var;
		switch (var)
		{
			// 1.Add animal
		case 1:
		{
			cout << "Choose an animal:\n"
				<< "1.Cat\n"
				<< "2.Dog\n"
				<< "3.Pinguin\n"
				<< "4.Dolphin\n";
			cin >> var;
			cout << "Enter name >> kg >> continen\n";
			cin >> _name >> k >> cont;
			switch (var)
			{
				// 1.Cat
			case 1:
			{
				if (cat == nullptr)
				{
					cat = new Cat;
				}
				lcat.push_front(Cat(_name, k, cont));
				cout << "Added\n";
				break;
			}
			// 2.Dog
			case 2:
			{
				if (dog == nullptr)
				{
					dog = new Dog;
				}
				ldog.push_front(Dog(_name, k, cont));
				cout << "Added\n";
				break;
			}
			// 3.Pinguin
			case 3:
			{
				if (pin == nullptr)
				{
					pin = new Pinguin;
				}
				lpin.push_front(Pinguin(_name, k, cont));
				cout << "Added\n";
				break;
			}
			// 4.Dolphin
			case 4:
			{
				if (dol == nullptr)
				{
					dol = new Dolphin;
				}
				ldol.push_front(Dolphin(_name, k, cont));
				cout << "Added\n";
				break;
			}
			// default
			default:
			{
				cout << "Error.Missing position";
				break;
			}
			}
			break;
		}
		// 2.Remove animal
		case 2:
		{
			cout << "Choose an animal:\n"
				<< "1.Cat\n"
				<< "2.Dog\n"
				<< "3.Pinguin\n"
				<< "4.Dolphin\n";
			cin >> var;
			cout << "First = 1 or End = 2\n";
			cin >> pos;
			switch (var)
			{
				// 1.Cat
			case 1:
			{
				if (cat == nullptr)
				{
					cout << "No Cats" << endl;
					break;
				}
				if (pos == 1)
				{
					lcat.pop_front();
					break;
				}
				if (pos == 2)
				{
					lcat.pop_back();
					break;
				}
				break;
			}
			// 2.Dog
			case 2:
			{
				if (dog == nullptr)
				{
					cout << "No Cats" << endl;
					break;
				}
				if (pos == 1)
				{
					ldog.pop_front();
					break;
				}
				if (pos == 2)
				{
					ldog.pop_back();
					break;
				}
				break;
			}
			// 3.Pinguin
			case 3:
			{
				if (pin == nullptr)
				{
					cout << "No Cats" << endl;
					break;
				}
				if (pos == 1)
				{
					lpin.pop_front();
					break;
				}
				if (pos == 2)
				{
					lpin.pop_back();
					break;
				}
				break;
			}
			// 4.Dolphin
			case 4:
			{
				if (dol == nullptr)
				{
					cout << "No Cats" << endl;
					break;
				}
				if (pos == 1)
				{
					ldol.pop_front();
					break;
				}
				if (pos == 2)
				{
					ldol.pop_back();
					break;
				}
				break;
			}
			// default
			default:
			{
				cout << "Error.Missing position";
				break;
			}
			}
			break;
		}
		// 3.Search animal
		case 3:
		{
			cout << "Enter name animal: ";
			cin >> _name;
			if (cat != nullptr)
			{
				for (auto ptr = lcat.begin(); ptr != lcat.end(); ptr++)
				{
					if (ptr->GetName() == _name)
					{
						ptr->Print();
						break;
					}
				}
			}
			if (dog != nullptr)
			{
				for (auto ptr = ldog.begin(); ptr != ldog.end(); ptr++)
				{
					if (ptr->GetName() == _name)
					{
						ptr->Print();
						break;
					}
				}
			}
			if (pin != nullptr)
			{
				for (auto ptr = lpin.begin(); ptr != lpin.end(); ptr++)
				{
					if (ptr->GetName() == _name)
					{
						ptr->Print();
						break;
					}
				}
			}
			if (dol != nullptr)
			{
				for (auto ptr = ldol.begin(); ptr != ldol.end(); ptr++)
				{
					if (ptr->GetName() == _name)
					{
						ptr->Print();
						break;
					}
				}
			}
			break;
		}
		// 4.Insrert
		case 4:
		{
			cout << "Choose an animal:\n"
				<< "1.Cat\n"
				<< "2.Dog\n"
				<< "3.Pinguin\n"
				<< "4.Dolphin\n";
			cin >> var;
			cout << "Enter name >> kg >> continen\n";
			cin >> _name >> k >> cont;
			cout << "Enter position: \n"
				<< "1 - First\n"
				<< "2 - second\n"
				<< "3 - final\n";
			cin >> pos;
			switch (var)
			{
				// 1.Cat
			case 1:
			{
				if (cat == nullptr)
				{
					cout << "No cats!\n";
					break;
				}
				if (pos == 1)
				{
					lcat.insert(lcat.begin(), Cat(_name, k, cont));
					cout << "Added\n";
					break;
				}
				if (pos == 2)
				{
					lcat.insert(++lcat.begin(), Cat(_name, k, cont));
					cout << "Added\n";
					break;
				}
				if (pos == 3)
				{
					lcat.insert(--lcat.end(), Cat(_name, k, cont));
					cout << "Added\n";
					break;
				}
				break;
			}
			// 2.Dog
			case 2:
			{
				if (dog == nullptr)
				{
					cout << "No Dog!\n";
					break;
				}
				if (pos == 1)
				{
					ldog.insert(ldog.begin(), Dog(_name, k, cont));
					cout << "Added\n";
					break;
				}
				if (pos == 2)
				{
					ldog.insert(++ldog.begin(), Dog(_name, k, cont));
					cout << "Added\n";
					break;
				}
				if (pos == 3)
				{
					ldog.insert(--ldog.end(), Dog(_name, k, cont));
					cout << "Added\n";
					break;
				}
				break;
			}
			// 3.Pinguin
			case 3:
			{
				if (pin == nullptr)
				{
					cout << "No Pinguin!\n";
					break;
				}
				if (pos == 1)
				{
					lpin.insert(lpin.begin(), Pinguin(_name, k, cont));
					break;
				}
				if (pos == 2)
				{
					lpin.insert(++lpin.begin(), Pinguin(_name, k, cont));
					break;
				}
				if (pos == 3)
				{
					lpin.insert(--lpin.end(), Pinguin(_name, k, cont));
					break;
				}
				break;
			}
			// 4.Dolphin
			case 4:
			{
				if (dol == nullptr)
				{
					cout << "No Pinguin!\n";
					break;
				}
				if (pos == 1)
				{
					ldol.insert(ldol.begin(), Dolphin(_name, k, cont));
					break;
				}
				if (pos == 2)
				{
					ldol.insert(++ldol.begin(), Dolphin(_name, k, cont));
					break;
				}
				if (pos == 3)
				{
					ldol.insert(--ldol.end(), Dolphin(_name, k, cont));
					break;
				}
				break;
			}
			// default
			default:
			{
				cout << "Error.Missing position";
				break;
			}
			}
			break;
		}
		// 5.Print
		case 5:
		{
			cout << "Choose an animal:\n"
				<< "1.Cat\n"
				<< "2.Dog\n"
				<< "3.Pinguin\n"
				<< "4.Dolphin\n";
			cin >> var;
			switch (var)
			{
				// 1.Cat
			case 1:
			{
				if (cat == nullptr)
				{
					cout << "No cats\n";
					break;
				}
				else
				{
					int i = 1;
					for (auto ptr = lcat.begin(); ptr != lcat.end(); ptr++, i++)
					{
						cout << i << ": ";
						ptr->PrintStr();
					}
					cout << endl;
				}
				break;
			}
			// 2.Dog
			case 2:
			{
				if (dog == nullptr)
				{
					cout << "No dogs\n";
					break;
				}
				else
				{
					int i = 1;
					for (auto ptr = ldog.begin(); ptr != ldog.end(); ptr++, i++)
					{
						cout << i << ": ";
						ptr->PrintStr();
					}
					cout << endl;
				}
				break;
			}
			// 3.Pinguin
			case 3:
			{
				if (dog == nullptr)
				{
					cout << "No Pinguins\n";
					break;
				}
				else
				{
					int i = 1;
					for (auto ptr = lpin.begin(); ptr != lpin.end(); ptr++, i++)
					{
						cout << i << ": ";
						ptr->PrintStr();;
					}
					cout << endl;
				}
				break;
			}
			// 4.Dolphin
			case 4:
			{
				if (dol == nullptr)
				{
					cout << "No Dolphins\n";
					break;
				}
				else
				{
					int i = 1;
					for (auto ptr = ldol.begin(); ptr != ldol.end(); ptr++, i++)
					{
						cout << i << ": ";
						ptr->PrintStr();
					}
					cout << endl;
				}
				break;
			}
			// default
			default:
			{
				cout << "Error.Missing position";
				break;
			}
			}
			break;
		}
		// 6.Search and edit
		case 6:
		{
			cout << "Enter name animal: ";
			cin >> _name;
			if (cat != nullptr)
			{
				for (auto ptr = lcat.begin(); ptr != lcat.end(); ptr++)
				{
					if (ptr->GetName() == _name)
					{
						ptr->Print();
						cout << "Enter name >> kg >> continen\n";
						cin >> _name >> k >> cont;
						ptr->SetName(_name);
						ptr->SetKg(k);
						ptr->SetCont(cont);
						break;
					}
				}
			}
			if (dog != nullptr)
			{
				for (auto ptr = ldog.begin(); ptr != ldog.end(); ptr++)
				{
					if (ptr->GetName() == _name)
					{
						ptr->Print();
						cout << "Enter name >> kg >> continen\n";
						cin >> _name >> k >> cont;
						ptr->SetName(_name);
						ptr->SetKg(k);
						ptr->SetCont(cont);
						break;
					}
				}
			}
			if (pin != nullptr)
			{
				for (auto ptr = lpin.begin(); ptr != lpin.end(); ptr++)
				{
					if (ptr->GetName() == _name)
					{
						ptr->Print();
						cout << "Enter name >> kg >> continen\n";
						cin >> _name >> k >> cont;
						ptr->SetName(_name);
						ptr->SetKg(k);
						ptr->SetCont(cont);
						break;
					}
				}
			}
			if (dol != nullptr)
			{
				for (auto ptr = ldol.begin(); ptr != ldol.end(); ptr++)
				{
					if (ptr->GetName() == _name)
					{
						ptr->Print();
						cout << "Enter name >> kg >> continen\n";
						cin >> _name >> k >> cont;
						ptr->SetName(_name);
						ptr->SetKg(k);
						ptr->SetCont(cont);
						break;
					}
				}
			}
			break;
		}
		// default
		default:
		{
			cout << "Error.Missing position";
			break;
		}
		}
	}
}