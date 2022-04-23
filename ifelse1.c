#include<stdio.h>

int main(){

    int age;
    printf("enter your age \n");
    scanf("%d" ,&age);
    printf("you have enter %d as your age\n", age);
    if (age>=18)
    {
        printf("you are able to givee a vote!!!\n");
    }

    else if(age>10){
        printf("you are able to give vote to children \n");
    }
    else{
        printf("you are to able to give vote");
    }
    
    return 0;
}