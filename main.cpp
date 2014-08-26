
/*
 * main.cpp
 *
 *  Created on: 23 Aug 2014
 *      Author: sander
 */
#include <iostream>
#include <string.h>
#include <math.h>

#define CIJFERNUM 3

using namespace std;

class student{

private:
	int C_total=0;
	int cijfer[CIJFERNUM];
	int index,C_count=0;
	double gemiddelde;

private:
	//bereken het gemiddelde
double middelen(){
	C_total+=this->cijfer[this->index];
	return (C_total / ++C_count);
	}

public:
	//invoer, vullen van array
	void SW_readpersoon(int *cijfer, int *index){
		this->index=*index; //class index update
		this->cijfer[this->index]=*cijfer;
		this->gemiddelde=middelen();
	}
	//uitvoer
	void SW_writepersoon(int *cijfer, int *index){
		this->index=*index; //class index update
		*cijfer=this->cijfer[this->index];
	}
	//krijg gemiddelde waarde
	void SW_gemiddelde(double *gemiddelde){
		*gemiddelde=this->gemiddelde;
	}

};

int main(void){
	student p;
	int cijfer[CIJFERNUM];

	//input: array wordt gevuld dmv readpersoon object

	for (int i=0;i<CIJFERNUM;i++){
	cout<<"cijfer :"<<i+1<<endl; cin>>cijfer[i];
	p.SW_readpersoon(&cijfer[i],&i);
	}

	//array wordt gekopieerd naar temperary dmv writepersoon object

	int tempcijfer[CIJFERNUM];
	for (int i=0;i<CIJFERNUM;i++){
	p.SW_writepersoon(&tempcijfer[i],&i);
	}

	double temp_gemiddelde;
	p.SW_gemiddelde(&temp_gemiddelde);

	//output

	for (int i=0;i<CIJFERNUM;i++){
	cout<<"opgevraagde cijfer :"		<<tempcijfer[i]<<endl;
	}
	cout<<"gemiddelde cijfer :"			<<temp_gemiddelde<<endl;
}




