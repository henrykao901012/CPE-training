#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
   int data;
   struct Node *nxt;
} Node;
Node *head = NULL, *tail = NULL;
int size = 0;
void insert(int data)
{
   Node *node = (Node *)malloc(sizeof(Node));
   node->nxt = NULL;
   node->data = data;
   if (!head)
   {
      head = node;
      tail = node;
   }
   else
   {
      tail->nxt = node;
      tail = tail->nxt;
   }
   ++size;
}
void printOut()
{
   if (!head)
      return;
   Node *cur = head;
   while (cur)
   {
      printf("%d ", cur->data);
      cur = cur->nxt;
   }
   printf("\n");
}
void del(Node **node)
{
   --size;
   if (!head)
      return;
   else if (*node == head)
      head = NULL;
   else
   {
      (*node)->nxt = NULL;
      free(*node);
   }
}
void solve()
{
   int n, a, b;
   // scanf("%d %d", &n, &b);
   // a = 1; b++;
   // b = 2;
   scanf("%d %d %d", &n, &a, &b);
   for (int i = 0; i < n; ++i)
      insert(i + 1);
   Node *cur = head, *prev = tail;
   for (int i = 0; i < a - 1; ++i)
   {
      prev = cur;
      cur = cur->nxt;
      if (!cur)
         cur = head;
   }
   while (size > 0)
   {
      // printf("%p\n", prev->nxt);
      if (size < n && prev->nxt)
         cur = prev->nxt;
      else if (size < n)
         cur = head;
      for (int i = 0; i < b - 1; ++i)
      {
         prev = cur;
         cur = cur->nxt;
         if (!cur)
            cur = head;
      }
      if (cur == head)
      {
         head = cur->nxt;
      }
      else if (cur == tail)
      {
         tail = prev;
         prev->nxt = NULL;
      }
      else
         prev->nxt = cur->nxt;
      printf("%d", cur->data);
      del(&cur);
      printf("%c", " \n"[size == 0]);
   }
}
int main()
{
   solve();
   return 0;
}