#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#define N 100
using namespace std;

class game{
    private:
    int top1,top2,top3;
    int numDisk;
    int tower1[N];
    int tower2[N]={0};
    int tower3[N];
    int moves=0;

public:

    game(int n){
        numDisk=n;
        for (int i=0;i<n;i++){
            tower1[i]=i+11;
        }
        for (int low = 0, high = n - 1; low < high; low++, high--) {
            swap(tower1[low], tower1[high]);
        }
        top1=n-1;
        for (int i=0;i<n;i++){
            tower3[i]=i+31;
        }
        for (int low = 0, high = n - 1; low < high; low++, high--) {
            swap(tower3[low], tower3[high]);
        }
        top3=n-1;
        top2=-1;
    }

    int* getTower(int n){
        if (n==1){
            return tower1;
        }
        else if(n==2){
            return tower2;
        }
        else{
            return tower3;
        }
    }


    void singleMove(int sourceTowerNo, int targetTowerno){

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
            temp1 = temp1%10;//Returns the disk number of source tower
            temp2=temp2%10;//Returns the disk number of target tower
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

        }
        displayTower(tower1);
        displayTower(tower2);
        displayTower(tower3);

        cout<<"########################"<<endl<<endl;

    }

    bool gameOverCheck(){
        for (int i=0;i<numDisk;i++){
            if (tower3[i]==i+11){
            }
            else{
                return false;
            }
            if (tower1[i]==i+31){
            }
            else{
                return false;
            }
        }
        return true;
    }

    void displayTower(int tower[]){
        for (int i=0;i<numDisk;i++){
            tower[i]=tower[i]%10;
            cout<<tower[i]<<" ";
        }
        cout<<"- Tower"<<endl;
    }

    bool isEmpty(int top){
        if (top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(int top,int size){
        if (top==size-1){
            return true;
        }
        else{
            return false;
        }
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

    void updateTop1(int data){
        top1=data;
    }
    void updateTop2(int data){
        top2=data;
    }
    void updateTop3(int data){
        top3=data;
    }





};

int main()
{
        cout<<"Time for Task 3\n\n";


        cout<<"Enter the number of disks you want to add: ";
        int n;
        cin>>n;
        game a(n);
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

            if (a.gameOverCheck()){
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
        return 0;
}

