#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){

   FILE *fp;
   char *line;
   size_t len = 0;
   size_t nread;
   int i,count;


   if (argc == 1){
      printf("Usage ./mycat <filename, ...>\n");
      return 0;
   }
   for (i = 1; i<argc; i++){
      if (argv[i][0] == '-')
            continue;
      fp = fopen(argv[i],"r");
      if (fp == NULL){
         printf("Error opening file\n");
         continue;
      }
      count = 0;
      while ((nread = getline(&line, &len,fp)) != -1){
          if (strcmp(argv[1],"-b") == 0){
            
             int blank = 1;
             //printf("%d\n",strlen(line));
            
             for (int k = 0; k<strlen(line); k++){
               if (*(line+k) != ' ' && line[k] != '\n' && line[k] != '\r' && line[k] != '\t'){
                   blank = 0;
                }
             }
            
             if (blank == 0){
                 printf("%d %s",count+1,line);
                 count++;
             }
             else{
                 printf("%s",line);
             }
          }
          else if (strcmp(argv[1],"-e") == 0){
             
             line[strlen(line)-1] = '$';
             printf("%s",line);
             printf("\n");
           
          }
          else if (strcmp(argv[1],"-n") == 0){
             printf("%d %s",count+1,line);
             count++;
          }
          else if (strcmp(argv[1],"-s") == 0){
             int blank = 1;
             for (int j = 0; j<strlen(line); j++){
                if (line[j] != ' ' && line[j] != '\n' && line[j] != '\r' && line[j] != '\t'){
                   blank = 0;
                  
                }
             }
             if (blank == 0){
                 printf("%s",line);
                 count++;
             }
          }
            else if((strcmp(argv[1],"-sn") == 0) || (strcmp(argv[1],"-sb") == 0)){
              int blank = 1;
             for (int j = 0; j<strlen(line); j++){
                if (line[j] != ' ' && line[j] != '\n' && line[j] != '\r' && line[j] != '\t'){
                   blank = 0;
                  
                }
             }
             if (blank == 0){
                 printf("%d %s",(count+1),line);
                 count++;
                }
            }
            else if((strcmp(argv[1],"-bn") == 0) || (strcmp(argv[1],"-nb") == 0)){
                int blank = 1;
                for (int k = 0; k<strlen(line); k++){
                    if (*(line+k) != ' ' && line[k] != '\n' && line[k] != '\r' && line[k] != '\t'){
                    blank = 0;
                    }
                }
                if (blank == 0){
                    printf("%d %s",count+1,line);
                    count++;
                } 
                else{
                 printf("%s",line);
                }
             }
            else if((strcmp(argv[1],"-be") == 0) || (strcmp(argv[1],"-eb") == 0)){
                int blank = 1;
                for (int k = 0; k<strlen(line); k++){
                    if (*(line+k) != ' ' && line[k] != '\n' && line[k] != '\r' && line[k] != '\t'){
                    blank = 0;
                    }
                }
                line[strlen(line)-1] = '$';
                if (blank == 0){
                    printf("%d %s",count+1,line);
                    printf("\n");
                    count++;
                } 
                else{
                    printf("%s",line);
                    printf("\n");
                }

            }
            else if((strcmp(argv[1],"-ens") == 0) || (strcmp(argv[1],"-ebs") == 0) || (strcmp(argv[1],"-bse") == 0) ||
            (strcmp(argv[1],"-nbe") == 0)|| (strcmp(argv[1],"-sne") == 0) || (strcmp(argv[1],"-sbe") == 0)){
                 int blank = 1;
             for (int j = 0; j<strlen(line); j++){
                if (line[j] != ' ' && line[j] != '\n' && line[j] != '\r' && line[j] != '\t'){
                   blank = 0;
                  
                }
             }
             line[strlen(line)-1] = '$';
             if (blank == 0){
                 printf("%d %s",(count+1),line);
                 printf("\n");
                 count++;
                }
            }
            

            else {
              printf("%s",line);

          }
               
      }
      fclose(fp);
   }
   return 0;
}