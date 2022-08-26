/* Importing the standard input and output library and the string library. */
#include <stdio.h>
#include <string.h>

/**
 * It prints a string centered in a 22 character wide field
 * 
 * @param str The string to be printed
 * @param fmt 1 = print dashes, 0 = print spaces
 */
void centerPrint(char str[], int fmt)
{
    int length;
    int diff;
    int i;

    length = strlen(str);
    diff = 22 - length;

    for (i = diff/2; i > 0; --i) {
        if ( fmt == 1 ) {
            printf ("-");  
        }
        else {
             printf (" ");
        }
    }

    printf(" %s ", str);

    for (i = diff/2; i > 0; --i) {
        if ( fmt == 1 ) {
            printf ("-");  
        }
        else {
             printf (" ");
        }
    }

    printf ("\n");
}



/**
 * This function takes in the names of the two players, the game board, and prints the game board to
 * the screen
 * 
 * @param userOne The name of the first player.
 * @param userTwo The name of the second player.
 * @param game The game board.
 */
void showGame(char userOne[], char userTwo[], char game[]) {
    char input[20] = "";
    int format = 1;

    /* Concatenating the strings together. */
    strcat(input, userOne); 
    strcat(input, " v ");
    strcat(input, userTwo);

    printf ("\n");
    centerPrint(input, format);

    format = 0;

    /* Taking the game board and putting it into a format that can be printed to the screen. */
    char lineOne[10] = "[-][-][-]";
    char lineTwo[10] = "[-][-][-]";
    char lineThree[10] = "[-][-][-]";

    int i;
    for(i = 0; i < 28; i++) {
        if(game[i] == 'X' || game[i] == 'O') {
            if(i < 9 ) {
                lineOne[i] = game[i];
            } else if (i < 18) {
                lineTwo[i - 9] = game[i];
            } else {
                lineThree[i - 18] = game[i];
            }
        }
    }

    /* Printing the game board to the screen. */
    centerPrint(lineOne, format);
    centerPrint(lineTwo, format);
    centerPrint(lineThree, format);
}

int main() {

    /* Declaring the variables that will be used in the program. */
    char game[28] = "[-][-][-][-][-][-][-][-][-]";
    char user1[10];
    char user2[10];
    char cursors[3] = "XO";
    int choice;
    int player = 0;
    
    /* This is the beginning of the program. It is asking the user for their name and then storing it
    in the variable user1 and user2. */
    printf("Welcome to TicTacToe! \n\n");

    printf("User#1 Name: ");
    scanf("%s", &user1);

    printf("\nUser#2 Name: ");
    scanf("%s", &user2);

    /* This is the main game loop. It is asking the user for their choice and then checking if the choice
    is valid. If it is valid, it will place the cursor in the correct spot. If it is not valid, it will
    ask the user to pick again. */
    while (1 == 1) {
        /* Printing the game board to the screen. */
        showGame(user1, user2, game);

        printf("\nUser#%d Pick: ", player + 1);
        scanf("%d", &choice);

        if(game[choice * 3 - 2] == '-') {
            game[choice * 3 - 2] = cursors[player];
        }else {
            printf("\nPick Again!");
            player = player - 1;
        }

        if (game[1] != '-' && game[1] == game[4] && game[4] == game[7] || game[10] != '-' && game[10] == game[13] && game[13] == game[16] || game[19] != '-' && game[19] == game[22] && game[22] == game[25]) {
            showGame(user1, user2, game);
            printf("\nUser#%d WON!!\n", player + 1);
            break;
        } else if(game[1] != '-' && game[1] == game[10] && game[10] == game[19] || game[4] != '-' && game[4] == game[13] && game[13] == game[22] || game[7] != '-' && game[7] == game[16] && game[16] == game[25]) {
            showGame(user1, user2, game);
            printf("\nUser#%d WON!!\n", player + 1);
            break;
        }  else if(game[1] != '-' && game[1] == game[13] && game[13] == game[25] || game[7] != '-' && game[7] == game[13] && game[13] == game[19]) {
            showGame(user1, user2, game);
            printf("\nUser#%d WON!!\n", player + 1);
            break;
        } else if(game[1] != '-' && game[4] != '-' && game[7] != '-' && game[10] != '-' && game[13] != '-' && game[16] != '-' && game[19] != '-' && game[22] != '-' && game[25] != '-') {
            showGame(user1, user2, game);
            printf("\nTie Game!!\n");
            break;
        }

        /* Switching the player. */
        if(player == 0) {
            player = 1;
        } else {
            player = 0;
        }
    }
   
    return 0;
}
