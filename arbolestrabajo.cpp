#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;  

struct Nodo{
 int dato;
 Nodo *Derecha;
 Nodo *Izquierda;
 Nodo *padre;
};
void menu();
Nodo *crearNodo(int,Nodo *);
void insertarNodo(Nodo *&,int,Nodo *);
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void posOrden(Nodo *);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);
Nodo *arbol=NULL;

int main(){
	
	
	
	menu();
	getch();
	return 0;
}

void menu(){
 int dato,opcion,contador=0;
 
 do{
  cout<<"\t.:MENU:."<<endl;
  cout<<"1.Insertar un nuevo nodo."<<endl;
  cout<<"2.Mostrar Arbol."<<endl;
  cout<<"3.Buscar en el Arbol."<<endl;
  cout<<"4.Recorrer Arbol en preOrden."<<endl;
  cout<<"5.Recorrer Arbol en inOrden."<<endl;
  cout<<"6.Recorrer Arbol en posOrden."<<endl;
  cout<<"7.Eliminar nodo de arbol."<<endl;
  cout<<"8.Salir"<<endl;
  cout<<"Opcion: ";
  cin>>opcion;
  
  switch (opcion){
   case 1: cout<<"\nDigite un numero: ";
     cin>>dato;
     insertarNodo(arbol,dato,NULL);
     cout<<"\n";
     system("pause");
     break;
   case 2: cout<<"\nMostrando El Arbol:\n\n";
   mostrarArbol(arbol,contador);
   cout<<"\n";
   system("pause");
   break;
   case 3:cout<<"\nDigite un numero a buscar: ";
   cin>>dato;
   if (busqueda(arbol,dato)== true){
   	cout<< "n\Elemento"<<dato<<"se encontro en el arbol\n";
   }
   else{
   	cout<<"n\Elemento no encontrado\n";
   	}
   	cout<<"\n";
     system("pause");
     break;
     case 4: cout<<"\nRecorrido en preorden: ";
     preOrden(arbol);
     cout<<"\n\n";
     system("pause");
     break;
     
     case 5: cout<<"\nRecorrido en inorden: ";
     inOrden(arbol);
     cout<<"\n\n";
     system("pause");
     break;
     
     case 6:cout<<"\nRecorrido en posorden: ";
     posOrden(arbol);
     cout<<"\n\n";
     system("pause");
     break;
     
       case 7:cout<<"\nDigite numero a eliminar: ";
        cin>>dato;
        eliminar(arbol,dato);
        cout<<"\n";
        system("pause");
        break;
   }
  
  system("cls");
 }while(opcion!=8);
}

Nodo *crearNodo(int n,Nodo *padre){
	Nodo *nuevo_Nodo=new Nodo();
	
	nuevo_Nodo->dato=n;
	nuevo_Nodo->Derecha=NULL;
	nuevo_Nodo->Izquierda=NULL;
	nuevo_Nodo->padre = padre;
	return nuevo_Nodo;
	
}

void insertarNodo(Nodo *&arbol,int n,Nodo *padre){
	if(arbol == NULL){
		Nodo *nuevo_Nodo=crearNodo(n,padre);
		arbol=nuevo_Nodo;
	}
	else{
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			insertarNodo(arbol->Izquierda,n,arbol);
		}
		else{
			insertarNodo(arbol->Derecha,n,arbol);
		}
	}
}
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol== NULL){
		return;
	}else{
		mostrarArbol(arbol->Derecha,cont+1);
		for (int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->Izquierda,cont+1);
	}
}

bool busqueda(Nodo *arbol,int n){
	if(arbol==NULL){
		return false;
	}
	else if(arbol->dato == n){
		return true;
	}
	else if(n < arbol->dato){
		return busqueda(arbol->Izquierda,n);
	}
	else{
	      return busqueda(arbol->Derecha,n); 	
	}
}

void preOrden (Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		cout<<arbol->dato<<"-";
		preOrden(arbol->Izquierda);
		preOrden(arbol->Izquierda);
	}
}

void inOrden (Nodo *arbol){
	if (arbol == NULL){
		return;
	}
	else{
		inOrden(arbol->Izquierda);
		cout<<arbol->dato<<"-";
		inOrden(arbol->Derecha);
	}
}

void posOrden (Nodo *arbol){
	if (arbol == NULL){
		return;
	}
	else{
		posOrden(arbol->Izquierda);
		posOrden(arbol->Derecha);
		cout<<arbol->dato<<"-";
	
	}
}

void eliminar (Nodo *arbol,int n){
	if(arbol==NULL){
		return;
	}
	else if(n < arbol->dato){
		eliminar (arbol->Izquierda,n);
	}
	else if(n > arbol->dato){
		eliminar (arbol->Derecha,n);
}
else{
	eliminarNodo(arbol);
}
}

Nodo *minimo(Nodo *arbol){
	if(arbol==NULL){
		return NULL;
	}
	if (arbol->Izquierda){
	return minimo(arbol->Izquierda);
}
else {
	return arbol;
}
}

void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
	if(arbol->padre){
		
		if(arbol->dato == arbol->padre->Izquierda->dato){
			arbol->padre->Izquierda=nuevoNodo;
		}
		else if (arbol->dato==arbol->padre->Derecha->dato){
			arbol->padre->Derecha = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}

void destruirNodo(Nodo *nodo){
	nodo->Izquierda=NULL;
	nodo->Derecha=NULL;
	
	delete nodo;
}

void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->Izquierda && nodoEliminar->Derecha){
		Nodo *menor=minimo(nodoEliminar->Derecha);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->Izquierda){
		reemplazar(nodoEliminar,nodoEliminar->Izquierda);
		destruirNodo(nodoEliminar);
	}
	else if (nodoEliminar->Derecha){
		reemplazar(nodoEliminar,nodoEliminar->Derecha);
		destruirNodo(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
	}
}