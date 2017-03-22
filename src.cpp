#include <string>
#include <iostream>

using namespace std;
 
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

int main(){
	cout << depunctuator("hello!") << '\n';
	return 0;
}
