import java.util.*;
class Stack{
	String ar[] = new String[1000];
	int top = -1;
	void push(String data){
		if(isFull())
			return ;
		ar[++top] = data;
	}
	void pop(){
		if(isEmpty())
			return ;
		top--;
	}
	String top(){
		if(isEmpty())
			return "c";
		return ar[top];
	}
	boolean isEmpty(){
		return top == -1;
	}
	boolean isFull(){
		return top == 999;
	}

}
class postToInfix{
	public static void main(String ar[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter some string");
		Stack stk = new Stack();
		String s = sc.next();
		String result = "";

		for(int i = 0 ; i < s.length() ; i++)
		{
			if(s.charAt(i) == '+' ||s.charAt(i) == '-' ||s.charAt(i) == '/' ||s.charAt(i) == '*'){
				String operand1 = stk.top();
				stk.pop();
				String operand2 = stk.top();
				stk.pop();
				result = "("+operand2+String.valueOf(s.charAt(i))+operand1+")";
				stk.push(result);

			}
			else
				stk.push(String.valueOf(s.charAt(i)));
		}
			System.out.println(stk.top());
	}
}