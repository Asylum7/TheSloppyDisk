#include <windows.h>
#include <iostream>
using namespace std;

//Opens whatever web link string is passed into the function
void ExternalLink(string webLink)//IN - the web link to open
{
    ShellExecute(NULL, "open", webLink.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
