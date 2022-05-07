/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package actividad3paradigmas;

import java.util.Scanner;

/**
 *
 * @author titok
 */
public class Actividad3paradigmas {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        double ganancia;
        double ganancia1;
        double ganancia2;  
        int cliente_ingreso;
        Scanner leer = new Scanner(System.in);
        boolean salir = false;
        int opcion;
        
        while(!salir){  
            System.out.println("*********Bienvenidos a banco XYZ*********");//Creo un menu para que el usuario escoja la opcion deseada.
            System.out.println("1. cuenta de ahorro.");//Creo la opcion 1 con la cuenta de ahorro.
            System.out.println("2. cuenta corriente.");//Creo la opcion 2 con cuenta corriente.
            System.out.println("3. cuenta de plazo fijo.");//Creo la opcion 3 con cuenta de plazo fijo.
            System.out.println("4. Salir");//Creo la opcion 4 para salir y terminar el programa.
            System.out.print("Ingrese cantidad que quiere ahorrar:");//Ingreso de la cantidad que el usuario quiere ahorrar.
            cliente_ingreso = leer.nextInt();//Ingreso de la cantidad que el usuario quiere ahorrar.
            System.out.print("Escribe una de las opciones:");//Ingreso de la opcion que el usuario quiera escoger.
            opcion = leer.nextInt();//Ingreso de la opcion que el usuario quiera escoger.
          
            
            switch(opcion){ //Se crean distintos casos             
                case 1://En el caso que se escoja la opcion uno va a realizar la operacion de ganancia y va a mostrar la cantidad que el cliente ganara al anio.
                    double pp = 1.0;
                    System.out.println("---------------------------------------------------------------------------");
                    System.out.println("Ha seleccionado la cuenta de ahorro.");
                    ganancia = (cliente_ingreso*pp);
                    System.out.println("La ganancia del cliente al anio con la cuenta de ahorro es de :"+ganancia);
                    System.out.println("---------------------------------------------------------------------------");
                    break;
                case 2://En el caso que se escoja la opcion dos va a realizar la operacion de ganancia y va a mostrar la cantidad que el cliente ganara al anio.
                    double af = 0.5;
                    System.out.println("---------------------------------------------------------------------------");
                    System.out.println("Ha seleccionado la cuenta corriente.");
                    ganancia1 = (cliente_ingreso*af);
                    System.out.println("La ganancia del cliente al anio con la cuenta de corriente es de :"+ganancia1);
                    System.out.println("---------------------------------------------------------------------------");
                    break;
                case 3://En el caso que se escoja la opcion tres va a pasar a un segundo menu en el cual le va a dar la opcion de si tomar 3 o 6 meses con la cuenta de plazo fijo.
                    System.out.println("---------------------------------------------------------------------------");
                    System.out.println("Ha seleccionado la cuenta a plazo fijo.");
                    System.out.println("opcion 1 = 3 meses.");
                    System.out.println("opcion 2 = 6 meses.");
                    System.out.print("Ingrese opcion:");
                    int var = leer.nextInt();
                    
                    if(var ==1){//En el caso que se escoja la opcion uno va a realizar la operacion de ganancia y va a mostrar la cantidad que el cliente ganara en los 3 meses.
                        double pf = 1.2;
                        System.out.println("---------------------------------------------------------------------------");
                        System.out.println("Ha seleccionado la cuenta a plazo fijo a 3 meses.");
                        ganancia2 = (cliente_ingreso*pf)*3;
                        System.out.println("La ganancia del cliente en 3 meses con la cuenta de plazo fijo es de :"+ganancia2);
                        System.out.println("---------------------------------------------------------------------------");
                
                    }
            
                    if(var ==2){//En el caso que se escoja la opcion dos va a realizar la operacion de ganancia y va a mostrar la cantidad que el cliente ganara en los 6 meses.
                        double pf = 1.2;
                        System.out.println("---------------------------------------------------------------------------");
                        System.out.println("Ha seleccionado la cuenta a plazo fijo a 6 meses."); 
                        ganancia2 = (cliente_ingreso*pf)*6;
                        System.out.println("La ganancia del cliente en 6 meses con la cuenta de plazo fijo es de :"+ganancia2);
                        System.out.println("---------------------------------------------------------------------------");
                    }
                    break;
                case 4:
                    salir=true;
                    break;
                default://en el caso de que la opcion sea distinta de las que estan designadas ,se pedira un reingreso.
                    System.out.println("---------------------------------------------------------------------------");
                    System.out.println("Opcion ingresada no valida,reingrese opcion...");
                    System.out.println("---------------------------------------------------------------------------");
           }
            
       }
        
    }
     
}
