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
        ArrayList<Stap> allNodes = begin.getNodesListCopy();
        Set<Stap> duplicatecheck = new HashSet<>();
        ArrayList<Stap> settled = new ArrayList<>();
        begin.setTempShortestDistance(0);
        unsettled.add(begin);
        duplicatecheck.add(begin);
        Stap currentevaluation;
        begin.setLastnode(begin);// voor het algoritme telt hij de vorige distances op met de nieuwe, om te kijken of het kleiner is dan iets anders. Dit is om een null pointer te voorkomen bij de eerste. ( want er is geen vorige )
        Stap last;
        //evaluate unsettled en voeg nieuwe dingen toe, totdat er niets meer unsettled is. ( en verplaats dingen van unsettled naar settled als ze dus, helemaal gechecked zijn.) en begin bij de laagste.
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
        Stap huidige = eind;
        System.out.println(huidige);
        while (huidige != begin){
            System.out.println(huidige.getLastnode());
            huidige = huidige.getLastnode();
        }
        System.out.println(eind.getTempShortestDistance());
    }
}


