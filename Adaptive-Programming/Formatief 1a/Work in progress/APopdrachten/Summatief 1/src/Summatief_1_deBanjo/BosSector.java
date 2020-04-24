package Summatief_1_deBanjo;

import javax.lang.model.type.ArrayType;
import java.util.ArrayList;

public class BosSector{
    private ArrayList<Boom> bomen = new ArrayList<Boom>();

    public void addToSector(Boom boom){
        bomen.add(boom);

    }
    public ArrayList<String> getDistinctBomen(){
        // return a string version of the classes that are in this array
        ArrayList<String> distinctBomen = new ArrayList<String>();
        for(Boom boom : bomen){
            if (!distinctBomen.contains(boom.getClass().toString()) ){
                distinctBomen.add(boom.getClass().toString());
            }
        }
        return distinctBomen;
    }
    public Boom getBoom(int index){
        int size = bomen.size();

        if (index < 0){
            return bomen.get(size+index);
        }
        return bomen.get(index);
    }





    public void delBoom(int index){
        if (index < 0){
            bomen.remove(bomen.size()+index);
        }
        bomen.remove(index);
    }

}
