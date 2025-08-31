#include <iostream>
using namespace std;

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void push(int x) {
        if (isFull())
            cout << "Stack Overflow!" << endl;
        else
            arr[++top] = x;
    }

    void pop() {
        if (isEmpty())
            cout << "Stack Underflow!" << endl;
        else
            cout << "Popped: " << arr[top--] << endl;
    }

    void peek() {
        if (isEmpty())
            cout << "Stack is empty!" << endl;
        else
            cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty())
            cout << "Stack is empty!" << endl;
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, val;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; s.push(val); break;
            case 2: s.pop(); break;
            case 3: cout << (s.isEmpty() ? "Stack is Empty\n" : "Stack is not Empty\n"); break;
            case 4: cout << (s.isFull() ? "Stack is Full\n" : "Stack is not Full\n"); break;
            case 5: s.display(); break;
            case 6: s.peek(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}



#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> s;
    for (char c : str) s.push(c);

    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    return rev;
}

int main() {
    string str = "DataStructure";
    cout << "Original: " << str << endl;
    cout << "Reversed: " << reverseString(str) << endl;
    return 0;
}



#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(char ch : s) {
        // Opening brackets → push
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // Closing brackets → check match
        else if(ch == ')' || ch == '}' || ch == ']') {
            if(st.empty()) return false; // no matching opening

            char topCh = st.top();
            st.pop();

            if((ch == ')' && topCh != '(') ||
               (ch == '}' && topCh != '{') ||
               (ch == ']' && topCh != '[')) {
                return false; // mismatch
            }
        }
        // Ignore other characters
    }

    if(st.empty()) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if(isValid(expr))
        cout << "Valid Parentheses\n";
    else
        cout << "Invalid Parentheses\n";

    return 0;
}




#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to postfix
string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If operand, add to result
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
        // If '(', push to stack
        else if (c == '(') {
            st.push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }//IMPORTANT NOTE IF WE KNOW THE PARENTHESIS IS VALID THEN we dont need to check the stack is empty or not

        // If it is an operator
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}





#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string exp) {
    stack<int> st;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // If operand (digit), push to stack
        if (isdigit(c)) {
            st.push(c - '0');  // convert char digit to int
        }
        // If operator, pop two and apply
        else {
            int val2 = st.top();
             st.pop();
            int val1 = st.top();
             st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.top(); // final result
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit numbers): ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix) << endl;

    return 0;
}
