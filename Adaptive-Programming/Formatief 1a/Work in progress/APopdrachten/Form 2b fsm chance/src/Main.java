import java.util.ArrayList;

public class Main {
    public static void createDice(int numberofdice){
        float kantPerPercent = 100 / numberofdice;
        Node start = new Node(0, false);
        ArrayList<Node> nodes = new ArrayList<>();
        // maak alle nodes
        for (int i = 0; i < numberofdice; i++) {
            nodes.add(new Node(i, true));
            nodes.get(i).setPercentages(i, kantPerPercent);
            start.addConnectie(nodes.get(i), nodes.get(i).getId());
        }

        //dit is een public variable zodat ik het makkelijk in de "test" kan laten zien aan jullie. Ik weet dat ik dit eigenlijk met get/set methodes zou moeten oproepen.
        start.useNode();
    }
    public static void main(String args[]){
        //code werkt alleen onder de 100 kanten aan dice, dit kan aangepast, maar dan kan je niet makkelijk meer werken met percentages.
        int dicesides = 10;
        System.out.println("starting up...");
        createDice(dicesides);
        }




}