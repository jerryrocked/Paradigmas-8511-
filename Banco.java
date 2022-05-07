
package com.mycompany.mavenproject1;
import java.util.Scanner;

public class Banco {

    public static void main(String[] args) {
        int valor;
        int respuesta;
        Scanner leer= new Scanner (System.in);
        
        System.out.println("    Bienvenido al Banco XYZ  ");
        System.out.println("    elija una cuenta: ");
        System.out.println("1. cuenta de ahorro");  /* enseñar tipo de cuenta de ahorro*/
        System.out.println("2. cuenta corriente");  /* enseñar tipo de cuenta de ahorro*/
        System.out.println("3. Cuenta ahorro fijo");    /* enseñar tipo de cuenta de ahorro*/
        System.out.println("4.salir"); /*en ccaso de no usar ninguna opcion*/ 
        System.out.print("Escribe una de las opciones:");
        respuesta = leer.nextInt();/*otorgat valor a respuesta y pausa*/
        System.out.print("Ingrese cantidad que quiere ahorrar:");/*ingresar el la cantidad del dinero ahorrada (esto ira a valor)*/
        valor = leer.nextInt();//ingreso para valor y pausa
            
        switch(respuesta){ /*creacion de casos*/
            case 1:
              double porcentaje1 = 1.0; /*valor anual*/
              double primera1 = (valor + ( valor*porcentaje1/100)); /*año 1*/ 
              double segunda1 = (primera1 + (primera1 * porcentaje1/100)); /*año 2*/
              double tercera1 = (segunda1 + (segunda1* porcentaje1/100)); /*año 3*/
              double cuarta1 = (tercera1 + ( tercera1 * porcentaje1/100)); /*año 4*/
              double quinta1 = (cuarta1 + (cuarta1 * porcentaje1/100)); /*año 5*/
              double sexta1 = (quinta1 + (quinta1 * porcentaje1/100)); /* año 6*/
              System.out.println("su eleccion es la 1. cuenta de ahorro:");/*repeticion de eleccion solicitada*/
              System.out.println("su monto original era de:"+ valor);/*monto original*/
              System.out.println("su ganancia sera de:");/*impresion de cada año*/
              System.out.println("primer ano: "+primera1);/*impresion de cada año*/
              System.out.println("segundo ano: "+segunda1);/*impresion de cada año*/
              System.out.println("tercer ano: "+tercera1);/*impresion de cada año*/
              System.out.println("cuarto ano: "+cuarta1);/*impresion de cada año*/
              System.out.println("quinto ano: "+quinta1);/*impresion de cada año*/
              System.out.println("sexto ano: "+sexta1);/*impresion de cada año*/
              System.out.println("gracias por preferir el banco XYZ"); /*despedida*/
              break;
             
            case 2:
              double porcentaje2 = 0.5; /*valor anual*/
              double primera2 = (valor + ( valor*porcentaje2/100)); /*año 1*/ 
              double segunda2 = (primera2 + (primera2 * porcentaje2/100)); /*año 2*/
              double tercera2 = (segunda2 + (segunda2* porcentaje2/100)); /*año 3*/
              double cuarta2 = (tercera2 + ( tercera2 * porcentaje2/100)); /*año 4*/
              double quinta2 = (cuarta2 + (cuarta2 * porcentaje2/100)); /*año 5*/
              double sexta2 = (quinta2 + (quinta2 * porcentaje2/100)); /* año 6*/
              System.out.println("su eleccion es la 2. Cuenta corriente:");/*repeticion de eleccion solicitada*/
              System.out.println("su monto original era de:"+ valor);/*monto original*/
              System.out.println("su ganancia sera de:");/*impresion de cada año*/
              System.out.println("primer ano: "+primera2);/*impresion de cada año*/
              System.out.println("segundo ano: "+segunda2);/*impresion de cada año*/
              System.out.println("tercer ano: "+tercera2);/*impresion de cada año*/
              System.out.println("cuarto ano: "+cuarta2);/*impresion de cada año*/
              System.out.println("quinto ano: "+quinta2);/*impresion de cada año*/
              System.out.println("sexto ano: "+sexta2);/*impresion de cada año*/
              System.out.println("gracias por preferir el banco XYZ"); /*despedida*/
              break;
              
            case 3:
              double porcentaje3 = 1.2; /*valor mensual*/
              double primera3 = (valor + ( valor*porcentaje3/100)); /*mes 1*/ 
              double segunda3 = (primera3 + (primera3 * porcentaje3/100)); /*mes 2*/
              double tercera3 = (segunda3 + (segunda3* porcentaje3/100)); /*mes 3*/
              double cuarta3 = (tercera3 + ( tercera3 * porcentaje3/100)); /*mes 4*/
              double quinta3 = (cuarta3 + (cuarta3 * porcentaje3/100)); /*mes 5*/
              double sexta3 = (quinta3 + (quinta3 * porcentaje3/100)); /* mes 6*/
              System.out.println("su eleccion es la 3. Aplazo fijo:");/*repeticion de eleccion solicitada*/
              System.out.println("PRECAUcION: ESTA CUENTA SOLO PUEDE SER A PLAZOS DE 3 O 6 MESES");/*recordatorio*/
              System.out.println("su monto original era de:"+ valor);/*valor original*/
              System.out.println("su ganancia sera de:");/*ganancia mensual*/
              System.out.println("tercer ano: "+tercera3);/*impresion de cada mes*/
              System.out.println("sexto ano: "+sexta3);/*impresion de cada mes*/
              System.out.println("gracias por preferir el banco XYZ"); /*despedida*/
              break;
            case 4:
              System.out.println("gracias por preferir el banco XYZ"); /*despedida al ser solo un salir*/
              break;
        }   
    }
}
