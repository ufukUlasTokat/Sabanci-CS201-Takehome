/* Ufuk Ulas Tokat */
#include <iostream>
#include <string>
using namespace std;

int main () {
	
	float m,f,exam;
	float q1,q2,q3,q4,qa;
	float ql = 10;
	float h1,h2,h3,h4,h5,ha;
	float ratio, hf;
	float grade;
	string name;

	cout<<"The purpose of this program is to calculate your CS201 grade. What is your name? ";
	cin>> name;
	cout<<"Hello "<<name<<", what are your midterm and final exam grades? ";
	cin>>m>>f;
	exam = ((m*0.30)+(f*0.35))/0.65;
	if (exam < 30){
		cout<<name<<", your weighted exam average is less than 30, you will fail the course!"<<endl;
	}
	else {
		cout<<"What are the grades of your 5 homework? ";
		cin>>h1>>h2>>h3>>h4>>h5;	
		ha = (h1+h2+h3+h4+h5)/5;
		ratio = ha/exam;
		if (ratio <= 2){
			hf = ha;
			cout<<"You'll get all the points earned from homework!"<<endl;
		}
		else if (ratio > 2 && ratio < 3){
			hf = ha*(3-ratio);
			cout<<"You'll get "<<hf<<" from the points earned from homework!"<<endl;
		}
		else {
			hf = 0;
			cout<<"You'll get NONE of the points earned from homework!"<<endl;
		}
		cout<<"What are the grades of your 4 quizzes? If any, enter your grade as 0 for missed quizzes. ";
		cin>>q1>>q2>>q3>>q4;
		if (q1<ql){
			ql = q1;
		}
		if (q2<ql){
			ql = q2;
		}
		if (q3<ql){
			ql = q3;
		}
		if (q4<ql){
			ql = q4;
		}
		qa = (q1+q2+q3+q4-ql)/3;
		grade = (qa) + (hf*0.25) + (m*0.30) + (f*0.35);
		cout<<name<<", your grade for CS201 is: "<<grade<<endl;
	}

	return 0;
}