#include <stdio.h>
#include <string.h>

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

void showGame(char userOne[], char userTwo[], char lineOne[], char lineTwo[], char lineThree[]) {
    char input[20] = "";
    int format = 1;

    strcat(input, userOne); 
    strcat(input, " v ");
    strcat(input, userTwo);

    printf ("\n");
    centerPrint(input, format);

    format = 0;

    centerPrint(lineOne, format);
    centerPrint(lineTwo, format);
    centerPrint(lineThree, format);
}

int main() {
    // Variables
    char lineOne[10] = "[-][-][-]";
    char lineTwo[10] = "[-][-][-]";
    char lineThree[10] = "[-][-][-]";
    char user1[10];
    char user2[10];
    char cursors[3] = "XO";
    int choice;
    int player = 0;
    
    printf("Welcome to TicTacToe! \n\n");

    printf("User#1 Name: ");
    scanf("%s", &user1);

    printf("\nUser#2 Name: ");
    scanf("%s", &user2);

    while (1 == 1) {
        showGame(user1, user2, lineOne, lineTwo, lineThree);

        printf("\nUser#%d Pick: ", player + 1);
        scanf("%d", &choice);

        if(choice > 6) {
            if(lineThree[choice * 3 - 20] == '-') {
                lineThree[choice * 3 - 20] = cursors[player];
            } else {
                printf("\nPick Again!");
                player = player - 1;
            }
        } else if(choice > 3) {
            if(lineTwo[choice * 3 - 11] == '-') {
                lineTwo[choice * 3 - 11] = cursors[player];
            } else {
                printf("\nPick Again!");
                player = player - 1;
            }
        } else if(choice > 0) {
            if(lineOne[choice * 3 - 2] == '-') {
                lineOne[choice * 3 - 2] = cursors[player];
            } else {
                printf("\nPick Again! %c", lineOne[choice * 3 - 1]);
                player = player - 1;
            }
        }

        if (lineOne[1] != '-' && lineOne[1] == lineOne[4] && lineOne[4] == lineOne[7] || lineTwo[1] != '-' && lineTwo[1] == lineTwo[4] && lineTwo[4] == lineTwo[7] || lineThree[1] != '-' && lineThree[1] == lineThree[4] && lineThree[4] == lineThree[7]) {
            showGame(user1, user2, lineOne, lineTwo, lineThree);
            printf("\nUser#%d WON!!\n", player + 1);
            break;
        } else if(lineOne[1] != '-' && lineOne[1] == lineTwo[1] && lineTwo[1] == lineThree[1] || lineOne[4] != '-' && lineOne[4] == lineTwo[4] && lineTwo[4] == lineThree[4] || lineOne[7] != '-' && lineOne[7] == lineTwo[7] && lineTwo[7] == lineThree[7]) {
            showGame(user1, user2, lineOne, lineTwo, lineThree);
            printf("\nUser#%d WON!!\n", player + 1);
            break;
        }  else if(lineOne[1] != '-' && lineOne[1] == lineTwo[4] && lineTwo[4] == lineThree[7] || lineOne[7] != '-' && lineOne[7] == lineTwo[4] && lineTwo[4] == lineThree[1]) {
            showGame(user1, user2, lineOne, lineTwo, lineThree);
            printf("\nUser#%d WON!!\n", player + 1);
            break;
        } else if(lineOne[1] != '-' && lineOne[4] != '-' && lineOne[7] != '-' && lineTwo[1] != '-' && lineTwo[4] != '-' && lineTwo[7] != '-' && lineThree[1] != '-' && lineThree[4] != '-' && lineThree[7] != '-') {
            showGame(user1, user2, lineOne, lineTwo, lineThree);
            printf("\nTie Game!!\n");
            break;
        }

        if(player == 0) {
            player = 1;
        } else {
            player = 0;
        }
    }
   
    return 0;
}
