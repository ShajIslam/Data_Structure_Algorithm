#include <iostream>
#include <cstddef>
using namespace std;



class person{
    private: 
    string name;
   
  public:
  double salary;
  bool is_sup; 
  person(string value){
    name = value;
  }
  void display(){
    cout<<"Employee info:"<<endl;
	cout<<"Name: "<<name<<" Salary: "<<salary<<" Supervisor: "<<is_sup<<endl;
  }
};

typedef person p;

double increment(p *pointer){

    if( pointer == nullptr){
        return -999999;
    }
    double total = pointer->salary;
    if(pointer->is_sup){
        total = total + .2*pointer->salary;
    }
    return total;
    

}



int main(){

    string temp;
    cout<<"Enter the value of temp"<<endl;
    cin>>temp;

    p *p1, *p2;
    p1 = new p(temp);

    cin>>temp;
    p2 = new p(temp);

    p1->is_sup = true;
    p2->is_sup = false;

    cout<<"enter salary 1: ";
    cin>>p1->salary;
    cout<<"enter salary 2: ";
    cin>>p2->salary;

    p1->salary = increment(p1);
    p2->salary = increment(p2);

    p1->display();
    p2->display();
	

    delete p1;
    delete p2;

    return 0;
    



}