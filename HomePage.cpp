#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dish
{
    char name[1000];
    struct Dish *prev, *next;
} *head, *tail, *curr;

void clear_screen ()
{
    system("cls");
}

void description ()
{
    clear_screen();
    puts("\nDESCRIPTION");
    puts("==============");
}

void instruction ()
{
    puts("\nINSTRUCTION");
    puts("=============");
}

void ingredients ()
{
    puts("\nINGREDIENTS");
    puts("==============");
}

void hamburger ()
{
    description();
    puts("A sandwich consisting of one or more cooked patties of ground meat, usually beef, placed inside a sliced bread roll or bun. The patty may be pan fried, grilled, smoked or flame broiled");

    ingredients();    
    puts("1/2 cup seasoned bread crumbs");
    puts("1 large egg, lightly beaten");
    puts("1/2 teaspoon salt");
    puts("1/2 teaspoon pepper");
    puts("1 ground pound beef");
    puts("1 tablespoon olive oil");
    puts("4 sesame hamburger seed");

    instruction();
    puts("1. In a bowl, mix ground beef, egg, onion, bread crumbs, Worcestershire, garlic, 1/2 teaspoon salt, and 1/4 teaspoon pepper until well blended.");
    puts("2. Lay burgers on an oiled barbecue grill over a solid bed of hot coals or high heat on a gas grill");
    puts("3. Lay buns, cut side down, on grill and cook until lightly toasted, 30 seconds to 1 minute.");
    puts("4. Add lettuce, tomato, burger, onion, and salt and pepper to taste. Set bun tops in place.");
}

void french_fries ()
{
    description();
    puts("French fries are batonnet or allumette-cut deep-fried potatoes.");

    ingredients();
    puts("- 2 1/2 pound potatoes");
    puts("- vegetable or peanut oil");
    puts("- sea salt");
    puts("- ketchup and mayonnaise");

    instruction();
    puts("1. Peel and rinse the potatoes. Cut each potato into sticks. Place the fries in a large bowl, cover with cold water, then allow them to soak.");
    puts("2. drain the water and lay the potatoes on  baking sheets lined with paper towels and dry it.");
    puts("3. 3. Heat vegetable oil to around 150 C then fry the potatoes until golden and crisp.");
}

void bacon ()
{
    description();
    puts("Bacon is a type of salt-cured pork made from various cuts, typically from the pork belly or from the less fatty back cuts.");

    ingredients();
    puts("2-3 pounds of pork belly");
    puts("1/2 cup brown sugar");
    puts("3 tablespoon kosher salt");
    puts("1 1/4 teaspoons ground black pepper");

    instruction();
    puts("1. Pat the pork belly dry with paper towels. In a small bowl, combine the brown sugar, salt, pepper and optional curing salt then rub the seasoning mixture into all sides of the pork belly and spend a couple minutes massaging the mixture into the meat.");
    puts("2. place the pork belly along with any leftover mixture into a plastic bag and seal it shut.Store it in the refrigerator for 10 to 14 days, turning the bag occasioanlly. Rinse the bacon and again pat it thoroughly dry with paper towels");
    puts("3. Roast the bacon in 93 C oven until the internal temperature reaches 66 C. This should take about 2 hours.");

}

void AMERICAN_FOOD ()
{
    clear_screen();
    puts("1. Hamburger");
    puts("2. French Fries");
    puts("3. Bacon");
    puts("0. Back");
    
    int choice;
    do
    {
        printf(">> ");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 3);

    switch (choice)
    {
        case 1: hamburger();
        break;
        case 2: french_fries();
        break;
        case 3: bacon();
        break;
        default: return;
        break;
    }
}

void salad ()
{
    description();
    puts("Salad is a cold dish of various mixtures of raw or cooked vegetables, usually seasoned with oil, vinegar or other dressing.");

    ingredients();
    puts("- 4 ounce lettuce or mixed greens(washed, dried, and torn)");
    puts("- 2 tablespoons olive oil");
    puts("- 2 teaspoons vinegar or lemon juice");
    puts("- flaky salt and freshly ground black pepper");

    instruction();
    puts("1. Chop the greens into bite size then wash them thoroughly in a bowl.");
    puts("2. Put the greens in a really big bowl.");
    puts("3. Add any other vegetables you like such as carrots or cucumber");
    puts("4. Sprinkle salt and pepper");
}

void banana_split ()
{

}

void FRUIT_AND_VEGE ()
{
    clear_screen();
    puts("1. Salad");
    puts("2. Banana Split");
    puts("0. Back");

    int choice;
    do
    {
        printf(">> ");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 2);

    switch (choice)
    {
        case 1: salad();
        break;
        case 2: banana_split();
        break;
        default: return;
        break;
    }
}

void SNACKS ()
{
    clear_screen();
    puts("1. ");
}

void orange_juice ()
{

}

void milkshake ()
{

}

void DRINKS ()
{
    clear_screen();
    puts("1. Orange Juice");
    puts("2. Milkshake");
    puts("0. Back");

    int choice;
    do
    {
        printf(">> ");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 2);

    switch (choice)
    {
        case 1: orange_juice();
        break;
        case 2: milkshake();
        break;
        default: return;
        break;
    }
}

void recipe_suggestion ()
{
    clear_screen();
    puts("RECIPE SUGGESTION:");
    puts("==================");
    puts("1. American Food");
    puts("2. Fruit and Vegetables");
    puts("3. Snacks");
    puts("4. Drinks");
    puts("0. Back");
    
    int choice;
    do
    {
        printf(">> ");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 4);

    switch (choice)
    {
        case 1: AMERICAN_FOOD();
        break;
        case 2: FRUIT_AND_VEGE();
        break;
        case 3: SNACKS();
        break;
        case 4: DRINKS();
        break;
        default: return;
        break;
    }
}

void search_dish ()
{
    clear_screen();
    char name[1000];
    printf("Enter the name of the dish : ");
    scanf("%[^\n]", name); getchar();

    bool found = false;
    curr = head;
    while (curr)
    {
        if (strcmp(name, curr->name) == 0)
        {
            found = true;
            break;
        }
        curr = curr->next;
    }

    if (found)
    {
        printf("%s is found\n", name);
        puts("Recipe : ");

    }   
    else
    {
        puts("Dish not found!");   
    }
}

void home_page ()
{
    puts("1. Recipe Suggestion");
    puts("2. Search Dish");
    puts("0. Back");
    int choice;
    do
    {
        printf(">> ");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 2);
    
    switch (choice)
    {
        case 1: recipe_suggestion();
        break;
        case 2: search_dish();
        break;
        case 0: return;
        break;
    }
}

int main()
{
    home_page();

    return 0;
}