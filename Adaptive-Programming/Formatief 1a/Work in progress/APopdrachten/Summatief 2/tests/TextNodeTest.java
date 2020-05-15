import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TextNodeTest {

    @Test
    void codeValidator() throws Exception {

        TextNode test = new TextNode();
        String testString = test.codeValidator("aabbYbbbac");
        // test of de code niet leeg is.
        assertNotNull(testString);
        //als er in de zelfgemaakte "foute string" nogsteeds een Y zit raise een error
        assertFalse( testString.contains("Y"));



    }
}