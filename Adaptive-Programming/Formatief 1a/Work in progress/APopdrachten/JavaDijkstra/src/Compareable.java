import java.util.ArrayList;
import java.util.Comparator;

public interface Compareable {
    int vliegtuigBias = 0;  // - betekend dat dit JUIST graag gedaan word, en + betekend dat dit minder graag gedaan word.
    int treinBias = 0; // ik raad aan de getallen in de bias tussen de -5 en +5 te houden, omdat je anders de kans loopt dat je bijvoorbeeld ALLEENMAAR de trein wil nemen, terwijl dit niet altijd kan
    int ritBias = 0;
    Comparator<Stap> nodeCompareator = new Comparator<Stap>() {
        @Override
        public int compare(Stap a, Stap b) {
            //vergelijk hier je 2 nodes, op een manier die je wilt.
            //aangezien dit redelijk appels met peren vergelijken is, kun je hier onder zelf de ratio's aanpassen, ik zelf heb een heuristiek toegepast die alles terug kan rekenen naar km's.
            // Dit is mijn oplossing van dit probleem:
            ArrayList<Stap> node= new ArrayList<>();
            node.add(a);
            node.add(b);
            // om twee nodes te vergelijken met andere "unit" waarden, ga ik deze berekenen naar een universele waarde in verhouding met de vantevoren gedefineerde bias.
            // get distance doet dit voor mij al. ( want seconden met euros vergelijken, zonder een heuristiek toe passen is niet echt mogenlijk....)

                    if (a.getConnecties().keySet().contains(b)){
                        if (a.getClass().getName()=="Vlucht") {
                            return (int) (a.getDistance(b)+vliegtuigBias);
                        }
                        if (a.getClass().getName()=="Treinrit") {
                            return (int) (a.getDistance(b)+treinBias);
                        };
                        }
                        if (a.getClass().getName()=="Rit") {
                            return (int) (a.getDistance(b)+ritBias);
                        }

            return 0;}
        };
    }

