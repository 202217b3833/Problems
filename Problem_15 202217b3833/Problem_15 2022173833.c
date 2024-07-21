#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {

    char* key;
   
    char* value;
    struct node* next;
};

void setNode(struct node* node, char* key, char* value) {
    node->key = key;
    node->value = value;
    node->next = NULL;
}

struct hashMap {

    int numOfElements, capacity;
    struct node** arr;
};

void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;
    mp->numOfElements = 0;
    // array of size = capacity
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;
    }
}

// Hash function
int hashFunction(struct hashMap* mp, char* key) {
    int bucketIndex;
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++) {
        // sum = sum + (ascii value of char * (factor ^ x)) % capacity
        sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
        // factor = factor * 31 % __INT16_MAX__
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }
    bucketIndex = sum;
    return bucketIndex;
}

// Function to insert key-value pair into hash map
void insert(struct hashMap* mp, char* key, char* value) {
    // Getting bucket index for the given key-value pair
    int bucketIndex = hashFunction(mp, key);
    // Creating a new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    // Setting value of node
    setNode(newNode, key, value);
    // Bucket index is empty....no collision
    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else { // Collision
        // Adding newNode at the head of linked list at bucket index
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

// Function to delete key from hash map
void delete (struct hashMap* mp, char* key) {
    // Getting bucket index for the given key
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    // Points to the head of linked list present at bucket index
    struct node* currNode = mp->arr[bucketIndex];
    while (currNode != NULL) {
        // Key is matched at delete this node from linked list
        if (strcmp(key, currNode->key) == 0) {
            // Head node deletion
            if (currNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = currNode->next;
            } else { // Last node or middle node deletion
                prevNode->next = currNode->next;
            }
            free(currNode);
            mp->numOfElements--;
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Function to search for value associated with given key
char* search(struct hashMap* mp, char* key) {
    // Getting the bucket index for the given key
    int bucketIndex = hashFunction(mp, key);
    // Head of the linked list present at bucket index
    struct node* bucketHead = mp->arr[bucketIndex];
    while (bucketHead != NULL) {
        // Key is found in the hashMap
        if (strcmp(bucketHead->key, key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    // If no key found in the hashMap equal to the given key
    return "Oops! No data found.\n";
}

// Driver code
int main() {
    // Initialize the value of mp
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    // Inserting key-value pairs
    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    // Searching for values associated with keys
    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));
    // Key is not inserted
    printf("%s\n", search(mp, "randomKey"));

    printf("\nAfter deletion:\n");
    // Deleting key from hash map
    delete (mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));

    return 0;
}
