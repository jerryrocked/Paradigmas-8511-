package com.mycompany.tareabanco;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.math.BigDecimal;
import java.math.RoundingMode;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class Banco extends JFrame {

    private JPanel panel;
    private JLabel op1;
    private JLabel op2;
    private JLabel op3;
    private JTextField cajatexto1;
    private JTextField cajatexto2;
    private JTextField cajatexto3;
    private JTextField cajaanos1;

    Banco() {
        setSize(1000, 500);
        setLocationRelativeTo(null);
        this.getContentPane().setBackground(Color.yellow);
        iniciocomponentes();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    private void iniciocomponentes() {
        colocarpanel();
        texto();
        seleccion();
    }

    private void colocarpanel() {
        panel = new JPanel();
        panel.setLayout(null);
        this.getContentPane().add(panel);
    }

    private void texto() {
        JLabel etiqueta = new JLabel();
        etiqueta.setText("Bienvenido al Banco XYZ");
        etiqueta.setBounds(10, 10, 500, 30);
        etiqueta.setForeground(Color.black);
        etiqueta.setFont(new Font("Arial", 1, 20));
        panel.add(etiqueta);
        JLabel etiqueta2 = new JLabel();
        etiqueta2.setText("¿Que tipo de cuenta va a abrir?");
        etiqueta2.setBounds(10, 50, 500, 30);
        etiqueta2.setForeground(Color.black);
        etiqueta2.setFont(new Font("Arial", 1, 20));
        panel.add(etiqueta2);
    }

    private void seleccion() {
        JRadioButton radiobot1 = new JRadioButton("Cuenta Ahorro", true);
        radiobot1.setBounds(10, 100, 150, 20);
        panel.add(radiobot1);
        JRadioButton radiobot2 = new JRadioButton("Cuenta Corriente", false);
        radiobot2.setBounds(10, 150, 300, 20);
        panel.add(radiobot2);
        JRadioButton radiobot3 = new JRadioButton("Cuenta a Plazo Fijo", false);
        radiobot3.setBounds(10, 200, 450, 20);
        panel.add(radiobot3);
        ButtonGroup gruporadioboton = new ButtonGroup();
        gruporadioboton.add(radiobot1);
        gruporadioboton.add(radiobot2);
        gruporadioboton.add(radiobot3);

        op1 = new JLabel();
        op1.setBounds(100, 220, 300, 40);
        panel.add(op1);

        ActionListener PB1 = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                op1.setText("¿Cuanto desea abonar?");

                cajatexto1 = new JTextField();
                cajatexto1.setBounds(100, 250, 200, 30);
                panel.add(cajatexto1);

                ActionListener Ingreso1 = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        JLabel ingreso = new JLabel();
                        ingreso.setBounds(100, 275, 300, 30);
                        panel.add(ingreso);
                        String num = cajatexto1.getText();
                        int numEntero = Integer.parseInt(num);
                        double ganancia;
                        ganancia = 0.01;
                        double total;
                        total = numEntero + (numEntero * ganancia);
                        ingreso.setText("Su aumento incial sera: " + total);

                        JLabel años = new JLabel();
                        años.setBounds(100, 290, 300, 30);
                        panel.add(años);
                        años.setText("¿Cuantos años va a contratar? ");
                        cajaanos1 = new JTextField();
                        cajaanos1.setBounds(100, 315, 200, 30);
                        panel.add(cajaanos1);

                        ActionListener pucha = new ActionListener() {
                            @Override
                            public void actionPerformed(ActionEvent e) {
                                String multi = cajaanos1.getText();
                                int multiEntero = Integer.parseInt(multi);
                                int i = 2;
                                double total2 = total;
                                while (i <= multiEntero) {
                                    total2 = total2 + total2 * ganancia;
                                    i++;
                                }
                                JLabel equis = new JLabel();
                                equis.setBounds(100, 325, 300, 30);
                                panel.add(equis);
                                equis.setText("Su monto final sera: " + total);
                            }
                        };
                        cajaanos1.addActionListener(pucha);
                    }
                };
                cajatexto1.addActionListener(Ingreso1);
            }
        };
        radiobot1.addActionListener(PB1);

        op2 = new JLabel();
        op2.setBounds(100, 220, 300, 40);
        panel.add(op2);

        ActionListener PB2 = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                op1.setText("¿Cuanto desea abonar?");

                cajatexto2 = new JTextField();
                cajatexto2.setBounds(100, 250, 200, 30);
                panel.add(cajatexto2);

                ActionListener Ingreso2 = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        JLabel ingreso = new JLabel();
                        ingreso.setBounds(100, 275, 300, 30);
                        panel.add(ingreso);
                        String num = cajatexto2.getText();
                        int numEntero = Integer.parseInt(num);
                        double ganancia;
                        ganancia = 0.005;
                        double total;
                        total = numEntero + (numEntero * ganancia);
                        ingreso.setText("Su aumento anual sera: " + total);
                    }
                };
                cajatexto2.addActionListener(Ingreso2);
            }
        };
        radiobot2.addActionListener(PB2);

        op3 = new JLabel();
        op3.setBounds(100, 220, 300, 40);
        panel.add(op3);

        ActionListener PB3 = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                op1.setText("1. Escoja una de las dos opciones");

                JButton boton1 = new JButton();
                boton1.setText("3 meses");
                boton1.setBounds(100, 250, 100, 30);
                boton1.setEnabled(true);
                boton1.setForeground(Color.black);
                panel.add(boton1);

                JButton boton2 = new JButton();
                boton2.setText("6 meses");
                boton2.setBounds(200, 250, 100, 30);
                boton2.setEnabled(true);
                boton2.setForeground(Color.black);
                panel.add(boton2);

                JLabel monto = new JLabel();
                monto.setText("2. ¿Cuanto desea abonar?");
                monto.setBounds(100, 280, 300, 30);
                panel.add(monto);

                ActionListener Precionado = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        JLabel monto = new JLabel();
                        monto.setText("2. ¿Cuanto desea abonar?");
                        monto.setBounds(100, 280, 300, 30);
                        panel.add(monto);

                        cajatexto3 = new JTextField();
                        cajatexto3.setBounds(100, 300, 200, 30);
                        panel.add(cajatexto3);

                        ActionListener Ingreso3 = new ActionListener() {
                            @Override
                            public void actionPerformed(ActionEvent e) {
                                JLabel ingreso = new JLabel();
                                ingreso.setBounds(100, 325, 300, 30);
                                panel.add(ingreso);
                                String num = cajatexto3.getText();
                                int numEntero = Integer.parseInt(num);
                                double ganancia;
                                ganancia = 0.012;
                                double total;
                                total = numEntero + (numEntero * ganancia);
                                BigDecimal bd = new BigDecimal(total).setScale(2, RoundingMode.HALF_UP);
                                double val2 = bd.doubleValue();
                                ingreso.setText("Su aumento mensual sera: " + val2);
                            }
                        };
                        cajatexto3.addActionListener(Ingreso3);
                    }
                };
                boton1.addActionListener(Precionado);

                ActionListener Precionado2 = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        JLabel monto = new JLabel();
                        monto.setText("2. ¿Cuanto desea abonar?");
                        monto.setBounds(100, 280, 300, 30);
                        panel.add(monto);

                        cajatexto3 = new JTextField();
                        cajatexto3.setBounds(100, 300, 200, 30);
                        panel.add(cajatexto3);

                        ActionListener Ingreso6 = new ActionListener() {
                            @Override
                            public void actionPerformed(ActionEvent e) {
                                JLabel ingreso = new JLabel();
                                ingreso.setBounds(100, 335, 300, 30);
                                panel.add(ingreso);
                                String num = cajatexto3.getText();
                                int numEntero = Integer.parseInt(num);
                                double ganancia;
                                ganancia = 0.012;
                                double total;
                                total = numEntero + (numEntero * ganancia);
                                BigDecimal bd = new BigDecimal(total).setScale(2, RoundingMode.HALF_UP);
                                double val2 = bd.doubleValue();
                                ingreso.setText("Su aumento mensual sera: " + val2);
                            }
                        };
                        cajatexto3.addActionListener(Ingreso6);
                    }
                };
                boton2.addActionListener(Precionado2);
            }
        };
        radiobot3.addActionListener(PB3);
    }
}
