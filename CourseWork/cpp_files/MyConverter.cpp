#include "../h_files/MyConverter.h"

bool ConvertStrToInt(const string& from, int& to)
{
	to = 0;
	char* tmp = new char[100]{};
	char* p_tmp = tmp;
	for (const char& it : from) {
		if (it < '0' || it > '9') {
			delete p_tmp;
			//delete[] tmp;
			cout << "Fail type: \"" + from + "\" Try it again: ";
			return false;
		}
		*tmp = it;
		tmp++;
	}
	to = atoi(p_tmp);
	//delete[] tmp; почему то не работает, хз почему, но оставлю на всякий случай
	delete p_tmp;

	return true;
}
