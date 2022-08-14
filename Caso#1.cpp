//**CASO #1 Isaac Rojas Robles**

#include <iostream>
using namespace std;

struct region {
    int id;
    int color;
    int adyacentes[];
	};
	
int cant;
int cantAdy;

int verificarTeorema(region lasRegiones[]){
	bool cumple=true;
	cout<<"\nVerificar el teorema ""Four Color"""<<endl;
    for(int indexReg=0;indexReg<cant; indexReg++){
    	for(int indexRegAdy=0; indexRegAdy<cantAdy; indexRegAdy++){
    		if(lasRegiones[indexReg].color==lasRegiones[lasRegiones[indexReg].adyacentes[indexRegAdy]-1].color){ //Verifica que el color de la region en ese momento sea diferente al color de sus adyacentes
    			cumple=false;
    		}
    	}
		
	} if (cumple==true){
		cout<<"**El teorema fue comprobado, no existen regiones adyacentes con el mismo color**"<<endl;
	}else{
		cout<<"**Existen regiones adyacentes con el mismo color, el teorema no se pudo comprobar**"<<endl;
	}
}
int main(){
	
	region lasRegiones[cant];
	int arr[cantAdy];
	cout<<"Indique la cantidad de regiones que quiere agregar: ";
	cin>>cant;
	for (int index=0; index<cant; index++){
		cout<<"\nIndique el numero de la nueva region: ";
		cin>>lasRegiones[index].id;
		
		cout<<"\n**COLORES**\n1.Rojo\n2.Azul\n3.Verde\n4.Amarillo"<<endl;
		cout<<"Indique el color de la region: ";
		cin>>lasRegiones[index].color;	

		cout<<"\nIndique la cantidad de adyecentes de la region: ";
		cin>>cantAdy;
			for (int indexAdy=0; indexAdy<cantAdy; indexAdy++){
				cout<<"\nIndique el numero de la region adyacente: ";
				cin>>lasRegiones[index].adyacentes[indexAdy];
		}
	}
	verificarTeorema(lasRegiones);
    
    return 0;
}
