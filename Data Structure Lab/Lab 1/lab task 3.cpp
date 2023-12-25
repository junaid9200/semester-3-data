#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
	
	int temp [4][7];
	int *ptr = &temp[0][0];
	for(int i=0;i<4;i++){
		for(int j=0;j<7;j++){
			*ptr=(rand() % 15) + 16;
			ptr++;
		}
	}
	
	ptr = &temp[0][0];
	cout<<"Temperture Of Each Week:"<<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<7;j++){
			cout<<*ptr<<"\t";
			ptr++;
		}
		cout<<endl;
	}
	
	int week = 0;
	int day = 0;
	int max_temp = 0;
	int hottest_day;
	ptr = &temp[0][0];
	cout<<endl;
	for(week=0;week<4;week++){
		for(day=0;day<7;day++){
			if(*ptr > max_temp){
				max_temp = *ptr;
				hottest_day = day + 1;
			}
			ptr++;	
		}
		cout<<"The Hottest Day Of Week "<<week+1<<" Is Day "<<hottest_day<<" With Temperature: "<<max_temp<<" C"<<endl;
		max_temp = 0;
	}
}
