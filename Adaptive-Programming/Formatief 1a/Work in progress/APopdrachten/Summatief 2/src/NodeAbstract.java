import java.util.ArrayList;
//deze abstract class is een beetje nutteloos, maar ik wil dit leerzaam maken. Dus heb ook een abstract class gebruikt.
abstract class NodeAbstract {
    private String nodeNaam;
    static int hoeveelheidVerplaatst;
    static int counter;
    static String letters = "";
    public boolean isendnode;
    static ArrayList<String> nodesList = new ArrayList<String>();

    public static void addLetters(String letter) {
        letters.concat(letter);
    }


    public NodeAbstract() {
        counter++;
        nodeNaam = this.getClass().toString();
    }


    public String getNodeNaam(){
        return nodeNaam;
    }
    public int getHoeveelheidVerplaatst(){
        return hoeveelheidVerplaatst;
    }


    protected abstract void useNode(String newCode);
}
