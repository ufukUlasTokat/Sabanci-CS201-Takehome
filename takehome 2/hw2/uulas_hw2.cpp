#include <iostream>
#include <string>
#include "strutils.h"
using namespace std;
/*
bool inputChecker(string expression){
	int sum = expression.find("+",1); 
	int sub = expression.find("-",1); 
	int equal = expression.find("=",1);
	int count = 0;
	int opr;
	if (equal < sum || equal < sub){
		return false;
	}
	if ((sum < sub && sum != -1) || (sum > sub && sub == -1)){
		opr = sum;
	}
	else if ((sub < sum && sub != -1) || (sub > sum && sum == -1)){
		opr = sub;
	}
	else{
		opr = 0;
	}
	equal = expression.find("=",opr);
	if (expression.substr(0,opr)!="0"){
		int num1 = atoi(expression.substr(0,opr));
		int a = 0;
		while (a<opr){
			if (expression.substr(a,1)!="0"&&expression.substr(a,1)!="-"&&expression.substr(a,1)!="+"){
				if (atoi(expression.substr(a,1))==0){
					return false;
				}
			}
			a = a+1;
		}

		if (num1 != 0){
			count = count + 1;
		}
		else {
			return false;
		}
	}
	else{
		int num1 = 0;
		count = count+1;
	}
	if (expression.substr(opr+1,equal-opr-1)!="0"){
		int num2 = atoi(expression.substr(opr+1,equal-opr-1));
		int a = 1;
		while (a<=equal-opr-1){
			if (expression.substr(opr+a,1)=="0"&&expression.substr(opr+a,1)=="-"&&expression.substr(opr+a,1)=="+"){
				if (atoi(expression.substr(opr+a,1))==0){
					return false;
				}
			}
			a = a+1;
		}
		if(num2 != 0){
			count = count+1;
		}
		else{
			return false;
		}
	}
	else{
		int num2 = 0;
		count = count+1;
	}
	if(expression.substr(equal+1)!="0"){
		int num3 = atoi(expression.substr(equal+1));
		int a = 1;
		int b = expression.length()-equal-1;
		while (a<b){
			if (expression.substr(equal+1+a,1)!="0"&&expression.substr(equal+1+a,1)!="-"&&expression.substr(equal+1+a,1)!="+"){
				if (atoi(expression.substr(equal+1+a,1))==0){
					return false;
				}
			}
			a = a+1;
		}
		if(num3 != 0){
			count = count+1;
		}
		else{
			return false;
		}
	}
	else{
		int num3 = 0;
		count = count+1;
	}
	if (count == 3){
		return true;
	}
	else {
		return false;
	}
}
*/

bool inputChecker(string expression){
	int len = expression.length();
	int a = 0;
	int b =0;
	int sum = expression.find("+",1); 
	int sub = expression.find("-",1); 
	int equal = expression.find("=",1);
	int opr;
	if ((sum < sub && sum != -1) || (sum > sub && sub == -1)){
		opr = sum;
	}
	else if ((sub < sum && sub != -1) || (sub > sum && sum == -1)){
		opr = sub;
	}
	else{
		opr = 0;
	}
	if (equal < opr){
		return false;
	}
	while (a<len){
		if (expression.substr(a,1)!="0"&&expression.substr(a,1)!="-"&&expression.substr(a,1)!="+"&&expression.substr(a,1)!="="){
			if (atoi(expression.substr(a,1))==0){
				return false;			
			}
			else {
				b = b+1;
			}
		}
		else{
			b = b+1;
		}
		a = a+1;
	}
	if (b==len){
		return true;
	}
	else{
		return false;
	}
}

int answerChecker(int num1 , int num2, int num3, string opr){
	if (opr == "+"){
		if(num3==num1+num2){
			return num3;
		}
		else{
			int num4 = num1+num2;
			return num4;
		}
	}
	else {
		if(num3==num1-num2){
			return num3;
		}
		else{
			int num4 = num1-num2;
			return num4;
		}
	}	
}


string questionParse(string expression,int joker,int time){
	if(inputChecker(expression)){
		int sum = expression.find("+",1);
		int sub = expression.find("-",1);
		int equal = expression.find("=",1);
		int opr;
		string opr2;
		if ((sum < sub && sum != -1) || (sum > sub && sub == -1)){
			opr = sum;
			opr2 = expression.substr(opr,1);
		}
		else if ((sub < sum && sub != -1) || (sub > sum && sum == -1)){
			opr = sub;
			opr2 = expression.substr(opr,1);
		}
		else {
			return expression.substr(0,equal);
		}
		int num1 = atoi(expression.substr(0,opr));
		int num2 = atoi(expression.substr(opr+1,equal-opr-1));
		int num3 = atoi(expression.substr(equal+1));
		if(answerChecker(num1,num2,num3,opr2) == num3){
			return expression;
		}
		else{
			if (time == 1){
				if  (joker == 0){
					cout<<"Sorry! The answer should have been: "<<answerChecker(num1,num2,num3,opr2)<<". You got -10 penalty points for this joker option."<<endl<<endl;
					return expression.substr(0,equal);
				}
				else{
					cout<<"Sorry! The answer should have been: "<<answerChecker(num1,num2,num3,opr2)<<". You got 0 points for this math expression."<<endl<<endl;
					return expression.substr(0,equal);
				}
			}
			else{
				return expression.substr(0,equal);
			}
		}
	}
	else {
		return"0";
	}
}


int main(){
	string expression;
	int i = 1;
	int joker = 0;
	int point = 0;
	while(i<5){
		cout<<"Please enter question #"<<i<<" and its answer: ";
		cin>>expression;
		if (inputChecker(expression)){
			if(questionParse(expression,0,0)==expression){
					cout<<"Correct answer! You got 25 points for this math expression."<<endl<<endl;
					point = point + 25;
			}
			else{
				if (joker==0){
					cout<<"Wrong!"<<endl<<"Would you like to use your joker option to correct the answer? ";
					string choice;
					cin>>choice;
					ToLower(choice);
					if (choice == "yes"){
						joker = joker+1;
						cout<<"Please enter the expression again: ";
						string expression2;
						cin>>expression2;
						if(inputChecker(expression2)){
							if (expression2.find(questionParse(expression,joker,0))==-1){
								cout<<"Different question! You got -10 penalty points for this joker option."<<endl<<endl;
								point = point -10;
							}
							else{
								if (questionParse(expression2,0,1)==expression2){
									cout<<"Correct answer! You got 25 points for this joker option."<<endl<<endl;
									point = point+25;
								}
								else{
									point = point -10;
								}	
							}
						}
						else{
							cout<<"Wrong input format! You got -10 penalty points for this joker option."<<endl<<endl;
							point = point-10;
						}
					}
					else{
						point = point;
						questionParse(expression,1,1);
					}
				}
				else{
					point = point;
					questionParse(expression,1,1);
				}
			}
		}
		else{
			cout<<"Wrong input format! You got -10 penalty points for this math expression."<<endl<<endl;
			point = point -10;
		}
		i = i + 1;
	}
	if (point<=0){
		point = 0;
	}
	cout<<"End of the program. You got "<<point<<" points in total."<<endl;;
	return 0;
}