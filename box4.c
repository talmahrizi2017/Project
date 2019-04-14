#include "hangmanPlayer.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include<stdlib.h>
typedef struct NODE
{
	char current_word[24];
	int record_times[26];
}NODE; 
NODE wordnode[24][32400]; 
int frequence_all[24][26]={0};
int total=0;
void create_file(int length_of_word,char *word_file)
{
	int total;
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
		}	
		if(strlen(word)==length_of_word)
		{
			
			strcpy(wordnode[length_of_word-1][total].current_word ,word);
			printf("%s",wordnode[length_of_word-1][total].current_word);
			//printf("word is:%s",word);
			fprintf(fp1,"%s\n",word);
			for(j=0;j<length_of_word;j++)
			{			
				record=word[j]-'a';			
				frequence_all[length_of_word-1][record]++;	
				(wordnode[length_of_word-1][total].record_times[record])++;		
			}
			total++;
			/*for(i=0;i<52;i++)
			{
				for(j=0;j<26;j++)
				{	
					printf("times appear is:%d ",wordnode[length_of_word-1][i].record_times[j]);		
				}
				printf("\n");
			}*/						
		}	
	}
	fclose(fp);
	fclose(fp1);
} 
void init_hangman_player(char* word_file)
{
	int i,j,k,word_length,word_total=0,longest_word=-1;
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
	printf("longest length is %d\n",longest_word);	
	fclose(word_dictionary);
	for(i=0;i<24;i++)
	{
		for(j=0;j<32400;j++)
		{
			for(k=0;k<24;k++)
				wordnode[i][j].record_times[k]=0;		
		}
	}
	for(i=1;i<=longest_word;i++)
	{
		create_file(i,word_file);
		total=0;
	}
	//create_file(1,word_file);
	//total=0;
	//create_file(24,word_file);
}
int main()
{
	int i,j;
	char filename[24];
	strcpy(filename,"words.txt");
	init_hangman_player(filename);
	//for(i=0;i<24;i++)
	//{		
	//	for(j=0;j<26;j++)
	//		printf(" %d ",frequence_all[i][j]);
	//	printf("\n"); 
	//}
	
}
