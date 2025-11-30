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
    char ls[256];
    printf("GRUB\n");
    printf("1 : Ministros OS\n");
    printf("Choose Operating System To Boot\n");
    scanf("%d",&option_os);
    getchar();
    if (option_os == 1) {
    sleep(1);
    printf("Booting...\n");
    FILE *file = fopen("splash.txt","r");
    if (file == NULL) {
    printf("BOOT ERROR : SPLASH NOT FOUND\n");
    
    }
    else{
    while (fgets(splash,sizeof(splash),file)) {
    printf("%s",splash);
    }
    fclose(file);
    }
    
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
        else if (strcmp(input,"touch") == 0) {
            printf("Enter Filename\n");
            fgets(touch_filename,sizeof(touch_filename),stdin);
            touch_filename[strcspn(touch_filename,"\n")] = '\0';
            FILE *touch = fopen("touch.db","a");
            if (touch == NULL) {
                printf("Failed To Create File\n");
            }
            else{
            fprintf(touch,"%s\n",touch_filename);
            fclose(touch);
            }
        }  
        else if (strcmp(input,"ls") == 0) {
            FILE *touch_file = fopen("touch.db","r");
        if (touch_file == NULL) {
            printf("Touch DB Error : 404 FILE NOT FOUND\n");
        }
        else{
            while (fgets(ls,sizeof(ls),touch_file)) {
            ls[strcspn(ls,"\n")] = '\0';
            printf("%s\n",ls);
            }
             fclose(touch_file);
        }
       
      }
     else if (strcmp(input,"sudo pacman -Syu") == 0) {
        printf("Updating Ministros OS\n");
        sleep(1);
         printf("Updating Ministros OS\n");
         sleep(1);
        printf("Updating Ministros OS\n");
        sleep(1);
        printf("Ministros OS Is Updated\n");
     }
     else if (strcmp(input,"sysinfo") == 0) {
        printf("CPU : INTEL CORE ULTRA 9 285K\n");
        printf("GPU : NVIDIA GEFORCE RTX 5090\n");
        printf("RAM : 64GB DDR5\n");
        printf("Storage : 2TB NVME M.2 SSD\n");
     }
     else if (strcmp(input,"--version") == 0) {
        printf("Ministros OS v1.3\n");
        
     }
     else if (strcmp(input,"shutdown now") == 0 || strcmp(input,"exit") == 0) {
        printf("Shutting down..\n");
        break;
     }
     else if (strcmp(input,"help") == 0 || strcmp(input,"--help") == 0) {
        printf("whoami: Prints username\n");
        printf("--version: Prints version\n");
        printf("touch: Creates a file\n");
        printf("ls: List files\n");
        printf("sysinfo: Prints system info\n");
        printf("shutdown now & exit: Shutdown system\n");
        printf("sudo pacman -Syu: Updates system\n");
     }
    else{
        printf("Command Not Found\n");
    }
    }
    }
    else{
        printf("Boot Option Not Found\n");
    }
    return 0;
}
