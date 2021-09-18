#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
#include "trie.h"

int main()
{
	trie dict;
	string sample_words[12]={
	"mentor","an experienced and trusted adviser",
	"trade","buying or selling anything",
	"goat","greatest of all time :)",
	"sad","unhappy",
	"mob","crowd",
	"compassion","sympathy"
	};
	for(int i=0;i<12;i=i+2)
		dict.insert(sample_words[i],sample_words[i+1]);
	
	char c='y';
	string word;
	char meaning[40];
	int choice;
	while(c=='y')
	{
		cout<<"MENU \n1 - SEARCH WORD \n2 - ADD WORD \n3 - DELETE WORD \n4 - VIEW DICTIONARY \n\n\nENTER CHOICE : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter word to search : ";
				cin>>word;
				dict.search(word) ? cout<<"\n\n" : cout<<"Word not found \n\n";
				break;
			case 2:
				cout<<"\nEnter word to add : ";
				cin>>word;				
				cout<<"\nEnter meaning for "<<word<<" : ";
				gets(meaning);
				cin.getline(meaning,sizeof(meaning));
				dict.insert(word,meaning) ? cout<<"Word added \n\n" : cout<<"\n\nWord already present \n\n";;
				break;
			case 3:
				cout<<"\nEnter word to delete : ";
				cin>>word;
				dict.delete_word(word) ? cout<<"Deleted \n\n" : cout<<"Word not present \n\n";
				break;
			case 4:
				dict.view();
				break;	
			default:
				cout<<"Invalid choice \n\n";
				break;				
		}
		
		cout<<"do you want to continue (y/n)  ";
		cin>>c;
		system("cls");
	}
	
	return 0;
}
