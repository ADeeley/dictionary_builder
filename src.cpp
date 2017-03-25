#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>

using namespace std;

void error(string s){
	throw runtime_error(s);
}

string lowerstring(string s){
	// @pre string(s)
	// Takes in a string and converts any uppercase chars to lowercase chars.
	// @post returns string
	string newstring = "";
	for (char c : s){
		newstring += tolower(c);
	}
	return newstring;
}

/* 
string depunctuator(string s){
	// Replaces punctuation with whitespace and returns a new string. 
	string newstring {""};
	int originalStrLen {0};
	for ( char c : s)
	{
		originalStrLen += 1;

		switch ( c  )
		{
			case ( '.' ): case ( ';' ): case ( ',' ):
			case ( '?' ): case ( '-' ): case ( '!' ):
				newstring += ' '; // add whitespace
				break;
			default:
				newstring += c;
		}
	}
	return newstring;
}
*/
stringstream de_abbreviator(string s){
	// changes words with apostrophies in the given string to their equivalent 
	// full counterparts: e.g. don't will become do not.
	// @post: returns a stringstream object
	string word = "";
	stringstream instring(s);
	stringstream outstring;	
	while ( instring >> word )
	{
		if ( lowerstring(word) == "don't" )
		{
		//	cout << lowerstring(word) << '\n';
			outstring << "do not ";
		}
		else if ( lowerstring(word) == "can't" )
		{
		//	cout << lowerstring(word) << '\n';
			outstring << "cannot ";
		}
		else if ( lowerstring(word) == "won't" )
		{
		//	cout << lowerstring(word) << '\n';
			outstring << "will not ";
		}
		else 
			outstring << word << " ";
	}

	return outstring;
}

string depunctuator(string s){
	// replaces puctuation with whitespace and returns a new string
	string cleanstring = "";
	for ( char c : s )
	{
		if ( ispunct( c ) )
		{
		//	cout << c << " Ispunct\n";
			cleanstring += ' ';
		}
		else
		{
		//	cout << c << " notpunct\n";
			cleanstring += c;
		}
	}
	return cleanstring;
}

void depunctuator_tests(){
	// returns true if all tests run correctly	
	if (!( depunctuator( "hello!" ) == "hello " ) ||
		!( depunctuator( ".?;,!toad!" ) == "     toad " ) ||
		!( depunctuator( "the largest hot-to" ) == "the largest hot to" ) ||
		!( depunctuator( "black, berry!" ) == "black  berry " ) )
		error( "depuctuation failiure" );
}

// ======== dictionary declaration and members ==============

class dictionary{
	public:
		void add_word(string s);
		void print_all();
		bool in_dict(string s);
	private:
		vector<string>dict;
};

void dictionary::add_word(string s){
	dict.push_back(s);
}

void dictionary::print_all(){
	for ( string word : dict ) 
		cout << word << '\n';
}

bool dictionary::in_dict(string s){
	for ( string word : dict )
	{
		if ( word == s)
			return true;
	}
	return false;
}

int main(){
	try
	{
	depunctuator_tests();
	// De_abbreviation tests ==================
	stringstream s = de_abbreviator("don't sweat the small stuff");
	string sentence = s.str();
	cout << sentence << '\n';
	s =  de_abbreviator("You can't be serious!");
	sentence = s.str();
	cout << sentence << '\n';
	s =  de_abbreviator("Can'T WON't Don't");
	sentence = s.str();
	cout << sentence << '\n';
	}

	catch ( runtime_error& e )
	{
		cerr << "Runtime error: " << e.what() << '\n';
		return 1;
	}

	catch ( ... )
	{
		cerr << "Unknown runtime error...\n";
		return 1;
	}
	return 0;
}
