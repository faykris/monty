#include "monty.h"
/**
 * _pop - Function that remove the top element of the stack 
 * @stack: Elements past for stack
 * @lines: Lines of read past bytecodes
 * Return: None.
 **/
void _pop(stack_t **stack, unsigned int lines)
{
    stack_t *tmp;

    if (*stack == NULL)
    {
        printf("L%d: can't pop an empty stack",lines);
        free(f_struct.buffer);
		free_stack(stack);
		fclose(f_struct.fp);
		exit(EXIT_FAILURE);
    }
    else
    {
        tmp = *stack;
        *stack = (*stack) -> prev;
        (*stack) -> next=NULL;

        free(tmp);
    }
}
