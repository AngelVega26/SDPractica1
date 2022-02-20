#include <Socket_Servidor.h>
#include <Socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

main () {

	int Socket_Servidor;
	int Socket_Cliente;
	int Auxiliar, Longitud, Auxiliar2, Envio;
	char Texto[10];
	
	
	Socket_Servidor = Abre_Socket_Inet("cpp_java");
	if (Socket_Servidor == -1){
		printf("Error al abrir el socket del servidor\n");
		exit(-1);
	}
	
	Socket_Cliente = Acepta_Conexion_Cliente(Socket_Servidor);
	if (Socket_Cliente == -1){
		printf ("Error al abrir el socket del cliente\n");
		exit(-1);
	}
	
    Longitud = 5;
    strcpy (Texto, "");
    Auxiliar = htonl (Longitud);

    //Escribe_Socket (Socket_Cliente, (char *)&Auxiliar, sizeof(Longitud));
    //Escribe_Socket (Socket_Cliente, Texto, Longitud);
    int num;
    do{

  
    	Lee_Socket (Socket_Cliente, (char *)&Auxiliar, sizeof(Longitud));
    	Longitud= ntohl(Auxiliar);
	
	
		Lee_Socket(Socket_Cliente,Texto, Longitud);
		num = atoi(Texto);

		//Longitud=ntohl(Auxiliar);
		printf("Numero recibido en el servidor: %d\n",num);

		num = num + 1;

		sprintf(Texto,"%d",num);
		Escribe_Socket (Socket_Cliente, (char *)&Auxiliar, sizeof(Longitud));
		Escribe_Socket(Socket_Cliente, Texto, Longitud);
    	
		

    }while (num!=0);
    
 
	
	close (Socket_Cliente);
	close (Socket_Servidor);

}
