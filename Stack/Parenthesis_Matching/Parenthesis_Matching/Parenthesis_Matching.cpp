#include <iostream>

using namespace std;

template <typename T>

class Stack
{
private:

    int size;
    int top;
    T* S;

public:

    Stack(int size)
    {
        this->size = size;
        this->S = new T[this->size];
        this->top = -1;
    }

    ~Stack()
    {
        delete []S;
    }

    void push(T x);
    T pop();
    T peek(int pos);
    T stackTop();
    int isEmpty();
    int isFull();
    void display();

};





// Push

template<class T>

void Stack<T>::push(T x)                                               // Template Class's Function's syntax is little different.
{
    if (top == size - 1)
    {
        cout << "\nStack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        S[top] = x;
    }
}

// Pop
template<class T>

T Stack<T>::pop()
{
    T x = -1;
    if (top == -1)
    {
        cout << "\nStack Underflow" << endl;
    }
    else
    {
        x = S[top];
        top--;
    }
    return x;
}

// Peek
template<class T>

T Stack<T>::peek(int pos)
{
    T x = -1;
    if (top - pos + 1 < 0 || pos <= 0)
    {
        cout << "\nInvalid Position" << endl;
    }
    else
    {
        x = S[top - pos + 1];
    }
    return x;
}

// Stack Top
template<class T>

T Stack<T>::stackTop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return S[top];
    }
}

// Checking Stack Empty

template<class T>

int Stack<T>::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

// Checking Stack Full

template<class T>

int Stack<T>::isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

// Display

template<class T>

void Stack<T>::display()
{
    int P = top;

    if (P == -1)
    {
        cout << "\n\nStack is Empty" << endl;
    }
    else
    {
        while (P != -1)
        {
            cout << S[P] << " ";
            P--;
        }
    }
}

    /***********************************************************************************************************************************************************************************************************/


// String length

int strlen(char* exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        i++;
    }
    return i;        
}

// Parenthesis Balancing

int isbalanced(char* exp)                       // This is not the Member function of our Stack, But it is Using our Stack.
{

    int x = strlen(exp);
    
    class Stack<char>st(x);                   // Creating Stack.       (Stack should be created seprately for this Function to work)

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            st.push('(');
        }

        else if (exp[i] == ')')
        {
            if (st.isEmpty())  return 0;                             // It means Extra closing Bracket.

            st.pop();
        }
    }

    return st.isEmpty() ? 1 : 0;                                    // It means Extra opening Bracket.
}

// Supplementry functions for "Infix to Postfix"

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' )
        return 0;
    else
        return 1;
}


int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;                                               // This is very important as we initially have '#'
}


// Infix to Postfix

char* I_to_P(char* infix)
{
    class Stack<char>stk(strlen(infix) + 2);
    stk.push('#');

    char* postfix = new char[strlen(infix) + 2];

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (precedence(infix[i]) > precedence(stk.stackTop()))               // "#" is initially added because Stack is initially empty and gives error here.
            {
                stk.push(infix[i++]);
            }
            else
            {
                postfix[j++] = stk.pop();
            }
        }
    }

    while (!stk.isEmpty())
    {
        postfix[j++] = stk.pop();
    }

    postfix[j] = '\0';

    return postfix;
}

// Supplementry Functions for "Infix to Postfix2"

int isOp(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        return 0;
    else
        return 1;
}

int pre_out(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
}

int pre_in(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    else
        return 0;                                // This is very important as we initially have '#'                              

                                                // ')' Doesn't have Instack Precedence as it is never Pushed inside the Stack.
}


// Infix to Postfix 2

char* I_to_P2(char* infix)
{
    class Stack<char>stk(strlen(infix) + 2);     
    stk.push('#');

    char* postfix = new char[strlen(infix) + 2];

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (isOp(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (pre_out(infix[i]) > pre_in(stk.stackTop()))               // "#" is initially added because Stack is initially empty and gives error here.
            {
                stk.push(infix[i++]);
            }
            else if (pre_out(infix[i]) == pre_in(stk.stackTop()))         // This is only for "(" inside        and         ")" outside case.
            {
                stk.pop();
                i++;
            }
            else                                                     // Less than.
            {
                postfix[j++] = stk.pop();
            }
        }
    }

    while (!stk.isEmpty() && stk.stackTop() != '(')
    {
        postfix[j++] = stk.pop();
    }

    postfix[j] = '\0';

    return postfix;
}

// Evaluation

int evaluate(char* postfix)
{
    Stack <int> st(strlen(postfix + 2));               // Error : Data Loss after entering in strlen() function.
    st.push('#');

    int x1, x2, r;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            st.push(postfix[i++] - '0');                // As we are pushing Numbers from character array into integer stack. for conversion purpose '0' is subtracted.
        }
        else
        {
            x2 = st.pop();
            x1 = st.pop();

            switch (postfix[i])
            {
            case '+': r = x1 + x2; st.push(r); break;
            case '-': r = x1 - x2; st.push(r); break;
            case '*': r = x1 * x2; st.push(r); break;
            case '/': r = x1 / x2; st.push(r); break;
            }
        }
    }
    return st.stackTop();
}


int main()
{
    int x = 0;
    cout << "\nEnter the Size of Stack : ";
    cin >> x;

    class Stack<int>st(x);

    
    int choice;
    do
    {
        cout << "\nEnter Choice : ";
        cout << "\n1]Push \n2]Pop \n3]Peek \n4]Is Empty \n5]Is Full \n6]Display \n7]Parenthesis Matching \n8]Infix to Postfix Convertion";
        cout << "\n9]Infix to Postfix Advanced \n10]Evaluating Postfix Expression";
        cout << "\n\nChoice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int x = -1;                                                              // Change the Data type according to data type of Class.
            cout << "\nElement : ";
            cin >> x;
            st.push(x);
            break;
        }

        case 2:
        {
            cout << "\nDeleted Element : " << st.pop() << endl;;
            break;
        }

        case 3:
        {
            int x = -1;
            cout << "\nPosition : ";
            cin >> x;

            cout << "\nElement : " << st.peek(x) << endl;
            break;

        }

        case 4:
        {
            if (st.isEmpty())
            {
                cout << "\nStack is Empty" << endl;
            }
            else
            {
                cout << "\nStack is not Empty" << endl;
            }
            break;
        }

        case 5:
        {
            if (st.isFull())
            {
                cout << "\nStack is Full" << endl;
            }
            else
            {
                cout << "\nStack is not Full" << endl;
            }
            break;
        }

        case 6:
        {
            cout << endl;
            cout << "\nStack : ";
            st.display();
            cout << endl;
            break;
        }

        case 7:
        {
            char exp[50] ;

            cout << "\nEnter the Expression : ";
            cin >> exp;

            if (isbalanced(exp))
            {
                cout << "\nEntered Expression has \"Balanced Parenthesis\"." << endl;
            }

            else
            {
                cout << "\nEntered Expression has \"Unbalanced Parenthesis\"." << endl;
            }

            break;

        }

        case 8:
        {
            cout << "\nNOTE : Only '+' , '-' , '*' , '/' Operators are allowd" << endl;

            char exp[50];

            cout << "\nEnter the Expression : ";
            cin >> exp;

            char* postfix = I_to_P(exp);

            cout << "\nConverted Expression : " << postfix << endl;

            break;

           
        }

        case 9:
        {
            cout << "\nNOTE : Only '+' , '-' , '*' , '/' , '^' , '(' , ')'  Operators are Allowd" << endl;

            char exp[50];

            cout << "\nEnter the Expression : ";
            cin >> exp;

            char* postfix = I_to_P2(exp);

            cout << "\nConverted Expression : " << postfix << endl;

            break;
        }

        case 10:
        {
            cout << "\nNOTE : Only '+' , '-' , '*' , '/' Operators are allowd" << endl;

            /*char exp[50];

            cout << "\nEnter the Postfix Expression : ";
            cin >> exp;*/

            /*char* postfix = "234*+" ;

            cout << "\nAnswer : " << evaluate(exp) << endl;*/

            break;
        }



        
        }
    } while (choice > 0);

}
