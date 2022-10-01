#include <iostream>

using namespace std;

char* f1(char* arr, int position);

char* f2(char* stroka, char s);

char* f3(char* str, int p, char c);

char* f4(char* str);

int f5(char* str5, int c);

void f6(char* str);

char* f7(char* str);

void f8(char* str);

int f9(char* str);

void f10(char* str);

int main()
{
	cout << "Task 1_____________________\n\n";
	char* str1 = new char[256];
	int n;
	gets_s(str1, 256);
	cin >> n;
	str1 = f1(str1, n);
	cout << str1 << endl;
	system("pause");
	system("cls");

	cout << "Task 2_____________________\n\n";
	char* str2 = new char[256]{ "hello world" };
	char h;
	cin >> h;
	cout <<f2(str2, h)<<endl;
	system("pause");
	system("cls");

	cout << "Task 3_____________________\n\n";
	char* str3 = new char[256]{"Hello world!"};
	int p;
	char c;
	cin >> p;
	cin >> c;
	cout<<f3(str3, p, c) << endl;
	system("pause");
	system("cls");

	cout << "Task 4_____________________\n\n";
	char* str4 = new char[256];
	gets_s(str4, 256);
	cout << f4(str4) << endl;
	system("pause");
	system("cls");

	cout << "Task 5_____________________\n\n";
	char* str5 = new char[256];
	char q;
	gets_s(str5, 256);
	cin >> q;
	cout<<f5(str5, q) << endl;
	system("pause");
	system("cls");

	cout << "Task 6_____________________\n\n";
	char* str6 = new char[256];
	gets_s(str6, 256);
	f6(str6);
	system("pause");
	system("cls");

	cout << "Task 7_____________________\n\n";
	char* str7 = new char[256];
	gets_s(str7, 256);
	cout<<f7(str7) << endl;
	system("pause");
	system("cls");

	cout << "Task 8_____________________\n\n";
	char* str8 = new char[256]{"Hello world!!!123"};
	cout << str8<<endl;
	f8(str8);
	system("pause");
	system("cls");
	
	cout << "Task 9_____________________\n\n";
	char* str9 = new char[256];
	gets_s(str9, 256);
	cout << f9(str9)<<endl;
	system("pause");
	system("cls");

	cout << "Task 10____________________\n\n";
	setlocale(LC_ALL, "");
	char* str11 = new char[256]{ "шалАш" };
	char* str12 = new char[256]{ "А роза упала на лапу Азора" };
	char* str13 = new char[256]{ "Не палиндром" };
	f10(str12);
}

char* f1(char* arr, int position) {
	char* new_arr = new char[strlen(arr) - 1];
	strncpy_s(new_arr, strlen(arr), arr, position - 1);
	strcat_s(new_arr, strlen(arr), arr + position);
	delete[]arr;
	return new_arr;

}

char* f2(char* stroka, char s) {
	char* new_stroka = new char[256]{ "" };
	char* temp_stroka;
	while (temp_stroka = strchr(stroka, s)) {
		strncat_s(new_stroka, 256, stroka,
			strlen(stroka) - strlen(temp_stroka));
		stroka = ++temp_stroka;
	}
	strcat_s(new_stroka, 256, stroka);

	return new_stroka;
}

char* f3(char* str, int p, char c) {
	char* new_str = new char[strlen(str) + 1];
	strncpy_s(new_str, p + 2, str, p + 1);
	*(new_str + p) = c;
	strcat_s(new_str, strlen(str) + 2, str + p);
	return new_str;
}

char* f4(char* str) {
	char* temp;
	while (temp = strchr(str, '.')) {
		*temp = '!';
		strcpy_s(str + (strlen(str) - strlen(temp)),
			strlen(str),
			temp);
	}
	return str;
}

int f5(char* str5, int c) {
	char* temp;
	int count = 0;
	while (temp = strchr(str5, c)) {
		count++;
		str5 = ++temp;
	}
	return count;
}

void f6(char* str) {
	int n = 0, c = 0, o = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 48 && str[i] <= 57)
			n++;
		else if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
			c++;
		else
			o++;
	}
	cout << n << " " << c << " " << o << endl;
}

char* f7(char* str) {
	char* temp;
	while (temp = strchr(str, ' ')) {
		*temp = '\t';
		strcpy_s(str + (strlen(str) - strlen(temp)),
			strlen(str),
			temp);
	}
	return str;
}

void f8(char* str) {
	int n = 0, c = 0, o = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 48 && str[i] <= 57)
			n++;
		else if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
			c++;
		else
			o++;
	}
	cout << n << " " << c << " " << o << endl;
}

int f9(char* str) {
	char* temp;
	int count = 1;
	while (temp = strchr(str, ' ')) {
		count++;
		str = ++temp;
	}
	return count;
}

void f10(char* str) {
	char* str10 = new char[256];
	for (int i = 0, j = 0; i < strlen(str) + 1; i++) {
		if (str[i] != ' ') {
			str10[j] = str[i];
			j++;
		}
	}
	delete[]str;
	if (_stricmp(str10, _strrev(str10)) == 0) std::cout << "палиндром";
	else std::cout << "Нет";
}