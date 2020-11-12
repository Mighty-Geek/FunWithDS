#include<iostream>
#include<cmath>
#include<windows.h>
using namespace std;


void display1(){

    //prints the colour-blocked horizontal line
    //ASCII value 176= graphic character(low density dotted)
    //ASCII value 177= graphic character(medium density dotted)
    //ASCII value 178= graphic character(high density dotted)

    char a=176,b=177,c=178;

    for(int i=0;i<114;++i) cout<<a<<b<<c;
    cout<<a<<b;

}

void display2(){

    //prints the colour-blocked vertical lines and message on the initial output screen
    //ASCII value 176= graphic character(low density dotted)
    //ASCII value 177= graphic character(medium density dotted)
    //ASCII value 178= graphic character(high density dotted)

    char a=176,b=177,c=178;

    for(int i=0;i<36;++i){

            //printing the left pole
            cout<<c<<b<<a;

            //for spaces and messages between two vertical poles on the output screen
            for(int j=0;j<165;++j) {

                    //printing message at the center of the output screen
                    if(i==15 && j==75) {
                            cout<<"SUDOKU SOLVER....";
                            j=91;          //updating j with respect to the length of the above message
                            continue;
                    }

                    //printing message at the centre of the output screen
                    if(i==17 && j==73) {
                            cout<<"Press 0 to continue.....";
                            j=96;          //updating j with respect to the length of the above message
                            continue;
                    }

                    //for spaces
                    cout<<" ";
            }

            //printing the right pole
            cout<<c<<b<<a<<endl;
    }
}

print(int arr[][9]){

    //prints the final output sudoku in boxes
    //ASCII value 201= box drawing character(double line, upper left corner)
    //ASCII value 187= box drawing character(double line, upper right corner)
    //ASCII value 200= box drawing character(double line, lower left corner)
    //ASCII value 188= box drawing character(double line, lower right corner)
    //ASCII value 205= box drawing character(double, horizontal line)
    //ASCII value 186= box drawing character(double, vertical line)

    char a=201, b=187, c=200, d=188, l=205, s=186;

    //to clear output screen
    system("CLS");

    //prints the colour-blocked top horizontal line
    display1();
    cout<<endl<<endl<<endl;

    //prints squares and sudoku
    for(int j=0;j<9;++j){

            //for spaces to align the output to centre
            for(int i=0;i<60;++i) cout<<" ";

            int n=0;      //for array column-wise traversal

            //prints top part of squares
            for(int i=0;i<9;++i){
                cout<<a<<l<<l<<l<<b;

                //to add space after each 3x3 block
                if(i%3==2) cout<<"  ";
            }
            cout<<endl;

            //for spaces to align the output to centre
            for(int i=0;i<60;++i) cout<<" ";

            //prints middle part of squares along with values
            for(int i=0;i<9;++i){
                cout<<s<<" "<<arr[j][n]<<" "<<s;
                ++n;
                //to add space after each 3x3 block
                if(i%3==2) cout<<"  ";
            }
            cout<<endl;

            //for spaces to align the output to centre
            for(int i=0;i<60;++i) cout<<" ";

            //prints bottom part of squares
            for(int i=0;i<9;++i){
                cout<<c<<l<<l<<l<<d;
                //to add space after each 3x3 block
                if(i%3==2) cout<<"  ";
            }
            cout<<endl;

            //to add space after each 3x3 block row
            if(j%3==2) cout<<endl;
    }
    cout<<endl;

    //prints the colour-blocked bottom horizontal line
    display1();
}

bool canplace(int a[][9],int i,int j,int n,int no){

    //to check whether we can place 'no' at i,j or not

    //to check rows and columns
	for(int x=0;x<n;++x){
		if(a[i][x]==no || a[x][j]==no) return false;
	}

	//to check 3x3 square containing 'no'
	int rn=sqrt(n);
	int sx=(i/rn)*rn;
	int sy=(j/rn)*rn;
	for(int x=sx;x<sx+rn;++x){
		for(int y=sy;y<sy+rn;++y){
			if(a[x][y]==no) return false;
		}
	}

	//return true since position i,j is fine for 'no'
	return true;
}

bool solvesudoku(int a[][9],int i,int j,int n){

    //if current row is equal to no. of rows
    //this means sudoku is solved and hence print the output
	if(i==n){
	    system("CLS");
        cout<<"Sudoku solved"<<endl<<endl;
		print(a);
		return true;
	}

	//if row ends, go to next row
	if(j==n) return solvesudoku(a,i+1,0,n);

	//if square already filled, go to next square
	if(a[i][j]!=0) return solvesudoku(a,i,j+1,n);

	//tests whether numbers 1-9 are suitable for position i,j in the sudoku
	for(int no=1;no<=n;++no){

        //to check whether we can place 'no' at i,j or not
		if(canplace(a,i,j,n,no)){
            //to check whether placing 'no' at i,j will help in solving the sudoku
			a[i][j]=no;
            //go to next square
			if(solvesudoku(a,i,j+1,n)) return true;
		}
	}

	//if none of the numbers helped in solving i,j position of sudoku then return false
	//again assign 0 to i,j position and go back to the previous position
	//back-tracking
	a[i][j]=0;
	return false;
}

int main() {

    //prints initial display screen
    display1();
    display2();
    display1();

    //for 0 input
    //used for changing the output screen according to the user's time-requirement
    int ch;
    cin>>ch;

    //to clear screen
    system("CLS");

	int a[9][9];
	char c='Y';

	//taking input as per the user's choice
	while(c=='y' || c=='Y'){

        //to clear output screen
        system("CLS");

        //to display top horizontal colour-blocked lines
        display1();

        cout<<endl<<endl<<"Enter the values of sudoku :"<<endl<<endl;

        //taking input values in a 2-D array
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                cin>>a[i][j];
            }
        }

        //adding extra lines
        for(int i=0;i<20;++i) cout<<endl;

        //to display bottom horizontal colour-blocked lines
        display1();

        //for 0 input
        //used for changing the output screen according to the user's time-requirement
        cout<<"Press 0 to continue.....";
        cin>>ch;

        //calling function to solve sudoku
        if(solvesudoku(a,0,0,9)==false){

            //prints the colour-blocked top horizontal line
            display1();
            cout<<endl<<endl<<endl<<"Can't be solved!!"<<endl<<endl;
        }

        //taking input as per the user requirements
        cout<<"Want to enter more(Y/N)? ";
        cin>>c;
	}
	return 0;
}
