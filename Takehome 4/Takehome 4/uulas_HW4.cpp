#include <iostream>
#include <string>
#include <vector>
#include "strutils.h"
#include "randgen.h"
using namespace std;


struct movie {

	string name,year,genre;

};

void Mgenre (vector<movie> movies, string mgenre){
	vector<int> index;
	for (int i=0;i<movies.size();i++){
		string tgenre = movies[i].genre;
		ToLower(tgenre);
		string tmgenre = mgenre;
		ToLower(tmgenre);
		if(tgenre== tmgenre){
			index.push_back(i);
			
		}
	}
	if (index.size()!=0){
		cout<<mgenre<<" movies from newest to oldest:"<<endl;
	}
	else{
		cout<<"There are no "<<mgenre<<" movies!"<<endl;
	}
	
	for (int i=0;i<index.size();i++){
		for (int j=0;j<index.size();j++){
			if(movies[index[i]].year > movies[index[j]].year){
				int temp = index[i];
				index[i] = index[j];
				index[j]= temp;
			}
			if (movies[index[i]].year == movies[index[j]].year && movies[index[i]].name < movies[index[j]].name){
				int temp = index[i];
				index[i] = index[j];
				index[j]= temp;
			}
		}
	}
	int b = index.size();
	for(int i=0;i<index.size();i++){
		cout<<"Movie name: "<<movies[index[i]].name<< " Release Year: "<<movies[index[i]].year<<endl;
	}
	cout<<endl;
}

void Myear (vector<movie> movies, string year,string year2) {
	vector<int> index;
	for (int i=0;i<movies.size();i++){
		if(movies[i].year >= year && movies[i].year <= year2){
			index.push_back(i);
		}
	}
	
	for (int i=0;i<index.size();i++){
		for (int j=0;j<index.size();j++){
			if(movies[index[i]].year > movies[index[j]].year){
				int temp = index[i];
				index[i] = index[j];
				index[j]= temp;
			}
			if (movies[index[i]].year == movies[index[j]].year && movies[index[i]].name < movies[index[j]].name){
				int temp = index[i];
				index[i] = index[j];
				index[j]= temp;
			}
		}
	}
	if (index.size()!=0){
		if (year == year2){
			cout<<"Movies released in "<<year<<" from A to Z:"<<endl;
		}
		else{
			cout<<"Movies released between the years "<<year<<"-"<<year2<<" from A to Z with decreasing year ordering:"<<endl;
		}
	}
	else{
		if (year == year2){
			cout<<"There are no movies released in "<<year<<"!"<<endl;
		}
		else{
			cout<<"There are no movies released between "<<year<<"-"<<year2<<"!"<<endl;
		}
	}

	int b = index.size();
	for(int i=0;i<index.size();i++){
		if (year == year2){
			cout<<"Movie name: "<<movies[index[i]].name<< " Genre: "<<movies[index[i]].genre<<endl;
		}
		else{
			cout<<"Movie name: "<<movies[index[i]].name<<" Release Year: "<<movies[index[i]].year<< " Genre: "<<movies[index[i]].genre<<endl;
		}
	}
	cout<<endl;
}




int main(){

	string list;
	int choice; 
	vector<movie> movies;

	cout<<"Welcome to the movie recommender program!"<<endl<<endl;
	cout<<"Please enter the movie, year and genre list:"<<endl;
	cin>>list;
	int i=0;
	while (i <= list.rfind("|")){
		string list2;
		if (i==0){
			list2 = list.substr(i,list.find("|",i+1)-i);
		}
		else{
			list2 = list.substr(i+1,list.find("|",i+1)-(i+1));
		}
		movie tempm;
		tempm.name = list2.substr(0,list2.find(";"));
		tempm.year = list2.substr(list2.find(";")+1,list2.rfind(";")-(list2.find(";")+1));
		tempm.genre = list2.substr(list2.rfind(";")+1);
		movies.push_back (tempm);
		int a = list.find("|",i+1);
		i = a;
		
	}

	cout<<endl<<"Please select your action:"<<endl;
	cout<<"1. Select the genre of the movie that you want to watch"<<endl;
	cout<<"2. Select the year of the movie that you want to watch"<<endl;
	cout<<"3. Choose a random movie"<<endl;
	cout<<"4. Exit program"<<endl<<endl;

	bool flag = true;
	while (flag){
	cout<<"Enter your choice: ";
	cin>>choice;

	if (choice == 1){
		string mgenre;
		cout<<"Please enter the genre of the movie you want to watch: ";
		cin>>mgenre;
		cout<<endl;
		Mgenre(movies,mgenre);
	}
	else if (choice == 2){
		string year,year2;
		cout<<"Please enter the year of the movie you want to watch: ";
		cin>>year;
		
		if (year.find("-")==-1){
			year2 = year;
		}
		else{
			year2 = year.substr(year.find("-")+1);
			year = year.substr(0,year.find("-"));
		}
		Myear(movies,year,year2);
	}
	else if (choice == 3){
		RandGen rand;
		int index = rand.RandInt(movies.size());
		cout<<"Movie name: "<<movies[index].name<<" Release Year: "<<movies[index].year<<" Genre: "<<movies[index].genre<<endl<<endl;
	}
	else if (choice == 4){
		cout<<"Thank you..."<<endl;
		flag = false;
	}
	else{
		cout<<"Invalid action!"<<endl<<endl;
	}
	}
	return 0;
}