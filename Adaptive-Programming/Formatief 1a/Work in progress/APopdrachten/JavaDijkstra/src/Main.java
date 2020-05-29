import java.util.ArrayList;
import java.util.List;



// Small disclaimer voor de docent:   Ik heb erg mijn best gedaan verschillende currency's met elkaar te vergelijken, maar behalve een onduidelijke berekening te laten zien vind ik dit niet erg duidlijk. Ik zal de
public class Main {
    //nederland is vrij bereikbaar door heel europa heen, en mijn meeste destinations zullen in europa zijn.
    static Vlucht schipholAirport = new Vlucht();
    static Treinrit schipholTreinstation = new Treinrit();
    static Rit schipholParking = new Rit();

    //duitsland vrij bereikbaar
    static Vlucht berlinAirport = new Vlucht();
    static Treinrit berlinTreinstation = new Treinrit();
    static Rit berlinParking = new Rit();

    //zwitserland vrij bereikbaar, maar helaas zijn de airport en het treinstation gesloten ivm corona.
    static Rit geneveParking = new Rit();

    //italie is redelijk bereikbaar, maar helaas is de airport gesloten ivm corona.
    static Treinrit romeTreinstation = new Treinrit();
    static Rit romeParking = new Rit();

    //engeland is redelijk bereikbaar, maar helaas niet echt te bereiken met de trein.
    static Rit londenParking = new Rit();
    static Vlucht londenAirport = new Vlucht();

    //belgie is vrij bereikbaar, maar helaas niet met de auto ( de boot van engeland telt niet ;) ), want de belgen hadden de weg afgesneden. Ook is de airport dicht ivm corona
    static Treinrit brusselTreinstation = new Treinrit();
    static Rit brusselParking = new Rit();

    //japan is vrij ver, maar niet te bereiken met de trein of auto.
    static Vlucht hanedaAirport = new Vlucht();


    public static void main(String arg[])
    {

        // maak de graaf, en leg basis connecties.
        createGraaf();
        //defineer begin en eind node, bereken de reis.
        initDijkstra(hanedaAirport,romeTreinstation);

    }


    public static void createGraaf(){
        // -------------- CREEEREN VAN ALLE NODES + linken van de nodes die een connectie hebben.
        // ( ja achteraf gezien had ik hier beter een universele functie voor kunnen maken, maar aangezien ik 3 verschillende nodes moet kunnen linken vond ik dit het makkelijkste)
        //

       //alle lokale reis mogenlijkheden. ( dit kost dus geen tijd, en kan je "gratis nemen (als je de reis bias niet zou mee nemen!)"
        addWederzijdseConnectie(schipholAirport,schipholTreinstation,0);
        addWederzijdseConnectie(schipholAirport,schipholParking,0);
        addWederzijdseConnectie(schipholParking,schipholTreinstation,0);

        addWederzijdseConnectie(berlinAirport,berlinTreinstation,0);
        addWederzijdseConnectie(berlinAirport,berlinParking,0);
        addWederzijdseConnectie(berlinTreinstation,berlinParking,0);

        addWederzijdseConnectie(romeParking,romeTreinstation,0);

        addWederzijdseConnectie(londenParking,londenAirport,0);

        // alle vlucht connecties volgends mijn schema, voor de makkelijkheid kan je alleen tussen deze heen en weer vliegen. ( in werkelijkheid kan je natuurlijk ook van schiphol naar haneda )
        // nu moet je verplicht overstappen, maar voor een proof of concept is dit prima.
        addWederzijdseConnectie(londenAirport,schipholAirport,90);
        addWederzijdseConnectie(schipholAirport,berlinAirport, 200);
        addWederzijdseConnectie(berlinAirport,hanedaAirport,1000);
        // alle trein ritten volgens mijn schema
        addWederzijdseConnectie(schipholTreinstation,berlinTreinstation,200);
        addWederzijdseConnectie(schipholTreinstation,brusselTreinstation,100);
        addWederzijdseConnectie(brusselTreinstation,berlinTreinstation,160);
        addWederzijdseConnectie(brusselTreinstation,romeTreinstation,400);
        // alle auto ritten volgends  schema
        addWederzijdseConnectie(schipholParking,berlinParking,200);
        addWederzijdseConnectie(berlinParking,geneveParking,150);
        addWederzijdseConnectie(brusselParking,romeParking,400);
        addWederzijdseConnectie(londenParking,brusselParking,150);
    }
    public static void initDijkstra(Stap beginNode,Stap endNode){
        //voer hier in van waar naar waar je wilt reizen standaard die meeste voertuigenbenut is london -> rome
        Reis reis = new Reis(beginNode,endNode);
    }
    public static void addWederzijdseConnectie(Stap a, Stap b,int distance){
        //makkelijke manier om 2 connecties aan elkaar te leggen zonder al teveel duplicate code. ( minder menselijke fouten. )
        //in pricipe is het mogenlijk om een airport aan een station te linken, wat in het echt logisch zou zijn.(overstappen(lopen) kost tijd) In de code houden we alleen hier geen rekening mee.
        // de distance met overstappen is altijd 0, aangezien ik hier geen rekening mee houd.
        a.addConnectie(b,distance);
        b.addConnectie(a,distance);
    }
}
