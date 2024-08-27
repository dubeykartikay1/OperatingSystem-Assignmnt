#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct pcb {
    int id;
    char state;
    int time_;
    int flg;
    struct pcb *next;
};


struct pcb *getNode(int id, int time, char state) {
    struct pcb *new_node = (struct pcb *)malloc(sizeof(struct pcb));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->id = id;
    new_node->state = state;
    new_node->time_ = time;
    new_node->next = NULL;
    new_node->flg = 1;
    return new_node;
}


void enqueue(struct pcb **root, struct pcb *node) {
    if (*root == NULL) {
        *root = node;
    } else {
        struct pcb *temp = *root;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    printf("Process %d enqueued\n", node->id);
}


void display(struct pcb *root, const char *decor) {
    if (root == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct pcb *temp = root;
    while (temp != NULL) {
        printf("PCB %d %s", temp->id, decor);
        temp = temp->next;
    }
    printf("NULL\n");
}


int dequeue(struct pcb **root) {
    if (*root == NULL) {
        printf("Queue is empty, nothing to dequeue\n");
        return 0;
    }

    struct pcb *temp = *root;
    *root = (*root)->next;
    free(temp);

    printf("Process dequeued\n");
    return 1;
}

// Main function to demonstrate the PCB queue
int main() {
    struct pcb *root = NULL;

    struct pcb *node1 = getNode(101, 2, 'O');
    enqueue(&root, node1);

    struct pcb *node2 = getNode(102, 100, 'C');
    enqueue(&root, node2);

    struct pcb *node3 = getNode(103, 103, 'C');
    enqueue(&root, node3);

    struct pcb *node4 = getNode(104, 130, 'C');
    enqueue(&root, node4);

    printf("Displaying queue after enqueues:\n");
    display(root, " => ");

    dequeue(&root);
    dequeue(&root);

    printf("Displaying queue after dequeues:\n");
    display(root, " => ");

    dequeue(&root);
    dequeue(&root);

    printf("Displaying queue after final dequeues:\n");
    display(root, " => ");

    return 0;
}
