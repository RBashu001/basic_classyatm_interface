//this is an atm which do some basic task..
#include<iostream>
#include<cmath>
using namespace std;
void choice_window(int *t,int *c,int pi);
void cwdrl(int *t,int *c,int pi);
void cdpst(int *t,int *c,int pi);
string login(string name,int pi){
string n;
int p;
cout<<"\nUSERNAME: ";
cin>>n;
cout<<"PIN: ";
cin>>p;
system("CLS");
if(n==name && p==pi){
    cout<<"YOU HAVE LOGED IN.\n";
    return "granted";
    }
else {
    cout<<"INVALID USERNAME OR PIN!!.\nPLEASE RE-ENTER IT.";
    return login(name,pi);
}
}
void cdp(int *t,int *c,int pi){
    cout<<"1-->GO TO MAIN MENU\n 0-->EXIT\n";
    cin>>*t;
    system("CLS");
    if(*t==1)return choice_window(t,c,pi);
    else if(*t==0)cout<<"THANKS FOR USING @RBA_ATM.";
    return;
}
void choice_window(int *t,int *c,int pi){
    cout<<"PLEASE SELECT YOUR QUERY:\n"
    "1-->BALANCE ENQUIRY\n2-->CASH WITHDRAWL\n3-->CASH DEPOSIT\n0-->EXIT.\n";
    cin>>*t;
    system("CLS");
    if(*t==1){
    cout<<"YOUR CURRENT BALANCE IS: "<<*c<<endl;
    //return choice_window(t,c,pi);
    return cdp(t,c,pi);
    }
    else if(*t==2)cwdrl(t,c,pi);
    else if(*t==3)cdpst(t,c,pi);
    else if(*t==0){
        cout<<"THANKS FOR USING @RBA_ATM.";
        return;
    }
    else{
        cout<<"ERROR!! PLEASE SELECT FROM ABOVE MENTIONED CHOICES!!.";
        return choice_window(t,c,pi);
    }
    return;
}
void cwdrl(int *t,int *c,int pi){
    cout<<"TO CONTINUE ENTER YOUR PIN\n PIN: ";
    cin>>*t;
    if(*t==pi){
    cout<<"ENTER THE AMOUNT: ";
    cin>>*t;
    system("CLS");
    if(*t<=*c){
        *c=*c-*t;
        cout<<"WITHDRAWL OF RS."<<*t<<" SUCCESSFULL...\n"<<"PRESS 1 TO DISPLAY BALANCE ON SCREEN;\tPRESS 0 TO GO TO MAIN SCREEN\n";
        cin>>*t;
        if(*t==1){
            cout<<"AVAILABLE BALANCE IS: "<<*c<<endl;
            //return choice_window(t,c,pi);
            return cdp(t,c,pi);
        }   
            else return choice_window(t,c,pi);
    }
    else{
        cout<<"TRANSACTTION FAILED!! DUE TO INSUFFICIENT BALANCE!!\n";
        //return choice_window(t,c,pi);
        return cdp(t,c,pi);
    }
    }
    else{
        cout<<"TRANSACTTION FAILED!! DUE TO INCORRECT PIN\n";
        //return choice_window(t,c,pi);
        return cdp(t,c,pi);
    }
}
void cdpst(int *t,int *c,int pi){
    cout<<"TO CONTINUE ENTER YOUR PIN\n PIN: ";
    cin>>*t;
    if(*t==pi){
    cout<<"ENTER THE AMOUNT: ";
    cin>>*t;
    if(*t>=*c){
        *c=*c+*t;
        system("CLS");
        cout<<"SUCCESSFULLY DEPOSITED RS."<<*t<<"\nPRESS 1 TO DISPLAY BALANCE ON SCREEN;\tPRESS 0 TO GO TO MAIN SCREEN\n";
        cin>>*t;
        if(*t==1){
            cout<<"AVAILABLE BALANCE IS: "<<*c<<endl;
            //return choice_window(t,c,pi);
            return cdp(t,c,pi);
        }   
        else return choice_window(t,c,pi);
    }
    }
    else{
        cout<<"TRANSACTTION FAILED!! DUE TO INCORRECT PIN\n";
        //return choice_window(t,c,pi);
        return cdp(t,c,pi);
    }
}
int main(){
cout<<"JAI SRI RAM"<<endl;
int cash=0,temp,pi;
string name;
cout<<"WELCOME!! TO @RBA_ATM.\nPLEASE REGISTER TO CONTINUE.\nENTER YOUR USERNAME: ";
cin>>name;
cout<<"PLEASE CREATE YOUR 4 DIGIT PIN: ";
cin>>pi;
if(log10(pi)>=3 && log10(pi)<4){
system("CLS");
cout<<"YOU HAVE SUCCESSFULLY REGISTERED AS AN USER.";
cout<<" PLEASE LOGIN WITH REGISTERED CREDENTIAL.\n";
if(login(name,pi)=="granted")choice_window(&temp,&cash,pi);
}
else cout<<"ERROR!! ENTER A 4 DIGIT PIN.";
cout<<"\nMADE BY @RBASHUTOSH\n(STUDENT NIT SRINAGAR)";
return 0;
}