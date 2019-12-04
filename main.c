#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct folder{
    
    char name[30];
    char date[30];
    struct folder * homeDirectory;
    struct folder * next[30];
};

struct file{
    char name[30];
    char content[30];
    struct folder *parent;
};

typedef struct folder folder;
typedef struct file file;

/*
struct filesystem{

    struct folder ** fold;
    struct file * file;
    
    
};*/

folder * createFolder(char nume[30],char date[30],folder * current_folder);
folder * alloc(int n);
void showFilesFolders(folder * prime);
char * allocChar(int n);
char * reAlloc(char * your_var,int n);
void program_running();
void evaluateEnteredText(char *a);
void lookForCommandsY(char * l,char * text);
void changeFolder(char *s);


char * route;
folder * home;


int main(){
    
    program_running();
    
    
    
    return 0;
}



void program_running(){
    
    folder * prime;
    folder * second;
    
    char a[30];
    
    prime=createFolder("root","date",NULL);
    showFilesFolders(prime);
    home=prime;
    strcpy(a,"folder");
    
    second=createFolder(a,"date",prime);
    showFilesFolders(second);
    while(1){
        
        printf("\n>");
        gets(a);
        evaluateEnteredText(a);
        
      //  second=createFolder(a,"date",second);
        // showFilesFolders(second);
    }
    
}


void evaluateEnteredText(char *a){
    char b[30],*l,*text;
    if (a==NULL){
        printf("\n>");
        gets(*a);
    }else{
        strcpy(b,a);
        l=strtok(b," ");
        text=strtok(NULL," ");
        lookForCommandsY(l,text);
 //       printf(" \n--%s ",l);
    }
   // while(l!=NULL){
//        l=strtok(b," ");
//    }
    
    
}

void lookForCommandsY(char * l,char * text){
    
    
        if(strcmp(l,"ls")==0){
            showFilesFolders(NULL);
            printf("%s",text);
        }else if(strcmp(l,"mkdir")==0){
            createFolder(text,"date",home);
           // showFilesFolders(NULL);
        }else if(strcmp(l,"cd")==0){
            changeFolder(text);
        }else if(strcmp(l,"exit")==0){
            exit(1);
        }
    
}

void changeFolder(char *s){
    
    
    
    if(strcmp(s,"..")!=0){
        for(int i=0;i<20;i++){
            if (home->next[i]!=NULL && strcmp(home->next[i]->name,s)==0){
                home=home->next[i];
                printf("%s", home->next[i]->name);
            }
        } 
    }else{
        home=home->homeDirectory;
        
    }
}


folder * createFolder(char nume[30],char date[30] ,folder * current_folder){
    
    if ( current_folder==NULL){
        folder * start_folder;
        start_folder=alloc(1);
        strcpy(start_folder->name,nume);
        strcpy(start_folder->date,date);
        start_folder->homeDirectory=start_folder;
    
        return start_folder;  
    }else{
        folder * new;
        new=alloc(1);
        for(int i=0;i<30;i++){
            if(current_folder->next[i]==NULL){
                current_folder->next[i]=new;
                strcpy(current_folder->next[i]->name,nume);
                strcpy(current_folder->next[i]->date,date);
                current_folder->next[i]->homeDirectory=current_folder;
                return current_folder;
            }
        }
    }
 
}
void showFilesFolders(folder * prime){    
   
    
    //strcpy(second.name,"second");
    //prime.next[0]=&second;
    if(prime!=NULL){
        route=allocChar(strlen(prime->name));
        strcpy(route,prime->name);
        strcat(route,prime->name);
    
        printf("%s %s>",prime->name,prime->next[0]->name);//,prime.next[0]->name);
        for(int i=0;i<20;i++){
            if (prime->next[i]==NULL){
                break;
            }else{
            
                printf("%s\n", prime->next[i]->name);
            }
        } 
    }else{
        for(int i=0;i<20;i++){
            if (home->next[i]==NULL){
                break;
            }else{
                printf("%s\n", home->next[i]->name);
            }
        } 
    }
    
    
}

folder * alloc(int n){
    folder * alloc1;
    alloc1 = (folder *) malloc(n*sizeof(folder));
    if(alloc1==NULL){
        printf("nu mai ai memorie!");
        exit(1);   
    }
    
    return alloc1;
}


char * allocChar(int n){
    char *all;
    all=(char *) malloc(n*sizeof(char));
    if(all == NULL){
        printf("Nu mai ai memorie!");
        exit(1);
    }
    
    return all;
}

char * reAlloc(char * your_var,int n){
    
    your_var=(char *) realloc(your_var,(n+strlen(your_var))*sizeof(char));
    
    return your_var; 
}















