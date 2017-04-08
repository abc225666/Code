#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
using namespace std;

template<typename T>
struct Int_Node
{
	T value;
	Int_Node *pre, *next;
	Int_Node();
	Int_Node(T value);
};


template<typename T>
class Link_List
{
	template<typename T2>
	friend ostream &operator<<(ostream &, const Link_List<T2> &list);
	template<typename T2>
	friend istream &operator>>(istream &, Link_List<T2> &list);

public:
	Link_List( T = 10);			//default constructor
	Link_List(const Link_List &);	// copy constructor
	~Link_List();
	int getSize() const;
	
	const Link_List &operator=(const Link_List &);		// assignment operator
	bool operator==(const Link_List &) const;			// equality operator
	bool operator!=(const Link_List &right) const		// inequality operator
	{
		return !(*this == right);
	}

	T &operator[](int);								// subscript operator for non-const objects
	T operator[](int) const;							// subscript operator for const objects

	bool insert_node(T);								// insert an integer at the back of link list
	bool delete_node();									// delete the last node
	bool insert_node(int , T);						// insert an integer after the i_th position
	bool delete_node(int);								// delete the i_th node

private:
	int size;
	Int_Node<T> *head, *tail;								// pointer to the first and the last element of Link_List
};

#include "0516062_Link_List.tpp"

#endif // LINK_LIST