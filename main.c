#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



void print_help(){
    printf(" CLI - Toolkit\n");
    printf("- commands:\n");
    printf("  uuid   Generate a random UUID\n");
    printf("  help   Print this help message\n");
}

void generate_uuid(){
    const char *hex = "0123456789abcdef";
    char uuid[37];

    srand(time(NULL));

    for(int i = 0; i < 36; i++){
        if(i == 8 || i == 13 || i == 18 || i == 23){
            uuid[i] = '-';
        }else if (i==14){
            uuid[i] = '4';
        } else if(i == 19) {
            uuid[i] = hex[(rand() % 4) + 8];
        } else {
            uuid[i] = hex[rand() % 16];
        }
    }
    uuid[36] = '\0';
    printf("%s\n", uuid);
}
int main(int argc, char *argv[]){
    if(argc == 1){
        print_help();
        return 0;
    }
    if(strcmp(argv[1], "uuid") == 0){
        printf("Generating UUID...\n");
        generate_uuid();
        return 0;
    }
    if(strcmp(argv[1], "help") == 0){
        print_help();
        return 0;
    }
    printf("Unknown command: %s\n", argv[1]);
    return 1;
}
