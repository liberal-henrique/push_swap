/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:07:26 by lliberal          #+#    #+#             */
/*   Updated: 2023/01/20 14:41:35 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int x;
  struct Node* next;
} Node;

void  insert_end(Node** root, int value)
{
  Node* new_node = malloc(sizeof(Node));
  if (new_node == NULL)
    exit(1);
  new_node->next = NULL;
  new_node->x = value;

  if (*root == NULL)
  {
    *root = new_node;
    return;
  }

  Node* curr = *root;
  while (curr->next != NULL)
    curr = curr->next;
  curr->next = new_node;
}

void  deallocate (Node **root)
{
  Node* curr = *root;
  while (curr != NULL)
  {
    Node* aux = curr;
    curr = curr->next;
    free(aux);
  }
  *root = NULL;
}

void  insert_beginning(Node** root, int value)
{
  Node* new_node = malloc(sizeof(Node));
  if (new_node == NULL)
    return;

  new_node->x = value;
  new_node->next = *root;

  *root = new_node;
}

void  insert_after(Node* node, int value)
{
  Node* new_node = malloc(sizeof(Node));
  if (new_node == NULL)
    return ;
  new_node->x = value;
  new_node->next = node->next;
  node->next = new_node;
}

void  insert_sorted(Node** root, int value)
{
  if (*root == NULL || (*root)->x >= value)
  {
    insert_beginning(root, value);
    return;
  }

  Node* curr = *root;
  while (curr->next != NULL)
  {
    if (curr->next->x >= value)
    {
      insert_after(curr, value);
      return;
    }
    curr = curr->next;
  }
  insert_after(curr, value);
}

void  remove_element(Node** root, int value)
{
  if (*root == NULL)
    return;
  Node* curr = *root;
  Node* to_remove;

  if ((*root)->x == value)
  {
    to_remove = *root;
    *root = (*root)->next;
    free(to_remove);
    return;
  }

  while(curr->next != NULL)
  {
    if (curr->next->x == value)
    {
      to_remove = curr->next;
      curr->next = curr->next->next;
      free(to_remove);
      return;
    }
    curr = curr->next;
  }
}

void  reverse(Node** root)
{
  Node* prev = NULL;
  Node* curr = *root;
  Node* next;

  while (curr != NULL)
  {
    next = curr->next;

    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *root = prev;
}

int	count(Node* root)
{
	Node	*curr;
	int		i;

	curr = root;
	i = 0;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int	count_recursively(Node* node)
{
	if (node == NULL)
		return (0);
	return (1 + count_recursively(node->next));
}

int main(int argc, char *argv[])
{
  Node* root = NULL;

  // insert_end(&root, 1);
  // insert_end(&root, 3);
  // insert_end(&root, 6);

  insert_sorted(&root, 12);
  insert_sorted(&root, 4);
  insert_sorted(&root, 1);
  insert_sorted(&root, 2);
  insert_sorted(&root, 10);
  insert_sorted(&root, 3);
  insert_sorted(&root, 5);
  insert_sorted(&root, 9);

  // Node* root = malloc(sizeof(Node));
  // if (root == NULL)
  //   return (0);
  // root->x = 15;
  // root->next = NULL;

  // insert_end(&root, -2);
  // insert_end(&root, 11);
  // insert_end(&root, 22);

  // insert_beginning(&root, 1);

  // insert_after(root, 7);

  for(Node* curr = root; curr != NULL; curr = curr->next)
    printf("%d\n", curr->x);

  printf("The Linked List has: %i\n", count_recursively(root));

  deallocate(&root);
  return (0);
}


// int main(int argc, char *argv[]) {
//   Node root;
//   Node element2;

//   root.x = 15;	insert_end(&root, 12);
//   root.next = malloc(sizeof(Node));
//   root.next->x = -2;
//   root.next->next = malloc(sizeof(Node));
//   root.next->next->x = 22;
//   root.next->next->next = NULL;

  // Node* curr = &root;
  // while (curr != NULL)
  // {
  //   printf("%d\n", curr->x);
  //   curr = curr->next;
  // }

  // for(Node* curr = &root; curr != NULL; curr = curr->next)
  // {
  //   printf("%d\n", curr->x);
  // }

  // free(root.next->next);
  // free(root.next);
  // return 0;
// }
