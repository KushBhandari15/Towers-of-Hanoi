#include <iostream>
#include <cstdlib>
#include <algorithm>
#define SIZE 10
#define N 3
using namespace std;


//------------------------------------------------------TASK 1--------------------------------------------------------------------------------------------------
class Stack{
private:
    int top;
    int size;
    int *arr[SIZE];
public:
    Stack(int n){
        size=n;
        top=-1;
        for (int i=0;i<size;i++){
            arr[i]=0;
        }
    }

    bool isEmpty(){
        if (top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if (top==size-1i){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int *data){
        if (top>=(size-1)){
            throw "Stack Overflow";
        }
        else{
            top=top+1;
            arr[top]= data;
        }
    }

    int* pop(){
        if(top<0)
        {
            throw "Stack Overflow";
        }
        else
        {
            int *popValue=arr[top];
            arr[top]=0;
            top=top-1;
            return popValue;
        }
    }

    void display()
    {
        cout<<"The entered values in stack:\n";
        for(int i=top;i>=0;i--)
        {
            if (i==0){
                cout<<*arr[i];
            }
            else{
                cout<<*arr[i]<<" -> ";
            }

        }
        cout<<endl;
    }

    int length(){
        return top++;
    }


};

//------------------------------------------------------TASK 2----------------------------------------------------------------------------------------------------
class hanoiGame{

private:
    int top1,top2,top3;
    int numDisk;
    int tower1[N];
    int tower2[N];
    int tower3[N];
    int moves=0;

public:

    hanoiGame(int n){
        numDisk=n;
        for (int i=0,j=numDisk;i<numDisk && j>0;i++,j--){
            tower1[i]=j;
        }

        for (int i=0;i<numDisk;i++){
            tower2[i]=0;
            tower3[i]=0;
        }
        top1=numDisk-1;
        top2=top3=-1;
    }

    void displayTower(int tower[]){
        for (int i=0;i<numDisk;i++){
            cout<<tower[i]<<" ";
        }
        cout<<" - Tower"<<endl;
    }

    int getTop(int n){
        if (n==1){
            return top1;
        }
        else if(n==2){
            return top2;
        }
        else{
            return top3;
        }
    }

    int* getTower(int n){
        if (n==1){
            return tower1;
        }
        else if(n==2){
            return tower2;
        }
        else if(n==3){
            return tower3;
        }
    }

    bool gameOverCheck(){
        for (int i=0,j=numDisk;i<numDisk && j>0;i++,j--){
            if (tower3[i]==j){
            }
            else{
                return false;
            }
        }
        return true;
    }

    void updateTop1(int data){
        top1=data;
    }
    void updateTop2(int data){
        top2=data;
    }
    void updateTop3(int data){
        top3=data;
    }



    bool isEmpty(int top){
        if (top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(int top){
        if (top==numDisk-1){
            return true;
        }
        else{
            return false;
        }
    }

    int length(int top){
        return top++;
    }

    void push1(int data,int tower[],int &top){
        if (top>=(numDisk-1)){
            throw "Stack Overflow";
        }
        else{
            top=top+1;
            tower[top]=data;
        }
    }

    int pop1(int arr[], int &top){
        if(top<0)
        {
            throw "Stack Overflow";
        }
        else
        {
            int popValue=arr[top];
            cout<<popValue<<endl;
            arr[top]=0;
            top=top-1;
            return popValue;
        }
    }





    void singleMove(int sourceTowerNo, int targetTowerno){

        cout<<"Lets display tower"<<endl;
        int sourceTop=getTop(sourceTowerNo);
        int targetTop=getTop(targetTowerno);

        cout<<"Top of tower 1: "<<top1<<endl;
        cout<<"Top of tower 2: "<<top2<<endl;
        cout<<"Top of tower 3: "<<top3<<endl;
        bool illegalMove;
        if (isEmpty(sourceTop)){
            cout<<"Source tower is empty"<<endl;
            illegalMove=true;
        }

        if (!isEmpty(targetTop)){
            int temp1=getTower(sourceTowerNo)[sourceTop];
            int temp2=getTower(targetTowerno)[targetTop];
            if (temp1>temp2){
                cout<<"No disk may be placed on top of a disk that is smaller than it."<<endl;
                illegalMove=true;
            }
        }

        if(illegalMove){
            cout<<"Illegal move!! Please follow the rules"<<endl<<endl;
            return;
        }
        else {
            //if (abs(sourceTowerNo-targetTowerno)==1){
                moves++;
                /* Move the nth disk from source to target*/
                int temp=pop1(getTower(sourceTowerNo),sourceTop);
                cout<<"Popped element : "<<temp<<endl<<endl;
                push1(temp,getTower(targetTowerno),targetTop);
                if (sourceTowerNo==1){
                    updateTop1(sourceTop);
                }
                else if(sourceTowerNo==2){
                    updateTop2(sourceTop);
                }
                else if(sourceTowerNo==3){
                    updateTop3(sourceTop);
                }
                if (targetTowerno==1){
                    updateTop1(targetTop);
                }
                else if(targetTowerno==2){
                    updateTop2(targetTop);
                }
                else if(targetTowerno==3){
                    updateTop3(targetTop);
                }

            cout<<"Lets display the progress"<<endl<<endl;
            displayTower(tower1);
            displayTower(tower2);
            displayTower(tower3);
            cout<<endl;
            cout<<"########################"<<endl<<endl;
        }

    }


};

//-------------------------------------------------------MAIN------------------------------------------------------------------------------------------------------
int main()
{
    int taskno;
    cout<<"Do you wanna run Task 1, Task 2: ";
    cin>>taskno;

    if (taskno==1){
        cout<<"Time for Task 1\n\n";


        cout<<"Enter the number of elements you want to add to the stack: ";
        int n;
        cin>>n;
        Stack y(n);

        for (int i=0;i<n;i++){
            y.display();
            cout<<"Enter the element you want to add: ";
            int *t=new int;
            cin>>*t;
            y.push(t);
        }
        y.display();
        int choice;
        cout<<"Do you want to pop the last element(0-no/1-yes): "<<endl;
        cin>>choice;
        if (choice==1){
            cout<<endl<<"Lets pop the last element"<<endl;
            int* x = y.pop();
            cout<<endl<<"Element popped: "<<*x<<endl<<endl;
            y.display();
        }

    }

    if (taskno==2){
        cout<<endl<<endl<<"Time for Task 2\n\n";


        cout<<"Enter the number of disks you want to add: ";
        int n;
        cin>>n;
        hanoiGame a(n);
        cout<<"Lets play"<<endl;

        while (true){
            int temp;
            cout<<"Enter the source tower(1/2/3): "<<endl;
            cin>>temp;

            int sourceTowerTop=a.getTop(temp);
            int temp1;

            cout<<"Enter the target tower(1/2/3): "<<endl;
            cin>>temp1;
            int targetTowerTop=a.getTop(temp1);

            a.singleMove(temp,temp1);

            if (a.gameOverCheck()==true){
                cout<<"Game over! You have won"<<endl;
                break;
            }

            int choice;
            cout<<"Do you want to continue(0-no/1-yes)"<<endl;
            cin>>choice;
            if (choice==0){
                break;
            }

        }
    }

}
