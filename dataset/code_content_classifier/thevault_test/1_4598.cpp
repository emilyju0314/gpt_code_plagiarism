int dequeue(struct Queue* queue){
  if(isEmpty(queue)) return INT_MIN;
  int item = queue->array[queue->front];

  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}