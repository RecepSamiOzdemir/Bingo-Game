#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Please dont spreedly use program because randomazing is depends on the seed of when you use function. If you use spreedly, ýt gives 
void showBoard(char board[][3]) { // When function called, it will only show board arrays item. Set algorithm is inside main function
    printf("  %s %s %s %s %s %s %s %s\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7]);
}

int main()
{
    int entry; // entry is variable for controling to player wants to play again end of the game and print end game messagess. 
    do{
        int i, j, counter = 0, tries = 0, num;// i and j for making loop, counter for chacking for player correctly guessed all numbers, tries used for counting how many guess is player made and num used for set board items 
        char board[8][3], guess[3]; // 
        srand(time(NULL)); // this function for the generate random number with a value based on the current time's seed.
        for (i = 0; i < 8; i++) {// this loop for set board items
            do {
                num = rand() % 99 + 1;
                for (j = 0; j < i; j++) {// and this loop checks for if randomazed number same as others
                    if (atoi(board[j]) == num) {
                        break;
                    }
                }
            } while (j < i);
            sprintf(board[i], "%d", num);
        }
        printf("\n=========================\n       Bingo Game       \n=========================\n\n");
        showBoard(board);
        while (counter < 8) {// This loop is provides game loop
            printf("\nPlease enter a number :\n\nAlso you can type 0 for Blessing For Ancient Bingo Gods and they will choose a number for you \nOr type -1 for if the game made you feel a little bit hard.\n");
            scanf("%s", guess);
            ++tries;
            printf("\n");
            if (guess[0] == '-' && guess[1] == '1') { //This block quits program when you enter -1
                printf("We apologize for making a game that will made you feel a little bit hard you.\nWe will publish difficulty option in next big update.\n");
                break;
                getchar();
            }
            if (guess[0] == '0') { //This blocks generates random number when you enter 0 but please dont spreedly use 0 entry because randomazing is depends on the seed of when you use function. If you use spreedly, it gives same number.
            	srand(time(NULL));
                num = rand() % 99 + 1;
                printf("Ancient Bingo Gods unquestionable decided number is %d\n\n", num);
                sprintf(guess, "%d", num);
            }
            for (i = 0; i < 8; i++) { // this loop for checking if entry is in the array. And if any item match with entry, its changes with X
                if (strcmp(board[i], guess) == 0) {
                    board[i][0] = 'X';
                    board[i][1] = '\0';
                    ++counter;
                }
            }
            showBoard(board);
            if(counter == 8){ // this block for displaying endgame message and gets players choice
                printf("\n\nCongratulations!! You are an SUPER PLAYER\n");
                printf("And just finising this game only cost %d turn\n", tries);
                printf("Do you want to play with me one more game pls ^^?\n\nType 1 for 'Sure I want to play with you again my sweet sweet computer.'\n\nType 0 for 'Sorry but I have to jobs to do. Maybe we can play later.'\n\n");
                scanf("%d", &entry);
                if (entry == 0){
                    printf("\n\n\t<3 You Played Well <3\n\t    ^^ Goodbye ^^\n\n");
                    getchar();
				}else{
					printf("\n\n       ! YIPPEE !\n");
				}
			}
        }
    } while(entry == 1);
    system("pause");
    return 0;
}
