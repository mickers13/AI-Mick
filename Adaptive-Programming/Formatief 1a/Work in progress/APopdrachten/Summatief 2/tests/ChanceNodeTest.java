import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ChanceNodeTest {

    @Test
    void correctThreshold() {
        ChanceNode test = new ChanceNode();

        // test of de minimum en maximum goed is gedefineerd voor percentages.
        assertFalse(test.correctThreshold(101));
        assertFalse(test.correctThreshold(-1));
        assertTrue(test.correctThreshold(20));
    }
}