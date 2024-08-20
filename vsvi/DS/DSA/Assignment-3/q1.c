#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long int myInt;

myInt prime_int = 1000003;


myInt getHash (myInt value) {
    return value % prime_int;
}

typedef struct Node {
    myInt index;
    myInt data;
    bool checked;
    struct Node* next;
} Node;

typedef struct hashTable {
    myInt size;
    struct Node** array;
} hashTable;

typedef struct simpleNode {
    myInt index;
    myInt data;
    struct simpleNode* next;
} simpleNode;

typedef struct LL{
    struct simpleNode* head;
    int size;
} LL;

struct Node* createNode(myInt index, myInt data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->index = index;
    newNode->data = data;
    newNode->checked = false;
    newNode->next = NULL;
    return newNode;
}

simpleNode* createSimpleNode(myInt index, myInt data) {
    simpleNode* newNode = (simpleNode*)malloc(sizeof(simpleNode));
    newNode->index = index;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

LL* initialiseLL() {
    LL* newLL = (LL*)malloc(sizeof(LL));
    newLL->head = NULL;
    newLL->size = 0;
    return newLL;
}

LL* insertLL(LL* newLL, simpleNode* newNode) {
    if (newNode != NULL) {
        if (newLL->head == NULL) {
            newLL->head = newNode;
        } else {
            simpleNode* temp = newLL->head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        newLL->size++;
    }
    return newLL;
}

hashTable* initializeHashTable(myInt size) {
    hashTable* newHashTable = (hashTable*)malloc(sizeof(hashTable));
    newHashTable->size = size;
    newHashTable->array = (Node**)malloc(prime_int * sizeof(struct Node*));

    for (myInt i = 0; i < prime_int; i++) {
        newHashTable->array[i] = NULL;
    }
    return newHashTable;
}

void insert(hashTable* newHashTable, myInt index, myInt value) {
    myInt hash_key = getHash(value);
    Node* newNode = createNode(index, value);
    if (newHashTable->array[hash_key] == NULL) {
        newHashTable->array[hash_key] = newNode;
    } else {
        Node* tempNode = newHashTable->array[hash_key];
        // while (tempNode->next != NULL) {
        //     tempNode = tempNode->next;
        // }
        newNode->next = tempNode;
        newHashTable->array[hash_key] = newNode;
    }
}

Node* findElement(hashTable* newHashTable, myInt value) {
    myInt hash_key = getHash(value);
    Node* current = newHashTable->array[hash_key];
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;    
    }
    return NULL;
}

Node* findGreaterIndexElement(hashTable* newHashTable, myInt value, myInt index) {
    myInt hash_key = getHash(value);
    Node* current = newHashTable->array[hash_key];
    while (current != NULL) {
        //printf("current:%d ",current->data);
        // printf("Did I even come here? with NODE: %lld, %lld\n", current->index, current->data);
        if (current->data == value && current->index > index) {
            return current;
        }
       current = current->next;
    }
    return NULL;
}

myInt returnBiggestint(hashTable* newHashTable, myInt index, myInt value, myInt* maxLen) {
    myInt currLen = 1;
    Node* current = findElement(newHashTable, value);
    if (current == NULL || current->checked) {
        return *maxLen;
    }
    current->checked = true;
    myInt currIndex = current->index;
    Node* newCurr = findGreaterIndexElement(newHashTable, value + 1, currIndex);
    myInt newCurrIndex = (newCurr != NULL) ? newCurr->index : 0;
    myInt tempint = value + 1;
    while (newCurr != NULL) {
        if (newCurrIndex > currIndex) {
            currIndex = newCurrIndex;
            currLen++;
            newCurr->checked = true;
            tempint += 1;
            Node* temp = findGreaterIndexElement(newHashTable, tempint, newCurrIndex);
            if (temp == NULL) {
                break;
            }
            newCurr = temp;
            newCurrIndex = newCurr->index;
        }
        else newCurr = newCurr->next;
    }
    if (currLen > *maxLen) {
        *maxLen = currLen;
        return index;
    }
    else return -1;

}


// LL* returnBiggestLL(hashTable* newHashTable, LL* existingLL, myInt value) {
//     LL* newLL = initialiseLL();
//     Node* current = findElement(newHashTable, value);
//     if (current == NULL || current->checked) {
//         return existingLL;
//     }

//     simpleNode* newSimpleNode = createSimpleNode(current->index, current->data);
//     newLL = insertLL(newLL, newSimpleNode);
//     current->checked = true;
//     myInt currIndex = current->index;
//     Node* newCurr = findGreaterIndexElement(newHashTable, value + 1, currIndex);
//     myInt newCurrIndex = (newCurr != NULL) ? newCurr->index : 0;
//     // printf("NewCurrIndex: %lld\n", newCurrIndex);
//     myInt tempint = value + 1;
//     while (newCurr != NULL) {
//         if (newCurrIndex > currIndex) // if (!newCurr->checked && newCurrIndex > currIndex) {
//             currIndex = newCurrIndex;
//             newSimpleNode = createSimpleNode(newCurr->index, newCurr->data);
//             newLL = insertLL(newLL, newSimpleNode);
//             newCurr->checked = true;
//             // printf("NewCurrIndex: %lld\n", newCurrIndex);
//             tempint += 1;
//             Node* temp = findGreaterIndexElement(newHashTable, tempint, newCurrIndex);
//             if (temp == NULL) {
//                 //insertLL(newLL, NULL);
//                 break;
//             }
//             newCurr = temp;
//             newCurrIndex = newCurr->index;
//         }


//     if (newLL->size > existingLL->size) {
//         while (existingLL->head != NULL) {
//             simpleNode* temp = existingLL->head;
//             existingLL->head = existingLL->head->next;
//             free(temp);
//         }
//         free(existingLL);
//         return newLL;
//     } else {
//         while (newLL->head != NULL) {
//             simpleNode* temp = newLL->head;
//             newLL->head = newLL->head->next;
//             free(temp);
//         }
//         free(newLL);
//         return existingLL;
//     }
// }

void display(hashTable* newHashTable) {
    for (myInt i = 0; i < newHashTable->size; i++) {
        printf("%lld: ", i);

        struct Node* current = newHashTable->array[i];

        while (current != NULL) {
            printf("(%lld, %lld, %d) ", current->index, current->data, current->checked);
            current = current->next;
        }

        printf("\n");
    }
}

void printLL(LL* currentLL) {
    printf("%d\n", currentLL->size);
    simpleNode* current = currentLL->head;
    while (current != NULL) {
        //printf("%lld, %lld ", current->index, current->data);
        printf("%lld ", current->index);
        current = current->next;
    }
    printf("\n");
}

int main() {
    myInt size;
    scanf("%lld", &size);
    hashTable* newHashTable = initializeHashTable(size);
    myInt* newArray = (myInt*)malloc(size * sizeof(myInt));
    for (myInt i = 0; i < size; i++) {
        scanf("%lld", &newArray[i]);
    }

    for(int i =size-1;i>=0;i--){
        //printf("value of:%lld",i);
        insert(newHashTable, i, newArray[i]);
    }
    //printf("out of hash");
    //display(newHashTable);

   // LL* biggestLL = initialiseLL();
    myInt maxLen = 1;
    myInt finIndex = 0;
    for (myInt i = 0; i < size; i++) {
        //printf("\nHave gotten to %lld\n", i);
        Node* temp = findElement(newHashTable, newArray[i]);
        //printf("Working at i:%d\n",i);
        if (temp->checked) {
            //printf("I am continuing at index: %lld\n", i);
            continue;
        }
        // else biggestLL = returnBiggestLL(newHashTable, biggestLL, newArray[i]);
        else {
            myInt tempIndex = returnBiggestint(newHashTable, i, newArray[i], &maxLen);
          //  printf("%lld\n",maxLen);
            if(tempIndex != -1) {
                finIndex = tempIndex;
            }
        }

        //printLL(biggestLL);
    }
       // printf("%lld\n", maxLen);
        // printf("FinIndex: %lld\n", finIndex);
       // printf("%d ",finIndex);
        int printer = newArray[finIndex]+1;
        int count=1;
        for(int i =finIndex+1;i<size;i++){
            if(newArray[i] == printer){
                count++;
                printer++;
            }
        }
        printf("%lld\n",count);
        printf("%d ",finIndex);
      printer = newArray[finIndex]+1;
         count=1;
        for(int i =finIndex+1;i<size;i++){
            if(newArray[i] == printer){
                printf("%d ",i);
                printer++;
            }
        }

    return 0;
}