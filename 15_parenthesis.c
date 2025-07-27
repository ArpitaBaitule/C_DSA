// #include <stdio.h>
// #include <stdlib.h>

// // Node structure for linked list
// struct Node {
//     char data;
//     struct Node* next;
// };

// // Stack structure using linked list
// struct Stack {
//     struct Node* top;
// };

// // Function to create a new node
// struct Node* newNode(char data) {
//     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//     node->data = data;
//     node->next = NULL;
//     return node;
// }

// // Function to create an empty stack
// struct Stack* createStack() {
//     struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
//     stack->top = NULL;
//     return stack;
// }

// // Function to push an element onto the stack
// void push(struct Stack* stack, char data) {
//     struct Node* node = newNode(data);
//     node->next = stack->top;
//     stack->top = node;
// }

// // Function to pop an element from the stack
// char pop(struct Stack* stack) {
//     if (stack->top == NULL) {
//         return '\0';
//     }
//     struct Node* temp = stack->top;
//     stack->top = stack->top->next;
//     char popped = temp->data;
//     free(temp);
//     return popped;
// }

// // Function to check if the stack is empty
// int isEmpty(struct Stack* stack) {
//     return stack->top == NULL;
// }

// // Function to check if the given character is an opening bracket
// int isOpeningBracket(char ch) {
//     return ch == '(' || ch == '{' || ch == '[';
// }

// // Function to check if the given character is a closing bracket
// int isClosingBracket(char ch) {
//     return ch == ')' || ch == '}' || ch == ']';
// }

// // Function to check if the two characters are matching brackets
// int isMatchingPair(char opening, char closing) {
//     return (opening == '(' && closing == ')') ||
//            (opening == '{' && closing == '}') ||
//            (opening == '[' && closing == ']');
// }

// // Function to check if brackets are balanced
// int areBracketsBalanced(char* expression) {
//     struct Stack* stack = createStack();
//     for (int i = 0; expression[i] != '\0'; i++) {
//         if (isOpeningBracket(expression[i])) {
//             push(stack, expression[i]);
//         } else if (isClosingBracket(expression[i])) {
//             if (isEmpty(stack) || !isMatchingPair(pop(stack), expression[i])) {
//                 return 0;  // Unbalanced
//             }
//         }
//     }
//     int balanced = isEmpty(stack);
//     free(stack);
//     return balanced;
// }

// // Main function
// int main() {
//     char expression[100];
//     printf("Enter an expression: ");
//     scanf("%s", expression);

//     if (areBracketsBalanced(expression)) {
//         printf("Brackets are balanced.\n");
//     } else {
//         printf("Brackets are not balanced.\n");
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr; // interger pointer which use to allocate dynamic memory
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!! Cannot push %d to the stack", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!! Cannot pop to the stack");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMatched(char *exp)
{
    // create and initilize stack
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp,'(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char * exp = "2+3*(4+1)";
    if(parenthesisMatched(exp))
    {
        printf("The Parethesis is matching");
    }
    else
    {
        printf("The Parethesis is not matching");
    }
    
    return 0;
}
