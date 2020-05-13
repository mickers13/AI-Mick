import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;
public class Node extends NodeAbstract {


    private float beginPercent;
    private float endPercent;
    private HashMap<Integer,Node> connecties = new HashMap<>();
    private Random rand = new Random();
    private int id;
    String newCode;

    public Node(int id, boolean isendnode) {
        super(id, isendnode);
    }

    @Override
    public void useNode() {
        int r = rand.nextInt(101);
        for(Integer i : connecties.keySet()){
            if(r > connecties.get(i).beginPercent && r < connecties.get(i).endPercent){
                //dice kant gevonden. Ik had ook naar deze dice kunnen gaan zoals ik ook in formatief 2a heb gedaan, maar voor de opdracht is dit goed genoeg.
                System.out.println(id);

            }
        }


        System.out.println("end of sequence reached.");
    }
    @Override
    public void addConnectie(Node node,Integer id) {
        connecties.put(id,node);
    }

    public void setPercentages(int i,float kantPercent){
        beginPercent = (i-1)*kantPercent;
        endPercent = (i*kantPercent)-1;
    }
    public float getBeginPercent() {
        return beginPercent;
    }

    public float getEndPercent() {
        return endPercent;
    }
    public int getId() {
        return id;
    }

}

