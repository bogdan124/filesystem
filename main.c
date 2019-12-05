#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct folder{
    
    char name[30];
    char date[30];
    char * owner;
    struct folder * homeDirectory;
    struct folder * next[30];
    struct file * file[30];
};



struct file{
    char name[30];
    char * owner;
    char * content;
    struct folder *parent;
};


struct varname{
    
    char * name;
    float number;
    
};

typedef struct folder folder;
typedef struct file file;
typedef struct varname variable;


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
void evaluateEnteredText(char *a,variable * v);
void lookForCommandsY(char * l,char * text,char *allText,variable * v);
void changeFolder(char *s);
file * createFile(char nume[30],folder * folderWereIs);
file * fileAlloc(int n);
void catFile(char *s,folder * name_house,int cat_option);
void helpF();
int connect(char *s,char *pass);
void verify_entry__();
void changeUser(char *user);
void createVariable(char *val,char *number,variable * v);
variable * storeVarAlloc(int n);
int searchVariable(char *s,variable * v);
float searchVariableGET(char *s,variable * v);



char * route;
folder * home;
char * current_user_now;
char * current_pass_now;




int main(){
    
    
    
    verify_entry__();
    
    
    return 0;
}








void verify_entry__(){
    char *user,*password;

    
    user=allocChar(30);
    current_user_now=allocChar(30);
    current_pass_now=allocChar(30);
    password=allocChar(30);
    
    printf("******Connect******\n");
    printf("user:");
    gets(user);
    strcpy(current_user_now,user);
    printf("\npassword:");
    gets(password);
    strcpy(current_pass_now,password);
    if(connect(user,password)==1){
        program_running();
    }
}




void program_running(){
    
    folder * prime;
    folder * second;
    
    char a[30];
    variable *v;
    
    v=storeVarAlloc(100);
    
    prime=createFolder("root","date",NULL);
    //showFilesFolders(prime);
    home=prime;
    strcpy(a,"folder");
    
    second=createFolder(a,"date",prime);
    //showFilesFolders(second);
    while(1){
        
        printf(">");
        gets(a);
        evaluateEnteredText(a,v);
        
      //  second=createFolder(a,"date",second);
        // showFilesFolders(second);
    }
    
}




void evaluateEnteredText(char *a,variable * v){
    char b[30],*l,*text;
    if (a==NULL){
        printf(">");
        gets(*a);
    }else{
        strcpy(b,a);
        l=strtok(b," ");
        text=strtok(NULL," ");
        lookForCommandsY(l,text,a,v);
 //       printf(" \n--%s ",l);
    }
   // while(l!=NULL){
//        l=strtok(b," ");
//    }
    
    
}






void lookForCommandsY(char * l,char * text,char *allText,variable * v){
    
    
    
    
        if(strcmp(l,"ls")==0){
            showFilesFolders(NULL);
        }else if(strcmp(l,"mkdir")==0){
            createFolder(text,"date",home);
           // showFilesFolders(NULL);
        }else if(strcmp(l,"cd")==0){
            changeFolder(text);
        }else if(strcmp(l,"exit")==0){
            exit(1);
        }else if(strcmp(l,"touch")==0){
            createFile(text,home);
        }else if(strcmp(l,"cat")==0){
            catFile(text,home,0);
        }else if(strcmp(l,"cat>")==0){
            catFile(text,home,1);
        }else if(strcmp(l,"cat>>")==0){
            catFile(text,home,2);
        }else if(strcmp(l,"help")==0){
            helpF();
        }else if(strcmp(l,"su")==0){
            changeUser(text);
        }else if(strcmp(l,"whoami")==0){
            printf("%s\n",current_user_now);
        }else if( l[0]=='$' && l[1]!=' '){
             printf("%s",allText);
             createVariable(l,text,v);        
        }else{
            printf("No command!!");
        }
    
}




void createVariable(char *val,char *number,variable * v){
 
    
    if(searchVariable(val,v)==0){
        
    

    for(int i=0;i<100;i++){
        if(v[i].name==NULL){
            v[i].name=allocChar(30);
            strcpy(v[i].name,val);
            v[i].number=strtod(number,NULL);
            break;
        }
    }
    
    
    
    printf("%f\n",v[0].number);
    }else{
       printf("%f\n", searchVariableGET(val,v));
    }
}


int searchVariable(char *s,variable * v){
    int ex=0;
    float save_num;
    for(int i=0;i<100;i++){
        if(strcmp(v[i].name,s)==0){
            ex=1;
            save_num=v[i].number;
        }
    }
    if(ex==1){
        return 1;
    }else{
        return 0;
    }
}


float searchVariableGET(char *s,variable * v){
    int ex=0;
    float save_num;
    for(int i=0;i<100;i++){
        if(strcmp(v[i].name,s)==0){
            ex=1;
            save_num=v[i].number;
        }
    }
    if(ex==1){
        return save_num;
    }else{
        return 0;
    }
}




int connect(char *s,char *pass){
    if(strcmp(s,"root")==0 && strcmp(pass,"pass")==0){
        return 1;
    }else{
        printf("Wrong user or password !");
        return 0;
    }
    
}




void changeUser(char *user){
    
    FILE *pt;
    char *s;
    char user1[30];
    
    pt=fopen("user.txt","rt");
    if(pt==NULL){
        printf("ERROR:2\nMissing file user");
    }
    s=allocChar(30);
    //while(!eof(pt)){      
      //  fgets(user,300,fil);
        if(strcmp(user,"bogdan")==0){
            printf("Password:");
            gets(s);
            current_user_now=user; 
            current_pass_now=s;

        //}
    }
    
}



void helpF(){
    FILE *fil;
    
    fil=fopen("help.txt","rt");
    
    if(fil==NULL){
        printf("ERROR:1\nMissing file help");
        exit(1);
    }
    
    char s[300];
    
    printf("\n");
    while(!feof(fil)){
        fgets(s,300,fil);
        printf("%s",s);
    }
    
    fclose(fil);
    printf("\n");
}





void catFile(char *s,folder * name_house,int cat_option){
    
    
        for(int i=0;i<30;i++){
            if(name_house->file[i]!=NULL){
                if(strcmp(name_house->file[i]->name,s)==0){
                    if(cat_option==0){
                        printf("%s",name_house->file[i]->content);  
                        printf("\n");
                    }else if(cat_option==1){
                        char *file1;
                        file1=allocChar(1000);
                        gets(file1);
                        name_house->file[i]->content=allocChar(strlen(file1));
                        strcpy(name_house->file[i]->content,file1);
                    }else if(cat_option==2){
                        printf("not implemented");
                    }
                }
            }else{
                break;
            }
        }
    
}





void changeFolder(char *s){
    
    
    
    if(strcmp(s,"..")!=0){
        for(int i=0;i<20;i++){
            if (home->next[i]!=NULL && strcmp(home->next[i]->name,s)==0){
                home=home->next[i];
                //printf("%s", home->next[i]->name);
            }
        } 
    }else{
        home=home->homeDirectory;
        
    }
}





file * createFile(char nume[30],folder * folderWereIs){
    
    file * create;
    
    create=fileAlloc(1);
    strcpy(create->name,nume);
    create->owner=current_user_now;
    create->parent=folderWereIs;
    for(int i=0;i<30;i++){
        if(folderWereIs->file[i]==NULL){
            folderWereIs->file[i]=create;
            break;
        }
    }
    
    return create;
}





folder * createFolder(char nume[30],char date[30] ,folder * current_folder){
    
    if ( current_folder==NULL){
        folder * start_folder;
        start_folder=alloc(1);
        strcpy(start_folder->name,nume);
        strcpy(start_folder->date,date);
        start_folder->homeDirectory=start_folder;
        start_folder->owner=current_user_now;
    
        return start_folder;  
    }else{
        folder * new;
        new=alloc(1);
        for(int i=0;i<30;i++){
            if(current_folder->next[i]==NULL){
                current_folder->next[i]=new;
                strcpy(current_folder->next[i]->name,nume);
                strcpy(current_folder->next[i]->date,date);
                current_folder->owner=current_user_now;
                current_folder->next[i]->homeDirectory=current_folder;
                return current_folder;
            }
        }
    }
 
}





void showFilesFolders(folder * prime){    
   
    
   
    //strcpy(second.name,"second");
    //prime.next[0]=&second;
    printf("Owner\tSize\tName\n");
    
    if(prime!=NULL){
        route=allocChar(strlen(prime->name));
        strcpy(route,prime->name);
        strcat(route,prime->name);
    
       // printf("%s %s>",prime->name,prime->next[0]->name);//,prime.next[0]->name);
        for(int i=0;i<20;i++){
            if (prime->next[i]==NULL){
                break;
            }else{
            
                printf("%s ", prime->next[i]->name);
            }
        } 
    }else{
        printf("\033[0;34m");
      //  printf("\n");
        for(int i=0;i<20;i++){
            if (home->next[i]==NULL){
                break;
            }else{
                printf("%s\t%zu\t%s\n",current_user_now,sizeof(home), home->next[i]->name);
            }
        } 
        printf("\033[0;33m");
          for(int i=0;i<20;i++){
            if (home->file[i]==NULL){
                break;
            }else{
                printf("%s\t%zu\t%s\n",current_user_now, sizeof(home->file[i]->content), home->file[i]->name);
            }
        }
    }
    printf("\033[0m");
  //  printf("\n");
    
    
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



variable * storeVarAlloc(int n){
    
    variable *var;
    var=(variable*)malloc(n*sizeof(variable));
                                          
    if(var==NULL){
        printf("No memory!");
    }
    
   return var; 
}





file * fileAlloc(int n){
     file * alloc1;
    alloc1 = (file *) malloc(n*sizeof(file));
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















