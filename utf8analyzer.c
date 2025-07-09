#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }

    // implement the UTF-8 analyzer here
    //Chiaki 
    const char* is_ascii(char str[]) {
    	for (int i = 0; str[i] != '\0'; i++) {
        	if ((unsigned char)str[i] >= 128) {
            		return "false";
        	}
   	}	
    	return "true";
   }

    int print_animal_emojis(const char str[]) {
 	int i = 0;
    	int count = 0;

    	while (str[i] != '\0') {
        	unsigned char c = (unsigned char)str[i];
        	uint32_t codepoint = 0;
        	int bytes = 1;

        	// Decode UTF-8 to codepoint
        	if ((c & 0x80) == 0x00) {
            		codepoint = c;
        	} else if ((c & 0xE0) == 0xC0) {
            		codepoint = ((c & 0x1F) << 6) | (str[i+1] & 0x3F);
            	bytes = 2;
        	} else if ((c & 0xF0) == 0xE0) {
            		codepoint = ((c & 0x0F) << 12) |
                        ((str[i+1] & 0x3F) << 6) |
                        (str[i+2] & 0x3F);
            		bytes = 3;
        	} else if ((c & 0xF8) == 0xF0) {
            		codepoint = ((c & 0x07) << 18) |
                        ((str[i+1] & 0x3F) << 12) |
                        ((str[i+2] & 0x3F) << 6) |
                        (str[i+3] & 0x3F);
            		bytes = 4;
        	}

        	// Check if it's in the animal emoji ranges
        	if ((codepoint >= 0x1F400 && codepoint <= 0x1F43F) ||
            	(codepoint >= 0x1F980 && codepoint <= 0x1F9AE)) {
            	// print the emoji
           	 	for (int j = 0; j < bytes; j++) {
                		putchar(str[i + j]);
            		}
            	count++;
       	 	}	

        	i += bytes;
    	}

    	return count;
    }


    char* increment_codepoint_at_index_3(const char str[]) {
    	static char result[8];
    	int i = 0; // index into input string
    	int skip = 3;

    	// skip exactly 3 codepoints (no decoding, just advancing by UTF-8 bytes)
    	while (skip > 0) {
        	unsigned char c = (unsigned char)str[i];
        	if (c < 0x80) i += 1;
        	else if (c < 0xE0) i += 2;
        	else if (c < 0xF0) i += 3;
        	else i += 4;
        	skip--;
    	}

    // decode the 4th codepoint
    unsigned char c = (unsigned char)str[i];
    uint32_t cp;
    int bytes;
    if (c < 0x80) {
        cp = c;
        bytes = 1;
    } else if (c < 0xE0) {
        cp = ((c & 0x1F) << 6) | (str[i+1] & 0x3F);
        bytes = 2;
    } else if (c < 0xF0) {
        cp = ((c & 0x0F) << 12) | ((str[i+1] & 0x3F) << 6) | (str[i+2] & 0x3F);
        bytes = 3;
    } else {
        cp = ((c & 0x07) << 18) | ((str[i+1] & 0x3F) << 12) |
             ((str[i+2] & 0x3F) << 6) | (str[i+3] & 0x3F);
        bytes = 4;
    }

    // increment codepoint
    cp++;

    // encode it back into UTF-8
    int ri = 0;
    if (cp < 0x80) {
        result[ri++] = (char)cp;
    } else if (cp < 0x800) {
        result[ri++] = (char)(0xC0 | (cp >> 6));
        result[ri++] = (char)(0x80 | (cp & 0x3F));
    } else if (cp < 0x10000) {
        result[ri++] = (char)(0xE0 | (cp >> 12));
        result[ri++] = (char)(0x80 | ((cp >> 6) & 0x3F));
        result[ri++] = (char)(0x80 | (cp & 0x3F));
    } else {
        result[ri++] = (char)(0xF0 | (cp >> 18));
        result[ri++] = (char)(0x80 | ((cp >> 12) & 0x3F));
        result[ri++] = (char)(0x80 | ((cp >> 6) & 0x3F));
        result[ri++] = (char)(0x80 | (cp & 0x3F));
    }

    result[ri] = '\0';
    return result;
}


}
