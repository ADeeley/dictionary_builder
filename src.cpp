#include <string>
#include <iostream>
#include <sstream>

using namespace std;

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
			cout << lowerstring(word) << '\n';
			outstring << "do not ";
		}
		else if ( lowerstring(word) == "can't" )
		{
			cout << lowerstring(word) << '\n';
			outstring << "cannot ";
		}
		else if ( lowerstring(word) == "won't" )
		{
			cout << lowerstring(word) << '\n';
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
			cout << c << " Ispunct\n";
			cleanstring += ' ';
		}
		else
		{
			cout << c << " notpunct\n";
			cleanstring += c;
		}
	}
	return cleanstring;
}

int main(){
	// Depunctuation tests ====================
	cout << depunctuator("hello!") << '\n';
	cout << depunctuator(".?;,!toad!") << '\n';
	cout << depunctuator("the largest hot-to") << '\n';
	cout << depunctuator("black, berry!") << '\n';
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
	
	return 0;
}
