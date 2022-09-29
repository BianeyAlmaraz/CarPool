/*Program Assignment: 2*/
/*Description:Total program size and total size of each of the program’s parts (classes). */
/*Name: Bianeiry Almaraz Arenas*/

#include<iostream>
#include<fstream>
#include <bits/stdc++.h>

using namespace std;

class loops
{
    public:
			
	void functionfor(int &i, int &count, int &k, int &l ,int &m, string lines[], int vectorclase[], int vectorclase2[], int vectormetodos[], string &str1 , string &str2, string &str3, string &str4, string &str5, string &str6,float &suma)
	{
		for (i=1;
				i<=(count+1);
							i++){
       	lines[i].find(str1) != string::npos ?/*Find:Encontrar*/
       	k++:
       	suma=suma+1;
		}	
				
		for (i=1;
				i<=(count+1);
						i++){
    	lines[i].find(str1) != string::npos ?
       	vectorclase[i]=1:
        suma=suma+1;
		}	
		for (i=1;
				i<=(count+1);
						i++){
       	lines[i].find(str2) != string::npos ?
       	l++:
       	suma=suma+1;
		}	
			
		for (i=1;
				i<=(count+1);
						i++){
    	lines[i].find(str2) != string::npos ?
       	vectorclase2[i]=1:
       	suma=suma+1;
		}
		
		/* contabilizamos los metodos*/
		for (i=1;
				i<=(count+1);
						i++){
       	lines[i].find(str3) != string::npos ?
       	m++:
       	suma=suma+1;
       	lines[i].find(str4) != string::npos ?
       	m++:
		suma=suma+1;
       	lines[i].find(str5) != string::npos ?
       	m++:
		suma=suma+1;
       	lines[i].find(str6) != string::npos ?
       	m++:
		suma=suma+1;		
		}	
			
		for (i=1;
				i<=(count+1);
						i++){
    	lines[i].find(str3) != string::npos ?
       	vectormetodos[i]=1:
       	suma=suma+1;
    	lines[i].find(str4) != string::npos ?
       	vectormetodos[i]=1:
       	suma=suma+1;
    	lines[i].find(str5) != string::npos ?
       	vectormetodos[i]=1:
       	suma=suma+1;
    	lines[i].find(str6) != string::npos ?
       	vectormetodos[i]=1:
       	suma=suma+1;       	
		}		

	}		
	void rearrangevectors(int &i, int &j, int &count, int vectorclase[], int clase[], int vectorclase2[], int clasecierre[], int vectormetodos[],int metodosrenglon[])
	{			
			j=0;
			for (i=1;
					i<=(count+1);
							i++){
    			if (vectorclase[i]==1){
    				j++;
    				clase[j]=i;     /*i es el renglon donde se encuentra la palabra class*/
				}
			}
			j=0;
			for (i=1;
					i<=(count+1);
							i++){
    			if (vectorclase2[i]==1){
    			j++;
    			clasecierre[j]=i; /*i es el renglon donde se ecnuentra "}"*/
				}
			}		
			
			j=0;
			for (i=1;
					i<=(count+1);
							i++){
    			if (vectormetodos[i]==1){
    			j++;
    			metodosrenglon[j]=i; /*i es el renglon donde se ecnuentra el metodo*/
				}
			}			
	}	
};
 
int main()
{
	loops obj1;
    int count = 0;
    int i=0;
    int j=0;
    string line;
    string lines[10000];
    string str1="class";
    string str2="};";
    string str3="node()";
	string str4="void";
	string str5="float";
	string str6="Linkedlist()";	
    int vectorclase[200];
    int vectorclase2[200];
    int vectormetodos[200];
    int tamanoclase[1000];
    int clase[1000];
    int clasecierre[1000];
    int clase_metodos[1000];
    int metodosrenglon[1000];
    int min[1000];
    int k=0;
    int l=0;
    int m=0;
    int clases=0;
    int tamanoprevio=0;
    float suma=0;
    ifstream file("main_proyecto3.cpp"); /*Agregamos el nombre del archivo*/
    while (getline(file, line)){
        i++;
        lines[i]=line;
        count++;
	}	
	obj1.functionfor(i,count,k,l,m,lines,vectorclase,vectorclase2,vectormetodos,str1,str2,str3,str4,str5,str6,suma);
	
	obj1.rearrangevectors(i,j,count,vectorclase,clase,vectorclase2,clasecierre,vectormetodos,metodosrenglon);
	
	for (i=1;i<(k+1);i++){
	min[i]=clasecierre[i]-clase[i]; 
	}
	
	for (j=1;j<(m+1);j++){
	for (i=1;i<(k+1);i++)
	{
   		if(metodosrenglon[j]>clase[i] && metodosrenglon[j]<clasecierre[i])
   		{
        	clase_metodos[i]++;		
		}
	}	
	}
	/*ajustamos el tamano de las clases*/	
	for (i=1;
			i<(k+1);
				i++){
		min[i]=min[i]+1;
		clases=clase[i];		
		cout<<"El tamano de "<<lines[clases]<<" es "<<min[i]<<endl; /*lines[mmm] guarda el nombre de la clase*/
		cout<<"y tiene "<<clase_metodos[i]<<" metodos"<<endl;
	}
	
	
	
    cout << "Numero de clases "<<k<<endl;
    cout << "Numero de lineas en el archivo : " << count << endl;
      return 0;
}
