#include "HTML_File.h"

#include <stack>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

HTML_File::HTML_File()
{
	cout << "Constructor by default\n";
	filepath = nullptr;
}

HTML_File::HTML_File(const char* _filepath)
{
	cout << "Constructor by params\n";
	filepath = new char[strlen(_filepath) + 1];
	strcpy_s(filepath, strlen(_filepath) + 1, _filepath);
}

HTML_File::~HTML_File()
{
	cout << "Destructor\n";
	if (filepath != nullptr)
		delete[] filepath;
}

bool HTML_File::Validator() const
{
	const unsigned short SIZE_TAGS = 20;
	string tags[SIZE_TAGS];

	fstream html(filepath, ios::in);
	if (!html.is_open()) cout << "Could not open the file" << endl;

	unsigned short counter = 0;
	string temp;
	// write tag into array
	while (html >> temp)	// while writing
	{
		if (temp == "<html" || temp == "</html>" || temp == "<head>" || temp == "</head>" || temp == "<title>" || temp == "</title>" || temp == "<body>" || temp == "</body>")
		{
			tags[counter] = temp;
			//cout << counter++ << ": " << temp << endl;
		}
	}


	stack<string> st;
	for (size_t i = 0; i < counter; i++)
	{
		if (st.empty())
		{
			// If the stack is empty
			// just push the current tag
			st.push(tags[i]);
		}
		else if ((st.top() == "<html" && tags[i] == "</html>")
			|| (st.top() == "<body>" && tags[i] == "</body>")
			|| (st.top() == "<title>" && tags[i] == "</title>")
			|| (st.top() == "<head>" && tags[i] == "</head>")) {

			// If we found any complete pair of bracket
			// then pop
			st.pop();
		}
		else 
		{
			st.push(tags[i]);
		}
	}

	if (st.empty()) {

		// If stack is empty return true
		return true;
	}
	return false;
}

void HTML_File::Input()
{
	const short MAX_FILE_PATH = 256;
	char buffer[MAX_FILE_PATH];
	cout << "Enter filename\n->";
	cin >> buffer;

	if (filepath != nullptr) delete[] filepath;

	filepath = new char[strlen(buffer) + 1];
	strcpy_s(filepath, strlen(buffer) + 1, buffer);
}

void HTML_File::ReadPrint() const
{
	// Opening file and checking
	ifstream html(filepath);
	if (!html)
	{
		cout << "Error opening \"" << filepath << "\"\n";
		return;
	}

	// Read file
	string line;
	while (getline(html, line))
		cout << line << '\n';

	html.close();
}

void HTML_File::OpenInBrowser() const
{
	short delay = 5;
	cout << "Opening file in browser...";
	for (; delay > 0; delay--)
	{
		cout << delay;
		Sleep(1000);
		cout << "\b";
	}
	cout << "\nFile is open in browser";
	system(filepath);
}



