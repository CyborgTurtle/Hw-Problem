// FILE: stringexam.cxx
// A program that runs random (but not thorough) tests on string objects.
// The tests involve only the constructors, assignment operator, length
// function, and the += operators.

#include <iostream>    // Provides cin and cout
#include <cstring>
#include "stringlist.h"  // Provides stringlist class
using namespace std;
using namespace project_stringlist;
//
enum comparison { EQUAL, NOTEQUAL, LE, GE, LESS, GREATER };
const string COMPARISON_NAMES[] = { "==", "!=", "<=", ">=", "<", ">" };
const int MANY = 6;
const string WORDS[] = {
	"t",
	"quick",
	"brown",
	"fox",
	"",
	"01234567890012345678900123456789001234567890012345678900123456789"
};

bool samelist(string s1, const node* s2)
{
	size_t i = 0;

	if (s1.length() != list_length(s2))
		return false;

	while (s2 != nullptr)
	{
		if (s1[i] != s2->data())
			return false;
		s2 = s2->nlink();

		++i;
	}

	return true;
}
////
//bool same(string s1, stringlist s2)
//{
//	size_t i;
//
//	if (s1.length() != s2.length())
//		return false;
//
//	for (i = 0; i < s1.length(); ++i)
//	{
//		if (s1[i] != s2[i])
//			return false;
//	}
//
//	return true;
//}

//bool test_comparisons(string a1, string a2, comparison which)
//{
//	stringlist s1(a1.c_str());
//	stringlist s2(a2.c_str());
//
//	switch (which)
//	{
//	case EQUAL:    return ((a1 == a2) == (s1 == s2));
//	case NOTEQUAL: return ((a1 != a2) == (s1 != s2));
//	case LE:       return ((a1 <= a2) == (s1 <= s2));
//	case GE:       return ((a1 >= a2) == (s1 >= s2));
//	case LESS:     return ((a1 < a2) == (s1 < s2));
//	case GREATER:  return ((a1 > a2) == (s1 > s2));
//	}
//	return false;
//}

int test_value_semantics(string s)
{
	stringlist s1(s.c_str());
	stringlist s2(s1);
	stringlist s3;
	stringlist s4;

	s3 = s2;
	s4 = s2;
	s4 = s2;

	return samelist(s, s1.getHeadptr()) + samelist(s, s2.getHeadptr()) + samelist(s, s3.getHeadptr()) + samelist(s, s4.getHeadptr());
}

int main()
{
	//stringlist test1("Hyeon");
	//stringlist test2(test1);
	////test2 = test1;
	//while (test2.headptr != nullptr)
	//{
	//	std::cout << test2.headptr->data();
	//	test2.headptr = test2.headptr->nlink();
	//}
	//
	int passed;       // Number of tests passed in one part of the program
	int score = 0;    // Number of tests passed overall
	int total = 0;    // Number of tests run
	int i, j, which;  // Index counters
	string s, sABC("abc");         // A string to test the += operator
	stringlist mys; // A string to test the += operator
	stringlist abc; // A string to test the += operator

					// Introductory message.
	cout << "This program runs a few tests on your string class.\n";
	cout << "Please note that most of these tests require\n";
	cout << "valid list at headptr.\n" << endl;

	// Test the constructors and assignment operator:
	cout << "Testing constructors and assignments..." << endl;
	passed = 0;
	for (i = 0; i < MANY; ++i)
	{
		if (test_value_semantics(WORDS[i]) >= 3) ++passed;
	}
	if (test_value_semantics(WORDS[i]) == 4) ++passed;
	cout << "Passed " << passed << " out of " << (MANY + 1) << "." << endl;
	score += passed;
	total += MANY + 1;

	//// Test the += operator
	//cout << "Testing the += operators..." << endl;
	//passed = 0;
	//s += 'x';
	//mys += 'x';
	//if (samelist(s, mys.getHeadptr())) ++passed;
	//for (i = 0; i < MANY; ++i)
	//{
	//	s += WORDS[i]; mys += WORDS[i].c_str();
	//	if (samelist(s, mys.getHeadptr())) ++passed;
	//}
	//s += "abc";
	//abc = "abc";
	//mys += abc;
	//if (samelist(s, mys.getHeadptr())) ++passed;
	//cout << "Passed " << passed << " out of " << MANY + 2 << "." << endl;
	//score += passed;
	//total += MANY + 2;

	//// Test the [] operator and length
	//cout << "Testing the []operator and length..." << endl;
	//passed = 0;
	//if (same(sABC, abc)) ++passed;
	//cout << "Passed " << passed << " out of 1." << endl;
	//score += passed;
	//++total;

	//// Test a self-assignment:
	//cout << "Testing a self-assignment..." << endl;
	//passed = 0;
	//s = s;
	//mys = mys;
	//if (samelist(s, mys.getHeadptr())) ++passed;
	//cout << "Passed " << passed << " out of 1." << endl;
	//score += passed;
	//++total;

	//// Test a self +=:
	//cout << "Testing a self application of the += operator..." << endl;
	//passed = 0;
	//s += s;
	//mys += mys;
	//if (samelist(s, mys.getHeadptr())) ++passed;
	//cout << "Passed " << passed << " out of 1." << endl;
	//score += passed;
	//++total;

	//// Test the Boolean operators
	//for (which = EQUAL; which <= GREATER; ++which)
	//{
	//	cout << "Testing the Boolean operator "
	//		<< COMPARISON_NAMES[which] << "..." << endl;
	//	passed = 0;
	//	for (i = 0; i < MANY; ++i)
	//		for (j = 0; j < MANY; ++j)
	//			if (test_comparisons(WORDS[i], WORDS[j], comparison(which)))
	//				++passed;
	//	if (passed == MANY * MANY)
	//	{
	//		cout << "Passed 1 out of 1." << endl;
	//		++score;
	//	}
	//	else
	//		cout << "Passed 0 out of 1." << endl;
	//	++total;
	//}

	//// Testing clear
	//cout << "Testing clear..." << endl;
	//passed = 0;
	//s.clear();
	//mys.clear();
	//if (samelist(s, mys.getHeadptr())) ++passed;
	//cout << "Passed " << passed << " out of 1." << endl;
	//score += passed;
	//++total;

	//// Testing c_str;
	//char cstr[255];
	//cout << "Testing c_str..." << endl;
	//passed = 0;
	//mys = "abc";
	//mys.c_str(cstr);
	//if (strcmp(cstr, "abc") == 0) ++passed;
	//cout << "Passed " << passed << " out of 1." << endl;
	//score += passed;
	//++total;

	//// Testing insert
	//cout << "Testing insert..." << endl;
	//passed = 0;
	//s = "abc";
	//mys = "abc";
	//s.insert(2, sABC.c_str());
	//mys.insert(2, sABC.c_str());
	//if (samelist(s, mys.getHeadptr())) ++passed;
	//cout << "Passed " << passed << " out of 1." << endl;
	//score += passed;
	//total += 1;

	//// Print results
	//cout << "Total for these little tests: "
	//	<< score << " out of " << total << "." << endl;

	return 0;
}


