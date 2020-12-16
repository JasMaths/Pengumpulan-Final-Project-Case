
struct Recipe
{
    int steps,ingr;
    char Name[255];
    char Description[255];
    char Instruction[20][255];
    char Ingredients[20][255];
    bool bookmark;
    Recipe *next, *prev;
} *head_Recipe, *tail_Recipe, *curr_Recipe;

struct Recipe *createRecipe(char *name, char *Description, int steps, int ingr, char Instruction[][255],  char Ingredient[][255])
{
    struct Recipe *temp = (Recipe *)malloc(sizeof(Recipe));
    strcpy(temp->Description, Description);
    strcpy(temp->Name, name);
    temp->steps = steps;
    temp->ingr = ingr;
    temp->bookmark = false;
    for(int i = 0;i < steps;i++)
    {
        strcpy(temp->Instruction[i],Instruction[i]); 
    }
    for(int i = 0;i < ingr;i++)
    {
        strcpy(temp->Ingredients[i],Ingredient[i]);
    }
    temp->next = temp->prev = NULL;
    return temp;
}

void pushRecipe(struct Recipe *temp)
{
    if (!head_Recipe)
    {
        head_Recipe = tail_Recipe = temp;
    }
    else
    {
        tail_Recipe->next = temp;
        temp->prev = tail_Recipe;
        tail_Recipe = temp;
    }
}

void SavedRecipes()
{
    system("cls || clear");
    curr_Recipe = head_Recipe;
    while(curr_Recipe)
    {
        if(curr_Recipe->bookmark == true)
        {
            printf("%s\n",curr_Recipe->Name);
        }
        curr_Recipe = curr_Recipe->next;
    }
    getchar();
    cookbook();
}

void SearchRecipes()
{
    system("cls || clear");
    char nametemp[255];
    bool flag = false;
    puts("Enter name of recipe");
    scanf("%[^\n]", nametemp);
    getchar();
    curr_Recipe = head_Recipe;
    while(curr_Recipe)
    {
        if(strcmp(curr_Recipe->Name,nametemp)==0)
        {
            printf("%s\n",curr_Recipe->Name);
            printf("%s\n",curr_Recipe->Description);
            for(int i = 0;i<curr_Recipe->steps;i++)
            {
                printf("%s\n",curr_Recipe->Instruction[i]);
            }
            for(int i = 0;i<curr_Recipe->ingr;i++)
            {
                printf("%s\n",curr_Recipe->Ingredients[i]);
            }
            puts("Would you like to bookmark this recipe? [yes/no]");
            char trash[5];
            scanf("%s",trash);
            if(strcmp(trash,"yes")==0)
            {
                curr_Recipe->bookmark = true;
            }
            flag = true;
            break;
        }
        curr_Recipe = curr_Recipe->next;
    }
    (flag) ? puts("") : puts("Recipe not found!");
    getchar();
    cookbook();
}

void NewRecipe()
{
    system("cls || clear");
    char nametemp[255], desctemp[255], instrtemp[20][255], ingrdtemp[20][255];
    int steps,ingr;
    puts("Enter name of recipe");
    scanf("%[^\n]", nametemp);
    getchar();


    puts("Enter recipe description");
    scanf("%[^\n]", desctemp);
    getchar();
    
    puts("Enter number of instruction");
    scanf("%d", &steps);
    
    puts("Enter cooking instructions");
    for(int i = 0;i<steps;i++)
    {
    	getchar();
        scanf("%[^\n]", instrtemp[i]);
    }
    
    puts("Enter amount of ingredient");
    scanf("%d", &ingr);
    
    puts("Enter cooking ingredients");
    for(int i = 0;i<ingr;i++)
    {
    	getchar();
        scanf("%[^\n]", ingrdtemp[i]);
    }
    
    pushRecipe(createRecipe(nametemp, desctemp, steps, ingr, instrtemp, ingrdtemp));
    puts("Recipe has been successfully made");
    getchar();
    getchar();
    cookbook();
}

void cookbook()
{
    system("cls || clear");
    puts("Cookbook");
    puts("1. Saved recipes");
    puts("2. Search recipe");
    puts("3. Insert new recipe");
    puts("4. Back to Home Page");
    int input;
    do
    {
        printf(">> ");
        scanf("%d", &input);
        getchar();
        switch (input)
        {
        case 1:
            SavedRecipes();
            break;
        case 2:
            SearchRecipes();
            break;
        case 3:
            NewRecipe();
            break;
        case 4:
            mainScreen();
            break;
        }
    } while (input < 1 || input > 4);
}
