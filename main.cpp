#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int longitud(char[]);
//Declaracion de las funciones que van a rotar ma matriz original.

void cientochenta(int *b, int pos);
void noventa(int *a, int pos);
void dossetenta(int *c, int pos);

//Declaracion de la funcion que va hacer llamada constantemente para imprimir cada matriz
void mostrar(int a[][5]);
int main()
{
    int opcion=1;
    while(opcion !=0)
    {
    cout<<"\n********** Ejercicios de la practica 1 **********"<<endl;
    cout<<"Presione 1 para saber el minimo de billetes dada una cantidad"<<endl;
    cout<<"Presione 2 para saber cuantas veces se repite una letra en un arreglo"<<endl;
    cout<<"Presione 3 para convertir de cadena de entero a entero"<<endl;
    cout<<"Presione 4 para cambiar de minuscula a mayuscula una cadena"<<endl;
    cout<<"Presione 5 para separar de una cadena los numeros de las letras"<<endl;
    cout<<"Presione 6 para separar cada n numeros y sumarlos"<<endl;
    cout<<"Presione 7 para saber si una matriz es cuadrado magico"<<endl;
    cout<<"Presione 8 para saber cuantas estrellas hay en una matriz"<<endl;
    cout<<"Presione 9 para saber la interseccion de dos rectangulos"<<endl;
    cout<<"Presione 10 para sumar los numeros amigables menores a n"<<endl;
    cout<<"Presione 0 para salir"<<endl;
    cin>>opcion;

   switch(opcion)
    {
      case 1:{
       int num,i=0;
       int maq[11][2]={{50000,0},{20000,0},{10000,0},{5000,0},{2000,0},{1000,0},{500,0},{200,0},{100,0},{50,0},{0,0}};
       cout << "Ingrese una cantidad: "; cin>>num;
       while(num>0){
           if(num>=maq[i][0]){
               if(i==10){
                   maq[i][1]=num;
                   num=0;
               }
               else{
                   num-=maq[i][0];
                   maq[i][1]++;
               }
           }
           else i++;

       }
       for (i=0;i<11;i++){
           if(i==10){
           cout<<"Sobrante: "<<maq[i][1]<<endl;
           }
           else cout<<maq[i][0]<<" : "<<maq[i][1]<<endl;
       }
      break;
   }
      case 2:{

       break;
}
   case 3:{
          char numero[100]={};
          cout<<"Ingrese el numero: "; cin>>numero;
          int j=0; int r=0, t=0;
          for(int i=0; i<longitud(numero); i++){
           t=t*10+(numero[j++]-'0');
          }
          r+=t;t=0;
          cout<<r+1<<endl;
        break;
   }
   case 4:{
       char pal[100]={};
       cout<<"Ingrese una palabra: "; cin>>pal;
       cout<<"Original: "<<pal<<endl;
       for(int i=0; i<longitud(pal); i++){
           if(pal[i]>='a' && pal[i]<='z'){
               pal[i]-=32;
           }
       }
       cout<<"En mayuscula: "<<pal<<endl;

       break;
   }
   case 5:{
       char numero[100]={}; int n;
          cout<<"Ingrese la cantidad de separaciones: "; cin>>n;
          cout<<"Ingrese el numero: "; cin>>numero;
          cout<<"Original: "<<numero<<endl;
          int j=0, r=0, t=0;
          while(j<longitud(numero)){
              for(int i=0;i<longitud(numero)%n;i++){
                  t=t*10+(numero[j++]-'0');
                  }
                  r+=t;t=0;
              for(int i=0;i<n;i++){
                  t=t*10+(numero[j++]-'0');
              }
              r+=t;t=0;
          }
          cout<<"Suma: "<<r<<endl;
       break;
   }
   case 6:{

       break;
   }
   case 7:{
       int matriz[50][50],dim, suma=0,suma1=0;
       cout<<"Ingrese la dimension: "; cin>>dim;
       for(int i=0;i<dim;i++){
           for(int j=0;j<dim;j++){
               cout<<"Ingrese un numero ["<<i<<"]["<<j<<"]: "; cin>>matriz[i][j];
           }
       }
       for(int i=0;i<dim;i++){
           suma1=0;
           int suma2=0, suma3=0, suma4=0;
           for(int j=0;j<dim;j++){
               if(i==0)
                   suma+=matriz[i][j];
            else{
              suma1+=matriz[i][j]; suma2+=matriz[j][i]; suma3+=matriz[j][j]; suma4+=matriz[j][dim-j-1];
               }
           }
             if((suma!=suma1)&&i>0){
                 cout<<"No es cuadrado magico"<<endl;
             break;
             }
             else if((suma!=suma2)&&i>0){
                 cout<<"No es cuadrado magico"<<endl;
             break;
             }
             else if((suma!=suma3)&&i>0){
                 cout<<"No es cuadrado magico"<<endl;
             break;
             }
             else if((suma!=suma4)&&i>0){
                 cout<<"No es cuadrado magico"<<endl;
             break;
             }
       }
       if(suma==suma1)
           cout<<"El cuadrado es magico"<<endl;
       for(int i=0;i<dim;i++){
           for(int j=0;j<dim;j++){
               cout<<matriz[i][j];
           }
           cout<<"\n";
               }
       break;
   }
   case 8: {
       int original[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
       cout << "Matriz original" << endl;
       mostrar(original);//Se llama la funcion mostrar que es la encargada de imprimir cada matriz

       int (*px)[5]=original;//apuntador declarado para apuntar a un arreglo de paquetes de a 5, en este caso la matriz original
       for(int fila = 0; fila < 5; fila++)//ciclo que recorre las filas
           noventa(*(px + fila), 4 - fila);//Se llama la funcion noventa que recibe una direccion de memoria de cada fila de la matriz orgiinal y un entero


       return 0;

       break;
   }
   case 9:{
       int n=0,i=1;
       unsigned long long int factoriall=0,d;
       unsigned long long int caminos=0;
       cout << "Ingrese  el tamano de la matriz" << endl;
       cin>>n;
       factoriall=1;

       while(i<=n){
           factoriall=factoriall*i;
           i++;
       }
       caminos=factoriall;
       while(i<=2*n){
           factoriall=factoriall*i;
           i++;
       }
       d=factoriall;
       d=d/(caminos*caminos);

       cout<<"Para una matriz de "<<n<<" x "<<n<<" hay "<<d<<" caminos"<<endl;
       return 0;
       break;
   }
   case 10: {


       break;
   }
   default:
        cout<<"Opcion no valida"<<endl;
        break;
     }
   }
    return 0;
}
int longitud(char num[]){
    int s=0, cant=0;
    for(int i=0; i<num[s++]; i++){
    if(s!='\0'){
        cant+=1;
        }
    }
    return cant;
}
void noventa(int *a, int pos){//implementacion de la funcion noventa que recibe un puntero y un entero
   int nov[5][5]; //declaracion de la matriz de noventa grados
   for(int i = 0; i < 5; i++) //ciclo que recorre las filas y las cambia a un columna en la ultima posicion
       nov[i][pos] = *(a + i);//Se va llenando la matriz de 90 para que la fila 1 de la matriz original la ponga en la ultima columna y asi sucesvamente
   if (pos==0){//condicional que indica que ya se lleno la matriz
       cout<<endl;
       cout<<"Matriz rotada a 90 grados: "<<endl;
       mostrar(nov);//se llama la funcion mostrar para que muestre la matriz de 90
       cout<<endl;
       int (*py)[5]= nov;//apuntador que apunta a la matriz de 90 grados
       for(int fila = 0; fila < 5; fila++)//ciclo que recorre las fila en la matriz de 90
        cientochenta(*(py + fila), 4 - fila);//se llama la funcion cientoochenta que recibe una direcciond de memoria y un entero
   }
}

void cientochenta(int *b, int pos){ //implementacion de la funcion que recibe la direccion de memoria de las filas de la matriz de 90 y un entero
    int c_ochenta[5][5];//declaracion de la matriz de 180
    for(int j =0 ; j < 5; j++)//ciclo que recorre las filas y las cambia a una columna en la ultima pisicion
        c_ochenta[j][pos]= *( b + j);//Se va llenando la matriz de 180 para que la fila 1 de la matriz de 90 la ponga en la ultima columna y asi sucesvamente
    if(pos==0){//condicional que indica que ya se lleno la matriz
    cout<<"Matriz rotada a 180 grados: "<<endl;
    mostrar(c_ochenta);//se llama la funcion mostrar para que muestre la matriz de 180
    cout<<endl;
    int (*py)[5]= c_ochenta;//apuntador a la matriz de 180 grados
    for(int fila = 0; fila < 5; fila++)//ciclo que recorre las fila en la matriz de 180
        dossetenta(*(py + fila), 4 - fila);//se llama la funcion dossetenta que recibe una direcciond de memoria y un entero
    }
}


void dossetenta(int *c, int pos){//implementacion de la funcion que recibe la direccion de memoria de las filas de la matriz de 90 y un entero
    int dossetenta[5][5];//declaracion de la matriz de 270
    for(int j =0 ; j < 5; j++)//ciclo que recorre las filas y las cambia a una columna en la ultima pisicion
        dossetenta[j][pos]= *( c + j);//Se va llenando la matriz de 270 para que la fila 1 de la matriz de 180 la ponga en la ultima columna y asi sucesvamente
    if(pos==0){//condicional que indica que ya se lleno la matriz
    cout<<"Matriz rotada a 270 grados: "<<endl;
    mostrar(dossetenta);//se llama la funcion mostrar para que muestre la matriz de 270
    }
}
