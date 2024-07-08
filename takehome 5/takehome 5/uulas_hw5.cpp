#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "movie.h"
#include "strutils.h"
using namespace std;



int main(){
	
	vector<Movie> movie;

	cout<<"Welcome to the movie recommender program!"<<endl<<endl;

	string filename;
	cout<<"Please enter the movie list filename: ";
	cin>>filename;
	ifstream infile;
	infile.open(filename.c_str());
	while (infile.fail()){
		cout<<"Please check filename! Enter a correct movie list filename: ";
		cin>>filename;
		infile.open(filename.c_str());
	}

	string line;
	while (getline(infile, line)) {
		Movie temp;
		int a = line.rfind(" ");
		int b = line.rfind(" ",a-1);
		temp.setGenre(line.substr(a+1));
		temp.setYear(stoi(line.substr(b+1,a)));
		temp.setName(line.substr(0,b));
		movie.push_back(temp);
	 }

	for(int i = 0;i<movie.size();i++){
		for(int j = 0;j<movie.size();j++){
			if(movie[i].getYear()>movie[j].getYear()){
				Movie tempp = movie[i];
				movie[i]=movie[j];
				movie[j]=tempp;
			}
			if (movie[i].getYear()==movie[j].getYear()){
				if(movie[i].getName()<movie[j].getName()){
					Movie tempp2 = movie[i];
					movie[i]=movie[j];
					movie[j]=tempp2;
				}
			}
		}
	}
	for(int j = 0;j<movie.size();j++){
		string genretemp = movie[j].getGenre();
		if(genretemp.find('\r')!=-1){
			genretemp = genretemp.substr(0,genretemp.find('\r'));
			movie[j].setGenre(genretemp);
		}
	}

	cout<<"Please select your action:"<<endl;
	cout<<"1. Select the genre of the movie that you want to watch"<<endl;
	cout<<"2. Select the year of the movie that you want to watch"<<endl;
	cout<<"3. Exit program"<<endl<<endl;

	bool flag = true;
	while(flag==true){

		cout<<"Enter your choice: ";
		int choice;
		cin>>choice;

		if (choice == 1){
			string genre;
			cout<<"Please enter the genre of the movie you want to watch: ";
			cin>>genre;
			cout<<endl;
			int count = 0;
			vector<Movie> results;
 			for (int i = 0;i<movie.size();i++){
				string mgenre = LowerString(movie[i].getGenre());
				string tgenre = LowerString(genre);
				if(mgenre==tgenre){
					results.push_back(movie[i]);
					count= count+1;
				}
			}
			if(count==0){
				cout<<"There are no "<<genre<<" movies!"<<endl;
			}
			else{
				cout<<genre<<" movies from newest to oldest:"<<endl;
				for(int i = 0;i<results.size();i++){
					cout<<"Movie name: "<<results[i].getName()<<" Release Year: "<<results[i].getYear()<<endl;
				}
			}
			cout<<endl;
		}
		else if (choice == 2){
			string year;
			cout<<"Please enter the year of the movie you want to watch: ";
			cin>>year;
			vector<Movie> results;
			if(year.find("-")==-1){
				for (int i = 0;i<movie.size();i++){
					if(movie[i].getYear()==stoi(year)){
						results.push_back(movie[i]);
					}
				}
			}
			else{
				int year1 = stoi(year.substr(0,year.find("-")));
				int year2 = stoi(year.substr(year.find("-")+1));
				for (int i = 0;i<movie.size();i++){
					if(movie[i].getYear()>=year1&&movie[i].getYear()<=year2){
						results.push_back(movie[i]);
					}
				}
			}
			if (results.size()==0){
				cout<<"There are no movies released in "<<year<<"!"<<endl<<endl;
			}
			else{
				if(year.find("-")==-1){
					cout<<"Movies released in "<<year<<" from A to Z:"<<endl;
					for(int i = 0;i<results.size();i++){
						cout<<"Movie name: "<<results[i].getName()<<" Genre: "<<results[i].getGenre()<<endl;
					}
					cout<<endl;
				}
				else{
					cout<<"Movies released between the years "<<year<<" from A to Z with decreasing year ordering:"<<endl;
					for(int i = 0;i<results.size();i++){
						cout<<"Movie name: "<<results[i].getName()<<" Release Year: "<<results[i].getYear()<<" Genre: "<<results[i].getGenre()<<endl;
					}
					cout<<endl;
				}
			}
		}
		
		else if (choice == 3){
			cout<<"Thank you..."<<endl;
			flag = false;
		}
		else{
		cout<<"Invalid action!"<<endl<<endl;
		}
	}
	return 0;
}
