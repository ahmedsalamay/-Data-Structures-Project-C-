#include<iostream>
#include<stack>
#include<string>


using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Type>
#include<iostream>
class stackType
{
public:
	const stackType<Type>& operator=(const stackType<Type>&);
	void initializeStack();

	bool isEmptyStack() const;


	bool isFullStack() const;

	void push(const Type& newItem);
	Type top() const;
	void pop();
	stackType(int stackSize = 100);
	stackType(const stackType<Type>& otherStack);
	~stackType();

private:
	int maxStackSize; //variable to store the maximum stack size
	int stackTop; //variable to point to the top of the stack
	Type *list; //pointer to the array that holds the stack elements
	void copyStack(const stackType<Type>& otherStack);
	};

template <class Type>

void stackType<Type>::initializeStack()
{
	stackTop = 0;
}//end initializeStack

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
	return(stackTop == 0);
}//end isEmptyStack

template <class Type>
bool stackType<Type>::isFullStack() const
{
	return(stackTop == maxStackSize);
} //end isFullStack

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
	if (!isFullStack())
	{
		list[stackTop] = newItem; //add newItem at the top
		stackTop++;   //increment stackTop
	}
	else
		cout << "Cannot add to a full stack." << endl;
}//end push

template <class Type>
Type stackType<Type>::top() const
{
	if (stackTop == 0)
		return 0;

	return list[stackTop - 1];
}

template <class Type>
void stackType<Type>::pop()
{
	if (!isEmptyStack())
		stackTop--;    //decrement stackTop
	else
		cout << "Cannot remove from an empty stack." << endl;
}
//end pop
template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;
	list = new Type[maxStackSize];
	//copy otherStack into this stack

	for (int j = 0; j < stackTop; j++)
		list[j] = otherStack.list[j];
}
 //end copyStack
template <class Type>
stackType<Type>::stackType(int stackSize)
{
	if (stackSize <= 0)
	{
		cout << "Size of the array to hold the stack must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;
		maxStackSize = 100;
	}
	else
		maxStackSize = stackSize; //set the stack size to
	stackTop = 0; //set stackTop to 0
	list = new Type[maxStackSize]; //create the array to
	//hold the stack elements
}//end constructor
template <class Type>
stackType<Type>::~stackType() //destructor
{
	delete[] list; //deallocate the memory occupied
	//by the array
}//end destructor
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
	list = NULL;
	copyStack(otherStack);
}//end copy constructor
template <class Type>
const stackType<Type>& stackType<Type>::operator=
(const stackType<Type>& otherStack)
{
	if (this != &otherStack) //avoid self-copy
		copyStack(otherStack);
	return *this;
} //end operator=
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool openPrace(char c)
{
	if (c == '{' || c == '(' || c == '[') return true;
	return false;
}
bool closePrace(char c)
{
	if (c == '}' || c == ')' || c == ']') return true;
	return false;
}
bool matched(char o, char c)
{
	if (o == '{' && c == '}') return true;
	if (o == '(' && c == ')') return true;
	if (o == '[' && c == ']') return true;
	return false;
}

bool checkPraces(string exp)
{
	stackType<char> s;
	for (int i = 0; i<exp.length(); i++)
	{
		char c = exp[i];
		if (openPrace(c))
		{
			s.push(c);
		}
		else if (closePrace(c))
		{
			if (s.isEmptyStack()) return false;
			char tmp = s.top();
			if (matched(tmp, c)) s.pop();
			else return false;
		}
	}
	return s.isEmptyStack();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function to to check the operator and evaluate the resurlt of tow numbers
double evaluate(double a, double b, char c)
{
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '*') return a*b;
	if (c == '/') return a / b;
	//if (c == '%') return fmod(a, b);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool isOperator(char character);
double postEval(string exp)
{
	stackType<double> s;
	int res = 0, ten = 1,count=0;
	for (int i = 0; i < exp.length(); i++)
	{
		char c = exp[i];
		///////////////////////
		if (isdigit(c))
		{
			s.push(c - '0');
			count++;
		}//END  IF
		////////////////////////////////////////
		else if (c == '#'&&isdigit( exp[i-1]))
		{
			if (s.isEmptyStack())
			{
				cout << "Invalid"; return-1;
			}
			for (int i = 0; i < count;i++)
			{
				res = res + (s.top())*ten;
				ten *= 10;
				s.pop();
			}
			s.push(res); res = 0; count = 0,ten=1;
		}//END ESLE IF
		////////////////////////////////////////////
		else if ( isOperator(c)&&isdigit( exp[i-1]))
		{
			if (s.isEmptyStack())
			{
				cout << "Invalid"; return-1;
			}
			for (int i = 0; i < count; i++)
			{
				res = res + (s.top())*ten;
				ten *= 10;
				s.pop();
			}
			s.push(res); res = 0,count=0,ten=1;

			if (s.isEmptyStack())
			{
				cout << "Invalid"; return-1;
			}
			double sec = s.top();
			s.pop();
			if (s.isEmptyStack())
			{
				cout << "Invalid"; return-1;
			}
			double fir = s.top();
			s.pop();
			double res = evaluate(fir, sec, c);
			s.push(res);
		}//END ELSE IF
		//////////////////////////////////////////////////////////////////////////
		else if (isOperator(c) && (isOperator(exp[i - 1]) || exp[i - 1]=='#'))
		{
			if (s.isEmptyStack())
			{
				cout << "Invalid"; return-1;
			}
			double sec = s.top();
			s.pop();
			if (s.isEmptyStack())
			{
				cout << "Invalid"; return-1;
			}
			double fir = s.top();
			s.pop();
			double res = evaluate(fir, sec, c);

			s.push(res);
		}//END ELSE IF
	}//END FOR LOOP
		return s.top();

}//END FUNCTION
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Simply determine if character is one of the four standard operators.
bool isOperator(char character) {
	if (character == '+' || character == '-' || character == '*' || character == '/') {
		return true;
	}
	return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// If the character is not an operator or a parenthesis, then it is assumed to be an operand.
bool isOperand(char character) {
	if (!isOperator(character) && !openPrace(character)&&!closePrace(character)) {
		return true;
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Compare operator precedence of main operators.
// Return 0 if equal, -1 if op2 is less than op1, and 1 if op2 is greater than op1.
int compareOperators(char op1, char op2) {
	if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) { return -1; }
	else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) { return 1; }
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	// Empty character stack and blank postfix string.
	stackType<char> opStack;
	string postFixString = "";

	char input[100];
	// Collect input
	cout << "Enter an expression: ";
	cin >> input;
	// Get a pointer to our character array.
	char *cPtr = input;
	int  digit = 0;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Loop through the array (one character at a time) until we reach the end of the string.
	while (*cPtr != '\0') {
		// If operand, simply add it to our postfix string.
		// If it is an operator, pop operators off our stack until it is empty, an open parenthesis or an operator with less than or equal precedence.
		if (isOperand(*cPtr)) { postFixString += *cPtr; digit++; }
		else if (isOperator(*cPtr)) {
			postFixString += "#";
			while (!opStack.isEmptyStack() && opStack.top() != '('&& opStack.top() != '{' && opStack.top() != '['&& compareOperators(opStack.top(), *cPtr) <= 0) {
				postFixString += opStack.top();
				opStack.pop();
			}
			opStack.push(*cPtr);
		}
		// Simply push all open parenthesis onto our stack
		// When we reach a closing one, start popping off operators until we run into the opening parenthesis.
		else if (*cPtr == '(' || *cPtr == '{'||*cPtr == '[') { opStack.push(*cPtr); }
		else if (*cPtr == ')' || *cPtr == '}' || *cPtr == ']') {
			while (!opStack.isEmptyStack()) {
				if (opStack.top() == '(' || opStack.top() == '{' || opStack.top() == '[') { opStack.pop(); break; }
				postFixString += opStack.top();
				opStack.pop();
			}
		}

		// Advance our pointer to next character in string.
		cPtr++;
	}

	// After the input expression has been ran through, if there is any remaining operators left on the stack
	// pop them off and put them onto the postfix string.
	while (!opStack.isEmptyStack()) {
		postFixString += opStack.top();
		opStack.pop();
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Show the postfix string at the end.
	cout << "Postfix is: " << postFixString << endl;

	//if (checkPraces(input))
	if (checkPraces(input)&&digit!=0)
	{
		cout << postEval(postFixString)<<endl;
	}
	else cout << "Invalid -1"<<endl;

	return 0;
}
/*
Infix to postfix conversion in C++
Input Postfix expression must be in a desired format.
Operands and operator, both must be single character.
Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected.
*/


