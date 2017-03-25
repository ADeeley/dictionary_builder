#include <string>
#include <iostream>

using namespace std;
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
	cout << depunctuator("hello!") << '\n';
	cout << depunctuator(".?;,!toad!") << '\n';
	cout << depunctuator("the largest hot-to") << '\n';
	cout << depunctuator("black, berry!") << '\n';
	return 0;
}
