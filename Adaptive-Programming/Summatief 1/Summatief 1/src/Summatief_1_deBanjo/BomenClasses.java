package Summatief_1_deBanjo;

import java.util.Random;
///////////////////////////////////////////WILG
class Wilg implements Boom {

    private int waardeEuros;
    private boolean ziek;
    private String blaadjes = "heel veel kleine blaadjes";
    Random rand = new Random();
    private String naam = "wilg";
    private static int counter = 0;

    public Wilg() {
        counter++;
        waardeEuros = 300;
        naam = "wilg";
    }

    @Override
    public void neemWaterOp() {
        System.out.println("slurp, oh lekker");
    }

    @Override
    public void neemCo2Op() {
        System.out.println("adem, oh lekker");
    }

    @Override
    public int getNumofInstances() {
        return counter;
    }
    public int NumofInstancesmin() {
        return counter--;
    }
    @Override
    public int getWaarde() {
        return waardeEuros;
    }

    @Override
    public String getNaam() {
        return naam;
    }

    @Override
    public String toString(){
        int num = getNumofInstances();
        if( num < 1 ){
        return "Er zijn op het moment geen wilgen in het bos.";
        }else{
        return ("De wilg heeft "+blaadjes+" en een totaal waarde van "+getWaarde()+". Er zijn intotaal "+num+" wilgen in het hele bos.");
        }

    }
}
/////////////////////////////////////////EIK
class Eik implements Boom{
    private int waardeEuros;
    Random rand = new Random();
    private static int counter = 0;
    private String naam = "eik";
    private String blaadjes = "redelijk wat grote bladeren";
    public Eik() {
        counter++;

        waardeEuros = 900;

    }

    @Override
    public void neemWaterOp() {
        System.out.println("slurp, oh lekker");
    }


    @Override
    public void neemCo2Op() {
        System.out.println("adem, oh lekker");
    }

    @Override
    public int getNumofInstances() {
        return counter;
    }
    public int NumofInstancesmin() {
        return counter--;
    }
    @Override
    public int getWaarde() {
        return waardeEuros;
    }

    @Override
    public String getNaam() {
        return naam;
    }

    public String toString() {
        int num = getNumofInstances();
        if (num < 1) {
            return "Er zijn op het moment geen wilgen in het bos.";
        } else {
            return ("De eik heeft " + blaadjes + " en een totaal waarde van " + getWaarde() + ". Er zijn intotaal " + num + " eiken in het hele bos.");
        }

    }
}
/////////////////////////////////////Berk
class Berk implements Boom {
    private int houtRotResistentie;
    private int waardeEuros;
    private String naam = "berk";
    private String blaadjes = "vrij weinig maar kleine blaadjes";
    Random rand = new Random();
    private static int counter = 0;

    public Berk() {
        counter++;
        waardeEuros = 1000;
    }


    @Override
    public void neemWaterOp() {
        System.out.println("slurp, oh lekker");
    }

    @Override
    public void neemCo2Op() {
        System.out.println("adem, oh lekker");
    }

    @Override
    public int getNumofInstances() {
        return counter;
    }
    public int NumofInstancesmin() {
        return counter--;
    }
    @Override
    public int getWaarde() {
        return waardeEuros;
    }

    @Override
    public String getNaam() {
        return naam;
    }

    public String toString() {
        int num = getNumofInstances();
        if (num < 1) {
            return "Er zijn op het moment geen wilgen in het bos.";
        } else {
            return ("De berk heeft " + blaadjes + " en een totaal waarde van " + getWaarde() + ". Er zijn intotaal " + num + " eiken in het hele bos.");
        }

    }
}