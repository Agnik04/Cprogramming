#include "sll.h"

int main()
{
    Node* head = NULL, *temp;

    int i, ch, value, count = 1, position;

    while(1)
    {
        printf("1: To add at beginning.\n");
        printf("2: To add at end.\n");
        printf("3: To print the list.\n");
        printf("4: To insert a value after a position.\n");
        printf("5: To delete a value after a position.\n");
        printf("6: To delete a value from the beginning.\n");
        printf("7: To reverse.\n");
        printf("8 To Exit.\n\n");

        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter the value to be inserted :");
                scanf("%d",&value);
                add_begin(&head, value);
                break;
            case 2:
                printf("Enter the value to be inserted :");
                scanf("%d",&value);
                append(&head, value);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                printf("Enter the position :");
                scanf("%d",&position);
                printf("Enter the value to be inserted :");
                scanf("%d",&value);
                
                temp = search(head, position);
                insert_after(temp, value);
                break;
            case 5:
            	printf("Enter the position :");
                scanf("%d",&position);
                
                temp = search(head, position);
                delete_after(temp);
                break;
            case 6:
            	delete_begin(&head);
            	break;
            case 7:
            	reverse(&head);
            	break;
            case 8:
                return 0;
            default : 
                printf("Invalid choise, choose once again");
                break;
        }
    }
    return 0;
}
