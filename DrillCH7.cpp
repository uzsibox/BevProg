#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

struct Token //Token construktorok
{
	Token(char ch) : kind(ch), value(0) { }
	Token(char ch, double val) : kind(ch), value(val) { }
	Token(char ch, string s) : kind(ch), name(s) {}  //konstruktor hi�nyzott

	char kind;
	double value;
	string name;
};

// -----------------------------------------------------------------------------

class Token_stream //Token stream cinr�l olvas
{
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);

private:
	bool full;
	Token buffer;
};

// -----------------------------------------------------------------------------
//constans v�ltoz�k
const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char squareR = 's';
const char powCh = 'p';

const string quitKey = "exit";
const string sqrtKey = "sqrt";
const string letKey = "let";
const string powKey = "pow";

// -----------------------------------------------------------------------------

Token Token_stream::get() //Felismeri a k�l�nb�z� caseket �s switchel megfelel�len
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch)
	{
	case '(': case ')':
	case '+': case '-':
	case '*': case '/':
	case '=': case ',':
	case let: case print: case quit:
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch))
		{
			string s;
			s += ch;

			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			cin.unget();

			if (s == letKey)
				return Token(let);
			else if (s == quitKey)
				return Token(quit);
			else if (s == sqrtKey)
				return Token(squareR);
			else if (s == powKey)
				return Token(powCh);

			return Token(name, s);
		}
		error("Bad token");
	}
}

// -----------------------------------------------------------------------------

void Token_stream::ignore(char c) //T�rli a tokent a bufferb�l
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

// -----------------------------------------------------------------------------

struct Variable //V�ltoz�k deklar�l�sa
{
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

// -----------------------------------------------------------------------------

double get_value(string s) //Beolvas 
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error(s, " is undefined. Enter ';' to continue");
}

// -----------------------------------------------------------------------------

void set_value(string s, double d)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s)
		{
			names[i].value = d;
			return;
		}
	error(s, " is undefined. Enter ';' to continue");
}

// -----------------------------------------------------------------------------

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

// -----------------------------------------------------------------------------

//add {variable, value} to var_table
double define_name(string var, double val)
{
	if (is_declared(var))
		error(var, " has already been declared");
	names.push_back(Variable{ var,val });

	return val;
}

// -----------------------------------------------------------------------------

Token_stream ts;

double expression();

// -----------------------------------------------------------------------------

//handle sqrt(expression)
double squareRoot()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();

		//handle if d is 0 or negative
		if (d <= 0)
			error(to_string(d), " cannot be square routed. Enter ';' to continue");

		t = ts.get();
		if (t.kind != ')')
			error(" ')' was expected. Enter ';' to continue");
		return sqrt(d);
	}
	default:
		error(" '(' was expected. Enter ';' to continue");
	}
}

// -----------------------------------------------------------------------------

//handle pow(expression, expression)
double powpow()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression(); // first expression

		t = ts.get();
		if (t.kind != ',')
			error(" ',' was expected. Enter ';' to continue");

		double d2 = expression(); //second expression

		t = ts.get();
		if (t.kind != ')')
			error(" ')' was expected. Enter ';' to continue");

		return pow(d, d2);
	}
	default:
		error(" '(' was expected. Enter ';' to continue");
	}
}

// -----------------------------------------------------------------------------

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			error(" ')' was expected.");
		return d;
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case squareR:
		return squareRoot();
	case powCh:
		return powpow();
	default:
		error("primary expected.");
	}
}

// -----------------------------------------------------------------------------

double term()
{
	double left = primary();
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case '*':
			left *= primary();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero. Enter ';' to continue");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

// -----------------------------------------------------------------------------

double expression()
{
	double left = term();
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

// -----------------------------------------------------------------------------

double declaration()
{
	Token t = ts.get();
	if (t.kind != name)
		error("name expected in declaration. Enter ';' to continue");

	string name = t.name;
	if (is_declared(name))
		error(name, " declared twice. Enter ';' to continue");

	Token t2 = ts.get();
	if (t2.kind != '=')
		error(name, "= missing in declaration. Enter ';' to continue");

	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

// -----------------------------------------------------------------------------

double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

// -----------------------------------------------------------------------------

void clean_up_mess()
{
	ts.ignore(print);
}

// -----------------------------------------------------------------------------

const string prompt = "> ";
const string result = "= ";

// -----------------------------------------------------------------------------

void calculate()
{
	cout << prompt;

	while (true)
		try
	{
		Token t = ts.get();

		while (t.kind == print)
		{
			cout << prompt;
			t = ts.get();
		}

		if (t.kind == quit)
			return;
		ts.unget(t);

		cout << result << statement() << endl;
	}
	catch (runtime_error& e)
	{
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

// -----------------------------------------------------------------------------

int main()
try
{
	//pre-defined names
	define_name("k", 1000);

	cout << "//------------------------------------------------------------------------------//" << endl;
	cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers." << endl;
	cout << "Operators available: {}, (), +, -, /, *" << endl;
	cout << "Pre-defined names: k = 1000 || sqrt() || pow(,)" << endl;
	cout << "Define your own names using " << letKey << " name = number;" << endl;
	cout << "use ';' to print and 'Q' or 'exit' to quit" << endl;
	cout << "//------------------------------------------------------------------------------//" << endl;

	calculate();
	return 0;
}
catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...)
{
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
