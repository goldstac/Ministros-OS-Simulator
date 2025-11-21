#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
    char username[50];
    char password[50];
    int option_os;
    char input[50];
    char splash[256];
    char touch_filename[50];
    char touch_file[50];
    char ls[256];
    printf("Grub\n");
    printf("1 : Ministros OS\n");
    printf("Choose Operating System To Boot\n");
    scanf("%d",&option_os);
    getchar();
    if (option_os == 1) {
    sleep(1);
    printf("Booting...\n");
    FILE *file = fopen("splash.txt","r");
    sleep(2.3);
    while (fgets(splash,sizeof(splash),file)) {
    printf("%s",splash);
    }
    fclose(file);
    printf("OS\n");
    printf("Username\n");
    fgets(username,sizeof(username),stdin);
    username[strcspn(username,"\n")] = '\0';
    printf("Password\n");
    fgets(password,sizeof(password),stdin);
    password[strcspn(password,"\n")] = '\0';
    
    while (1) {
        printf("%s@ministros [~] $> ",username);
        fgets(input,sizeof(input),stdin);
        input[strcspn(input,"\n")] = '\0';
        if (strcmp(input,"whoami") == 0) {
            printf("%s\n",username);
        } 
        else if (strcmp(input,"--version") == 0) {
            printf("Ministros OS v1.2\n");
        }
        else if (strcmp(input,"touch") == 0) {
            printf("Enter Filename\n");
            fgets(touch_filename,sizeof(touch_filename),stdin);
            touch_filename[strcspn(touch_filename,"\n")] = '\0';
            FILE *touch = fopen("touch.txt","a");
            fprintf(touch,"%s\n",touch_filename);
            fclose(touch);
        }  
        else if (strcmp(input,"ls") == 0) {
            FILE *touch_file = fopen("touch.txt","r");
        while (fgets(ls,sizeof(ls),touch_file)) {
            ls[strcspn(ls,"\n")] = '\0';
            printf("%s\n",ls);
        }
        fclose(touch_file);
      }

    }
    }
    else{
        printf("Boot Option Not Found\n");
    }
    return 0;
}
