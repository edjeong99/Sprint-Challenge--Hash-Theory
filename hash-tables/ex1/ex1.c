#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE
  // add each element into hash table
  for (int i = 0; i < length; i++){
      // printf( " Insert= %d\n", weights[i]);

    hash_table_insert(ht, weights[i], i);
  }

  // check if there is an element that match limit when added
  for (int i = 0; i < length-1; i++ ){
    //get value for each element
    int first_index = i;
    int second_value = limit - weights[i];
    int second_index = hash_table_retrieve(ht, second_value);
 
    // printf( " first value = %d  Second Value = %d 1st_index = %d 2nd_index = %d\n", weights[i],second_value, first_index, second_index);

    if( second_index > -1){
      Answer *answer = malloc(sizeof(Answer));
      if(weights[i] >= second_value){
        answer->index_1 = first_index;
        answer->index_2 = second_index;
      }
      else {
        answer->index_1 = second_index;
        answer->index_2 = first_index;
      }

      
      destroy_hash_table(ht);
      return answer;
    }
 
  }
  
destroy_hash_table(ht);
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}
#endif
