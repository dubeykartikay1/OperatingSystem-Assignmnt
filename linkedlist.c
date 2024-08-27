#include <stdio.h> 
#include <stdlib.h> 
 
// Structure for a linked list node 
typedef struct Node { 
    int value; 
    struct Node* previous; 
    struct Node* next; 
} Node; 
 
// Structure to manage the linked list 
typedef struct { 
    Node* head; 
    Node* tail; 
} ListManager; 
 
// Function to insert a new node in the linked list 
void insert_node(ListManager* list_manager, int value) { 
    Node* new_node = (Node*)malloc(sizeof(Node)); 
    new_node->value = value; 
    new_node->previous = NULL; 
    new_node->next = NULL; 
 
    if (list_manager->head == NULL) { 
        list_manager->head = new_node; 
        list_manager->tail = new_node; 
    } else { 
        list_manager->tail->next = new_node; 
        list_manager->tail = new_node; 
    } 
} 
 
// Function to remove a node at a given position in the linked list 
void remove_node(ListManager* list_manager, int position) { 
    if (position < 0) return; 
 
    Node* current_node = list_manager->head; 
    Node* previous_node = NULL; 
 
    for (int i = 0; current_node != NULL && i < position; i++) { 
        previous_node = current_node; 
        current_node = current_node->next; 
    } 
 
    if (current_node == NULL) return; 
 
    if (previous_node == NULL) { 
        list_manager->head = current_node->next; 
    } else { 
        previous_node->next = current_node->next; 
    } 
 
    if (current_node->next == NULL) { 
        list_manager->tail = previous_node; 
    } 
 
    free(current_node); 
} 
 
// Function to search for a value in the linked list 
int find_node(ListManager* list_manager, int value) { 
    Node* current_node = list_manager->head; 
    int position = 0; 
 
    while (current_node != NULL) { 
        if (current_node->value == value) { 
            return position; 
        } 
        position++; 
        current_node = current_node->next; 
    } 
    return -1; 
} 
 
// Function to sort the linked list 
void sort_list(ListManager* list_manager) { 
    int temp_array[100], count = 0; 
    Node* current_node = list_manager->head; 
 
    while (current_node != NULL) { 
        temp_array[count++] = current_node->value; 
        current_node = current_node->next; 
    } 
 
    // Simple bubble sort 
    for (int i = 0; i < count - 1; i++) { 
        for (int j = 0; j < count - i - 1; j++) { 
            if (temp_array[j] > temp_array[j + 1]) { 
                int temp = temp_array[j]; 
                temp_array[j] = temp_array[j + 1]; 
                temp_array[j + 1] = temp; 
            } 
        } 
    } 
 
    current_node = list_manager->head; 
    for (int i = 0; i < count; i++) { 
        current_node->value = temp_array[i]; 
        current_node = current_node->next; 
    } 
} 
 
// Function to print the linked list 
void display_list(ListManager* list_manager) { 
    Node* current_node = list_manager->head; 
    while (current_node != NULL) { 
        printf("%d -> ", current_node->value); 
        current_node = current_node->next; 
    } 
    printf("NULL\n"); 
} 
 
// Function to display the menu 
void display_menu() { 
    printf( 
        "\nLinked List Operations:\n" 
        "=========================\n" 
        "[1] Insert a value\n" 
        "[2] Remove a value by position\n" 
        "[3] Find a value\n" 
        "[4] Sort the list\n" 
        "[5] Display the list\n" 
        "[6] Exit\n" 
        "=========================\n" 
        "Select an option: " 
    ); 
} 
 
// Function to clear the console (for Windows) 
void clear_screen() { 
    system("cls"); 
} 
 
// Main function 
int main() { 
    ListManager list_manager = { NULL, NULL }; 
    int is_running = 1; 
 
    while (is_running) { 
        clear_screen(); 
        display_menu(); 
 
        int option; 
        scanf("%d", &option); 
 
        switch (option) { 
            case 1: { 
                int value; 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                insert_node(&list_manager, value); 
            } break; 
            case 2: { 
                int position;

printf("Enter position to remove: "); 
                scanf("%d", &position); 
                remove_node(&list_manager, position); 
            } break; 
            case 3: { 
                int value; 
                printf("Enter value to find: "); 
                scanf("%d", &value); 
                int position = find_node(&list_manager, value); 
                if (position == -1) { 
                    printf("Value %d not found.\n", value); 
                } else { 
                    printf("Value %d found at position %d.\n", value, position); 
                } 
                printf("Press any key to continue...\n"); 
                getchar(); 
                getchar(); 
            } break; 
            case 4: 
                sort_list(&list_manager); 
                break; 
            case 5: 
                display_list(&list_manager); 
                printf("Press any key to continue...\n"); 
                getchar(); 
                getchar(); 
                break; 
            case 6: 
                is_running = 0; 
                break; 
            default: 
                printf("Invalid option.\n"); 
                printf("Press any key to continue...\n"); 
                getchar(); 
                getchar(); 
        } 
    } 
 
    printf("Exiting...\n"); 
    return 0; 
}