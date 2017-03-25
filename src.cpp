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
			outstring << lowerstring(word) << " ";
	}

	return outstring;
}


// ======== dictionary declaration and members ==============
class dictionary{
	public:
		void add_word( string s );
		void print_all();
		bool in_dict( string s );
		string depunctuator( string s );
	private:
		vector<string>dict;
};

void dictionary::add_word( string s ){
	string word { depunctuator( s ) };
	dict.push_back( word );
}

void dictionary::print_all(){
	for ( string word : dict ) 
		cout << word << '\n';
}

bool dictionary::in_dict( string s ){
	for ( string word : dict )
	{
		if ( word == s)
			return true;
	}
	return false;
}

string dictionary::depunctuator(string s){
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
	dictionary d = dictionary();
	if (!( d.depunctuator( "hello!" ) == "hello " ) ||
		!( d.depunctuator( ".?;,!toad!" ) == "     toad " ) ||
		!( d.depunctuator( "the largest hot-to" ) == "the largest hot to" ) ||
		!( d.depunctuator( "black, berry!" ) == "black  berry " ) )
		error( "depuctuation failiure" );
}

void de_abbreviator_tests(){

	stringstream s = de_abbreviator("don't sweat the small stuff");
	// cout << s.str() << '\n';
	if (!( s.str() == "do not sweat the small stuff "))
		error( "de_abbreviation failiure1" );

	s =  de_abbreviator("You can't be serious!");
	// cout << s.str() << '\n';
	if (!( s.str() == "you cannot be serious! "))
		error( "de_abbreviation failiure2" );

	s =  de_abbreviator("Can'T WON't Don't");
	// cout << s.str() << '\n';
	if (!( s.str() == "cannot will not do not "))
		error( "de_abbreviation failiure3" );
}

int main(){
	try
	{
	// tests start =================================
	//depunctuator_tests();
	//de_abbreviator_tests();
	// tests end =================================== 

	dictionary d = dictionary();
	stringstream speech {"Hello, this is your Captain speaking."};
	string word = "";
	while ( speech >> word )
	{
		d.add_word(word);
	}
	d.print_all();
	

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
