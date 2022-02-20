

import java.net.*;
import java.io.*;
import java.util.Scanner;


public class SocketCliente
 {

     public static void main (String [] args)
     {
         new SocketCliente();
     }
     
    
     public SocketCliente()
     {
         try
         {

             Socket socket = new Socket ("localhost", 25557);
             System.out.println ("ConexiÃ²n exitosa");


             socket.setSoLinger (true, 10);
             

             DataInputStream bufferEntrada = new DataInputStream (socket.getInputStream());

             DataOutputStream bufferSalida = new DataOutputStream (socket.getOutputStream());

             int Entero;
             String num;
             Scanner sc =new Scanner(System.in);
             do{
                System.out.println("Numero a enviar: ");
                Entero = sc.nextInt();
                num = String.valueOf(Entero);
                DatoSocket aux = new DatoSocket (num);
                aux.writeObject (bufferSalida);

                DatoSocket dato = new DatoSocket("");
                dato.readObject(bufferEntrada);
                System.out.println ("Respuesta del Servidor: " + dato.toString());


             }while(Entero!=0);



             socket.close();
         }
         catch (Exception e)
         {
             e.printStackTrace();
         }
     }
}
