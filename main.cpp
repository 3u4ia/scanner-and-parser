#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include "BinaryTreeClass/BinaryTree.h"
#include "IntermediateStruct.h"


bool getInput(char [], char **, char *argv[], int);
void trim(char *, char *);
void tokenize(char *, char**, int);



int main(int argc, char* argv[]) {
	char *input;
	char textBuffer[1024] = "";
	char extension[] = ".fs25s1";
	bool didHaveArg = false;
	char *fileName;
	FILE* file = NULL;
	char cleanBuffer[1024];
	

	didHaveArg = getInput(textBuffer, &input, argv, argc);

	if(didHaveArg) {
		printf("argv[1]: %s\n", input);
		size_t fileNameSize = strlen(input) + strlen(extension);
		fileName = (char *)malloc(sizeof(char) * (fileNameSize + 1));
	
		strncpy(fileName, input, fileNameSize);
		strncat(fileName, extension, fileNameSize - strlen(extension) - 1); // -1 to give room for null terminator '\0'

		// Open File
		file = fopen(fileName, "r");
		if(file == NULL) {
			printf("%s failed to open\n", fileName);
			exit(-1);
		} else {
			// READ FROM THE FILE

			//validity checks
			if(fseek(file, 0, SEEK_END) != 0) { // Sets the File pointer to the end of the file from SEEK_END
				printf("%s failed to be seeked\n", fileName);
				exit(-1);
			}
			size_t fileSize = ftell(file); // seeks how far the file pointer is from the start of the file in bytes	
			if(fileSize > 1024) {
				printf("%s too large for textBuffer please use a different file or shorten it\n", fileName);
				exit(1);
			}
			rewind(file); // Moves the file pointer back to the start

			// The actual read
			size_t bytesRead = fread(textBuffer, 1, sizeof(textBuffer), file);
			textBuffer[bytesRead] = '\0'; // null terminating so it's a proper c string
		}
	
	}
	trim(textBuffer, cleanBuffer);

	int wordCount = 0;
	for(size_t i = 0; i < strlen(cleanBuffer); i++) {
		if(cleanBuffer[i] == ' ' || cleanBuffer[i] == '\n') {
			wordCount++;

			while(cleanBuffer[i+1] == ' ' || i>= strlen(cleanBuffer)) {
				i++;
			}
		}
	}
	if(wordCount == 0) { // If empty finish program
		printf("No words to count\n");
		exit(1);
	}
	wordCount++;

	char *arrOfTokens[wordCount]; 
	tokenize(cleanBuffer, arrOfTokens, wordCount);
	
	
	std::vector<IntermediateRep> interArr;
	bool foundCopyFlag = false;
	for(int i = 0; i < wordCount; i++) {
		for(size_t j = 0; j < interArr.size(); j++) {
			if(strcmp(arrOfTokens[i], interArr[j].word) == 0){
				interArr[j].count++;
				foundCopyFlag = true;
			}
		}
		if(!foundCopyFlag) {
			interArr.push_back(IntermediateRep{1, arrOfTokens[i]});
		}
		foundCopyFlag = false;
	}

	
	for(size_t i = 0; i < interArr.size(); i++) {
		printf("word: %s, count: %d\n", interArr[i].word, interArr[i].count);
	}

	BinaryTree treeObj;
	for(size_t i = 0; i < interArr.size(); i++) {
		treeObj.insertNode(interArr[i]);
	}

	printf("\n\n");
	treeObj.displayInOrder();

	



	if(didHaveArg) {
		free(fileName);
	}

	return 0;
}

void tokenize(char *str, char **arrayOfStrs, int tokenCount) {
	char *temp;
	temp = strtok(str, " ,\n");
	int j = 0;
	while(temp != NULL){
		if(j > tokenCount) {
			printf("Error while putting token in array\n");
			exit(-1);
		}
		arrayOfStrs[j] = temp;
		temp = strtok(NULL, " ,\n");
		j++;
	}
	return;

}


bool getInput(char textBuffer[], char **input, char *argv[], int argc) {
	char character;
	if(argc > 1) {
		*input = argv[1];
		return true;
	} else { 
		// SOMEHOW THIS TAKES THE FIRST LETTER OFF OF THE FIRST WORD???
		//if(character = getchar() == EOF) {
		//	textBuffer[0] = '\0';
		//	return false;
		//}
		while((character = getchar()) != EOF) {
			textBuffer[strlen(textBuffer)] = character;
			textBuffer[strlen(textBuffer) + 1] = '\0';
		}
		return false;
	}

}

void trim(char *src, char *dest) {
	if(!src || !dest) {
		return;
	}

	size_t length = strlen(src);

	if(!length) {
		*dest = '\0';
		return;
	}

	char *ptr = src + length - 1;

	// remove trailing
	while (ptr > src) {
		if(!isspace(*ptr)) {
			break;
		}
		ptr--;
	}

	ptr++;

	char *tmp = src;
	// remove leading
	while(tmp < ptr && isspace(*tmp)) {
		tmp++;
	}

	// Set output
	while(tmp < ptr) {
		*dest = *tmp;
		*dest++;
		*tmp++;
	}

	*dest = '\0';
}































