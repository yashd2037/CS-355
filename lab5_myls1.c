# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>
int myCompare (const void * a, const void * b ) {
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;

    return strcmp(pa,pb);
}

// Prints all files in the DIR even the hidden files
void do_ls1(char *dir_name){
    DIR *dir_ptr;
    struct dirent *dirent_ptr;
    dir_ptr = opendir(dir_name);
    if(dir_ptr==0){
        perror("Cannont open directory");
    }
    else{
        while((dirent_ptr=readdir(dir_ptr)) != 0){
            printf("%s\n", dirent_ptr->d_name);
        }
    }
    closedir(dir_ptr);
}

//Prints all files in the dir except the hidden files
void do_ls2(char *dir_name){
    DIR *dir_ptr;
    struct dirent *dirent_ptr;
    dir_ptr = opendir(dir_name);
    if(dir_ptr==0){
        perror("Cannont open directory");
    }
    else{
        while((dirent_ptr=readdir(dir_ptr)) != 0){
            if(dirent_ptr->d_name[0] != '.'){
                printf("%s\n", dirent_ptr->d_name);
            }
        }
    }
    closedir(dir_ptr);
}

//-s sorts in lexigraphical order
void do_ls3(char *dir_name){
    DIR *dir_ptr;
    char fnames[100][20];
    char temp[50];
    int count = 0;
    struct dirent *dirent_ptr;
    dir_ptr = opendir(dir_name);
    if(dir_ptr==0){
        perror("Cannont open directory");
    }
    else{
        while((dirent_ptr=readdir(dir_ptr)) != 0){
            
                strcpy(fnames[count],dirent_ptr->d_name);
                count++;
            
        }
    }
    closedir(dir_ptr);
    // qsort(fnames, count, sizeof(char *), myCompare);
     for(int i = 0; i < count; i++){
        for(int j=i+1; j<count; j++){
            if(strcmp(fnames[i],fnames[j])<0){
                strcpy(temp,fnames[i]);
                strcpy(fnames[i],fnames[j]);
                strcpy(fnames[j],temp);
            }

        }
        
    }
    for(int i=count-1; i>-1; i--){
        if(fnames[i][0]!='.'){
            printf("%s\n",fnames[i]);
        }
    }

    
}

// -r reverse lexigraphicaly order
void do_ls4(char *dir_name){
    DIR *dir_ptr;
    char fnames[100][20];
    char temp[50];
    int count = 0;
    struct dirent *dirent_ptr;
    dir_ptr = opendir(dir_name);
    if(dir_ptr==0){
        perror("Cannont open directory");
    }
    else{
        while((dirent_ptr=readdir(dir_ptr)) != 0){
            
                strcpy(fnames[count],dirent_ptr->d_name);
                count++;
            
        }
    }
    closedir(dir_ptr);
    
    for(int i = 0; i < count; i++){
        for(int j=i+1; j<count; j++){
            if(strcmp(fnames[i],fnames[j])<0){
                strcpy(temp,fnames[i]);
                strcpy(fnames[i],fnames[j]);
                strcpy(fnames[j],temp);
            }

        }
        
    }
    for(int i=0; i<count; i++){
        if(fnames[i][0]!='.'){
            printf("%s\n",fnames[i]);
        }
    }
    
}

int main(int ac, char *av[]){
    
    if(ac == 1){
        do_ls2(".");
        return 0;
    }

    for(int i=1; i<ac; i++){
        if(av[i][0] == '-'){
            if(strcmp(av[1],"-a")==0){
                if(av[2]!= NULL){
                    do_ls1(av[2]);
                    return 0;
                }
                else{
                    do_ls1(".");
                    return 0;
                }
            }
            else if(strcmp(av[1],"-s")==0){
                if(av[2]!= NULL){
                    do_ls3(av[2]);
                    return 0;
                }
                else{
                    do_ls3(".");
                    return 0;
                }
                
            }
            else if(strcmp(av[1],"-r")==0){
                if(av[2]!= NULL){
                    do_ls4(av[2]);
                    return 0;
                }
                else{
                    do_ls4(".");
                    return 0;
                }
            }
                }
        else{
            do_ls2(av[i]);
        }
        return 0;
    }
    
    
    
    return 0;

}
