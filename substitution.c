#include <stdio.h>
#include <string.h>

int validatekey(char* key[]);

int main(int argc, char* argv[]){

    char input[255];
    
    if(argc == 1){
        printf("Usage: ./substitution key");
        return 1;
    }

    else if(argc > 2){
        printf("Too many arguments");
        return 1;
    }

    switch(validatekey(argv)){

        case 1:
        printf("Key is required to be 26 characters long");
        return 1;
        break;
        
        case 2:
        printf("Key must contain only letters");
        return 1;
        break;

        case 3:
        printf("Key must not contain duplicates");
        return 1;
        break;
    }

    for(int i = 0, n = strlen(argv[1]); i < n; i++){
        if(argv[1][i] >= 'a' && argv[1][i] <= 'z'){
            argv[1][i] = argv[1][i] - ('a' - 'A');
        }
    }
    printf("Plaintext: ");
    scanf("%s", input);

    for(int i = 0, n = strlen(input); i < n; i++){
        if(!((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))){

        }

        else if(input[i] >= 'A' && input[i] <= 'Z'){
            input[i] = argv[1][input[i] - 'A'];
        }
        else{
            input[i] = (argv[1][input[i] - 'a']) + ('a' - 'A');
        }
    }

    printf("Ciphertext: %s\n", input);
    return 0;
    
}

int validatekey(char* key[]){
    int length = strlen(key[1]);
    if(length != 26){
        return 1;
    }
    
    for(int i = 0; i < length; i++){
        if(!((key[1][i] >= 'A' && key[1][i] <= 'Z') || (key[1][i] >= 'a' && key[1][i] <= 'z'))){
            return 2;
        }
        for(int j = 0; j < length; j++){
            if(i == j){

            }
            else if (key[1][i] == key[1][j]){
                return 3;
            }
        }
    }
    return 0;
}