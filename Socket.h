
#ifndef _SOCKET_H
#define _SOCKET_H

#include <sys/socket.h>


int Lee_Socket (int fd, char *Datos, int Longitud);


int Escribe_Socket (int fd, char *Datos, int Longitud);

int Lee_Socket_Udp (int fd, struct sockaddr *Remoto, socklen_t *Longitud_Remoto, char *Datos, int Longitud_Datos);

int Escribe_Socket_Udp (int fd, struct sockaddr *Remoto, socklen_t Longitud_Remoto, char *Datos, int Longitud);

int Dame_Direccion_Udp (char *Host, char *Servicio, struct sockaddr_in *Servidor, int *Longitud);
#endif
