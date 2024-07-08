#include <iostream>
#include <string>
#include <vector>
#include "strutils.h"
using namespace std;


void print(string board[3][3]){

	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
	cout<<"-----------"<<endl;
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
	cout<<"-----------"<<endl;
	cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}

bool checkFormat(string move){

	if(atoi(move.substr(0,1))<1||atoi(move.substr(0,1))>3){
		return false;
	}
	else{
		if (move.substr(1,1)!="-"){
			return false;
		}
		else{
			if (atoi(move.substr(2,1))<1||atoi(move.substr(2,1))>3){
			return false;
			}
			else{
				return true;
			}
		}
	}

}
void playerMove(string name,string symbol, string board[3][3]){

	string move;
	bool a = true;
	while(a){
		cout<<name<<", please enter your move: ";
		cin>>move;
		if (checkFormat(move)){
			int row = atoi(move.substr(0,1))-1;
			int column = atoi(move.substr(2,1))-1;
			if (board[row][column]==" "){
				board[row][column]=symbol;
				a = false;
			}
			else{
				cout<<"That location is already full!"<<endl;
				a = true;
			}
		}
		else{
			cout<<"Please enter correct move format!"<<endl;
			a = true;
		}
	}
}



bool CheckWinner(string board[3][3],string symbol){
	bool returncond = false;
	for (int i = 0;i<3&&!returncond;i++){
		if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol){
			 returncond = true;
		}
		else if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol){
			returncond = true;
		}
		else if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol){
			returncond = true;
		}
		else if (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol){
			returncond = true;
		}
	}
	return returncond;
}

void playGame(string player1,string symbol1,string player2,string symbol2,int & score1,int & score2){
	string board[3][3];
	for (int i =0;i<3;i++){
		for(int k =0;k<3;k++){
			board[i][k] = " ";
		}
	}
	int a =  0;
	while (a<9){
		a = a+1;
		playerMove(player1,symbol1,board);
		if(CheckWinner(board,symbol1)){
			cout<<player1<<" is the winner!"<<endl;
			score1 = score1+1;
			break;
		}	
		if (a==9){
			break;
		}
		cout<<"Current board: "<<endl;
		print(board);
		
	
		a = a+1;
		playerMove(player2,symbol2,board);
		if(CheckWinner(board,symbol2)){
			cout<<player2<<" is the winner!"<<endl;
			score2 = score2+1;
			break;
		}
		cout<<"Current board: "<<endl;
		print(board);
	}
	if (a==9){
		cout<<"The game ended in a draw!"<<endl;
	}
}


int main(){
	

	string name1,name2;
	string board[3][3];
	string board2[3][3];

	for (int i =0;i<3;i++){
		for(int k =0;k<3;k++){
			board[i][k] = " ";
			board2[i][k] = " ";
		}
	}

	cout<<"Welcome to Tic-Tac-Toe!"<<endl;
	cout<<"Player 1, please enter your name: ";
	cin>> name1;
	cout<<"Hello, "<<name1<<". You are going to play with X"<<endl;
	string symbol1 = "X";
	cout<<"Player 2, please enter your name: ";
	cin>>name2;
	cout<<"Hello, "<<name2<<". You are going to play with O"<<endl<<endl;
	string symbol2 = "O";

	cout<<"Starting a new game..."<<endl;
	cout<<"Current board: "<<endl;
	print(board);
	int score1 = 0;
	int score2 = 0;
	playGame(name1,symbol1,name2,symbol2,score1,score2);
	cout<<"Current Scores: "<<endl;
	cout<<name1<<": "<<score1<<"   "<<name2<<": "<<score2<<endl<<endl;
	cout<<"Starting a new game..."<<endl;
	cout<<"Current board: "<<endl;

	print(board2);
	playGame(name2,symbol2,name1,symbol1,score2,score1);
	cout<<"Current Scores: "<<endl;
	cout<<name1<<": "<<score1<<"   "<<name2<<": "<<score2<<endl<<endl;

	cout<<"Final Scores: "<<endl;
	cout<<name1<<": "<<score1<<"   "<<name2<<": "<<score2<<endl;

	if (score1>score2){
		cout<<name1<<" is the overall winner!"<<endl;
	}
	else if(score2>score1){
		cout<<name2<<" is the overall winner!"<<endl;
	}
	else{
		cout<<"The overall game ended in a draw!"<<endl;
	}
	return 0;

}