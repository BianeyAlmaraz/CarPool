#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

#include<math.h>
#include "conio.h"

class node{
	public:
		float v1;
		float v2;
		node *next;
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
				
		void insert(float v1, float v2){
			node *temp = new node();
			temp->v1 = v1;
			temp->v2 = v2;
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
					cout<<temp->v1<<",";
					cout<<temp->v2<<"->";
					temp = temp->next;
				}
				cout<<"NULL"<<endl;
			}
		}
		
    	float operations(float &sumx, float &sumy, float &xy, float &x2, float &y2){
			node* temp = head;
      		while(temp != NULL){
        		sumx += temp->v1;
      			sumy += temp->v2;
        		xy += (temp->v1)*(temp->v2);
        		x2 += (temp->v1)*(temp->v1);
        		y2 += (temp->v2)*(temp->v2);
				temp = temp->next;        
      		}  
    	}
};

void menu(){
  cout << " MENU"<< '\n';
  cout << "1) Ingresar datos" << '\n';
  cout << "2) Calcular coeficientes" << '\n';
  cout << "3) Salir" << '\n';
  cout << " Elige una opcion ";

}

int main(int argc, char const *argv[]){
	int opcion = -1;
	LinkedList l;
	float xavg,yavg,xy,x2,y2,sumx,sumy;
	float beta0,beta1,rxy,rxyarriba, rxyabajo,r2;
	float xk=386,yk;
	ifstream f;
	ifstream g;
	int i;
	int n;
	float aa,bb;

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
				f.open("test3_columna1.txt");
 				g.open("test3_columna2.txt");
 				if(!f)
 					cout << "Error abriendo el fichero" << endl;
 				else{
 					for(i = 1; i <= 10; i++){
						n++;
 						f>> aa;
 						g>> bb;
 						cout<<"x="<<aa<<" y="<<bb<<endl;			
 						l.insert(aa,bb);
 					}
 					f.close();
 				}
 				l.display();
        		cout << "continuar..." << endl;
        		getch(); 				
          		break;
			case 2:
   		    	xy=0;
				x2=0;
        		y2=0;
        		sumx=0;
        		sumy=0;
				l.operations(sumx,sumy,xy,x2,y2);
        		xavg=sumx/n;
				yavg=sumy/n;		
				beta1=(xy-(n*xavg*yavg))/(x2-(n*xavg*xavg));
				beta0=yavg-(beta1*xavg);
        		rxyarriba=(n*xy)-(sumx*sumy);
				rxyabajo=sqrt(((n*x2)-(sumx*sumx))*((n*y2)-(sumy*sumy)));
				rxy=rxyarriba/rxyabajo;
        		r2=rxy*rxy;
				yk=beta0+beta1*xk;
        		cout<< "Coeficientes de regresion"<<endl;
				cout<< "beta0 = "<<beta0<< endl;
				cout<< "beta1 = "<<beta1<< endl;
				cout<< "Coeficientes de correlaccion"<<endl;
		        cout<< "rxy = "<<rxy<< endl;		
				cout<< "r2 = "<<r2<< endl;
				cout<< "Prediccion"<<endl;
				cout<< "yk = "<<yk<< endl;
        		cout << "continuar..." << endl;
        		getch();
          		break;
          	case 3:
          		exit(0);
    		default:
        		cout << "No existe opcion" << '\n';
        		break;
    	}
	} while (opcion != 4);
  	return 0;
}
