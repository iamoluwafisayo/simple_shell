#include "shell.h"

/**
 * main - adds strings
 * str1: first person
 * str2: joiner
 * str3: second person
 * str4: statement
 * result - declares a character array name
 * Return: always 0. success
 */

int main()
{
    char str1[] = "Frank Kaziputa";
    char str2[] = "and";
    char str3[] = "David Oluwatosin Dorcas";
    char str4[] = "have done this assignment and betty is proud with it";
    char result[100];

    sprintf(result, "%s %s %s %s", str1, str2, str3, str4);

    printf("%s\n", result);

    return (0);
}
