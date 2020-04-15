package com.testRefreshJavaMick;

import java.util.Random;

public class Main {


    public static void main(String[] args) {
        Random rand = new Random();
        System.out.println("even oefenen test.");

        pan koekenpan = new pan();

        while(true) {
            pannenkoekbakken pannenkoek = new pannenkoekbakken();
            if (koekenpan.getSchoon() <= 90) {
                koekenpan.maakSchoon();
                }
            if (koekenpan.getSchoon() > 90) {
                int antiaanbak = koekenpan.getAntiaanbaklaag();
                int aanbakkans = rand.nextInt(antiaanbak);
                if (aanbakkans < 10){
                    System.out.println("ownee! een aangebakken pannenkoek.");
                    break;
                }else {
                    System.out.println("pannenkoek gebakken");
                    System.out.println(pannenkoek.toString());
                }
            }
        }
    }
}

