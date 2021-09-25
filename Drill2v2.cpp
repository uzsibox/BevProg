#include "std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";
	string first_name;
	cin >> first_name;
	cout << "Dear, " << first_name << " How are you? I am fine. I miss you!\n";
	cout << "Enter the name of your friend (followed by 'enter'):\n";
	string friend_name;
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately ? \n";
	char friend_sex = '0';
	cout << "What sex is " << friend_name << "  ?(m/f) \n";
	cin >> friend_sex;
	if (friend_sex == 'm') {
		cout << "If you see " << friend_name << " please ask him to call me.\n";
	}
	if (friend_sex == 'f') {
		cout << "If you see " << friend_name << " please ask her to call me.\n";

	}
	cout << "Enter the age of the recipient(followed by 'enter'):\n";
	int age = 0;
	cin >> age;
	cout << "I hear you just had a birthday and you are " << age << " years old.\n";
	if (age <= 0 || age >= 110) {
		simple_error("you're kidding!");
	}
	elseif(age < 12) {
		cout << "Next year you will be " << age + 1 << " . \n";
	}
	elseif(age == 17) {
		cout << "Next year you will be able to vote. \n";
	}
	elseif(age > 70) {
		cout << "I hope you are enjoying retirement. \n";
	}
	cout << "Yours sincerely \n\n Attila Balogh";
}