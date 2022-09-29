#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

#include "conio.h"
#include<math.h>

class node{
	private:
		float v;
		node *next;
	public:
		node(){
			next = NULL;
		}
};

class LinkedList{
	node *head;
	public:
		
		LinkedList(){
			head = NULL;
		}
				
		void insert(float v){
			node *temp = new node();
			temp->v = v;
			temp->next = head;
			head = temp;
		}
		
		void display(){
			if (head == NULL){
				cout<<"List is empty"<<endl;
			}
			else{
				node *temp = head;
				cout<<"Linked List: ";
				while (temp != NULL){
					cout<<temp->v<<"->";
					temp = temp->next;
				}
				cout<<"NULL"<<endl;
			}
		}
		float operation_media(float &sumx){
    		node *temp = head;
    		
	    	while (temp != NULL) {
    	    	sumx += temp->v ;
        		temp = temp->next;
    		}
		}
		float operation_desvest(float &sum_desvx,float mediax){
    		node *temp = head;
    	
    		while (temp != NULL) {
        		sum_desvx += pow((temp->v)-mediax,2);
        		temp = temp->next;
    		}
		}		
		
		
};

void menu(){
  cout << " MENU"<< '\n';
  cout << "1) Ingresar datos" << '\n';
  cout << "2) Calcular media" << '\n';
  cout << "3) Calcular desviacion" << '\n';
  cout << "4) Salir" << '\n';
  cout << " Elige una opcion ";

}

int main(int argc, char const *argv[]){
    LinkedList list;	
 	int opcion = -1;
 	ifstream f;
 	float valuea;
 	float sumx,sum_desvx;
 	float desv_est;
 	float mediax;
 	int i;
 	int n;
 
	do{
    	menu();
	    cin >> opcion;
    	if(cin.fail() && cin.rdstate()){
        	cout << "NO ES UN NUMERO" << endl;
        	opcion = -1;
    	}
    	switch (opcion) {
 	     	case 1:
				n=0;
 				f.open("tabla1_columna1.txt");
 				if(!f)
 					cout << "Error abriendo el fichero" << endl;
 				else{
 					for(i = 1; i <= 10; i++){
 						n=n+1;
 						f>> valuea;
 						list.insert(valuea);
 					}
 					f.close();
 				}
 				list.display();
 				cout<<endl;
        		cout << "continuar..." << endl;				
    	    	getch(); 				
         		break;
		  	case 2:
	  			sumx=0;
		  		list.operation_media(sumx);
        		mediax=sumx/n;
				cout<< "La media es: "<<mediax<< endl;
        		cout << "continuar..." << endl;
        		getch();
          		break;
   		   	case 3:
   		   		sum_desvx=0;
      			list.operation_desvest(sum_desvx,mediax);
				desv_est=sqrt(sum_desvx/(n-1));
				cout<< "La desviacion estandar es: " <<desv_est<< endl;
        		cout << "continuar..." << endl;				
    	    	getch();
        		break;
        	case 4:
        		exit(0);
      		default:
      		  	cout << "No existe opcion" << '\n';
        		break;
		}
  } while (opcion != 5);
  return 0;
}
