#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Recipe
{
    char Description[1005];
    char *Instruction[20];
    char *Ingredients[20];
    bool bookmark;
    Recipe *next, *prev;
} * head_Recipe, *tail_Recipe, *curr_Recipe;

void clear()
{
    system("cls || clear");
}

void ingredient()
{
    clear();
    curr_Recipe = head_Recipe;
    puts("Ingredient list");
    puts("================");
    int i = 0;
    while (curr_Recipe)
    {
        printf("%d :  %s\n", i + 1, curr_Recipe->Ingredients[i]);
        curr_Recipe = curr_Recipe->next;
        i++;
    }
}

void kitchenMenu()
{
    clear();
    puts("1. Selected Recipes");
    puts("2. Ingredients List");
    puts("3. Start Cooking");
    puts("4. Go Back");
    int input;

    do
    {
        printf(">> ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:

            break;
        case 2:
            ingredient();
            break;
        case 3:

            break;
        case 4:

            break;
        }
    } while (!(input >= 1 && input <= 4));
}