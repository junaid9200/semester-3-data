#include<iostream>
using namespace std;
int main(){
	char grid[3][3];
	char *ptr=&grid[0][0];
	int user_input;
	
	for(int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            grid[i][j] = '-';
        }
    }
	grid[3/2][3/2]='o';
	ptr=&grid[0][0];
	for(int i=0;i<3;++i) {
        for(int j=0;j<3;++j) {
            if (grid[i][j]!='o') {
                grid[i][j]=(rand()%2==1)?'x':'-';
            }
        }
    }
    
    ptr=&grid[1][1];
    cout<<"Chose a move, You are currently standing at center of the grid."<<endl;
    cout<<"1. Up"<<endl;
    cout<<"2. Down"<<endl;
    cout<<"3. Left"<<endl;
    cout<<"4. Right"<<endl;
    cout<<"\nYour Input: ";
    cin>>user_input;
    if(user_input==1){
    	ptr=ptr-3;
    	if(*ptr=='x'){
    		cout<<"Colided. You Lost!"<<endl;
		}
		else{
			cout<<"Moved at: -"<<endl;
			cout<<"\nSafe Place, You Won!"<<endl;
		}
	}
	if(user_input==2){
		ptr=ptr+3;
    	if(*ptr=='x'){
    		cout<<"Colided. You Lost!"<<endl;
		}
		else{
			cout<<"Moved at: -"<<endl;
			cout<<"\nSafe Place, You Won!"<<endl;
		}
	}
	if(user_input==3){
		ptr=ptr-1;
    	if(*ptr=='x'){
    		cout<<"Colided. You Lost!"<<endl;
		}
		else{
			cout<<"Moved at: -"<<endl;
			cout<<"\nSafe Place, You Won!"<<endl;
		}		
	}
	if(user_input==4){
		ptr=ptr-1;
    	if(*ptr=='x'){
    		cout<<"Colided. You Lost!"<<endl;
		}
		else{
			cout<<"Moved at: -"<<endl;
			cout<<"\nSafe Place, You Won!"<<endl;
		}		
	}
	cout<<"\nDisplaying Grid:"<<endl;
	for(int i=0;i<3;++i) {
        for(int j=0;j<3;++j) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

