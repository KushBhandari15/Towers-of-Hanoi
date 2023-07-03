#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#define N 100
using namespace std;

class queue{
private:
    vector<string> moves;

public:
    void push(string movD){
        moves.push_back(movD);
    }

    void pop(){
        moves.erase(moves.begin());
    }
    string getFront(){
        return moves.front();
    }
    string getBack(){
        return moves.back();
    }
    void display()
        {
        for(int i; i<moves.size(); i++)
        {
            cout << moves[i] << " ";
        }
        cout << "\n" << endl;
    }
};



class hanoiGame : public queue{

private:
    vector<string> moves;
    int top1,top2,top3;
    int numDisk;
    int tower1[N];
    int tower2[N];
    int tower3[N];
    int noMoves=0;

public:

    hanoiGame(int n){
        numDisk=n;
        for (int i=0,j=n;i<n && j>0;i++,j--){
            tower1[i]=j;
        }

        for (int i=0;i<n;i++){
            tower2[i]=0;
            tower3[i]=0;
        }
        top1=numDisk-1;
        top2=top3=-1;
    }

    void push(string movD){
        moves.push_back(movD);
    }

    void pop(){
        moves.erase(moves.begin());
    }
    string getFront(){
        return moves.front();
    }
    string getBack(){
        return moves.back();
    }
    void display()
    {
        cout<<"\n\nThe moves played are:-"<<endl<<endl;
        for(int i=0; i<moves.size(); i++)
        {
            cout<<moves[i];
        }
        cout << "\n" << endl;
    }

    void displayTower(int tower[]){
        for (int i=0;i<numDisk;i++){
            cout<<tower[i]<<" ";
        }
        cout<<" - Tower"<<endl;
    }

    string movDesc(int sourceTowerNo, int targetTowerNo,int diskNo){
        char letters[]={'A','B','C'};
        stringstream ss;
        ss<<"Move "<<diskNo<<" from tower "<<letters[sourceTowerNo-1]<<" to tower "<<letters[targetTowerNo-1]<<endl;
        string s=ss.str();
        return s;
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
            cout<<targetTop<<endl;
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
                noMoves++;
                /* Move the nth disk from source to target*/
                int temp=pop1(getTower(sourceTowerNo),sourceTop);
                cout<<"Popped element : "<<temp<<endl<<endl;
                push1(temp,getTower(targetTowerno),targetTop);
                string str= movDesc(sourceTowerNo,targetTowerno,temp);
                push(str);
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

            displayTower(tower1);
            displayTower(tower2);
            displayTower(tower3);
            cout<<"########################"<<endl<<endl;
        }



    }

};

int main()
{


    cout<<endl<<endl<<"Enter the number of disks you want to add: ";
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
    a.display();

    return 0;
}
