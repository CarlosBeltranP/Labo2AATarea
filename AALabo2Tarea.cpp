#include <iostream>
#include <stdio.h>
#include <array>
using namespace std;

struct Nodo{
    int data;
    Nodo *sig;
}*startEven, *startOdd;


class StackE{
    public:
        Nodo* create(int v){
            Nodo *node = new Nodo;
            node -> data = v;
            node -> sig = nullptr;
            return node;
        }

        void addEven(int v){
            Nodo *node = create(v);
            node->sig = startEven;
            startEven = node;
        }

        void showEven(){
            Nodo *key = startEven;
            if(!startEven){
                cout<<"Empty stack"<<endl;
            } else{
                while(key){
                    cout<<"\t-- "<<
					key->data<<"\n";
                    key = key->sig;
                }
            }
        }
};


class StackO{
    public:
        Nodo* create2(int v){
            Nodo *n = new Nodo;
            n -> data = v;
            n -> sig = nullptr;
            return n;
        }
        
        void addOdd(int v){
            Nodo *n = create2(v);
            n->sig = startOdd;
            startOdd = n;
        }
      
        void showOdd(){
            Nodo *key = startOdd;
            if(!startOdd){
                cout<<"Empty stack"<<endl;
            } else{
                while(key){
                    cout<<"\t-- "<<
					key->data<<"\n";
                    key = key->sig;
                }
            }
        }
};

bool nEven(int n){
    if(n % 2 == 0){
        return true;
    }else{
        return false;
    }
}

void arrayHandle(int integers[], int quantity, StackE EvenStack, StackO OddStack){
    int odd = 0, even = 0;
    for (int i = 0; i < quantity; i++){
        if(nEven(integers[i])){
            EvenStack.addEven(integers[i]);
            even++;
        }else{
            OddStack.addOdd(integers[i]);
            odd++;
        }
    }
    if(even == odd){
        cout<<"\n\tRESULTADO: \n\n\tIgual cantidad de numeros pares e impares." <<endl;
    }else{
        cout<<"\n\tRESULTADO: \n\n\tDistinta cantidad de numeros pares e impares."<<endl;
    }
} 

int main(){
    StackE EvenStack;
    StackO OddStack;
    int quantity = 0, flag = 1, a = 0, ite = 0;
    cout<<"\n\n\tTAREA LABORATORIO 2 - ANALISIS DE ALGORITMOS\n\n";
    cout<<"-------------------------------\n";
    cout<<"\n\tIngrese la cantidad total de numeros a ingresar: ";
    cin >> quantity;
      cout<<"\n";
      cout<<"\tDATOS\n";
    int integers[quantity];
    while(ite < quantity){
    	cout<<"\t-- ";
        cin >> a;
        integers[ite] = a;
        ite++;
    }
    arrayHandle(integers, quantity, EvenStack, OddStack);  
    cout<<"\n\n\n\tPILAS "<<endl;
	cout<<"\n\tPAR "<<endl;
    EvenStack.showEven();
    cout<<"\n\tIMPAR "<<endl;
    OddStack.showOdd();
    cout<<endl;
   
    return 0;
}
