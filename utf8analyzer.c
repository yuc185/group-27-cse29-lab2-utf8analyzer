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
    const char* is_ascii(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((unsigned char)str[i] >= 128) {
            return "false";
        }
    }
    return "true";
}

    int capitalize_ascii(char str[]){
	int count =0;
	for (int i = 0; str[i] != '\0'; i++){
		if (str[i] >= 'a' && str[i] <= 'z'){
			str[i] -= 32;
			count += 1;
		}
	}
		return count;
}



}
