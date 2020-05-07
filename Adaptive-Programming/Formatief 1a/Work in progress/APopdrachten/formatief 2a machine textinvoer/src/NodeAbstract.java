import java.util.ArrayList;
//deze abstract class is een beetje nutteloos, maar ik wil dit leerzaam maken. Dus heb ook een abstract class gebruikt.
abstract class NodeAbstract {
    private String nodeNaam;
    static int hoeveelheidVerplaatst;
    static int counter;

    static ArrayList<String> nodesList = new ArrayList<String>();
    static String letters;
    public NodeAbstract() {
        counter++;
        nodeNaam = this.getClass().toString();
    }
    abstract void useNode(String abccode);


    public abstract void addConnectie(Node node,String letter);

    public String getNodeNaam(){
        return nodeNaam;
    }
    public int getHoeveelheidVerplaatst(){
        return hoeveelheidVerplaatst;
    }


}
