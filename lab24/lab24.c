#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct stack {
	char arr[256];
	int top;
} stack;

typedef struct queue {
	char arr[256];
	int front, rear;
} queue;


void init_stack(stack* stack);
int is_stack_full(stack* stack);
int is_stack_empty(stack* stack);
int push(stack* stack, char val);
int pop(stack* stack, char* val);

void init_queue(queue* queue);
int is_queue_full(queue* queue);
int is_queue_empty(queue* queue);
int enqueue(queue* queue, char val);
int dequeue(queue* queue, char* val);

int main() {
	system("chcp 1251");
	char input[256];
	stack stack;
	queue queue;
	char* sep;
	int flag = 0;
	char stack_val, queue_val;

	init_stack(&stack);
	init_queue(&queue);
	printf("Введите две строки в формате s*w\n");
	fgets(input, sizeof(input), stdin);
	sep = strchr(input, '*');
	if (!sep) {
		printf("В строке нет разделителя '*'!");
	}
	*sep = '\0';
	char* s = input;
	char* w = sep + 1;
	for (int i = 0; i < strlen(s); i++) {
		push(&stack, s[i]);
	}
	for (int i = 0; i < strlen(w); i++) {
		enqueue(&queue, w[i]);
	}
	while (pop(&stack, &stack_val) && dequeue(&queue, &queue_val)) {
		if (stack_val != queue_val) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		printf("w не обратна s");
	}
	else {
		printf("w обратна s");
	}
}

void init_stack(stack* stack) {
	stack->top = -1;
}

int is_stack_full(stack* stack) {
	return stack->top == 255;
}

int is_stack_empty(stack* stack) {
	return stack->top == -1;
}

int push(stack* stack, char val) {
	if (!is_stack_full(stack)) {
		stack->arr[++stack->top] = val;
		return 1;
	}
	return 0;
}

int pop(stack* stack, char* val) {
	if (!is_stack_empty(stack)) {
		*val = stack->arr[stack->top--];
		return 1;
	}
	return 0;
}

void init_queue(queue* queue) {
	queue->front = 0;
	queue->rear = 0;
}

int is_queue_full(queue* queue) {
	return queue->rear == 256;
}

int is_queue_empty(queue* queue) {
	return queue->front == queue->rear;
}

int enqueue(queue* queue, char val) {
	if (!is_queue_full(queue)) {
		queue->arr[queue->rear++] = val;
		return 1;
	}
	return 0;
}

int dequeue(queue* queue, char* val) {
	if (!is_queue_empty(queue)) {
		*val = queue->arr[queue->front++];
		return 1;
	}
	return 0;
}