#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include <iostream>
#include <list>
using namespace std;
/*
    定义一个list列表存储方程的表达式    
*/
typedef list<double> Expression;
void Enter(Expression *expression);
double GetValue(int number, double x);
double DerivativeValue(double x, Expression *expression);
double GetFunctionValue(double x, Expression *expression);
double NewtonIterator(Expression *expression, double x0, int time);



int main() {
    Expression *expression = new Expression();
    Enter(expression);
    cout<<"Choise the serves:[root/value]"<<endl;
    string str;

    while(cin>>str){
    
        if(str == "root"){
            int time;
            cout<<"You can enter iterate time and the default x0 is 1:"<<endl;
            while(cin>>time){
                cout<<NewtonIterator(expression, 1, time)<<endl;
                cout<<"Finish"<<endl;
            }
        }
        else if(str == "value"){
            double x;
            cout<<"Enter x:"<<endl;
            while(cin>>x){
                cout<<GetFunctionValue(x,expression)<<endl; 
                cout<<"Finish"<<endl;
            }
        }
        else cout<<"No such serves"<<endl;
        cout<<"Serves end , you can enter again or live"<<endl;
    
    }
    
    return 0;
}



void Enter(Expression *expression) {
    double n;
    double temp;
    cout<<"Please enter number of item:"<<endl;
    cin>>n;
    cout<<"Please enter the degree of every item:"<<endl;
    for(int i = 1; i <= n+1; i++) {
        cin>>temp;
        expression->push_back(temp);
    }
}

double GetValue(int number, double x) {
    double sum = 1;
    for(int i = 1; i <= number; i++)
        sum *= x;
    return sum;
}

double DerivativeValue(double x, Expression *expression) {
    double value = 0;
    int i = 0;
    if(!expression->empty()) {
        for(Expression::iterator it = expression->begin(); it != expression->end(); it++) {
            if(i != 0) 
                value += (*it)*i*GetValue(i, x);    
            i++;
        }
        return value;
    }
    return 0;
}

double GetFunctionValue(double x, Expression *expression) {
    double value = 0;
    int i = 0;
    if(!expression->empty()) {
        for(Expression::iterator it = expression->begin(); it != expression->end(); it++) {
            value += (*it)*GetValue(i, x);
            i++;
        }
        return value;
    }
    return 0;
}

double NewtonIterator(Expression *expression, double x0, int time) {
    for(int i = 1; i <= time; i++) {
        x0 = x0 - GetFunctionValue(x0, expression)/DerivativeValue(x0, expression);
        cout<<GetFunctionValue(x0,expression)<<endl;
    }
    return x0;
}