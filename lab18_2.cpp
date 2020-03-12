//Modify function overlap() form lab18_1.cpp by using pointers as input arguments.
#include<iostream>
#include<cmath>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *,Rect *);

int main(){
	Rect R1, R2;

	cout << "Please input Rect 1 (x y w h): ";
	cin >> 	R1.x >> R1.y >> R1.w >> R1.h;
	cout << "Please input Rect 2 (x y w h): ";
	cin >> 	R2.x >> R2.y >> R2.w >> R2.h;
	
	
	cout << "Overlap area = " << overlap(&R1, &R2);	
	return 0;
}

double overlap(Rect *R1,Rect *R2){
	double wnew, hnew, topx, lowx, topy, lowy;
	
	if(R1->x > R2->x) lowx = R1->x;
	else lowx = R2->x;
	
	if(R1->x+R1->w < R2->x+R2->w) topx = R1->x+R1->w;
	else topx = R2->x+R2->w;
	
	if(topx < lowx) return 0;
	else{
		wnew = topx - lowx;

		if(R1->y > R2->y) topy = R2->y;
		else topy= R1->y;
		
		if(R1->y-R1->h > R2->y-R2->h) lowy = R1->y-R1->h;
		else lowy = R2->y-R2->h;
		
		if(topy < lowy) return 0;
		else{
			hnew = topy - lowy;
		}
		
	}
	return abs(wnew*hnew);
	
}