package Summatief_1_deBanjo;

import java.util.ArrayList;

public class Bedrijf {
    private ArrayList<Medewerker> medewerkers = new ArrayList<Medewerker>();
    String naam;
    int oprichting;
    int huidigJaar;
    public Bedrijf(){
        String naam = "De Banjo";
        int oprichting = 2016;
        int huidigJaar = 2019;
    }
    public Medewerker getMedewerker(int index){
        if (index < 0){
            return medewerkers.get(medewerkers.size()+index);
        }
        return medewerkers.get(index);
    }
    public void addMedewerkerToSysteem(Medewerker medewerker){

        medewerkers.add(medewerker);
        System.out.println("Medewerker "+medewerker.getName()+" is toegevoegd aan het systeem als: "+medewerker.getWerktype()+" In totaal zijn er nu "+medewerker.getNumofInstances()+" in dit beroep in dienst.");

    }
}
