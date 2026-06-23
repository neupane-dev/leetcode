/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 */



 #include <stdio.h>
 #include <stdlib.h>

 //Node structure for the hash table
 typedef struct Node
 {
    int key;
    int value;
    struct Node* next;
 } Node;

 //Hash table structure
 typedef struct
 {
    int size;
    Node** buckets;
 } HashTable;

 //Hash function
 int hash(int key,int size)
 {
    int h = key % size;
    return h < 0 ? h + size : h;
 }

 //Insert key-value pair into the hash table
 void insert(HashTable* table, int key, int value)
 {
    int index = hash(key, table->size);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
 }

 //Search for key inthe hash table
 Node* search(HashTable* table, int key)
 {
    int index = hash(key,table->size);
    Node* current = table->buckets[index];
    while(current != NULL)
    {
        if(current->key == key)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
 }

 //Free allocated memory for the hash table
 void freeTable(HashTable* table)
 {
    for(int i = 0; i < table->size; i++)
    {
        Node* current = table->buckets[i];
        while (current != NULL)     
        {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        
    }
    free(table->buckets);
 }
 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numSize, int target, int* returnSize)
{
    *returnSize = 2;
    int* result = (int*)malloc(2*sizeof(int));

    //Initialize has table size proportional to input size
    HashTable table;
    table.size = numSize*2;
    table.buckets = (Node**)calloc(table.size,sizeof(Node*));

    for(int i = 0; i < numSize; i++)
    {
        int complement = target - nums[i];
        Node* found = search(&table, complement);

        if(found != NULL)
        {
            result[0] = found->value;
            result[1] = i;
            freeTable(&table);
            return result;
        }

        insert(&table,nums[i],i);

        
    }
    //In case no solution is found
        freeTable(&table);
        *returnSize = 0;
        return NULL;
    
}


void runTestCase(int testNum, int* nums, int numsSize, int target) {
    int returnSize;
    int* result = twoSum(nums, numsSize, target, &returnSize);
    
    printf("Test Case %d:\n", testNum);
    printf("Input: nums = [");
    for(int i = 0; i < numsSize; i++) {
        printf("%d%s", nums[i], (i == numsSize - 1) ? "" : ", ");
    }
    printf("], target = %d\n", target);
    
    if (returnSize == 2) {
        printf("Output: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("Output: No solution found.\n");
    }
    printf("---------------------------\n");
}


int main()
{
// Example 1
    int nums1[] = {2, 7, 11, 15};
    runTestCase(1, nums1, 4, 9);

    // Example 2
    int nums2[] = {3, 2, 4};
    runTestCase(2, nums2, 3, 6);

    // Example 3
    int nums3[] = {3, 3};
    runTestCase(3, nums3, 2, 6);

    // Bonus Example: Negative numbers
    int nums4[] = {-1, -3, -5, 8};
    runTestCase(4, nums4, 4, -8);

    return 0;
}