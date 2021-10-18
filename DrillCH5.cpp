#include "std_lib_facilities.h"
int main()
try {
	/*cout << "Success!\n"; //Nagybetû

	cout << "Success!\n"; //" hiányzó

	cout << "Success" << "!\n"; //hiányzó " ;

	cout << "success" << '\n'; //nincs success változó

	int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n"; //konverzió string->int

	vector<int> v(10); v[5] = 7; if (v[5] != 7) cout << "Success!\n"; //szögletes zárójel elemekre való hivatkozáskor successt nem írja ki

	bool cond = true; if (cond = true) cout << "Success!\n"; else cout << "Fail!\n"; //cond nincs definiálva

	bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";

	string s = "ape"; bool c = "fool" < s; if (c) cout << "Success!\n"; //boo volt bool helyett

	string s = "ape"; if (s == "fool") cout << "Success!\n";

	string s = "ape"; if (s == "fool") cout << "Success!\n"; //kimaradt  <

	string s = "ape"; if (s + "fool") cout << "Success!\n"; //kimaradt  < , s+"fool" nem konvertibilis booleanra

	vector<char> v(5); for (int i = 0; 0 < v.size(); ++i); cout << "Success!\n";

	vector<char> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";

	string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s[i];

	if (true)  cout << "Success!\n"; else cout << "Fail!\n"; //then-re nincs szükség

	int x = 2000; char c = x; if (c == 2000) cout << "Success!\n";

	string s = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s[i];

	vector<int> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n"  //int hiányzik

	int i = 0; int j = 9; while (i < 10) ++j; if (j < i) cout << "Success!\n";

	int x = 2; double d = 5 / (x - 2); if (d == 2 * x + 0.5) cout << "Success!\n"; // illegális karakter a másolt -, 0-val való osztás, c3873

	string s = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s[i]; //char tipust nem adunk meg, c3873

	int i = 0; while (i < 10) ++j; if (j < i) cout << "Success!\n"; // j nincs definiálva, c3873

	int x = 4; double d =( 5 / ( x – 2 )); if (d = 2 * x + 0.5) cout << "Success!\n";  //c3873

	cout << "Success!\n"; // cinre nem értelmezzük */
		keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}