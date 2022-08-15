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
    char lineOne[] = "[-][-][-]";
    char lineTwo[] = "[-][-][-]";
    char lineThree[] = "[-][-][-]";
    char user1[8];
    char user2[8];
    char cursors[] = "eXO";
    int choice;
    int player = 1;
    
    printf("Welcome to TicTacToe! \n\n");

    printf("User#1 Name: ");
    scanf("%s", user1);

    printf("\nUser#2 Name: ");
    scanf("%s", user2);

    while (1 == 1) {
        showGame(user1, user2, lineOne, lineTwo, lineThree);

        printf("\nUser#%d Pick: ", player);
        scanf("%d", &choice);

        printf("\n%i\n", choice * 3 - 1);

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
            printf("\nUser#%d WON!!\n", player);
            break;
        } else if(lineOne[1] != '-' && lineOne[1] == lineTwo[1] && lineTwo[1] == lineThree[1] || lineOne[4] != '-' && lineOne[4] == lineTwo[4] && lineTwo[4] == lineThree[4] || lineOne[7] != '-' && lineOne[7] == lineTwo[7] && lineTwo[7] == lineThree[7]) {
            showGame(user1, user2, lineOne, lineTwo, lineThree);
            printf("\nUser#%d WON!!\n", player);
            break;
        }  else if(lineOne[1] != '-' && lineOne[1] == lineTwo[4] && lineTwo[4] == lineThree[7] || lineOne[7] != '-' && lineOne[7] == lineTwo[4] && lineTwo[4] == lineThree[1]) {
            showGame(user1, user2, lineOne, lineTwo, lineThree);
            printf("\nUser#%d WON!!\n", player);
            break;
        } else if(lineOne[1] != '-' && lineOne[4] != '-' && lineOne[7] != '-' && lineTwo[1] != '-' && lineTwo[4] != '-' && lineTwo[7] != '-' && lineThree[1] != '-' && lineThree[4] != '-' && lineThree[7] != '-') {
            showGame(user1, user2, lineOne, lineTwo, lineThree);
            printf("\nTie Game!!\n");
            break;
        }

        if(player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }
   
    return 0;
}
