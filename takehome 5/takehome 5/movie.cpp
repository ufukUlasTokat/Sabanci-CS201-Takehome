#include <iostream>
#include "movie.h"
#include<string>



Movie::Movie(){
	name = " ";
	year = 0;
	genre = " ";
}

Movie::Movie(string n, int y, string g){
	name = n;
	year = y;
	genre = g;
}

void Movie::setName(string n){
	name = n;
}

void Movie::setGenre(string g){
	genre = g;
}

void Movie::setYear(int y){
	year = y;
}

string Movie::getName() const{
	return name;
}

string Movie::getGenre() const{
	return genre;
}

int Movie::getYear() const{
	return year;
}

void Movie::print() const{
	cout<<name<<" "<<year<<" "<<genre<<" "<<endl;
}