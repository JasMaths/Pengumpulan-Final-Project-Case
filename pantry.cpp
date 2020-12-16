void checkIngredients()
{
	int i = 1;
	if(!head_Ingredients)
	{
		puts("There are no ingredients in the pantry!");
	}
	else
	{
		curr_Ingredients = head_Ingredients;
		while(curr_Ingredients)
		{
			 puts("============================================");
			 printf("No: %d\n", i);
			 printf("Name: %s\n", curr_Ingredients->name);
			 printf("Type: %s\n", curr_Ingredients->type);
			 printf("Quantity: %d\n", curr_Ingredients->quantity);
			 puts("============================================\n");
			 i++;
			 curr_Ingredients = curr_Ingredients->next;
		 }
	}
	puts("Press enter to continue...");
	getchar();
}

bool checkName(char *name)
{
	curr_Ingredients = head_Ingredients;
	while(curr_Ingredients)
	{
		if(strcmp(name, curr_Ingredients->name) == 0)
		{
			return true;
		}
		curr_Ingredients = curr_Ingredients->next;
	}
    return false;
}

void checkType(char *type)
{
	int i = 1;
	bool flag = false;
	curr_Ingredients = head_Ingredients;
	while(curr_Ingredients)
	{
		if(strcmp(type, curr_Ingredients->type) == 0)
		{
			if(!flag)
			{
				puts("This is what we found:");
				flag = true;
			}
			puts("============================================");
			printf("No: %d\n", i);
			printf("Name: %s\n", curr_Ingredients->name);
			printf("Type: %s\n", curr_Ingredients->type);
			printf("Quantity: %d\n", curr_Ingredients->quantity);
			puts("============================================\n");
			i++;
		}
		curr_Ingredients = curr_Ingredients->next;
	}
	if(!flag)
	{
		printf("There is no type \"%s\" in the pantry!\n", type);
	}
	return;
}

void searchByName()
{
	char name[255] = " ";
	puts("\nPlease input the name!");
	printf("Input >> ");
	scanf("%[^\n]", &name);
	clear();
	(checkName(name)) ? printf("This is what we found:\n============================================\nName: %s\nType: %s\nQuantity: %d\n============================================\n", name, curr_Ingredients->type, curr_Ingredients->quantity) : printf("There is no name \"%s\" in the pantry!\n", name);
	puts("\nPress enter to continue...");
	getchar();
	getchar();
}

void searchByType()
{
	char type[255] = " ";
	puts("\nPlease input the type!");
	printf("Input >> ");
	scanf("%[^\n]", type);
	clear();
	checkType(type);
	puts("Press enter to continue...");
	getchar();
	getchar();
}

void searchIngredients()
{
	int input;
	do
	{
	 clear();
	 puts("Please select your type of search:");
	 puts("1. Search by name");
	 puts("2. Search by type");
	 puts("3. Leave");
	 puts("============================================");
	 printf("Input >> ");
	 scanf("%d", &input);
	}while(input < 1 || input > 3);
	switch(input)
	{
		case 1:
		getchar();
		searchByName();
		break;
		case 2:
		getchar();
		searchByType();
		break;
		case 3:
		getchar();
		return;
	}
}

bool verifyString(char *name, char *type)
{
	int leng = strlen(name);
	bool flag = true;
	if(leng < 5 || leng > 100)
	{
		(leng < 5) ? puts("SYSTEM: Name is too short!") : puts("SYSTEM: Name is too long!");
		flag = false;
	}
	for(int i = 0;i < leng;i++)
	{
		if(name[i] == ' ' || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z'))
		{
			continue;
		}
		else
		{
			puts("SYSTEM: Name must only in alphabet form!");
			flag = false;
			break;
		}
	}
	if(strcmp("name", type) == 0 && checkName(name))
	{
		puts("SYSTEM: Duplicate name detected!");
		flag = false;
	}
	return flag;
}

bool verifyQuantity(int a)
{
	if(a < 1 || a > 999)
	{
		puts("SYSTEM: Quantity must strictly 1 - 999!");
		return false;
	}
	return true;
}

Ingredients *createIngredient(char *name, char *type, int quantity)
{
	Ingredients *temp = (Ingredients*)malloc(sizeof(Ingredients));
	strcpy(temp->name, name);
	strcpy(temp->type, type);
	temp->quantity = quantity;
	temp->next = temp->prev = NULL;
	return temp;
}

void insertIngredient(struct Ingredients *temp)
{
    if(!head_Ingredients)
    {
    	head_Ingredients = tail_Ingredients = temp;
	}else
	{
	   tail_Ingredients->next = temp;
       temp->prev = tail_Ingredients;
       tail_Ingredients = temp;
	}
}

void addNewIngredients()
{
	int quantity;
	char name[255], type[255];
	do
	{
		printf("Please input name ingredient[5...100]: ");
		scanf("%[^\n]", name);
		getchar();
	}while(!verifyString(name, (char*)"name"));
	
	do
	{
		printf("Please input type ingredient[5...100]: ");
		scanf("%[^\n]", type);
		getchar();
	}while(!verifyString(type, (char*)"type"));
	
	do
	{
		printf("Please input quantity ingredient[1...999]: ");
		scanf("%d", &quantity);
	}while(!verifyQuantity(quantity));
	insertIngredient(createIngredient(name, type, quantity));
	puts("Successfully add the ingredient!");
	puts("Press enter to continue...");
	getchar();
	getchar();
}

bool verifyStock(int n)
{
	if(n < 1 || n > 999)
	{
		puts("SYSTEM: Stock must strictly 1 - 999!");
		return false;
	}
	if(curr_Ingredients->quantity + n > 999 || curr_Ingredients->quantity + n < 1)
	{
		puts("SYSTEM: Pantry can only handle maximum stock [999]!");
		printf("This is your current stock of %s: %d\n", curr_Ingredients->name, curr_Ingredients->quantity);
		return false;
	}
	curr_Ingredients->quantity += n;
	return true;
}

void addStock()
{
	char name[255];
	int n;
	bool warn = false;
	if(!head_Ingredients)
	{
		puts("There are no ingredients in the pantry!");
		puts("Please add new ingredient first!");
		puts("Press enter to continue...");
		getchar();
	}
	else
	{
	do
	{
	  if(warn)
	  {
		puts("SYSTEM: Name not found!");
	  }
    printf("Input name of the ingredient[5...100]: ");
	scanf("%[^\n]", name);
	warn = true;
	getchar();
    }while(!checkName(name));
	
	do
	{
	printf("Input stock you want to add[1...999]: ");
	scanf("%d", &n);
    }while(!verifyStock(n));
    puts("\nSuccessfully add the stock!");
    puts("Press enter to continue...");
    getchar();
    getchar();
    }
}

void addIngredients()
{
	int input;
	do
	{
	 clear();
	 puts("Please select your type of add:");
	 puts("1. Add new ingredient");
	 puts("2. Add stocks");
	 puts("3. Leave");
	 puts("============================================");
	 printf("Input >> ");
	 scanf("%d", &input);
	}while(input < 1 || input > 3);
	switch(input)
	{
		case 1:
		getchar();
		clear();
		addNewIngredients();
		break;
		case 2:
		getchar();
		clear();
		addStock();
		break;
		case 3:
		getchar();
		return;
	}
}

void removeHead(){
   if(head_Ingredients && head_Ingredients == tail_Ingredients)
   {
	   head_Ingredients = tail_Ingredients = NULL;
	   free(head_Ingredients);
   }else
   {
	   Ingredients *temp = head_Ingredients->next; 
	   head_Ingredients->next = temp->prev = NULL; 
	   free(head_Ingredients);	
	   head_Ingredients = temp;			  
   }
}
void removeTail(){
   if(head_Ingredients && head_Ingredients == tail_Ingredients)
   {
	   head_Ingredients = tail_Ingredients = NULL;
	   free(head_Ingredients);
   }
   else
   {
		Ingredients *temp = tail_Ingredients->prev; 
		tail_Ingredients->prev = temp->next = NULL;
        free(tail_Ingredients);
		tail_Ingredients = temp;
   }
}
void removeName(char *name)
{
	bool flag = false;
	if(strcmp(name, head_Ingredients->name) == 0)
	{
		removeHead();
		flag = true;
	}
	else if(strcmp(name, tail_Ingredients->name) == 0)
	{
		removeTail();
		flag = true;
	}
	else
	{
		curr_Ingredients = head_Ingredients;
		while(curr_Ingredients)
		{
			if(strcmp(name, curr_Ingredients->name) == 0)
			{
					curr_Ingredients->prev->next = curr_Ingredients->next;
		            curr_Ingredients->next->prev = curr_Ingredients->prev;
	            	curr_Ingredients->next = curr_Ingredients->prev = NULL;
		            free(curr_Ingredients);
		            flag = true;
		            break;
			}
			curr_Ingredients = curr_Ingredients->next;
		}
	}
	(flag) ? puts("Successfully remove the ingredient!") : printf("There is no name \"%s\" in the pantry!\n", name);
	return;
}

bool removeType(char *type)
{
	if(!head_Ingredients)
	{
		return false;
	}
	if(strcmp(type, head_Ingredients->type) == 0)
	{
		removeHead();
		return true;
	}
	else if(strcmp(type, tail_Ingredients->type) == 0)
	{
		removeTail();
		return true;
	}
	else
	{
		curr_Ingredients = head_Ingredients;
		while(curr_Ingredients)
		{
			if(strcmp(type, curr_Ingredients->type) == 0)
			{
					curr_Ingredients->prev->next = curr_Ingredients->next;
		            curr_Ingredients->next->prev = curr_Ingredients->prev;
	            	curr_Ingredients->next = curr_Ingredients->prev = NULL;
		            free(curr_Ingredients);
		            return true;
			}
			curr_Ingredients = curr_Ingredients->next;
		}
	}
	return false;
}

void removeByName()
{
	char name[255] = " ";
	if(!head_Ingredients)
    {
    	puts("Looks like you have not add the ingredients yet!");
	}
	else
	{
	puts("\nPlease input the name!");
	printf("Input >> ");
	scanf("%[^\n]", name);
	getchar();
	clear();
	removeName(name);
    }
    puts("Press enter to continue...");
	getchar();
}

void removeByType()
{
	char type[255] = " ";
	if(!head_Ingredients)
    {
    	puts("Looks like you have not add the ingredients yet!");
	}
	else
	{
	bool flag = false;
	puts("\nPlease input the type!");
	printf("Input >> ");
	scanf("%[^\n]", type);
	getchar();
	clear();
	 while(removeType(type))
	 {
	 	flag = true;
	 }
	 (flag) ? puts("Successfully remove the ingredient!") : printf("There is no type \"%s\" in the pantry!\n", type);
    }
	puts("Press enter to continue...");
	getchar();
}

void removeIngredients()
{
	int input;
	do
	{
	puts("Please select your type of remove:");
	puts("1. Remove by name");
	puts("2. Remove by type");
	puts("3. Leave");
	puts("============================================");
	printf("Input >> ");
	scanf("%d", &input);
    }while(input < 1 || input > 3);
	switch(input)
	{
		case 1:
		getchar();
		removeByName();
		break;
		case 2:
		getchar();
		removeByType();
		break;
		case 3:
		getchar();
		return;
	}
}


void pantryScreen()
{
	bool pantry = true;
	while(pantry)
	{
	int position = 1, key = 0;
	while(key != ENTER)
	{
	clear();
	puts("\n\t\t   Pantry Menu");
    puts("\t=================================");
    arrowPosition(1, position); puts("Check Ingredients      #");
    arrowPosition(2, position); puts("Search Ingredients     #");
    arrowPosition(3, position); puts("Add Ingredients        #");
    arrowPosition(4, position); puts("Remove Ingredients     #");
    arrowPosition(5, position); puts("Exit Pantry            #");
    puts("\t=================================");
    key = getch();
	position = arrowFunc(key, position, 5, 1);
    }
    clear();
    switch(position)
    {
    	case 1:
    	checkIngredients();
    	break;
    	case 2:
    	searchIngredients();
    	break;
    	case 3:
    	addIngredients();
    	break;
    	case 4:
    	removeIngredients();
    	break;
    	case 5:
    	pantry = false;
    	mainScreen();
	}
    }
}
