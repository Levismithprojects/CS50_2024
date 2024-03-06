#include <stdio.h>
#include <string.h>

int scorecalc();
int main()
{
    
    int scorep1 = 0;
    int scorep2 = 0;

    char player1[25];
    printf("Player1: ");
    scanf("%s", player1);

    char player2[25];
    printf("Player2: ");
    scanf("%s", player2);
    
    scorep1 = scorecalc(player1);
    scorep2 = scorecalc(player2);
    
    if(scorep1 > scorep2){
        printf("Player1 wins!");
    }

    else if(scorep1 < scorep2){
        printf("Player2 wins!");
    }

    else{
        printf("Tie!");
    }
}

int scorecalc(char str[25]){
    
    const int toupper = 'a'-'A';
    const int SCORE[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int total = 0;

    for(int i = 0, n = strlen(str); i < n; i++ ){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - toupper;
        }
        if(str[i] >= 'A' && str[i] <= 'Z'){
            total = total + SCORE[str[i] - 'A'];
        }
    }

    return total;
}