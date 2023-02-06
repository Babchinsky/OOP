#pragma once
class HTML_File
{
private:
	char* filepath;

public:
	HTML_File();
	HTML_File(const char* _filepath);
	~HTML_File();

	bool Validator() const;


	void ReadPrint() const;
	void OpenInBrowser() const;
	void Input();
};