#include "workTxt.h"

/*
Get string char by char from standart input and keep it in a string s. a line ends with '\n'
return number of char accepted.
assumes max size of string is LINE.
return -1 if contains EOF.
(assumes line end with '\n' so if recived EOF before '\n'- not a line.)
*/
int getLine(char s[])
{
	int characterNumber = 0;
	char c;
	do
	{
		/*
		if the size of the string is bigger than the length of a line,
		got bad input. (the next character is going to get out ot the size of the sting)
		return 0 as the number of gotten input

		*/
		if (characterNumber == LINE)
		{
			//error. the line is longer then LINE
			return 0;
		}
		c = s[characterNumber] = getchar();
		if (c == EOF)
			return -1;

		characterNumber++;


	} while (c != '\n');
	s[characterNumber - 1] = '\0';//put in the place of '\n'

	//printf("1, %s:", s);
	return characterNumber;
}
/*
Get string char by char from standrat input and keep in w string.
word ends with '\n','\t',' '
return number of char accepted.
assumes max size of string is WORD
return -1 if contains EOF.
(assumes word ends with '\n', '\t' or ' ' ,so if recived EOF before- not a word.)

*/
int  getword(char w[]) {

	int characterNumber = 0;
	char c;
	do
	{
		/*
		if the size of the string is bigger than the length of a word,
		got bad input. (the next character is going to get out ot the size of the string)
		return 0 as the number of gotten input;
		*/
		if (characterNumber == WORD)
		{
			//error. the word is longer then WORD
			return 0;
		}
		c = w[characterNumber] = getchar();
		if (c == EOF)
			return -1;
		characterNumber++;


	} while (c != '\n' && c != '\t' && c != ' ');
	w[characterNumber - 1] = '\0';//put in the place of '\n' , ' ' or , '\t'
	//printf("2, %s:", w);

	return characterNumber;

}
/*
* the funcion gets 2 strings and check if str2 is in the begining of str1.
* return 1 if true, 0 if false, -1 if str1 is smaller then str2
*/
int substringStart(const char* str1, const char* str2)
{
	int i = 0;
	while (str2[i] != '\0')
	{
		//if str1 ends before str2, return -1
		if (str1[i] == '\0')
			return -1;
		if (str1[i] != str2[i])
			return 0;
		i++;
	}
	return 1;

}

/*
* the funcion gets 2 strings and check if str2 is substing of str1
* return 1 if true, 0 if false
*/
int substring(const char* str1, const char* str2)
{
	int i = 0;
	while (str1[i] != '\0')
	{
		//if found the same letter, check if the subtring starts here
		if (str2[0] == str1[i])
		{
			int ans = substringStart(str1 + i, str2);
			if (ans == 1)
				return 1;
			//what remines of str1 is smaller then str2, 
			//which means there isn't any room to find str2 in str1
			if (ans == -1)
				return 0;

			//and else- continue and loo for another potantial start of the substing 

		}
		i++;


	}
	return 0;
}
/*
* The function get 2 string and integer.
* return 1 if can get from string s to string t by leaveing n characer out,
* 0 if not.
* assumes each string has '\0' at the end
*/
int similar(char* s, char* t, int n)
{
	int numberOfRemovedChar = 0;
	int tIndex = 0;
	int sIndex = 0;
	while (s[sIndex] != '\0')
	{
		//if found the next character, update the idnex and look for the next one 
		if (s[sIndex] == t[tIndex])
		{
			tIndex++;
		}
		else
		{
			numberOfRemovedChar++;//this character needs to be left out.
		}
		sIndex++;
	}
	//not found the intire t string 
	if (t[tIndex] != '\0')
		return 0;
	//if need to remove more then n characters.
	if (numberOfRemovedChar > n)
		return 0;
	return 1;
}

/*
* the function get string to look for, get the line of the text, (from standart input)
* and print the line the string appears in.
*/
void print_lines(char* str)
{
	char* line;
	for (int i = 0; i < MAX_LINE_NUMBER; i++)
	{
		line = (char*)malloc(sizeof(char) * LINE);
		if (line == NULL)
			printf("error. did not succside in memory allocatin\n");

		//printf("sent to sub string\n");
		int size = getLine(line);
		if (size > 0)
		{
			if (substring(line, str))
				printf("%s\n", line);
		}
		free(line);
		if (size < 0)
			return;//EOF
	}

}
/*
the function get string to look for, get the words of the text (from standart input), and print the words that are similar to the string
(diffrent only by loosing one letter)
*/
void print_similar_words(char* str)
{
	char* word;
	for (int i = 0; i < MAX_LINE_NUMBER; i++)
	{
		word = (char*)malloc(sizeof(char) * WORD);
		if (word == NULL)
			printf("error. did not succside in memory allocatin\n");

		int size = getword(word);
		if (size > 0)
		{
			if (similar(word, str, 1))
				printf("%s\n", word);
		}
		free(word);
		if (size < 0)
			break;//EOF
	}

}