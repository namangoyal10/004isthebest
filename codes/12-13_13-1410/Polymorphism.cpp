#include<iostream>
#include<cstring>
using namespace std;


class Response{
private:
    string Ans1;
public:
    Response(){
        Ans1="Give me the specs";
    }
    void GetRedLabel(){
        cout<<Ans1;
    }
};

class FatherResponse: public Response{
public:
    void GetRedLabel(){
        Response::GetRedLabel();
        cout<<"(in ml)";
    }
};

class MotherResponse: public Response{
public:
    void GetRedLabel(){
        Response::GetRedLabel();
        cout<<"(in gms)";
        cout<<"I didn't get you what do you want?";
    }
};


int main(){
    Response r;
    r.GetRedLabel();cout<<endl;

    FatherResponse fr;
    fr.GetRedLabel();cout<<endl;

    MotherResponse mr;
    mr.GetRedLabel();cout<<endl;

    Response *rptr;
    char ch;
    cin>>ch;
    if (ch=='m')
        rptr=new MotherResponse;
    else if (ch=='f')
        rptr = new FatherResponse;
    else rptr = new Response;

    ///(*rptr).GetRedLabel();
    rptr->GetRedLabel();

}
