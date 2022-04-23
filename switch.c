#include <stdio.h>

int main()
{
    int age, marks;
    printf("enter your age\n ");
    scanf("%d", &age);
    printf("enter your marks\n ");
    scanf("%d", &marks);

    switch (age)
    {
    case 3:
        printf("the age is 3\n");
        // break;
        switch (marks)
        {
        case 45:
            printf("you got 45 marks\n");
            break;

        default:
            printf("your marks are not 45\n");
        }
        break;
    case 5:
        printf("age is 5\n");
        break;

    default:
        printf("your age is not 3 or 5");
        break;
    }
    return 0;
}