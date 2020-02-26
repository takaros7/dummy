#include "pzhelp.h"

class queue {
public:
  queue ()
  {
    front = rear = NULL;
  }

  bool empty ()
  {
    return front == NULL;
  }

  void enqueue (int x)
  {
    node *n = new node;
    n->data = x;
    n->next = NULL;
    if (rear == NULL)
      front = n;
    else
      rear->next = n;
    rear = n;
  }

  int dequeue ()
  {
    node *n = front;
    int result = n->data;
    if (front == rear)
      rear = NULL;
    front = front->next;
    delete n;
    return result;
  }

  int peek ()
  {
    return front->data;
  }

private:
  struct node {
    int data;
    node *next;
  };

  node *front, *rear;
};

//PROGRAM qposneg ()
int main ()
{
  queue q;
  int x;
  while (scanf("%d", &x) == 1)
    if (q.empty())
      q.enqueue(x);
    else {
      int y = q.peek();
      if (x * y > 0)
        q.enqueue(x);
      else if (x == -y)
        q.dequeue();
      else
        break;
    }
  if (q.empty())
    WRITELN("yes");
  else
    WRITELN("no");
}
