#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void headLooks();
int admin_Check();
int add_Student();
void find_Student();
void remove_Student();
void options();
int main()
{
    int var;
    headLooks(); // Design
label:
    var = admin_Check(); // Password
    if (var == 1)
    {
        options(); //Student Manage Mant Starts
    }
    else
    {
        printf("Wrong Username or password\n");
        goto label;
    }
    return 0;
}
void headLooks()
{
    printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t+                WELLCOME to Student Management System      +\n");
    printf("\t\t\t+                         of YOUR SCHOOL                    +\n");
    printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n\n\t\t===============================================================================\n");
    printf("\t\t                                  Please Login\n");
}
int admin_Check()
{
    char user[32];
    char password[32];
    printf("User Name : ");
    scanf("%s", user);
    printf("Password  : ");
    scanf("%s", password);
    if (strcmp(user, "admin") == 0 && strcmp(password, "admin") == 0)
    {
        return 1;
    }
    return 0;
}
int add_Student()
{
    char name[32];
    char roll[10];
    int class;
    printf("Enter the Name of The Student: ");
    fflush(stdin);
    scanf("%[^\n]%*c", name);
    printf("Enter the roll of The Student: ");
    scanf("%s", roll);
    printf("Enter the class of The Student: ");
    scanf("%d", &class);
    FILE *ptr = fopen("database.txt", "w");
    fprintf(ptr, "==========================================================\n           Cantonment Public School & College         \n%35s\n%26s\n%26d", name, roll, class);
    fclose(ptr);
}
void find_Student()
{
    char list[3][32], name[32];
    FILE *ptr = fopen("database.txt", "r");
    for (int i = 0; i < 3; i++)
    {
        fscanf(ptr, "%[^\n]%*c", list[i]);
    }
    fflush(stdin);
    printf("Enter Name of the Student\n");
    scanf("%[^\n]%*c", name);
    if (strcmp(list[0], name) == 0)
    {
        system("database.txt");
    }
}
void remove_Student()
{
    FILE *ptr = fopen("database.txt", "w");
}
void options()
{
    int chose;
    printf("1. Add a Student\n");
    printf("2. Find a Student\n");
    printf("3. Remove a Student\n");
    printf("Enter your Choice\n");
    scanf("%d", &chose);
    switch (chose)
    {
    case 1:
        add_Student();
        break;
    case 2:
        find_Student();
        break;
    case 3:
        remove_Student();
        break;
    default:
        printf("wrong Number");
        break;
    }
}