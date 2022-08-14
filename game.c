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
    char line1[] = "[-][-][-]";
    char line2[] = "[-][-][-]";
    char line3[] = "[-][-][-]";
    char user1[8];
    char user2[8];
    char cursors[] = { "X", "O" };
    char choice[1];
    int player = 1;
    
    printf("Welcome to TicTacToe! \n\n");

    printf("User#1 Name: ");
    scanf("%s", user1);

    printf("\nUser#2 Name: ");
    scanf("%s", user2);

    while (1 == 1) {
        showGame(user1, user2, line1, line2, line3);

        printf("\nUser#%d Pick: ", player);
        scanf("%s", choice);

        if (choice[0] == '1' ) {
            if (line1[1] == '-') {
                line1[1] = cursors[player - 1];
            } else {
                printf("\nPick Again!");
                player = player - 1;
            }
            
        } 
        else if (choice[0] == '2') {
            if (line1[4] == '-') {
                line1[4] = cursors[player - 1];
            } else {
                printf("\nPick Again!");
                player = player - 1;
            }
            
        }
        else if (choice[0] == '3') {
            if (line1[7] == '-') {
                line1[7] = cursors[player - 1];
            } else {
                printf("\nPick Again!");
                player = player - 1;
            }
        }    
        else if (choice[0] == '4') {
            if (line2[1] == '-') {
                line2[1] = cursors[player - 1];
            } else {
                printf("\nPick Again!");
                player = player - 1;
            }
        }   
        else if (choice[0] == '5') {
            if (line2[4] == '-') {
                line2[4] = cursors[player - 1];
            } else {
                printf("\nPick Again!");
                player = player - 1;
            }
        }     
        else if (choice[0] == '6') {
            if (line2[7] == '-') {
                line2[7] = cursors[player - 1];
            } else {
                printf("\nPick Again!");
                player = player - 1;
            }
        }    
        else if (choice[0] == '7') {
            if (line3[1] == '-') {
                line3[1] = cursors[player - 1];
            } else {
                printf("\nPick Again!");
                player = player - 1;
            }
        } 
        else if (choice[0] == '8') {
            if (line3[4] == '-') {
                line3[4] = cursors[player - 1];
            } else {
                printf("\nPick Again!");
                player = player - 1;
            }
        }
        else if (choice[0] == '9') {
            if (line3[7] == '-') {
                line3[7] = cursors[player - 1];
            }  else {
                printf("\nPick Again!");
                player = player - 1;
            }
        }

        if (line1[1] != '-' && line1[1] == line1[4] && line1[4] == line1[7] || line2[1] != '-' && line2[1] == line2[4] && line2[4] == line2[7] || line3[1] != '-' && line3[1] == line3[4] && line3[4] == line3[7]) {
            showGame(user1, user2, line1, line2, line3);
            printf("\nUser#%d WON!!\n", player);
            break;
        } else if(line1[1] != '-' && line1[1] == line2[1] && line2[1] == line3[1] || line1[4] != '-' && line1[4] == line2[4] && line2[4] == line3[4] || line1[7] != '-' && line1[7] == line2[7] && line2[7] == line3[7]) {
            showGame(user1, user2, line1, line2, line3);
            printf("\nUser#%d WON!!\n", player);
            break;
        }  else if(line1[1] != '-' && line1[1] == line2[4] && line2[4] == line3[7] || line1[7] != '-' && line1[7] == line2[4] && line2[4] == line3[1]) {
            showGame(user1, user2, line1, line2, line3);
            printf("\nUser#%d WON!!\n", player);
            break;
        } else if(line1[1] != '-' && line1[4] != '-' && line1[7] != '-' && line2[1] != '-' && line2[4] != '-' && line2[7] != '-' && line3[1] != '-' && line3[4] != '-' && line3[7] != '-') {
            showGame(user1, user2, line1, line2, line3);
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
