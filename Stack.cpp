#include <iostream>
using namespace std;

#define n 5

typedef struct calculator
{
    int top;
    int memory[n];
} stack;
void initstack(stack *s){
    s->top=-1;
}
int empty_checker(stack *s)
{ // top = -1
    if (s->top == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
int full_checker(stack *s)
{ // top <-1
    if (s->top == n - 1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
void pop(stack *s)
{ // delete top value
    int delet_value, checker;
    checker = empty_checker(s);
    if (checker == 0)
    {
        delet_value = s->memory[s->top];
        s->top--;
    }
    else
    {
        cerr << "Error: The stack is empty" << endl;
    }
    cout << "Pop value:" << delet_value<<endl;
}
void push(stack *s, int var)
{ // insert var
    int checker;
    checker = full_checker(s);
    if (checker == 0)
    {
        s->top++;
        s->memory[s->top] = var;
    }
    else
    {
        cerr << "Error: Ther stack is full" << endl;
    }
}
void display(stack *s)
{
    cout << "Stack:" << endl;
    for (int i = 0; i <= s->top; i++)
    {
        cout << "Data in stack:" << i << ":" << s->memory[i]<<endl;
    }
}

int main()
{
    stack *s;
    s = (stack *)malloc(sizeof(stack *));
    initstack(s);
    int var, input;
    do
    {
        cout << "What you want to do:" << endl
             << "1: push" << endl
             << "2: pop"<<endl
             << "3: Display" <<endl
             << "0: stop" <<endl;
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "Enter variable:";
            cin >> var;
            push(s, var);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            display(s);
            break;
        case 0:
            cout << "Stop the operation"<<endl;
            break;
        default:
            cerr << "Error:";
            break;
        }

    } while (input != 0);
    cout << "Your final stack is::" << endl;
    display(s);
    free(s);
    return 0;
}
