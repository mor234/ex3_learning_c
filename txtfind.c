#include "workTxt.h"


int main(int argc, char* argv[]) {
	char* str = (char*)malloc(sizeof(char) * WORD);
	if (str == NULL)
		printf("error. did not succside in memory allocatin\n");
	getword(str);//get the string
	char opt = getchar();
	//getchar();//get empty line

	if (opt == 'a')
		print_lines(str);
	if (opt == 'b')
		print_similar_words(str);
	free(str);

	return 0;

}