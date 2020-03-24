// Yash Dalsania
// 2/6/2020
// CS 355 Lab 1 Loops, condition, and functions

#include <stdio.h>

int multipleThree(int x){
    return x % 3;
}
int multipleFive(int x){
    return x % 5;
}

int main(){
    int x,y,z;
    printf("Please enter an integer: ");
    scanf("%d", &x);
    if(x < 0){
        printf("Please enter a positive integer: ");
        scanf("%d", &x);
    }
    for(int i = 0; i <= x; i++){
        if(multipleThree(i)==0 && multipleFive(i)==0)
            printf("FizzBuzz \n");
        else if(multipleThree(i)==0)
            printf("Fizz \n");
        else if(multipleFive(i)==0)
            printf("Buzz \n");
        else 
            printf("%d \n", i);
        
    }

}

