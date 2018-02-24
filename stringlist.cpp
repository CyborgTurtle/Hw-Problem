#include "stringlist.h"

project_stringlist::stringlist::stringlist(const char str[])
{
	headptr = nullptr;
	tailptr = nullptr;
	nodeCount = 0;
	while (*(str + nodeCount) != NULL) {
		++nodeCount;
	}
		if (nodeCount > 0)
			list_head_insert(headptr, str[0]);
	

	tailptr = headptr;
	if (headptr != nullptr && tailptr != nullptr) {
		for (size_t i = 1; i < nodeCount; ++i)
		{
			list_append(tailptr, str[i]);
			tailptr = tailptr->nlink();
		}
	}
	/*node* newnode = nullptr;
	list_append(newnode, str[0]);
	node* ccursor = headptr;

	for (size_t i = 1; i < strlen(str); ++i) {
		ccursor = list_append(ccursor, str[i]);
	}

*/


}

project_stringlist::stringlist::stringlist(const stringlist & source)
{
	clear();
	nodeCount = 0;
	nodeCount = source.length();
	headptr = tailptr = nullptr;
	if (nodeCount > 0)
	list_head_insert(headptr, source[0]);
	tailptr = headptr;
	if (headptr != nullptr && tailptr != nullptr) {
		for (size_t i = 1; i < nodeCount; ++i)
		{
			list_append(tailptr, source[i]);
			tailptr = tailptr->nlink();
		}
	}
	/*
	/*
	stringlist temp(source);
	node* newnode = nullptr;
	list_append(newnode, temp[0]);
	node* ccursor = headptr;

	for (size_t i = 1; i < temp.length(); ++i) {
		ccursor = list_append(ccursor, temp[i]);
	}*/
	
}


project_stringlist::stringlist::~stringlist()
{
	if (headptr != nullptr) {
		clear();
		nodeCount = 0;


	}
}

void project_stringlist::stringlist::clear()
{
	while(headptr != nullptr) {
		list_clear(headptr);
		nodeCount = 0;
	}
}
//
//void project_stringlist::stringlist::operator+=(const stringlist & addend)
//{
//	stringlist* temp= new stringlist(addend);
//	this->tailptr->set_nlink(temp->headptr);
//	temp->headptr->set_plink(headptr);
//	this->tailptr = temp->tailptr;
//	//list_piece may work instead
//
//	
//	
//
//
//}
//
//void project_stringlist::stringlist::operator+=(const char addend[])
//{
//	stringlist* temp = new stringlist(addend);
//	this->tailptr->set_nlink(temp->headptr);
//	temp->headptr->set_plink(headptr);
//	this->tailptr = temp->tailptr;
//
//	
//	
//}
//
//void project_stringlist::stringlist::operator+=(char addend)
//{
//	list_append(tailptr, addend);
//}
//
//void project_stringlist::stringlist::operator=(const stringlist & source)
//{
//	if (*this == source) {
//		return;
//
//	}
//	clear();
//	*this = source;
//}
//
//
char project_stringlist::stringlist::operator[](std::size_t position) const
{
	//return (list_locate(headptr, position)->data());
	node* temp = headptr;
	for (size_t i = 0; i < position; ++i)
		temp = temp->nlink();
	return temp->data();
}
//
void project_stringlist::stringlist::c_str(char * s) const
{
	for (size_t i = 0; i < strlen(s); i++) {
		s[i] = this->operator[](i);

	}
}

//int project_stringlist::stringlist::strcmp(const stringlist & right) const
//{
//	node* lcursor = this->headptr;
//	node* rcursor = right.headptr;
//
//	while (lcursor != nullptr && rcursor != nullptr) {
////         -1	the first character that does not match has a lower value in *this than in right
//		if (lcursor->data() < rcursor->data()) {
//			return -1;
//		}
//
//
//		
//		 
//		//         0	the contents of both strings are equal
//		if (lcursor->data() == rcursor->data()) {
//			return 0;
//		}
//
//		//         1	the first character that does not match has a greater value in *this than in right
//		if (lcursor->data() > rcursor->data()) {
//			return 1;
//		}
//		lcursor = lcursor->nlink();
//		rcursor = rcursor->nlink();
//
//		
//	}
//}

