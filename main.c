#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    char username[20];
    char password[30];
    char input[100];
    printf("Booting....\n");
    FILE *file = fopen("splash.txt","r");
    char data[256];
    sleep(1.5);
    while (fgets(data,sizeof(data),file)) {
        printf("%s",data);
    }
    printf("\n");
     sleep(1.5);
    printf("Ministros OS Login\n");
    printf("Username\n");
    fgets(username,sizeof(username),stdin);
    username[strcspn(username,"\n")] = '\0';
    printf("Password \n");
    fgets(password,sizeof(password),stdin);
    password[strcspn(password,"\n")] = '\0';
    printf("Welcome %s \n",username);
    while(1) {
        printf("%s@ministros $ > ",username);
        fgets(input,sizeof(input),stdin);
       input[strcspn(input,"\n")] = '\0';
       if (strcmp(input,"whoami") == 0) {
        printf("%s\n",username);
       }
       else if (strcmp(input,"--version") == 0) {
        printf("Ministros OS v1.0\n");
       }
       else if (strcmp(input,"shutdown now") == 0 || strcmp(input,"exit") == 0) {
        break;
       }
       else if (strcmp(input,"help") == 0) {
        printf("whoami : prints username\n");
        printf("--version : prints version\n");
        printf("shutdown now : exit system\n");
        printf("exit : exit system\n");
        printf("help : prints commands\n");
        printf("sudo pacman -Syu : updates system\n");
       }
       else if (strcmp(input,"sudo pacman -Syu") == 0) {
        sleep(0.3);
        printf("Updating Ministros OS ########\n");
        sleep(1);
        printf("Updating Ministros OS ########\n");
        sleep(1);
        printf("Updating Ministros OS ########\n");
        printf("Ministros OS Updated\n");
       }
       else{
        printf("Command Not Found\n");
       }

    }
}
