#include "hangmanPlayer.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int a_z_record_all[30][26]={0};
void create_file(int length_of_word,char *word_file)
{
	char filename[12],word[30];
	if(length_of_word<10)
	{
		filename[0]=length_of_word+'0';
		filename[1]='.';
		filename[2]='t';
		filename[3]='x';
		filename[4]='t';
		filename[5]='\0';		
	}
	if(length_of_word>=10)
	{
		filename[0]=(length_of_word /10.0+'0');
		filename[1]=(length_of_word %10+'0');		
		filename[2]='.';
		filename[3]='t';
		filename[4]='x';
		filename[5]='t';
		filename[6]='\0';			
	}
			
	FILE *fp,*fp1;
	fp=fopen(word_file,"r");
	fp1=fopen(filename,"w");
	
	int i,record,j,count=0;

    while(fscanf(fp,"%s",word) != EOF)
	{
		for(j=0;j<length_of_word;j++)
		{
			if(word[j]>='A' && word[j]<='Z')
				word[j]=tolower(word[j]);
			//record=word[j]-'a';
			//a_z_record_all[length_of_word][record]++;
		}	
		if(strlen(word)==length_of_word)
		{
			//printf("word is:%s",word);
			fprintf(fp1,"%s\n",word);
		}	
	}
	/*for(i=0;i<30;i++)
	{		
		for(j=0;j<26;j++)
			printf("%d ",a_z_record_all[i][j]);
		printf("\n"); 
	}*/ 
	fclose(fp);
	fclose(fp1);
} 
void init_hangman_player(char* word_file)
{
	int i,word_length,word_total=0,longest_word=-1;
	char word[64];
	FILE *word_dictionary;
	word_dictionary=fopen(word_file,"r");
	while(fscanf(word_dictionary,"%s",word) != EOF)
	{
		word_length=strlen(word);
		word_total++;
		if(longest_word<word_length)
			longest_word=word_length;

	}
	printf("longest length is %d",longest_word);	
	fclose(word_dictionary);
	for(i=1;i<=longest_word;i++)
		create_file(i,word_file);
	//create_file(24,word_file);
	
}
int main()
{
	char filename[24];
	strcpy(filename,"words.txt");
	init_hangman_player(filename);
}
