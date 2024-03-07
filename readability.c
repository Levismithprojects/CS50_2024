#include <stdio.h>
#include <string.h>

int round(float number);

int main(){

    const float LMULTIPLIER = 0.0588;
    const float SMULTIPLIER = 0.296;
    const float SUBTRACT = 15.8;

    float letters = 0.0;
    float words = 1.0;
    float sentences = 0.0;
    float grade = 0.0;

    char text[1024];
    printf("Text: ");
    scanf("%1023[^\n]", text);
    
    for(int i = 0, n = strlen(text); i < n; i++){
        char input = text[i];
        
        if((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')){
            letters++;
        }

        else if(input == ' ')
        {
            words++;
        }

        else if(input == '!' || input == '.' || input == '?')
        {
            sentences++;
        }
    }
    grade = (((letters/words)*100)*LMULTIPLIER - ((sentences/words)*100)*SMULTIPLIER - SUBTRACT);
    grade = round(grade);

    if(grade < 1)
        printf("Before Grade 1");
    else if(grade >= 16)
        printf("Grade 16+");
    else
        printf("Grade %i", (int)grade);
}

int round(float number){
    int wholenumber = (int)number;
    
    if(number - wholenumber < 0.5){
        return (int)number;
    }

    else{
        return (int)number+1;
    }

    
}