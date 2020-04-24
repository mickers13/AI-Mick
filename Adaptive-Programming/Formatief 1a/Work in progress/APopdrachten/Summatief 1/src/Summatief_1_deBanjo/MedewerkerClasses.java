package Summatief_1_deBanjo;


import java.util.ArrayList;
import java.util.Random;

class Directeur implements Medewerker{
    private String naam;
    private String Geheim;
    double hoeveelheidGeld;
    private String werkType;
    public Directeur(String naam) {
        this.naam = naam;
        werkType = "Directeur";
        double hoeveeheidGeld = 12223;
        String geheim = "IFdpbSB2ZXJrb29wdCBhZiBlbiB0b2UgQzE3SDIxTk80IG5hYXN0IGhvdXQ=";

        System.out.println("Wim gebruikt zijn geheim op het hout: "+ geheim);
    }

    @Override
    public String werk() {
        return "aan het werk met 'administratie'";
    }

    @Override
    public double ontvangloon() {
        hoeveelheidGeld += 30000;
        return 30000;
    }

    @Override
    public String getName() {
        return naam;
    }

    @Override
    public int getNumofInstances() {
        return 0;
    }

    @Override
    public String getWerktype() {
        return werkType;
    }

}


class Houthakker implements Medewerker{
    private String naam;
    private static int counter;
    private String werkType;

    public Houthakker(String naam) {
        this.naam = naam;
        counter++;
        double hoeveelheidGeld = 2;
        werkType = "Houthakker";
    }
    public void hak(int index,BosSector bosSector){
        Boom tempboom = bosSector.getBoom(index);

        bosSector.delBoom(index);
        tempboom.NumofInstancesmin();
        //nummer euros niet veranderd aangezien ik ivm deadline druk dit oversla, inpricipe meer van wat ik al gedaan heb. Dus niet heel relevant.
        System.out.println("Er is een "+ tempboom.getNaam()+" omgehakt. Er zijn er nu nog "+tempboom.getNumofInstances()+" maar dit leverde wel "+ tempboom.getWaarde() +" euro op!");
    }
    @Override
    public String werk() {
        return "aan het houthakken";
    }

    @Override
    public double ontvangloon() {
        return 1790;
    }

    @Override
    public String getName() {
        return naam;
    }

    @Override
    public int getNumofInstances() {
        return counter;
    }

    @Override
    public String getWerktype() {
        return werkType;
    }

}

class BoomPlanter implements Medewerker{
    private String naam;
    private static int counter;
    private String werkType;
    public BoomPlanter(String naam) {
        this.naam = naam;
        counter++;
        double hoeveelheidGeld = 2;
        werkType = "boomPlanter";
    }
    public void plantBoom(Boom boom,BosSector bosSector){
        ArrayList<String> distinctBomen= bosSector.getDistinctBomen();
        String currentBoomType = boom.getClass().toString();
        if (distinctBomen.contains(currentBoomType)||distinctBomen.size()<2){
            bosSector.addToSector(boom);
        }else{
            System.out.println("Er mogen niet meer dan 2 verschillende soorten bomen in dit bos staan!");
        }
    }

    @Override
    public String werk() {
        return "aan het bomenplanten";
    }

    public double ontvangloon() {
        // ingehuurde vakantie werkers rond de 16 jaar oud.
        return 700;
    }

    @Override
    public String getName() {
        return naam;
    }

    @Override
    public int getNumofInstances() {
        return counter;
    }

    @Override
    public String getWerktype() {
        return werkType;
    }

}

