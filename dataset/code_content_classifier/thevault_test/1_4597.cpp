void enqueue(struct Queue* queue, int item) {
  if(isFull(queue)) return;
  queue->rear = (queue->rear + 1) % queue->capacity;

  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;

  cout << "enqueued to queue" << item << endl;
}