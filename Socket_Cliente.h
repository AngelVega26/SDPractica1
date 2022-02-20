
#ifndef _SOCKET_CLIENTE_H
#define _SOCKET_CLIENTE_H

#include <sys/socket.h>


int Abre_Conexion_Unix (char *Servicio);

int Abre_Conexion_Inet (char *Host_Servidor, char *Servicio);

#endif
