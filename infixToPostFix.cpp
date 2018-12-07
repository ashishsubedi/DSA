#include<iostream>
#include<stack>
#include<string>


using namespace std;
string convertToPostfix(string ex){ // 2+32*2 -> 2 32 2 * +
    stack<char> s;
    string res;
    for(int i=0; i< ex.length(); i++){
        if(ex[i] == ' ') continue;

        if(IsNumericDigit(ex[i])){
            res+= ex[i];
        }else if(IsOperator(ex[i])){
            while(!s.empty() && HasHigherPrecedence(s.top(),ex[i])){
                res += s.top();
                s.pop();
            }
            s.push(ex[i]);

        }
        else if (ex[i] == '(') 
		{
			s.push(ex[i]);
        }       
        else if(ex[i] == ')') 
		{
			while(!s.empty() && s.top() !=  '(') {
				res += s.top();
				s.pop();
			}
			s.pop();
        }
        while(!s.empty()) {
		res += s.top();
		s.pop();
	    }

    return res;




    }
}
// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}
int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}

// Function to perform an operation and return output. 
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative. 
	// return false, if right associative. 
	// if operator is left-associative, left one should be given priority. 
	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}
bool IsNumericDigit(char C) 
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}
int main(){




    return 0;
}