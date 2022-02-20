
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <sys/un.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#include "Socket.h"

int Lee_Socket (int fd, char *Datos, int Longitud)
{
	int Leido = 0;
	int Aux = 0;

	if ((fd == -1) || (Datos == NULL) || (Longitud < 1))
		return -1;

	while (Leido < Longitud)
	{
		Aux = read (fd, Datos + Leido, Longitud - Leido);
		if (Aux > 0)
		{

			Leido = Leido + Aux;
		}
		else
		{

			if (Aux == 0) 
				return Leido;
			if (Aux == -1)
			{

				switch (errno)
				{
					case EINTR:
					case EAGAIN:
						usleep (100);
						break;
					default:
						return -1;
				}
			}
		}
	}

	return Leido;
}

int Escribe_Socket (int fd, char *Datos, int Longitud)
{
	int Escrito = 0;
	int Aux = 0;


	if ((fd == -1) || (Datos == NULL) || (Longitud < 1))
		return -1;


	while (Escrito < Longitud)
	{
		Aux = write (fd, Datos + Escrito, Longitud - Escrito);
		if (Aux > 0)
		{

			Escrito = Escrito + Aux;
		}
		else
		{

			if (Aux == 0)
				return Escrito;
			else
				return -1;
		}
	}

	return Escrito;
}

int Lee_Socket_Udp (
	int fd, struct sockaddr *Remoto, socklen_t *Longitud_Remoto,
	char *Datos, int Longitud_Datos)
{
	int Leido = 0;
	int Aux = 0;

	if ((fd == -1) || (Datos == NULL) || (Longitud_Datos < 1)
			|| (Remoto == NULL) || (Longitud_Remoto == NULL))
	{
		return -1;
	}

	while (Leido < Longitud_Datos)
	{
		Aux = recvfrom (fd, Datos + Leido, Longitud_Datos - Leido, 0,
			Remoto, Longitud_Remoto);

		if (Aux > 0)
		{

			Leido = Leido + Aux;
		}
		else
		{

			if (Aux == 0) 
				return Leido;
			if (Aux == -1)
			{

				switch (errno)
				{
					case EINTR:
					case EAGAIN:
						usleep (100);
						break;
					default:
						return -1;
				}
			}
		}
	}


	return Leido;
}

int Escribe_Socket_Udp (int fd, struct sockaddr *Remoto, 
	socklen_t Longitud_Remoto, char *Datos, int Longitud_Datos)
{
	int Escrito = 0;
	int Aux = 0;

	if ((fd == -1) || (Datos == NULL) || (Longitud_Datos < 1) 
			|| (Remoto == NULL) )
   {
		return -1;
   }

	while (Escrito < Longitud_Datos)
	{
		Aux = sendto (fd, Datos + Escrito, Longitud_Datos - Escrito, 0,
			Remoto, Longitud_Remoto);

		if (Aux > 0)
		{

			Escrito = Escrito + Aux;
		}
		else
		{

			if (Aux == 0)
				return Escrito;
			else
         {
				return -1;
         }
		}
	}

	return Escrito;
}


int Dame_Direccion_Udp (char *Host, char *Servicio, struct sockaddr_in *Servidor,
   int *Longitud_Servidor)
{
   struct servent *Puerto;
   struct hostent *Maquina;
  

   if (Servidor == NULL) return -1;

   Servidor->sin_family = AF_INET;

   if (Host != NULL)
   {

      Maquina = gethostbyname (Host);
      if (Maquina == NULL)
         return -1;

      Servidor->sin_addr.s_addr = ((struct in_addr *)(Maquina->h_addr))->s_addr;
   }
   else

      Servidor->sin_addr.s_addr = INADDR_ANY;


   if (Servicio == NULL)
      Servidor->sin_port = 0;
   else
   {

      Puerto = getservbyname (Servicio, "udp");
      if (Puerto == NULL)
         return -1;
      Servidor->sin_port = Puerto->s_port;
   }
}
