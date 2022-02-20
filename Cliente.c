
#include <stdio.h>
#include <Socket_Cliente.h>
#include <Socket.h>

main ()
{

	int Socket_Con_Servidor;
   int Longitud = 0;
   int Auxiliar;
	char Texto[100];


	Socket_Con_Servidor = Abre_Conexion_Inet ("localhost", "cpp_java");
	if (Socket_Con_Servidor == 1)
	{
		printf ("Conexion no exitosa\n");
		exit (-1);
	}

   strcpy (Cadena, "Hola");
   Longitud = 6;


   Auxiliar = htonl (Longitud);
   Escribe_Socket (Socket_Con_Servidor, (char *)&Auxiliar, sizeof(Longitud));

	Escribe_Socket (Socket_Con_Servidor, Texto, Longitud);

   Lee_Socket (Socket_Con_Servidor, (char *)&Auxiliar, sizeof(int));
   Longitud = ntohl (Auxiliar);

   Lee_Socket (Socket_Con_Servidor, Texto, Longitud);
   printf ("From Server: %s\n", Texto);
   
	close (Socket_Con_Servidor);
}
