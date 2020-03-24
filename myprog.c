# include <stdio.h>
# include <stdlib.h>


int main(int ac, char *av[] ){
    
     for(int i=2; i<ac; i++){
         char *word = av[i];
         char *str;
         str = (char*)malloc(sizeof(word));
         for(int j=0; word[j]!=0;j++){
            char a = word[j];
            if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
                str[j]=a;
                printf("%s\n",str);
            }
         }
            
         
        
    }


}