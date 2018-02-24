// FILE: stringlist.h
// CLASS PROVIDED: stringlist (a sequence of characters)
//
// CONSTRUCTOR for the stringlist class:
//   stringlist(const char str[ ] = "") -- default argument is the empty string.
//     Precondition: str is an ordinary null-terminated string.
//     Postcondition: The string contains the sequence of chars from str.
//
// CONSTANT MEMBER FUNCTIONS for the stringlist class:
//   size_t length( ) const
//     Postcondition: The return value is the number of characters in the string.
//
//   char operator [ ](size_t position) const
//     Precondition: position < length( ).
//     Postcondition: The value returned is the character at the specified
//     position of the string. A string's positions start from 0 at the start
//     of the sequence and go up to length( )-1 at the right end.
//
//   void c_str(char * s) const
//     Precondition: At least this->length()+1 bytes available at s
//	   Postcondition:  Copies to s a null-terminated sequence of characters (i.e., a C-string)
//       representing the current value of the stringlist object.
//
//   int strcmp(const stringlist& right) const
//	   Precondition: none
//	   Postcondition: Returns an integral value indicating the relationship between the strings:
//       return value	indicates
//         -1	the first character that does not match has a lower value in *this than in right
//         0	the contents of both strings are equal
//         1	the first character that does not match has a greater value in *this than in right
//
// MODIFICATION MEMBER FUNCTIONS for the stringlist class:
//   void clear()
//	   Erases the contents of the stringlist, which becomes an empty string (with a length of 0 characters).
//
//   void operator +=(const string& addend)
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(const char addend[ ])
//     Precondition: addend is an ordinary null-terminated string.
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(char addend)
//     Postcondition: The single character addend has been catenated to the
//     end of the string.
//
//   stringlist& insert (size_t pos, const char* s, size_t n)
//     Precondition: pos >= 0 <= this->length() and n <= strlen(s)
//     Postcondition: Inserts additional characters into the stringlist right before the character indicated by pos (or p).
//       The first character is denoted by a value of 0 (not 1).
//       n: Number of characters to insert.
//       returns *this.
//
//   stringlist& insert (size_t pos, const char* s)
//     Precondition: pos >= 0 <= this->length()
//     Postcondition: Inserts additional characters into the stringlist right before the character indicated by pos (or p).
//       The first character is denoted by a value of 0 (not 1).
//		 All of s is inserted into the stringlist.
//       returns *this.
//
// NON-MEMBER FUNCTIONS for the stringlist class:
//   stringlist operator +(const stringlist& s1, const stringlist& s2)
//     Postcondition: The string returned is the catenation of s1 and s2.
//
//   istream& operator >>(istream& ins, stringlist& target)
//     Postcondition: A string has been read from the istream ins, and the
//     istream ins is then returned by the function. The reading operation
//     skips white space (i.e., blanks, newlines, tabs) at the start of ins.
//     Then the string is read up to the next white space or the end of the
//     file. The white space character that terminates the string has not
//     been read.
//
//   ostream& operator <<(ostream& outs, const stringlist& source)
//     Postcondition: The sequence of characters in source has been written
//     to outs. The return value is the ostream outs.
//
//   void getline(istream& ins, stringlist& target)
//     Postcondition: A string has been read from the istream ins. The reading
//     operation reads all characters (including white space) until a newline
//     or end of file is encountered. The newline character is read and
//     discarded (but not added to the end of the string).
//
//  VALUE SEMANTICS for the stringlist class:
//    Assignments and the copy constructor may be used with stringlist objects.
//
//  TOTAL ORDER SEMANTICS for the stringlist class:
//    The six comparison operators (==, !=, >=, <=, >, and <) are implemented
//    for the stringlist class, forming a total order semantics, using the usual
//    lexicographic order on stringlists.
//
// DYNAMIC MEMORY usage by the stringlist class:
//   If there is insufficient dynamic memory then the following functions call
//   new_handler: The constructors, reserve, operator +=, operator +, and the
//   assignment operator.

#ifndef STRINGLIST_H
#define STRINGLIST_H
#include <cstdlib>  // Provides size_t
#include <iostream>  // Provides ostream & istream
#include "node1d.h"

namespace project_stringlist
{
	class stringlist
	{
	public:
		// CONSTRUCTORS and DESTRUCTOR
		stringlist(const char str[] = "");
		stringlist(const stringlist& source);
		~stringlist();
		//// MODIFICATION MEMBER FUNCTIONS
		void clear();
		//void operator +=(const stringlist& addend);
		//void operator +=(const char addend[]);
		//void operator +=(char addend);
		//void operator =(const stringlist& source);
		//stringlist& insert(size_t pos, const char* s);
		//stringlist& insert(size_t pos, const char* s, size_t n);

		//// CONSTANT MEMBER FUNCTIONS
		bool empty() const { return nodeCount == 0; };
		std::size_t length() const { return nodeCount; };
		char operator [ ](std::size_t position) const;
		void c_str(char * s) const;
		/*int strcmp(const stringlist& right) const;*/

		//A function that can be utilized by the comparison operators, since they are not friends this time
		const node* getHeadptr() const { return headptr; };

		// FRIEND FUNCTIONS
		//friend std::ostream& operator <<(std::ostream& outs, const stringlist& source);
	//private:
		node * headptr;
		node* tailptr;
		size_t nodeCount;
	};

	// NON-MEMBER FUNCTIONS for the stringlist class
	//bool operator ==(const stringlist& s1, const stringlist& s2);
	//bool operator !=(const stringlist& s1, const stringlist& s2);
	//bool operator >=(const stringlist& s1, const stringlist& s2);
	//bool operator <=(const stringlist& s1, const stringlist& s2);
	//bool operator > (const stringlist& s1, const stringlist& s2);
	//bool operator < (const stringlist& s1, const stringlist& s2);
	//stringlist operator +(const stringlist& s1, const stringlist& s2);
	//std::istream& operator >>(std::istream& ins, stringlist& target);
	//std::istream& getline(std::istream& ins, stringlist& target);
}

#endif