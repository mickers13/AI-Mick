import java.util.*;

public class Reis {
    private Stap begin;
    private Stap eind;
    private PriorityQueue<Stap> unsettled = new PriorityQueue<>(Compareable.nodeCompareator);
    // opslag van alle daadwerkelijk bezochte nodes, die pas gevuld is aan het einde van de reis.
    private ArrayList<Stap> route = new ArrayList<>();

    public Reis(Stap begin, Stap eind) {
        // defineer begin node en eind node van een reis
        this.begin = begin;
        this.eind = eind;
        Stap temp = begin;
//        NodeCompareQueue.add(begin);
        // initialisatie van dijkstra
        ArrayList<Stap> allNodes = begin.getNodesListCopy();
        Set<Stap> duplicatecheck = new HashSet<>();
        ArrayList<Stap> settled = new ArrayList<>();
        begin.setTempShortestDistance(0);
        unsettled.add(begin);
        duplicatecheck.add(begin);
        Stap currentevaluation;
        begin.setLastnode(begin);// voor het algoritme telt hij de vorige distances op met de nieuwe, om te kijken of het kleiner is dan iets anders. Dit is om een null pointer te voorkomen bij de eerste. ( want er is geen vorige )
        Stap last;
        /// ----- daad werkelijk dijkstra algoritme
        while (unsettled.size() > 0) {

            currentevaluation = unsettled.poll();// nog niet poll, want dat kan de lijst naar 0 brengen, wat de while loop sluit.
            Set<Map.Entry<Stap,Double>> connect = currentevaluation.getConnecties().entrySet();
            for (Map.Entry<Stap, Double> entry : connect) {
                Stap stap = entry.getKey();
                if (!settled.contains(stap)) {
                    int distance = (currentevaluation.getDistance(stap)).intValue();
                    if (unsettled.contains(stap)) {
                        if (distance < stap.getTempShortestDistance()) {
                            unsettled.remove(stap);

                        }
                    }
                    stap.setTempShortestDistance(currentevaluation.getTempShortestDistance()+distance);
                    stap.setLastnode(currentevaluation);
                    unsettled.add(stap);
                }
            }
            settled.add(currentevaluation);
        }
        System.out.println(settled);
        // Vanaf het einde terug tracen, zodat ik de route makkelijk kan bekijken. Ik had dit ook tijdens de while loop kunnen doen, maar ik vond dit onoverzichtelijk en deze aanpak is denk ik ook nét wat efficienter ( aan het einde een keer de goedkoopste route bekijken, ipv elke keer checken of je het moet toevoegen ja of nee.)
        Stap huidige = eind;
        ArrayList<Stap> goedkoopsteroute = new ArrayList<>();
        goedkoopsteroute.add(huidige);
        while (huidige != begin){
            goedkoopsteroute.add(huidige.getLastnode());
        }
        for(String index: goedkoopsteroute){

        }
        );
    }
}


