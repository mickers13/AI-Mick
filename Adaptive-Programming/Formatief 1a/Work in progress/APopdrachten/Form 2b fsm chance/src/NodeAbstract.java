import java.util.ArrayList;
//deze abstract class is een beetje nutteloos, maar ik wil dit leerzaam maken. Dus heb ook een abstract class gebruikt.
abstract class NodeAbstract {
    private String nodeNaam;
    static int hoeveelheidVerplaatst;
    static int counter;
    private boolean endNode;
    int id;
    static ArrayList<String> nodesList = new ArrayList<String>();
    public NodeAbstract(int id, boolean isendnode) {
        counter++;
        this.id = id;
        endNode = isendnode;
        nodeNaam = this.getClass().toString();
    }
    abstract void useNode();


    public abstract void addConnectie(Node node,Integer id);

    public String getNodeNaam(){
        return nodeNaam;
    }
    public int getHoeveelheidVerplaatst(){
        return hoeveelheidVerplaatst;
    }


}
