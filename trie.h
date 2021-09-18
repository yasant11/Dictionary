#include<iostream>

using namespace std;

struct trie_node
{
	struct trie_node *collection[26];
	bool isend;
	string meaning;
};

class trie
{
	trie_node * root;
	public:
	trie()
	{
		root=getnode();
	}
	trie_node * getnode()
	{
		trie_node * temp =new trie_node;
		for(int i=0;i<26;i++)
			temp->collection[i]=NULL;
		temp->isend=false;
		return temp;
	}
	
	bool insert(string word, string meaning)
	{
		if(search(word))
			return false;
		int len=word.length();
		int index;
		trie_node * cur=root;
		for(int i=0;i<len;i++)
		{
			index=int(word[i])-int('a');
			if(cur->collection[index]==NULL)
				cur->collection[index]=getnode();
			cur=cur->collection[index];	
		}
		cur->isend=true;
		cur->meaning=meaning;
		return true;
	}
	
	bool search(string word)
	{
		int len=word.length();
		int index;
		trie_node * cur=root;
		for(int i=0;i<len;i++)
		{
			index=int(word[i])-int('a');
			if(cur->collection[index]==NULL)
				return false;
			cur=cur->collection[index];
		}
		if(!cur->isend)
			return false;
		cout<<"Meaning : "<<cur->meaning;	
		return true;
	}
	
	bool delete_word(string word)
	{
		int len=word.length();
		int index;
		trie_node * cur=root;
		for(int i=0;i<len;i++)
		{
			index=int(word[i])-int('a');
			if(cur->collection[index]==NULL)
				return false;
			cur=cur->collection[index];
		}
		if(!cur->isend)
			return false;
		cur->isend=false;
		return true;
	}	
	void viewUtil(string s,trie_node* cur)
	{
		for(int i=0;i<26;i++)
		{
			if(cur->collection[i]!=NULL)
				viewUtil(s+(char)(i+97),cur->collection[i]);
		}
		if(cur->isend==true)
			cout<<"Word : "<<s<<"\nMeaning : "<<cur->meaning<<"\n\n";
	}
	void view()
	{
		viewUtil("",root);
	}
};
