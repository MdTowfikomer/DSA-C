#include <stdio.h>
#define SIZE 10
#define EMPTY -1
#define DELETED -2

// linear probing technique

int hash_table[SIZE];

void init(void){
    for(int i = 0; i < SIZE; i++){
        hash_table[i] = EMPTY;
    }
}

int hash(int key){
    return key % SIZE;
}

void insert(int key){
    int index = hash(key);
    int first_deleted = -1;

    int i = 0;
    while(i < SIZE){
        int probe = (index + i) % SIZE;

        // to reuse the deleted index
        if(hash_table[probe] == DELETED && first_deleted == -1){
            first_deleted = probe;
        }

        // to check the duplicate
        if(hash_table[probe] == key){
            printf("key %d already exist..\n");
            return;
        }

        // main logic for insert
        if(hash_table[probe] == EMPTY){
            if(first_deleted != -1){
                hash_table[first_deleted] = key;
            } else{
                hash_table[probe] = key;
            }
            return;
        }
        i++;
    }  
    
    printf("Hash table is full. couldn't insert key %d\n", key);

}


int search(int key){
   int index = hash(key);
   int i = 0;
   
   while(i < SIZE){
       int probe = (index + i) % SIZE;

    if(hash_table[probe] == EMPTY){
        return -1;
    }

    if(hash_table[probe] == key){
        return probe;       // if element found return the index
    }
    i++;
   }

   return -1;
}


void delete(int key){
    int pos = search(key);

    if(pos == -1){
          printf("Key %d not found. Cannot delete.\n", key);
    } else{
        hash_table[pos] = DELETED;
         printf("Key %d deleted from index %d.\n", key, pos);
    }
}

void display(void){
    for(int i = 0; i < SIZE; i++){
        if(hash_table[i] == EMPTY){
            printf("[%d] = EMPTY\n", i);
        } else if(hash_table[i] == DELETED){
            printf("[%d] = DELETED\n", i);
        } else{
            printf("[%d] = %d\n", i, hash_table[i]);
        }
    }
    return;

}


int main(){ 

 init();

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    printf("\nSearching for 30...\n");
    int result = search(30);
    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found!\n");

    printf("\nDeleting 30 and 20...\n");
    delete(30);
    delete(20);

    display();

    printf("\nReinserting 60 and 70...\n");
    insert(60);
    insert(70);

    display();

    return 0;
}
