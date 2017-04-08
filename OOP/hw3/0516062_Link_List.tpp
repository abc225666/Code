//#include "Link_List.h"

#include <iostream>

using namespace std;

template<typename T>
Int_Node<T>::Int_Node()
{
	this->pre=NULL;
	this->next=NULL;
	this->value=0;
}

template<typename T>
Int_Node<T>::Int_Node(T value)
{
	this->pre=NULL;
	this->next=NULL;
	this->value=value;
}

template<typename T>
Link_List<T>::Link_List(T inputnum)
{	
	this->head=NULL;
	this->tail=NULL;
	this->size=0;

	Int_Node<T>* new_node=new Int_Node<T>(inputnum);

	this->head = new_node;
	this->tail = new_node;
	this->size++;

	
	
}

template<typename T>
Link_List<T>::Link_List(const Link_List &list)
{
	(*this)=list;	
}

template<typename T>
Link_List<T>::~Link_List()
{
	Int_Node<T>* parser=this->head;
	Int_Node<T>* n;
	//cout<<"deing\n";
	while(parser!=NULL)
	{
		if(parser->next!=NULL)
			n=parser->next;
		else
			n=NULL;
		delete parser;
		parser=n;
	}

	this->head=NULL;
	this->tail=NULL;
}

template<typename T>
int Link_List<T>::getSize() const
{
	return this->size;
}

template<typename T>
bool Link_List<T>::insert_node(T insert_num)
{
	try
	{
		Int_Node<T>* new_node=new Int_Node<T>(insert_num);
		if(this->tail==NULL)
		{
			this->head=this->tail=new_node;
		}
		else
		{
			this->tail->next=new_node;
			this->tail->next->pre=this->tail;
			this->tail=this->tail->next;
		}
		this->size++;
		return true;
	}
	catch(int err)
	{
		return false;
	}
}

//TODO
template<typename T>
bool Link_List<T>::insert_node(int position, T insert_num)
{
	try
	{
		Int_Node<T>* new_node=new Int_Node<T>(insert_num);
		Int_Node<T>* parser=this->head;
		while(position--)
		{
			if(parser==NULL)
				throw 0;
			parser=parser->next;
		}

		if(parser==NULL)
			throw 0;
		else
		{
			if(parser->next!=NULL)
			{
				parser->next->pre = new_node;
				new_node->next = parser->next;
				parser->next = new_node;
				new_node->pre = parser;
				this->size++;
			}
			else
				this->insert_node(insert_num);

		}

		


		return true;
	}
	catch(int err)
	{
		return false;
	}
}

template<typename T>
bool Link_List<T>::delete_node()
{
	try
	{
		if(this->tail==NULL)
			throw 0;
		else
		{
			Int_Node<T>* temp;
			temp=this->tail;
			this->tail=this->tail->pre;
			if(this->tail!=NULL)
				this->tail->next=NULL;
			else
				this->head=NULL;

			delete temp;
		}
		this->size--;
		return true;

	}
	catch(int err)
	{
		return false;
	}
}


//TODO
template<typename T>
bool Link_List<T>::delete_node(int position)
{
	try
	{
		Int_Node<T>* parser=this->head;
		while(position--)
		{
			if(parser==NULL)
				throw 0;
			parser=parser->next;
		}

		if(parser==NULL)
			throw 0;

		if(parser->pre!=NULL)
			parser->pre->next=parser->next;
		else
			this->head=parser->next;

		if(parser->next!=NULL)
			parser->next->pre=parser->pre;
		else
			this->tail=parser->pre;

		this->size--;
		return true;
	}
	catch(int err)
	{
		return false;
	}
}

template<typename T>
const Link_List<T> &Link_List<T>::operator=(const Link_List<T>& list)
{
	Int_Node<T>* new_head=NULL;
	Int_Node<T>* new_tail=NULL;

	Int_Node<T>* parser=list.head;

	while(parser!=NULL)
	{
		Int_Node<T>* temp=new Int_Node<T>(parser->value);
		if(new_head==NULL)
		{
			new_head=temp;
			new_tail=temp;
		}
		else
		{
			new_tail->next=temp;
			new_tail->next->pre=new_tail;
			new_tail=new_tail->next;
		}
		parser=parser->next;
	}

	this->head=new_head;
	this->tail=new_tail;
	this->size=list.getSize();

}

template<typename T>
bool Link_List<T>::operator==(const Link_List& list) const
{
	Int_Node<T>* p1=this->head;
	Int_Node<T>* p2=list.head;

	while(p1!=NULL && p2!=NULL)
	{
		if(p1->value != p2->value)
			return false;
		p1=p1->next;
		p2=p2->next;
	}

	if(p1!=p2)
	{
		return false;	
	}

	return true;

}

//TODO
template<typename T>
T &Link_List<T>::operator[](int index)
{
	Int_Node<T>* parser=this->head;
	if(index<0)
		throw 0;
	while(index--)
	{
		if(parser==NULL)
			throw 0;
		parser=parser->next;
	}

	if(parser==NULL)
		throw 0;

	return parser->value;
}

template<typename T>
T Link_List<T>::operator[](int index) const
{
	Int_Node<T>* parser=this->head;
	if(index<0)
		throw 0;
	while(index--)
	{
		if(parser==NULL)
			throw 0;
		parser=parser->next;
	}

	if(parser==NULL)
		throw 0;

	return parser->value;
}

template<typename T>
istream &operator >> (istream &is, Link_List<T> &list)
{
	T in;
	is>>in;
	
	bool ret=list.insert_node(in);

	return is;
}

template<typename T>
ostream &operator << (ostream & os, const Link_List<T> &list)
{
	int space=0;

	Int_Node<T>* parser=list.head;

	while(parser!=NULL)
	{
		if(space) os<<" ";
		else  space=1;
		os<< parser->value;
		parser=parser->next;
	}
	//os<<"\n";

	return os;
}



