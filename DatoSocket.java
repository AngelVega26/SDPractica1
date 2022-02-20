

import java.io.*;


public class DatoSocket implements Serializable
 {

   public DatoSocket (String cadena)
   {
      
      if (cadena != null)
      {
         c = cadena.length();
         d = cadena;
      }
   }


   public int c = 0;
     
  
   public String d = "";
     

   public String toString ()
   {
       String resultado;
       resultado = Integer.toString(c) + " -- " + d;
       return resultado;
   }


   public void writeObject(java.io.DataOutputStream out)
         throws IOException
     {

         out.writeInt (c+1);


         out.writeBytes (d);

    
         out.writeByte ('\0');
     }
    

     public void readObject(java.io.DataInputStream in)
     throws IOException
     {


         c = in.readInt() - 1;
         

         byte [] aux = null;
         
         aux = new byte[c];    
         in.read(aux, 0, c);   
         d = new String (aux); 
         in.read(aux,0,1);     
     }
}
