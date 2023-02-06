#include "HTML_File.h"
#include <iostream>
using namespace std;



int main()
{
    HTML_File html;
    html.Input();

    if (html.Validator())
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;


    //html.ReadPrint();
    //html.OpenInBrowser();
}