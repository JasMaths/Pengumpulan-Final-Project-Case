struct Ingredients
{
	int quantity;
	char name[255];
	char type[255];
	Ingredients *next,*prev;
}*head_Ingredients, *tail_Ingredients, *curr_Ingredients;

int arrowFunc(int key, int position, int max, int min);
void arrowPosition(int realPost, int position), mainScreen(), clear(void), pantryScreen();
