/*Program Assignment: 1 */
/*Description:Calculate the Mean and Standard Deviation of an entered file with saved numbers*/
/*Name: Bianeiry Almaraz Arenas*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

class Media
{
	public:	
	/*M*/	float CalcularMedia(float data[11]);
	protected:
		float data[11];
};
		
float Media::CalcularMedia(float data[11])
{
	float suma;
	int i;
	float mediaprom;
	suma=0;
	for(i=1;
			i <= 10;
				 i++)
	{
		suma=suma+data[i];
	}
	mediaprom=suma/10;
	return mediaprom;

}


class Desviacion
{
	public:
	/*M*/	float CalcularEstandar(float data[11]);		
	protected:
		float data[11];		
};

/*Se realiza el cálculo para la desviación*/
float Desviacion::CalcularEstandar(float data[11])
{
	float suma;
	int i;
	float mediaprom;
	float desv;
	float num;
	suma=0;
	for (i=1;
			i<=10;
				i++)
	{
		suma=suma+data[i];
	}
	mediaprom=suma/10;
	suma=0;
	for (i=1;
			i<=10;
				i++)
	{
		suma=suma+pow(data[i]-mediaprom,2);
	}
	desv=sqrt(suma/9);
	return desv;
}

#include "conio.h"


float CalcularMedia(float data[11]);
float CalcularEstandar(float data[11]);

void menu(){
  cout << " MENU"<< '\n';
  cout << "1) Ingresar datos" << '\n';
  cout << "2) Calcular media" << '\n';
  cout << "3) Calcular desviacion" << '\n';
  cout << "4) Salir" << '\n';
  cout << " Elige una opcion ";

}

int main(int argc, char const *argv[])
{
 int opcion = -1;
 float data[11];
 Media p;
 Desviacion q;
 ifstream f;
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
 			else
 			{
 			for(i = 1;
			 		 i <= 10; 
					  	i++)
 			{
 				n=n+1;
 				f>> data [i];
 				cout << data[i]<< endl;
 			}
 			f.close();
 			}
          break;
	  case 2:
        p.CalcularMedia(data);
		cout<< "La media es: "<<p.CalcularMedia(data)<< endl;
        cout << "continuar..." << endl;
        getch();
          break;
      case 3:
			q.CalcularEstandar(data);
			cout<< "La desviacion estandar es: " <<q.CalcularEstandar(data)<< endl;
          getch();
          break;
      default:
        cout << "No existe opción" << '\n';
        break;
    }

  } while (opcion != 4);
  return 0;
}
