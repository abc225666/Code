#include "Link_List.h"

#include <iostream>

using namespace std;

Int_Node::Int_Node()
{
	this->pre=NULL;
	this->next=NULL;
	this->value=0;
}

Int_Node::Int_Node(int value)
{
	this->pre=NULL;
	this->next=NULL;
	this->value=value;
}

Link_List::Link_List(int inputnum)
{	
	this->head=NULL;
	this->tail=NULL;
	this->size=0;

	Int_Node* new_node=new Int_Node(inputnum);

	this->head = new_node;
	this->tail = new_node;
	this->size++;

	// for(t=0;t<count;t++)
	// {
	// 	Int_Node* new_node= new Int_Node();


	// 	if( this->head == NULL )
	// 	{
	// 		this->head=new_node;
	// 		this->tail=new_node;
	// 	}
	// 	else
	// 	{
	// 		this->tail->next=new_node;
	// 		this->tail->next->pre=this->tail;
	// 		this->tail=this->tail->next;

	// 	}

	// }
	
}

Link_List::Link_List(const Link_List &list)
{
	(*this)=list;	
}


Link_List::~Link_List()
{
	Int_Node* parser=this->head;
	Int_Node* n;
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

int Link_List::getSize() const
{
	return this->size;
}

bool Link_List::insert_node(int insert_num)
{
	try
	{
		Int_Node* new_node=new Int_Node(insert_num);
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
bool Link_List::insert_node(int position, int insert_num)
{
	try
	{
		Int_Node* new_node=new Int_Node(insert_num);
		Int_Node* parser=this->head;
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

bool Link_List::delete_node()
{
	try
	{
		if(this->tail==NULL)
			throw 0;
		else
		{
			Int_Node* temp;
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
bool Link_List::delete_node(int position)
{
	try
	{
		Int_Node* parser=this->head;
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

const Link_List &Link_List::operator=(const Link_List& list)
{
	Int_Node* new_head=NULL;
	Int_Node* new_tail=NULL;

	Int_Node* parser=list.head;

	while(parser!=NULL)
	{
		Int_Node* temp=new Int_Node(parser->value);
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

bool Link_List::operator==(const Link_List& list) const
{
	Int_Node* p1=this->head;
	Int_Node* p2=list.head;

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
int &Link_List::operator[](int index)
{
	Int_Node* parser=this->head;
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

int Link_List::operator[](int index) const
{
	Int_Node* parser=this->head;
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

istream &operator >> (istream &is, Link_List &list)
{
	int in;
	is>>in;
	
	bool ret=list.insert_node(in);

	return is;
}

ostream &operator << (ostream & os, const Link_List &list)
{
	int space=0;

	Int_Node* parser=list.head;

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



