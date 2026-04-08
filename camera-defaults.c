#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "camera-dictionary.h"

#define UserBuffer 100

void user_input(char* buffer){
	fflush(stdout);
	ssize_t UserInput;	
	if((UserInput = read(0, buffer, UserBuffer))){
		buffer[strcspn(buffer, "\n")] = 0;	
		//buffer[strcspn(buffer, " ")] = 0;	// disabled because some of the names have white space in them 
	}

	return;
}


void keyword(char * input){	
	char camera_buffer[UserBuffer]={};
	char** search;

	if(!strncmp(input, "query", 5)){
		printf("(query)>> ");

		user_input(camera_buffer);

		search=query(camera_buffer);
	
		if(search == NULL){
			printf("\'%s\' Not Found Check List With p|print\n", camera_buffer);
			return;
		}
		
		for(int i = 0; i<c_index[c_entry]; i++){
			printf("%s", search[i]);
			if(i < c_index[c_entry] - 1){
				printf(":");
			}
		}
		printf("\n");
	}else if(!strncmp(input, "print", 1)){
		print_all();
	} else if(!strncmp(input, "quit", 1)){
		exit(1);
	}else if(!strncmp(input, "help", 1)){
		printf("----------\noptions:\n\t(help | prints this screen)\n\t(query | search for camera)\n\t(print | print all cameras)\n\t({q}uit | close program)\n----------\n");
	}
	return;
}

//interactive mode is used when no args are given
void interactive(){
	unsigned short state=1;
	char buffer[UserBuffer];
	
	while(state){
		printf(">> ");
		user_input(buffer);
		keyword(buffer);
	}
	return;
}

int main(int argc, char** argv){
	if(argc < 2){
		interactive();
		return 0;
	} else if (argc == 3 && !(strncmp(argv[1], "-q", 2))) {
		// -q camera
		char** search = query(argv[2]);
		if( search == NULL){
			printf("No results for \'%s\'\n", argv[2]);
			return -1;
		}
		for(int i = 0; i<c_index[c_entry]; i++){
			printf("%s", search[i]);
			if(i < c_index[c_entry] - 1){
				printf(":");
			}
		}
		printf("\n");
		return 0;
	} else if (argc == 2){
		if(!strncmp(argv[1],"-p",2) || !(strncmp(argv[1],"--print",7))){
			print_all();
			return 0;
		}
	}

	printf("%s [options]\n----------\noptions:\n\t--help : prints help\n\t-q [query] : query database for default creds and extra info\n\t--print|-p : print all cameras\n----------\n", argv[0]);
	return 0;
}
