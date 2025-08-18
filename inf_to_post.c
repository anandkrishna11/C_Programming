#include <stdio.h>
#define max 100
int main(){
	char infix[100],postfix[100],stack[100];
	int top=-1;
	printf("Enter the postfix expression:");
	scanf("%s",infix);
	int i=0,j=0;
	char push(char c){
		if(top<(max-1)){
			top=top+1;
			stack[top]=c;
		}
	}
	char pop(){
		if(top==-1){
			return '\0';
		}
		else{
			char c=stack[top];
			top=top-1;
			return c;
		}
	}
	int isopr(char c){
		return(c=='+'||c=='-'||c=='/'||c=='^'||c=='*');
	}
	int precedence(char c){
		if(c=='^'){
			return 3;
		}
		else if(c=='*'||c=='/'){
			return 2;
		}
			
		else if(c=='+'||c=='-'){
			return 1;
		}
		else{
			return 0;
		}
	}
	while (infix[i]!='\0'){
		char c=infix[i];
		if(isopr(c)){
			while ((top!=-1 && isopr(stack[top]))&&(precedence(c)<precedence(stack[top]))){
				postfix[j]=pop();
				j++;
			}
			push(c);
		}
		else if(c=='('){
			push(c);
		}
		else if(c==')'){
			while(stack[top]!='('){
				postfix[j]=pop();
				j++;
			}
			pop();
		}
		else{
			postfix[j]=c;
			j++;
		}
	i++;
	}
	while(top!=-1){
		postfix[j]=pop();
		j++;
	}
	printf("Postfix Expression:%s\n",postfix);
	return 0;
}
				

