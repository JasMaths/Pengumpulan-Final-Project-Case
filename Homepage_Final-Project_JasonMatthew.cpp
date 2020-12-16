#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	char* pass;
    char* p="hello";
    int i=0;
 
    printf("Enter password and press ENTER.\n \n");
    do{
        printf("Password: ");
        scanf( "%s",  pass);
 
        if(strcmp ( pass, p ) == 0){
            printf("Correct Password. \n \n");
            i=10;
        }
        else
        {
            if(strcmp ( pass, "hint" ) == 0)
            {
                printf("Password Hint: Form of salutation. \n \n");
            }
            else
            {
                printf("Incorrect Password. \nType 'hint' for help. \n \n");
                i++;
            }
        }
 
        if (i == 3){
            i++;
            printf("\n---- PROGRAM TERMINATED ----\n--- PRESS ANY KEY TO END ---\n");
        }
    }
    while (i<4);
 
    if (i == 10){
        printf("Press ENTER to continue... \n");
        //Open a program or file
        system ("C:\\PROGRA~1\\INTERN~1\\iexplore\.exe");
        printf("\n---- PROGRAM TERMINATED ----\n--- PRESS ANY KEY TO END ---\n");
    }
 
	return 0;
}